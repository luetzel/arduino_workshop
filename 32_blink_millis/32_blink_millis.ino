// #define is an instruction for the C preprocessor and works like an
// alias. In the example below, LED_PIN is replaced by 13 before
// the code is compiled
#define LED_PIN 13
#define BLINK_TIME 1000
int long time;
int long time_old;

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
