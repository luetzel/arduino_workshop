#include <avr/io.h>
void setup() {
   DDRB |= (1 << PB5);
   DDRB |= (1 << PB3);
   PORTB |= (1 << PORTB);
}
void loop() {
     PORTB |= (1 << PB5);
     delay(100);
     PORTB &= ~(1 << PB5);
     delay(100);
}
