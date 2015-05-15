
//**********************************************************************************************//
//					DEFINES						 	//
//**********************************************************************************************//

#define         MOTOR_ANGLE_BUFFER       15             //Inputs with absolute value below this 
                                                        //number are ignored

//**********************************************************************************************//
//					GLOBAL VARIABLES				 	//
//**********************************************************************************************//

int desiredAngle = 0;
int desiredDirection = turnDirection;
int motorActive = false;

//**********************************************************************************************//
//				   FUNCTIONS DECLARATIONS				 	//
//**********************************************************************************************//

void updateFunctions();                  //This function contains all the other update functions and
                                        // is executed at the end of every loop
                                        
void motor_update();                     //Moves slightly closer to desiredAngle in desiredDirection
                                        
//**********************************************************************************************//
//					FUNCTIONS					 	//
//**********************************************************************************************//

void motor_update(){                    //Moves slightly closer to desiredAngle in desiredDirection
  if (abs(getAngle() - desiredAngle) < MOTOR_ANGLE_BUFFER ){//reached position
    motorOut(0);
    motorActive = false;
  }
  else if (motorActive != false) {
    motorOut(255*desiredDirection);
  }
}

void updateFunctions(){
  motor_update();			//Moves slightly closer to desiredAngle in desiredDirection
}
