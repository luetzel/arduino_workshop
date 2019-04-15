/*
 Lese jedes Byte des internen EEPROMS
 */
#include <EEPROM.h>
int address = 0;
byte value;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
}

void loop() {
  value = EEPROM.read(address);
  Serial.print(address);
  Serial.print("\t");
  Serial.print(value, DEC);
  Serial.println();

  address = address + 1;
  if (address == EEPROM.length()) {
    address = 0;
  }

  delay(500);
}
