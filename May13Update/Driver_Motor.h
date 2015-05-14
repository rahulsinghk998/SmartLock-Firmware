//**********************************************************************************************//
//					DEFINES						 	//
//**********************************************************************************************//

#define		PIN_MOTOR_A	        11		//Pin number
#define		PIN_MOTOR_B	        12		//Pin number
#define         MOTOR_DUTY_BUFFER       10              //Inputs with absolute value below this 
                                                        //number are ignored

//**********************************************************************************************//
//					GLOBAL VARIABLES				 	//
//**********************************************************************************************//

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

void motorOut(int rotationalVelocity){
  int motorADutyCycle; int motorBDutyCycle;
  
  if (rotationalVelocity > MOTOR_DUTY_BUFFER)
  {analogWrite(PIN_MOTOR_A, rotationalVelocity);digitalWrite(PIN_MOTOR_B, LOW);Serial.println("forwards");}
  
  else if (rotationalVelocity < -MOTOR_DUTY_BUFFER)
  {analogWrite(PIN_MOTOR_B, -rotationalVelocity);digitalWrite(PIN_MOTOR_A, LOW);Serial.println("backwards");}
  
  else
  {digitalWrite(PIN_MOTOR_A, LOW );digitalWrite(PIN_MOTOR_B, LOW);Serial.println("stop");}
}
