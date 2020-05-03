#define potPin A0
#define ledPin 9 
int readValue;
int writeValue;

void setup() {
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 readValue = analogRead(potPin);
 //writeValue = (255./1023.) * readValue;
 //analogWrite(ledPin, writeValue);

 analogWrite( ledPin, map(readValue, 0, 1023, 255, 0) );
 Serial.print("You are reading a value of ");
 Serial.println(readValue);
 Serial.print("You are writing a value of ");
 Serial.println(writeValue);
 delay(250);
}
