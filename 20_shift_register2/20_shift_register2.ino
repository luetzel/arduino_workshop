int taktPin = 8;
int speicherPin = 9;
int datenPin = 10;

/* Shift Register
OE (Pin13) => GND
MR (Pin10) => VCC
*/

byte wert = 0; // Gemeisame Anode
//byte wert = 255; // Gemeinsame Cathode

void setup() {
  pinMode(taktPin, OUTPUT);
  pinMode(speicherPin, OUTPUT);
  pinMode(datenPin, OUTPUT);

}

void loop() {
  digitalWrite(speicherPin, LOW);
  shiftOut(datenPin, taktPin, MSBFIRST, wert);
  digitalWrite(speicherPin, HIGH);
  delay(20);
}
