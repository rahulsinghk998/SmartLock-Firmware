//*******************************************************************************************//
//                   			 INCLUDES         		                     //
//*******************************************************************************************//
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

//Include all the relevent Libraries on which this header file is dependent 
//eg include the library which contains the declaration for <BLE> module and its pins

//*******************************************************************************************//
//                   			 DEFINES         		                     //
//*******************************************************************************************//

#define        SLAVE_ADDR      0x68        //Slave address of Accelerometer//For MPU6050 its 0x68
#define        ACCEL_REG_XL    0x3B        //Accelerometer axes register which data will be stored//For MPU6050 Its 0x3B
#define        ACCEL_REG_XH    0x3C        //Needs to be changed which depends on Accelerometer
#define        ACCEL_REG_YL    0x3D
#define        ACCEL_REG_YH    0x3E
#define        ACCEL_REG_ZL    0x3F
#define        ACCEL_REG_ZH    0x40
#define        MAX_ANGLE    	180        //Motor Max Rotation Angle
#define        MIN_ANGLE    	0        //Motor Min Rotation Angle
#define        ANGLE_INCRE    	1        //decides the incrementation between the 2 consecutive angles
#define        OPEN_ANGLE    	120        //Close angle for the door lock
#define        CLOSE_ANGLE    	50        //Open angle for the door lock

//*******************************************************************************************//
//                    			GLOBAL VARIABLES		                     //
//*******************************************************************************************//

int angle=0;            //Stores the angle calculated from the received data
SoftwareSerial BLE(2,3);

//*******************************************************************************************//
//                   			FUNCTIONS DECLARATIONS                     	     //
//*******************************************************************************************//
void accel_init();            //Accelerometer initialization//Depends on the type of accelerometer
int getData(int reg_addr);    //returns data from 2 set of consecutive registers//Can be made for 1 register
int getAngle();                //Gives the angle rotation of motor
char getPosition();            //Gives the position whether [Closed:Open:Intermediate]
void jamAlert();            //Debug purpose to give the jamming alert//currently in progress

//******************************************************************************************//
//                    			    FUNCTIONS		                            //
//******************************************************************************************//
/*
    Initialialization of TWI [Two wire Interface](I2C) for the Accelerometer so that the I2C pins
    gets activated.
*/
void accel_init(){
    Wire.begin();
        Wire.beginTransmission(SLAVE_ADDR);      //transmission with this address
        Wire.write(0x6B);          //first specifies power management address of MCU
        Wire.write(0);               //awakes MCU by sending 0 to above register address
        Wire.endTransmission(true);
    /* Code to set some initial registers of accelerometer
       before starting the actual transmission */
    /* e.g setting the power management setting in MPU 6050
       and also selecting the desired range of accelerometer
       which is very essestial part as it determines the
       resolution of our angle */
}

/*     Function:    The main aim of this function is to give the data stored in particular registers
    Parameter:    Take the register address from which data has to extracted
       Retuns:        It returns the data stored in 2 consecutive addresses of accelerometer
*/
int getData(int reg_addr){
    unsigned int data=0;
    Wire.beginTransmission(SLAVE_ADDR);     //starting the communication again
      Wire.write(reg_addr);              //start with this register address (its the first data register
      Wire.endTransmission(false);          //continue to read data
      Wire.requestFrom(SLAVE_ADDR,2,true);      //request the slave to send the 2 byte data
      data=Wire.read()<<8|Wire.read();      //data is 16 bit data .the data is automatically read sequently

//Need to add extra loop and code for error codes returned by  Wire.endTransmission//
    Wire.endTransmission();
return data;
}

/*
    Function:     map(value, fromLow, fromHigh, toLow, toHigh)
    Description:    Re-maps a number from one range to another.That is,a value of fromLow would
            get mapped to toLow, a value of fromHigh to toHigh, values in-between to values
            in-between.
*/
int getAngle(){
    return map(getData(ACCEL_REG_XL),-16384,16384,0,180);
}

/*
    Returns the the position of the (open, closed, unknown) of the knob
*/
char getPosition(){
  char pos = 'j';
  angle=getAngle();
  if (angle <= CLOSE_ANGLE) {pos = 'c';}
  else if (angle >= OPEN_ANGLE) {pos = 'o';}
  //if (angle < closedPot()) {pos = 'c';}
  //else if (angle > openPot()) {pos = 'o';}
  else {pos = 'm';}
  return pos;
}

//I have commented out these functions as I have declared the <OPEN_ANGLE> and <CLOSE_ANGLE> in <#define>
//int closedPot(){return (closedAngle+potBuffer*turnDirection);}// returns angle of the lock for it to be considered "closed"
//int openPot(){return (openAngle-potBuffer*turnDirection);}    // ditto

/*
    Sends the Postion of the Motor to bluetooth. Tells whether the lock is [closed:open:intermediate]
    position based on the angle readings.
*/

void givePosition(){
    BLE.println(getPosition());                
}         

/*    
    Prints the angle of the motor rotated. It uses the function <getAngle()>
*/
void giveAngle(){
    BLE.println(getAngle());
}

/*
    Its currently in development phase. Basically it will be used to determine whether the
    lock is jamed or not. There is some thinking required to design the function. It requires
    the tracking of the previous readings as well as change of angle with respect to time.
*/
void jamAlert(){
    char text='j'; BLE.println(text);            
}     


