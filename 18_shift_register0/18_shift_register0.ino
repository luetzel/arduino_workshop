/*
Beispielcode für die Kombination eines 74HC595 ShiftRegisters mit einer
7-Segment-Anzeige. Die Anschlüsse QA bis QH des ShiftRegisters werden
der Reihenfolge nach mit den Segmenten der 7-Segment-Anzeige verbunden.

QB  (Pin1) => b
QC  (Pin2) => c
QD  (Pin3) => d
QE  (Pin4) => e
QF  (Pin5) => f
QG  (Pin6) => g
QH  (Pin7) => h
GND (Pin8) => GND
Q7  (Pin9) => ---
MR  (Pin10) => VCC
SH  (Pin11) => D8
ST  (Pin12) => D9
OE  (Pin13) => GND
DS  (Pin14) => D10
QA  (Pin15) => a
VCC (Pin16) => VCC
*/

int taktPin = 8; 	// SH_CP
int speicherPin = 9; 	// ST_CP
int datenPin = 10; 	// DS

/*
Zur Darstellung der Zahlen von 0 bis 9 wird ein Array deklariert. Die Bitmuster wurden in
hexadezimaler Schreibweise in das Array geschrieben. Die Indizierung der Elemente beginnt mit '0'
Index                  0      1     2     3     4     5     6     7     8     9     10 */
const byte werte[] = { 0xFC,  0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6, 0xFF};

/* Zeichentabelle   
HEX   a b c d e f g dp  Zeichen
0xFC  1 1 1 1 1 1 0 0   0
0x60  0 1 1 0 0 0 0 0   1
0xDA  1 0 1 0 1 1 0 1   2
0xF2  1 1 1 1 0 0 1 0   3
0x66  0 1 1 0 0 1 1 0   4
0xB6  1 0 1 1 0 1 1 0   5
0xBE  1 0 1 1 1 1 1 0   6
0xE0  1 1 1 0 0 0 0 0   7
0xFE  1 1 1 1 1 1 1 0   8
0xF6  1 1 1 1 0 1 1 0   9
0xFF  1 1 1 1 1 1 1 1   alle
*/

void setup(){
  pinMode(taktPin, OUTPUT);
  pinMode(speicherPin, OUTPUT);
  pinMode(datenPin, OUTPUT);
}

void loop(){
  for (int i = 0; i < 10; i++){
    digitalWrite(speicherPin, LOW);
    // Abhängig davon welches Display verwendet wird (gemeinsame Anode oder Kathode), müssen die Bits der Array-Elemente invertiert werden.
    shiftOut(datenPin,taktPin,LSBFIRST,~werte[i]); // Last Significant Bit First; Letzte Stelle zuerst übertragen; NOT Operator zur Inversion der Bits (gem. Anode) 
    //shiftOut(datenPin,taktPin,LSBFIRST,werte[i]); // Last Significant Bit First; Letzte Stelle zuerst übertragen; NOT Operator zur Inversion der Bits (gem. Kathode) 
    digitalWrite(speicherPin, HIGH);
    delay(1000);
  }
}

