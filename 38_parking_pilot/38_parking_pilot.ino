#define TRIGGER 3
#define ECHO 4
#define BUZZER 5

unsigned int distance;
unsigned long duration;
unsigned long time_old;

void setup()
{
 // put your setup code here, to run once:
 unsigned int distance;
 unsigned long duration;
 unsigned long time_old;
 Serial.begin(115200);
 pinMode(TRIGGER, OUTPUT);
 pinMode(ECHO, INPUT);
 pinMode(BUZZER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // put your setup code here, to run once:
  duration = ping();
  distance = duration / 2 / 29;
  Serial.println(distance);
  beep(distance);
  delay(30);
}

void beep(int distance)
{
  if (millis() - time_old > 30 + distance) {
    digitalWrite(BUZZER, !digitalRead(BUZZER));
    time_old = millis();
  }
}

unsigned long ping() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  return duration;
}
