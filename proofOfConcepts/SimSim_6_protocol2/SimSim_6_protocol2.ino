//=============setup====================

//experiment

#include <SoftwareSerial.h>

int settingsSet = 0;
int openAngle = 0;
int closedAngle = 0;
int potBuffer = 0;
int turnDirection = 0;
int power = 0;

//===========default stuff===============

SoftwareSerial BLE(2, 3); // RX, TX

//===========DEBUGGING

void monitorOutput(){
  BLE.print(openAngle);BLE.print(closedAngle);BLE.print(pos);
}

//===============main functions=================

void setup() {
  BLE.begin(9600);
  Serial.begin(9600);
  pinMode(13,OUTPUT); 
  startupSettings();
}
 
void loop() {delay(100); digitalWrite(13,HIGH); delay(100); digitalWrite(13,LOW); // otherwise it's going to break

if (BLE.available() > 0) {char command=BLE.read(); changePosition(command);}

      // testing purposes
      givePosition();
      monitorOutput();
}
