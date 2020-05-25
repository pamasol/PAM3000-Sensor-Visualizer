/*--------------------------------------------------------------------------------------------------------------------
  //******************************************************************************************************************

    Programm:       PAM3000_Sensor_Visualizer_001
    Prozessor:      Arduino Due
    Clock:          16MHz

    Version:        001
    Datum:          01.05.2020

    Programmierer:  D.Bernhard, J.Glaus
   
  //******************************************************************************************************************

     Hochladen: - Board:      "Arduino Due"

                - Port:       "COM03(Arduino Due)"
                - Programmer: "USBasp"

  //******************************************************************************************************************

  Info: - Display Auflösung 800x480pixel

  Struktur:
  
  0. Hauptmenü
  1. Stoppuhr
  2. Geschwindigkeitsanzeige
  3. Analogeanzeige
  4. Magnetpolanzeige
  5. Einstellungen
  
*/

//********************************************************************************************************************

#define DisplaySerial Serial                  //define für Hallsensor
#define HALL_SENSOR 7                         //define für Hallsensor

#include <Diablo_Const4D.h>                   //include für Display
#include <Diablo_Serial_4DLib.h>              //include für Display

#include <Wire.h>                             //include für INA219 Analoge Anzeige
#include <Adafruit_INA219.h>                  //include für INA219 Analoge Anzeige 

Adafruit_INA219 sensor219;                    //Declare für INA219

Diablo_Serial_4DLib Display(&DisplaySerial);  //Serielle Kommunikation mit Display

//********************************************************************************************************************

int interruptPin = 8;               //Pin 8 für Interrupt
int interruptPin2 = 9;              //Pin 9 für Interrupt

byte Status_Display;                //Status Display

word Kontrast_Display = 10;         //Kontrast Display(1-15)

int Textbreite = 2;                 //Textbreite
int Textrahmen = 3;                 //Textrahmen

word Schrifttyp = FONT1;            //Schrifttyp (FONT1, FONT2, FONT3)
word Texthintergrund = GREEN;       //Texthintergrundfarbe (Menüstruktur, Reset)
word Textfarbe = WHITE;             //Textfarbe (Menüstruktur, Reset)
word Texthintergrund_2 = GREEN;     //Texthintergrundfarbe 2 (Menüstruktur, Reset)
word Textfarbe_2 = BLACK;           //Textfarbe 2 (Menüstruktur, Reset)

word Status_Taste;                  //Status Touch Taste
word X_Pos;                         //X Positionswert Touch
word Y_Pos;                         //Y Positionswert Touch

int Menue_angewaehlt;               //Menü angewählt

bool Bild_aufgebaut[16];            //Bildschirm aufgebaut (0-15 Bilder)

bool Start_speichern[2];            //Zeiten speichern 
bool Zeiten_speichern[2];           //Zeiten speichern 
bool Zeit_speichern;                //Zeiten speichern 

int Stunden;                        //Stunden Anzeige 1
int Minuten;                        //Minuten Anzeige 1
int Sekunden;                       //Sekunden Anzeige 1
int Millisekunden;                  //Millisekunden Anzeige 1

bool Displaystopp;                  //Displaystopp

bool Reset1;                        //Reset Stoppuhr
bool Reset2;                        //Reset Stoppuhr 2

bool Stoppuhrinterrupt;             //Stoppuhr Interrupt
bool Stoppuhrinterrupt2;            //Stoppuhr Interrupt 2

bool Geschwingigkeitinterrupt;      //Geschwindigkeitsanzeige Interrupt
bool Geschwingigkeitinterrupt2;     //Geschwindigkeitsanzeige Interrupt 2

bool Start_speichern2[2];           //Zeiten speichern 2
bool Zeiten_speichern2[2];          //Zeiten speichern 2
bool Zeit_speichern2;               //Zeiten speichern 2

int Stunden2;                       //Stunden Anzeige 2
int Minuten2;                       //Minuten Anzeige 2
int Sekunden2;                      //Sekunden Anzeige 2
int Millisekunden2;                 //Millisekunden Anzeige 2

unsigned long Start_Zeit_Stoppuhr[2];         //Start Zeit Stoppuhr 1
unsigned long Stop_Zeit_Stoppuhr[2];          //Stop Zeit Stoppuhr 1
unsigned long Zeiten_Stoppuhr_1[9];           //Zeiten Stoppuhr 1 (0-9)

unsigned long Start_Zeit;                     //Start Stoppuhr 1
unsigned long Stopp_Zeit;                     //Stopp Stoppuhr 1

unsigned long Start_Zeit_Stoppuhr2[2];        //Start Zeit Stoppuhr 2
unsigned long Stop_Zeit_Stoppuhr2[2];         //Stop Zeit Stoppuhr 2
unsigned long Zeiten_Stoppuhr_2[9];           //Zeiten Stoppuhr 2 (0-9)

unsigned long Start_Zeit2;                    //Start Stoppuhr 2
unsigned long Stopp_Zeit2;                    //Stopp Stoppuhr 2

float Start_Zeit_Geschwindigkeit;             //Start Zeit für Geschwindigkeitsanzeige
unsigned long Stopp_Zeit_Geschwindigkeit;     //Stopp Zeit für Geschwindigkeitsanzeige
unsigned long Zeiten_Geschwindigkeit_1[9];    //Geschwindigeitswert Speichern
unsigned long Hoechstwert;                    //Hoechstwert von Geschwindigkeitsanzeige

float Start_Zeit_Geschwindigkeit2;            //Start Zeit für Geschwindigkeitsanzeige 2
unsigned long Stopp_Zeit_Geschwindigkeit2;    //Stopp Zeit für Geschwindigkeitsanzeige 2
unsigned long Zeiten_Geschwindigkeit_2[9];    //Geschwindigeitswert 2 Speichern
unsigned long Hoechstwert2;                   //Hoechstwert von Geschwindigkeitsanzeige 2

unsigned long Start_Zeit3;                    //Start Geschwindikeitsanzeige
unsigned long Stopp_Zeit3;                    //Stopp Geschwindikeitsanzeige

unsigned long Start_Zeit4;                    //Start Geschwindikeitsanzeige 2
unsigned long Stopp_Zeit4;                    //Stopp Geschwindikeitsanzeige 2

bool Zeit_speichern3;                         //Zeiten speichern Geschwindigkeitsanzeige
bool Zeit_speichern4;                         //Zeiten speichern Geschwindigkeitsanzeige

bool Geschwindigkeit_Stopp;                   //Stoppzeit Geschwindigkeitsanzeige
bool Geschwindigkeit_Stopp2;                  //Stoppzeit Geschwindigkeitsanzeige 2


bool Geschwingigkeitinterrupt_Durchschnitt;   //Durchschnitt Geschwindigkeitsanzeige
bool Geschwingigkeitinterrupt_Durchschnitt2;  //Durchschnitt Geschwindigkeitsanzeige 2

bool Zeit_speichern5;                         //Zeiten Speichern5

bool Geschwingigkeitinterrupt3;               //Geschwindigkeitsanzeige Durchschnitt Interrupt
bool Geschwingigkeitinterrupt4;               //Geschwindigkeitsanzeige Durchschnitt Interrupt 2

unsigned long Stopp_Zeit_Geschwindigkeit3;    //Stopp Zeit Geschwindigkeitsanzeige
unsigned long Stopp_Zeit_Geschwindigkeit4;    //Stopp Zeit Geschwindigkeitsanzeige2
unsigned long Start_Zeit_Geschwindigkeit3;    //Start Zeit Geschwindigkeitsanzeige
unsigned long Start_Zeit_Geschwindigkeit4;    //Start Zeit Geschwindigkeitsanzeige2

unsigned long Hoechstwert3 = 0;               //Höchstwert Geschwindigkeitsanzeige
unsigned long Hoechstwert4 = 0;               //Höchstwert Geschwindigkeitsanzeige

bool Reset3;                                  //Reset3

unsigned long Zeiten_Geschwindigkeit_3[9];    //Zeiten Geschwindigkeit für Durchschnitt
long Durchschnittanzahl;                      //Durchschnittanzahl
bool Interrupt_Durchschnitt;                  //Interrupt Durchschnitt

long Leistung;                                //Leistung für Analogeanzeige

bool Reset4;                                  //Reset4

bool Zeit_speichern6;                         //Zeitspeichern6
unsigned long Zeiten_Geschwindigkeit_4[9];    //Zeiten Geschwindigkeit für Durchschnitt2
long Durchschnittanzahl2;                     //Durchschnittanzahl2
bool Interrupt_Durchschnitt2;                 //Interrupt Durchschnitt2

float DruckSensor;                            //DruckSensor wert für Analogeanzeige
long Max_Bar;                                 //Max Bar von DruckSensor
long Max_mA;                                  //Max Strom von DruckSensor
long Min_mA;                                  //Min Strom von DruckSensor

float busVoltage = 0;                         //Spannung INA219
float current = 0;                            //Strom INA219 in mA
float power = 0;                              //Leistung INA219

//********************************************************************************************************************

void setup()
{
  
  pinMode(interruptPin, INPUT);                          // Interrupt Pin 8 Input
  attachInterrupt(interruptPin, Interrupt, RISING);      // Interrupt Void Interrupt

  pinMode(interruptPin2, INPUT);                         // Interrupt Pin 9 Input
  attachInterrupt(interruptPin2, Interrupt2, RISING);    // Interrupt Void Interrupt2

  pinMode(2, OUTPUT);                                    // Pin für Buzzer

  DisplaySerial.begin(9600);              //9600 Geschwindigkeit Serielle Schnittstelle
  Display.TimeLimit4D = 5000;             //Timout 5000ms
  Display.Callback4D = mycallback;        //Fehler Auswertung

  pinMode(4, OUTPUT);                     //D4 auf Output
  digitalWrite(4, HIGH);                  //Reset den Display via D4
  delay(100);                             //Verzögerung 100ms
  digitalWrite(4, LOW);                   //unReset den Display via D4

  delay(5000);                            //Verzögerung 5000ms

  Display.gfx_ScreenMode(LANDSCAPE);      //Display quer ausrichtung
  Display.gfx_BGcolour(BLACK);            //Hintergrundfarbe bestimmen
  Display.gfx_BevelShadow(2);             //Schatten Tasten
  Display.touch_Set(TOUCH_ENABLE);        //Freigabe Touch Screen

  Display.txt_Height(1);                                //Texthöhe
  Display.gfx_MoveTo(160, 350);                         //Text Position x,y
  Display.print("PAM3000-Sensor-Visualizer");           //Text Anzeigen
  Display.print(" Version 001 / 05.12.2019 / MR");      //Text Anzeigen

  delay(3000);                                          //Verzögerung 3000ms

  Display.gfx_Cls();                                    //Display löschen

  Zeit_speichern = true;                                //Zeiten speichern
  Zeit_speichern2 = true;                               //Zeiten speichern 2 
  Zeit_speichern3 = true;                               //Zeiten speichern 3
  Zeit_speichern4 = true;                               //Zeiten speichern 4
  Zeit_speichern5 = true;                               //Zeiten speichern 5
  Zeit_speichern6 = true;                               //Zeiten speichern 6
  
  Reset1 = true;                                        //Reset
  Reset2 = true;                                        //Reset2
  Reset3 = true;                                        //Reset3
  Reset4 = true;                                        //Reset4
  
  Stoppuhrinterrupt = false;                            //Stoppuhrinterrupt auf false setzen
  Stoppuhrinterrupt2 = false;                           //Stoppuhrinterrupt2 auf false setzen
  Geschwingigkeitinterrupt = false;                     //Geschwingigkeitinterrupt auf false setzen
  Geschwingigkeitinterrupt2 = false;                    //Geschwingigkeitinterrupt2 auf false setzen
  Geschwingigkeitinterrupt3 = false;                    //Geschwingigkeitinterrupt3 auf false setzen
  Geschwingigkeitinterrupt4 = false;                    //Geschwingigkeitinterrupt4 auf false setzen
  
  Geschwindigkeit_Stopp = true;                         //Geschwingigkeit_Stopp setzen
  
  Interrupt_Durchschnitt = true;                        //Interrupt_Durchschnitt setzen
  Interrupt_Durchschnitt2 = true;                       //Interrupt_Durchschnitt2 setzen

  Stopp_Zeit_Geschwindigkeit3 = 0;                      //Stopp_Zeit_Geschwindigkeit3 auf 0 setzen
  Stopp_Zeit_Geschwindigkeit4 = 0;                      //Stopp_Zeit_Geschwindigkeit4 auf 0 setzen

  Leistung = 0;                                         //Leistung für Analogeanzeige auf 0 setzen

  pinMode(HALL_SENSOR, INPUT);                          //Pin Hall_Sensor auf Input setzen

  Serial.begin(9600);                                   //Serial Monitor Start
  sensor219.begin();                                    //INA219 Start
}

//********************************************************************************************************************

void loop()
{

  Display.gfx_Contrast(Kontrast_Display);       //Kontrast Display

  switch (Menue_angewaehlt)
  {
 
//Hauptmenue
    
    case 0:
    
    Hauptmenue();               //Aufruf Funktion Hauptmenü
      
    break;

//Stoppuhr

    case 1:

    Stoppuhr();                 //Aufruf Funktion Stoppuhr

    break;

//Geschwindigkeitsanzeige

    case 2:

    Geschwindigkeitsanzeige();  //Aufruf Funktion Geschwindigkeitsanzeige

    break;

//Analogeanzeige

    case 3:

    Analogeanzeige();           //Aufruf Funktion Analogeanzeige

    break;

//Magnetpolanzeige

    case 4:

    Magnetpolanzeige();         //Aufruf Funktion Magnetpolanzeige

    break;

//Einstellungen

    case 5:

    Einstellungen();            //Aufruf Funktion Einstellungen

    break;

//Stoppuhr Interrupt

    case 6:

      if (Displaystopp == true) //Überwachung Bildschirm aufgebaut
      {
        
      Start_Zeit = 0;           //Start Zeit Reset
      Stopp_Zeit = 0;           //Stopp Zeit Reset

     
        if (Zeit_speichern == true)
        {
          
        Display.gfx_CircleFilled(40, 120, 20, GREEN); //Status Anzeigen grüner Punkt (Kreis x,y,r)    //Display Gruener Punkt Anzeigen

        Start_Zeit_Stoppuhr[0] = millis();                                                            //Zeit Ablesen seit Start von Arduino

        Zeit_speichern = false;                                                                       //Zeit Speichern auf false setzen
        }


        if (digitalRead(8) == LOW)
        {

        Display.gfx_CircleFilled(40, 120, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)       //Display Roter Punkt Anzeigen

        Stop_Zeit_Stoppuhr[0]=(millis())- Start_Zeit_Stoppuhr[0];                                     //Stoppzeit ausrechnen, aus aktuelle Zeit Minus Start_Zeit_Stoppuhr

        Zeiten_Stoppuhr_1[9]=Zeiten_Stoppuhr_1[8];                                                    //History
        Zeiten_Stoppuhr_1[8]=Zeiten_Stoppuhr_1[7];
        Zeiten_Stoppuhr_1[7]=Zeiten_Stoppuhr_1[6];
        Zeiten_Stoppuhr_1[6]=Zeiten_Stoppuhr_1[5];
        Zeiten_Stoppuhr_1[5]=Zeiten_Stoppuhr_1[4];
        Zeiten_Stoppuhr_1[4]=Zeiten_Stoppuhr_1[3];
        Zeiten_Stoppuhr_1[3]=Zeiten_Stoppuhr_1[2];
        Zeiten_Stoppuhr_1[2]=Zeiten_Stoppuhr_1[1];
        Zeiten_Stoppuhr_1[1]=Zeiten_Stoppuhr_1[0];
        Zeiten_Stoppuhr_1[0]=Stop_Zeit_Stoppuhr[0];                

        Display.txt_Height(2);                        //Texthöhe
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(580, 100);                 //Text Position x,y
        Display.print(Zeiten_Stoppuhr_1[0]);          //Wert Anzeigen
        Display.print(" ms    ");
        Display.gfx_MoveTo(580, 125);                 //Text Position x,y
        Display.print(Zeiten_Stoppuhr_1[1]);          //Wert Anzeigen
        Display.print(" ms    ");
        Display.gfx_MoveTo(580, 150);                 //Text Position x,y
        Display.print(Zeiten_Stoppuhr_1[2]);          //Wert Anzeigen
        Display.print(" ms    ");

        Zeiten_speichern[0]=false;                   //Zeiten_speichern auf false setzen

        Display.txt_Height(4);                       //Texthöhe
        Display.txt_Width(3);                        //Textweite
        Display.txt_Inverse(OFF);                    //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);         //Textfarbe Weiss
        Display.gfx_MoveTo(80, 100);                 //Text Position x,y
        Display.print("");
        Display.print(Zeiten_Stoppuhr_1[0]);         //Wert Anzeigen
        Display.print(" ms       ");   

        Stunden=(Zeiten_Stoppuhr_1[0]/3600000)%24;   //Stunden, Minuten, Sekunden, Millisekunden ausrechnen
        Minuten=(Zeiten_Stoppuhr_1[0]/60000)%60;     //Das Zeichen: "%" ist der Modulo-Operator
        Sekunden=(Zeiten_Stoppuhr_1[0]/1000)%60;
        Millisekunden=Zeiten_Stoppuhr_1[0];

        Display.txt_Height(2);              //Texthöhe
        Display.txt_Width(2);               //Textweite
        Display.gfx_MoveTo(80, 150);        //Text Position x,y
        Display.print(Stunden);             //Wert Anzeigen
        Display.print(" : ");
        Display.print(Minuten);             //Wert Anzeigen
        Display.print(" : ");
        Display.print(Sekunden);            //Wert Anzeigen
        Display.print("      ");

        Zeit_speichern = true;              //Zeit_speichern setzen

        Menue_angewaehlt = 1;               //Menue_angewaehlt setzen
        }

      }

      else
      {
        
      Menue_angewaehlt = 0;                 //Hauptmenü
      }

    break;

//Stoppuhr 2 Interrupt

    case 7:

      if (Displaystopp == true)        //Überwachung Bildschirm aufgebaut
      {
        
      Start_Zeit2 = 0;                 //Start Zeit 2 Reset
      Stopp_Zeit2 = 0;                 //Stopp Zeit 2 Reset      

                                                                            
        if (Zeit_speichern2 == true)
        {
          
        Display.gfx_CircleFilled(40, 250, 20, GREEN); //Status Anzeigen grüner Punkt (Kreis x,y,r)    //Display Gruener Punkt Anzeigen

        Start_Zeit_Stoppuhr2[0] = millis();                                                           //Zeit Ablesen seit Start von Arduino

        Zeit_speichern2 = false;                                                                      //Zeit Speichern 2 auf 0 setzen
        }


        if (digitalRead(9) == LOW)
        {

        Display.gfx_CircleFilled(40, 250, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)       //Display Roter Punkt Anzeigen

        Stop_Zeit_Stoppuhr2[0]=(millis())- Start_Zeit_Stoppuhr2[0];                                   //Stoppzeit 2 ausrechnen, aus aktuelle Zeit Minus Start_Zeit_Stoppuhr 2

        Zeiten_Stoppuhr_2[9]=Zeiten_Stoppuhr_2[8];                                                    //History 2
        Zeiten_Stoppuhr_2[8]=Zeiten_Stoppuhr_2[7];
        Zeiten_Stoppuhr_2[7]=Zeiten_Stoppuhr_2[6];
        Zeiten_Stoppuhr_2[6]=Zeiten_Stoppuhr_2[5];
        Zeiten_Stoppuhr_2[5]=Zeiten_Stoppuhr_2[4];
        Zeiten_Stoppuhr_2[4]=Zeiten_Stoppuhr_2[3];
        Zeiten_Stoppuhr_2[3]=Zeiten_Stoppuhr_2[2];
        Zeiten_Stoppuhr_2[2]=Zeiten_Stoppuhr_2[1];
        Zeiten_Stoppuhr_2[1]=Zeiten_Stoppuhr_2[0];
        Zeiten_Stoppuhr_2[0]=Stop_Zeit_Stoppuhr2[0];               

        Display.txt_Height(2);                        //Texthöhe
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(580, 225);                 //Text Position x,y
        Display.print(Zeiten_Stoppuhr_2[0]);          //Wert Anzeigen
        Display.print(" ms    ");
        Display.gfx_MoveTo(580, 250);                 //Text Position x,y
        Display.print(Zeiten_Stoppuhr_2[1]);          //Wert Anzeigen
        Display.print(" ms    ");
        Display.gfx_MoveTo(580, 275);                 //Text Position x,y
        Display.print(Zeiten_Stoppuhr_2[2]);          //Wert Anzeigen
        Display.print(" ms    ");

        Zeiten_speichern2[0]=false;
        
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);          //Textfarbe Weiss
        Display.gfx_MoveTo(80, 230);                  //Text Position x,y
        Display.print("");
        Display.print(Zeiten_Stoppuhr_2[0]);          //Wert Anzeigen
        Display.print(" ms       ");

        Stunden2=(Zeiten_Stoppuhr_2[0]/3600000)%24;   //Stunden, Minuten, Sekunden, Millisekunden ausrechnen 
        Minuten2=(Zeiten_Stoppuhr_2[0]/60000)%60;     //Das Zeichen: "%" ist der Modulo-Operator
        Sekunden2=(Zeiten_Stoppuhr_2[0]/1000)%60;
        Millisekunden2=Zeiten_Stoppuhr_2[0];

        Display.txt_Height(2);                        //Texthöhe 
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(80, 280);                  //Text Position x,y
        Display.print(Stunden2);                      //Wert Anzeigen
        Display.print(" : ");
        Display.print(Minuten2);                      //Wert Anzeigen
        Display.print(" : ");
        Display.print(Sekunden2);                     //Wert Anzeigen
        Display.print("      ");

        //Display.print(" . ");
        //Display.print(Millisekunden);

        Zeit_speichern2 = true;            //Zeit_speichern 2 setzen

        Menue_angewaehlt = 1;              //Menue_angewaehlt setzen

        }
      }
      
      else 
      {
        
      Menue_angewaehlt = 0;                //Hauptmeü
      }

    break;

//Geschwindigkeitsanzeige

    case 8:

      if (Displaystopp == true)     
      {
        
     
        if (Zeit_speichern3 == true)
        {
          
        Display.gfx_CircleFilled(40, 120, 20, GREEN);                                                 //Display Gruener Punkt Anzeigen

        Start_Zeit_Geschwindigkeit = millis();                                                        //Zeit Ablesen seit Start von Arduino

        Zeit_speichern3 = false;                                                                      //Zeit Speichern3 auf false setzen

        Geschwindigkeit_Stopp = false;                                                                //Geschwindigkeit Stopp auf flase setzen
        }

        if (Geschwindigkeit_Stopp == true)
        {    

        Display.gfx_CircleFilled(40, 120, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)       //Display Roter Punkt Anzeigen
  
        Stopp_Zeit_Geschwindigkeit=(60/((millis()- Start_Zeit_Geschwindigkeit)/1000));                //Stoppzeit ausrechnen, aus 60 durch aktuelle Zeit Minus Start_Zeit_Geschwindigkeit

  
          if (Stopp_Zeit_Geschwindigkeit >= Hoechstwert)
          {
            
          Hoechstwert = Stopp_Zeit_Geschwindigkeit;     //Höchstwert Stopp_Zeit_Geschwindigkeit gleichsetzen
          
          Display.txt_Height(2);                        //Texthöhe
          Display.txt_Width(2);                         //Textweite
          Display.gfx_MoveTo(83, 160);                  //Text Position x,y
          Display.print(Hoechstwert);                   //Wert Anzeigen
          Display.print(" Hoechstwert  ");
          }
  
        Zeiten_Geschwindigkeit_1[9]=Zeiten_Geschwindigkeit_1[8];                                      //History
        Zeiten_Geschwindigkeit_1[8]=Zeiten_Geschwindigkeit_1[7];
        Zeiten_Geschwindigkeit_1[7]=Zeiten_Geschwindigkeit_1[6];
        Zeiten_Geschwindigkeit_1[6]=Zeiten_Geschwindigkeit_1[5];
        Zeiten_Geschwindigkeit_1[5]=Zeiten_Geschwindigkeit_1[4];
        Zeiten_Geschwindigkeit_1[4]=Zeiten_Geschwindigkeit_1[3];
        Zeiten_Geschwindigkeit_1[3]=Zeiten_Geschwindigkeit_1[2];
        Zeiten_Geschwindigkeit_1[2]=Zeiten_Geschwindigkeit_1[1];
        Zeiten_Geschwindigkeit_1[1]=Zeiten_Geschwindigkeit_1[0];
        Zeiten_Geschwindigkeit_1[0]=Stopp_Zeit_Geschwindigkeit;                
  
        Display.txt_Height(2);                        //Texthöhe
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(580, 100);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_1[0]);   //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 125);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_1[1]);   //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 150);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_1[2]);   //Wert Anzeigen
        Display.print(" cpm    ");
  
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);          //Textfarbe Weiss
        Display.gfx_MoveTo(80, 100);                  //Text Position x,y
        Display.print("");
        Display.print(Zeiten_Geschwindigkeit_1[0]);   //Wert Anzeigen
        Display.print(" cpm       ");   

        Zeit_speichern3 = true;                       //Zeit_speichern3 setzen
  
        Menue_angewaehlt = 2;                         //Menue_angewaehlt auf 2 setzen
  
        Geschwindigkeit_Stopp = true;                 //Geschwindigkeitstopp setzen
        } 
        
        else
        {
          
        Menue_angewaehlt = 2;                         //Geschwindigkeitsanzeige
        }
      }
   
    
    break;

//Geschwindigkeitsanzeige

    case 9:

      if (Displaystopp == true)     //Überwachung Bildschirm aufgebaut
      {
        
      Start_Zeit4 = 0;              //Start Zeit4 Reset                                                                       
      Stopp_Zeit4 = 0;              //Stopp Zeit4 Reset

     
        if (Zeit_speichern4 == true)
        {
          
        Display.gfx_CircleFilled(40, 250, 20, GREEN); //Status Anzeigen grüner Punkt (Kreis x,y,r)    //Display Gruener Punkt Anzeigen

        Start_Zeit_Geschwindigkeit2 = millis();                                                       //Zeit Ablesen seit Start von Arduino

        Zeit_speichern4 = false;                                                                      //Zeit Speichern 4 auf fasle setzen

        Geschwindigkeit_Stopp2 = false;                                                               //Geschwindigkeit_Stopp2 auf false setzen
        }

    
        if (Geschwindigkeit_Stopp2 == true)
        {

        Display.gfx_CircleFilled(40, 250, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)       //Display Roter Punkt Anzeigen

        Stopp_Zeit_Geschwindigkeit2=(60/((millis()- Start_Zeit_Geschwindigkeit2)/1000));              //Stoppzeit ausrechnen, aus 60 durch aktuelle Zeit Minus Start_Zeit_Geschwindigkeit


          if (Stopp_Zeit_Geschwindigkeit2 >= Hoechstwert2)
          {
            
          Hoechstwert2 = Stopp_Zeit_Geschwindigkeit2;   //Höchstwert2 Stopp_Zeit_Geschwindigkeit2 gleichsetzen
          Display.txt_Height(2);                        //Texthöhe
          Display.txt_Width(2);                         //Textweite
          Display.gfx_MoveTo(83, 290);                  //Text Position x,y
          Display.print(Hoechstwert2);                  //Wert Anzeigen
          Display.print(" Hoechstwert  ");
          }

        Zeiten_Geschwindigkeit_2[9]=Zeiten_Geschwindigkeit_2[8];                                      //History
        Zeiten_Geschwindigkeit_2[8]=Zeiten_Geschwindigkeit_2[7];
        Zeiten_Geschwindigkeit_2[7]=Zeiten_Geschwindigkeit_2[6];
        Zeiten_Geschwindigkeit_2[6]=Zeiten_Geschwindigkeit_2[5];
        Zeiten_Geschwindigkeit_2[5]=Zeiten_Geschwindigkeit_2[4];
        Zeiten_Geschwindigkeit_2[4]=Zeiten_Geschwindigkeit_2[3];
        Zeiten_Geschwindigkeit_2[3]=Zeiten_Geschwindigkeit_2[2];
        Zeiten_Geschwindigkeit_2[2]=Zeiten_Geschwindigkeit_2[1];
        Zeiten_Geschwindigkeit_2[1]=Zeiten_Geschwindigkeit_2[0];
        Zeiten_Geschwindigkeit_2[0]=Stopp_Zeit_Geschwindigkeit2;                

        Display.txt_Height(2);                        //Texthöhe
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(580, 225);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_2[0]);   //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 250);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_2[1]);   //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 275);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_2[2]);   //Wert Anzeigen
        Display.print(" cpm    ");

        Display.txt_Height(4);                       //Texthöhe
        Display.txt_Width(3);                        //Textweite
        Display.txt_Inverse(OFF);                    //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);         //Textfarbe Weiss
        Display.gfx_MoveTo(80, 230);                 //Text Position x,y
        Display.print("");
        Display.print(Zeiten_Geschwindigkeit_2[0]);  //Wert Anzeigen
        Display.print(" cpm       ");   

        Zeit_speichern4 = true;                      //Zeit_speichern4 setzen

        Menue_angewaehlt = 2;                        //Geschwindigkeitsanzeige

        Geschwindigkeit_Stopp2 = true;               //Geschwindigkeit_Stopp2 setzen
        }

        else
        {
        
        Menue_angewaehlt = 2;                        //Geschwindigkeitsanzeige
        }
      }

    break;

//Geschwindigkeitsanzeige_Durchschnitt

    case 10:

    Geschwindigkeitsanzeige_Durchschnitt();         //Aufruf Funktion Geschwindigkeitsanzeige_Durchschnitt

    break;

//Geschwindigkeitsanzeige_Durchschnitt Interrupt

    case 11:

      if (Displaystopp == true)                     //Überwachung Bildschirm aufgebaut
      {
        
     
        if (Zeit_speichern5 == true)
        {
          
        Display.gfx_CircleFilled(40, 120, 20, GREEN);    //Display Gruener Punkt Anzeigen 

        Start_Zeit_Geschwindigkeit3 = millis();          //Zeit Ablesen seit Start von Arduino
                        
        Zeit_speichern5 = false;                         //Zeit_speichern5 auf false setzen                                             

        Durchschnittanzahl = 0;                          //Durchschnittanzahl Reset
        }

    Interrupt_Durchschnitt = true;                       //Interrupt_Durchschnitt setzen

    Stopp_Zeit_Geschwindigkeit3 = (millis() - Start_Zeit_Geschwindigkeit3);           //Zeit seit start ausrechnen


        if (Stopp_Zeit_Geschwindigkeit3 >= 60000)                                     //Zeit abfragen nach 60s
        {    

        Display.gfx_CircleFilled(40, 120, 20, RED);                                   //Display Roter Punkt Anzeigen  
  
        Zeiten_Geschwindigkeit_3[9]=Zeiten_Geschwindigkeit_3[8];                      //History
        Zeiten_Geschwindigkeit_3[8]=Zeiten_Geschwindigkeit_3[7];
        Zeiten_Geschwindigkeit_3[7]=Zeiten_Geschwindigkeit_3[6];
        Zeiten_Geschwindigkeit_3[6]=Zeiten_Geschwindigkeit_3[5];
        Zeiten_Geschwindigkeit_3[5]=Zeiten_Geschwindigkeit_3[4];
        Zeiten_Geschwindigkeit_3[4]=Zeiten_Geschwindigkeit_3[3];
        Zeiten_Geschwindigkeit_3[3]=Zeiten_Geschwindigkeit_3[2];
        Zeiten_Geschwindigkeit_3[2]=Zeiten_Geschwindigkeit_3[1];
        Zeiten_Geschwindigkeit_3[1]=Zeiten_Geschwindigkeit_3[0];
        Zeiten_Geschwindigkeit_3[0]=Durchschnittanzahl;                
  
        Display.txt_Height(2);                        //Texthöhe
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(580, 100);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_3[0]);   //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 125);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_3[1]);   //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 150);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_3[2]);   //Wert Anzeigen
        Display.print(" cpm    ");
  
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);          //Textfarbe Weiss
        Display.gfx_MoveTo(80, 100);                  //Text Position x,y
        Display.print("");
        Display.print(Zeiten_Geschwindigkeit_3[0]);   //Wert Anzeigen
        Display.print(" cpm       ");   
  
        Zeit_speichern5 = true;                       //Zeit_speichern 5 setzen
  
        Menue_angewaehlt = 10;                        //Menue_angewaehlt auf 10 setzen
        } 

        else         
        {

        Menue_angewaehlt = 10;                        //Menue_angewaehlt auf 10 setzen
        }    
      }

    break;

//Geschwindigkeitsanzeige_Durchschnitt Interrupt

    case 12:

      if (Displaystopp == true)                       //Überwachung Bildschirm aufgebaut
      {
        
     
        if (Zeit_speichern6 == true)
        {
          
          Display.gfx_CircleFilled(40, 250, 20, GREEN);                           //Display Gruener Punkt Anzeigen 

          Start_Zeit_Geschwindigkeit4 = millis();                                 //Zeit Ablesen seit Start von Arduino
                        
          Zeit_speichern6 = false;                                                //Zeit_speichern6 auf false setzen                      

          Durchschnittanzahl2 = 0;                                                //Durchschnittanzahl 2 Reset
        }

        Interrupt_Durchschnitt2 = true;                                           //Interrupt_Durchschnitt 2 setzen

        Stopp_Zeit_Geschwindigkeit4 = (millis() - Start_Zeit_Geschwindigkeit4);   //Zeit seit start ausrechnen


        if (Stopp_Zeit_Geschwindigkeit4 >= 60000)                                 //Zeit abfragen nach 60s
        {    

        Display.gfx_CircleFilled(40, 250, 20, RED);                               //Display Roter Punkt Anzeigen
          
        Zeiten_Geschwindigkeit_4[9]=Zeiten_Geschwindigkeit_4[8];                  //History
        Zeiten_Geschwindigkeit_4[8]=Zeiten_Geschwindigkeit_4[7];
        Zeiten_Geschwindigkeit_4[7]=Zeiten_Geschwindigkeit_4[6];
        Zeiten_Geschwindigkeit_4[6]=Zeiten_Geschwindigkeit_4[5];
        Zeiten_Geschwindigkeit_4[5]=Zeiten_Geschwindigkeit_4[4];
        Zeiten_Geschwindigkeit_4[4]=Zeiten_Geschwindigkeit_4[3];
        Zeiten_Geschwindigkeit_4[3]=Zeiten_Geschwindigkeit_4[2];
        Zeiten_Geschwindigkeit_4[2]=Zeiten_Geschwindigkeit_4[1];
        Zeiten_Geschwindigkeit_4[1]=Zeiten_Geschwindigkeit_4[0];
        Zeiten_Geschwindigkeit_4[0]=Durchschnittanzahl2;                
  
        Display.txt_Height(2);                        //Texthöhe
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(580, 225);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_4[0]);   //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 250);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_4[1]);   //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 275);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_4[2]);   //Wert Anzeigen
        Display.print(" cpm    ");
  
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);          //Textfarbe Weiss
        Display.gfx_MoveTo(80, 230);                  //Text Position x,y
        Display.print("");
        Display.print(Zeiten_Geschwindigkeit_4[0]);   //Wert Anzeigen
        Display.print(" cpm       ");   

        Zeit_speichern6 = true;             //Zeit_speichern 6 setzen
  
        Menue_angewaehlt = 10;              //Menue_angewaehlt auf 10 setzen
        } 

        else
        {
  
        Menue_angewaehlt = 10;              //Menue_angewaehlt auf 10 setzen
        }  
      }

    break;
    
  }
}
