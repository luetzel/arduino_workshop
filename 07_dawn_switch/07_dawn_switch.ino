#define ldrPin A1
#define ledPin 13

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
int ldrValue = analogRead(ldrPin);

 if (600 > ldrValue) {
    digitalWrite(ledPin,HIGH);
 }
 else {
    digitalWrite(ledPin,LOW);
  }
 Serial.println(ldrValue);
}
