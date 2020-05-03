#include <PCF8574.h>
#include <Wire.h>

PCF8574 expander(0x20);

// Anschlüsse konfigurieren
#define echoPin 8
#define trigPin 7
int distance;

// Pins als Input/Output konfigurieren
void setup() {
  expander.begin();
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// Schleife
void loop()
{
  distance = getDistance(trigPin, echoPin);
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();
  expander.write8(255);
  if (distance < 10) {
    //expander.write(0,0);
    expander.write8(0xFE);
    //Serial.println(expander.read8(), HEX);
    }
  else if (distance < 20) {
    //expander.write(0,0);
    //expander.write(1,0);
    expander.write8(0xFC);
    //Serial.println(expander.read8(), HEX);
    }
  else if (distance < 30) {
    //expander.write(0,0);
    //expander.write(1,0);
    //expander.write(2,0);
    expander.write8(0xF8);
    //Serial.println(expander.read8(), HEX);
    }
  else if (distance < 40) {
    //expander.write(0,0);
    //expander.write(1,0);
    //expander.write(2,0);
    //expander.write(3,0);
    expander.write8(0xF0);
    //Serial.println(expander.read8(), HEX);
    }
  else if (distance < 50) {
    //expander.write(0,0);
    //expander.write(1,0);
    //expander.write(2,0);
    //expander.write(3,0);
    //expander.write(4,0);
    expander.write8(0xE0);
    //Serial.println(expander.read8(), HEX);
    
    }
  else if (distance < 60) {
    //expander.write(0,0);
    //expander.write(1,0);
    //expander.write(2,0);
    //expander.write(3,0);
    //expander.write(4,0);
    //expander.write(5,0);
    expander.write8(0xC0);
    //Serial.println(expander.read8(), HEX);
    }
    else if (distance < 70) {
    //expander.write(0,0);
    //expander.write(1,0);
    //expander.write(2,0);
    //expander.write(3,0);
    //expander.write(4,0);
    //expander.write(5,0);
    //expander.write(6,0);
    expander.write8(0x80);
    //Serial.println(expander.read8(), HEX);
    }
    else if (distance > 70) {
    //expander.write(0,0);
    //expander.write(1,0);
    //expander.write(2,0);
    //expander.write(3,0);
    //expander.write(4,0);
    //expander.write(5,0);
    //expander.write(6,0);
    //expander.write(7,0);
    expander.write8(0x00);
    //Serial.println(expander.read8(), HEX);
    }
  delay(100);
}

// Funktion zum Auslesen der Distanz in cm
int getDistance(int trigPin, int echoPin)
{
  long duration, cm;
  // Ping auslösen
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  
  /* Warten bis das Echo eingetroffen ist. Leider "frieren" manche Sensoren ein, wenn kein
  Echo empfangen wird. Deshalb wird hier ein "Timeout" von 30 ms eingestellt. pulseIn liefert
  dann den Wert '0'. 20 ms entsprechen einer Distanz von ca. 3 m */
  duration = pulseIn(echoPin, HIGH, 30000);

  // Wenn kein Echo empfangen erfolgt ein Reset des Sensors
  if(duration == 0) // Timeout!
    {
    pinMode(echoPin, OUTPUT); // echoPin als OUTPUT konfigurieren
    digitalWrite(echoPin, LOW); // echoPin auf LOW Pegel setzen
    delayMicroseconds(200);
    pinMode(echoPin, INPUT); // echoPin wieder als INPUT konfigurieren
    }
  else if (duration != 0) {
    cm = microsecondsToCentimeters(duration);
    return constrain(cm, 5, 400); // Wertebereich auf 5 bis 400 cm beschränken
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
