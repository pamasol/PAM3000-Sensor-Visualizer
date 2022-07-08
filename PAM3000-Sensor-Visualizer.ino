/********************************************************************************************************************

  Änderungen:     - Programm erstellt

  Version:        001
  Datum:          04.12.2019

  Programmierer:  D.Bernhard, J.Glaus, M.Ruoss

/******************************************************************************************************************

  Programm:       PAM3000_Sensor_Visualizer_002
  Prozessor:      Arduino Due
  Clock:          84MHz

  Version:        002
  Datum:          13.08.2020
    
  Programmierer:  D.Bernhard, J.Glaus, M.Ruoss
   
********************************************************************************************************************

  Änderungen:     - Struktur/Text vereinheitlicht.
                  - Hauptschalter LED integriert.
                  - Lichtsensor Akkuladestand integriert.
                  - Zusätzliche Höchstwertanzeigen bei Geschwindigkeitsanzeige Durchschnitt.
                  - Anzeige von Listen (Letzte Werte).
                  - Serielle Geschwindigkeit von 9600 auf 115200 Baud erhöht.

                    
  Version:        002
  Datum:          13.08.2020

  Programmierer:  M.Ruoss

********************************************************************************************************************

  Änderungen:     - "Alte" Stoppuhr ist Neu "Doppel-Stoppuhr.
                  - "Neu" ist Stoppuhr, mit Start und Stop Signal.
                    
  Version:        003
  Datum:          18.08.2021

  Programmierer:  M.Ruoss

********************************************************************************************************************

  Hochladen: - Board:      "Arduino Due"
             - Port:       "COM07(Arduino Due(Native USB Port))"
             - Programmer: "USBasp"

********************************************************************************************************************

  Info: 
  
  - Display Auflösung 800 x 480 pixel (x =  0 - 799 pixel, y = 0 - 479 pixel)
  - Display RS232 115200 Baud
 
  - Achtung: "Diablo16-Serial-Arduino-Library" auf Version 1.0.0 lassen -> nicht aktualisieren!!
             "Arduino Due" funktioniert bei der höheren Version nicht mehr mit dem Display!



  - USB RS2323 9600 Baud

  - SD Karte muss im FAT16 oder FAT32 formatiert sein!


            
  Struktur:
  
  0.Hauptmenü
  
  1.Doppel-Stoppuhr
    13.Doppel-Stoppuhr Liste
  
  2.Geschwindigkeitsanzeige Takt
    14.Geschwindigkeitsanzeige Takt Liste
    
  3.Analogeanzeige
  4.Magnetpolanzeige
  5.Einstellungen

  6.IO-Tester

  7.Info

  8.Speed Sensor
  9.Distanz Sensor
 
  10.Geschwindigkeitsanzeige Sortierer
    15.Geschwindigkeitsanzeige Sortierer Liste

  16.Stoppuhr
    17.Stoppuhr Liste

  Arduino Due Pinbelegung:

  Pin SCL1 -> (SCL) I2C Bus SCL
  Pin SDA1 -> (SDA) I2C Bus SDA

  Pin 0 -> (TX0) RS232-0 TX Display Kommunikation
  Pin 1 -> (RX0) RS232-0 RX Display Kommunikation
  Pin 2 -> Digital Ausgang Buzzer       
  Pin 3 -> Digital Ausgang Hauptschalter LED 
  Pin 4 -> Digital Ausgang Reset Display
  Pin 5 -> Digital Ausgang Mosfet Versorgung 24VDC
  Pin 6 -> 
  Pin 7 -> Digital Eingang Hallsensor
  Pin 8 -> Digital Eingang Interrupt 8
  Pin 9 -> Digital Eingang Interrupt 9
  Pin 10 -> (CS)   SPI CS 
  Pin 11 -> (MOSI) SPI MOSI
  Pin 12 -> (MISO) SPI MISO
  Pin 13 -> (CLK)  SPI CLK
  Pin 14 -> (TX3) RS232-3 TX
  Pin 15 -> (RX3) RS232-3 RX
  Pin 16 -> (TX2) RS232-2 TX
  Pin 17 -> (RX2) RS232-2 RX
  Pin 18 -> (TX1) RS232-1 TX MP3 Player Kommunikation
  Pin 19 -> (RX1) RS232-1 RX MP3 Player Kommunikation
  Pin 20 -> (SDA) I2C Bus SDA (Standart I2C) Stromsensor INA219 [0x40], Echtzeituhr DS1307 [0x68], Distanzsensor VL53LOX [0x29], 6-Achsen Gyro [0x6A]
  Pin 21 -> (SCL) I2C Bus SCL (Standart I2C) Stromsensor INA219 [0x40], Echtzeituhr DS1307 [0x68], Distanzsensor VL53LOX [0x29], 6-Achsen Gyro [0x6A]
  Pin 22 ->
  Pin 23 ->
  Pin 24 ->
  Pin 25 ->
  Pin 26 ->
  Pin 27 ->
  Pin 28 ->  
  Pin 29 ->
  Pin 30 ->
  Pin 31 ->
  Pin 32 ->
  Pin 33 ->
  Pin 34 ->
  Pin 35 ->
  Pin 36 ->
  Pin 37 ->
  Pin 38 ->
  Pin 39 ->
  Pin 40 ->
  Pin 41 ->
  Pin 42 ->
  Pin 43 ->
  Pin 44 ->
  Pin 45 ->
  Pin 46 ->
  Pin 47 ->
  Pin 48 ->
  Pin 49 ->  
  Pin 50 ->
  Pin 51 ->
  Pin 52 ->
  Pin 53 ->

  Pin A0 -> Analog Eingang Lichtsensor Akkuladestand
  Pin A1 -> Analog Eingang Magnetfeldsensor SS495A
  Pin A2 ->
  Pin A3 ->
  Pin A4 ->
  Pin A5 ->
  Pin A6 ->
  Pin A7 ->
  Pin A8 -> Analog Eingang Spannungsteiler Adapter Typ
  Pin A9 ->
  Pin A10 ->
  Pin A11 ->

  Pin DAC0 -> 
  Pin DAC1 ->

  Pin CANTX ->
  Pin CANRX ->

  USB -> Native USB Port 9600 Baud



  Noch zu erledigen: 

- Bei Geschwindigkeitsanzeige Takt noch Kopfanzahl integrieren,
  imfalle es nur einen Rundenzähler hat!

- IO Tester -> Digital Eingang, 
            -> Digital Eingang Exi (8VDC)
            -> Digital Ausgang  

- Akkuladestand auswerten


- Funktionen mit Bildaufbau und Reset erweitern!



- Standbymodus

- Aktuelle Daten speichern

- Datenlogger

        
*/

/********************************************************************************************************************/
/*      
  Problemlösungen:  - PAM3000 läst sich nicht aufstarten: - Spannung vom Verteilerboard falsch eingestellt,
                                                            der kleine Switch muss auf 5VDC sein!
                                                          - Bibliothek wurde auf neusten Stand aktualisiert,
                                                            es kann sein das die Neuere Version nicht unterstütz wird!
                                                            Die betreffenden library auf alte Version zurück wechseln.
 
                    - Keine Kommunikation mit Arduino Due: - "erase" Reset drücken auf Board, und dann den "Normalen"
                                                             Reset drücken, dann sollte die USB Schnittstelle wieder
                                                             verbinden.
                                                          
*/
/********************************************************************************************************************/

/* SD Karte*/
#include <SPI.h>
#include <SD.h>

/* Echtzeituhr DS1307
   Library "Grove - RTC DS1307" Version 1.0.0 
*/
#include <Wire.h>
#include "DS1307.h"                             
DS1307 Uhr;                                  

/* Display 4D Systems 
   Library "Diablo16-Serial-Arduino-Library" Version 1.0.0 
*/
#include <Diablo_Const4D.h>                  
#include <Diablo_Serial_4DLib.h>             
#define DisplaySerial Serial                  
Diablo_Serial_4DLib Display(&DisplaySerial);  

/* Stromsensor INA219 
   Library "Adafruit INA219" Version 1.2.0
*/
#include <Wire.h>                        
#include <Adafruit_INA219.h> 
#include "Filter.h"          //Analogerfilter
#include "MegunoLink.h"       //Analogerfilter      
Adafruit_INA219 sensor219;                    

/* Speed Sensor LM393 */
//#include "TimerOne.h"

/* Distanzsensor VL53LOX 
   Library "Adafruit_VL53L0X" Version 1.1.3
*/
#include "Adafruit_VL53L0X.h"
#define LOX_ADDRESS 0x29        //0x29 Adresse steht auf dem Sensor!
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

/* 6-Achsen Gyro 
   Library "Seeed Arduino LSM6DS3" Version 2.0.3
*/
#include "SparkFunLSM6DS3.h"
#include "Wire.h"                      
#include "SPI.h"                       
LSM6DS3Core Gyro( I2C_MODE, 0x6A );       //0x6A Adresse steht auf dem Sensor!

/* MP3 Player 
   Library "DFRobotDFPlayerMini" Version 1.0.5 
*/
#include "Arduino.h"   
#include "DFRobotDFPlayerMini.h"

DFRobotDFPlayerMini DFMP3_Player; 
void printDetail(uint8_t type, int value);

/********************************************************************************************************************/

/* Ports */
int DA_Buzzer = 2;                  //Digital Ausgang Buzzer
int DA_Hauptschalter_LED = 3;       //Digital Ausgang Hauptschalter LED
int DA_Display_Reset = 4;           //Digital Ausgang Display Reset
int DA_Versorgung_24VDC = 5;        //Digital Ausgang Versorgung 24VDC
int DE_Hallsensor = 7;              //Digital Eingang Hallsensor
int DE_Sensor_1 = 8;                //Digital Eingang Sensor 1
int DE_Sensor_2 = 9;                //Digital Eingang Sensor 2
int AD_Akkuladestand = 0;           //Analog Eingang Lichtsensor Akkuladestand
int AD_Magnetfeldsensor = 1;        //Analog Eingang Magnetfeldsensor
int AD_Adapter_Typ = 8;             //Analog Eingang Spannungsteiler Adapter Typ

/* SD Karte*/
File Daten_File;          //Daten File
File buzzer;              //buzzer File
File Messung;             //Messung File

String Buzzer_String = "";                        //Buzzer
String Buzzer_Lautstaerke_String = "";            //Buzzer Lautstärke
String Buzzer_Ein_Aus_String = "";                //Buzzer Ein/Aus

/* Echtzeituhr DS1307 */
int Stunden;          
int Minuten;
int Sekunden;
int Monat;
int Tag;
int Jahr;
int Wochentag_Nr;
char Wochentag;

/* Alarm */
bool Alarm_Ein[10];      
int Alarm_Stunden[10];
int Alarm_Minuten[10];
char Alarm_Wochentag;

/* Display */
byte Status_Display;                //Status Display

int Textbreite = 2;                 //Textbreite
int Textrahmen = 3;                 //Textrahmen

int X_Pos_Text;                     //X Positionswert Text
int Y_Pos_Text;                     //Y Positionswert Text

word Kontrast_Display = 10;         //Kontrast Display (1-15)

word Schrifttyp = FONT1;                  //Schrifttyp (FONT1, FONT2, FONT3)

word Texthintergrund_Menue = YELLOW;      //Texthintergrundfarbe Menüstruktur
word Textfarbe_Menue = BLACK;             //Textfarbe Menüstruktur

word Texthintergrund_Taster = GREEN;      //Texthintergrundfarbe Taster ungedrückt
word Textfarbe_Taster = WHITE;            //Textfarbe Taster ungedrückt

word Texthintergrund_2_Taster = GREEN;    //Texthintergrundfarbe Taster gedrückt
word Textfarbe_2_Taster = BLACK;          //Textfarbe Taster gedrückt

word Textfarbe = WHITE;                   //Textfarbe Allgemein
bool Text_ausblenden;                     //Text ausblenden (Textfarbe schwarz)
 
word Status_Touch_Taste;            //Status Touch Taste
word X_Pos_Touch;                   //X Positionswert Touch
word Y_Pos_Touch;                   //Y Positionswert Touch


/* Allgemein */
bool Bild_aufgebaut[50];            //Bildschirm aufgebaut (0-18 Bilder)
int Menue_angewaehlt;               //Menü angewählt
int Letztes_Menue;                  //Letztes angewähltes Menü
int Info_Seite;                     //Info Seite
int Info_Seite_Max = 19;            //Info Seite Max

int Spannung_Adapter_Typ;           //Spannung Adapter Typ
byte Adapter_Typ;                   //Adapter Typ

int Sensor_Akkuladestand;                       //Sensor Akkuladestand
int Anzahl_Mittelwert_Sensor_Akkuladestand;     //Anzahl Mittelwert Sensor Akkuladestand
int Zaehler_Mittelwert_Sensor_Akkuladestand;    //Zähler Mittelwert Sensor Akkuladestand
long Temp_Mittelwert_Sensor_Akkuladestand;      //Temporärer Mittelwert Sensor Akkuladestand
int Mittelwert_Sensor_Akkuladestand;            //Mittelwert Sensor Akkuladestand
int Kleinster_Sensor_Akkuladestand;             //Kleinster Sensor Akkuladestand
int Akkuladestand_Filter;                       //Akkuladestand Filter
int Akkuladestand_auswerten;                    //Akkuladestand auswerten (warten auf Mittelwert)
int Akkuladestand;                              //Akkuladestand (0-100%)
int Akku_leer;                                  //Akkugrenzwert leer
int Akku_laden;                                 //Akkugrenzwert laden
int Akku_voll;                                  //Akkugrenzwert voll

char Text_Zurueck = 'Zrug';         //Text Zurück


/* Einstellungen */
bool Zeit_Button = false;             //Zeit Button

int Buzzer_Einstellungen = 0;    //Buzzer Einstellungen
int Buzzer_Lautstaerke = 255;          //Buzzer Lautstärke

String Buzzer_Lautstaerke_string;           

/* Doppel-Stoppuhr */
bool Startzeit_speichern_D_Stoppuhr_1;          //Startzeit speichern Doppel-Stoppuhr 1
bool Startzeit_speichern_D_Stoppuhr_2;          //Startzeit speichern Doppel-Stoppuhr 2

bool Stoppzeit_speichern_D_Stoppuhr_1;          //Stoppzeit speichern Doppel-Stoppuhr 1
bool Stoppzeit_speichern_D_Stoppuhr_2;          //Stoppzeit speichern Doppel-Stoppuhr 2

int Stunden_D_Stoppuhr_1;             //Stunden Doppel-Stoppuhr 1
int Stunden_D_Stoppuhr_2;             //Stunden Doppel-Stoppuhr 2
int Minuten_D_Stoppuhr_1;             //Minuten Doppel-Stoppuhr 1
int Minuten_D_Stoppuhr_2;             //Minuten Doppel-Stoppuhr 2
int Sekunden_D_Stoppuhr_1;            //Sekunden Doppel-Stoppuhr 1
int Sekunden_D_Stoppuhr_2;            //Sekunden Doppel-Stoppuhr 2
int Millisekunden_D_Stoppuhr_1;       //Millisekunden Doppel-Stoppuhr 1
int Millisekunden_D_Stoppuhr_2;       //Millisekunden Doppel-Stoppuhr 2

int Listen_Startwert_D_Stoppuhr;      //Listen Startwert Doppel-Stoppuhr

int Messungen_D_Stoppuhr_1;           //Messungen Doppel-Stoppuhr 1
int Messungen_D_Stoppuhr_2;           //Messungen Doppel-Stoppuhr 2

volatile unsigned long Startzeit_D_Stoppuhr_1;     //Startzeit Doppel-Stoppuhr 1
volatile unsigned long Startzeit_D_Stoppuhr_2;     //Startzeit Doppel-Stoppuhr 2

volatile unsigned long Zeit_D_Stoppuhr_1;          //Zeit Doppel-Stoppuhr 1
volatile unsigned long Zeit_D_Stoppuhr_2;          //Zeit Doppel-Stoppuhr 2

unsigned long Zeiten_D_Stoppuhr_1[60];    //Zeiten Doppel-Stoppuhr 1 (0-59)
unsigned long Zeiten_D_Stoppuhr_2[60];    //Zeiten Doppel-Stoppuhr 2 (0-59)

unsigned long Hoechstwert_D_Stoppuhr_1;        //Höchstwert Doppel-Stoppuhr 1
unsigned long Hoechstwert_D_Stoppuhr_2;        //Höchstwert Doppel-Stoppuhr 2

unsigned long Summe_Mittelwert_D_Stoppuhr_1;   //Summe Mittelwert Doppel-Stoppuhr 1
unsigned long Summe_Mittelwert_D_Stoppuhr_2;   //Summe Mittelwert Doppel-Stoppuhr 1

unsigned long Mittelwert_D_Stoppuhr_1;         //Mittelwert Doppel-Stoppuhr 1
unsigned long Mittelwert_D_Stoppuhr_2;         //Mittelwert Doppel-Stoppuhr 2
       
unsigned long Kleinstwert_D_Stoppuhr_1;        //Kleinstwert Doppel-Stoppuhr 1
unsigned long Kleinstwert_D_Stoppuhr_2;        //Kleinstwert Doppel-Stoppuhr 2


/* Stoppuhr */
bool Freigabe_Messung_Stoppuhr;             //Freigabe Messung Stoppuhr
bool Messung_aktiv_Stoppuhr;                //Messung aktiv Stoppuhr
bool Startzeit_speichern_Stoppuhr;          //Startzeit speichern Stoppuhr
bool Stoppzeit_speichern_Stoppuhr;          //Stoppzeit speichern Stoppuhr

int Stunden_Stoppuhr;             //Stunden Stoppuhr
int Minuten_Stoppuhr;             //Minuten Stoppuhr
int Sekunden_Stoppuhr;            //Sekunden Stoppuhr
int Millisekunden_Stoppuhr;       //Millisekunden Stoppuhr

int Listen_Startwert_Stoppuhr;      //Listen Startwert Stoppuhr
int Messungen_Stoppuhr;             //Messungen Stoppuhr

volatile unsigned long Startzeit_Stoppuhr;     //Startzeit Stoppuhr
volatile unsigned long Zeit_Stoppuhr;          //Zeit Stoppuhr

unsigned long Zeiten_Stoppuhr[60];            //Zeiten Stoppuhr (0-59)
unsigned long Hoechstwert_Stoppuhr;           //Höchstwert Stoppuhr
unsigned long Summe_Mittelwert_Stoppuhr;      //Summe Mittelwert Stoppuhr
unsigned long Mittelwert_Stoppuhr;            //Mittelwert Stoppuhr     
unsigned long Kleinstwert_Stoppuhr;           //Kleinstwert Stoppuhr
unsigned long Ref_Wert_Stoppuhr;              //Rererenzwert Stoppuhr
unsigned long Ref_Wert_abweichung_Stoppuhr;   //Rererenzwert abweichung Stoppuhr


/* Geschwindgkeitsanzeige Takt */
bool Startzeit_speichern_Geschw_Takt_1;       //Startzeit speichern Geschwindigkeit Takt 1
bool Startzeit_speichern_Geschw_Takt_2;       //Startzeit speichern Geschwindigkeit Takt 2

bool Messung_aktiv_Geschw_Takt_1;               //Messung aktiv Geschwindigkeit Takt 1
bool Messung_aktiv_Geschw_Takt_2;               //Messung aktiv Geschwindigkeit Takt 2

bool Geschw_Stopp_Takt_1;                     //Geschwindigkeit Stopp Takt 1
bool Geschw_Stopp_Takt_2;                     //Geschwindigkeit Stopp Takt 2

int Listen_Startwert_Gesch_Takt;                //Listen Startwert Geschwindigkeit Takt

volatile unsigned long Startzeit_Geschw_Takt_1;        //Startzeit Geschwindigkeit Takt 1
volatile unsigned long Startzeit_Geschw_Takt_2;        //Startzeit Geschwindigkeit Takt 2

volatile unsigned long Stoppzeit_Geschw_Takt_1;        //Stoppzeit Geschwindigkeit Takt 1
volatile unsigned long Stoppzeit_Geschw_Takt_2;        //Stoppzeit Geschwindigkeit Takt 2

unsigned long Hoechstwert_Geschw_Takt_1;      //Höchstwert Geschwindigkeit Takt 1
unsigned long Hoechstwert_Geschw_Takt_2;      //Höchstwert Geschwindigkeit Takt 2

unsigned long Zeiten_Geschw_Takt_1[60];       //Zeiten Geschwindigkeit Takt 1 (0-59)
unsigned long Zeiten_Geschw_Takt_2[60];       //Zeiten Geschwindigkeit Takt 2 (0-59)


/* Geschwindigkeitsanzeige Sortierer */
bool Messung_Ein_Geschw_Sort;                   //Messung Ein Geschwindigkeit Sortierer          

bool Startzeit_speichern_Geschw_Sort_1;         //Startzeit speichern Geschwindigkeit Sortierer 1
bool Startzeit_speichern_Geschw_Sort_2;         //Startzeit speichern Geschwindigkeit Sortierer 2

bool Messung_aktiv_Geschw_Sort_1;               //Messung aktiv Geschwindigkeit Sortierer 1
bool Messung_aktiv_Geschw_Sort_2;               //Messung aktiv Geschwindigkeit Sortierer 2

bool Zaehler_Geschw_Sort_1;                     //Zähler Geschwindigkeit Sortierer 1
bool Zaehler_Geschw_Sort_2;                     //Zähler Geschwindigkeit Sortierer 2

int Messungen_Geschw_Sort_1;                    //Messungen Geschwindigkeit Sortierer 1
int Messungen_Geschw_Sort_2;                    //Messungen Geschwindigkeit Sortierer 2

int Zeitsaeule_Gesch_Sort_1;                    //Zeitsäule Geschwindigkeit Sortierer 1
int Zeitsaeule_Gesch_Sort_2;                    //Zeitsäule Geschwindigkeit Sortierer 2

int Sensor_Logik_Sort_1;                        //Sensor Logik Geschwindigkeit Sortierer 1
int Sensor_Logik_Sort_2;                        //Sensor Logik Geschwindigkeit Sortierer 2

int Listen_Startwert_Gesch_Sort;                //Listen Startwert Geschwindigkeit Sortierer
      
volatile unsigned long Startzeit_Geschw_Sort_1;          //Startzeit Geschwindigkeit Sortierer 1
volatile unsigned long Startzeit_Geschw_Sort_2;          //Startzeit Geschwindigkeit Sortierer 2

volatile unsigned long Stoppzeit_Geschw_Sort_1;          //Stoppzeit Geschwindigkeit Sortierer 1
volatile unsigned long Stoppzeit_Geschw_Sort_2;          //Stoppzeit Geschwindigkeit Sortierer 2

unsigned long Hoechstwert_Geschw_Sort_1;        //Höchstwert Geschwindigkeit Sortierer 1
unsigned long Hoechstwert_Geschw_Sort_2;        //Höchstwert Geschwindigkeit Sortierer 2

unsigned long Hoechstwert_50_Geschw_Sort_1;        //Höchstwert 50% Geschwindigkeit Sortierer 1
unsigned long Hoechstwert_50_Geschw_Sort_2;        //Höchstwert 50% Geschwindigkeit Sortierer 2

unsigned long Summe_Mittelwert_Geschw_Sort_1;   //Summe Mittelwert Geschwindigkeit Sortierer 1
unsigned long Summe_Mittelwert_Geschw_Sort_2;   //Summe Mittelwert Geschwindigkeit Sortierer 1

unsigned long Mittelwert_Geschw_Sort_1;         //Mittelwert Geschwindigkeit Sortierer 1
unsigned long Mittelwert_Geschw_Sort_2;         //Mittelwert Geschwindigkeit Sortierer 2
       
unsigned long Kleinstwert_Geschw_Sort_1;        //Kleinstwert Geschwindigkeit Sortierer 1
unsigned long Kleinstwert_Geschw_Sort_2;        //Kleinstwert Geschwindigkeit Sortierer 2

unsigned long Wertbegrenzung_Geschw_Sort = 9999;       //Wertbegrenzung Geschwindigkeit Sortierer

volatile unsigned long Zaehlwert_Geschw_Sort_1;          //Zählwert Geschwindigkeit Sortierer 1
volatile unsigned long Zaehlwert_Geschw_Sort_2;          //Zählwert Geschwindigkeit Sortierer 2

unsigned long Zaehlwerte_Geschw_Sort_1[60];     //Zählwerte Geschwindigkeit Sortierer 1 (0-59)
unsigned long Zaehlwerte_Geschw_Sort_2[60];     //Zählwerte Geschwindigkeit Sortierer 2 (0-59)


/* Analogeanzeige */
bool Messung_Ein_Analog;                      //Messung Ein Analog
long Min_mA_Analog;                           //Min Strom Analog
long Max_mA_Analog;                           //Max Strom Analog
long Max_Wert_Analog;                         //Max Wert Analog
long Leistung;                                //Leistung für Analogeanzeige
long Messungen_Zeit_Analog;                    //Messung Zeit Analog

float Aktueller_Wert_Analog;                  //Aktueller Wert Analog
float busVoltage = 0;                         //Spannung INA219
float current = 0;                            //Strom INA219 in mA
float power = 0;                              //Leistung INA219

float offset_current = 0;                     //Offset Strom

word Log_X;
word Log_Y;

int Einheit_Analog;                           //Einheit Analog (0=Nichts Angewählt, 1=Druck 10bar, 2=Druck 20bar, 3=Druck 50bar, 4=Druck 100bar,
                                              //                10=Durchfluss 10000Nl/min, 
                                              //                20=Temperatur 100Grad, 21=Temperatur 150Grad, 22=Temperatur 350Grad) 

int Zeitraster_Messung;                       //Zeitraster Messung
int Anzahl_Messungen;                         //Anzahl Messungen
int Messungen_Analog;                         //Messungen Analog
float Zeit_Messung[10000];                    //Zeit Messung (0-10000)
float Analogwert[10000];                      //Analogwerte (0-10000)


bool Mess_Auswahl_Liste_aufgebaut = false;      //Mess Auswahl Liste aufgebaut
int Mess_Auswahl_Liste = 0;                     //Mess Auswahl Liste
bool Druck_Liste_anzeigen = false;              //Druck Liste anzeigen
bool Durchfluss_Liste_anzeigen = false;         //Durchfluss List anzeigen
bool Temperatur_Liste_anzeigen = false;         //Temperatur Liste anzeigen

/* Analoge Anzeiche Berechnung Funktion */
bool Merker_DE_Sensor_1 = false;                //Merker DE Sensor 1
bool Hoch_Runter_Merker = false;                //Runter Merker
bool Display_Gedrueckt = false;                 //Display Gedrückt Merker

int Aktueller_Zaehlwert = 0;                    //Berechnung Zählwert
int Spitzenwert = 0;                            //Berechunung Spitzenwert
int Gesamt_Spitzenwert = 0;                     //Gesamtspitzenwert
int Anzahl_Durchschnitt_Messung = 0;            //Anzahl Durchschnitt Messung
int Anzahl_Messungen_Impuls = 0;                //Anzahl Impuls Messungen Option
int Zaehlwert_Max = 1000;                       //Zählwert Max Grundeinstellung 1000
int Durchfluss_Menge = 0;                       //Durchfluss Menge
int Zeit_Start_Messung_Minuten = 0;            //Zeit seit Start Messung Minuten
int Zeit_Start_Messung_Sekunden = 0;           //Zeit seit Start Messung Sekunden

float Durchschnitt_Messung = 0;                 //Durchschnitt Messung setzen
float Durchschnitt_Messung_Berechnung = 0;      //Durchschnitt Messung Berechnung
float Zeit_Start_Messung_Sekunden_float = 0;           //Zeit seit Start Messung Sekunden float

long Zeit_Start = 0;                            //Start Zeit
long Hoch_Runter_Zeit = 0;                      //Hoch Runter Zeit

unsigned long Zeit_Start_Impuls = 0;            //Zeit Start Impuls




/* Magnetpolanzeige */
float Magnetfeld_bit = 0.0;                   //Magnetfeldsensor Wert bit
float Offset_Magnetfeld_bit;                  //Umrechnungsfaktor Magnetfeldsensor Wert bit in Gs     
float Magnetfeld_Gs = 0.0;                    //Magnetfeldsensor Wert Gs
float Nullpunkt_Magnetfeld_bit;               //Nullpunkt Magnetfeldsensor bit

/* IO Tester */
bool Buzzer_Ein_IO_Tester;                  //Buzzer Ein IO Tester

/* 6-Achsen Gyro */

bool Buzzer_Ein = false;            //Buzzer Ein 


int16_t Ist_X_Gyro;                 //Ist Wert X Achse Gyro 
int16_t Ist_Y_Gyro;                 //Ist Wert Y Achse Gyro
int16_t Ist_Z_Gyro;                 //Ist Wert Z Achse Gyro
uint16_t Gyro_Fehlerzaehler;        //Gyro Fehlerzähler

float Ist_X_Grad_Gyro;              //Ist Wert X Achse Grad Gyro
float Ist_Y_Grad_Gyro;              //Ist Wert X Achse Grad Gyro
float Ist_Z_Grad_Gyro;              //Ist Wert X Achse Grad Gyro

float Buzzer_Gyro;                        //Buzzer Gyro
float Ist_X_Grad_Gyro_Merker = 1000;      //X Gyro Merker
float Ist_Y_Grad_Gyro_Merker = 1000;      //Y Gyro Merker

long Buzzer_Time;                         //Buzer Zeit setzen

/* Graphik */
bool Graphik_Anzeige = false;             //Graphik Anzeige
bool Graphik_Freigabe = false;            //Graphik Freigabe
bool Graph_Messung_Start = false;         //Graphik Messung Start
bool Einheit_Abfrage = false;             //Graphik Einheit Abfrage
bool Endlos_Ein = false;                  //Graphik Endlos Taster Abfrage
bool Analog_Filter_Ein = false;           //Analog Filter Ein/Aus
bool Graph_Raster = false;                //Graphik Raster Abfrage
bool Graphik_Stopp = false;               //Graphik Stopp
bool Anzahl_Messungen_Merker = false;     //Anzahl Messungen Merker setzen

int Graphik_Text_Anzeige;                 //Graphik Text Anzeige
int Graph_Auswahl_Liste = 0;              //Graphik Auswahl Liste
int x;                                    //x Achse Zeit
int x_Cursor;                             //x Cursor
int y_Cursor;                             //y Cursor
int Ports_Graphik = 0;                    //Ports Graphik

long Graphik_Zeit;                        //Graphik Zeitachse Zeit

float y_Achse_Float; //y Achse als float deklarieren

unsigned long Vorherige_Zeit_Graphik = 0; //Vorherige Graphik Zeit
unsigned long Vorherige_Zeit = 0;         //Vorherige Graphik Zeit

/*Speed Sensor */
bool Speed_Messung_Ein = false;           //Speed Messung Ein
bool Speed_Merker = false;                //Speed Merker

int Frequenz_Anpassung = 0;               //Frequenz Anpassung

float Speed_Inputs = 0;                   //Speed Sensor Inputs
float Speed = 0;                          //Speed
float Ref_Wert_Speed = 0;                 //Referenz Wert Speed Sensor

unsigned long Speed_Zeit = 0;             //Speed Zeit

/* MP3 Player */
bool MP3_Ein = false;                     //MP3 Ein

byte MP3_Lautstaerke;                     //MP3 Player Lautstärke (0-30)

int Equalizer = 0;                        //Equalizer
int Playlist = 0;                         //Playlist
int Lied_Nr = 1;                          //Lied Nummer

/* Analogfilter Analogeanzeige */
ExponentialFilter<float> Filter_Wert_Analog(10, 0);          //Analogfilter (0-100) stärke des Filters 0=stark, 100=schwach 

/* Analogfilter Neigungssensor */
ExponentialFilter<float> Ist_X_Filter_Gyro(40, 0);          //Analogfilter (0-100) stärke des Filters 0=stark, 100=schwach                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        0, 0);          //Analogfilter 0 - 100 stärke des Filters 0 stark / 100 schwach
ExponentialFilter<float> Ist_Y_Filter_Gyro(40, 0);          //Analogfilter (0-100) stärke des Filters 0=stark, 100=schwach
ExponentialFilter<float> Ist_Z_Filter_Gyro(40, 0);          //Analogfilter (0-100) stärke des Filters 0=stark, 100=schwach

/********************************************************************************************************************/

/* Setup 
   Setup wird nur einmal beim aufstarten ausgeführt! */
   
void setup()              //Funktion Setup
{
  /* Ports */
  pinMode(DA_Buzzer, OUTPUT);               //Digital Ausgang Pin 2 Buzzer zuordnen
  pinMode(DA_Hauptschalter_LED, OUTPUT);    //Digital Ausgang Pin 3 Hauptschalter LED zuordnen
  pinMode(DA_Display_Reset, OUTPUT);        //Digital Ausgang Pin 4 Display Reset zuordnen
  pinMode(DA_Versorgung_24VDC, OUTPUT);     //Digital Ausgang Pin 5 Mosfet Versorgung 24VDC zuordnen  
  pinMode(DE_Hallsensor, INPUT);            //Digital Eingang Pin 7 Hallsensor zuordnen 
//  pinMode(AD_Akkuladestand, INPUT);         //Analoger Eingang PIN A0 Akkuladestand Lichtsensor zuordnen 
//  pinMode(AD_Magnetfeldsensor, INPUT);      //Analoger Eingang PIN A1 Magnetfeldsensor zuordnen

  /* Interrupt
     RISING Interrupt wird getriggert, wenn der Pin von LOW auf HIGH wechselt. */
  pinMode(DE_Sensor_1, INPUT);              //Digital Eingang Pin 8 Sensor 1 zuordnen
  pinMode(DE_Sensor_2, INPUT);              //Digital Eingang Pin 9 Sensor 2 zuordnen

  /* INA219 Stromsensor */
  Serial.begin(115200);                   //Serial Monitor Start
  sensor219.begin();                      //Start INA219 Stromsensor

  /* Serieller Monitor */
  SerialUSB.begin(9600);                   //Start des seriellen Monitors
  
  /* Display */
  DisplaySerial.begin(115200);            //115200 Geschwindigkeit Serielle Schnittstelle
  Display.TimeLimit4D = 5000;             //Timout 5000ms
  Display.Callback4D = mycallback;        //Fehler Auswertung Serielle Schnittstelle

  /* Display Reset */
  digitalWrite(DA_Display_Reset, HIGH);   //Digital Ausgang Display Reset setzen
  delay(100);                             //Verzögerung 100ms
  digitalWrite(DA_Display_Reset, LOW);    //Digital Ausgang Display Reset zurücksetzen
  delay(5000);                            //Verzögerung 5000ms

  /* Echtzeituhr DS1307 */
  Uhr.begin();

  /* 6-Achsen Gyro */
  Gyro.beginCore();     //Gyro aktivieren
  
  /* Gyro Parameter setzen */
  uint8_t dataToWrite = 0;    //Temporäre Variable

  dataToWrite = 0;      //Neustart
  dataToWrite |= LSM6DS3_ACC_GYRO_BW_XL_100Hz;
  dataToWrite |= LSM6DS3_ACC_GYRO_FS_XL_16g; 
  dataToWrite |= LSM6DS3_ACC_GYRO_ODR_XL_104Hz;

  //Now, write the patched together data
  Gyro_Fehlerzaehler += Gyro.writeRegister(LSM6DS3_ACC_GYRO_CTRL1_XL, dataToWrite);

  //Set the ODR bit
  Gyro_Fehlerzaehler += Gyro.readRegister(&dataToWrite, LSM6DS3_ACC_GYRO_CTRL4_C);
  dataToWrite &= ~((uint8_t)LSM6DS3_ACC_GYRO_BW_SCAL_ODR_ENABLED);

  /* MP3 Player */
  Serial1.begin(9600);                     //Serielle Schnittstelle 1 öffnen

//  SerialUSB.println();
//  SerialUSB.println(F("DFRobot DFPlayer Mini Demo"));
//  SerialUSB.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  //Use softwareSerial to communicate with mp3.
  if (!DFMP3_Player.begin(Serial1)) 
  {  
    SerialUSB.println(F("Unable to begin:"));
    SerialUSB.println(F("1.Please recheck the connection!"));
    SerialUSB.println(F("2.Please insert the SD card!"));
    while(true);
  } 
    
/********************************************************************************************************************/

  /* Einschaltbildschirm */ 
  
  /* Buzzer */
  Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

  /* Hauptschalter LED */ 
  digitalWrite(DA_Hauptschalter_LED, HIGH);         //Digital Ausgang Hauptschalter LED setzen
  
  /* Text Format */ 
  Display.gfx_ScreenMode(LANDSCAPE);      //Display quer ausrichtung
  Display.gfx_BGcolour(BLACK);            //Hintergrundfarbe bestimmen
  Display.gfx_BevelShadow(2);             //Schatten Tasten
  Display.touch_Set(TOUCH_ENABLE);        //Freigabe Touch Screen

  /* Version anzeigen */
  Display.txt_Height(1);                    //Texthöhe
  Display.txt_Set(BLACK, WHITE);            //Textfarbe
  Display.gfx_MoveTo(160, 410);             //Text Position (x,y)
  Display.print("PAM3000-Sensor-Visualizer Version 003 / 18.08.2021 / MR");           //Text anzeigen

  /* Pamasol anzeigen */
  Display.txt_Height(10);                   //Texthöhe
  Display.txt_Width(9);                     //Textweite        
  Display.gfx_MoveTo(40, 100);              //Text Position (x,y)
  Display.print("pamasol");                 //Text anzeigen

  Display.txt_Height(5);                    //Texthöhe
  Display.txt_Width(4);                     //Textweite       
  Display.gfx_MoveTo(40, 250);              //Text Position (x,y)
  Display.print("Swiss Aerosol Solutions"); //Text anzeigen

  delay(3000);                              //Verzögerung 3000ms
  Display.gfx_Cls();                        //Display löschen

/********************************************************************************************************************/

  /* SD Karte */
  /* Überwachung keine Karte gesteckt */
  if (!SD.begin(10))      //Überwachung keine Karte gesteckt
  {
    Display.gfx_Cls();                              //Display löschen
    Display.txt_Height(2);                          //Texthöhe
    Display.txt_Width(2);                           //Textweite
    Display.txt_Set(TEXT_COLOUR, RED);              //Textfarbe
    Display.gfx_MoveTo(100, 10);                    //Text Position (x,y)
    Display.println("Bitte SD Karte einschieben!");   //Text anzeigen
    Buzzer(1000);                                   //Aufruf Funktion Buzzer(int Buzzer_Zeit)
    delay(3000);                                    //Verzögerung 3000ms
  }

  /* Daten lesen */  
  if (SD.begin(10))      //Überwachung Karte gesteckt
  {   
    /* File nicht vorhanden */
    char Filenamen[] = "DATEN.TXT";       //SD Karte Filenamen  
    if (!SD.exists(Filenamen))            //Überwachung File vorhanden
    {  
      Display.gfx_Cls();                                      //Display löschen
      Display.txt_Height(2);                                  //Texthöhe
      Display.txt_Width(2);                                   //Textweite
      Display.txt_Set(TEXT_COLOUR, WHITE);                    //Textfarbe
      Display.gfx_MoveTo(200, 35);                            //Text Position (x,y)
      Display.println("Datei fehlt... ");                     //Text anzeigen 
      Display.println("neue wird erstellt!");                 //Text anzeigen 
      delay(3000);                                            //Verzögerung 1000ms 

      /* Neues File erstellen */  
      Daten_File = SD.open(Filenamen, FILE_WRITE);    //Neues File erstellen
      Daten_File.close();       //File schliessen
    }   
        
    Display.gfx_Cls();                                      //Display löschen
    Display.txt_Height(3);                                  //Texthöhe
    Display.txt_Width(3);                                   //Textweite
    Display.txt_Set(TEXT_COLOUR, WHITE);                    //Textfarbe
    Display.gfx_MoveTo(50, 185);                            //Text Position (x,y)
    Display.println("Daten lesen...!");   //Text anzeigen 
    delay(1000);                                            //Verzögerung 1000ms 

    /* File öffnen */
    Display.gfx_Cls();                                      //Display löschen
    Display.txt_Height(2);                                  //Texthöhe
    Display.txt_Width(2);                                   //Textweite
    Display.txt_Set(TEXT_COLOUR, WHITE);                    //Textfarbe
    Display.gfx_MoveTo(30, 10);                             //Text Position (x,y)
   
    char str[210];
    int i = 0;
//    char Filenamen[] = "DATEN.TXT";       //SD Karte Filenamen            
    Daten_File = SD.open(Filenamen);      //File öffnen
    if (Daten_File)                       //Überwachung File geöffnet
    {
      /* File lesen */
      while (Daten_File.available())      //Überwachung File verfügbar
      {                             
        str[i] = Daten_File.read();
        Display.print(str[i]);   //Wert anzeigen 
        i++;
        delay(100);                                            //Verzögerung 1000ms               
      }            
      Daten_File.close();       //File schliessen
      
      Display.gfx_Cls();                                      //Display löschen
      Display.txt_Height(3);                                  //Texthöhe
      Display.txt_Width(3);                                   //Textweite
      Display.txt_Set(TEXT_COLOUR, WHITE);                    //Textfarbe
      Display.gfx_MoveTo(50, 185);                            //Text Position (x,y)
      Display.println("Daten erfolgreich gelesen!");          //Text anzeigen 
      delay(3000);                                            //Verzögerung 3000ms 
    }      
    else                        //File lese Fehler
    {
      Display.gfx_Cls();                                    //Display löschen
      Display.txt_Height(2);                                //Texthöhe
      Display.txt_Width(2);                                 //Textweite
      Display.txt_Set(TEXT_COLOUR, RED);                    //Textfarbe
      Display.gfx_MoveTo(200, 35);                          //Text Position (x,y)
      Display.println("Daten konnten nicht gelesen");       //Text anzeigen 
      Display.println("werden!");                           //Text anzeigen
      Buzzer(1000);                                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
      delay(3000);                                          //Verzögerung 3000ms
    }  
  }

/********************************************************************************************************************/
    
  /* Daten schreiben 
     Es kann jeweils nur immer ein File gleichzeitige geöffnet sein!
     Filenamen maximum 8 Zeichen!      
  */

/********************************************************************************************************************/
  
  /* File generieren */
  SD.mkdir("Settings");       //File öffnen Name darf 8 Zeichen nicht überschreiten
  SD.mkdir("Graphik");        //File öffnen Name darf 8 Zeichen nicht überschreiten
  
/********************************************************************************************************************/

  /*Einstellungen SD */
  buzzer = SD.open("Settings/buzzer.txt", FILE_READ);                 //datalog Datei auf SD Karte öffnen
  Buzzer_String = "";                                                 //Buzzer Laustärke String zurücksetzen
  Buzzer_Lautstaerke_String = "";                                     //Buzzer Laustärke String zurücksetzen
  Buzzer_Ein_Aus_String = "";                                         //Buzzer Ein/Aus zurücksetzen
 
  while (buzzer.available())                                          //Solange das File lesbarer Text beinhaltet
  {
    Buzzer_String += (char)buzzer.read();                             //Buchstaben auslesen und am String anhängen
    if (Buzzer_String == "Buzzer_Ein/Aus:") 
    {
      Buzzer_Ein_Aus_String = buzzer.readStringUntil('\n');           //String lesen bis Abstand
      Buzzer_Einstellungen = Buzzer_Ein_Aus_String.toInt();           //String auf Variable Schreiben
      Buzzer_String = "";                                             //String zurücksetzen
      Buzzer_Ein_Aus_String = "";
    }
    if (Buzzer_String == "Buzzer_Lautstaerke:") 
    {   
      Buzzer_Lautstaerke_String = buzzer.readStringUntil('\n');       //String lesen bis Abstand
      Buzzer_Lautstaerke = Buzzer_Lautstaerke_String.toInt();         //String auf Variable Schreiben
      Buzzer_String = "";                                             //String zurücksetzen
      Buzzer_Lautstaerke_String = "";
    }
  }

/********************************************************************************************************************/
  
//    Filenamen = "DATEN.TXT";        //SD Karte Filenamen
      
//  Daten_File = SD.open(Filenamen, FILE_WRITE);     //File öffnen

  /* File beschreiben */
/*  if (Daten_File)     //Überwachung File geöffnet, bereit zum schreiben
  {
    Daten_File.println("PAM3000 Data");      //Text schreiben
    Daten_File.println(Nullpunkt_Magnetfeld_bit);    //Wert schreiben

    for (int i = 0; i <= 19; i++)
    {
      Daten_File.println(Zaehlwerte_Geschw_Sort_1[i]);
      Daten_File.println(Zaehlwerte_Geschw_Sort_2[i]);
    }
    
    Daten_File.close();       //File schliessen
  } 
  else //File schreibe Fehler
  {
    Display.gfx_Cls();                                          //Display löschen
    Display.txt_Height(2);                                      //Texthöhe
    Display.txt_Width(2);                                       //Textweite
    Display.txt_Set(TEXT_COLOUR, RED);                          //Textfarbe
    Display.gfx_MoveTo(200, 35);                                //Text Position (x,y)
    Display.println("Daten konnten nicht geschrieben");         //Text anzeigen
    Display.println("werden!");                                 //Text anzeigen      
    Buzzer(1000);                                               //Aufruf Funktion Buzzer(int Buzzer_Zeit)
    delay(3000);                                                //Verzögerung 3000ms
  }
*/

/********************************************************************************************************************/

  /* Datei löschen */
//  char Filenamen[] = "DATEN.TXT";         //SD Karte Filenamen    
//  SD.remove("DATEN.TXT");                 //File löschen

/********************************************************************************************************************/

  /* Start Variablen */ 
  Startzeit_speichern_D_Stoppuhr_1 = true;              //Startzeit speichern Doppel-Stoppuhr 1 setzen
  Startzeit_speichern_D_Stoppuhr_2 = true;              //Startzeit speichern Doppel-Stoppuhr 2 setzen

  Kleinstwert_D_Stoppuhr_1 = 9999;                      //Kleinstwert Doppel-Stoppuhr 1 auf maximumwert setzen
  Kleinstwert_D_Stoppuhr_2 = 9999;                      //Kleinstwert Doppel-Stoppuhr 2 auf maximumwert setzen
  
  Startzeit_speichern_Stoppuhr = true;                  //Startzeit speichern Stoppuhr setzen
  Kleinstwert_Stoppuhr = 9999;                          //Kleinstwert Stoppuhr auf maximumwert setzen
      
  Startzeit_speichern_Geschw_Takt_1 = true;             //Startzeit speichern Geschwindigkeit Takt 1 setzen
  Startzeit_speichern_Geschw_Takt_2 = true;             //Startzeit speichern Geschwindigkeit Takt 2 setzen
  Startzeit_speichern_Geschw_Sort_1 = true;             //Startzeit speichern Geschwindigkeit Sortierer 1 setzen
  Startzeit_speichern_Geschw_Sort_2 = true;             //Startzeit speichern Geschwindigkeit Sortierer 2 setzen

  Zaehler_Geschw_Sort_1 = true;                         //Zählwert Geschwindigkeit Sortierer 1 
  Zaehler_Geschw_Sort_2 = true;                         //Zählwert Geschwindigkeit Sortierer 2
   
  Geschw_Stopp_Takt_1 = true;                           //Geschwingigkeit_Stopp Takt 1 setzen
  Geschw_Stopp_Takt_2 = true;                           //Geschwingigkeit_Stopp Takt 2 setzen
    
  Stoppzeit_Geschw_Sort_1 = 0;                        //Stoppzeit Geschwindigkeit Sortierer 1 zurücksetzen
  Stoppzeit_Geschw_Sort_2 = 0;                        //Stoppzeit Geschwindigkeit Sortierer 2 zurücksetzen

  Kleinstwert_Geschw_Sort_1 = 9999;                   //Kleinstwert Geschwindigkeit Sortierer 1 auf maximumwert setzen
  Kleinstwert_Geschw_Sort_2 = 9999;                   //Kleinstwert Geschwindigkeit Sortierer 2 auf maximumwert setzen

  Sensor_Logik_Sort_1 = 1;                            //Sensor Logik Geschwindigkeit Sortierer 1 (0= - o -, 1= = o)
  Sensor_Logik_Sort_2 = 1;                            //Sensor Logik Geschwindigkeit Sortierer 2 (0= - o -, 1= = o)

  Leistung = 0;                                         //Leistung für Analogeanzeige auf 0 setzen

  MP3_Lautstaerke = 10;                               //MP3 Player Lautstärke setzen
  DFMP3_Player.volume(MP3_Lautstaerke);               //MP3 Player Lautstärke (0-30)

  /* Startmenü anwahl */
  Menue_angewaehlt = 0;     //Hauptmenü anwählen  
}

/********************************************************************************************************************/

void loop()         //Funktion loop
{

/********************************************************************************************************************/

  /* Menü anwahl */
  switch (Menue_angewaehlt)
  {

/********************************************************************************************************************/
     
     /* 0.Hauptmenü 1 */
    case 0:   
      Hauptmenue(true, true);               //Aufruf Funktion Hauptmenü 1 (bool Bildaufbau, bool Werte_Reset)     
      break;

/********************************************************************************************************************/

    /* 1.Doppel-Stoppuhr */
    case 1:
      D_Stoppuhr(true, true);                 //Aufruf Funktion Doppel-Stoppuhr (bool Bildaufbau, bool Werte_Reset)
      break;

/********************************************************************************************************************/

    /* 2.Geschwindigkeitsanzeige Takt */
    case 2:
      Geschw_Takt(true, true);              //Aufruf Funktion Geschwindigkeitsanzeige Takt (bool Bildaufbau, bool Werte_Reset)
      break;

/********************************************************************************************************************/

    /* 3.Analogeanzeige */
    case 3:
      Analogeanzeige(true, true);           //Aufruf Funktion Analogeanzeige (bool Bildaufbau, bool Werte_Reset)
      break;

/********************************************************************************************************************/

    /* 4.Magnetpolanzeige */
    case 4:
      Magnetpolanzeige(true, true);         //Aufruf Funktion Magnetpolanzeige (bool Bildaufbau, bool Werte_Reset)
      break;

/********************************************************************************************************************/

    /* 5.Einstellungen */
    case 5:
      Einstellungen(true, true);            //Aufruf Funktion Einstellungen (bool Bildaufbau, bool Werte_Reset)
      break;

/********************************************************************************************************************/

    /* 6.IO Tester */
    case 6:
      IO_Tester(true, true);            //Aufruf Funktion IO Tester (bool Bildaufbau, bool Werte_Reset)
      break;

/********************************************************************************************************************/

    /* 7.Info */
    case 7:
      Info();            //Aufruf Funktion Info
      break;

/********************************************************************************************************************/

    /* 8.Speed Sensor */
    case 8:
      Speed_Sensor(true, true);         //Aufruf Funktion Speed Sensor (bool Bildaufbau, bool Werte_Reset)
      break;

/********************************************************************************************************************/

    /* 9.Distanz Sensor */
    case 9:
      Distanz_Sensor(true, true);         //Aufruf Funktion Distanz Sensor (bool Bildaufbau, bool Werte_Reset)
      break;
            
/********************************************************************************************************************/

    /* 10.Geschwindigkeitsanzeige Sortierer */
    case 10:
      Geschwindigkeitsanzeige_Sort(true, true);         //Aufruf Funktion Geschwindigkeitsanzeige Sortierer (bool Bildaufbau, bool Werte_Reset)
      break;

/********************************************************************************************************************/

    /* 13.Doppel-Stoppuhr Liste */
    case 13:
      D_Stoppuhr_Liste(true, true);                 //Aufruf Funktion Doppel-Stoppuhr Liste (bool Bildaufbau, bool Werte_Reset)
      break; 

/********************************************************************************************************************/

    /* 14.Geschwindigkeitsanzeige Takt Liste */
    case 14:
      Geschw_Takt_Liste(true, true);                   //Aufruf Funktion Geschwindigkeitsanzeige Takt Liste (bool Bildaufbau, bool Werte_Reset)
      break;

/********************************************************************************************************************/

    /* 15.Geschwindigkeitsanzeige Sortierer Liste */
    case 15:
      Geschw_Sort_Liste(true, true);            //Aufruf Funktion Geschwindigkeitsanzeige Sortierer Liste (bool Bildaufbau, bool Werte_Reset)
      break;    

/********************************************************************************************************************/

    /* 16.Stoppuhr */
    case 16:
      Stoppuhr(true, true);                 //Aufruf Funktion Stoppuhr (bool Bildaufbau, bool Werte_Reset)
      break;

/********************************************************************************************************************/

    /* 17.Stoppuhr Liste */
    case 17:
      Stoppuhr_Liste(true, true);                 //Aufruf Funktion Stoppuhr Liste (bool Bildaufbau, bool Werte_Reset)
      break; 

/********************************************************************************************************************/

    /* 18.Graphik Analogeanzeige */
    case 18:
      Graphik(true, true);                        //Aufruf Funktion Graphik (bool Bildaufbau, bool Werte_Reset)
      break; 

/********************************************************************************************************************/

    /* 19.Berechnen Analogeanzeige */
    case 19:
      Berechnung(true, true);                        //Aufruf Funktion Graphik (bool Bildaufbau, bool Werte_Reset)
      break; 

/********************************************************************************************************************/

    /* 50.Hauptmenü 2 */
    case 50:
      Hauptmenue2(true, true);                    //Aufruf Funktion Hauptmenü 2 (bool Bildaufbau, bool Werte_Reset)
      break; 

/********************************************************************************************************************/

    /* 51.Neigungs Sensor */
    case 51:
      Neigungs_Sensor(true, true);                 //Aufruf Funktion Neigungs Sensor (bool Bildaufbau, bool Werte_Reset)
      break; 

/********************************************************************************************************************/

    /* 52.MP3 Player */
    case 52:
      MP3_Player(true, true);                 //Aufruf Funktion MP3 Player (bool Bildaufbau, bool Werte_Reset)
      break; 

/********************************************************************************************************************/
      
  }   //loop Ende

/********************************************************************************************************************/

}

/********************************************************************************************************************/
