#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
int potPin = A0;
int servoPin = 9;

int closedPos = 15;
int openPos = 170;
int pos = closedPos;    // variable to store the servo position

int closedPot = 450;
int openPot = 900;
int pot = 'c'; // on potentiometer

void setup() 
{ 
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
  pinMode(13,OUTPUT);
} 
 
void loop() {
delay(100); // otherwise it's going to break
digitalWrite(13,HIGH);
delay(100);
digitalWrite(13,LOW);
 
 //==================Take commands================
 
 if (Serial.available() > 0) { char command=Serial.read();
 
 if (command=='o') {pos = openPos;}
 if (command=='c') {pos = closedPos;}
 myservo.write(pos);
 }

 //==================Status check================

int sensorValue = analogRead(potPin);
 if (sensorValue < closedPot) {pot = 'c';}
 if (sensorValue > openPot) {pot = 'o';}
Serial.println(sensorValue);
Serial.println(pot);
}
