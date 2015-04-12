
int motor1 = 8;
int motor2 = 10;

int potPin = A0;

int closedPot = 120; // actual value is 100
int openPot = 340; // actual value range from 360 to 400
int pot = 'c'; // on potentiometer

void setup() 
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  pinMode(10, OUTPUT);
} 
 
void loop() {
delay(100); // otherwise it's going to break
digitalWrite(13,HIGH);
delay(200);
digitalWrite(13,LOW);
 
 //==================Take commands================
 
 if (Serial.available() > 0) { char command=Serial.read();
 
 if (command=='o') {
 while (analogRead(potPin)<openPot) {
   digitalWrite(motor1,HIGH);
   digitalWrite(motor1,LOW);}}
 if (command=='c') {
 while (analogRead(potPin)>closedPot){
   digitalWrite(motor2,HIGH);
   digitalWrite(motor2,LOW);}}
 }

 //==================Status check================

int sensorValue = analogRead(potPin);
 if (sensorValue < closedPot) {pot = 'c';}
 if (sensorValue > openPot) {pot = 'o';}
Serial.println(sensorValue);
Serial.println(pot);
}
