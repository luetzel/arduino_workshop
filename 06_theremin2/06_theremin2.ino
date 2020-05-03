#include <CapacitiveSensor.h>
#define receivePin 12
#define speakerPin 10
#define sendPin 2
CapacitiveSensor sens = CapacitiveSensor(sendPin,receivePin); 

void setup() { 
  Serial.begin(9600); 
} 

void loop() {
  //long start = millis(); 
  long total = sens.capacitiveSensor(30); // 30 Messungen
  //Serial.print(millis() - start); // Reaktionszeit in ms
  //Serial.print("\t"); 
  Serial.println(total); 
  int pitch = 100 + total / 10;
  tone(speakerPin, pitch);
}
