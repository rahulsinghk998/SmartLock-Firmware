
// ===== generic =========

char getPosition(){ // returns the the position (of the (open, closed, unknown) of the knob
  char pot = 'j';
  int angle=getAngle();
  if (angle < closedPot()) {pot = 'c';}
  else if (angle > openPot()) {pot = 'o';}
  else {pot = 'm';}
  return pot;}
  
int closedPot(){return (closedAngle+potBuffer*turnDirection);} 
// returns the angle of the lock for it to be considered "closed"
int openPot(){return (openAngle-potBuffer*turnDirection);}
// ditto

void givePosition(){BLE.println(getPosition());} // sends the position (of the (open, closed, unknown) to bluetooth
void giveAngle(){BLE.println(getAngle());}
void jamAlert(){char text='j'; BLE.println(text);} // sends a "j" to BLE.  right now it's just for debugging purposes.

// =========== accelerometer ===============

/*
          int getAngle(){// returns angle relative to positive x-axis, where z axis is pointing out of the door and positive y-axis is pointing up (away from gravity)
            int angle = 42;
            return angle;}
*/

//out dated

          //===========Pot stuff====================
          
          int potScaling = 360/1000;
          int potOffset = 0;// in degrees
          // for calibrating the analog values we get from the potentiometer to the actual angle of the lock switcher
          
          int potPin = A0; // the potentiometer is plugged into the analog 0 pin
          
          int getAngle(){
            int sensorValue = analogRead(potPin);
            return (sensorValue)*potScaling+potOffset;
          }
