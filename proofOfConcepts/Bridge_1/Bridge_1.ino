//=============setup====================

#include <SoftwareSerial.h>
SoftwareSerial BT(2, 4); SoftwareSerial WIFI(3,5); SoftwareSerial BLE(10,11);// RX, TX

//===============main functions=================

void setup() {
  BLE.begin(9600); BT.begin(9600); WIFI.begin(9600);
  pinMode(13,OUTPUT);
}

void BLEWrite(char val){
  BLE.write("asdfijashdfilajkghdalisgvhaliurgha;egha;ijghauifgyhasaseivuhsuldgvhaoilvufbhao8wergfalijgvhalfgvuyaeirfgba;eighaergsrthQWSFAWERTYHhdgalwergh;auhigaiejghasgd"); delay(10);
  BLE.write(val);}

void loop() {
  if (BT.available()) {BLEWrite(BT.read());}
  if (WIFI.available()) {BLE.write(WIFI.read());}
  if (BLE.available()) {BT.write(Serial.read());WIFI.write(Serial.read());}
}
