
//==============MAIN============

int pos = 0;

// the main function to watch out for is changePosition.  It uses a helper function "turnMotor".  Turnmotor is different for
// DC motor and servos.  Turnmotor accepts two inputs, pos, and dir.  pos is the angle it should move to.  dir is the 
// how it gets there (clockwise or counterclockwise) which is kind of a lie because servos can only get there in one
// direction so the dir variable is only used for DC motors.

void changePosition(char command){//recieves either a "o" or a "c"
  int dir = turnDirection;
  if (command=='o') {pos = openAngle; dir=dir;} if (command=='c') {pos = closedAngle; dir=-dir;}
  turnMotor(pos,dir); // this function is different for servo and dc motor
  if (getPosition() != command) {jamAlert();}
}

//======================SERVO===========================

#include <Servo.h>

Servo myservo; int servoPin = 9;

void turnMotor(int pos,int dir){//dir actually isn't used
  myservo.attach(servoPin); myservo.write(pos); delay(1000); myservo.detach();
}

//======================DC MOTOR======================

int motor1 = 10; int motor2 = 11;

void setupMotors(){
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
}

void motorTest(char dir){
  int len = 1000;
  if (dir == 'r') {littleTurnMotor(len,turnDirection);}
  else if (dir == 'l') {littleTurnMotor(len,-turnDirection);}
}

void littleTurnMotor(int len, int dir){
  Serial.println("turning motor");
  digitalWrite(10,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(11,LOW);
  delay(1000);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(13,LOW);
  /*
  motorOut(255);
  delay(len);
  motorOut(0);
  */
}

void motorOut(int power1){ // currently pow doesn't do much, but it will range between -255 to 255

  int motor1Val; int motor2Val;
  Serial.println("motorrunning");
  Serial.println(power1);
  
  if (power1 > 10){motor1Val = HIGH; motor2Val=LOW;}
  else if (power1 < -10){motor1Val = LOW; motor2Val=HIGH;}
  else {motor1Val = LOW; motor2Val=LOW;}
  
  digitalWrite(motor1,motor1Val);
  digitalWrite(motor2,motor2Val);
}

/*

void turnMotor(int pos, int dir){
  
  for (x = 0; x < 200; x ++){ // exits if either 2000ms passes or it reaches the desired position.
     motorOut(dir*power); delay(10);
     if (abs(pos-getAngle()) < potBuffer){break;}
   }
   motorOut(0);
}

*/
