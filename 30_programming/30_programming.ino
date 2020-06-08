// #include wird verwendet, um externe Bibliotheken in den Sketch aufzunehmen.
// Dadurch erhält der Programmierer Zugriff auf eine große Gruppe von
// Standard-C-Bibliotheken (Gruppen vorgefertigter Funktionen) sowie auf speziell
// für Arduino geschriebene Bibliotheken.
#include <EEPROM.h> // -> libraries 
#include "Led.h" //

// #define ist eine nützliche Programmieranweisung mit der man
// einem konstanten Wert einen Namen geben kann. Definierte
// Konstanten nehmen keinen Programmspeicherplatz ein.
// Der Compiler ersetzt zur Kompilierzeit Verweise auf diese Konstanten
// durch den definierten Wert. WICHTIG: der Variablenname wird meist
// groß geschreiben. Die Zeile wird nicht mit einem Semikolon abgeschlossen!
#define LEDPIN 10
#define BTTNPIN 11

// Variablen können in allen Teilen eines Programms deklariert werden. Meist erfolgt
// die Deklaration aber am Anfang. Variablen dienen zur Zwischenspeicherung und
// Verarbeitung von Daten z.B. Messwerten oder Benutzereingaben, die zur Laufzeit
// des Programms erfasst oder eingegeben werden.
// Der Inhalt von Variablen kann sich zur Laufzeit des Programms ändern. Schon
// bei der Deklaration einer Veriablen muss angegeben werden, von welchem Datentyp
// der Wert einer Variablen ist.
// <datentyp> <name> = <wert>;
bool w = true;               // Wahrheitswert
const char c = 'A';          // einzelner Buchstabe
const char c1 = 65;          // einzelner Buchstabe -127 bis +128
String s = "Hallo Welt!";    // eine Zeichenkette bzw. char array
char s1[12] = "Hallo Welt!"; // Platz für Null-Terminator berücksichtigen '\0'
byte b = 255;
int x = 32767;
short x1 = 32767;
word x2 = 65535;
long x3 = 2147483647;
float y = 3.4028235E+38;

// Funktionen sind Programmanweisungsblöcke, die wiederkehrende Abfolgen von Anweisungen
// zusammenfassen. Bestandteil eines jeden Arduino-Sketch sind die Funktionen setup() und
// loop(). Diese müssen IMMER vorhanden sein, sonst lässt sich das Programm nicht kompilieren.
// Das Schlüsselwort 'void' gibt an, dass die Funktion keinen Rückgabewert an die aufrufende
// Anweisung zurückliefert.
// Beim Kaltstart oder Reset des Mikrocontrollers wird die Funktion setup() einmalig, die
// Funktion loop() dauerhaft ausgeführt. Dieser Programmteil wird meist für Einstellungen
// verwendet, z.B. die Einrichtung der seriellen Kommunikation zwischen Arduino und PC.
void setup() {
Serial.begin(9600);

// Pins konfigurieren. Digitale Pins können benutzt werden als INPUT, OUTPUT oder INPUT_PULLUP.
// Arduino Pins, die als INPUT konfiguriert sind, haben einen hohen Innenwiderstand, vergleichbar
// mit einem Widerstand von 100 MegaOhm und mehr, so dass hier extrem wenig Strom fließt.
// Wenn ein Pin als INPUT konfiguriert ist, dann will man ihn oft auf einem definierten Potential haben.
// Das wird erreicht mit einem Pulldown-Widerstand vom Pin nach Masse. Dann liegt der Pin im
// unbeschalteten Zustand auf LOW. Das Gegenteil wird erreicht bei Benutzung des internen Pullup mit
// INPUT_PULLUP.
// Als OUTPUT konfigurierte Pins haben einen geringen Innenwiderstand, so dass sie maximal
// 40 mA Strom in die Schaltung treiben können. Es ist jedoch nicht möglich alle verfügbaren
// Pins als OUTPUT zu konfigurieren und gleichzeitig auf HIGH zu setzen! Das würde den Arduino
// zerstören.

pinMode(LEDPIN, OUTPUT);
pinMode(BTTNPIN, INPUT_PULLUP);

// Pin Zustände HIGH and LOW. Arduino-Pins "kennen" nur zwei Zustände, HIGH und LOW. Wenn ein
// pin als INPUT konfiguriert ist, dann wird er mit der Funktion digitalRead() ein HIGH melden,
// wenn eine Spannung von 3 Volt oder mehr anliegt.
// Der Arduino wird ein LOW melden, wenn die Spannung 2 Volt unterschreitet. Ist ein Pin als
// OUTPUT konfiguriert, dann bedeutet LOW 0 Volt. In diesem Zustand kann der Pin Strom treiben,
// jedoch gegen die Boardspannung. Hie handelt es sich um eine negative Logik (LOW-aktiv).

digitalWrite(LEDPIN, HIGH);
digitalWrite(LEDPIN, LOW);

// Analoge Ausgabe. Durch Pulsweitenmodulation gelingt es auf einigen Pins des Arduino
// Spannungen beliebiger Höhe, d.h. von 0 bis 5 Volt auszugeben.
// analogWrite() funktioniert nur bei den Pins, die für PWM vorgesehen sind. Das sind im
// Allgemeinen 3, 5, 6, 9, 10, 11 . Es gibt aber noch mehr Möglichkeiten per Software.
// Die PWM-Frequenz liegt bei den ATMega328-basierten Boards bei ca. 490Hz
// an den Pins 3,9,10,11 und ca. 980Hz an Pins 5 und 6. Diese kann aber auch geändert werden.
// Der Befehl analogWrite() ist etwas verwirrend, wird doch hier keine echte "analoge" Spannung
// ausgegeben, sondern eine Rechteckfrequenz mit unterschiedlicher Pulsbreite.
// Als Pulsbreite sind nur Werte von 0 bis 255 zulässig (8 Bit)

analogWrite(3, 100);

// Analoge Eingabe. Die Pins A0 bis A7 erlauben das Auslesen einer Spannung bis zur Höhe
// der Betriebsspannung von 5 Volt.
// Als Rückgabewert erhält man ein 10 Bit Integerwert (0 bis 1023), aus dem sich die Spannung
// errechnen lässt. Zum Auslesen der analogen Pins ist es zuvor nicht nötig diese als
// INPUT zu konfigurieren.

int x = analogRead(A0);

} // Ende setup()

// Benutzerdefinierte Funktionen. Funktionen enthalten wiederkehrende Anweisungen und müssen
// außerhalb der Funktion setup() und loop() deklariert werden. Dem Funktionsnamen wird der
// Datentyp des Rückgabewerts vorangestellt. Gibt es keinen Rückgabewert, dann steht 'void'
// vor dem Namen. Die runden Klammern bleiben entweder leer oder enthalten eine Liste von
// Variablen, die der Funktion übergeben werden.
float meinefunktion(int x, int y) {
  return x / y;
}

void loop() {
// Kontrollstrukturen. Der Ablauf eines Programms wird in der Regel von Ereignissen, wie z.B.
// Benutzereingaben (Knopf A gedrückt) gesteuert. Mit der if, else if, else Anweisung lässt sich
// steuern was passieren soll, wenn eine bestimmte Bedingung erfüllt ist.
meinefunktion(2,6);

if (x > y) {
  Serial.println("x ist größer als y");
} else if (x < y) {
  Serial.println("x ist kleiner als y");
} else {
  Serial.println("x und y sind gleich");
}

// Vergleichsoperatoren. Für den Vergleich von Variablen(werten) stehen verschiedene Vergleichsoperatoren
// zur Verfügung (<,>,==,!=,<=,>=), die miteinander verknüft werden können. Bei einem
// logischen 'und' (&&) müssen alle Bedingungen 'wahr' sein, damit der gesamte Ausdruck
// wahr ist. Bei einem 'oder' (||) genügt es, wenn eine Bedingung 'wahr' ist, damit der
// gesamte Ausdruck wahr wird.

if ((x > y) && (x1 < x2)) {
  Serial.println("x ist größer als y und x1 ist kleiner als x2");
}

// Switch/Case. Ähnlich wie if-Anweisungen erlauben die switch/case-Anweisungen
// die Ausführung bestimmter Abläufe zu kontrollieren. Eine switch-Anweisung vergleicht
// den Wert einer Variablen mit den Werten aus den case-Anweisungen. Wenn eine
// Übereinstimmung gefunden wird, wird das Programm ab der jeweiligen case-Anweisung
// bis zum nächsten break ausgeführt.

int var = 20;
switch (var) {
  case 10:
    Serial.println(var);
    break;
  case 20:
    Serial.println(var);
    break;
  case 30:
    Serial.println(var);
    break;
}

// Schleifen. Eine Schleife wiederholt einen Programmblock so lange bis ihre
// Abbruch-Bedingung in (runden Klammern) erfüllt (wahr) ist. Von der while Schleife
// gibt es zwei Varianten, bei denen die Bedingung jeweils vor (while) oder nach dem
// (do .. while) ersten Durchlauf getestet wird.

int i = 0;
while(i < 3) {
  Serial.println("Hallo Welt!");
  i++;
}

i = 0;
do {
  Serial.println("Hallo Welt!");
  i++;
} while(i < 3);

// For-Schleifen. Werden manchmal auch Zähl-Scheifen genannt, weil bei jedem Durchlauf
// ein "Startwert" inkrementiert bzw. dekrementiert wird. Um mehrere Pins als INPUT zu
// konfigurieren, lässt sich die folgende for Schleife verwenden.

for (int i = 0; i < 7; i++) {
  pinMode(i, INPUT_PULLUP);
}

// Interrupts. Bei längeren Programmen, die viele Funktionen enthalten, kann es vorkommen,
// dass der Arduino nicht oder stark verzögert auf Benutzereingaben reagiert, z.B. Tastendrücke.
// Wird gerade ein anderer Programmteil ausgeführt und nicht der Status des Tasters abgefragt,
// wird die Eingabe u.U. "verpasst". Durch das Festlegen eines Interrupts lässt sich dieses
// Verhalten ändern. Der Programmablauf wird unterbrochen und die in der Anweisung angegebene
// Funktion sofort ausgeführt. Beim Arduino Nano stehen nur zwei Interrupt-Pins zur
// Verfügung, die zwar in der Anweisung mit 0 und 1 angegeben werden, jedoch den physischen
// Pins 2 und 3 entsprechen.

attachInterrupt(0, meinefunktion, CHANGE);

// Objektorientiertes Programmieren. Weil der Arduino von einer großen Benutzer-Community
// unterstützt wird, findet man für nahezu jedes beliebige Bauteil eine Bibliothek, die
// dessen Nutzung erheblich vereinfacht. Bibliotheken werden ganz zu Beginn eines Sketches
// mit der #include Anweisung eingebunden. Es stehen dann alle von der Bibliothek bereitgestellten
// Funktionen zur Verfügung. Bei der objektorientierten Programmierung versucht man physische
// Objekte in Software abzubilden, z.B. eine LED. Will man das Objekt im Programm nutzen,
// erzeugt manzunächst eine "Instanz" des Objekts und konfiguriert ggf. dessen Attribute
// Darüber hinaus stellen Bibliotheken Funktionen bereit, welche auf das Objekt angewendet
// oder vom Objekt ausgeführt werden, z.B. die Messung eines Sensors. Wird eine Funktion
// auf ein Objekt angewendet, dann verküpft man den Objektnamen mit der Funktion durch
// einen Punkt (.) und spricht nicht mehr von einer Funktion, sondern von einer Methode.

Led statusLed(LED_BUILTIN); // erzeugt eine neue Instanz statusLed
statusLed.on();             // schalte statusLed ein

// Pausieren. In vielen Situationen, z.B. bei der Arbeit mit Umweltsensoren kommt es vor,
// dass Messwerte über längere Zeit-Intervalle erfasst werden sollen. Mit der Funktion delay()
// kann man das Programm für eine definierte Zeit pausieren. Die Wartezeit wird in Millisekunden
// angegeben.
delay(3000);
} // ende loop()
