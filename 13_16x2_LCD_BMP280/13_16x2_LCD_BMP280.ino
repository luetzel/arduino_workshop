#include <LiquidCrystal_PCF8574.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

// die I2C Adresse 0x76 kann nur in der Adafruit_BMP280.h
// eingestellt werden!
Adafruit_BMP280 BMP280; // erzeuge Sensor Instanz - die I2C Adresse muss in Adafruit_BMP280.h eingestellt werden!
LiquidCrystal_PCF8574 LCD(0x3f);  // erzeuge  LCD Instanz

void setup()
{
  LCD.begin(16, 2); // LCD initialisieren
  BMP280.begin(); // Barometer initialisieren
}

void loop()
{
 LCD.setBacklight(255);
 String Zeile1 = "T: " + String(BMP280.readTemperature()) + " \337C"; // \337 Grad Celsius Sonderzeichen
 LCD.setCursor(0,0);
 LCD.print(Zeile1);
 LCD.setCursor(0,1);
 String Zeile2 = "L: " + String(BMP280.readPressure()/100) + " hPa";
 LCD.print(Zeile2);
 delay(1000);
}
