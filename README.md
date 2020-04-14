## Arduino Grundkurs - TU-Berlin (L543, ALBA WP7)
### Institut für Berufliche Bildung und Arbeitslehre - Sommersemester 2020

* Der Kurs findet in diesem Semester ausschließlich **online** statt!
* Der Termin für den Kurs-Start wird noch bekannt gegeben.
* Den Einschreibeschlüssel/ Zugangsdaten und Link für die Teilnahme am Online-Kurs erhalten Sie per E-Mail.
* **WICHTIG:** Für die Teilnahme am Kurs benötigen Sie ein eigenes Notebook, einen Laptop oder Desktop-PC.
* Die Betreuung des Kurses erfolgt nach dem Flipped-Classroom-Prinzip. D.h. Sie lernen selbständig und nutzen dafür eine  
eigens eingerichtete Moodle-Lern-Plattform.
* Fragen werden per Forum, Chat und Online-Video-Sprechstunden beantwortet.
* Die Termine für die Online-Sprechstunden werden mit Ihnen abgestimmt.
* Installieren Sie bitte die aktuelle Version der [Arduino-Entwicklungsumgebung](https://www.arduino.cc/en/Main/Software) (Version 1.8.12) auf Ihrem Computer.
* Für die Arduino-Starterkits wird ein Pfand in Höhe von 30,- € erhoben, das Sie bei Rückgabe des vollständigen und unbeschädigten Kits zurück erhalten.
* Der Termin und der Ort für die Übergabe/ Abholung der Kits wird noch bekannt gegeben. 
* **Bitte bringen Sie den Betrag möglichst passend mit, weil ich keine großen Summen Wechselgeld bereithalten kann!**

### Installation der Arduino-Entwicklungsumgebung
Bitte laden Sie sich die aktuelle Version der Arduino-Entwicklungsumgebung für Ihr Betriebssystem herunter.

* [Link zum Download der Entwicklungsumgebung](https://www.arduino.cc/en/Main/Software)

* Eine Installationsanleitung für Windows, MacOSX oder Linux finden Sie unter diesem Link: 
[Installationsanleitung](https://www.arduino.cc/en/Guide/HomePage)

### Treiber
Wenn Sie die Arduino-Entwicklungsumgebung unter Windows oder MacOSX verwenden wollen, müssen Sie zusätzlich einen Treiber für den CH340-USB-Controller-Chip installieren,
 damit Sie die im Kurs verwendeten Arduino Nano Platinen mit Ihrem Notebook/ Desktop-PC über den USB-Anschluss programmieren können.

* [Link zum Download der Treiber](https://wiki.wemos.cc/downloads)
* [Offizieller Treiber des Herstellers](http://www.wch.cn/download/CH341SER_EXE.html)

Auf Win10 Geräten müssen Sie möglicherweise die Sicherheitseinstellungen so verändern, dass Sie auch unsignierte Treiber auf Ihrem Gerät installieren können.

#### Probleme mit Apple-Geräten
Auf Apple-Geräten kann es bei Verwendung des original CH340 Treibers zu System-Abstürzen kommen (Kernel-Panic). Betroffen davon sind nach meiner Recherche ausschließlich Geräte mit MacOS "Sierra".
 Abhilfe schafft ein gepatchter Treiber, der [hier heruntergeladen](http://download.makeblock.com/mblock/CH34x_Install_V1.3.pkg) werden kann.

#### Den richtigen COM-Port finden
Auf Windows-Geräten ist es manchmal schwierig den richtigen COM-Port zu finden, mit dem der Arduino per USB verbunden ist. Dieses Video erklärt wie man den korrekten USB-Port mit dem Windows-Geräte-Manager aufspürt:

* [Wie finde ich den richtigen COM-Port? (Video)](https://www.youtube.com/watch?v=hou4okcCX7E)

#### Hinweise für Linux-Nutzer
Falls Sie ein Notebook mit einer aktuellen Linux-Distribution (Ubuntu, Debian, SuSE o. ä.) verwenden müssen Sie in der Regel keinen Treiber installieren, denn der Linux-Kernel unterstützt den CH340-Chip bereits out-of-the-box.

Beim Linux-Kernel ab der Version 5.5.x wurden Veränderungen am CH340-Modul vorgenommen, die dazu führen können, dass sich keine Firmware in den Flash-Speicher des Arduino übertragen lässt. Falls Sie noch einen Kernel 
einsetzen, der älter als Patch-Level 5.5.8 ist, müssen Sie ein Kernel-Update durchführen, um das Problem zu beheben. Die Kernel-Serie 5.4.x und 5.6.x ist nicht betroffen.

Damit Sie unter Linux auf den Seriellen Port schreiben können, müssen Sie ihren Benutzernamen der Gruppe `dialout` hinzufügen. Das geht durch Eingabe des Befels:

`sudo usermod -a -G dialout username`

auf der Konsole. Damit erlangen Sie Schreibrechte für /dev/ttyUSB0 Port.

### Beispiel-Codes
Ab dem 20. April 2020 können Sie hier alle [Beispiel-Codes](https://gogs.raspberryblog.de/superuser/arduino_workshop/archive/master.zip) und weiteres Arbeitsmaterial für die praktischen Übungen herunterladen.
Das Verzeichnis wird im Verlauf des Kurses gelegentlich aktualisert.

Wenn Sie das Tool ['git'](https://git-scm.com/download) auf Ihrem System installiert haben, können Sie den Beispiel-Code auch durch Eingabe des Befehls:

```
git clone https://gogs.raspberryblog.de/superuser/arduino_workshop.git
```

herunterladen und im Fall von Updates später mit

```
git pull
```

aktualisieren.

Die Inhalte des Verzeichnis `sketches` bzw. `libraries` kopieren Sie bitte in die zugehörigen Unter-Verzeichnisse, die auf Ihrem System während der Installation der Arduino-Entwicklungsumgebung angelegt wurden.
Unter Windows ist das in der Regel das Arbeits-Verzeichnis `Meine Dokumente/Arduino`.

In das Verzeichnis libraries kopieren Sie zusätzliche Bibliotheken, welche die Verwendung von verschiedener Hardware-Module erleichtern.

### Unterstützung anderer Mikrocontroller
Inzwischen kann man mit der Arduino-IDE auch andere Mikrocontroller programmieren. Die Installation der dafür erforderlichen Dateien kann über den Board-Manager der Arduino-IDE erfolgen.

Die URLs zu den Paketquellen können in den Einstellungen der Arduino-IDE hinterlegt werden. Eine Anleitung dafür findet man auf dieser Seite:

* https://github.com/arduino/Arduino/wiki/Unofficial-list-of-3rd-party-boards-support-urls

### Datenblätter
Im Verzeichnis `Datasheets` finden Sie eine Sammlung von Datenblättern zu den im Starter-Kit enthaltenen Bauteilen. Bitte beachten Sie, dass das Starterkit zum Teil baugleiche Teile anderer Hersteller enthält.
Das Barometer-Breakout-Modul (BMP280) benötigt eine Versorgungsspannung **3,3 Volt** und darf deshalb **nicht** an 5 Volt betrieben werden! Der Sensor wird dabei zerstört!

### Fritzing.org
Für das Zeichnen von Schaltskizzen sollten Sie das kostenlose Programm Fritzing auf Ihrem Gerät installieren.
Mit Fritzing lassen sich elektronische Schaltungen am Computer zeichnen und dann als JPG-Bild exportieren. Die Bauteile können per drag'n drop auf dem Steckbrett platziert werden. Die Bedienung ist recht intuitiv.

Das kostenlose Programm können Sie hier für [Windows, MacOS oder Linux herunterladen](https://github.com/fritzing/fritzing-app/releases/tag/CD-548). Es handelt sich dabei um eine Entwickler-Version.
 Falls das Programm nicht startet oder abstürzt, versuchen Sie bitte eine ältere Version zu installieren.

Im Unterverzeichnis [Fritzing](https://https://gogs.raspberryblog.de/superuser/arduino_workshop/blob/master/Fritzing) finden Sie einige Schaltpläne, die Sie während der praktischen Übungen kennengelernt haben,
sowohl als JPG-Bild, als auch im Fritzing-Datei-Format. Wenngleich die Bauteil-Bibliothek von Fritzing sehr umfangreich ist, sind nicht alle Bauteile des Starterkits enthalten. Im Verzeichnis Fritzing-Zusatzbauteile finden Sie 
weitere 
Bauteile, die Sie der Bibliothek per drag'n'drop hinzufügen können.

![Arduino Nano mit LED](https://gogs.raspberryblog.de/superuser/arduino_workshop/src/master/Fritzing/01_LED.jpg)

### Arduino Code-Referenz Handbuch
Das deutsche Arduino Forum hat ein sehr ausführliches Code-Referenz-Handbuch erstellt, in dem sämtliche Funktionen der Arduino-IDE dokumentiert sind. Es ist verständlich geschrieben und für Anfänger geeignet. Das Handbuch kann 
kostenlos als PDF heruntergeladen werden.

* [Arduino Code-Referenz](https://www.arduinoforum.de/referenz.php)

### Elektronik Kompendium
Das Elektronik-Kompendium ist ein sehr gutes Nachschlagwerk, um die im Kurs behandelten physikalischen Gesetzmäßigkeiten und Grundschaltungen nachzuschlagen:

* [Ohmsches Gesetz](http://www.elektronik-kompendium.de/sites/grd/0201113.htm)
* [Zweite Kirchhoffsche Regel](https://www.elektronik-kompendium.de/sites/grd/0608011.htm)
* [Vorwiderstand einer LED berechnen](https://www.elektronik-kompendium.de/sites/grd/1006011.htm)
* [Unbelasteter Spannungsteiler](https://www.elektronik-kompendium.de/sites/slt/0201111.htm)

### Probleme mit den Ultraschallsensoren
Bitte achten Sie beim Zusammenstecken der Schaltung auf die Orientierung des Sensors! VCC und GND dürfen nicht verwechselt werden!

![HC-SR04](https://gogs.raspberryblog.de/superuser/arduino_workshop/src/master/Fritzing/13_Ultraschall.jpg)

Ein Fehler in der Firmware des Sensors kann dazu führen, dass dieser "einfriert" wenn kein Echo empfangen wird. In anderen Worten, der Sensor wartet für eine unbegrenzte
 Zeit auf das eintreffende Echo. Abhilfe schafft die Programmierung eines "Timeouts", das den Sensor nach einer bestimmten Wartezeit zurücksetzt:

```
duration = pulseIn(echoPin, HIGH, 30000);
```

Auf den echoPin wird dafür ein LOW für 200 us geschrieben. Im folgenden Sketch wird außerdem die Ausgabe der Entfernung in cm auf ein Intervall zwischen 5 und 400 cm begrenzt.

[Ping Sketch mit Workaround](https://gogs.raspberryblog.de/superuser/arduino_workshop/src/master/10_ping_timeout/10_ping_timeout.ino)

Nicht alle Bibliotheken unterstützen die Timeout-Funktion.

### Verwendung von Bibliotheken
Für die meisten Bauteile gibt es Bibliotheken, die das Programmieren - gerade für Anfänger - erheblich vereinfachen. Bibliotheken lassen sich über das Menü der Arduino-IDE "Sketch > Bibiothek einbinden > Bibliothek verwalten" auffinden und installieren.
 Bevor eine Bibliothek in einem Sketch verwendet werden kann, muss eine sogenannte Header-Datei (Dateiendung *.h) importiert werden. Das erfolgt mit der #include ```<library.h>``` Anweisung. Zu jeder Library werden in der Regel
Code-Beispiele mitgeliefert, welche die Verwendung der Bibliothek erklären. Für den Ultraschallsensor können wir z.B. die NewPing Library nutzen:

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

Wenn die NewPing Library importiert wurde, genügt es die Anschluss-Pins zu deklarieren und eine Instanz des "Sensor-Objekts" zu erzeugen (hier wurde dem Objekt der Name "sonar" gegeben).
Die Funktion "ping_cm()" wird von der Bibliothek bereitgestellt, wodurch der eigene Programmieraufwand erheblich reduziert wird.

### 16x2 LCD mit PCF8574 Backplate und Barometer BMP280

![Arduino Nano mit LED](https://gogs.raspberryblog.de/superuser/arduino_workshop/src/master/Fritzing/17_BMP280_16x2_LCD.jpg)

Bei Verwendung von Bauteilen mit I2C-Bus muss die korrekte Adresse im Arduino-Sketch angegeben werden. Wenn die Adresse nicht bekannt ist, kann diese mit der i2cdetect Library ermittelt werden. Die Bibliothek wird über das Menü 
"Sketch > Bibliothek verwalten > Bibliothek einbinden" installiert. Nach dem Hochladen des mitgelieferten Beispiels "i2cdetect" werden im seriellen Monitor die Adressen aller angeschlossenen I2C-Bauteile sichtbar, z.B.:

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

Die 16x2 LC-Displays mit PCF8574-Adapter haben entweder die Adresse 0x3F oder 0x27. Der BMP280 Sensor (Barometer) hört auf die Adresse 0x76.
Manchmal kann es erforderlich sein die Adresse direkt in den C-Header Dateien der Bibliotheken zu ändern. Dafür navigiert man in das Arduino-Library Verzeichnis (z.B. unter Windows: Meine Dokumente/Arduino/libraries) und öffnet die 
betroffene Header-Datei. Beim BMP280-Sensor ist das die Datei ```Adafruit_BMP280.h```. Dort trägt man in der Zeile

```
 #define BMP280_ADDRESS (0x76)
```

0x76 anstelle der voreingestellten Adresse 0x77 ein. Beim Anschließen der I2C-adressierter Bauteile ist auf die Polarität GND/ VCC sowie deren Spannungsversorgung zu achten (**3V3 für das Barometer!**). Häufig werden die Module 
auch für andere Mikrocontroller oder Ein-Platinen-Computer (Raspberry Pi) verkauft. Ein Blick ins Datenblatt hilft, um herauszufinden, ob das Bauteil 5 Volt-tolerant ist oder einen Pegel-Wandler (Level-Shifter) benötigt.

Grundsätzlich gilt für alle Bauteile mit I2C-Bus:

* Der **SDA-Pin** wird immer mit dem Pin A4 des Arduino Nano verbunden.
* Der **SCL-Pin** wird immer mit dem Pin A5 des Arduino Nano verbunden.

## Prüfungsaufgabe
Wird zu einem späteren Zeitpunkt bekannt gegeben.
