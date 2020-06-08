#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

// die I2C Adresse 0x76 kann nur in der Adafruit_BMP280.h
// eingestellt werden!
Adafruit_BMP280 bme;
  
void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));
  bme.begin();
}
  
void loop() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bme.readPressure());
    Serial.println(" Pa");

    Serial.print("Approx altitude = ");
    Serial.print(bme.readAltitude(1013.25));
    Serial.println(" m");
    
    Serial.println();
    delay(2000);
}
