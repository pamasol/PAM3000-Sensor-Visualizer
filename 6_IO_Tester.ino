/* 6.IO Tester */

void IO_Tester(bool Bildaufbau, bool Werte_Reset)         //Funktion IO Tester
{

/********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[6] == false)           //Überwachung Bildschirm aufgebaut
  {
    Display.gfx_Cls();            //Display löschen
    Statusanzeige();              //Aufruf Funktion Statusanzeige

    /* Buzzer Aus */      
    Buzzer_Ein_IO_Tester = false;           //Buzzer Ein IO Tester zurücksetzen      
      
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "IO Tester");   //Funktion Namen anzeigen
    
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");           //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                       //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 450, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Buzzer");                   //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                  //Taste anzeigen gedrückt
        
    /* Grafik anzeigen */
    Display.gfx_Rectangle(0, 70, 799, 265, Texthintergrund_Menue);        //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_Rectangle(0, 70, 300, 265, Texthintergrund_Menue);        //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_Rectangle(0, 168, 300, 265, Texthintergrund_Menue);       //Rahmen zeichnen (Rechteck x1,y1,x2,y2)

    Display.gfx_Circle(767, 30, 22, WHITE);             //Info Kreis zeichnen (Kreis x,y,r)
    
    Display.gfx_Circle(40, 120, 21, GRAY);              //Kreis zeichnen (Kreis x,y,r)
    Display.gfx_Circle(40, 215, 21, GRAY);              //Kreis zeichnen (Kreis x,y,r)

    /* Text anzeigen */
    Display.txt_Height(3);                      //Texthöhe
    Display.txt_Width(3);                       //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
    Display.txt_Inverse(OFF);                   //Text invetieren
    Display.txt_Bold(OFF);                      //Text fett
    
    Display.gfx_MoveTo(320, 100);               //Text Position (x,y)
    Display.print("Spannung: 0.00 V  ");        //Text anzeigen
    Display.gfx_MoveTo(320, 150);               //Text Position (x,y)
    Display.print("Strom   : 0.00 mA  ");       //Text anzeigen
    Display.gfx_MoveTo(320, 200);               //Text Position (x,y)
    Display.print("Leistung: 0.00 W  ");        //Text anzeigen

    Display.gfx_MoveTo(80, 102);                //Text Position (x,y)
    Display.print("Sensor 1");                  //Text anzeigen
    Display.gfx_MoveTo(80, 200);                //Text Position (x,y)
    Display.print("Sensor 2");                  //Text anzeigen

    digitalWrite(DA_Versorgung_24VDC, HIGH);    //Digital Ausgang Versorgung 24VDC setzen
    delay(1000);                                //Verzögerung 1000ms 
    
    current = 0;
    
    /* Buzzer */
    Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit) 
         
    Bild_aufgebaut[6] = true;                   //Bildschirm aufgebaut setzen    
  }

/********************************************************************************************************************/
  
  Statusanzeige();              //Aufruf Funktion Statusanzeige
  
/********************************************************************************************************************/

  if ((sensor219.getCurrent_mA()>=current+0.5)||(sensor219.getCurrent_mA()<=current-0.5)||(sensor219.getBusVoltage_V()>=busVoltage+0.5)||(sensor219.getBusVoltage_V()<=busVoltage-0.5))   
  {   
    Min_mA_Analog = 4;                          //Wert eintragen von Min Strom ausgabe von Sensor
    Max_mA_Analog = 20;                         //Wert eintragen vom Max Strom ausgabe von Sensor
    Max_Wert_Analog = 20;                       //Wert eintragen von Max bar Wert bei Sensor
      
    busVoltage = sensor219.getBusVoltage_V();  //Ausgabe Sensorwert
    current = sensor219.getCurrent_mA();       //Ausgabe Sensorwert
    power = busVoltage * (current/1000);       //Leistung Ausrechnen

    /* Drucksensor berechnung */   
    Aktueller_Wert_Analog = ((current - Min_mA_Analog) * Max_Wert_Analog / (Max_mA_Analog - Min_mA_Analog));       //Variable für Druck Sensor. Werte einzugeben, Max bar, Max Strom, Min Strom

    Display.txt_Height(3);                      //Texthöhe
    Display.txt_Width(3);                       //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
    Display.txt_Inverse(OFF);                   //Text invetieren
    Display.txt_Bold(OFF);                      //Text fett
    
    Display.gfx_MoveTo(320, 100);               //Text Position (x,y)
    Display.print("Spannung: ");                //Text anzeigen
    Display.print(busVoltage);                  //Wert anzeigen
    Display.print(" V  ");                      //Text anzeigen
    Display.gfx_MoveTo(320, 150);               //Text Position (x,y)
    Display.print("Strom   : ");                //Text anzeigen
    Display.print(current);                     //Wert anzeigen
    Display.print(" mA  ");                     //Text anzeigen
    Display.gfx_MoveTo(320, 200);               //Text Position (x,y)
    Display.print("Leistung: ");                //Text anzeigen
    Display.print(power);                       //Wert anzeigen
    Display.print(" W  ");                      //Text anzeigen
  }   

/********************************************************************************************************************/

  /* Test Digital Eingang 1 */
  if (digitalRead(DE_Sensor_1) == HIGH)
  {               
    /* Grüner Punkt anzeigen */
    Display.gfx_CircleFilled(40, 120, 20, GREEN);         //Status anzeigen grüner Punkt (Kreis x,y,r)
  }  
  else
  {                   
    /* Roter Punkt anzeigen */
    Display.gfx_CircleFilled(40, 120, 20, RED);         //Status anzeigen roter Punkt (Kreis x,y,r)        
  }

/********************************************************************************************************************/

  /* Test Digital Eingang 2 */
  if (digitalRead(DE_Sensor_2) == HIGH)
  {               
    /* Grüner Punkt anzeigen */
    Display.gfx_CircleFilled(40, 215, 20, GREEN);       //Status anzeigen grüner Punkt (Kreis x,y,r)   
  }
  else
  {                 
    /* Roter Punkt anzeigen */
    Display.gfx_CircleFilled(40, 215, 20, RED);         //Status anzeigen roter Punkt (Kreis x,y,r)
  }

/********************************************************************************************************************/

  /* Buzzer */
  if ((digitalRead(DE_Sensor_1) == HIGH) || (digitalRead(DE_Sensor_2) == HIGH))
  {   
    /* Buzzer Ein */
    if (Buzzer_Ein_IO_Tester == true) digitalWrite(DA_Buzzer, HIGH);      //Digital Ausgang Buzzer setzen              
  }  
  else
  {    
    /* Buzzer Aus */
    digitalWrite(DA_Buzzer, LOW);                                         //Digital Ausgang Buzzer zurücksetzen 
  }

/********************************************************************************************************************/

  /* Doppeltaste Goto */
  Doppeltaste_Betaetigt:                     //Doppeltaste Goto
  
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
    
    /* Touch Feld abfragen [Zrug] Taste gedrückt */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrug] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");   //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 0;                         //Hauptmenü anwählen
        Bild_aufgebaut[0] = false;                    //Bildschirm aufgebaut zurücksetzen

        digitalWrite(DA_Versorgung_24VDC, LOW);       //Digital Ausgang Versorgung 24VDC zurücksetzen  
      }
    }
    
/********************************************************************************************************************/

    /* Touch Feld abfragen [Reset] Taste gedrückt */
    if ((X_Pos_Touch >= 320) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {     
      /* Touch Feld [Reset] Taste ausführen */
      if (Status_Touch_Taste)
      {         
        Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET");                   //Taste anzeigen gedrückt
    
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 6;                 //Menü Analogeanzeige anwählen       
        Bild_aufgebaut[6] = false;            //Bildschirm aufgebaut zurücksetzen
      }
    }
    
/********************************************************************************************************************/ 

    /* Touch Feld abfragen [Buzzer] Taste gedrückt (Doppel Taste Buzzer Ein/Aus)
       Es wird die Stopp Taste angezeigt! */
    if ((Buzzer_Ein_IO_Tester == false) && (X_Pos_Touch >= 420) && (X_Pos_Touch <= 550) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {     
      /* Touch Feld [Buzzer] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 450, 420, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Buzzer");                  //Taste anzeigen gedrückt         
        
        /* Buzzer Ein */
        Buzzer_Ein_IO_Tester = true;            //Buzzer Ein IO Tester setzen
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        /* Umschaltverzögerung */
        delay(500);                             //Verzögerung 500ms

        /* Doppeltaste Auschaltverhinderung bis erneut gedrückt */
        goto Doppeltaste_Betaetigt;       //Doppeltaste betätigt
      }
    }
    
/********************************************************************************************************************/

    /* Touch Feld abfragen [Buzzer] Taste gedrückt (Doppel Taste Buzzer Ein/Aus)
       Es wird die Start Taste angezeigt! */
    if ((Buzzer_Ein_IO_Tester == true) && (X_Pos_Touch >= 420) && (X_Pos_Touch <= 550) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {      
      /* Touch Feld [Buzzer] Taste ausführen */
      if (Status_Touch_Taste)
      { 
        Display.gfx_Button(Status_Touch_Taste, 450, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Buzzer");                  //Taste anzeigen gedrückt
        
        /* Buzzer Aus */      
        Buzzer_Ein_IO_Tester = false;           //Buzzer Ein IO Tester zurücksetzen      
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        /* Umschaltverzögerung */
        delay(500);                             //Verzögerung 500ms     

        /* Doppeltaste Auschaltverhinderung bis erneut gedrückt */
        goto Doppeltaste_Betaetigt;       //Doppeltaste betätigt                         
      }
    }
    
/********************************************************************************************************************/

    /* Touch Feld abfragen [i] Taste gedrückt */
    if ((X_Pos_Touch >= 720) && (X_Pos_Touch <= 799) && (Y_Pos_Touch >= 0) && (Y_Pos_Touch <= 45))    //Überwachung Touch Feld
    {
      /* Touch Feld [i] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, GRAY, Schrifttyp, Textbreite, Textrahmen, "i");                  //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 7;               //Menü Info anwählen
        Bild_aufgebaut[7] = false;          //Bildschirm Info aufgebaut zurücksetzen
        Letztes_Menue = 6;                  //Letztes angewähltes Menü   
      }
    }

/********************************************************************************************************************/
   
  }         //Touch Freigabe Ende

/********************************************************************************************************************/
    
}
