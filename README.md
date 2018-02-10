## Arduino-Workshop
### Arduino-Workshop am Institut für Berufliche Bildung und Arbeitslehre der TU-Berlin im Jan/ Feb2018

Kursbeginn ist **Freitag, der 05.01.2018 um 14:00 Uhr s.t.** im Elektrolabor MAR U0.37 (bis 17:15 Uhr).

Der zweite geblockte Kurs findet voraussichtlich zwischen dem 19.02.2018 und 23.02.2018 jeweils von
 9:00 Uhr s.t. bis um ca. 15 Uhr statt (Aushang beachten!).

**WICHTIG:** Bitte bringen Sie ihr eigenes Notebook oder Laptop mit und installieren Sie bitte vorab die
 aktuelle Version der Arduino-Entwicklungsumgebung (Version 1.8.5).

Für die Startersets wird am ersten Tag ein Pfand von 35,- € eingesammelt das sie bei Rückgabe
des vollständigen und unbeschädigten Sets am Ende des Kurses zurück erhalten. **Bitte bringen Sie den
Betrag passend mit!**

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

Auf einem Apple Gerät hat die Verwendung des seriellen Monitors zu einemSystem-Absturz geführt.
Davon betroffen sind nach meiner Recherche ausschließlich Geräte mit MacOS "Sierra".
Abhilfe schafft möglicherweise ein modifizierter Treiber, der [hier heruntergeladen](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver) werden
kann.

#### Den richtigen COM-Port finden
Auf Windows-Geräten ist es manchmal schwierig den richtigen COM-Port zu finden mit dem der Arduino
über USB verbunden ist. Dieses Video erklärt wie man den richtigen Port im Window-Geräte Manager
finden kann:

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
Unter Windows z.B. in das Verzeichnis `My Documents/Arduino`.

### Datenblätter

Im Verzeichnis `datasheets` finden Sie eine Sammlung von Datenblättern zu den im Starter-Kit enthaltenen
Bauteilen. Bitte beachten Sie, dass das Starter-Kit zum Teil baugleiche Teile anderer Hersteller enthält.

Bitte beachten Sie, dass das Barometer-Breakout eine Versorgungsspannung von 3V3 benötigt und nicht mit 5 Volt
Versorgungsspannung betrieben werden darf.

### Fritzing.org

Optional können Sie Fritzing auf Ihrem Gerät installieren. Mit Fritzing kann man elektronische
Schaltungen am Computer entwickeln bzw. dokumentieren. Die Bauteile können per drag'n drop auf
dem Steckbrett plaziert werden.

Das Programm können Sie hier für [Windows, MacOS oder Linux herunterladen](http://fritzing.org/download/).

Im Unterverzeichnis [fritzing](https://github.com/luetzel/arduino_workshop/blob/master/fritzing) finden Sie die Schaltpläne, die Sie während der praktischen Übungen
kennengelernt haben:

![Arduino Nano mit LED](https://github.com/luetzel/arduino_workshop/blob/master/fritzing/01_LED.jpg)

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

Am 26.01 haben wir versucht den Ultraschall-Sensor HC-SR04 zu verwenden. Leider haben die Sensoren bei
nicht allen Teilnehmer*Innen zuverlässig funktioniert. Die Ursache ist ein Fehler in der Firmware des
Microcontrollers, der sich auf der Sensor-Platine befindet. Offenbar sind nicht alle der gelieferten
 Sensoren davon betroffen.

Bitte beim Stecken der Schaltung auf die Orientierung des Sensors achten und VCC/GND nicht verwechseln!

![HC-SR04](https://github.com/luetzel/arduino_workshop/blob/master/fritzing/13_Ultraschall.jpg)

Der Fehler in der Firmware des Sensors kann dazu führen, dass dieser "einfriert" wenn kein Echo empfangen wird.
 In anderen Worten, der Sensor wartet für eine unbegrenzte Zeit auf das eintreffende Echo. Abhilfe schafft
die Programmierung eines "Timeouts":

```
duration = pulseIn(echoPin, HIGH, 30000);
```

und anschließendem "Reset" des Sensors. Auf den echoPin wird dafür ein LOW für 200 us geschrieben.
Im folgenden Sketch wird außerdem die Ausgabe der Distanz in cm auf ein Intervall zwischen 5
und 400 cm begrenzt.

[Ping Sketch mit Workaround](https://github.com/luetzel/arduino_workshop/blob/master/ping_timeout/ping_timeout.ino)

Durch diesen Workaround ist der Sensor voll funktionstüchtig. Vorsicht bei der Verwendung von Libraries/
Bibliotheken, denn nicht alle unterstützen diesen Workaround.

### Verwendung von Bibliotheken

Für die meisten Bauteile gibt es Bibliotheken, die das Programmieren - gerade für Anfänger - erheblich vereinfachen.
Bibliotheken lassen sich über das Menü der Arduino-IDE "Sketch > Bibiothek einbinden > Bibliothek verwalten"
suchen und installieren. Bevor eine Bibliothek in einem Sketch verwendet werden kann muss eine sogenannte Header-Datei
(Dateiendung *.h) eingebunden werden. Das erfolgt mit der #include ```<library.h>``` Anweisung. Mit jeder Library
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

Wenn die NewPing Library verwendet wird genügt es die Anschluss-Pins und ein "Sensor-Objekt" (hier: "sonar" genannt) zu deklarieren.
Die Funktion "ping_cm()" wird von der Bibliothek bereitgestellt, wodurch sich der eigene Programmieraufwand erheblich reduziert und
 zudem sehr "übersichtlicher" Code entsteht.

### 16x2 LCD mit PCF8574 Backplate / Barometer BMP280

Zur Verwendung von Bauteilen mit I2C-Anschluss muss die korrekte Adresse im Arduino-Sketch konfiguriert werden. Wenn die Adresse nicht
bekannt ist kann diese mit der I2C-detect Library ermittelt werden. Die Bibliothek kann über das Menü "Sketch > Bibliothek verwalten
Bibliothek einbinden" der Arduino-IDE installiert werden. Nach dem Hochladen des mitgelieferten Beispiels "i2cdetect" werden im
seriellen Monitor die Adressen sämtlicher angeschlossener I2C devices angezeigt:

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

Die 16x2 LC Displays mit PCF8574 Backplate haben entweder die Adresse 0x3F oder 0x27. Der BMP280 Sensor (Barometer) hört auf die
Adresse 0x76.

Manchmal kann es erforderlich sein die Adresse in den C-Header Dateien der Bibliotheken einzustellen. Dafür navigiert man in das
Arduino-Library Verzeichnis (Unter Windows: Dokumente/Arduino/libraries) und öffnet die betroffene Header-Datei. Für den BMP280
Sensor öffnet man die Datei Adafruit_BMP280.h und trägt in der Zeile

```
 #define BMP280_ADDRESS                (0x76)
```

0x76 statt der voreingestellten Adresse 0x77 ein.

Beim Anschließen der I2C Bauteile ist auf die Polarität GND/VCC und Spannungsversorgung zu achten (5V bzw 3V3 für das Barometer)!
Der SDA Pin des LCD und/oder des Barometers wird mit dem Pin A4 des Arduino Nano verbunden. Der SCL Pin mit dem Pin A5 des Arduino.

## Prüfungsaufgabe

Bauen Sie das Modell einer Einparkhilfe, so wie man sie in vielen modernen PKWs vorfindet.

Die Prüfungsaufgabe besteht aus insgesamt 3 Teilen:

1.) Beschreiben Sie in Textform (nicht mehr als 1 DIN A4 Seite) aus welchen Komponenten/ Bauteilen die Einparkhilfe
besteht und welche Funktionen z.B. optische oder akustische Signale implementiert werden sollen. Bitte senden Sie mir
die Beschreibung als PDF-Datei - andere Dateiformate werden **NICHT** angenommen.


2.) Zeichenen Sie einen **funktionsfähigen** Schaltplan mit dem Programm Fritzing. Sie dürfen alle Bauteile verwenden,
auch solche, die nicht im Starter-Kit enthalten waren!

3.) Schreiben Sie einen Arduino-Sketch für die Steuerung der verwendeten Bauteile in 2.) Zur Lösung der Aufgabe
dürfen Sie Libraries/ Bibliotheken aus dem Internet verwenden. Kommentieren Sie im Sketch wo Sie die Bibliothek
heruntergeladen haben, z.B:

```
#include <ultrasonic.h> // http://github.com/username/arduino_ultrasonic.git
```

Bitte **überprüfen** Sie vor Abgabe ob sich Ihr Sketch in der Arduino-IDE kompilieren lässt (auf den kleinen Haken
oben links klicken).

### Abgabe der Prüfungsaufgabe

Ihr PDF, den Schaltplan als JPG und den Arduino-Sketch (*.ino Datei) senden Sie per Email bis spätestens 3 Wochen
nach Kursende, d.h. den **09. März 2018**

Für die Benotung werden alle drei Aufgabenteile gleich gewichtet, d.h. gehen zu je 1/3 in die Gesamtnote ein.
