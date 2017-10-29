
const int ledPin = 13; // LED-Pin 13
const int tasterPin = 8; // Taster-Pin 8
bool tasterStatus; // Variable zur Aufname des Tasterstatus

void setup(){
 pinMode(ledPin, OUTPUT); // LED-Pin als Ausgang 
 pinMode(tasterPin, INPUT); // Taster-Pin als Eingang
}

void loop(){
 tasterStatus = digitalRead(tasterPin);
 if(tasterStatus == LOW)
    digitalWrite(ledPin, LOW);
 else
    digitalWrite(ledPin, HIGH);
}
