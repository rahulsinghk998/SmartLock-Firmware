
//=============setup====================

#include <Servo.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>

//===========default stuff===============
   
int addressSettingsSet = 0;
int addressOpenAngle = 1;
int addressClosedAngle = 2;
int addressBuffer = 3; // the tolerance of the potentiometer
int addressTurnsClockwise = 4; // 1 or -1
int addressPower = 5;
int settingsSet = false;
int openAngle = 0;
int closedAngle = 0;
int buffer = 0;
int turnsClockwise = 0;
int power = 0;

SoftwareSerial BLE(2, 3); // RX, TX
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
int potPin = A0;
int servoPin = 9;

int potScaling = 1000/360; int potOffset = 0; char pos = 'c'; // in degrees

void writeDefault(){
  EEPROM.write(addressSettingsSet, 1);
  EEPROM.write(addressOpenAngle, 15);
  EEPROM.write(addressClosedAngle, 170);
  EEPROM.write(addressBuffer, 10);
  EEPROM.write(addressTurnsClockwise, 1);
  EEPROM.write(addressPower, 255);
}
      
      void wipeMemory(){EEPROM.write(addressSettingsSet, 0);} // function not being used atm
      
      void readSettings(){
        settingsSet = EEPROM.read(addressSettingsSet);
        openAngle = EEPROM.read(addressOpenAngle);
        closedAngle = EEPROM.read(addressClosedAngle);
        buffer = EEPROM.read(addressBuffer);
        turnsClockwise = EEPROM.read(addressTurnsClockwise);
        power = EEPROM.read(addressPower);}
      
      void startupSettings(){
        if (EEPROM.read(addressSettingsSet) == false) {writeDefault();}
        readSettings();}
      
      //=====================================

int closedPot(){return (closedAngle+potOffset+buffer*turnsClockwise)*potScaling;}
int openPot(){return (openAngle+potOffset-buffer*turnsClockwise)*potScaling;}

void changePosition(char command){//recieves either a "o" or a "c"
  if (command=='o') {pos = openAngle;} if (command=='c') {pos = closedAngle;}
  myservo.attach(servoPin); myservo.write(pos); delay(1000); myservo.detach();
}

void givePosition(){
  int sensorValue = analogRead(potPin);
  if (sensorValue < closedPot()) {int pot = 'c'; BLE.println(pot);}
  if (sensorValue > openPot()) {int pot = 'o'; BLE.println(pot);}
}

//===============main functions=================

              void setup() {
                BLE.begin(9600);
                pinMode(13,OUTPUT); 
                startupSettings();
              }
               
              void loop() {
              delay(100); digitalWrite(13,HIGH); delay(100); digitalWrite(13,LOW); // otherwise it's going to break
              
              if (BLE.available() > 0) { char command=BLE.read(); changePosition(command);}
              givePosition();
              }
              
              
