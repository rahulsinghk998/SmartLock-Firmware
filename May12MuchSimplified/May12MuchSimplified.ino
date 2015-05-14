//**********************************************************************************************//
//					IMPORTS						 	//
//**********************************************************************************************//

#import <Arduino.h>

// =============BLE============

#include <SoftwareSerial.h>

#include "Driver_BLE.h"

// ============Accel============

#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps20.h"
//#include "MPU6050.h" // not necessary if using MotionApps include file

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

#include "Driver_Accel.h"

// ============Memory============

#include "Driver_Memory.h"

// ============Motor============

#include "Driver_Motor.h"

// ============Helper============

#include "Helper.h"

// ============Command Functions============

#include "command_functions.h"

//**********************************************************************************************//
//					SETUP AND LOOP					 	//
//**********************************************************************************************//

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

//**********************************************************************************************//
//					MAIN FUNCTIONS  				 	//
//**********************************************************************************************//

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

