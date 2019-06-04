#include<Wire.h>
#define DEVICE_ADDRESS 0x77  // I2C address of BMP180
#define OSS 0  // Oversampling Setting

// Calibration values
int ac1, ac2, ac3; 
unsigned int ac4, ac5, ac6;
int b1, b2, b3, mb, mc, md; 

long b5; 
float temperature;
float pressure;
float altitude;

const float p0 = 101325; // Pressure at sea level (Pa)

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  Calibration();
}

void Calibration()
{
  ac1 = i2cReadInt(0xAA);
  ac2 = i2cReadInt(0xAC);
  ac3 = i2cReadInt(0xAE);
  ac4 = i2cReadInt(0xB0);
  ac5 = i2cReadInt(0xB2);
  ac6 = i2cReadInt(0xB4);
  b1 = i2cReadInt(0xB6);
  b2 = i2cReadInt(0xB8);
  mb = i2cReadInt(0xBA);
  mc = i2cReadInt(0xBC);
  md = i2cReadInt(0xBE);
}

uint8_t i2cRead(uint8_t address)
{
  uint8_t data;
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  Wire.requestFrom(DEVICE_ADDRESS, 1);
  while(!Wire.available());
  return Wire.read();
}

int i2cReadInt(uint8_t address)
{
  uint8_t msb, lsb;
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  Wire.requestFrom(DEVICE_ADDRESS, 2);
  while(Wire.available()<2);
  msb = Wire.read();
  lsb = Wire.read();
  return (int)msb << 8 | lsb;
}

unsigned int i2cReadUT()
{
  unsigned int ut;
  // Write 0x2E into Register 0xF4
  // This requests a temperature reading
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(0xF4);
  Wire.write(0x2E);
  Wire.endTransmission();
  
  // Wait at least 4.5ms
  delay(5);
  
  // Read two bytes from registers 0xF6 and 0xF7
  ut = i2cReadInt(0xF6);
  return ut;
}

unsigned long i2cReadUP()
{
  uint8_t msb, lsb, xlsb;
  unsigned long up = 0;
  
  // Write 0x34 + (OSS << 6) into register 0xF4
  // Request a pressure reading w/ oversampling setting
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(0xF4);
  Wire.write(0x34 + (OSS << 6));
  Wire.endTransmission();
  
  // Wait for conversion, delay time dependent on OSS
  delay(2 + (3 << OSS));
  
  // Read register 0xF6 (MSB), 0xF7 (LSB), and 0xF8 (XLSB)
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(0xF6);
  Wire.endTransmission();
  Wire.requestFrom(DEVICE_ADDRESS, 3);
  
  // Wait for data to become available
  while(Wire.available() < 3);
  msb = Wire.read();
  lsb = Wire.read();
  xlsb = Wire.read();
  
  up = (((unsigned long) msb << 16) | ((unsigned long) lsb << 8) | (unsigned long) xlsb) >> (8-OSS);
  
  return up;
}

short GetTemperature(unsigned int ut)
{
  long x1, x2;
  
  x1 = (((long)ut - (long)ac6)*(long)ac5) >> 15;
  x2 = ((long)mc << 11)/(x1 + md);
  b5 = x1 + x2;

  return ((b5 + 8)>>4);  
}

long GetPressure(unsigned long up)
{
  long x1, x2, x3, b3, b6, p;
  unsigned long b4, b7;
  
  b6 = b5 - 4000;
  // Calculate B3
  x1 = (b2 * (b6 * b6)>>12)>>11;
  x2 = (ac2 * b6)>>11;
  x3 = x1 + x2;
  b3 = (((((long)ac1)*4 + x3)<<OSS) + 2)>>2;
  
  // Calculate B4
  x1 = (ac3 * b6)>>13;
  x2 = (b1 * ((b6 * b6)>>12))>>16;
  x3 = ((x1 + x2) + 2)>>2;
  b4 = (ac4 * (unsigned long)(x3 + 32768))>>15;
  
  b7 = ((unsigned long)(up - b3) * (50000>>OSS));
  if (b7 < 0x80000000)
    p = (b7<<1)/b4;
  else
    p = (b7/b4)<<1;
    
  x1 = (p>>8) * (p>>8);
  x1 = (x1 * 3038)>>16;
  x2 = (-7357 * p)>>16;
  p += (x1 + x2 + 3791)>>4;
  
  return p;
}

void loop()
{
  temperature = (float)GetTemperature(i2cReadUT());
  pressure = GetPressure(i2cReadUP());
  altitude = (float)44330 * (1 - pow(((float) pressure/p0), 0.190295));
  
  Serial.print("Temperature: ");
  Serial.print(temperature / 10.0, 2);
  Serial.println(" C");
  Serial.print("Pressure: ");
  Serial.print(pressure / 100.0, 2);
  Serial.println(" hPa");
  Serial.println();
  Serial.print("Altitude: ");
  Serial.print(altitude, 2);
  Serial.println(" m");
  delay(1000);
}
