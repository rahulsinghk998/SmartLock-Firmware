//=============setup====================

#include <SoftwareSerial.h>

int settingsSet = 0; // see the memory file
int openAngle = 0; // between 0 and 360
int closedAngle = 0; // same
int potBuffer = 0; // how much "error" in both plus and minus directions from the recorded angles above 
//the lock will accept as "open" or "closed"
int turnDirection = 0; // clockwise or counterclockwise, either 1 or -1 (I actually havent figured out which one is which)
int power = 0; // range from 0 to 255.  Too lazy to program this in at the moment, but it determines the amount of force
// the simsim actually applies, not using full power reduces chance of jamming the lock or breaking something.

//===========default stuff===============

SoftwareSerial BLE(2, 3); // RX, TX, it assigns these two pins to the serial monitor "BLE"

//===========DEBUGGING

void monitorOutput(){
  BLE.print(openAngle);BLE.print(closedAngle);BLE.print(pos); // print stuff to BLE for debugging purposes.
  // this corresponds to the random strings of characters // deal with it "output" in the protocol 2 document.
}

//===============main functions=================

//The arduino runs all the code that we write, then it activates the setup function, then it keeps running
// the loop function until we shut it off

void setup() { // executes this when it starts up.
  BLE.begin(9600); // 9600 is what's called the "baud" rate, I can explain this to you in person if you're curious, but
  // basically just understand that baud rate is a setting and 9600 is the most popular value
  Serial.begin(9600);
  pinMode(13,OUTPUT); // the pin13 digital pin is used for debugging purposes, and corresponds to the built-in LED.  
  // btw, the two other built-in LEDS corresponds to the pin1 and pin0 digital pins (remember that those are rx and tx)
  startupSettings(); // see "memory" file
}
 
void loop() {// this is an infinite loop.  It runs until you turn the arduino off.
  
  delay(100); digitalWrite(13,HIGH); delay(100); digitalWrite(13,LOW); // otherwise it's going to break
  // this is the blinking led 13.  delay is just a delay in miliseconds.  Kind of to keep the loop rate reasonable.

if (BLE.available() > 0) {char command=BLE.read(); changePosition(command);} // your job is to replace this line.

      // testing purposes
      givePosition(); // for now this is our output.  see the output file.
      monitorOutput(); // debugging
}
