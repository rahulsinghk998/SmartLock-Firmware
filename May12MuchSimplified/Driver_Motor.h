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
