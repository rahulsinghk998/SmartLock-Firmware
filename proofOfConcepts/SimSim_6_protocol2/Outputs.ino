
//===========Pot stuff====================

int potScaling = 1000/360; int potOffset = 0;// in degrees
int closedPot(){return (closedAngle+potOffset+potBuffer*turnDirection)*potScaling;}
int openPot(){return (openAngle+potOffset-potBuffer*turnDirection)*potScaling;}

int potPin = A0;

//=============actual outputs===================

char getPosition(){
  int sensorValue = analogRead(potPin);
  char pot = 'j';
  if (sensorValue < closedPot()) {pot = 'c';}
  else if (sensorValue > openPot()) {pot = 'o';}
  else {pot = 'm';}
  return pot;}
  
void givePosition(){BLE.println(getPosition());}

void jamAlert(){char text='j'; BLE.println(text);}
