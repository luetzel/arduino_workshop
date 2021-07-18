#define potPin A1
#define ldrPin A0
#define ledPin 13

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);
  int ldrValue = analogRead(ldrPin);
  if(ldrValue < potPin) {
    digitalWrite(ledPin,HIGH);
  }
  else {
    digitalWrite(ledPin,LOW);
  }
  Serial.print(potValue);
  Serial.print(" ");
  Serial.println(ldrValue);
  delay(1);
}
