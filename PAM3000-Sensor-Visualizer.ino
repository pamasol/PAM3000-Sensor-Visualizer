/*
  //*****************************************************************************************************

    Programm:       PAM3000_Sensor_Visualizer_001
    Prozessor:      Arduino Due
    Clock:          16MHz

    Version:        001
    Datum:          01.05.2020

    Programmierer:  D.Bernhard, J.Glaus
   
  //*****************************************************************************************************

     Hochladen: - Board:      "Arduino Due"

           - Port:       "COM03(Arduino Due)"
           - Programmer: "USBasp"

  //*****************************************************************************************************

  Info: - Display Auflösung 800x480pixel

  Struktur:
  
  0. Hauptmenü
  1. Stoppuhr
  2. Geschwindigkeitsanzeige
  3. Analogeanzeige
  4. Magnetpolanzeige
  5. Einstellungen
  
*/

//*****************************************************************************************************

#define DisplaySerial Serial
#define HALL_SENSOR 7

#include <Diablo_Const4D.h>
#include <Diablo_Serial_4DLib.h>

#include <Wire.h>
#include <Adafruit_INA219.h> // You will need to download this library

Adafruit_INA219 sensor219; // Declare and instance of INA219

Diablo_Serial_4DLib Display(&DisplaySerial);  //Serielle Kommunikation mit Display



//****************************************************************************************************************************************

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
bool Stoppuhrinterrupt2;             //Stoppuhr Interrupt 2
bool Geschwingigkeitinterrupt;      //Geschwindigkeitsanzeige Interrupt
bool Geschwingigkeitinterrupt2;      //Geschwindigkeitsanzeige Interrupt 2
bool Start_speichern2[2];           //Zeiten speichern 2
bool Zeiten_speichern2[2];          //Zeiten speichern 2
bool Zeit_speichern2;               //Zeiten speichern 2

int Stunden2;                       //Stunden Anzeige 2
int Minuten2;                       //Minuten Anzeige 2
int Sekunden2;                      //Sekunden Anzeige 2
int Millisekunden2;                 //Millisekunden Anzeige 2

unsigned long Start_Zeit_Stoppuhr[2];    //Start Zeit Stoppuhr 1
unsigned long Stop_Zeit_Stoppuhr[2];     //Stop Zeit Stoppuhr 1
unsigned long Zeiten_Stoppuhr_1[9];      //Zeiten Stoppuhr 1 (0-9)

unsigned long Start_Zeit;               //Start Stoppuhr 1
unsigned long Stopp_Zeit;               //Start Stoppuhr 1

unsigned long Start_Zeit_Stoppuhr2[2];   //Start Zeit Stoppuhr 2
unsigned long Stop_Zeit_Stoppuhr2[2];    //Stop Zeit Stoppuhr 2
unsigned long Zeiten_Stoppuhr_2[9];      //Zeiten Stoppuhr 2 (0-9)

unsigned long Start_Zeit2;               //Start Stoppuhr 2
unsigned long Stopp_Zeit2;               //Start Stoppuhr 2

float Start_Zeit_Geschwindigkeit;         //Start Zeit für Geschwindigkeitsanzeige
unsigned long Stopp_Zeit_Geschwindigkeit; //Stopp Zeit für Geschwindigkeitsanzeige
unsigned long Zeiten_Geschwindigkeit_1[9];//Geschwindigeitswert Speichern
unsigned long Hoechstwert;                // Hoechstwert von Geschwindigkeitsanzeige

float Start_Zeit_Geschwindigkeit2;        //Start Zeit für Geschwindigkeitsanzeige 2
unsigned long Stopp_Zeit_Geschwindigkeit2;//Stopp Zeit für Geschwindigkeitsanzeige 2
unsigned long Zeiten_Geschwindigkeit_2[9];//Geschwindigeitswert 2 Speichern
unsigned long Hoechstwert2;               // Hoechstwert von Geschwindigkeitsanzeige 2

unsigned long Start_Zeit3;               //Start Geschwindikeitsanzeige
unsigned long Stopp_Zeit3;               //Stopp Geschwindikeitsanzeige

unsigned long Start_Zeit4;               //Start Geschwindikeitsanzeige 2
unsigned long Stopp_Zeit4;               //Stopp Geschwindikeitsanzeige 2

bool Zeit_speichern3;                //Zeiten speichern Geschwindigkeitsanzeige
bool Zeit_speichern4;                //Zeiten speichern Geschwindigkeitsanzeige

bool Geschwindigkeit_Stopp;          //Stoppzeit Geschwindigkeitsanzeige
bool Geschwindigkeit_Stopp2;         //Stoppzeit Geschwindigkeitsanzeige 2


bool Geschwingigkeitinterrupt_Durchschnitt;  //Durchschnitt Geschwindigkeitsanzeige
bool Geschwingigkeitinterrupt_Durchschnitt2; //Durchschnitt Geschwindigkeitsanzeige 2
bool Zeit_speichern5;                        //Zeiten Speichern
bool Geschwingigkeitinterrupt3;             //Geschwindigkeitsanzeige Durchschnitt Interrupt
bool Geschwingigkeitinterrupt4;             //Geschwindigkeitsanzeige Durchschnitt Interrupt 2
unsigned long Stopp_Zeit_Geschwindigkeit3;
unsigned long Stopp_Zeit_Geschwindigkeit4;
unsigned long Start_Zeit_Geschwindigkeit3;
unsigned long Start_Zeit_Geschwindigkeit4;
unsigned long Hoechstwert3 = 0;
unsigned long Hoechstwert4 = 0;
bool Reset3;
unsigned long Zeiten_Geschwindigkeit_3[9];
long Durchschnittanzahl;
bool Interrupt_Durchschnitt;

long Leistung;
bool Reset4;
bool Zeit_speichern6;
unsigned long Zeiten_Geschwindigkeit_4[9];
long Durchschnittanzahl2;
bool Interrupt_Durchschnitt2;

float DruckSensor;
long Max_Bar;
long Max_mA;
long Min_mA;
float busVoltage = 0;
float current = 0; // Measure in milli amps
float power = 0;

unsigned long Test;
//****************************************************************************************************************************************

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

  pinMode(4, OUTPUT);                     //Set D4 on Arduino to Output (4D Arduino Adaptor V2 - Display Reset)
  digitalWrite(4, HIGH);                  //Reset the Display via D4
  delay(100);                             //Verzögerung 100ms
  digitalWrite(4, LOW);                   //unReset the Display via D4

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

  Zeit_speichern = true;                                //Zeiten speichern (1)
  Zeit_speichern2 = true;                               //Zeiten speichern 2 (1)
  Zeit_speichern3 = true;
  Zeit_speichern4 = true;
  Zeit_speichern5 = true;
  Zeit_speichern6 = true;
  Reset1 = true;
  Reset2 = true;
  Reset3 = true;
  Reset4 = true;
  Stoppuhrinterrupt = false;
  Stoppuhrinterrupt2 = false;
  Geschwingigkeitinterrupt = false;
  Geschwingigkeitinterrupt2 = false;
  Geschwingigkeitinterrupt3 = false;
  Geschwingigkeitinterrupt4 = false;
  Geschwindigkeit_Stopp = true;
  Interrupt_Durchschnitt = true;
  Interrupt_Durchschnitt2 = true;


  Stopp_Zeit_Geschwindigkeit3 = 0; 
  Stopp_Zeit_Geschwindigkeit4 = 0;

  Leistung = 0;


  pinMode(HALL_SENSOR, INPUT);

  Serial.begin(9600);    
  sensor219.begin();
  
}

//****************************************************************************************************************************************

void loop()

{

  Display.gfx_Contrast(Kontrast_Display);   //Kontrast Display

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
        
      Start_Zeit = 0;                                                                                 //Start Zeit Reset
      Stopp_Zeit = 0;                                                                                 //Stopp Zeit Reset

     
      if (Zeit_speichern == true)

      {
        Display.gfx_CircleFilled(40, 120, 20, GREEN); //Status Anzeigen grüner Punkt (Kreis x,y,r)    //Display Gruener Punkt Anzeigen

        Start_Zeit_Stoppuhr[0] = millis();                                                            //Zeit Ablesen seit Start von Arduino

        Zeit_speichern = false;                                                                       //Zeit Speichern (0)

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

        Zeiten_speichern[0]=false;                   //Zeiten_speichern (0)

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
        Display.print(Stunden);
        Display.print(" : ");
        Display.print(Minuten);
        Display.print(" : ");
        Display.print(Sekunden);
        Display.print("      ");

        Zeit_speichern = true;             //Zeit_speichern (1)

        Menue_angewaehlt = 1;              //Menue_angewaehlt (1)

       }

      }


      else
      {
        
      Menue_angewaehlt = 0;
      
      }

        break;


    //Stoppuhr 2 Interrupt


    case 7:

      if (Displaystopp == true) //Überwachung Bildschirm aufgebaut

      {
        
      Start_Zeit2 = 0;                                                                                //Start Zeit 2 Reset
      Stopp_Zeit2 = 0;                                                                                //Stopp Zeit 2 Reset      

                                                                            
      if (Zeit_speichern2 == true)

      {
        Display.gfx_CircleFilled(40, 250, 20, GREEN); //Status Anzeigen grüner Punkt (Kreis x,y,r)    //Display Gruener Punkt Anzeigen

        Start_Zeit_Stoppuhr2[0] = millis();                                                           //Zeit Ablesen seit Start von Arduino

        Zeit_speichern2 = false;                                                                      //Zeit Speichern 2 (0)

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
        Display.txt_Set(TEXT_COLOUR, WHITE);
        Display.gfx_MoveTo(80, 230);                  //Text Position x,y
        Display.print("");
        Display.print(Zeiten_Stoppuhr_2[0]);          //Wert Anzeigen
        Display.print(" ms       ");

        Stunden2=(Zeiten_Stoppuhr_2[0]/3600000)%24;   //Stunden, Minuten, Sekunden, Millisekunden ausrechnen 
        Minuten2=(Zeiten_Stoppuhr_2[0]/60000)%60;     //Das Zeichen: "%" ist der Modulo-Operator
        Sekunden2=(Zeiten_Stoppuhr_2[0]/1000)%60;
        Millisekunden2=Zeiten_Stoppuhr_2[0];

        Display.txt_Height(2);                       //Texthöhe 
        Display.txt_Width(2);                        //Textweite
        Display.gfx_MoveTo(80, 280);                 //Text Position x,y
        Display.print(Stunden2);
        Display.print(" : ");
        Display.print(Minuten2);
        Display.print(" : ");
        Display.print(Sekunden2);
        Display.print("      ");

        //Display.print(" . ");
        //Display.print(Millisekunden);

        Zeit_speichern2 = true;            //Zeit_speichern 2 (1)

        Menue_angewaehlt = 1;              //Menue_angewaehlt (1)

       }

      }

       else 
       {
        
        Menue_angewaehlt = 0;
        
       }

        break;

     case 8:

      if (Displaystopp == true) //Überwachung Bildschirm aufgebaut

      {
        
     
      if (Zeit_speichern3 == true)

        {
          Display.gfx_CircleFilled(40, 120, 20, GREEN); //Status Anzeigen grüner Punkt (Kreis x,y,r)    //Display Gruener Punkt Anzeigen

          Start_Zeit_Geschwindigkeit = millis();                                                            //Zeit Ablesen seit Start von Arduino

          Zeit_speichern3 = false;                                                                       //Zeit Speichern (0)

          Geschwindigkeit_Stopp = false;

          
        }

      if (Geschwindigkeit_Stopp == true)

        {    

 

          Display.gfx_CircleFilled(40, 120, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)       //Display Roter Punkt Anzeigen
  
          Stopp_Zeit_Geschwindigkeit=(60/((millis()- Start_Zeit_Geschwindigkeit)/1000));                //Stoppzeit ausrechnen, aus aktuelle Zeit Minus Start_Zeit_Stoppuhr

  
            if (Stopp_Zeit_Geschwindigkeit >= Hoechstwert)
          
          {
          Hoechstwert = Stopp_Zeit_Geschwindigkeit;
          Display.txt_Height(2);              //Texthöhe
          Display.txt_Width(2);               //Textweite
          Display.gfx_MoveTo(83, 160);        //Text Position x,y
          Display.print(Hoechstwert);
          Display.print(" Hoechstwert  ");
          }
  
          Zeiten_Geschwindigkeit_1[9]=Zeiten_Geschwindigkeit_1[8];                                                    //History
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
          Display.print(Zeiten_Geschwindigkeit_1[0]);          //Wert Anzeigen
          Display.print(" cpm    ");
          Display.gfx_MoveTo(580, 125);                 //Text Position x,y
          Display.print(Zeiten_Geschwindigkeit_1[1]);          //Wert Anzeigen
          Display.print(" cpm    ");
          Display.gfx_MoveTo(580, 150);                 //Text Position x,y
          Display.print(Zeiten_Geschwindigkeit_1[2]);          //Wert Anzeigen
          Display.print(" cpm    ");
  
          Display.txt_Height(4);                       //Texthöhe
          Display.txt_Width(3);                        //Textweite
          Display.txt_Inverse(OFF);                    //Text invetieren
          Display.txt_Bold(OFF);
          Display.txt_Set(TEXT_COLOUR, WHITE);         //Textfarbe Weiss
          Display.gfx_MoveTo(80, 100);                 //Text Position x,y
          Display.print("");
          Display.print(Zeiten_Geschwindigkeit_1[0]);         //Wert Anzeigen
          Display.print(" cpm       ");   

  
          Zeit_speichern3 = true;             //Zeit_speichern (1)
  
          Menue_angewaehlt = 2;              //Menue_angewaehlt (1)
  
          Geschwindigkeit_Stopp = true;

       } 
       else
         
          {
          
            Menue_angewaehlt = 2;
        
           }
      }
   
    
        break;


      case 9:

 if (Displaystopp == true) //Überwachung Bildschirm aufgebaut

      {
        
      Start_Zeit4 = 0;                                                                                 //Start Zeit Reset
      Stopp_Zeit4 = 0;
     
      if (Zeit_speichern4 == true)

      {
        Display.gfx_CircleFilled(40, 250, 20, GREEN); //Status Anzeigen grüner Punkt (Kreis x,y,r)    //Display Gruener Punkt Anzeigen

        Start_Zeit_Geschwindigkeit2 = millis();                                                            //Zeit Ablesen seit Start von Arduino

        Zeit_speichern4 = false;                                                                        //Zeit Speichern (0)

        Geschwindigkeit_Stopp2 = false;

      }

    
if (Geschwindigkeit_Stopp2 == true)

      {

        Display.gfx_CircleFilled(40, 250, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)       //Display Roter Punkt Anzeigen

        Stopp_Zeit_Geschwindigkeit2=(60/((millis()- Start_Zeit_Geschwindigkeit2)/1000));                //Stoppzeit ausrechnen, aus aktuelle Zeit Minus Start_Zeit_Stoppuhr


          if (Stopp_Zeit_Geschwindigkeit2 >= Hoechstwert2)
          
          {
          Hoechstwert2 = Stopp_Zeit_Geschwindigkeit2;
          Display.txt_Height(2);              //Texthöhe
          Display.txt_Width(2);               //Textweite
          Display.gfx_MoveTo(83, 290);        //Text Position x,y
          Display.print(Hoechstwert2);
          Display.print(" Hoechstwert  ");
          }

        Zeiten_Geschwindigkeit_2[9]=Zeiten_Geschwindigkeit_2[8];                                                    //History
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
        Display.print(Zeiten_Geschwindigkeit_2[0]);          //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 250);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_2[1]);          //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 275);                 //Text Position x,y
        Display.print(Zeiten_Geschwindigkeit_2[2]);          //Wert Anzeigen
        Display.print(" cpm    ");

        Display.txt_Height(4);                       //Texthöhe
        Display.txt_Width(3);                        //Textweite
        Display.txt_Inverse(OFF);                    //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);         //Textfarbe Weiss
        Display.gfx_MoveTo(80, 230);                 //Text Position x,y
        Display.print("");
        Display.print(Zeiten_Geschwindigkeit_2[0]);         //Wert Anzeigen
        Display.print(" cpm       ");   


        Zeit_speichern4 = true;             //Zeit_speichern (1)

        Menue_angewaehlt = 2;              //Menue_angewaehlt (1)

        Geschwindigkeit_Stopp2 = true;
        
       }

      
      else
      {
        
      Menue_angewaehlt = 2;
      
      }

     }

       break;


      case 10:



      Geschwindigkeitsanzeige_Durchschnitt();
      
      

      break;


      case 11:


 if (Displaystopp == true) //Überwachung Bildschirm aufgebaut

      {
        
     
      if (Zeit_speichern5 == true)

        {
          Display.gfx_CircleFilled(40, 120, 20, GREEN); //Status Anzeigen grüner Punkt (Kreis x,y,r)    //Display Gruener Punkt Anzeigen 

          Start_Zeit_Geschwindigkeit3 = millis();  
                        
          Zeit_speichern5 = false;                                                                      

          Durchschnittanzahl = 0;
        }



        Interrupt_Durchschnitt = true;

        Stopp_Zeit_Geschwindigkeit3 = (millis() - Start_Zeit_Geschwindigkeit3);



        

      if (Stopp_Zeit_Geschwindigkeit3 >= 60000)

        {    

 

          Display.gfx_CircleFilled(40, 120, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)       //Display Roter Punkt Anzeigen
          
  
          Zeiten_Geschwindigkeit_3[9]=Zeiten_Geschwindigkeit_3[8];                                                    //History
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
          Display.print(Zeiten_Geschwindigkeit_3[0]);          //Wert Anzeigen
          Display.print(" cpm    ");
          Display.gfx_MoveTo(580, 125);                 //Text Position x,y
          Display.print(Zeiten_Geschwindigkeit_3[1]);          //Wert Anzeigen
          Display.print(" cpm    ");
          Display.gfx_MoveTo(580, 150);                 //Text Position x,y
          Display.print(Zeiten_Geschwindigkeit_3[2]);          //Wert Anzeigen
          Display.print(" cpm    ");
  
          Display.txt_Height(4);                       //Texthöhe
          Display.txt_Width(3);                        //Textweite
          Display.txt_Inverse(OFF);                    //Text invetieren
          Display.txt_Bold(OFF);
          Display.txt_Set(TEXT_COLOUR, WHITE);         //Textfarbe Weiss
          Display.gfx_MoveTo(80, 100);                 //Text Position x,y
          Display.print("");
          Display.print(Zeiten_Geschwindigkeit_3[0]);         //Wert Anzeigen
          Display.print(" cpm       ");   

  
          Zeit_speichern5 = true;             //Zeit_speichern (1)
  
          Menue_angewaehlt = 10;              //Menue_angewaehlt (1)
  
          

       } 

       
       else
         
          {
          
            Menue_angewaehlt = 10;
        
           }
           
      }



      

      break;



 case 12:


 if (Displaystopp == true) //Überwachung Bildschirm aufgebaut

      {
        
     
      if (Zeit_speichern6 == true)

        {
          Display.gfx_CircleFilled(40, 250, 20, GREEN); //Status Anzeigen grüner Punkt (Kreis x,y,r)    //Display Gruener Punkt Anzeigen 

          Start_Zeit_Geschwindigkeit4 = millis();  
                        
          Zeit_speichern6 = false;                                                                      

          Durchschnittanzahl2 = 0;
        }



        Interrupt_Durchschnitt2 = true;

        Stopp_Zeit_Geschwindigkeit4 = (millis() - Start_Zeit_Geschwindigkeit4);



        

      if (Stopp_Zeit_Geschwindigkeit4 >= 60000)

        {    

 

          Display.gfx_CircleFilled(40, 250, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)       //Display Roter Punkt Anzeigen
          
  
          Zeiten_Geschwindigkeit_4[9]=Zeiten_Geschwindigkeit_4[8];                                                    //History
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
          Display.print(Zeiten_Geschwindigkeit_4[0]);          //Wert Anzeigen
          Display.print(" cpm    ");
          Display.gfx_MoveTo(580, 250);                 //Text Position x,y
          Display.print(Zeiten_Geschwindigkeit_4[1]);          //Wert Anzeigen
          Display.print(" cpm    ");
          Display.gfx_MoveTo(580, 275);                 //Text Position x,y
          Display.print(Zeiten_Geschwindigkeit_4[2]);          //Wert Anzeigen
          Display.print(" cpm    ");
  
          Display.txt_Height(4);                       //Texthöhe
          Display.txt_Width(3);                        //Textweite
          Display.txt_Inverse(OFF);                    //Text invetieren
          Display.txt_Bold(OFF);
          Display.txt_Set(TEXT_COLOUR, WHITE);         //Textfarbe Weiss
          Display.gfx_MoveTo(80, 230);                 //Text Position x,y
          Display.print("");
          Display.print(Zeiten_Geschwindigkeit_4[0]);         //Wert Anzeigen
          Display.print(" cpm       ");   

  
          Zeit_speichern6 = true;             //Zeit_speichern (1)
  
          Menue_angewaehlt = 10;              //Menue_angewaehlt (1)
  
          

       } 

       
       else
         
          {
          
            Menue_angewaehlt = 10;
        
           }
           
      }



      

      break;





  }

  }

//****************************************************************************************************************************************

void Hauptmenue()

{

  Stoppuhrinterrupt = false;
  Stoppuhrinterrupt2 = false;
  Geschwingigkeitinterrupt = false;
  Geschwingigkeitinterrupt2 = false;

  Stopp_Zeit_Geschwindigkeit = 0;
  Stopp_Zeit_Geschwindigkeit2 = 0;
  
  Displaystopp = false;

  if (Bild_aufgebaut[0] == false) //Überwachung Bildschirm aufgebaut

  {

    Display.gfx_Cls();                //Display löschen
    Display.gfx_Button(Status_Taste, 30, 60, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Stoppuhr");                 //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 30, 140, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige c to c"); //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 500, 140, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Durchschnitt"); //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 30, 220, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Analogeanzeige");          //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 30, 300, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Magnetpolanzeige");        //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 30, 380, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Einstellungen");           //Taste anzeigen ungedrückt
    

    Bild_aufgebaut[0] = true;      //Bildschirm aufgebaut setzen

  }

    Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen


  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING)) //Überwachung Touch gedrückt oder bewegt

  {

    X_Pos = Display.touch_Get(TOUCH_GETX);    //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);    //Y Position auslesen

  }


  if (Status_Display == TOUCH_RELEASED) //Überwachung Touch Freigabe

  {


    if ((X_Pos >= 10) && (X_Pos <= 790) && (Y_Pos >= 30) && (Y_Pos <= 90)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;
      
      Display.gfx_Button(Status_Taste, 30, 60, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Stoppuhr"); //Taste anzeigen gedrückt

      
      if (Status_Taste)

      {

        Menue_angewaehlt = 1;       //Menü anwählen

        Bild_aufgebaut[1] = false;  //Bildschirm aufgebaut zurücksetzen

      }

    }


    if ((X_Pos >= 10) && (X_Pos <= 490) && (Y_Pos >= 110) && (Y_Pos <= 170)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 30, 140, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige c to c"); //Taste anzeigen gedrückt


      if (Status_Taste)

      {

        Menue_angewaehlt = 2;       //Menü anwählen
        
        Bild_aufgebaut[2] = false;  //Bildschirm aufgebaut zurücksetzen

      }
      
    }


    if ((X_Pos >= 500) && (X_Pos <= 790) && (Y_Pos >= 110) && (Y_Pos <= 170)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 500, 140, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Durchschnitt"); //Taste anzeigen gedrückt


      if (Status_Taste)

      {

        Menue_angewaehlt = 10;       //Menü anwählen
        
        Bild_aufgebaut[3] = false;  //Bildschirm aufgebaut zurücksetzen

      }
      
    }


    if ((X_Pos >= 10) && (X_Pos <= 790) && (Y_Pos >= 190) && (Y_Pos <= 250)) //Überwachung Touch Feld

    {
      Status_Taste = !Status_Taste;
      
      Display.gfx_Button(Status_Taste, 30, 220, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Analogeanzeige"); //Taste anzeigen gedrückt

      if (Status_Taste)

      {

        Menue_angewaehlt = 3;       //Menü anwählen
        
        Bild_aufgebaut[6] = false;  //Bildschirm aufgebaut zurücksetzen

      }

    }

    if ((X_Pos >= 10) && (X_Pos <= 790) && (Y_Pos >= 270) && (Y_Pos <= 330)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 30, 300, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Magnetpolanzeige"); //Taste anzeigen gedrückt


      if (Status_Taste)

      {

        Menue_angewaehlt = 4;       //Menü anwählen

        Bild_aufgebaut[4] = false;  //Bildschirm aufgebaut zurücksetzen

      }

    }


    if ((X_Pos >= 10) && (X_Pos <= 790) && (Y_Pos >= 350) && (Y_Pos <= 410)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 30, 380, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Einstellungen");  //Taste anzeigen gedrückt


      if (Status_Taste)

      {

        Menue_angewaehlt = 5;       //Menü anwählen

        Bild_aufgebaut[5] = false;  //Bildschirm aufgebaut zurücksetzen

      }

    }

  }

}



void Stoppuhr()

{

  Stoppuhrinterrupt = true;

  Displaystopp = true;


  if (Bild_aufgebaut[1] == false) //Überwachung Bildschirm aufgebaut

  {

    Display.gfx_Cls();                //Display löschen

    Display.gfx_Button(Status_Taste, 40, 10, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Stoppuhr");

    Status_Taste = BUTTON_UP;

    Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 350, 400, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset"); //Taste anzeigen ungedrückt
    Display.gfx_Rectangle(10, 70, 790, 200, AQUA); //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 120, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)
    Display.gfx_Rectangle(10, 330, 790, 200, AQUA); //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 250, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)

    Bild_aufgebaut[1] = true;                   //Bildschirm aufgebaut setzen

  }

  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen


if ((Stop_Zeit_Stoppuhr[0]== 0) && (Zeiten_Stoppuhr_2[0]== 0) && (Reset1 == true))

       {

       for (int i = 0; i <= 9; i++)

        {

          Zeiten_Stoppuhr_1[i] = 0;   //Zeiten Stoppuhr 1 0-9 zurücksetzen
          Zeiten_Stoppuhr_2[i] = 0;   //Zeiten Stoppuhr 2 0-9 zurücksetzen */

        }
        

        Display.txt_Height(2);                        //Texthöhe
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(580, 100);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" ms    ");
        Display.gfx_MoveTo(580, 125);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" ms    ");
        Display.gfx_MoveTo(580, 150);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" ms    ");

        Display.txt_Height(4);                       //Texthöhe
        Display.txt_Width(3);                        //Textweite
        Display.txt_Inverse(OFF);                    //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);         //Textfarbe Weiss
        Display.gfx_MoveTo(80, 100);                 //Text Position x,y
        Display.print("");
        Display.print("000");         //Wert Anzeigen
        Display.print(" ms       ");

        Display.txt_Height(2);              //Texthöhe
        Display.txt_Width(2);               //Textweite
        Display.gfx_MoveTo(80, 150);        //Text Position x,y
        Display.print("0");
        Display.print(" : ");
        Display.print("0");
        Display.print(" : ");
        Display.print("0");
        Display.print("      ");

        Display.txt_Height(2);                        //Texthöhe
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(580, 225);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" ms    ");
        Display.gfx_MoveTo(580, 250);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" ms    ");
        Display.gfx_MoveTo(580, 275);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" ms    ");

        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);
        Display.gfx_MoveTo(80, 230);                  //Text Position x,y
        Display.print("");
        Display.print("000");          //Wert Anzeigen
        Display.print(" ms       ");
        Display.txt_Height(2);                       //Texthöhe 
        Display.txt_Width(2);                        //Textweite
        Display.gfx_MoveTo(80, 280);                 //Text Position x,y
        Display.print("0");
        Display.print(" : ");
        Display.print("0");
        Display.print(" : ");
        Display.print("0");
        Display.print("      ");

        Reset1 = false;
        
        }


  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING)) //Überwachung Touch gedrückt oder bewegt

  {

    X_Pos = Display.touch_Get(TOUCH_GETX);    //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);    //Y Position auslesen

  }


  if (Status_Display == TOUCH_RELEASED)                       //Überwachung Touch Freigabe

  {

    
    if ((X_Pos >= 620) && (X_Pos <= 790) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld^

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Zrug");  //Taste anzeigen gedrückt


      if (Status_Taste)

      {

        Menue_angewaehlt = 0;       //Menü anwählen
        
        Stop_Zeit_Stoppuhr[0]= 0;  
       
        Zeiten_Stoppuhr_2[0]= 0; 

        Reset1 = true;

        Bild_aufgebaut[0] = false;  //Bildschirm aufgebaut zurücksetzen

      }

    }


    if ((X_Pos >= 320) && (X_Pos <= 500) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 350, 400, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET"); //Taste anzeigen gedrückt


      if (Status_Taste)

      {
        
        Menue_angewaehlt = 1;        //Menü anwählen

        Stop_Zeit_Stoppuhr[0]= 0;  
        
        Zeiten_Stoppuhr_2[0]= 0; 

        Reset1 = true;

        Bild_aufgebaut[1] = false;  //Bildschirm aufgebaut zurücksetzen
        
      }

    }    
        
  } 

}


void Interrupt ()

{
  



if (Stoppuhrinterrupt == true)


{
  Menue_angewaehlt = 6;                     //Menue_angewaehlt (6)
}


if (Geschwingigkeitinterrupt == true)
  {
  
    if(Geschwindigkeit_Stopp == true)
  
      {
        Menue_angewaehlt = 8;                     //Menue_angewaehlt (6) 
      }

      if(Geschwindigkeit_Stopp == false)
       {
       Menue_angewaehlt = 8;
       Geschwindigkeit_Stopp = true;
       }


  
  }

  if(Geschwingigkeitinterrupt3 == true && Interrupt_Durchschnitt == true)
  {
    Menue_angewaehlt = 11;

    Durchschnittanzahl = (Durchschnittanzahl + 1);

    Interrupt_Durchschnitt = false;
        
     
  }


}


void Interrupt2 ()

{

  

if (Stoppuhrinterrupt == true)
{
  Menue_angewaehlt = 7;                     //Menue_angewaehlt (7) 
}


if (Geschwingigkeitinterrupt2 == true)
{
  Menue_angewaehlt = 9;                     //Menue_angewaehlt (6) 

  
  if(Geschwindigkeit_Stopp2 == true)
  
      {
        Menue_angewaehlt = 9;                  
      }

      
    if(Geschwindigkeit_Stopp2 == false)
           {
           Menue_angewaehlt = 9;
           Geschwindigkeit_Stopp2 = true;
           }
      
  }

    if(Geschwingigkeitinterrupt4 == true && Interrupt_Durchschnitt2 == true)
  {
    Menue_angewaehlt = 12;

    Durchschnittanzahl2 = (Durchschnittanzahl2 + 1);

    Interrupt_Durchschnitt2 = false;
        
     
  }



}


void Geschwindigkeitsanzeige()

{
  Displaystopp = true;
Geschwingigkeitinterrupt = true;
Geschwingigkeitinterrupt2 = true;
  
if (Bild_aufgebaut[2] == false) //Überwachung Bildschirm aufgebaut

  {

    Display.gfx_Cls();                //Display löschen

    Display.gfx_Button(Status_Taste, 40, 10, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige");

    Status_Taste = BUTTON_UP;

    Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 350, 400, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset"); //Taste anzeigen ungedrückt
    Display.gfx_Rectangle(10, 70, 790, 200, AQUA); //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 120, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)
    Display.gfx_Rectangle(10, 330, 790, 200, AQUA); //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 250, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)

    Bild_aufgebaut[2] = true;                   //Bildschirm aufgebaut setzen

  }


if ((Stopp_Zeit_Geschwindigkeit== 0) && (Stopp_Zeit_Geschwindigkeit2== 0) && (Reset2 == true))

       {

       for (int i = 0; i <= 9; i++)

        {

          Zeiten_Geschwindigkeit_1[i] = 0;   //Zeiten Stoppuhr 1 0-9 zurücksetzen
          Zeiten_Geschwindigkeit_2[i] = 0;   //Zeiten Stoppuhr 2 0-9 zurücksetzen */

        }
        

        Display.txt_Height(2);                        //Texthöhe
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(580, 100);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 125);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 150);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" cpm    ");

        Display.txt_Height(4);                       //Texthöhe
        Display.txt_Width(3);                        //Textweite
        Display.txt_Inverse(OFF);                    //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);         //Textfarbe Weiss
        Display.gfx_MoveTo(80, 100);                 //Text Position x,y
        Display.print("");
        Display.print("000");         //Wert Anzeigen
        Display.print(" cpm       ");


        Display.txt_Height(2);                        //Texthöhe
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(580, 225);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 250);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 275);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" cpm    ");

        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);
        Display.gfx_MoveTo(80, 230);                  //Text Position x,y
        Display.print("");
        Display.print("000");          //Wert Anzeigen
        Display.print(" cpm       ");


        Display.txt_Height(2);              //Texthöhe
        Display.txt_Width(2);               //Textweite
        Display.gfx_MoveTo(83, 160);        //Text Position x,y
        Display.print("00");
        Display.print(" Hoechstwert  ");

        Display.txt_Height(2);              //Texthöhe
        Display.txt_Width(2);               //Textweite
        Display.gfx_MoveTo(83, 290);        //Text Position x,y
        Display.print("00");
        Display.print(" Hoechstwert  ");

        Reset2 = false;
        
        }





  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen



  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING)) //Überwachung Touch gedrückt oder bewegt

  {

    X_Pos = Display.touch_Get(TOUCH_GETX);    //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);    //Y Position auslesen

  }


  //Touch Schalter auswertung


  if (Status_Display == TOUCH_RELEASED)                       //Überwachung Touch Freigabe

  {

    
    //Touch Feld Zurück


    if ((X_Pos >= 620) && (X_Pos <= 790) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen gedrückt


      //Menü Hauptmenü anwählen


      if (Status_Taste)

      {

        Menue_angewaehlt = 0;        //Menü anwählen
        Reset2 = true;
        
        Bild_aufgebaut[0] = false;  //Bildschirm aufgebaut zurücksetzen
        
        Stopp_Zeit_Geschwindigkeit = 0;
        Stopp_Zeit_Geschwindigkeit2 = 0;

        Hoechstwert = 0;
        Hoechstwert2 = 0;
      }

    }
 if ((X_Pos >= 320) && (X_Pos <= 500) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 350, 400, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET"); //Taste anzeigen gedrückt


      if (Status_Taste)

      {
        
        Menue_angewaehlt = 2;        //Menü anwählen

        Reset2 = true;

        Bild_aufgebaut[2] = false;  //Bildschirm aufgebaut zurücksetzen
        
        Stopp_Zeit_Geschwindigkeit = 0;
        Stopp_Zeit_Geschwindigkeit2 = 0;

        Hoechstwert = 0;
        Hoechstwert2 = 0;
      }

    }
  }


}



void Geschwindigkeitsanzeige_Durchschnitt()
{
  
  Displaystopp = true;
  Geschwingigkeitinterrupt3 = true;
  Geschwingigkeitinterrupt4 = true;
  Interrupt_Durchschnitt = true;
  Interrupt_Durchschnitt2 = true;

  
  if (Bild_aufgebaut[3] == false) //Überwachung Bildschirm aufgebaut

   {

    Display.gfx_Cls();                //Display löschen

    Display.gfx_Button(Status_Taste, 40, 10, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige Durchschnitt");

    Status_Taste = BUTTON_UP;

    Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 350, 400, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset"); //Taste anzeigen ungedrückt
    Display.gfx_Rectangle(10, 70, 790, 200, AQUA); //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 120, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)
    Display.gfx_Rectangle(10, 330, 790, 200, AQUA); //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 250, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)

    Bild_aufgebaut[3] = true;                   //Bildschirm aufgebaut setzen

  }


if ((Stopp_Zeit_Geschwindigkeit3 == 0) && (Stopp_Zeit_Geschwindigkeit4 == 0) && (Reset3 == true))

       {

       for (int i = 0; i <= 9; i++)

        {

          Zeiten_Geschwindigkeit_3[i] = 0;   //Zeiten Stoppuhr 1 0-9 zurücksetzen
          Zeiten_Geschwindigkeit_3[i] = 0;   //Zeiten Stoppuhr 2 0-9 zurücksetzen */

        }
        

        Display.txt_Height(2);                        //Texthöhe
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(580, 100);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 125);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 150);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" cpm    ");

        Display.txt_Height(4);                       //Texthöhe
        Display.txt_Width(3);                        //Textweite
        Display.txt_Inverse(OFF);                    //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);         //Textfarbe Weiss
        Display.gfx_MoveTo(80, 100);                 //Text Position x,y
        Display.print("");
        Display.print("000");         //Wert Anzeigen
        Display.print(" cpm       ");


        Display.txt_Height(2);                        //Texthöhe
        Display.txt_Width(2);                         //Textweite
        Display.gfx_MoveTo(580, 225);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 250);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" cpm    ");
        Display.gfx_MoveTo(580, 275);                 //Text Position x,y
        Display.print("00");          //Wert Anzeigen
        Display.print(" cpm    ");

        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);
        Display.gfx_MoveTo(80, 230);                  //Text Position x,y
        Display.print("");
        Display.print("000");          //Wert Anzeigen
        Display.print(" cpm       ");

        Reset3 = false;
        
        }





  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen



  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING)) //Überwachung Touch gedrückt oder bewegt

  {

    X_Pos = Display.touch_Get(TOUCH_GETX);    //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);    //Y Position auslesen

  }


  //Touch Schalter auswertung


  if (Status_Display == TOUCH_RELEASED)                       //Überwachung Touch Freigabe

  {

    
    //Touch Feld Zurück


    if ((X_Pos >= 620) && (X_Pos <= 790) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen gedrückt


      //Menü Hauptmenü anwählen


      if (Status_Taste)

      {

        Menue_angewaehlt = 0;        //Menü anwählen
        Reset3 = true;
        Zeit_speichern5 = true;
        Bild_aufgebaut[0] = false;  //Bildschirm aufgebaut zurücksetzen
        
        Stopp_Zeit_Geschwindigkeit3 = 0;
        Stopp_Zeit_Geschwindigkeit4 = 0;

        Hoechstwert3 = 0;
        Hoechstwert4 = 0;
      }

    }
 if ((X_Pos >= 320) && (X_Pos <= 500) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 350, 400, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET"); //Taste anzeigen gedrückt


      if (Status_Taste)

      {
        
        Menue_angewaehlt = 10;        //Menü anwählen

        Reset3 = true;
        Zeit_speichern5 = true;
        Bild_aufgebaut[3] = false;  //Bildschirm aufgebaut zurücksetzen
        
        Stopp_Zeit_Geschwindigkeit3 = 0;
        Stopp_Zeit_Geschwindigkeit4 = 0;

        Hoechstwert3 = 0;
        Hoechstwert4 = 0;
      }

    }
  }  
}





void Analogeanzeige()

{

  Displaystopp = true;

  if (Bild_aufgebaut[6] == false) //Überwachung Bildschirm aufgebaut

   {

    Display.gfx_Cls();                //Display löschen

    Display.gfx_Button(Status_Taste, 40, 10, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Analogeanzeige");

    Status_Taste = BUTTON_UP;

    Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 350, 400, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset"); //Taste anzeigen ungedrückt
    Display.gfx_Rectangle(10, 70, 790, 280, AQUA); //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    

    Bild_aufgebaut[6] = true;                   //Bildschirm aufgebaut setzen

    

  }

  

  DruckSensor = 0;
  Max_Bar = 10;
  Max_mA = 20;
  Min_mA = 4;
  
  busVoltage = sensor219.getBusVoltage_V();
  current = sensor219.getCurrent_mA();
  power = busVoltage * (current/1000); // Calculate the Power

  DruckSensor = ((current-Min_mA)*(Max_Bar/(Max_mA-Min_mA)));       //Variable für Druck Sensor. Werte einzugeben, Max Bar, Max Strom, Min Strom

   Display.txt_Height(3);                        //Texthöhe
   Display.txt_Width(3);                         //Textweite
   Display.txt_Inverse(OFF);                     //Text invetieren
   Display.txt_Bold(OFF);
   Display.txt_Set(TEXT_COLOUR, WHITE);
   Display.gfx_MoveTo(200, 100);        //Text Position x,y
   Display.print("Spannung: ");
   Display.print(busVoltage);          //Wert Anzeigen
   Display.print(" V    ");
   Display.gfx_MoveTo(200, 150);                 //Text Position x,y
   Display.print("Strom   : ");
   Display.print(current);          //Wert Anzeigen
   Display.print(" mA    ");
   Display.gfx_MoveTo(200, 200);                 //Text Position x,y
   Display.print("Leistung: ");
   Display.print(power);          //Wert Anzeigen
   Display.print(" W     ");
   
  }    
    
    Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen

  

  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING)) //Überwachung Touch gedrückt oder bewegt

  {

    X_Pos = Display.touch_Get(TOUCH_GETX);    //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);    //Y Position auslesen

  }


  //Touch Schalter auswertung


  if (Status_Display == TOUCH_RELEASED)                       //Überwachung Touch Freigabe

  {

    
    //Touch Feld Zurück


    if ((X_Pos >= 620) && (X_Pos <= 790) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen gedrückt


      //Menü Hauptmenü anwählen


      if (Status_Taste)

      {

        Menue_angewaehlt = 0;        //Menü anwählen

        Bild_aufgebaut[0] = false;  //Bildschirm aufgebaut zurücksetzen

      }

    }
     if ((X_Pos >= 320) && (X_Pos <= 500) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;
      
      Display.gfx_Button(Status_Taste, 350, 400, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET"); //Taste anzeigen gedrückt
      

      if (Status_Taste)

      {
        Menue_angewaehlt = 3;        //Menü anwählen
        Bild_aufgebaut[6] = false;  //Bildschirm aufgebaut zurücksetzen
      }



    }
 
  }  
}



void Magnetpolanzeige()

{

 int SensorValue = digitalRead(HALL_SENSOR);
 Displaystopp = true;

  
if (Bild_aufgebaut[4] == false) //Überwachung Bildschirm aufgebaut

  {

    Display.gfx_Cls();                //Display löschen

    Display.gfx_Button(Status_Taste, 40, 10, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Magnetpolanzeige");

    Status_Taste = BUTTON_UP;

    Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 350, 400, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset"); //Taste anzeigen ungedrückt
    Display.gfx_Rectangle(10, 70, 790, 200, AQUA); //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 120, 20, RED); //Status Anzeigen roter Punkt (Kreis x,y,r)


    Bild_aufgebaut[4] = true;                   //Bildschirm aufgebaut setzen

  }


  if(SensorValue == LOW)
  {
        Display.gfx_CircleFilled(40, 120, 20, GREEN); //Status Anzeigen grüner Punkt (Kreis x,y,r)    //Display Gruener Punkt Anzeigen 
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);
        Display.gfx_MoveTo(80, 100);                  //Text Position x,y
        Display.print("  ");
        Display.print("Suedpol");          //Wert Anzeigen
        digitalWrite(2, HIGH);
        
  }

  else
  {
        Display.gfx_CircleFilled(40, 120, 20, RED); //Status Anzeigen grüner Punkt (Kreis x,y,r)    //Display Gruener Punkt Anzeigen 
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);
        Display.txt_Set(TEXT_COLOUR, WHITE);
        Display.gfx_MoveTo(80, 100);                //Text Position x,y
        Display.print("  ");
        Display.print("Nordpol");          //Wert Anzeigen
        digitalWrite(2, LOW);
  }





  

  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen



  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING)) //Überwachung Touch gedrückt oder bewegt

  {

    X_Pos = Display.touch_Get(TOUCH_GETX);    //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);    //Y Position auslesen

  }


  //Touch Schalter auswertung


  if (Status_Display == TOUCH_RELEASED)                       //Überwachung Touch Freigabe

  {

    
    //Touch Feld Zurück


    if ((X_Pos >= 620) && (X_Pos <= 790) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen gedrückt


      //Menü Hauptmenü anwählen


      if (Status_Taste)

      {

        Menue_angewaehlt = 0;        //Menü anwählen
        
        
        Bild_aufgebaut[0] = false;  //Bildschirm aufgebaut zurücksetzen

      }

    }
 if ((X_Pos >= 320) && (X_Pos <= 500) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 350, 400, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET"); //Taste anzeigen gedrückt


      if (Status_Taste)

      {
        
        Menue_angewaehlt = 4;        //Menü anwählen

   

        Bild_aufgebaut[4] = false;  //Bildschirm aufgebaut zurücksetzen
        

      }

    }
  }


}


void Einstellungen()

{

  if (Bild_aufgebaut[5] == false) //Überwachung Bildschirm aufgebaut

  {

    Display.gfx_Cls();                //Display löschen

    Display.gfx_Button(Status_Taste, 30, 10, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Einstellungen");


    //Touch
    

    Status_Taste = BUTTON_UP;
    
    Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen ungedrückt

    Bild_aufgebaut[5] = true;      //Bildschirm aufgebaut setzen

  }

  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen


  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING)) //Überwachung Touch gedrückt oder bewegt

  {

    X_Pos = Display.touch_Get(TOUCH_GETX);    //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);    //Y Position auslesen

  }


  //Touch Schalter auswertung


  if (Status_Display == TOUCH_RELEASED)                       //Überwachung Touch Freigabe

  {

    
    //Touch Feld Zurück


    if ((X_Pos >= 620) && (X_Pos <= 790) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen gedrückt


      //Menü Hauptmenü anwählen


      if (Status_Taste)

      {

        Menue_angewaehlt = 0;        //Menü anwählen

        Bild_aufgebaut[0] = false;  //Bildschirm aufgebaut zurücksetzen

      }

    }

  }

}

//****************************************************************************************************************************************

void mycallback(int ErrCode, unsigned char Errorbyte)

{

#ifdef LOG_MESSAGES

  const char*Error4DTeX_Post[] = {"OK\0", "Timeout\0", "NAK\0", "Length\0", "Invalid\0"};

  Serial.print(F("Serial 4D Library reports error "));
  Serial.print(Error4DTeX_Post[ErrCode]);


  if (ErrCode == Err4D_NAK)

  {

    Serial.print(F(" returned data= "));
    Serial.println(Errorbyte);

  }

  else

    Serial.println(F(""));

  while (1);                   //you can return here, or you can loop

#else


                               //Pin 13 has an LED connected on most Arduino boards. Just give it a name


#define led 13

  while (1)

  {

    digitalWrite(led, HIGH);   //turn the LED on (HIGH is the voltage level)
    delay(200);                //Verzögerung 200ms
    digitalWrite(led, LOW);    //turn the LED off by making the voltage LOW
    delay(200);                //Verzögerung 200ms

  }

#endif

}
