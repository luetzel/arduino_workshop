const unsigned int ldrPin= A0;
const unsigned int ledPin= 8;

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
int ldrValue = analogRead(ldrPin);

 if (ldrValue > 200) {
    digitalWrite(ledPin,HIGH);
 }
 else {
    digitalWrite(ledPin,LOW);
  }
 Serial.println(ldrValue);
 delay(100);
}
