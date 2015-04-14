
//===========Pot stuff====================

int potScaling = 1000/360; int potOffset = 0;// in degrees
// for calibrating the analog values we get from the potentiometer to the actual angle of the lock switcher
int closedPot(){return (closedAngle+potOffset+potBuffer*turnDirection)*potScaling;} 
// returns the value of the analog value that we should get if the lock is in the closed position.
// now reading this function again I realized I wrote it wrong...it should not consider potbuffer.  
//potbuffer should be implemented when comparing the value from the potentiometer to the value this function gives.  Oh well.
int openPot(){return (openAngle+potOffset-potBuffer*turnDirection)*potScaling;}
// ditto

int potPin = A0; // the potentiometer is plugged into the analog 0 pin

//=============actual outputs===================

char getPosition(){ // returns the the position (of the (open, closed, unknown) of the knob
  int sensorValue = analogRead(potPin);
  char pot = 'j';
  if (sensorValue < closedPot()) {pot = 'c';}
  else if (sensorValue > openPot()) {pot = 'o';}
  else {pot = 'm';}
  return pot;}
  
void givePosition(){BLE.println(getPosition());} // sends the position (of the (open, closed, unknown) to bluetooth

void jamAlert(){char text='j'; BLE.println(text);} // sends a "j" to BLE.  right now it's just for debugging purposes.
