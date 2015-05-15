
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

char getPosition();			//Gives the position whether [Closed:Open:Intermediate]

//**********************************************************************************************//
//					FUNCTIONS					 	//
//**********************************************************************************************//



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
