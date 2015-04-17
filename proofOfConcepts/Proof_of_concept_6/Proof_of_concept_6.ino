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
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 

Serial.print("begin setup");

  Serial.begin(9600);  // Begin the serial monitor at 9600bps

  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  Serial.print("end setup");

  pinMode(13,OUTPUT);
} 
 
void loop() {
delay(100); // otherwise it's going to break
digitalWrite(13,HIGH);
delay(100);
digitalWrite(13,LOW);
 Serial.println("out");
 //==================Take commands================
 
 if (bluetooth.available() > 0) { 
   Serial.println("help");
   char command=bluetooth.read();
 Serial.println(command);
 if (command=='o') {pos = openPos;}
 if (command=='c') {pos = closedPos;}
 myservo.write(pos);
 }

 //==================Status check================

int sensorValue = analogRead(potPin);
 if (sensorValue < closedPot) {pot = 'c';}
 if (sensorValue > openPot) {pot = 'o';}
//Serial.println(sensorValue);
//Serial.println(pot);
}
