const int analogPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(analogPin);
  Serial.println(sensorValue);
  Serial.println(float(sensorValue) / 1023 * 5);
  delay(250);
}
