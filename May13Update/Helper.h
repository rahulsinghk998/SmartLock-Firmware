
//**********************************************************************************************//
//					DEFINES						 	//
//**********************************************************************************************//

#define		MAX_ANGLE	180		//Motor Max Rotation Angle
#define		MIN_ANGLE	0		//Motor Min Rotation Angle
#define		OPEN_ANGLE	120		//Close angle for the door lock
#define		CLOSE_ANGLE	0		//Open angle for the door lock

//**********************************************************************************************//
//					GLOBAL VARIABLES				 	//
//**********************************************************************************************//

//**********************************************************************************************//
//				   FUNCTIONS DECLARATIONS				 	//
//**********************************************************************************************//

void turnMotor(int pos,int dir);         //Moves motor to angle pos, by direction dir
char getPosition();			//Gives the position whether [Closed:Open:Intermediate]

//**********************************************************************************************//
//					FUNCTIONS					 	//
//**********************************************************************************************//

// CURRENTLY IS NOT FINAL CODE, THIS IS JUST PLACEHOLDER THAT WORKS, REAALLY DUMB

void turnMotor(int pos,int dir){//Moves motor to angle pos, by direction dir.
  motorOut(dir*255);
  delay(4500);
  motorOut(0);
}

/*
	Returns the the position of the (open, closed, unknown) of the knob
*/
char getPosition(){ 
  char pos = 'j';
  int angle=getAngle();
  if (angle <= CLOSE_ANGLE) {pos = 'c';}
  else if (angle >= OPEN_ANGLE) {pos = 'o';}
  //if (angle < closedPot()) {pos = 'c';}
  //else if (angle > openPot()) {pos = 'o';}
  else {pos = 'm';}
  return pos;
}
