#include "PCF8574.h"
#include <Wire.h>

// A0, A1, A2 connected to GND
// +5V ------ +LED ------- 330Rresistor ------ P8574pin
// Sink Current, sonst leuchten die LEDs nicht besonders hell.

PCF8574 expander(0x20);

void setup()
{
  expander.begin();
  Serial.begin(9600);
}
  
void loop()
{
  // auf alle Pins schreiben
  //for (int i=0; i<255; i++)
  //{
  //  expander.write8(i);
  //  delay(100);  
  //}

  // auf einen Pin schreiben
  expander.write(0,0);
  for (int i=0; i<7; i++)
    {
        expander.rotateLeft();
        Serial.println(expander.read8(), BIN);
        delay(100);
    }
  for (int i=0; i<7; i++)
    {
        expander.rotateRight();
        Serial.println(expander.read8(), BIN);
        delay(100);
    }
}
