## Arduino-Workshop
### Arduino-Workshop am Institut für Berufliche Bildung und Arbeitslehre der TU-Berlin im Jan/Feb2018

Hier entsteht in Kürze ein Code-Repository für den o.g. Kurs an der TU-Berlin.

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

Falls Sie ein Notebook mit einer aktuellen Linux-Distribution (Ubuntu, Debian, SuSE, etc.) verwenden,
wird kein Treiber benötigt, denn der Linux-Kernel unterstützt das Board bereits.

Damit Sie nicht mit Administratorrechten arbeiten müssen, fügen Sie Ihren Benutzernamen der
Gruppe `dialout` hinzu.

`sudo usermod -a -G dialout username`

### Beispiel-Code

Ab Mitte/Ende Dezember 2017 können Sie hier den [Beispiel-Code](https://github.com/luetzel/arduino_workshop/archive/master.zip)
 und weiteres Arbeitsmaterial für die praktischen Übungen herunterladen.

Die Inhalte des Verzeichnis `sketches` bzw. `libraries` speichern Sie bitte in den zugehörigen Verzeichnissen,
die auf Ihrem System während der Installation der  Arduino-Entwicklungsumgebung angelegt wurden. Unter Windows
z.B. im Verzeichnis `My Documents/Arduino`.

