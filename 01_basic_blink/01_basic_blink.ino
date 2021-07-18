//int LED_PIN = 10;
//int BLINK_TIME = 200;

#define LED_PIN 13

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  if (sensorValue > 800) {
  digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
 
  digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
}
