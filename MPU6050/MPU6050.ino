#include <Wire.h>
#include <SoftwareSerial.h>
#include "MPU6050_SimpleLib.h"


void setup(){
  Serial.begin(9600);
  accel_init();
}


void loop(){
  Serial.println(getAngle());
  delay(300);
}
