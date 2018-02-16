int countPin = 2;
int resetPin = 3;

void setup() {
  // put your setup code here, to run once:
pinMode(countPin, OUTPUT);
pinMode(resetPin, OUTPUT);
}

void loop() {
  for (int i = 1; i <= 9; i++) {
    digitalWrite(countPin, 1);
    delay(50);
    digitalWrite(countPin, 0);
    delay(950);
    }
    digitalWrite(resetPin, 1);
    delay(50);
    digitalWrite(resetPin, 0);
}
