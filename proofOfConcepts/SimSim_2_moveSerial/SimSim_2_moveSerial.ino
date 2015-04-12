//=============setup====================

#include <Servo.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
SoftwareSerial BLE(2, 3); // RX, TX
Servo myservo; 
int potPin = A0; int servoPin = 9;

      //===========default stuff===============
      
      int addSettings = 0;
      int addOpenAngle = 1;
      int addClosedAngle = 2;
      int addBuffer = 3; // the tolerance of the potentiometer
      int addTurnsClockwise = 4; // 1 or -1
      int addPower = 5;
      
      int settings = 0;
      int openAngle = 0;
      int closedAngle = 0;
      int buffer = 0;
      int turnsClockwise = 0;
      int addPower = 0;
      
      void writeDefault(){
        EEPROM.write(addSettings, 1);
        EEPROM.write(addOpenAngle, 15);
        EEPROM.write(addClosedAngle, 170);
        EEPROM.write(addBuffer, 10);
        EEPROM.write(addTurnsClockwise, 1);
        EEPROM.write(addPower, 255);
      }
      
      void wipeMemory(){EEPROM.write(addSettings, 0);} // function not being used atm
      
      void readSettings(){
        settings = EEPROM.read(addSettings);
        openAngle = EEPROM.read(addOpenAngle);
        closedAngle = EEPROM.read(addClosedAngle);
        buffer = EEPROM.read(addBuffer);
        turnsClockwise = EEPROM.read(addTurnsClockwise);
        power = EEPROM.read(addPower);
      
      void startupSettings(){
        if (EEPROM.read(addSettings) == 0) {writeDefault();}
        readSettings();
      
      //=====================================
      
int potScaling = 1000/360
int potOffset = 0 // in degrees

int closedPot(){return (closedAngle+potOffset+buffer*turnsClockwise)*closedPot}
int openPot(){return (openAngle+potOffset-buffer*turnsClockwise)*closedPot}

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
              }
               
              void loop() {
              delay(100); digitalWrite(13,HIGH); delay(100); digitalWrite(13,LOW); // otherwise it's going to break
              
              if (BLE.available() > 0) { char command=BLE.read(); changePosition(command);}
              givePosition();
              }
