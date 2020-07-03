/* Der pcf8574 Port Expander kann auch mit der Wire-Library
   angesteuert werden. Auf die Ports P0 - P7 muss lediglich
   ein Byte geschrieben werden, das die Ausgänge auf HIGH bzw.
   LOW setzt. Der Status der Ports lässt sich durch lesen
   eines Bytes aus dem Port-Expander ermitteln.   
*/
#include <Wire.h> // Two-Wire
#define DEVICE_ADDRESS  0x20
                                               // P        01234567
byte bytearray[] =   { 0b00000000, // 0 // 0b00000000
                                    0x80, // 1 // 0b10000000
                                    0b11000000, // 2 // 0b11000000
                                    0xE0, // 3 // 0b11100000
                                    0xF0, // 4
                                    0xF8, // 5
                                    0xFC, // 6
                                    0xFE, // 7
                                    0xFF};// 8 // 0b11111111

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.requestFrom(DEVICE_ADDRESS,1);
  byte val = Wire.read();
  //Wire.endTransmission(); not required, see https://github.com/Koepel/How-to-use-the-Arduino-Wire-library/wiki/Common-mistakes
  Serial.print("Status :");
  Serial.println(val, BIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 1; i <= 7; i++) {
    i2c_write(~bytearray[ i ]);
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
