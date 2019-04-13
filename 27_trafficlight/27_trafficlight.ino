#define RED 2
#define YELLOW 3
#define GREEN 4
#define BTTN 5

void setup(){
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BTTN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BTTN) == HIGH) {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
  }  
  else {
    delay(1000);
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, HIGH);
    delay(3000);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
    delay(6000);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
    delay(3000);
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    delay(6000);
  }
}
