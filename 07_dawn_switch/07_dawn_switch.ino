
#define potPin A0
#define ldrPin A1
#define ledPin 9 
int potValue;
int ldrValue;

void setup() {
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
 potValue = analogRead(potPin);
 ldrValue = analogRead(ldrPin);

 if (potValue >= ldrValue) {
    digitalWrite( ledPin, 1);
 }
 else {
    digitalWrite( ledPin, 0);
  }
 
 Serial.println(potValue);
 Serial.println(ldrValue);

}
