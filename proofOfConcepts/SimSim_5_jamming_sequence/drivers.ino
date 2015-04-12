int potScaling = 1000/360; int potOffset = 0; int pos = 0; // in degrees

int closedPot(){return (closedAngle+potOffset+potBuffer*turnDirection)*potScaling;}
int openPot(){return (openAngle+potOffset-potBuffer*turnDirection)*potScaling;}

void changePosition(char command){//recieves either a "o" or a "c"
  if (command=='o') {pos = openAngle;} if (command=='c') {pos = closedAngle;}
  myservo.attach(servoPin); myservo.write(pos); delay(1000); myservo.detach();
  if (getPosition() != command) {jamAlert();}
}

char getPosition(){
  int sensorValue = analogRead(potPin);
  char pot = 'j';
  if (sensorValue < closedPot()) {pot = 'c';}
  else if (sensorValue > openPot()) {pot = 'o';}
  else {pot = 'm';}
  return pot;}
  
void givePosition(){BLE.println(getPosition());}

void jamAlert(){char text='j'; BLE.println(text);}

void monitorOutput(){
  /*
  BLE.println(openAngle);BLE.println(closedAngle);
  */
  BLE.print(openAngle);BLE.print(closedAngle);BLE.print(pos);
}
