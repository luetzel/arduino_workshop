#define taktPin 2
#define speicherPin 3
#define datenPin 4

/* Shift Register
OE (Pin13) => GND
MR (Pin10) => VCC
*/

//byte wert = 0; // Gemeisame Anode
byte wert = 255; // Gemeinsame Kathode

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
