//**********************************************************************************************//
//					DEFINES						 	//
//**********************************************************************************************//

#define		PIN_MOTOR_A	        10		//Pin number
#define		PIN_MOTOR_B	        11		//Pin number
#define         MOTOR_DUTY_BUFFER       10              //Inputs with absolute value below this 
                                                        //number are ignored

//**********************************************************************************************//
//					GLOBAL VARIABLES				 	//
//**********************************************************************************************//

//**********************************************************************************************//
//				   FUNCTIONS DECLARATIONS				 	//
//**********************************************************************************************//

void motor_init();			//Motor initialization
int getAngle();				//Gives the angle rotation of motor
char getPosition();			//Gives the position whether [Closed:Open:Intermediate]

//**********************************************************************************************//
//					FUNCTIONS					 	//
//**********************************************************************************************//

// initialization

void motor_init(){
  pinMode(PIN_MOTOR_A,OUTPUT);
  pinMode(PIN_MOTOR_B,OUTPUT);
}

// actual motor driver function

void motorOut(int rotationalVelocity){
  int motorADutyCycle; int motorBDutyCycle;
  
  if (rotationalVelocity > MOTOR_DUTY_BUFFER)
  {motorADutyCycle = rotationalVelocity;  motorBDutyCycle=0;                   Serial.println("forwards");}
  
  else if (rotationalVelocity < -MOTOR_DUTY_BUFFER)
  {motorADutyCycle = 0;                   motorBDutyCycle=-rotationalVelocity; Serial.println("backwards");}
  
  else
  {motorADutyCycle = 0;                   motorBDutyCycle=0;                   Serial.println("stop");}
  
  analogWrite(PIN_MOTOR_A,motorADutyCycle);
  analogWrite(PIN_MOTOR_B,motorADutyCycle);
}
