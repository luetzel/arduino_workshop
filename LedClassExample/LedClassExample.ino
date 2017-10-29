#include "Led.h"

Led statusLed(LED_BUILTIN);
const int blinktime = 500;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  statusLed.on();
  delay(blinktime);
  statusLed.off();
  delay(blinktime);
}
