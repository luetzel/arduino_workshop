
const int ledPinBlink = 13; // Rote Blink-LED-Pin 13
const int ledPinTaster = 10; // Gelbe Taster-LED-Pin 10
const int tasterPin = 2; // Taster-Pin 8
bool tasterStatus; // Variable zur Aufname des Tasterstatus
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 200;

void setup(){
 pinMode(ledPinBlink, OUTPUT); // Blink-LED-Pin als Ausgang 
 pinMode(ledPinTaster, OUTPUT); // Taster-LED-Pin als Ausgang
 pinMode(tasterPin, INPUT_PULLUP); // Taster-Pin als Eingang
  attachInterrupt(digitalPinToInterrupt(tasterPin), toggle_led, RISING);
}

void loop(){
 // Blink-LED blinken lassen
 digitalWrite(ledPinBlink, HIGH); // Rote LED auf High-Pegel (5V)
 delay(1000); // Eine Sekunde warten
 digitalWrite(ledPinBlink, LOW); // Rote LED auf LOW-Pegel (0V)
 delay(1000); // Eine Sekunde warten
}

void toggle_led() {
if ( (millis() - lastDebounceTime) > debounceDelay) {  
  if(tasterStatus == 0) {
    digitalWrite(ledPinTaster, HIGH); // Gelbe LED auf High-Pegel (5V)
    lastDebounceTime = millis();
    tasterStatus = 1;
  }
  else 
  {
    digitalWrite(ledPinTaster, LOW); // Gelbe LED auf Low-Pegel (0V)
    lastDebounceTime = millis();
    tasterStatus = 0;
   }
  }
}
