#include "PCF8574.h"

// A0, A1, A2 connected to GND
// +5V ------ +LED ------- 330Rresistor ------ P8574pin
// sink current

PCF8574 expander(0x20);

void setup()
{
  expander.begin();
  Serial.begin(9600);
}
  
void loop()
{
  // auf einen Pin schreiben
  expander.write(0,LOW);

  //
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
  //

  /*
  expander.write8(0B00000000); // 0x00
  expander.write8(0B10000000); // 0x80
  expander.write8(0B11000000); // 0xC0
  expander.write8(0B11100000); // 0xE0
  expander.write8(0B11110000); // 0xF0
  expander.write8(0B11111000); // 0xF8
  expander.write8(0B11111100); // 0xFC
  expander.write8(0B11111110); // 0xFE
  expander.write8(0B11111111); // 0xFF
  */

  /*
  byte bytearray[] = {0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF};

  for (int i=0; i < 8; i++)
  {
    expander.write8(bytearray[i]);
    delay(300);
  }
  */

  // auf alle Pins schreiben
  /*for (int i=0; i<255; i++)
  {
    expander.write8(~i);
    delay(100);  
  }*/
}
