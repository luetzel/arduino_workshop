/* Datei: wire_bmp085.ino
 *  Autor: Dr. Martin Lützelberger
 *  Datum: 20210201
 *  Beispiel zum Auslesen von Temperatur und Luftdruck von einem BMP085 Sensor ohne die Verwendung einer speziellen Bibliothek.
 *  Der Sketch verwendet lediglich die Wire-Bibliothek, welche die Kommunikation mit dem Sensor per I2C-Bus ermöglicht. Um dem
 *  Sensor die aktuellen Messwerte zu entlocken, muss man verschiedene Register des Sensors auslesen. Diese sind im Datenblatt 
 *  angegeben. Auf Seite 13 ist ein "Workflow" abgebildet, der die einzelnen Schritte verdeutlicht. Nach dem Auslesen von zwei, bzw.
 *  drei Bytes für die Temperatur und den Luftdruck, werden diese zusammen gefügt (MSB, LSB). Mit dem im Datenblatt angegebenden
 *  Algorithmus wird anschließend die genaue Temperatur und der Luftdruck berechnet.
 *  Wenn Zeile 16 auskommentiert ist, dann werden statt der Sensordaten die vorgegebenen Werte aus dem Datenblatt verwendet.
 *  Damit lassen sich die einzelnen Schritte und Ergebnisse der Berechnung überprüfen. Das ist wichtig, weil ältere Versionen der
 *  Bosch-Datenblätter einen Fehler enthalten. Hier fehlt eine Klammer: b3 = (((ac1 * 4 + x3) << oss) + 2) / 4; Darüber hinaus
 *  muss für das Zusammenfügen von MSB, LSB und XLSB der Datentyp unsigned long verwendet werden.
 */

#include <Wire.h>

// Zusätzliche Ausgaben aktivieren
//#define DEBUG

// Konfiguration der Sensor-Adresse. Beim original Bosch-Sensor istdas in der Regel 0x77 alle anderen haben die Adresse 0x76.
#define DEVICE_ADDRESS  0x77

// Deklaration von Variablen zum zwischenpeichern der Registerdaten
short reg0, reg1;
short ac1, ac2, ac3; 
unsigned short ac4;
unsigned short ac5;
unsigned short ac6;
int b1, b2, mb, mc, md;
long b3, b5, b6, p, x1, x2, x3, ut;
unsigned long up, b4, b7;
short oss = 0;

void setup() {
  // I2C-Bus initialisieren
  Wire.begin();
  // Serielle Verbindung zum Computer
  Serial.begin(9600); 
  // Sensor-Register auslesen und zwischenspeichern
  read_bmp085_cal_data();
}

void loop() {
  // Temperatur auslesen
  #ifndef DEBUG
  read_tp(read_temperature(), read_pressure());
  #endif
  
  #ifdef DEBUG
  read_tp(27898, 23843);
  while(true);
  #endif
  delay(500);
}

long i2c_read(short reg0){
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(reg0);
  Wire.endTransmission();
  Wire.requestFrom(DEVICE_ADDRESS, 2);
  short MSB = Wire.read();
  short LSB = Wire.read();
  Wire.endTransmission(false);
  long value = ( (MSB << 8)  |  LSB);
  return value;
}

void read_bmp085_cal_data(){
 #ifndef DEBUG
 ac1 = i2c_read(0xAA); 
 ac2 = i2c_read(0xAC);
 ac3 = i2c_read(0xAE);
 ac4 = i2c_read(0xB0);
 ac5 = i2c_read(0xB2);
 ac6 = i2c_read(0xB4);
 b1 = i2c_read(0xB6);
 b2 = i2c_read(0xB8);
 mb = i2c_read(0xBA);
 mc= i2c_read(0xBC);
 md = i2c_read(0xBE);
#endif

#ifdef DEBUG
 ac1 = 408;
 ac2 = -72;
 ac3 = -14383;
 ac4 = 32741;
 ac5 = 32757;
 ac6 = 23153;
 b1 = 6190;
 b2 = 4;
 mb = -32768;
 mc= -8711;
 md = 2868;

  Serial.println("Reading calibration data ...");
  Serial.print("ac1: ");
  Serial.println(ac1);
  Serial.print("ac2: "); 
  Serial.println(ac2);
  Serial.print("ac3: ");
  Serial.println(ac3);
  Serial.print("ac4: ");
  Serial.println(ac4);
  Serial.print("ac5: ");
  Serial.println(ac5);
  Serial.print("ac6: ");
  Serial.println(ac6);
  Serial.print("b1: ");
  Serial.println(b1);
  Serial.print("b2: ");
  Serial.println(b2);
  Serial.print("mb: ");
  Serial.println(mb);
  Serial.print("mc: ");
  Serial.println(mc);
  Serial.print("md: ");
  Serial.println(md);
#endif 
 }

 long read_temperature() {
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(0xF4);
  Wire.write(0x2E);
  Wire.endTransmission();
  delay(5);
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(0xF6);
  Wire.endTransmission();
  Wire.requestFrom(DEVICE_ADDRESS, 2, true);
  short MSB = Wire.read();
  short LSB = Wire.read();
  Wire.endTransmission();
  ut = ((MSB << 8) | LSB);
  #ifdef DEBUG
  Serial.print("Uncompensated Temperature: ");
  Serial.println((float)ut / 1000, 2);
  #endif
  return ut;
}

long read_pressure() {
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(0xF4);
  Wire.write(0x34 + (oss << 6));
  Wire.endTransmission();
  delay(10);
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(0xF6);
  Wire.endTransmission();
  Wire.requestFrom(DEVICE_ADDRESS, 3, true);
  unsigned long MSB = Wire.read();
  unsigned long LSB = Wire.read();
  unsigned long XLSB = Wire.read(); 
  Wire.endTransmission();
  up = (MSB << 16  |  LSB << 8 | XLSB) >> (8 - oss) ;
  #ifdef DEBUG
  Serial.print("Uncompensated Pressure: ");
  Serial.println(up);
  #endif
  return up;
}

  void read_tp(long ut, long up) {
  //calculate  temperature
  x1 = (ut - ac6) * ac5 / pow(2,15);
  x2 = mc * pow(2,11) / (x1 + md);
  b5 = x1 + x2;
  long t = (b5 + 8) / pow(2, 4);
  #ifdef DEBUG
  Serial.print("x1: ");
  Serial.println(x1);
  Serial.print("x2: ");
  Serial.println(x2);
  Serial.print("b5: ");
  Serial.println(b5);
  Serial.print("t: ");
  Serial.println(t);
  #endif
  Serial.print("Compensated Temperature: ");
  Serial.println((float)t / 10, 2);
  
  // calculate pressure
  #ifdef DEBUG
  b6 = b5 - 4000;
  Serial.print("b6: ");
  Serial.println(b6);
  Serial.print("b2: ");
  Serial.println(b2);
  #endif
  x1 = ( b2 * ( b6 * b6 / pow(2,12) ) ) / pow(2,11);
  #ifdef DEBUG
  Serial.print("x1: ");
  Serial.println(x1);
  #endif
  x2 = ac2 * b6 / pow(2,11);
  #ifdef DEBUG
  Serial.print("x2: ");
  Serial.println(x2);
  #endif
  x3 = x1 + x2;
  #ifdef DEBUG
  Serial.print("x3: ");
  Serial.println(x3);
  #endif
  b3 = (((ac1 * 4 + x3) << oss) + 2) / 4;
  #ifdef DEBUG
  Serial.print("b3: ");
  Serial.println(b3);
  #endif
  x1 = ac3 * b6 / pow(2,13);
  #ifdef DEBUG
  Serial.print("x1: ");
  Serial.println(x1);
  #endif
  x2 = (b1 * (b6 * b6 / pow(2,12) ) ) /pow(2,16);
  #ifdef DEBUG
  Serial.print("x2: ");
  Serial.println(x2);
  #endif
  x3 = ( (x1 + x2) + 2 )/ pow(2,2);
  #ifdef DEBUG
  Serial.print("x3: ");
  Serial.println(x3);
  #endif
  b4 = ac4 * (unsigned long)(x3 + 32768) / pow(2,15);
  #ifdef DEBUG
  Serial.print("b4: ");
  Serial.println(b4);
  #endif
  b7 = ( (unsigned long)up - b3) * (50000 >> oss);
  #ifdef DEBUG
  Serial.print("b7: ");
  Serial.println(b7);
  #endif
  if (b7 < 0x80000000) {
    p = (b7 * 2) / b4;
  }
  else {
    p = (b7 / b4) * 2;
  }
  #ifdef DEBUG
  Serial.print("p: ");
  Serial.println(p);
  #endif
  x1 = (p / pow(2,8) ) * (p / pow(2,8) );
  #ifdef DEBUG
  Serial.print("x1: ");
  Serial.println(x1);
  #endif
  x1 = (x1 * 3038) / pow(2,16);
   #ifdef DEBUG
  Serial.print("x1: ");
  Serial.println(x1);
  #endif
  x2 = (-7357 * p) / pow(2,16);
   #ifdef DEBUG
  Serial.print("x2: ");
  Serial.println(x2);
  #endif
  p = p + (x1 + x2 + 3791) / pow(2,4);
  
  Serial.print("Compensated Pressure: ");
  Serial.println(p / 100.0, 2);
  }
