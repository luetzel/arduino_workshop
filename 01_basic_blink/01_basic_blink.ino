// #define is an instruction for the C preprocessor and works like an
// alias. In the example below, LED_PIN is replaced by 13 before
// the code is compiled
int LED_PIN = 13;
//#define LED_PIN 13
#define BLINK_TIME 100

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(BLINK_TIME);             // wait for a second
  digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(BLINK_TIME);             // wait for a second
}
