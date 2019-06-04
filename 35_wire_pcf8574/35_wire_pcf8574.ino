/* Der pcf8574 Port Expander kann auch mit der Wire-Library
   festeuert werden. Auf die Prots P0 - P7 muss lediglich
   ein Byte geschrieben werden, das die Ausgänge auf HIGH bzw.
   LOW setzt. Der Status der Ports lässt sich durch lesen
   eines Bytes aus dem Port-Expander ermitteln.   
*/
#include <Wire.h>
#define DEVICE_ADDRESS  0x20

byte bytearray[] =   { 0x00, // 0
                       0x80, // 1
                       0xC0, // 2
                       0xE0, // 3
                       0xF0, // 4
                       0xF8, // 5
                       0xFC, // 6
                       0xFE, // 7
                       0xFF};// 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.requestFrom(DEVICE_ADDRESS,1);
  byte val = Wire.read();
  Wire.endTransmission();
  Serial.print("Status :");
  Serial.println(val, BIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i; i <= 7; i++) {
    i2c_write(~bytearray[i]);
    delay(100);
  }
  for (int i; i <= 7; i++) {
    i2c_write(bytearray[i]);
    delay(100);
  }
}

void i2c_write(uint8_t val) {
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(val);
  Wire.endTransmission();
}
