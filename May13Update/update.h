// These are the functions that will run every loop.  
// The existence of these functions is so that everything works off the same delay() function

//**********************************************************************************************//
//					DEFINES						 	//
//**********************************************************************************************//

#define MOTOR_LOOP_BUFFER      10    // degrees at which motor can have error

//**********************************************************************************************//
//					GLOBAL VARIABLES				 	//
//**********************************************************************************************//

int desiredAngle = 0
int desiredDirection = turnDirection
boolean motorActive = false

//**********************************************************************************************//
//				   FUNCTIONS DECLARATIONS				 	//
//**********************************************************************************************//



//**********************************************************************************************//
//					FUNCTIONS					 	//
//**********************************************************************************************//

void motor_update(){
  if motorActive {
    if ( abs( getAngle() - desiredAngle ) > MOTOR_LOOP_BUFFER ) {
      motorOut(255*desiredDirection); }
     else {
       motorOut(0);
       motorActive = false; 
     }
  }
