/* Der pcf8574 Port Expander kann auch mit der Wire-Library
   angesteuert werden. Auf die Ports P0 - P7 muss lediglich
   ein Byte geschrieben werden, das die Ausgänge auf HIGH bzw.
   LOW setzt. Der Status der Ports lässt sich durch lesen
   eines Bytes aus dem Port-Expander ermitteln.   
*/
#include <Wire.h>
#define DEVICE_ADDRESS  0x20

byte bytearray[] =   { 0x00, // 0b00000000 // 0
                                    0x80, // 0b10000000 // 1
                                    0x40, // 0b01000000
                                    0x20, // 0b00100000
                                    0x10, // 0b00010000
                                    0x08, // 0b00001000
                                    0x04, // 0b00000100
                                    0x02, // 0b00000010
                                    0x01};// 0b00000001

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
  for (int i = 1; i <= 8; i++) {
    i2c_write(~bytearray[i]);
    delay(100);
  }
  
for (int j = 8; j >= 1; j--) {
  i2c_write(~bytearray[j]);
  Serial.println(j);
  delay(100);
 }

}

void i2c_write(uint8_t val) {
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(val);
  Wire.endTransmission();
}
