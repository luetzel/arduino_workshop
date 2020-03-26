#include <LiquidCrystal_PCF8574.h>
#include <Ultrasonic.h>
#include <Wire.h>

#define DEVICE_ADDRESS  0x20
#define BUZZERPIN 9
#define DURATION 100

LiquidCrystal_PCF8574 lcd(0x3f);
Ultrasonic ultrasonic(7, 8);

int distance, distance_old;
long time, time_old;
               
byte bytearray[] =   { 0x00, // 0 0B00000000
                       0x80, // 1 0B10000000
                       0xC0, // 2 0B11000000
                       0xE0, // 3 0B11100000
                       0xF0, // 4 0B11110000
                       0xF8, // 5 0B11111000
                       0xFC, // 6 0B11111100
                       0xFE, // 7 0B11111110
                       0xFF};// 8 0B11111111
void setup()
{
  Wire.begin();
  Wire.beginTransmission(DEVICE_ADDRESS);
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.setBacklight(0);
  pinMode(BUZZERPIN, OUTPUT);
} // setup()

void loop()
{   distance += constrain(ultrasonic.read(), 1, 400);
    distance += constrain(ultrasonic.read(), 1, 400);
    distance += constrain(ultrasonic.read(), 1, 400);
    distance = distance/3;
  if (abs(distance - distance_old) > 5) {
    Serial.print("Distance in CM: ");
    Serial.print(distance);
    Serial.println(" cm");
    if (distance > 400){
      show("*****************");
      i2c_write(~bytearray[8]);
    }
    else if (distance > 350){
      show("****************");
      i2c_write(~bytearray[8]);
    }
    else if (distance > 300){
      show("***************");
      i2c_write(~bytearray[7]);
    }
    else if (distance > 250){
      show("**************");
      i2c_write(~bytearray[7]);
    }
    else if (distance > 200){
      show("*************");
      i2c_write(~bytearray[6]);
    }
    else if (distance > 150){
      show("************");
      i2c_write(~bytearray[6]);
    }
    else if (distance > 100){
      show("**********");
      i2c_write(~bytearray[5]);
    }
    else if (distance > 90){
      show("*********");
      i2c_write(~bytearray[5]);
    }
    else if (distance > 80){
      show("********");
      i2c_write(~bytearray[4]);
    }
    else if (distance > 70){
      show("*******");
      i2c_write(~bytearray[4]);
    }
    else if (distance > 60){
      show("******");
      i2c_write(~bytearray[3]);
    }
    else if (distance > 50){
      show("*****");
      i2c_write(~bytearray[3]);
    }
    else if (distance > 40){
      show("****");
      i2c_write(~bytearray[2]);
    }
    else if (distance > 30){
      show("***");
      i2c_write(~bytearray[2]);
    }
    else if (distance > 20){
      show("**");
      i2c_write(~bytearray[1]);
    }
    else if (distance > 10){
      show("*");
      i2c_write(~bytearray[1]);
    }
    distance_old = distance;
  }
  delay(100);
  buzz(distance);
} // loop()

void show(String string) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(string);
      lcd.setCursor(0, 1);
      lcd.print(distance);
}

void i2c_write(uint8_t val) {
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(val);
  Wire.endTransmission();
}

void buzz(int pause) {
time = millis();
  if (time - time_old > DURATION + pause) {
    digitalWrite(BUZZERPIN, !digitalRead(BUZZERPIN));
    time_old = millis();
}
}
