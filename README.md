# EBS-AUD
Assistive Ultraschall-Distanzmessung für Rollstühle


## Allgemein
Das Haupt-System, die Box mit dem Arduino, der Stromversorgung und einem Sensor, wird unter der Fussablage des Rollstuhls angebracht. Diese lässt sich durch Klettverschluss-Punkte leicht abmontieren und austauschen. Alles Elemente des Projekts sind modular. Es können leicht weitere Sensoren angebracht werden, der Arduino kann einfach ausgetauscht werden und die Powerbank lässt sich zum Aufladen oder Austauschen leicht entfernen.

Der Arduino liest die Werte des Ultraschallmessers aus, berechnet die Distanz und gibt diese auf dem LCD-Display aus. Zusätzlich leuchtet die RGB-LED in Signalfarben um die Gefahr der Distanz zu bewerten.

* < 5 cm → grünes Licht
* 5-10 cm → gelbes Licht
* \> 10 cm → rotes Licht


## Material
* Haupt-Box (3D-Druck oder Laser Cutter)
* Arduino (UNO)
* Ultraschallsensor (HC - SR04, Datenblatt)
* Powerbank (ca 2500mA/h für einen Tag)
* Gehäuse für Signalausgabe
* 16x2 LCD-Display (1602A, Datenblatt)
* RGB-LED

## Verschaltung

### Ultraschallsensor 1
* Sensor1.VCC ( → Breadboard ) → Arduino.5V
* Sensor1.Trig → Arduino.A2 (beliebig, Festlegung im Code)
* Sensor1.Echo → Arduino.A3 (beliebig, Festlegung im Code)
* Sensor1.GND → Arduino.GND


### Ultraschallsensor 2
* Sensor2.VCC → Arduino.5V
* Sensor2.Trig → Arduino.A4 (beliebig, Festlegung im Code)
* Sensor2.Echo → Arduino.A5 (beliebig, Festlegung im Code)
* Sensor2.GND → Arduino.GND


### LCD-Display
* LCD.GND (Pin1) → Arduino.GND
* LCD.VCC (Pin2) → Arduino.5V
* LCD.V0 (Pin3) → Arduino.3V3
* LCD.RS (Pin4) → Arduino.Pin2
* LCD.R/W (Pin5) → Arduino.GND
* LCD.E (Pin6) → Arduino.Pin3
* LCD.Pin11 (D4) → Arduino.Pin4
* LCD.Pin12 (D5) → Arduino.Pin5
* LCD.Pin13 (D6) → Arduino.Pin6
* LCD.Pin14 (D7) → Arduino.Pin7
* LCD.Pin15 (A) → Arduino.5V
* LCD.Pin16 (K) → Arduino.GND


### RGB-LED
* LED.GND → Arduino.GND
* LED.Red → Arduino.Pin11
* LED.Green → Arduino.Pin10
* LED.Blue → Arduino.Pin9


## Gehäuse

* Gehäuse Arduino, Ultraschallsensor 1, Powerbank
* 3D-Druck
* Laser Cutter
* Gehäuse Display + LED 3D-Druck
