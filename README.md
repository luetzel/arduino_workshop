## Arduino-Workshop
### Arduino-Workshop am Institut für Berufliche Bildung und Arbeitslehre der TU-Berlin im Jan/ Feb2018

Kursbeginn ist **Freitag, der 05.01.2018 um 14:00 Uhr s.t.** im Elektrolabor MAR U0.37 (bis 17:15 Uhr).

**WICHTIG:** Bitte bringen Sie ihr eigenes Notebook oder Laptop mit und installieren Sie bitte vorab die aktuelle
Version der Arduino-Entwicklungsumgebung (Version 1.8.5).

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

Wenn Sie das Tool 'git' auf Ihrem System installiert haben, können Sie den Beispiel-Code auch durch
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

Optional können Sie Fritzing auf Ihrem Gerät installieren, das es ermöglicht elektronische
Schaltungen zu entwickeln oder zu dokumentieren.

Das Programm können Sie hier für [Windows, MacOS oder Linux herunterladen](http://fritzing.org/download/).
