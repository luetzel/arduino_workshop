## Arduino-Workshop
### Arduino-Workshop am Institut für Berufliche Bildung und Arbeitslehre der TU-Berlin im WS18

Der Kurs findet voraussichtlich immer freitags ab dem **26.10.2018** bis einschließlich **14.12.2018**
 jeweils von **08:00 Uhr s.t.** bis ca. **12 Uhr** statt. 

Am Freitag, dem **16.11.2018** findet der Kurs **nicht** statt.

**WICHTIG:** Bitte bringen Sie ihr eigenes Notebook oder Laptop mit und installieren Sie bitte vorab die
 aktuelle Version der Arduino-Entwicklungsumgebung (Version 1.8.6).

Für die Startersets wird am ersten Tag ein Pfand von 20,- € eingesammelt das sie bei Rückgabe
des vollständigen und unbeschädigten Sets abzüglich einer kleinen Leihgebühr von 5 € am Ende des Kurses
 zurück erhalten. **Bitte bringen Sie den Betrag möglichst passend mit!**

### Installation der Arduino-Entwicklungsumgebung

Bitte laden Sie sich die aktuelle Version der Arduino-Entwicklungsumgebung für Ihr Betriebssystem herunter. 

* [Link zum Download der Entwicklungsumgebung](https://www.arduino.cc/en/Main/Software)

Eine Installationsanleitung für Windows, MacOSX oder Linux finden Sie unter diesem Link:

* [Installationsanleitung](https://www.arduino.cc/en/Guide/HomePage)

### Treiber

Wenn Sie die Arduino-Entwicklungsumgebung unter Windows oder MacOSX verwenden wollen, benötigen Sie
zusätzlich den CH340-Treiber, damit Sie die im Kurs verwendeten Arduino Nano V3 Platinen mit Ihrem
Gerät über den USB-Anschluss verbinden können.

* [Link zum Download der Treiber](https://wiki.wemos.cc/downloads)

* [Offizieller Treiber des Herstellers](http://www.wch.cn/download/CH341SER_EXE.html)

Auf Win10 Geräten müssen Sie möglicherweise die Sicherheitseinstellungen verändern, damit Sie
unsignierte Treiber installieren können.

#### Probleme mit Apple-Geräten

Auf Apple-Geräten kann es bei Verbindung mit dem Arduino zu System-Abstürzen kommen (Kernel-Panic).
Betroffen davon sind nach meiner Recherche ausschließlich Geräte mit MacOS "Sierra".
Abhilfe schafft evtl. ein Treiber-Update, das [hier heruntergeladen](http://download.makeblock.com/mblock/CH34x_Install_V1.3.pkg)
 werden kann.

#### Den richtigen COM-Port finden
Auf Windows-Geräten ist es manchmal schwierig den richtigen COM-Port zu finden mit, dem der Arduino
über USB verbunden ist. Dieses Video erklärt wie das mit dem Windows-Geräte Manager geht:

[Wie finde ich den richtigen COM-Port? (Video)](https://www.youtube.com/watch?v=hou4okcCX7E)

#### Hinweise für Linux-Nutzer

Falls Sie ein Notebook mit einer aktuellen Linux-Distribution (Ubuntu, Debian, SuSE, etc.) verwenden,
wird kein Treiber benötigt, denn der Linux-Kernel unterstützt das Board bereits.

Damit Sie unter Linux nicht mit Administratorrechten arbeiten müssen, fügen Sie Ihren Benutzernamen der
Gruppe `dialout` hinzu.

`sudo usermod -a -G dialout username`

### Beispiel-Code

Ab Mitte/Ende Dezember 2017 können Sie hier den [Beispiel-Code](https://github.com/luetzel/arduino_workshop/archive/master.zip)
 und weiteres Arbeitsmaterial für die praktischen Übungen herunterladen.

Das Verzeichnis wird im Verlauf des Kurses aktualisert.

Wenn Sie das Tool ['git'](https://git-scm.com/download) auf Ihrem System installiert haben, können Sie den Beispiel-Code auch durch
Eingabe des Befehls:

```
git clone https://github.com/luetzel/arduino_workshop.git
```

herunterladen uns später mit

```
git pull
```

aktualisieren.

Die Inhalte des Verzeichnis `sketches` bzw. `libraries` kopieren Sie bitte in die zugehörigen Verzeichnisse,
die auf Ihrem System während der Installation der  Arduino-Entwicklungsumgebung angelegt wurden.
Unter Windows ist das in der Regel Verzeichnis `Meine Dokumente/Arduino`.

### Datenblätter

Im Verzeichnis `Datasheets` finden Sie eine Sammlung von Datenblättern zu den im Starter-Kit enthaltenen
Bauteilen. Bitte beachten Sie, dass das Starter-Kit zum Teil baugleiche Teile anderer Hersteller enthält.

Bitte beachten Sie, dass das Barometer-Breakout eine Versorgungsspannung von *3V3* benötigt und deshalb
*nicht* mit 5 Volt Versorgungsspannung betrieben werden darf.

### Fritzing.org

Optional können Sie Fritzing auf Ihrem Gerät installieren. Mit Fritzing kann man elektronische
Schaltungen am Computer entwickeln bzw. dokumentieren. Die Bauteile können per drag'n drop auf
dem Steckbrett plaziert werden.

Das Programm können Sie hier für [Windows, MacOS oder Linux herunterladen](http://Fritzing.org/download/).

Im Unterverzeichnis [Fritzing](https://github.com/luetzel/arduino_workshop/blob/master/Fritzing) finden Sie die
 Schaltpläne, die Sie während der praktischen Übungen kennengelernt haben:

![Arduino Nano mit LED](https://github.com/luetzel/arduino_workshop/blob/master/Fritzing/01_LED.jpg)

### Arduino Code-Referenz Handbuch

Das Arduino-Forum.de hat ein sehr ausführliches Code-Referenz Handbuch erstellt in dem sämtliche Funktionen
der Arduino-IDE dokumentiert sind. Es ist verträndlich geschrieben und für Anfänger geeignet. Das
Handbuch kann kostenlos als PDF heruntergeladen werden.

[Arduino Code-Referenz](https://www.arduinoforum.de/referenz.php)

### Elektronik Kompendium

Das Elektronik-Kompendium ist ein sehr gutes Nachschlagwerk, um die im Kurs behandelten Grundschaltungen
noch einmal nachzubereiten:

* [Ohmsches Gesetz](http://www.elektronik-kompendium.de/sites/grd/0201113.htm)
* [Zweite Kirchhoffsche Regel](https://www.elektronik-kompendium.de/sites/grd/0608011.htm)
* [Vorwiderstand einer LED berechnen](https://www.elektronik-kompendium.de/sites/grd/1006011.htm)
* [Unbelasteter Spannungsteiler](https://www.elektronik-kompendium.de/sites/slt/0201111.htm)

### Probleme mit den Ultraschallsensoren

Bitte beim Stecken der Schaltung auf die Orientierung des Sensors achten und VCC/GND nicht verwechseln!

![HC-SR04](https://github.com/luetzel/arduino_workshop/blob/master/Fritzing/13_Ultraschall.jpg)

Ein Fehler in der Firmware des Sensors kann dazu führen, dass dieser "einfriert" wenn kein Echo empfangen wird.
 In anderen Worten, der Sensor wartet für eine unbegrenzte Zeit auf das eintreffende Echo. Abhilfe schafft
die Programmierung eines "Timeouts":

```
duration = pulseIn(echoPin, HIGH, 30000);
```

und dem anschließendem "Reset" des Sensors. Auf den echoPin wird dafür ein LOW für 200 us geschrieben.
Im folgenden Sketch wird außerdem die Ausgabe der Distanz in cm auf ein Intervall zwischen 5
und 400 cm begrenzt.

[Ping Sketch mit Workaround](https://github.com/luetzel/arduino_workshop/blob/master/10_ping_timeout/10_ping_timeout.ino)

Durch diesen Workaround ist der Sensor voll funktionstüchtig. Vorsicht bei der Verwendung von einigen
Bibliotheken! Nicht alle unterstützen diesen Workaround.

### Verwendung von Bibliotheken

Für die meisten Bauteile gibt es Bibliotheken, die das Programmieren - gerade für Anfänger - erheblich vereinfachen.
Bibliotheken lassen sich über das Menü der Arduino-IDE "Sketch > Bibiothek einbinden > Bibliothek verwalten"
suchen und installieren. Bevor eine Bibliothek in einem Sketch verwendet werden kann muss eine sogenannte Header-Datei
(Dateiendung *.h) eingebunden werden. Das erfolgt mit der #include ```<library.h>``` Anweisung. Zu jeder Library
werden gewöhnlich Code-Beispiele mitgeliefert, welche die Verwendung der Bibliothek erklären. Für den Ultraschallsensor
können wir z.B. die NewPing Library verwenden:
```
#include <NewPing.h>

#define TRIGGER_PIN  7
#define ECHO_PIN     8
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(50);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
}
```

Wenn die NewPing Library verwendet wird, genügt es die Anschluss-Pins und ein "Sensor-Objekt" (hier: "sonar" genannt) zu deklarieren.
Die Funktion "ping_cm()" wird von der Bibliothek bereitgestellt, wodurch der eigene Programmieraufwand erheblich reduziert wird und
 wesentlich "übersichtlicherer" Code entsteht.

### 16x2 LCD mit PCF8574 Backplate / Barometer BMP280

![Arduino Nano mit LED](https://github.com/luetzel/arduino_workshop/blob/master/Fritzing/17_BMP280_16x2_LCD.jpg)

Zur Verwendung von Bauteilen mit I2C-Anschluss muss die korrekte Adresse im Arduino-Sketch konfiguriert werden. Wenn die Adresse nicht
bekannt ist kann diese mit der I2C-detect Library ermittelt werden. Die Bibliothek kann über das Menü "Sketch > Bibliothek verwalten
Bibliothek einbinden" installiert werden. Nach dem Hochladen des mitgelieferten Beispiels "i2cdetect" werden im
seriellen Monitor die Adressen sämtlicher angeschlossener I2C Bauteile angezeigt:

```
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- --
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
20: -- -- -- -- -- -- -- 27 -- -- -- -- -- -- -- --
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
70: -- -- -- -- -- -- 76 --
```

Die 16x2 LC Displays mit PCF8574-Backplate haben entweder die Adresse 0x3F oder 0x27. Der BMP280 Sensor (Barometer) hört auf die
Adresse 0x76.

Manchmal kann es erforderlich sein die Adresse direkt in den C-Header Dateien der Bibliotheken einzustellen. Dafür navigiert man in das
Arduino-Library Verzeichnis (z.B. unter Windows: Meine Dokumente/Arduino/libraries) und öffnet die betroffene Header-Datei. Für den BMP280
Sensor ist das die Datei ```Adafruit_BMP280.h```. Dort trägt man in der Zeile

```
 #define BMP280_ADDRESS (0x76)
```

0x76 statt der vorgegebenen Adresse 0x77 ein.

Beim Anschließen der I2C Bauteile ist auf die Polarität GND/VCC und Spannungsversorgung zu achten (5V bzw **3V3 für das Barometer!**)
Der SDA Pin des LCD und/oder des Barometers wird mit dem Pin A4 des Arduino Nano verbunden. Der SCL Pin mit dem Pin A5 des Arduino.
In jedem Fall muss die **Beschriftung der Pins auf dem Bauteil** beachtet werden!

## Prüfungsaufgabe

*folgt*
