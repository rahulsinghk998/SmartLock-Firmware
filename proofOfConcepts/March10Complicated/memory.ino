
#include <EEPROM.h>
boolean restartOverride = true; // for debugging purposes, should normally be false

// use of EEPROM is as follows:
// EEPROM.write(123,234) writes the byte 234 to the address 123
// EEPROM.read(123) returns the byte stored at address 123
// you should be able to figure the rest from there.
// It seems like this should be hardcoded since there's no way to edit them, but 
// there is additional code I will have you write in the future that actually edits these values.

void startupSettings(){
  readSettings(); // I used readSettings twice, which is expensive (a couple seconds), 
  // but you only activate this function when you first turn
  // it on so for now it's acceptable.
  if ((settingsSet == 0) || (restartOverride)) {writeDefault();readSettings();}
} // settingsSet should really be a boolean.  The problem is that I'm writing it in EEPROM, which only stores bytes.

int addressSettingsSet = 0;
int addressOpenAngle = 1;
int addressClosedAngle = 2;
int addressPotBuffer = 3; // the tolerance of the potentiometer
int addressTurnDirection = 4; // 1 or -1
int addressPower = 5;

void writeDefault(){
  EEPROM.write(addressSettingsSet, 1);
  EEPROM.write(addressOpenAngle, 15);
  EEPROM.write(addressClosedAngle, 170);
  EEPROM.write(addressPotBuffer, 10);
  EEPROM.write(addressTurnDirection, 1);
  EEPROM.write(addressPower, 255);
}
      
void wipeMemory(){EEPROM.write(addressSettingsSet, 0);} // function not being used atm

void readSettings(){
  settingsSet = EEPROM.read(addressSettingsSet);
  openAngle = EEPROM.read(addressOpenAngle);
  closedAngle = EEPROM.read(addressClosedAngle);
  potBuffer = EEPROM.read(addressPotBuffer);
  turnDirection = EEPROM.read(addressTurnDirection);
  power = EEPROM.read(addressPower);}
