/* Durchfluss berechnung */

void Berechnung(bool Bildaufbau, bool Werte_Reset)         //Funktion Analogeanzeige
{

/********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[19] == false)           //Überwachung Bildschirm aufgebaut
  {
    Display.gfx_Cls();            //Display löschen
    Statusanzeige();              //Aufruf Funktion Statusanzeige

    Messung_Ein_Analog = false;         //Messung Ein Analogeanzeige zurücksetzen
      
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Analogeanzeige Berechnung");   //Funktion Namen anzeigen
    
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
<<<<<<< HEAD
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");     //Taste anzeigen ungedrückt
=======
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");     //Taste anzeigen ungedrückt
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                                 //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Start");                                //Taste anzeigen ungedrückt 
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                     //Taste anzeigen gedrückt
  
    /* Grafik zu Tasten anzeigen */
    Display.gfx_Triangle(520, 65, 500, 85, 540, 85, WHITE);         //Dreieck Seite hoch zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_Triangle(520, 155, 500, 135, 540, 135, WHITE);      //Dreieck Seite runter zeichnen (x, y, x2, y2, x3, y3, Farbe)   
    Display.gfx_Circle(767, 30, 22, WHITE);                         //Info Kreis zeichnen (Kreis x,y,r)
    
    /* Text anzeigen */
    Display.txt_Height(2);                      //Texthöhe
    Display.txt_Width(2);                       //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
    Display.txt_Inverse(OFF);                   //Text invetieren
    Display.txt_Bold(OFF);                      //Text fett
    
    Display.gfx_MoveTo(50, 100);                //Text Position (x,y)
    Display.print("Zaehlwert Max: ");           //Text anzeigen
    Display.gfx_MoveTo(50, 150);                //Text Position (x,y)
    Display.print("Zaehlwert Aktuel: ");        //Text anzeigen
    Display.gfx_MoveTo(50, 200);                //Text Position (x,y)
    Display.print("Aktueller Durchfluss: ");    //Text anzeigen
    Display.gfx_MoveTo(50, 250);                //Text Position (x,y)
    Display.print("Gesamt Durchfluss: ");       //Text anzeigen
    Display.gfx_MoveTo(50, 300);                //Text Position (x,y)
    Display.print("Durchschnitt: ");            //Text anzeigen
    Display.gfx_MoveTo(50, 350);                //Text Position (x,y)
    Display.print("Zeit: ");                    //Text anzeigen
    digitalWrite(DA_Versorgung_24VDC, HIGH);    //Digital Ausgang Versorgung 24VDC setzen
    delay(1000);                                //Verzögerung 1000ms           

    /* Buzzer */
    Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

    Bild_aufgebaut[19] = true;                  //Bildschirm aufgebaut setzen         
  }
/********************************************************************************************************************/

     /* Zählwert Max anzeigen */
     Display.txt_Height(2);                      //Texthöhe
     Display.txt_Width(2);                       //Textweite
     Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
     Display.txt_Inverse(OFF);                   //Text invetieren
     Display.txt_Bold(OFF);                      //Text fett
    
     Display.gfx_MoveTo(390, 100);               //Text Position (x,y)
     Display.print(Zaehlwert_Max);               //Text anzeigen
     Display.print("   ");                       //Text anzeigen

/********************************************************************************************************************/

  /* Messung durchführen */
  while (Messung_Ein_Analog == true)
  {

    current = offset_current + sensor219.getCurrent_mA();                                                                       //Strom berechnen
    Aktueller_Wert_Analog = ((current - Min_mA_Analog) * Max_Wert_Analog / (Max_mA_Analog - Min_mA_Analog));                    //Analogerwert berechnen
    Filter_Wert_Analog.Filter(Aktueller_Wert_Analog);                                                                           //Analoger Wert filtern
    
    Durchschnitt_Messung = (Durchfluss_Menge / (Zeit_Start_Messung_Minuten + (Zeit_Start_Messung_Sekunden_float / 60.00)));     //Durchfluss Druchschnitt berechnung

    if ((Merker_DE_Sensor_1 == false) && (digitalRead(DE_Sensor_1) == HIGH))
    {      
      Anzahl_Messungen_Impuls++;                    //Anzahl Impuls Messungen Option
      Durchfluss_Menge = Durchfluss_Menge + 5;      //Durchfluss Menge bestimmen 0.005 Nm3 = 5 liter
      Merker_DE_Sensor_1 = true;                    //Merker setzen
    }

    if (digitalRead(DE_Sensor_1) == LOW)
    {
      Merker_DE_Sensor_1 = false;                   //Merker zurücksetzen
    }
    
    /* Zeit berechnen */    
    Zeit_Start_Messung_Sekunden_float = ((millis() - Zeit_Start) / 1000);      //Zeit seit Start Messung
    Zeit_Start_Messung_Sekunden = Zeit_Start_Messung_Sekunden_float;           //zu int umwandeln
    
    if (Zeit_Start_Messung_Sekunden >= 60)
    {
      Zeit_Start = (millis());                          //Zeit seit Start Arduino setzen
      Zeit_Start_Messung_Minuten++;                     //Zeit Minuten nach 60s setzen
    }
    
    if (Filter_Wert_Analog.Current() >= Spitzenwert)
    {           
      Spitzenwert = Aktueller_Wert_Analog;              //Spitzenwert übernehmen    
    }

    if ((Filter_Wert_Analog.Current() <= 50) && (Spitzenwert >= 100))
    {
      Aktueller_Zaehlwert++;                                        //Aktueller Zählwert eins dazu zählen
      Gesamt_Spitzenwert = Gesamt_Spitzenwert + Spitzenwert;        //Gesamt Spitzenwert berechnen
      Spitzenwert = 0;                                              //Spitzenwert zurücksetzen
    }

     /* Aktuelle Werte anzeigen */
     Display.txt_Height(2);                         //Texthöhe
     Display.txt_Width(2);                          //Textweite
     Display.txt_Set(TEXT_COLOUR, Textfarbe);       //Textfarbe
     Display.txt_Inverse(OFF);                      //Text invetieren
     Display.txt_Bold(OFF);                         //Text fett
    
     Display.gfx_MoveTo(390, 150);                  //Text Position (x,y)
     Display.print(Aktueller_Zaehlwert);            //Text anzeigen
     Display.gfx_MoveTo(390, 200);                  //Text Position (x,y)
     Display.print(Filter_Wert_Analog.Current());   //Text anzeigen
     Display.print(" ");                            //Abstand
     Display.print("Nl/min   ");                    //Einheit anzeigen
     Display.gfx_MoveTo(390, 250);                  //Text Position (x,y)
     Display.print(Durchfluss_Menge);               //Text anzeigen
     Display.print(" ");                            //Abstand
     Display.print("l   ");                         //Einheit anzeigen
     Display.gfx_MoveTo(390, 300);                  //Text Position (x,y)
     Display.print(Durchschnitt_Messung);           //Text anzeigen
     Display.print(" ");                            //Abstand
     Display.print("Nl/min   ");                    //Einheit anzeigen
     Display.gfx_MoveTo(390, 350);                  //Text Position (x,y)
     Display.print(Zeit_Start_Messung_Minuten);     //Text anzeigen
     Display.print(" ");                            //Abstand
     Display.print("min   ");                       //Einheit anzeigen
     Display.gfx_MoveTo(500, 350);                  //Text Position (x,y)
     Display.print(Zeit_Start_Messung_Sekunden);    //Text anzeigen
     Display.print(" ");                            //Abstand
     Display.print("s   ");                         //Einheit anzeigen
     
/********************************************************************************************************************/

    /* Touch Screen handling */   
    Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen

    /* Touch Positionen auslesen */
    if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))    //Überwachung Touch gedrückt oder bewegt
    {
      X_Pos_Touch = Display.touch_Get(TOUCH_GETX);     //X Position auslesen
      Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);     //Y Position auslesen
    }

    /* Touch Freigabe */
    if ((Aktueller_Zaehlwert >= Zaehlwert_Max) || Status_Display == TOUCH_RELEASED)      //Überwachung Touch Freigabe
    {

/********************************************************************************************************************/

      /* Touch Feld abfragen [Stopp] Taste gedrückt (Doppel Taste Start/Stopp)
         Es wird die Start Taste angezeigt! */
      if ((Aktueller_Zaehlwert >= Zaehlwert_Max) || ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450)))   //Überwachung Touch Feld
      {           
        /* Touch Feld [Stopp] Taste ausführen */
        if ((Aktueller_Zaehlwert >= Zaehlwert_Max) || Status_Touch_Taste)
        { 
          Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Start");                                //Taste anzeigen gedrückt
          
<<<<<<< HEAD
          Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");     //Taste anzeigen ungedrückt
=======
          Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");     //Taste anzeigen ungedrückt
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
          Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
          Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                                 //Taste anzeigen ungedrückt 
      
          /* Messung Aus */      
          Messung_Ein_Analog = false;         //Messung Ein Analogeanzeige zurücksetzen 
          Zeit_Start = 0;                     //Zeit Start zurücksetzen     
          Zeit_Start_Impuls = 0;              //Zeit start Impuls zurücksetzten
          Spitzenwert = 0;                    //Spitzenwert zurücksetzen
          
          /* Buzzer */
          Buzzer(500);                        //Aufruf Funktion Buzzer(int Buzzer_Zeit)             
        }
      }
        
/********************************************************************************************************************/

    }

/********************************************************************************************************************/
  
  }       //Messung aktiv Ende
        
/********************************************************************************************************************/

  /* Touch Screen handling */   
  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen

  /* Touch Positionen auslesen */
  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))    //Überwachung Touch gedrückt oder bewegt
  {
    X_Pos_Touch = Display.touch_Get(TOUCH_GETX);     //X Position auslesen
    Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);     //Y Position auslesen
  }

  /* Touch Freigabe */
  if (Status_Display == TOUCH_RELEASED)      //Überwachung Touch Freigabe
  {

/********************************************************************************************************************/
    
<<<<<<< HEAD
    /* Touch Feld abfragen [Zrugg] Taste gedrückt */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrugg] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");   //Taste anzeigen gedrückt
=======
    /* Touch Feld abfragen [Zrug] Taste gedrückt */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrug] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");   //Taste anzeigen gedrückt
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e

        Gesamt_Spitzenwert = 0;                     //Gesamtspitzenwert zurücksetzen
        Spitzenwert = 0;                            //Spitzenwert zurücksetzen
        Aktueller_Zaehlwert = 0;                    //Zählwert zurücksetzen
        Anzahl_Messungen_Impuls = 0;                //Anzahl Impuls Messungen zurücksetzen Option
        Durchfluss_Menge = 0;                       //Durchfluss_Menge zurücksetzen
        Zaehlwert_Max = 1000;                       //Zählerwert auf Grundeinstellung zurücksetzen

        /* Buzzer */
        Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 3;                       //Hauptmenü anwählen
        Bild_aufgebaut[3] = false;                  //Bildschirm aufgebaut zurücksetzen
        
        digitalWrite(DA_Versorgung_24VDC, LOW);     //Digital Ausgang Versorgung 24VDC zurücksetzen  
      }
    }
    
/********************************************************************************************************************/

    /* Touch Feld abfragen [Reset] Taste gedrückt */
    if ((X_Pos_Touch >= 320) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {      
      /* Touch Feld [Reset] Taste ausführen */
      if (Status_Touch_Taste)
      {                 
        Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET");     //Taste anzeigen gedrückt
      
        /* Messwerte zurücksetzen */
        for (int i = 0; i <= 10000; i++)
        {            
          Analogwert[i] = 0;                    //Messwerte zurücksetzen
        }              

        Messungen_Analog = 0;                   //Anzahl Messungen zurücksetzen       

        Gesamt_Spitzenwert = 0;                 //Gesamtspitzenwert zurücksetzen
        Spitzenwert = 0;                        //Spitzenwert zurücksetzen
        Aktueller_Zaehlwert = 0;                //Zählwert zurücksetzen

        Anzahl_Durchschnitt_Messung  = 0;       //Anzahl Durchschnitt Messung zurücksetzen
        Durchschnitt_Messung  = 0;              //Durchschnitt Messung zurücksetzen
        Durchschnitt_Messung_Berechnung = 0;    //Durchschnitt Messung Berechnung zurücksetzen
        Zeit_Start_Messung_Sekunden = 0;        //Zeit seit Start Sekunden zurücksetzen
        Zeit_Start_Messung_Minuten = 0;         //Zeit seit Start Minuten zurücksetzen
        Anzahl_Messungen_Impuls = 0;            //Anzahl Impuls Messungen zurücksetzen
        Durchfluss_Menge = 0;                   //Durfluss Menge zurücksetzen
        Zaehlwert_Max = 1000;                   //Zählwert auf Grundeinstellungen zurücksetzen

        /* Buzzer */
        Buzzer(100);                            //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 19;                  //Menü Analogeanzeige anwählen       
        Bild_aufgebaut[19] = false;             //Bildschirm aufgebaut zurücksetzen
      }
    }
    
/********************************************************************************************************************/ 

    /* Touch Feld abfragen [Export] Taste gedrückt */
    if ((X_Pos_Touch >= 20) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {     
      /* Touch Feld [Export] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Export");                  //Taste anzeigen gedrückt 
        
        /* Datenausgabe auf USB Schnittstelle */  
   //     if (SerialUSB.available())      //Überwachung Schnittstelle verfügbar
   //     {

        /* [Export] Taste anzeigen Funktion aktiv */
        Display.gfx_Button(Status_Touch_Taste, 50, 420, GREEN, BLACK, Schrifttyp, Textbreite, Textrahmen, "Export");                   //Taste anzeigen Funktion aktiv

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
           
<<<<<<< HEAD
        for (Messungen_Analog = 0; Messungen_Analog <= 10000; Messungen_Analog++)
=======
        for (Messungen_Analog = 0; Messungen_Analog <= Anzahl_Messungen; Messungen_Analog++)
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        {  
          Analogwert[Messungen_Analog] = Aktueller_Wert_Analog;       //Messwert übergeben
          SerialUSB.println();                                 
          SerialUSB.print(Messungen_Analog);                          //Ausgabe Aktuelle Messung
          SerialUSB.print(" Messung ");                               //Ausgabe Text
          SerialUSB.print(Analogwert[Messungen_Analog]);              //Ausgabe Aktueller Messwert auf USB Schnittstelle
          SerialUSB.print(" bar");                                    //Ausgabe Text
 //         delay(Zeitraster_Messung);                                //Zeitraster (Verzögerung für nächste Messung)                
        }      
  //      }

      Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                   //Taste anzeigen ungedrückt 
                                                
      }
    }
    
/********************************************************************************************************************/

      /* Touch Feld abfragen [Start] Taste gedrückt (Doppel Taste Start/Stopp)
         Es wird die Stopp Taste angezeigt! */
      if ((Messung_Ein_Analog == false) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {     
        /* Touch Feld [Start] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 500, 420, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Stopp");                  //Taste anzeigen gedrückt 

<<<<<<< HEAD
          Display.gfx_Button(Status_Touch_Taste, 650, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Zrugg");                  //Taste anzeigen nicht drückbar
=======
          Display.gfx_Button(Status_Touch_Taste, 650, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Zrug");                  //Taste anzeigen nicht drückbar
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
          Display.gfx_Button(Status_Touch_Taste, 350, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                 //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 50, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Export");                 //Taste anzeigen nicht drückbar 

          /* Messung Ein */
          Messung_Ein_Analog = true;            //Messung Ein Analogeanzeige setzen
          Zeit_Start = millis();                //Zeit Start abgleichen aktuelle Zeit
          Zeit_Start_Impuls = millis();         //Zeit Start abgleichen aktuelle Zeit

          /* Buzzer */
          Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        }
      }
    
/********************************************************************************************************************/

<<<<<<< HEAD
=======
    /* Touch Feld abfragen [i] Taste gedrückt */
    if ((X_Pos_Touch >= 720) && (X_Pos_Touch <= 799) && (Y_Pos_Touch >= 0) && (Y_Pos_Touch <= 45))    //Überwachung Touch Feld
    {
      /* Touch Feld [i] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, GRAY, Schrifttyp, Textbreite, Textrahmen, "i");                  //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 7;                 //Menü Info anwählen
        Bild_aufgebaut[7] = false;            //Bildschirm Info aufgebaut zurücksetzen
        Letztes_Menue = 19;                   //Letztes angewähltes Menü   
        Info_Seite = 17;                      //Info Seite anwählen
      }
    }
      
/********************************************************************************************************************/

>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
    /* Touch Feld abfragen [▲] Taste gedrückt */
    if ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 35) && (Y_Pos_Touch <= 115))    //Überwachung Touch Feld
    {
      /* Touch Feld [▲] Taste ausführen */
      if (Status_Touch_Taste)
      {
        if (Zaehlwert_Max < 10000) Zaehlwert_Max++;     //Zählwert Max +1
        Hoch_Runter_Merker = false;                     //Hoch Runter Merker zurücksetzen
        Display_Gedrueckt = false;                      //Display Gedrückt zurücksetzen  

        /* Buzzer */
        Buzzer(100);                                    //Aufruf Funktion Buzzer(int Buzzer_Zeit)          
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [▼] Taste gedrückt */
    if ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 105) && (Y_Pos_Touch <= 185))    //Überwachung Touch Feld
    {    
      /* Touch Feld [▼] Taste ausführen */
      if (Status_Touch_Taste)
      {
        if (Zaehlwert_Max > 1) Zaehlwert_Max--;       //Zählwert Max -1 
        Hoch_Runter_Merker = false;                   //Hoch Runter Merker zurücksetzen
        Display_Gedrueckt = false;                    //Display Gedrückt zurücksetzen          

        /* Buzzer */
        Buzzer(100);                                  //Aufruf Funktion Buzzer(int Buzzer_Zeit)
      }
    }

/********************************************************************************************************************/  

<<<<<<< HEAD
    /* Touch Feld abfragen [i] Taste gedrückt */
    if ((X_Pos_Touch >= 720) && (X_Pos_Touch <= 799) && (Y_Pos_Touch >= 0) && (Y_Pos_Touch <= 45))    //Überwachung Touch Feld
    {
      /* Touch Feld [i] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, GRAY, Schrifttyp, Textbreite, Textrahmen, "i");                  //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 7;                 //Menü Info anwählen
        Bild_aufgebaut[7] = false;            //Bildschirm Info aufgebaut zurücksetzen
        Letztes_Menue = 19;                   //Letztes angewähltes Menü   
        Info_Seite = 19;                      //Info Seite anwählen
      }
    }
      
/********************************************************************************************************************/

=======
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
  }         //Touch Freigabe Ende

/********************************************************************************************************************/

  /* Touch Freigabe Merker */
  if (Status_Display == TOUCH_PRESSED)
  {
    Display_Gedrueckt = true;           //Display Gedrückt setzen
  }

  /* Touch Freigabe für lange Gedrückt */
  if ((Display_Gedrueckt == true) && (Status_Display != TOUCH_PRESSED))     //Überwachung Touch nicht Gedrückt
  {
    
/********************************************************************************************************************/

    /* Touch Feld abfragen [▲] Taste gedrückt */
    if ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 35) && (Y_Pos_Touch <= 115))    //Überwachung Touch Feld
    {
      /* Touch Feld [▲] Taste ausführen */
      if (Hoch_Runter_Merker == false)
      {
        Hoch_Runter_Zeit = millis();          //Hoch Runter Zeit setzen auf aktuelle arduino Zeit
        Hoch_Runter_Merker = true;            //Hoch Runter Merker setzen

        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
      }

      /* Schnelles zählen wenn 2s gedrückt */
      if (((millis() - Hoch_Runter_Zeit) >= 2000) && (Zaehlwert_Max < 10000)) Zaehlwert_Max++;     //Zählwert Max +1
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [▼] Taste gedrückt */
    if ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 105) && (Y_Pos_Touch <= 185))    //Überwachung Touch Feld
    {
      /* Touch Feld [▼] Taste ausführen */
      if (Hoch_Runter_Merker == false)
      {
        Hoch_Runter_Zeit = millis();              //Hoch Runter Zeit setzen auf aktuelle arduino Zeit
        Hoch_Runter_Merker = true;                //Hoch Runter Merker setzen

        /* Buzzer */
        Buzzer(100);                              //Aufruf Funktion Buzzer(int Buzzer_Zeit)
      }

      /* Schnelles zählen wenn 2s gedrückt */
      if (((millis() - Hoch_Runter_Zeit) >= 2000) && (Zaehlwert_Max > 1)) Zaehlwert_Max--;    //Zählwert Max -1      
    }
  }

/********************************************************************************************************************/
   
}
