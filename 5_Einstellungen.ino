/*        5.Einstellungen
   Einstellungen hat momentan noch keine Funktion!
*/

void Einstellungen(bool Bildaufbau, bool Werte_Reset)          //Funktion Einstellungen
{

/********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[5] == false)                    //Überwachung Bildschirm aufgebaut
  {
    Display.gfx_Cls();            //Display löschen
    Statusanzeige();              //Aufruf Funktion Statusanzeige

    /* Aktuelle Uhzeit übernehmen als Vorgabe zur Einstellung */
    Stunden = Uhr.hour;
    Minuten = Uhr.minute;    
    Sekunden = 0; //Uhr.second;
    Wochentag = Uhr.dayOfWeek;

    switch (Uhr.dayOfWeek)      //Wochentag wandeln
    {
      case MON:             //Montag
        Wochentag_Nr = 1;   
        break;
      
      case TUE:             //Dienstag
        Wochentag_Nr = 2;   
        break;
      
      case WED:             //Mittwoch
        Wochentag_Nr = 3;
        break;
      
      case THU:             //Donnerstag
        Wochentag_Nr = 4;
        break;
      
      case FRI:             //Freitag
        Wochentag_Nr = 5;
        break;
      
      case SAT:             //Samstag
        Wochentag_Nr = 6;
        break;
      
      case SUN:             //Sonntag
        Wochentag_Nr = 7;
        break;
    }
   
    Monat = Uhr.month;
    Tag = Uhr.dayOfMonth;
    Jahr = Uhr.year+2000;
     
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Einstellungen");  //Funktion Namen anzeigen

    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 

    if (Zeit_Button == false)
    {
      /* Touch Tasten ungedrückt anzeigen */
      Status_Touch_Taste = BUTTON_UP;   
      Display.gfx_Button(Status_Touch_Taste, 30, 90, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "I2C Scanner");    //Taste anzeigen ungedrückt
      Display.gfx_Button(Status_Touch_Taste, 30, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Zeit");          //Taste anzeigen ungedrückt
    
<<<<<<< HEAD
      /* Buzzer eingeschalten */
      if (Buzzer_Einstellungen == 1)      //Überwachung Buzzer eingeschalten
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 210, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Buzzer");    //Taste anzeigen ungedrückt
      }
      
      /* Buzzer ausgeschalten */
=======
      if (Buzzer_Einstellungen == 0)
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 210, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Buzzer");    //Taste anzeigen ungedrückt
      }
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      else
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 210, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Buzzer");    //Taste anzeigen ungedrückt
      }

<<<<<<< HEAD
      /* Buzzer ausgeschalten oder maximum Lautstärke */
      if ((Buzzer_Einstellungen == 0) || (Buzzer_Lautstaerke == 255))        //Überwachung Buzzer maximum Lautstärke
      {
        Display.gfx_Button(Status_Touch_Taste, 240, 210, GRAY, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");     //Taste nicht drückbar anzeigen 
      }
      
      /* Buzzer eingeschalten und nicht maximum Lautstärke */
=======
      if (Buzzer_Lautstaerke == 255)
      {
        Display.gfx_Button(Status_Touch_Taste, 240, 210, GRAY, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");     //Taste anzeigen 
      }
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      else
      {
        Display.gfx_Button(Status_Touch_Taste, 240, 210, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");     //Taste anzeigen ungedrückt
      }
<<<<<<< HEAD

      /* Buzzer ausgeschalten oder minimum Lautstärke */
      if ((Buzzer_Einstellungen == 0) || (Buzzer_Lautstaerke == 5))        //Überwachung Buzzer minimum Lautstärke
      {
        Display.gfx_Button(Status_Touch_Taste, 150, 210, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, " - ");     //Taste nicht drückbar anzeigen 
      }  

      /* Buzzer eingeschalten und nicht minimum Lautstärke */
=======
      
      if (Buzzer_Lautstaerke == 5)
      {
        Display.gfx_Button(Status_Touch_Taste, 150, 210, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, " - ");     //Taste anzeigen 
      }  
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      else
      {
        Display.gfx_Button(Status_Touch_Taste, 150, 210, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");     //Taste anzeigen ungedrückt
      }
    }
    
<<<<<<< HEAD
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");          //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                           //Taste anzeigen gedrückt
=======
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");         //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                         //Taste anzeigen gedrückt
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
    
    if (Zeit_Button == true)
    {
      Display.gfx_Button(Status_Touch_Taste, 95, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");        //Taste anzeigen ungedrückt (+ Stunden)
      Display.gfx_Button(Status_Touch_Taste, 95, 250, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");        //Taste anzeigen ungedrückt (- Stunden)
      Display.gfx_Button(Status_Touch_Taste, 170, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");       //Taste anzeigen ungedrückt (+ Minuten)
      Display.gfx_Button(Status_Touch_Taste, 170, 250, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");       //Taste anzeigen ungedrückt (- Minuten)
      Display.gfx_Button(Status_Touch_Taste, 340, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");       //Taste anzeigen ungedrückt (+ Tag)
      Display.gfx_Button(Status_Touch_Taste, 340, 250, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");       //Taste anzeigen ungedrückt (- Tag)   
      Display.gfx_Button(Status_Touch_Taste, 415, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");       //Taste anzeigen ungedrückt (+ Monat)
      Display.gfx_Button(Status_Touch_Taste, 415, 250, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");       //Taste anzeigen ungedrückt (- Monat)   
      Display.gfx_Button(Status_Touch_Taste, 505, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");       //Taste anzeigen ungedrückt (+ Jahr)
      Display.gfx_Button(Status_Touch_Taste, 505, 250, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");       //Taste anzeigen ungedrückt (- Jahr)   
      Display.gfx_Button(Status_Touch_Taste, 625, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");       //Taste anzeigen ungedrückt (+ Wochentag)
      Display.gfx_Button(Status_Touch_Taste, 625, 250, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");       //Taste anzeigen ungedrückt (- Wochentag)   
      Display.gfx_Button(Status_Touch_Taste, 95, 320, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Set");        //Taste anzeigen ungedrückt
    }

    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);             //Info Kreis zeichnen (Kreis x,y,r)
    
    Bild_aufgebaut[5] = true;                          //Bildschirm aufgebaut setzen
  }

/********************************************************************************************************************/
  
  Statusanzeige();              //Aufruf Funktion Statusanzeige
  
/********************************************************************************************************************/

  if (Zeit_Button == true)
  {
    /* Zeit einstellen */
    Uhr.getTime();                          //Aktuelle Zeit lesen

    /* Zeit anzeigen */
    Display.txt_Height(3);                            //Texthöhe
    Display.txt_Width(3);                             //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);          //Textfarbe

<<<<<<< HEAD
    Display.gfx_MoveTo(100, 200);                     //Text Position (x,y)
=======
    Display.gfx_MoveTo(100, 200);               //Text Position (x,y)
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e

    /* Zeit */
    if (Stunden < 10) Display.print("0");       //Bei einstelligen Zahlen eine 0 davor stellen  
    Display.print(Stunden, DEC); 
    Display.print(":");
    if (Minuten < 10) Display.print("0");       //Bei einstelligen Zahlen eine 0 davor stellen
    Display.print(Minuten, DEC);
    Display.print(":");
    if (Sekunden < 10) Display.print("0");       //Bei einstelligen Zahlen eine 0 davor stellen  
    Display.print(Sekunden, DEC);

    /* Datum */
    Display.print("  ");   
    if (Tag < 10) Display.print("0");           //Bei einstelligen Zahlen eine 0 davor stellen
    Display.print(Tag, DEC);
    Display.print("/");
    if (Monat < 10) Display.print("0");         //Bei einstelligen Zahlen eine 0 davor stellen
    Display.print(Monat, DEC);
    Display.print("/");
    Display.print(Jahr, DEC);
    Display.print("  ");
  
    /* Wochentag anzeigen */
    switch (Wochentag_Nr)      //Wochentag anzeigen
    {
      case 1:                  //Montag
        Display.print("Mo");
        break;
      
      case 2:                 //Dienstag
        Display.print("Di");
        break;
      
      case 3:                 //Mittwoch
        Display.print("Mi");
        break;
      
      case 4:                 //Donnerstag
        Display.print("Do");
        break;
      
      case 5:                 //Freitag
        Display.print("Fr");
        break;
      
      case 6:                 //Samstag
        Display.print("Sa");
        break;
      
      case 7:                 //Sonntag
        Display.print("So");
        break;
    }
  }
  
/********************************************************************************************************************/
    
  /* Doppeltaste Goto */
  Doppeltaste_Betaetigt:                     //Doppeltaste Goto
  
  /* Touch Screen handling */
  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen

  /* Touch Positionen auslesen */
  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))      //Überwachung Touch gedrückt oder bewegt
  {
    X_Pos_Touch = Display.touch_Get(TOUCH_GETX);            //X Position auslesen
    Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);            //Y Position auslesen
  }

  /* Touch Freigabe */
  if (Status_Display == TOUCH_RELEASED)             //Überwachung Touch Freigabe
  {

/********************************************************************************************************************/
    
<<<<<<< HEAD
    /* Touch Feld abfragen [Zrugg] Taste gedrückt */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))     //Überwachung Touch Feld
    {
      /* Touch Feld [Zrugg] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");   //Taste anzeigen gedrückt
=======
    /* Touch Feld abfragen [Zrug] Taste gedrückt */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))     //Überwachung Touch Feld
    {
      /* Touch Feld [Zrug] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");   //Taste anzeigen gedrückt
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e

        if (Zeit_Button == false)
        {
          Menue_angewaehlt = 0;                         //Hauptmenü anwählen
          Bild_aufgebaut[0] = false;                    //Bildschirm aufgebaut zurücksetzen       
        }
        
        if (Zeit_Button == true)
        {
          Zeit_Button = false;                          //Zeit Button zurücksetzen
          Bild_aufgebaut[5] = false;                    //Bildschirm aufgebaut zurücksetzen        
        }

        /* Buzzer */
        Buzzer(100);        //Aufruf Funktion Buzzer(int Buzzer_Zeit)        
      }
    }
    
/********************************************************************************************************************/

    /* Touch Feld abfragen [I2C Scanner] Taste gedrückt */
    if ((Zeit_Button == false) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 130) && (Y_Pos_Touch >= 60) && (Y_Pos_Touch <= 120))     //Überwachung Touch Feld
    {
      /* Touch Feld [I2C Scanner] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 90, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, "I2C Scanner");   //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);        //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        /* I2C Scanner */
        I2C_Scanner();      //Aufruf Funktion I2C Scanner
        
        delay(1000);  //Verzögerung 1000ms
        Display.gfx_Button(Status_Touch_Taste, 30, 90, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "I2C Scanner");   //Taste anzeigen ungedrückt        
      }
    }
    
/********************************************************************************************************************/

    /* Touch Feld abfragen [Zeit] Taste gedrückt */
    if ((Zeit_Button == false) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 130) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [Zeit] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 150, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Zeit");   //Taste anzeigen gedrückt

        Bild_aufgebaut[5] = false;            //Bild Aufgebaut zurücksetzen
        Zeit_Button = true;                   //Zeit Button gesetzt
  
        /* Buzzer */
        Buzzer(100);        //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Display.gfx_Button(Status_Touch_Taste, 30, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Zeit");   //Taste anzeigen ungedrückt        
      }
    }
    
/********************************************************************************************************************/

    /* Touch Feld abfragen [Buzzer] Taste gedrückt */
<<<<<<< HEAD
    if ((Buzzer_Einstellungen == 1) && (Zeit_Button == false) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 130) && (Y_Pos_Touch >= 180) && (Y_Pos_Touch <= 240))     //Überwachung Touch Feld
=======
    if ((Buzzer_Einstellungen == 0) && (Zeit_Button == false) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 130) && (Y_Pos_Touch >= 180) && (Y_Pos_Touch <= 240))     //Überwachung Touch Feld
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
    {
      /* Touch Feld [Buzzer] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 210, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Buzzer");   //Taste anzeigen gedrückt

<<<<<<< HEAD
        Display.gfx_Button(Status_Touch_Taste, 150, 210, GRAY, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste nicht drückbar anzeigen
        Display.gfx_Button(Status_Touch_Taste, 240, 210, GRAY, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste nicht drückbar anzeigen
          
        /* Buzzer */
        Buzzer(100);                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        Buzzer_Einstellungen = 0;         //Buzzer Einstellungen zurücksetzen
=======
        /* Buzzer */
        Buzzer(100);                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        Buzzer_Einstellungen = 1;      //Buzzer Einstellungen setzen
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e

        /* Buzzer Ein/Aus auf SD Karte schreiben */
        SD.remove("Settings/buzzer.txt");                                               //buzzer File löschen
        File buzzer = SD.open("Settings/buzzer.txt", FILE_WRITE);                       //buzzer File in Ordner Settings im Schreibmodus auf SD Karte öffnen
        Buzzer_Ein_Aus_String = String(Buzzer_Einstellungen);                           //Buzzer Ein/Aus an String anhängen     
     
        if (buzzer) 
        {
          buzzer.println("Buzzer_Ein/Aus:" + Buzzer_Ein_Aus_String);                    //Buzzer Ein/Aus auf SD Karte schreiben
          buzzer.println("Buzzer_Lautstaerke:" + Buzzer_Lautstaerke_String);            //Buzzer Lautstärke auf SD Karte schreiben
          buzzer.close();                                                               //File schliessen
        }         

        /* Doppeltaste Auschaltverhinderung bis erneut gedrückt */
        goto Doppeltaste_Betaetigt;       //Doppeltaste betätigt       
      }
    }
    
/********************************************************************************************************************/

    /* Touch Feld abfragen [Buzzer] Taste gedrückt */
<<<<<<< HEAD
    if ((Buzzer_Einstellungen == 0) && (Zeit_Button == false) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 130) && (Y_Pos_Touch >= 180) && (Y_Pos_Touch <= 240))     //Überwachung Touch Feld
=======
    if ((Buzzer_Einstellungen == 1) && (Zeit_Button == false) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 130) && (Y_Pos_Touch >= 180) && (Y_Pos_Touch <= 240))     //Überwachung Touch Feld
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
    {
      /* Touch Feld [Buzzer] Taste ausführen */
      if (Status_Touch_Taste)
      {
<<<<<<< HEAD
        Display.gfx_Button(Status_Touch_Taste, 30, 210, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Buzzer");   //Taste anzeigen gedrückt

        Display.gfx_Button(Status_Touch_Taste, 150, 210, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste drückbar anzeigen
        Display.gfx_Button(Status_Touch_Taste, 240, 210, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste drückbar anzeigen

        /* Buzzer */
        Buzzer_Einstellungen = 1;           //Buzzer Einstellungen setzen
        Buzzer(100);                        //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        /* Buzzer Ein/Aus auf SD Karte schreiben */
        SD.remove("Settings/buzzer.txt");                                               //Buzzer File löschen
        File buzzer = SD.open("Settings/buzzer.txt", FILE_WRITE);                       //Buzzer File in Ordner Settings im Schreibmodus auf SD Karte öffnen
=======
        Display.gfx_Button(Status_Touch_Taste, 30, 210, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Buzzer");   //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer_Einstellungen = 0;           //Buzzer Einstellungen zurücksetzen
        Buzzer(100);                        //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        /* Buzzer Ein/Aus auf SD Karte schreiben */
        SD.remove("Settings/buzzer.txt");                                               //buzzer File löschen
        File buzzer = SD.open("Settings/buzzer.txt", FILE_WRITE);                       //buzzer File in Ordner Settings im Schreibmodus auf SD Karte öffnen
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        Buzzer_Ein_Aus_String = String(Buzzer_Einstellungen);                           //Buzzer Ein/Aus an String anhängen     
     
        if (buzzer) 
        {
          buzzer.println("Buzzer_Ein/Aus:" + Buzzer_Ein_Aus_String);                    //Buzzer Ein/Aus auf SD Karte schreiben
          buzzer.println("Buzzer_Lautstaerke:" + Buzzer_Lautstaerke_String);            //Buzzer Lautstärke auf SD Karte schreiben
          buzzer.close();                                                               //File schliessen
        }         
        
        /* Doppeltaste Auschaltverhinderung bis erneut gedrückt */
        goto Doppeltaste_Betaetigt;       //Doppeltaste betätigt       
      }
    }
    
/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [-] Taste gedrückt (Buzzer) */
    if ((Buzzer_Einstellungen == 1) && (Zeit_Button == false) && (X_Pos_Touch >= 140) && (X_Pos_Touch <= 230) && (Y_Pos_Touch >= 180) && (Y_Pos_Touch <= 240))     //Überwachung Touch Feld
    {
      /* Touch Feld [-] Taste ausführen (Buzzer) */
      if (Status_Touch_Taste)
      {

        if (Buzzer_Lautstaerke != 5)          //Überwachung Buzzer Lautstärke
=======
    /* Touch Feld abfragen [ - Buzzer] Taste gedrückt */
    if ((Zeit_Button == false) && (X_Pos_Touch >= 140) && (X_Pos_Touch <= 230) && (Y_Pos_Touch >= 180) && (Y_Pos_Touch <= 240))     //Überwachung Touch Feld
    {
      /* Touch Feld [ - Buzzer] Taste ausführen */
      if (Status_Touch_Taste)
      {

        if (Buzzer_Lautstaerke != 5)
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        {
          Display.gfx_Button(Status_Touch_Taste, 150, 210, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen gedrückt
          Display.gfx_Button(Status_Touch_Taste, 240, 210, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen gedrückt
                 
<<<<<<< HEAD
          if ((Buzzer_Lautstaerke <= 255) && (Buzzer_Lautstaerke > 115))      //Überwachung Buzzer Lautstärke
          {
            Buzzer_Lautstaerke = 125;                                         //Verstellwert Buzzer guter Ton
          }
          
          /* Buzzer */
          Buzzer_Lautstaerke = (Buzzer_Lautstaerke - 10);       //Buzzer Lautstärke reduzieren
=======
          if ((Buzzer_Lautstaerke <= 255) && (Buzzer_Lautstaerke > 115))
          {
            Buzzer_Lautstaerke = 125;                           //Verstellwert Buzzer guter Ton
          }
          
          /* Buzzer */
          Buzzer_Lautstaerke = (Buzzer_Lautstaerke -10);        //Buzzer Lautstärke reduzieren
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
          Buzzer(100);                                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          Display.gfx_Button(Status_Touch_Taste, 150, 210, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen gedrückt
        }
        
<<<<<<< HEAD
        if (Buzzer_Lautstaerke <= 5)        //Überwachung Buzzer Lautstärke
        {
          Buzzer_Lautstaerke = 5;           //Verstellwert begrenzen
          Display.gfx_Button(Status_Touch_Taste, 150, 210, GRAY, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste nicht drückbar anzeigen
=======
        if (Buzzer_Lautstaerke <= 5)
        {
          Buzzer_Lautstaerke = 5;                               //Verstellwert begrenzen
          Display.gfx_Button(Status_Touch_Taste, 150, 210, GRAY, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        }   
        
        /* Buzzer Lautstärke auf SD Karte schreiben */
        SD.remove("Settings/buzzer.txt");                                               //buzzer File löschen
        File buzzer = SD.open("Settings/buzzer.txt", FILE_WRITE);                       //buzzer File in Ordner Settings im Schreibmodus auf SD Karte öffnen
        Buzzer_Lautstaerke_String = String(Buzzer_Lautstaerke);                         //Buzzer Lautstärke an String anhängen     
     
        if (buzzer) 
        {
          buzzer.println("Buzzer_Ein/Aus:" + Buzzer_Ein_Aus_String);                    //Buzzer Ein/Aus auf SD Karte schreiben
          buzzer.println("Buzzer_Lautstaerke:" + Buzzer_Lautstaerke_String);            //Buzzer Lautstärke auf SD Karte schreiben
          buzzer.close();                                                               //File schliessen
        }  
      }
    }
    
/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [+] Taste gedrückt (Buzzer) */
    if ((Buzzer_Einstellungen == 1) && (Zeit_Button == false) && (X_Pos_Touch >= 230) && (X_Pos_Touch <= 320) && (Y_Pos_Touch >= 180) && (Y_Pos_Touch <= 240))     //Überwachung Touch Feld
    {
      /* Touch Feld [+] Taste ausführen (Buzzer) */
      if (Status_Touch_Taste)
      {
 
        if (Buzzer_Lautstaerke != 255)    //Überwachung Buzzer Lautstärke
=======
    /* Touch Feld abfragen [ + Buzzer] Taste gedrückt */
    if ((Zeit_Button == false) && (X_Pos_Touch >= 230) && (X_Pos_Touch <= 320) && (Y_Pos_Touch >= 180) && (Y_Pos_Touch <= 240))     //Überwachung Touch Feld
    {
      /* Touch Feld [ + Buzzer] Taste ausführen */
      if (Status_Touch_Taste)
      {
 
        if (Buzzer_Lautstaerke != 255)
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        {
          Display.gfx_Button(Status_Touch_Taste, 240, 210, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen gedrückt
          Display.gfx_Button(Status_Touch_Taste, 150, 210, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen gedrückt
         
<<<<<<< HEAD
          if ((Buzzer_Lautstaerke < 255) && (Buzzer_Lautstaerke >= 115))      //Überwachung Buzzer Lautstärke
=======
          if ((Buzzer_Lautstaerke < 255) && (Buzzer_Lautstaerke >= 115))
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
          {
            Buzzer_Lautstaerke = 245;                           //Verstellwert Buzzer guter Ton
          }
          
          /* Buzzer */
          Buzzer_Lautstaerke = (Buzzer_Lautstaerke + 10);       //Buzzer Lautstärke erhöhen
          Buzzer(100);                                          //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

          Display.gfx_Button(Status_Touch_Taste, 240, 210, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen gedrückt
        }
       
<<<<<<< HEAD
        if (Buzzer_Lautstaerke >= 255)    //Überwachung Buzzer Lautstärke
        {
          Buzzer_Lautstaerke = 255;       //Verstellwert begrenzen
          Display.gfx_Button(Status_Touch_Taste, 240, 210, GRAY, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste nicht drückbar anzeigen
=======
        if (Buzzer_Lautstaerke >= 255)
        {
          Buzzer_Lautstaerke = 255;                             //Verstellwert begrenzen
          Display.gfx_Button(Status_Touch_Taste, 240, 210, GRAY, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        } 
        
        /* Buzzer Lautstärke auf SD Karte schreiben */
        SD.remove("Settings/buzzer.txt");                                               //buzzer File löschen
        File buzzer = SD.open("Settings/buzzer.txt", FILE_WRITE);                       //buzzer File in Ordner Settings im Schreibmodus auf SD Karte öffnen  
        Buzzer_Lautstaerke_String = String(Buzzer_Lautstaerke);                         //Buzzer Lautstärke an String anhängen     

        if (buzzer) 
        {
          buzzer.println("Buzzer_Ein/Aus:" + Buzzer_Ein_Aus_String);                    //Buzzer Ein/Aus auf SD Karte schreiben
          buzzer.println("Buzzer_Lautstaerke:" + Buzzer_Lautstaerke_String);            //Buzzer Lautstärke auf SD Karte schreiben
          buzzer.close();                                                               //File schliessen
        } 
      }
    }
    
/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [+] Taste gedrückt (Stunden) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 95) && (X_Pos_Touch <= 145) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [+] Taste ausführen (Stunden) */
=======
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
        Letztes_Menue = 5;                  //Letztes angewähltes Menü   
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [ + ] Taste gedrückt (+ Stunden) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 95) && (X_Pos_Touch <= 145) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [ + ] Taste ausführen (+ Stunden) */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 95, 150, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen gedrückt

        Stunden++;
        if (Stunden > 23) Stunden = 0;        //Verstellwert begrenzen
        
        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 95, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen ungedrückt          
      }
    }

/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [-] Taste gedrückt (Stunden) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 95) && (X_Pos_Touch <= 145) && (Y_Pos_Touch >= 220) && (Y_Pos_Touch <= 280))     //Überwachung Touch Feld
    {
      /* Touch Feld [-] Taste ausführen (Stunden) */
=======
    /* Touch Feld abfragen [ - ] Taste gedrückt (- Stunden) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 95) && (X_Pos_Touch <= 145) && (Y_Pos_Touch >= 220) && (Y_Pos_Touch <= 280))     //Überwachung Touch Feld
    {
      /* Touch Feld [ - ] Taste ausführen (- Stunden) */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 95, 250, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen gedrückt

        Stunden--;
        
        if (Stunden < 0) Stunden = 23;        //Verstellwert begrenzen
                
        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 95, 250, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen ungedrückt         
      }
    }

/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [+] Taste gedrückt (Minuten) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 170) && (X_Pos_Touch <= 220) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [+] Taste ausführen (Minuten) */
=======
    /* Touch Feld abfragen [ + ] Taste gedrückt (+ Minuten) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 170) && (X_Pos_Touch <= 220) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [ + ] Taste ausführen (+ Minuten) */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 170, 150, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen gedrückt

        Minuten++;
        if (Minuten > 59) Minuten = 0;    //Verstellwert begrenzen
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 170, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen ungedrückt         
      }
    }

/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [-] Taste gedrückt (Minuten) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 170) && (X_Pos_Touch <= 220) && (Y_Pos_Touch >= 220) && (Y_Pos_Touch <= 280))     //Überwachung Touch Feld
    {
      /* Touch Feld [-] Taste ausführen (Minuten) */
=======
    /* Touch Feld abfragen [ - ] Taste gedrückt (- Minuten) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 170) && (X_Pos_Touch <= 220) && (Y_Pos_Touch >= 220) && (Y_Pos_Touch <= 280))     //Überwachung Touch Feld
    {
      /* Touch Feld [ - ] Taste ausführen (- Minuten) */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 170, 250, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen gedrückt

        Minuten--;
        if (Minuten < 0) Minuten = 59;      //Verstellwert begrenzen
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 170, 250, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen ungedrückt          
      }
    }

/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [+] Taste gedrückt (Tag) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 340) && (X_Pos_Touch <= 390) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [+] Taste ausführen (Tag) */
=======
    /* Touch Feld abfragen [ + ] Taste gedrückt (+ Tag) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 340) && (X_Pos_Touch <= 390) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [ + ] Taste ausführen (+ Tag) */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 340, 150, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen gedrückt

        Tag++;
        if (Tag > 31) Tag = 1;    //Verstellwert begrenzen
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 340, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen ungedrückt       
      }
    }

/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [-] Taste gedrückt (Tag) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 340) && (X_Pos_Touch <= 390) && (Y_Pos_Touch >= 220) && (Y_Pos_Touch <= 280))     //Überwachung Touch Feld
    {
      /* Touch Feld [-] Taste ausführen (Tag) */
=======
    /* Touch Feld abfragen [ - ] Taste gedrückt (- Tag) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 340) && (X_Pos_Touch <= 390) && (Y_Pos_Touch >= 220) && (Y_Pos_Touch <= 280))     //Überwachung Touch Feld
    {
      /* Touch Feld [ - ] Taste ausführen (- Tag) */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 340, 250, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen gedrückt

        Tag--;
        if (Tag < 1) Tag = 31;    //Verstellwert begrenzen
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 340, 250, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen ungedrückt        
      }
    }

/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [+] Taste gedrückt (Monat) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 415) && (X_Pos_Touch <= 465) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [+] Taste ausführen (Monat) */
=======
    /* Touch Feld abfragen [ + ] Taste gedrückt (+ Monat) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 415) && (X_Pos_Touch <= 465) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [ + ] Taste ausführen (+ Monat) */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 415, 150, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen gedrückt

        Monat++;
        if (Monat > 12) Monat = 1;    //Verstellwert begrenzen
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 415, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen ungedrückt          
      }
    }

/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [-] Taste gedrückt (Monat) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 415) && (X_Pos_Touch <= 465) && (Y_Pos_Touch >= 220) && (Y_Pos_Touch <= 280))     //Überwachung Touch Feld
    {
      /* Touch Feld [-] Taste ausführen (Monat) */
=======
    /* Touch Feld abfragen [ - ] Taste gedrückt (- Monat) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 415) && (X_Pos_Touch <= 465) && (Y_Pos_Touch >= 220) && (Y_Pos_Touch <= 280))     //Überwachung Touch Feld
    {
      /* Touch Feld [ - ] Taste ausführen (- Monat) */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 415, 250, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen gedrückt

        Monat--;
        if (Monat < 1) Monat = 12;    //Verstellwert begrenzen
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 415, 250, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen ungedrückt        
      }
    }

/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [+] Taste gedrückt (Jahr) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 505) && (X_Pos_Touch <= 555) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [+] Taste ausführen (Jahr) */
=======
    /* Touch Feld abfragen [ + ] Taste gedrückt (+ Jahr) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 505) && (X_Pos_Touch <= 555) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [ + ] Taste ausführen (+ Jahr) */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 505, 150, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen gedrückt

        Jahr++;
        if (Jahr > 2099) Jahr = 2000;    //Verstellwert begrenzen
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 505, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen ungedrückt          
      }
    }

/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [-] Taste gedrückt (Jahr) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 505) && (X_Pos_Touch <= 555) && (Y_Pos_Touch >= 220) && (Y_Pos_Touch <= 280))     //Überwachung Touch Feld
    {
      /* Touch Feld [-] Taste ausführen (Jahr) */
=======
    /* Touch Feld abfragen [ - ] Taste gedrückt (- Jahr) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 505) && (X_Pos_Touch <= 555) && (Y_Pos_Touch >= 220) && (Y_Pos_Touch <= 280))     //Überwachung Touch Feld
    {
      /* Touch Feld [ - ] Taste ausführen (- Jahr) */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 505, 250, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen gedrückt

        Jahr--;
        if (Jahr < 2000) Jahr = 2099;    //Verstellwert begrenzen
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 505, 250, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen ungedrückt          
      }
    }

/********************************************************************************************************************/
 
<<<<<<< HEAD
    /* Touch Feld abfragen [+] Taste gedrückt (Wochentag) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 625) && (X_Pos_Touch <= 675) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [+] Taste ausführen (Wochentag) */
=======
    /* Touch Feld abfragen [ + ] Taste gedrückt (+ Wochentag) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 625) && (X_Pos_Touch <= 675) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))     //Überwachung Touch Feld
    {
      /* Touch Feld [ + ] Taste ausführen (+ Wochentag) */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 625, 150, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen gedrückt

        Wochentag_Nr++;
        if (Wochentag_Nr > 7) Wochentag_Nr = 1;         //Verstellwert begrenzen
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
                
        Display.gfx_Button(Status_Touch_Taste, 625, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen ungedrückt         
      }
    }

/********************************************************************************************************************/

<<<<<<< HEAD
    /* Touch Feld abfragen [-] Taste gedrückt (Wochentag) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 625) && (X_Pos_Touch <= 675) && (Y_Pos_Touch >= 220) && (Y_Pos_Touch <= 280))     //Überwachung Touch Feld
    {
      /* Touch Feld [-] Taste ausführen (Wochentag) */
=======
    /* Touch Feld abfragen [ - ] Taste gedrückt (- Wochentag) */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 625) && (X_Pos_Touch <= 675) && (Y_Pos_Touch >= 220) && (Y_Pos_Touch <= 280))     //Überwachung Touch Feld
    {
      /* Touch Feld [ - ] Taste ausführen (- Wochentag) */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 625, 250, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen gedrückt

        Wochentag_Nr--;
        if (Wochentag_Nr < 1) Wochentag_Nr = 7;         //Verstellwert begrenzen
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
                
        Display.gfx_Button(Status_Touch_Taste, 625, 250, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen ungedrückt         
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Set Zeit] Taste gedrückt */
    if ((Zeit_Button == true) && (X_Pos_Touch >= 65) && (X_Pos_Touch <= 195) && (Y_Pos_Touch >= 290) && (Y_Pos_Touch <= 350))     //Überwachung Touch Feld
    {
      /* Touch Feld [Set Zeit] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 95, 320, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Set Zeit");   //Taste anzeigen gedrückt

        /* Vorgabe setzen */
        if (Stunden > 23) 
        {
          Stunden = 12;
          Minuten = 0;
          Tag = 1;
          Monat = 1; 
<<<<<<< HEAD
          Jahr = 2023;        
=======
          Jahr = 2022;        
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        }

        /* Zeit setzen */
        Uhr.fillByHMS(Stunden, Minuten, 00);      //Stunden, Minuten, Sekunden vorgeben
        Uhr.fillByYMD(Jahr, Monat, Tag);          //Jahr, Monat, Tag vorgeben

        switch (Wochentag_Nr)      //Wochentag wandeln
        {
          case 1:                 //Montag
            Wochentag = MON;
            break;
      
          case 2:                 //Dienstag
            Wochentag = TUE;
            break;
      
          case 3:                 //Mittwoch
            Wochentag = WED;
            break;
      
          case 4:                 //Donnerstag
            Wochentag = THU;
            break;
      
          case 5:                 //Freitag
            Wochentag = FRI;
            break;
      
          case 6:                 //Samstag
            Wochentag = SAT;
            break;
      
          case 7:                 //Sonntag
            Wochentag = SUN;
            break;
        }
              
        Uhr.fillDayOfWeek(Wochentag);             //Wochentag vorgeben        
        Uhr.setTime();    //Zeit setzen

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit) 
               
        Display.gfx_Button(Status_Touch_Taste, 95, 320, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Set Zeit");     //Taste anzeigen ungedrückt         
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
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 7;               //Menü Info anwählen
        Bild_aufgebaut[7] = false;          //Bildschirm Info aufgebaut zurücksetzen
        Letztes_Menue = 5;                  //Letztes angewähltes Menü   
        Info_Seite = 24;                    //Info Seite anwählen  
      }
    }

/********************************************************************************************************************/
=======
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
  
  }     //Touch Freigabe Ende

/********************************************************************************************************************/
  
}
