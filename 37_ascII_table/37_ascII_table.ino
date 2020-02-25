char a = 97;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for(char i = 65; i <= 90; i++) {
Serial.print(i);
}
Serial.println(" ");
delay(1000);
}
