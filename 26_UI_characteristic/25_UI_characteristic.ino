/* 
von Ferdinand Streicher 19.12.2018
basierend auf 
https://www.instructables.com/id/Measuring-the-IV-Curve-of-Semiconductors-With-an-A/
von rgco
*/


//Messung des Stroms in Abhängigkeit der Spannung mit zwei Anschlüssen. Besonders nützlich für LEDs
//Verbinde den RC-Tiefpassfilter mit dem Timer-Ausgang an D11 und D3, R = 100Ohm, C = 100muF, tau = 10ms
//Ausgabe des Filters an A0
//100Ohm Widerstand vom Filter zum Plus-Anschluss des untersuchten Geräts
//Plus Anschluss auch an A1 


void setup() {
  Serial.begin(115200);
  
  Serial.println();
  Serial.println(F("start:"));
  //Serial.println(F("title:UI-Kennlinien"));
  //Serial.println(F("subtitle:Showing magic"));
  Serial.println(F("setMaxY:20"));
  Serial.println(F("setMinY:0"));
  Serial.println(F("setMinX:0"));
  Serial.println(F("setMaxX:5"));
  Serial.println(F("setYFormat:#.###"));
  Serial.println(F("setXFormat:#.#"));
  Serial.println(F("setXAxisLabel:Spannung in Volt"));
  Serial.println(F("setYAxisLabel:Strom in Milliampere"));
  Serial.println(F("setPointColor:0,50,255"));
  Serial.println(F("setXDataLength:256"));
  
  Serial.println(F("button:B:Blue:0,0,255"));
  Serial.println(F("button:R:Red:255,0,0"));
  Serial.println(F("button:Y:Yellow:255,255,0"));
  Serial.println(F("button:G:Green:50,255,50"));
  Serial.println(F("button:W:White:0,0,0"));
  
  pinMode(11,OUTPUT); // PWM out
  pinMode(3,OUTPUT);  // PWM out
  pinMode(A0,INPUT);  // analog input
  pinMode(A1,INPUT);  // analog input
  TCCR2A = B10100011; //schnelle PWM an A and B
  TCCR2B = B00000001; //Keine Voreinstellung für Timer2
}

float Rseries=100;

void measure(byte val, byte nrep) {
  unsigned int v0=0;
  unsigned int v1=0;
  OCR2A=val;
  OCR2B=val;
  delay(30);
  for(byte i=0; i <nrep; i++){
    v0+=analogRead(A0);
    v1+=analogRead(A1);
    delay(1);
  }
  float volt0 = 5.0 * v0 / 1024.0 /nrep;
  float volt1 = 5.0 * v1 / 1024.0 /nrep;
  float ampere = 1000.0*(volt0-volt1)/Rseries;
  if (ampere<=0) ampere = 0;

  Serial.print(volt1);
  Serial.print(" ");
  Serial.println(ampere);
}

char command=0;
void loop() {
  if (command!=0) {
    switch (command) {
      case 'R' : // Rote LED
        Serial.println(F("activeGraph:0"));
        Serial.println(F("setPointColor:255,0,0"));
        Serial.println(F("setLineWidth:0"));
        break;
      case 'B' : // Blaue LED
        Serial.println(F("activeGraph:2"));
        Serial.println(F("setPointColor:0,0,255"));
        Serial.println(F("setLineWidth:0"));
        break;
      case 'Y' : // Gelbe LED
        Serial.println(F("activeGraph:5"));
        Serial.println(F("setPointColor:255,255,0"));
        Serial.println(F("setLineWidth:0"));
        break;
      case 'G' : // Grüne LED
        Serial.println(F("activeGraph:6"));
        Serial.println(F("setPointColor:50,205,50"));
        Serial.println(F("setLineWidth:0"));
        break;
      case 'W' : // Weiße LED
        Serial.println(F("activeGraph:8"));
        Serial.println(F("setPointColor:0,0,0"));
        Serial.println(F("setLineWidth:0"));
        break;
    }
    // starte eigentliche Messung 256 Messpunkte von 0...255
    for (int i=0;i<256;i++) {
      measure(i,32);
    }
    command =0;
  }
  // Lese Kommando von der seriellen Schnittstelle
  if(Serial.available()){
    command=Serial.read();
  } 
}
