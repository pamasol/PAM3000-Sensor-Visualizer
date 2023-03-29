# PAM3000-Sensor-Visualizer

## Functions

### Stoppuhr
Clicking on the menu Stoppuhr leads to the function time measurement with start and stop signals.

Sensor 1 = Start signal

Sensor 2 = Stop signal

All measurements over middle range are marked blue.

The button Referenz saves the current measurement as a reference. It will show the diference for the following meassurements.

Needed adapter type A

---

### Doppel-Stoppuhr
Time measurements for slave cylinders (Absenkstationen)

All measurements over middle range are marked blue.

Needed adapter type A

---

### Geschwindigkeitsanzeige Takt
Speed measurement for machines with internal tact sensors.

Needed adapter type ?

---

### Sortierer
Speed measurment with light barrier on the outlet side of the sorter.

Only values with a minimum of 50% of the highest value are taken into consideration. All values under the median are marked red.

Light barrier type:
[= o  ] Light sensor with reflection
[- o -] Light barrier

Needed adapter type B

---

### Analogeanzeige
Clicking on the menu *Analoganzeige* leads to the function "read analog input". Clicking the following options will show you the current measurement form 4-20mA.

| Option                      | Range                              | Adapter type |
|-----------------------------|------------------------------------|--------------|
| **Pressure measurement**    | 10bar, 20bar, 40bar, 50bar, 100bar | Type C       |
| **Temperature measurement** | 100°C, 150°C, 350°C                | Type C       |
| **Flow measurement**        | 2500 Nl/min                        | Type F       |

"Set 0" will set the current value back to 4mA.

The function Berechnung is used for calculating a flow measurement.

The function Graphik will draw a graph with the current selected sensor measurements. The time frame can be selected. 

The function Export can be used after a completed measurement of a graph. It will export all measurements in to a text file on the SD card. The values get directly imported to an excel file with a graph. Pushing the button Export deletes the previous file and creates a new one.

---

### IO Tester
Signal test of sensors.

Needed adapter type U

---

### Magnetpolanzeige
Displays the south pole / north pole of a magnet

The sensor is built-in to the side of the PAM3000. The magnet gets detected inside of the circle area.

---

### Speed Sensor
Displays speed of the adapter.
1. Press Start button
2. Hold the speed sensor wheel on the surface you want to measure
3. Speed is displayed in m/min

The function Referenz saves the current speed. The next meassurement at 50Hz displays the needed frequency adjustment.

Needed adapter type V

---

### Einstellungen
Adjustments to time/date, I2C-scanner and the buzzer volume

---

### Distanzsensor
Measures the distance between 30-1000mm with an accuracy of 1mm.

Needed adapter type D

---

### Neigungs Sensor
Shows current inclination of the Sensor.

Needed adapter type N

---

### Zähler
Counting function with master counter

---

### MP3 Player
Plays selected music playlist in the background.

---

### Adaptor

**Adapter type A**:
Adapter with two PE-converters for pneumatic measurements.

**Adapter type B**:
Adapter for two matrix light barriers.

**Adapter type C**:
Adapter for analog signal 0-20mA.

**Adapter type D**:
Adapter for distance measurement 30-1000mm.

**Adapter type F**:
Adapter for flow measurement with ifm SD9000
sensor.

**Adapter type N**:
Adapter to align machines.

**Adapter type U**:
Universal clamp adapter.

**Adapter type V**:
Adapter to measure speed.

**Adapter type Y**:
Adapter with the possibility to combine different adapters.

**Adapter type I2C**:
Adapter to connect I2C sensors externaly.

**Adapter type Klemmen**:
Universal terminal adapter

**Messadapter**:
To measure the values on the adapters with an external meter

---

## Hardware

* Touch-Panel Gen-uLCD-50DCT-CLB-SB-AR from [4D Systems](https://4dsystems.com.au/gen4-ulcd-50dct-clb-sb-ar)
* Arduino Board Due 32-Bit from [Arduino CC](https://www.arduino.cc/en/Guide/ArduinoDue)
* Grove Base Shield V2.0 for Arduino from [Seeed](https://www.seeedstudio.com/Base-Shield-V2.html)

## IDE installation and preparation

1. Download and install the open-source Arduino Software (IDE) from [arduino.cc](https://www.arduino.cc/en/main/software) in version `1.8.*`.

2. Clone this project with `git clone https://github.com/pamasol/PAM3000-Sensor-Visualizer.git` and open the `PAM3000-Sensor-Visualizer.ino` file with the Arduino IDE.

3. Update Arduino IDE settings according to the Wiki page [Arduino IDE Setup](https://github.com/pamasol/PAM3000-Sensor-Visualizer/wiki/Arduino-IDE-Setup).


## Workshop4 installation

1. Download and install the Windows software Workshop4 from [4dsystems.com.au/workshop4](https://4dsystems.com.au/workshop4).

## Helpful sources

* [Arduino language reference](https://www.arduino.cc/reference/en/)
* [Arduino Adaptor Shield](https://github.com/pamasol/PAM3000-Sensor-Visualizer/files/4503403/4D.Arduino.Adaptor.Shield.pdf) Datasheet
* [4D Systems 5" Display](https://github.com/pamasol/PAM3000-Sensor-Visualizer/files/4503404/4D.Systems.5Zoll.TP.pdf) Datasheet
* [DIABLO16 Embedded Graphics Processor](https://github.com/pamasol/PAM3000-Sensor-Visualizer/files/4503399/diablo16_serialcmdmanual_r_2_1.pdf) Serial Command Reference

https://www.youtube.com/watch?time_continue=70&v=L1TPs6dI11k&feature=emb_title