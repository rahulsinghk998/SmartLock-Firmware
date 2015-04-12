
//==============MAIN============

int pos = 0;

void changePosition(char command){//recieves either a "o" or a "c"
  int dir = turnDirection
  if (command=='o') {pos = openAngle; dir=dir} if (command=='c') {pos = closedAngle; dir=-dir;}
  turnMotor(pos,dir);
  if (getPosition() != command) {jamAlert();}
}

//======================SERVO===========================

#include <Servo.h>

Servo myservo; int servoPin = 9;

void turnMotor(int pos,int dir){//dir actually isn't used
  myservo.attach(servoPin); myservo.write(pos); delay(1000); myservo.detach();
}

//======================DC MOTOR======================

/*

int motor1 = 8; int motor2 = 10;

void motorOut(int pow){ // currently pow doesn't do much, but it will range between -255 to 255

  int motor1Val; int motor2Val;
  
  if (pow > 10){motor1Val = HIGH; motor2Val=LOW;}
  else if (pow < -10){motor1Val = LOW; motor2Val=HIGH;}
  else {motor1Val = LOW; motor2Val=LOW;}
  
  digitalWrite(motor1,motor1Val);
  digitalWrite(motor2,motor2Val);
}

void turnMotor(int pos, int dir){
  
  for (x = 0; x < 100; x ++){ // exits if either 1000ms passes or it reaches the desired position.
     motorOut(dir*power); delay(10);
     if (abs(openPot()-analogRead(potPin)) > potBuffer){break;}
   }
   motorOut(0);
}

*/
