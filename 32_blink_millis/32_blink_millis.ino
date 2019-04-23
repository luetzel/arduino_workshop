// blink example without delay
#define LED_PIN 13
#define BLINK_TIME 1000
unsigned long time;       // type to store millis is very important!
unsigned long time_old;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  time = millis();
  if (time - time_old > BLINK_TIME) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));   // toggle LED depending on previous state
    time_old = millis();
  }
}
