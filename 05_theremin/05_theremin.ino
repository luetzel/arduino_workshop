#define speakerPin 12
#define analogPin A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(analogPin);
  Serial.println(sensorValue);
  Serial.println(float(sensorValue) / 1023 * 5);
  int pitch = 200 + sensorValue / 10;
  tone(speakerPin, pitch);
}
