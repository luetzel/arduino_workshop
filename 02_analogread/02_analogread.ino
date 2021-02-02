#define analogPin A0

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  int sensorValue = analogRead(analogPin);
  Serial.println(sensorValue);
  Serial.println(float(sensorValue) / 1023 * 5);
  delay(250);
}
