
// Der folgende Code funktioniert nicht wie erhofft ...
#define ledPinBlink 13 // Rote Blink-LED-Pin 13
#define ledPinTaster 10 // Gelbe Taster-LED-Pin 10
#define tasterPin 8 // Taster-Pin 8
bool tasterStatus; // Variable zur Aufname des Tasterstatus
void setup(){
 pinMode(ledPinBlink, OUTPUT); // Blink-LED-Pin als Ausgang 
 pinMode(ledPinTaster, OUTPUT); // Taster-LED-Pin als Ausgang
 pinMode(tasterPin, INPUT_PULLUP); // Taster-Pin als Eingang
}

void loop(){
 // Blink-LED blinken lassen
 digitalWrite(ledPinBlink, HIGH); // Rote LED auf High-Pegel (5V)
 delay(1000); // Eine Sekunde warten
 digitalWrite(ledPinBlink, LOW); // Rote LED auf LOW-Pegel (0V)
 delay(1000); // Eine Sekunde warten
 // Abfrage des Taster-Status
 tasterStatus = digitalRead(tasterPin);
 if(tasterStatus == LOW)
 digitalWrite(ledPinTaster, HIGH); // Gelbe LED auf High-Pegel (5V)
 else
 digitalWrite(ledPinTaster, LOW); // Gelbe LED auf Low-Pegel (0V)
}
