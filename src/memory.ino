
#include <EEPROM.h>
boolean restartOverride = false; // for debugging purposes, should normally be false

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

void startupSettings(){
  readSettings();
  if ((settingsSet == 0) || (restartOverride)) {writeDefault();readSettings();}
}
