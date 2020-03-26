int wert = 10230;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
byte byteH = highByte(wert);
byte byteL = lowByte(wert);
// Die Funktionen highByte() und lowByte() führen
// folgende Byte-Operationen durch:
byte byteh = wert >> 8;
byte bytel = wert & 0xFF;
Serial.println("\nAusgangswert");
printBits(wert);
Serial.println("\nBit Shift Operation");
printBits(wert >> 8);
Serial.println("\nBit Maskierung mit");
printBits(0xFF);
Serial.println("\nErgebnis der Bit Maskierung");
printBits(wert & 0xFF);
Serial.println("\nAusgabe als Hexadezimal-Wert");
Serial.print(byteh,HEX);
Serial.print(" ");
Serial.println(bytel,HEX);
Serial.println("Ausgabe mit highByte() und LowByte()");
Serial.print(byteH,HEX);
Serial.print(" ");
Serial.println(byteL,HEX);
Serial.print("Zwei Bytes zusammenfügen\n");
int value = byteH << 8 | byteL;
Serial.println(value); 
delay(1000);
while(1);
}

// Hilfsfunktion
void printBits(long int n) {
  byte numBits = 16;
  char b;
  char c = ' ';
  for (byte i = 0; i < numBits; i++) {
    // shift 1 and mask to identify each bit value
    b = (n & (1 << (numBits - 1 - i))) > 0 ? '1' : '0';
    Serial.print(b);
    if (i < (numBits - 1) && ((numBits-i - 1) % 4 == 0 )) Serial.print(c);
  }
}
