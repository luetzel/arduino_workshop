#define LEDPIN 10
#define BUTTONPIN 2
bool status;

void setup(){
  pinMode(LEDPIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTONPIN), toggle_led, RISING);
}

void loop(){
   digitalWrite(LED_BUILTIN, HIGH);
   delay(5000);
   digitalWrite(LED_BUILTIN, LOW);
   delay(5000);
}

void toggle_led() {
   if ( status == 0) {
      digitalWrite(LEDPIN, HIGH);
      status = 1;
   }
else {
      digitalWrite(LEDPIN, LOW);
      status = 0;
   }
}
