// Anschlüsse konfigurieren
#define echoPin 8
#define trigPin 7 

// Pins als Input/Output konfigurieren
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// Schleife
void loop()
{
  Serial.print(getDistance(trigPin, echoPin));
  Serial.print(" cm");
  Serial.println();

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
