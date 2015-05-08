
#include <SoftwareSerial.h>
SoftwareSerial BLE(2, 3); // RX, TX

int count = 0;
int turnDuration = 6000;

void setup() {
  BLE.begin(9600);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  setupMotors();
}

void loop(){
  
  //motorOut(255);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  delay(turnDuration);
  
  //motorOut(-255);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  delay(turnDuration);
  
  count = count+1;
  BLE.println(count);
}
