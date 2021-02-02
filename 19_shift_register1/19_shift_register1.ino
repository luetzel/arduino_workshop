#define taktPin 2 // SH_CP
#define speicherPin 3 // ST_CP
#define datenPin 4 // DS

/* Shift Register
OE (Pin13) => GND
MR (Pin10) => VCC
*/

int datenArray[] = {1,1,1,1,1,1,1,1}; // gemeinsame Kathode
//int datenArray[] = {0,0,0,0,0,0,0,0}; // gemeinsame Anode

void setup() {
  pinMode(taktPin, OUTPUT);
  pinMode(speicherPin, OUTPUT);
  pinMode(datenPin, OUTPUT);
  resetPins();
  setzePins(datenArray);
  digitalWrite(speicherPin, HIGH);
}

void loop() {
  //leer
}

void resetPins() {
  digitalWrite(taktPin, LOW);
  digitalWrite(speicherPin, LOW);
  digitalWrite(datenPin, LOW);
  }

void setzePins(int daten[]) {
  for (int i = 0; i < 8; i++) {
    resetPins();
    digitalWrite(datenPin, daten[i]);
    delay(20);
    digitalWrite(taktPin, HIGH);
    delay(20);
    }
  }
