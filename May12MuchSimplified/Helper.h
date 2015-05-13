
//**********************************************************************************************//
//					GLOBAL VARIABLES				 	//
//**********************************************************************************************//

// THERE SHOULD BE NO REASON TO PUT GLOBAL VARIABLES HERE

//**********************************************************************************************//
//				   FUNCTIONS DECLARATIONS				 	//
//**********************************************************************************************//

void changePosition(char command);       //Moves motor to that position (open, closed)
void turnMotor(int pos,int dir);         //Moves motor to angle pos, by direction dir

//**********************************************************************************************//
//					FUNCTIONS					 	//
//**********************************************************************************************//

void changePosition(char command){//recieves either a "o" or a "c"
  int dir = turnDirection; int pos;
  if (command=='o') {pos = openAngle;   dir=dir;  turnMotor(pos,dir);} 
  if (command=='c') {pos = closedAngle; dir=-dir; turnMotor(pos,dir);}
  Serial.print(pos);Serial.print(dir);
}

// CURRENTLY IS NOT FINAL CODE, THIS IS JUST PLACEHOLDER THAT WORKS, REAALLY DUMB

void turnMotor(int pos,int dir){//Moves motor to angle pos, by direction dir.
  motorOut(dir*255);
  delay(3800);
  motorOut(0);
}
