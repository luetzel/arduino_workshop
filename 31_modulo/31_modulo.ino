// Unter modulo versteht man den Rest einer Division mit einer
// ganzen Zahl. Wird z.B. 13 durch 5 dividiert, ergibt das 2
// mit dem Rest 3
// Der Modulo-Operator liefert den Rest der Division und wird
// mit einem %-Zeichen ausgedrückt.

char fe[4];  // Array bzw. Feld mit 4 Zeichen
int z = 157; // Ganzzahl

void setup() {
  Serial.begin(9600);
  fe[0] = z / 100 + '0';        // Zerlegen einer 3-stelligen Zahl
  fe[1] = (z / 10) % 10 + '0';  // '0' liefert den ASCII-Code für die Zahl 0 => 0x30
  fe[2] = z % 10 + '0';         // liefert die letzte Stelle der Zahl
  fe[3] = '\0';                 // Ende der Zeichenkette
  Serial.print(fe);
}

void loop() {

}
