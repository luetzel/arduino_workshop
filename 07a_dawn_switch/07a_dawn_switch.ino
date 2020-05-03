#define ledPin 9
#define potPin A0
#define ldrPin A1

void setup() {
  pinMode(ledPin, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin); // ADC 10 Bit 0 bis 1023
  int ldrValue = analogRead(ldrPin); // ADC 10 Bit 0 bis 1023
  //Serial.print("Poti: "); Serial.println(potValue);      // debug
  //Serial.print("LDR: "); Serial.println(ldrValue);
  //analogWrite(ledPin, map( potValue, 0, 1023, 0, 255) ); // DAC 8 Bit, 0 bis 255
  // Wenn-Dann-Sonst Funktion
  if (ldrValue <= potValue ) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  delay(50);
}
