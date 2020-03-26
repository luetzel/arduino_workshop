#include <EEPROM.h>
int addr = 0;
int val = 42;
int len = EEPROM.length();

void setup() {
  Serial.begin(9600);
  Serial.print("My EEPROM can store ");
  Serial.print(len);
  Serial.println(" bytes");
  EEPROM.write(addr, val);
  Serial.println("Wrote successfully to EEPROM!");
}

void loop() {
  delay(1000);
}
