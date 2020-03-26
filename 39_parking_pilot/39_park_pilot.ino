#include <Wire.h>
#include <Ultrasonic.h>
 
//#define TRIGGER 3
//#define ECHO 4
#define BUZZER 5

 Ultrasonic ultrasonic(3, 4);

unsigned int distance;
unsigned long duration;
unsigned long duration_old;
unsigned long time_old;
unsigned long time_disp;

#define DEVICE_ADDRESS  0x20

byte bytearray[] =   { 0x00, // 0 0B00000000
                       0x80, // 1 0B10000000
                       0xC0, // 2 0B11000000
                       0xE0, // 3 0B11100000
                       0xF0, // 4 0B11110000
                       0xF8, // 5 0B11111000
                       0xFC, // 6 0B11111100
                       0xFE, // 7 0B11111110
                       0xFF};// 8 0B11111111

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ultrasonic.setTimeout(40000UL);
  Wire.begin();
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.requestFrom(DEVICE_ADDRESS,1);
  byte val = Wire.read();
  Wire.endTransmission();
  Serial.print("Status :");
  Serial.println(val, BIN);
  //pinMode(TRIGGER, OUTPUT);
  //pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  //duration = 0;
  // put your main code here, to run repeatedly:
  //for (int i=0; i < 2; i++) {
  //  duration = ping();
  //  duration += duration;
  //}
  //duration = duration / 3;
  //distance = duration / 2 / 29;
  distance = ultrasonic.read();
  Serial.println(distance);
  if (distance < 100) {
  beep(distance);
  show_distance(distance);
  }
  else {
  i2c_write(bytearray[8]);
  digitalWrite(BUZZER,LOW);
  }
  delay(10);
}

void beep(int distance)
{
  if (millis() - time_old > 30 + distance) {
    digitalWrite(BUZZER, !digitalRead(BUZZER));
    time_old = millis();
  }
}

void show_distance(int distance) {
  if (distance > 90) {
    i2c_write(bytearray[8]);
    }
  else if ((distance > 80 ) && ( distance <= 90 )) {
    i2c_write(bytearray[7]);
    }
  else if ((distance > 70 ) && ( distance <= 80 )) {
    i2c_write(bytearray[6]);
    }
  else if ((distance > 60 ) && ( distance <= 70 )) {
    i2c_write(bytearray[5]);
    }
  else if ((distance > 50 ) && ( distance <= 60 )) {
    i2c_write(bytearray[4]);
    }
  else if ((distance > 40 ) && ( distance <= 50 )) {
    i2c_write(bytearray[3]);
    }
  else if ((distance > 30 ) && ( distance <= 40 )) {
    i2c_write(bytearray[2]);
    }
  else if ((distance > 10 ) && ( distance <= 20 )) {
    i2c_write(bytearray[1]);
    }
  else {
    i2c_write(bytearray[0]);
    }  
}   

/*unsigned long ping() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  return duration;
}*/

void i2c_write(uint8_t val) {
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(val);
  Wire.endTransmission();
}
