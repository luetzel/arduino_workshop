/* Aufgabe:
Dieser Sketch soll eine LED blinken lassen und gleichzeitig auf
Benutzereingaben per Taster reagieren.

Möglichkeiten:
- non-blocking "delay()" Funktion
- Interrupt
*/

// Alias für die IO-Pins
#define ledPin 10 // LED-Pin 10 -> externe LED
#define LED_PIN 13 // LED-Pin 13 -> interne LED
#define tasterPin 2 // Taster-Pin 2

//Variablen
bool tasterStatus; // Variable zur Aufname des Tasterstatus
#define BLINK_TIME 5000
unsigned long time;       // type to store millis is very important!
unsigned long time_old;

// Einstellungen
void setup(){
 Serial.begin(9600);
 pinMode(LED_PIN, OUTPUT); // LED-Pin als Ausgang
 pinMode(ledPin, OUTPUT); // LED-Pin als Ausgang 
 pinMode(tasterPin, INPUT); // Taster-Pin als Eingang (hier externer Pull-Down Widerstand)
}

// Verarbeitung & Ausgabe
void loop(){
    time = millis();
    if (time - time_old > BLINK_TIME) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));   // toggle LED depending on previous state
    time_old = millis();
  }

//digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//delay(BLINK_TIME);             // wait for 5 seconds
//digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
//delay(BLINK_TIME);             // wait for a second
 
 tasterStatus = digitalRead(tasterPin);
 Serial.println(tasterStatus);
 if(tasterStatus == LOW)
    digitalWrite(ledPin, LOW);
 else
    digitalWrite(ledPin, HIGH);
}
