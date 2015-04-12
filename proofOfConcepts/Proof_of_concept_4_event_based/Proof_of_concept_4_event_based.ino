//=============setup====================

#include <Servo.h>

Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
int potPin = A0;
int servoPin = 9;

int closedPos = 15; int openPos = 170; int pos = closedPos;    // variable to store the servo position
int closedPot = 120; int openPot = 340; // actual values are 100 and 400

void changePosition(char command){//recieves either a "o" or a "c"
  if (command=='o') {pos = openPos;}
  if (command=='c') {pos = closedPos;}
  myservo.write(pos);
}

void givePosition(){
int sensorValue = analogRead(potPin);
if (sensorValue < closedPot) {int pot = 'c'; Serial.println(pot);}
if (sensorValue > openPot) {int pot = 'o'; Serial.println(pot);}
}

//===============main functions=================

void setup() { 
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}
 
void loop() {
delay(100); digitalWrite(13,HIGH); delay(100); digitalWrite(13,LOW); // otherwise it's going to break

if (Serial.available() > 0) { char command=Serial.read(); changePosition(command);}
givePosition();
}
