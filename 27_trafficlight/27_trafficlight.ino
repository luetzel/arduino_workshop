#define RED 2
#define YELLOW 3
#define GREEN 4
#define BTTN 5

void setup(){
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BTTN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BTTN) == HIGH)
    digitalWrite(RED, HIGH);
  else
    digitalWrite(YELLOW, HIGH);
    delay(500);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
    delay(2000);
    digitalWrite(YELLOW, HIGH);
    delay(1000);
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
}
