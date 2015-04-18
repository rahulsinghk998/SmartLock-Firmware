#include <Servo.h> 
#include <SoftwareSerial.h>

int bluetoothTx = 4;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 5;  // RX-I pin of bluetooth mate, Arduino D3

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

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
   Serial.begin(9600);
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 
  bluetooth.begin(9600);
  pinMode(13,OUTPUT);
} 
 
void loop() {
delay(100); // otherwise it's going to break
digitalWrite(13,HIGH);
delay(100);
digitalWrite(13,LOW);
 
 //==================Take commands================
 
 Serial.println("hey");
 if (bluetooth.available() > 0) { 
   
   //char command=bluetooth.read();
 Serial.println("bluetooth available");
 //Serial.println(bluetooth.read());
// if (command=='o') {pos = openPos;}
// if (command=='c') {pos = closedPos;}
// myservo.write(pos);
 
  myservo.write(bluetooth.read());
 }

 //==================Status check================

//int sensorValue = analogRead(potPin);
// if (sensorValue < closedPot) {pot = 'c';}
// if (sensorValue > openPot) {pot = 'o';}
//Serial.println(sensorValue);
//Serial.println(pot);
}
