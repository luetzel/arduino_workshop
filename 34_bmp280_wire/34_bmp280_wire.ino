/*
Dieses Code-Beispiel zeigt wie der Bosch BMP280 Sensor mithilfe der Wire-Library ausgelesen wird.
https://github.com/JAICHANGPARK/Arduino_BMP280/blob/master/BMP280.ino
Wesentlich einfacher geht es mit einer der vielen Libraries, die man für diesen Sensor findet.
Auch wenn der Code sehr komplex aussieht, ist das Auslesen der Sensordaten recht simpel. Diese
stecken im Speicherregister des Sensors und werden als ein bzw. mehrere Bytes ausgelesen und
in für uns lesbare Form gebracht. Dabei berücksichtigt werden u.a. Kalibrierwerte, die der 
Hersteller in den Registern untergebracht hat.
*/
#include <Wire.h>
#include "Arduino.h"
#include <math.h>

#define BMP280_ADDRESS  0x76
#define BMP280_CHIPID   0x58

const float seaLevelhPa = 1013.25f;
int32_t t_fine;

enum{
  
      BMP280_REGISTER_DIG_T1              = 0x88,
      BMP280_REGISTER_DIG_T2              = 0x8A,
      BMP280_REGISTER_DIG_T3              = 0x8C,

      BMP280_REGISTER_DIG_P1              = 0x8E,
      BMP280_REGISTER_DIG_P2              = 0x90,
      BMP280_REGISTER_DIG_P3              = 0x92,
      BMP280_REGISTER_DIG_P4              = 0x94,
      BMP280_REGISTER_DIG_P5              = 0x96,
      BMP280_REGISTER_DIG_P6              = 0x98,
      BMP280_REGISTER_DIG_P7              = 0x9A,
      BMP280_REGISTER_DIG_P8              = 0x9C,
      BMP280_REGISTER_DIG_P9              = 0x9E,

      BMP280_REGISTER_CHIPID              = 0xD0,
      BMP280_REGISTER_VERSION             = 0xD1,
      BMP280_REGISTER_SOFTRESET           = 0xE0,

      BMP280_REGISTER_CAL26               = 0xE1,  // R calibration stored in 0xE1-0xF0

      BMP280_REGISTER_CONTROL             = 0xF4,
      BMP280_REGISTER_CONFIG              = 0xF5,
      BMP280_REGISTER_PRESSUREDATA        = 0xF7,
      BMP280_REGISTER_TEMPDATA            = 0xFA,
};
    
typedef struct
{
      uint16_t dig_T1;
      int16_t  dig_T2;
      int16_t  dig_T3;

      uint16_t dig_P1;
      int16_t  dig_P2;
      int16_t  dig_P3;
      int16_t  dig_P4;
      int16_t  dig_P5;
      int16_t  dig_P6;
      int16_t  dig_P7;
      int16_t  dig_P8;
      int16_t  dig_P9;

      uint8_t  dig_H1;
      int16_t  dig_H2;
      uint8_t  dig_H3;
      int16_t  dig_H4;
      int16_t  dig_H5;
      int8_t   dig_H6;
      
} bmp280_calib_data;

bmp280_calib_data  bmp280_calib;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));
  bmp280_Write(BMP280_REGISTER_CONTROL, 0x3F);
  readCoefficients();
  
}

void loop() {
  // put your main code here, to run repeatedly:\
  
  Serial.print("Unit : [hPa]"); Serial.println(readPressure()/100);
  Serial.print("Unit : [m]"); Serial.println(readAltitude(seaLevelhPa));
  Serial.print("Unit : [C]"); Serial.println(readTemp());
 
  delay(500);
}
void bmp280_Write(byte reg, byte value)
{
    Wire.begin();
    Wire.beginTransmission(BMP280_ADDRESS);
    Wire.write((uint8_t)reg);
    Wire.write((uint8_t)value);
    Wire.endTransmission();
}
uint16_t bmp280_read16(byte reg)
{
    uint16_t value;

    Wire.beginTransmission(BMP280_ADDRESS);
    Wire.write((uint8_t)reg);
    Wire.endTransmission();
    Wire.requestFrom(BMP280_ADDRESS,2);
    value = (Wire.read() << 8) | Wire.read();
    
    return value;
}

int16_t readS16(byte reg)
{
  return (int16_t)bmp280_read16(reg);

}

int16_t readS16_LE(byte reg)
{
  return (int16_t)read16_LittleEndian(reg);

}


uint16_t read16_LittleEndian(byte reg) {
  uint16_t temp = bmp280_read16(reg);
  return (temp >> 8) | (temp << 8);
}

uint32_t bmp280_read24(byte reg)
{
    uint32_t value;

    Wire.beginTransmission(BMP280_ADDRESS);
    Wire.write((uint8_t)reg);
    Wire.endTransmission();
    Wire.requestFrom(BMP280_ADDRESS, 3);
    
    value = Wire.read();
    value <<= 8;
    value |= Wire.read();
    value <<= 8;
    value |= Wire.read();

    return value;
}

void readCoefficients(void)
{
    bmp280_calib.dig_T1 = read16_LittleEndian(BMP280_REGISTER_DIG_T1);
    bmp280_calib.dig_T2 = readS16_LE(BMP280_REGISTER_DIG_T2);
    bmp280_calib.dig_T3 = readS16_LE(BMP280_REGISTER_DIG_T3);

    bmp280_calib.dig_P1 = read16_LittleEndian(BMP280_REGISTER_DIG_P1);
    bmp280_calib.dig_P2 = readS16_LE(BMP280_REGISTER_DIG_P2);
    bmp280_calib.dig_P3 = readS16_LE(BMP280_REGISTER_DIG_P3);
    bmp280_calib.dig_P4 = readS16_LE(BMP280_REGISTER_DIG_P4);
    bmp280_calib.dig_P5 = readS16_LE(BMP280_REGISTER_DIG_P5);
    bmp280_calib.dig_P6 = readS16_LE(BMP280_REGISTER_DIG_P6);
    bmp280_calib.dig_P7 = readS16_LE(BMP280_REGISTER_DIG_P7);
    bmp280_calib.dig_P8 = readS16_LE(BMP280_REGISTER_DIG_P8);
    bmp280_calib.dig_P9 = readS16_LE(BMP280_REGISTER_DIG_P9);
}

// Returns temperature in DegC, resolution is 0.01 DegC. Output value of “5123” equals 51.23 DegC.
// t_fine carries fine temperature as global value

float readTemp(void)
{
  int32_t var1, var2;

  int32_t adc_T = bmp280_read24(BMP280_REGISTER_TEMPDATA);
  adc_T >>= 4;

  var1  = ((((adc_T >> 3) - ((int32_t)bmp280_calib.dig_T1 << 1 ))) * ((int32_t)bmp280_calib.dig_T2)) >> 11;

  var2  = (((((adc_T >> 4) - ((int32_t)bmp280_calib.dig_T1)) * ((adc_T >> 4) - ((int32_t)bmp280_calib.dig_T1))) >> 12) *
     ((int32_t)bmp280_calib.dig_T3)) >> 14;

  t_fine = var1 + var2;

  float T  = (t_fine * 5 + 128) >> 8;
  return T/100;
}

// Returns pressure in Pa as unsigned 32 bit integer in Q24.8 format (24 integer bits and 8 fractional bits).
// Output value of “24674867” represents 24674867/256 = 96386.2 Pa = 963.862 hPa

float readPressure(void) {
  
  int64_t var1, var2, p;

  // Must be done first to get the t_fine variable set up
  readTemp();
  
  int32_t adc_P = bmp280_read24(BMP280_REGISTER_PRESSUREDATA);
  adc_P >>= 4;

  var1 = ((int64_t)t_fine) - 128000;
  var2 = var1 * var1 * (int64_t)bmp280_calib.dig_P6;
  var2 = var2 + ((var1*(int64_t)bmp280_calib.dig_P5)<<17);
  var2 = var2 + (((int64_t)bmp280_calib.dig_P4)<<35);
  var1 = ((var1 * var1 * (int64_t)bmp280_calib.dig_P3) >> 8) + ((var1 * (int64_t)bmp280_calib.dig_P2) << 12);
  var1 = (((((int64_t)1) << 47)+var1))*((int64_t)bmp280_calib.dig_P1) >> 33;

  if (var1 == 0) {
    return 0;  // avoid exception caused by division by zero
  }
  p = 1048576 - adc_P;
  p = (((p<<31) - var2)*3125) / var1;
  var1 = (((int64_t)bmp280_calib.dig_P9) * (p >> 13) * (p >> 13)) >> 25;
  var2 = (((int64_t)bmp280_calib.dig_P8) * p) >> 19;

  p = ((p + var1 + var2) >> 8) + (((int64_t)bmp280_calib.dig_P7) << 4);
  return (float)p/256;
}

float readAltitude(const float seaLevelhPa) {
  
  float altitude;

  float pressure = readPressure(); // in Si units for Pascal
  pressure /= 100;

  altitude = 44330 * (1.0 - pow(pressure / seaLevelhPa, 0.1903));

  return altitude;
}
