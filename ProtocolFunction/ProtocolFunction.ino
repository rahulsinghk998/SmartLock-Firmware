//==============operator op codes==============

/*

0X = reserved
1X = reserved

21 = change power
22 = change direction
23 = change openAngle
24 = change closedAngle
25 = change closedAngle
26 = change openClosedBuffer

31 = change angle
32 = change position

======reference ascii=========

o = 111;
c = 99;

*/

//=============================================

void recieveX(int command){
  // command is in format 0x000000 (3 bytes)
  int prefix = getByte(2);
  int operator = getByte(1);
  int operand = getByte(0);

  executeFunction(operator,operand);
}

void executeFunction(int operator, int operand){
  if (operator == 0x31){
    operand = byteToAngle(operand);
    changeAngle(operand);
  }
  else if (operator == 0x32){
    changePosition(operand);
  }
}

//================more mathy helper function=================

void ShiftRegisterLeftByte(int n){
  return n/0x100;
}

void getLeastSiginificantByte(int n){ // gets the least significant byte of n
  return n - n/0x100*0x100;
}

void getByte(int n, int k){ // gets the kth byte of n, starting from the least significant digit
  for (int i=0; i<=2, i++){n = n/0x100}
  return getLeastSignificantByte(n, 0x100);
}

void byteToAngle(int n){return n*360/255;}

void angleToByte(int n){return n*255/360;}
