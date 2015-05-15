
//**********************************************************************************************//
//					DEFINES						 	//
//**********************************************************************************************//

#define		PIN_MOTOR_A	        11		//Pin number
#define		PIN_MOTOR_B	        12		//Pin number
#define         MOTOR_DUTY_BUFFER       10              //Inputs with absolute value below this 
                                                        //number are ignored
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

void motor_init();			//Motor initialization
void motorOut(int rotationalVelocity);  //Sets motor rotational velocity

//**********************************************************************************************//
//					FUNCTIONS					 	//
//**********************************************************************************************//

// initialization

void motor_init(){
  pinMode(PIN_MOTOR_A,OUTPUT);
  pinMode(PIN_MOTOR_B,OUTPUT);
}


//Moves motor to angle pos, by direction dir
void turnMotor(int pos,int dir){//Moves motor to angle pos, by direction dir.
  desiredAngle = pos;
  desiredDirection = dir;
  motorActive = true;
}

//Moves motor to that position (open, closed)
void changePosition(char command){//recieves either a "o" or a "c"
  int dir = turnDirection; int pos;
  if (command=='o') {pos = openAngle;   dir=dir;  turnMotor(pos,dir);} 
  if (command=='c') {pos = closedAngle; dir=-dir; turnMotor(pos,dir);}
  Serial.print(pos);Serial.print(dir);
}


//Moves slightly closer to desiredAngle in desiredDirection
//This function contains all the other update functions and is executed at the end of every loop
void controlMotor()

{                    
  
  //Moves slightly closer to desiredAngle in desiredDirection
  if (abs(getAngle() - desiredAngle) < MOTOR_ANGLE_BUFFER )
  {
    //reached position
    motorOut(0);
    motorActive = false;
  }
  else if (motorActive != false) {
    motorOut(255*desiredDirection);
  }
}


// actual motor driver function

void motorOut(int voltage){
  int dutyCycle = voltage;
  
  if (dutyCycle > MOTOR_DUTY_BUFFER)
  {analogWrite(PIN_MOTOR_A, dutyCycle);analogWrite(PIN_MOTOR_B, 0);Serial.println("forwards");}
  
  else if (dutyCycle < -MOTOR_DUTY_BUFFER)
  {analogWrite(PIN_MOTOR_B, -dutyCycle);analogWrite(PIN_MOTOR_A, 0);Serial.println("backwards");}
  
  else
  {analogWrite(PIN_MOTOR_A, 0);analogWrite(PIN_MOTOR_B, 0);Serial.println("stop");}
}
