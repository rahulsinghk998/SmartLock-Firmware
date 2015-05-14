// include other code

#import <Arduino.h>

#include <SoftwareSerial.h>
#include "Driver_BLE.h"

#include <Wire.h>
#include "Driver_Accel.h"

#include "Driver_Memory.h"

#include "Driver_Motor.h"

#include "Helper.h"

#include "command_functions.h"

//===============setup and loop=================

//The arduino runs all the code that we write, then it activates the setup function, then it keeps running
// the loop function until we shut it off

void setup() {pinMode(13,OUTPUT);
  BLE_init();
  accel_init();
  motor_init();
}

void loop() {delay(100); digitalWrite(13,HIGH); delay(200); digitalWrite(13,LOW);
  if (BLE.available() > 0) {
    char command=BLE.read();
      Serial.print("command:"); Serial.println(command);
    receiveX(command);
}
  transmitX();
}

//===============main functions============

void transmitX(){
  BLE.println(getAngle());
  Serial.print(getAngle());
  BLE.println(getPosition());
  Serial.println(getPosition());
  // print stuff to BLE for debugging purposes.
  // this corresponds to the random strings of characters // deal with it "output" in the protocol 2 document.
}

// this function needs work
void receiveX(char command){
  changePosition(command);
}

