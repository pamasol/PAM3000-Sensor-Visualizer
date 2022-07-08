/* 0.Hauptmenü 1

  Funktionsanwahl */

void Hauptmenue(bool Bildaufbau, bool Werte_Reset)         //Funktion Hauptmenu
{
  
/********************************************************************************************************************/

  /* Bildaufbau
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */      
  if (Bild_aufgebaut[0] == false)                         //Überwachung Bildschirm aufgebaut
  {
    Display.gfx_Cls();            //Display löschen
    Statusanzeige();              //Aufruf Funktion Statusanzeige
  
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP;  

    /* Touch Tasten ungedrückt anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 30, 60, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Doppel-Stoppuhr");                  //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 500, 60, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Stoppuhr");                        //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 30, 140, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige Takt");    //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 500, 140, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Sortierer");                      //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 30, 220, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Analogeanzeige");                  //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 500, 220, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "IO Tester");                      //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 30, 300, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Magnetpolanzeige");                //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 500, 300, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Speed Sensor");                   //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 30, 380, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Einstellungen");                   //Taste anzeigen ungedrückt   
    Display.gfx_Button(Status_Touch_Taste, 500, 380, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Distanz Sensor");                 //Taste anzeigen ungedrückt   
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                  //Taste anzeigen gedrückt

    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);                         //Info Kreis zeichnen (Kreis x,y,r)
    Display.gfx_Triangle(400, 470, 380, 450, 420, 450, WHITE);      //Dreieck Seite runter zeichnen (x, y, x2, y2, x3, y3, Farbe)
      
    Bild_aufgebaut[0] = true;                            //Bildschirm aufgebaut setzen
  }

/********************************************************************************************************************/

  Statusanzeige();              //Aufruf Funktion Statusanzeige

/********************************************************************************************************************/

  /* Touch Screen handling */
  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen
  
  /* Touch Positionen auslesen */
  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))    //Überwachung Touch gedrückt oder bewegt
  {
    X_Pos_Touch = Display.touch_Get(TOUCH_GETX);               //X Position auslesen
    Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);               //Y Position auslesen
  }

  /* Touch Freigabe */
  if (Status_Display == TOUCH_RELEASED)                //Überwachung Touch Freigabe
  {

/********************************************************************************************************************/

    /* Touch Feld abfragen [Doppel-Stoppuhr] Taste gedrückt */
    if ((X_Pos_Touch >= 0) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 30) && (Y_Pos_Touch <= 90))      //Überwachung Touch Feld
    { 
      /* Touch Feld [Doppel-Stoppuhr] Taste ausführen */       
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 60, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Doppel-Stoppuhr");                        //Taste anzeigen gedrückt
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 1;               //Menü Doppel-Stoppuhr anwählen
        Bild_aufgebaut[1] = false;          //Bildschirm Doppel-Stoppuhr aufgebaut zurücksetzen
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Stoppuhr] Taste gedrückt */
    if ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 799) && (Y_Pos_Touch >= 30) && (Y_Pos_Touch <= 90))      //Überwachung Touch Feld
    { 
      /* Touch Feld [Stoppuhr] Taste ausführen */       
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 500, 60, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Stoppuhr");                        //Taste anzeigen gedrückt
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 16;               //Menü Stoppuhr anwählen
        Bild_aufgebaut[16] = false;          //Bildschirm Stoppuhr aufgebaut zurücksetzen
      }
    }
    
/********************************************************************************************************************/

    /* Touch Feld abfragen [Geschwindigkeitsanzeige Takt] Taste gedrückt */
    if ((X_Pos_Touch >= 0) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 110) && (Y_Pos_Touch <= 170))    //Überwachung Touch Feld
    {
      /* Touch Feld [Geschwindigkeitsanzeige Takt] Taste ausführen */
      if (Status_Touch_Taste) 
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 140, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige Takt"); //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 2;               //Menü Geschwindigkeitsanzeige Takt anwählen
        Bild_aufgebaut[2] = false;          //Bildschirm Geschwindigkeitsanzeige Takt aufgebaut zurücksetzen
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Geschwindigkeitsanzeige Sortierer] Taste gedrückt */
    if ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 799) && (Y_Pos_Touch >= 110) && (Y_Pos_Touch <= 170))   //Überwachung Touch Feld
    {
      /* Touch Feld [Geschwindigkeitsanzeige Sortierer] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 500, 140, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Sortierer");                  //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 10;              //Menü Geschwindigkeitsanzeige Sortierer anwählen
        Bild_aufgebaut[10] = false;         //Bildschirm Geschwindigkeitsanzeige Sortierer aufgebaut zurücksetzen
      }      
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Analogeanzeige] Taste gedrückt */
    if ((X_Pos_Touch >= 0) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 190) && (Y_Pos_Touch <= 250))    //Überwachung Touch Feld
    {      
      /* Touch Feld [Analogeanzeige] Taste ausführen */
      if (Status_Touch_Taste)                           //Überwachung Touch Taste Analogeanzeige gedrückt
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 220, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Analogeanzeige");                 //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 3;                 //Menü Analogeanzeige anwählen
        Bild_aufgebaut[3] = false;            //Bildschirm Analogeanzeige aufgebaut zurücksetzen
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [IO Tester] Taste gedrückt */
    if ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 799) && (Y_Pos_Touch >= 190) && (Y_Pos_Touch <= 250))    //Überwachung Touch Feld
    {
      /* Touch Feld [IO Tester] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 500, 220, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "IO Tester");               //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 6;               //Menü IO Tester anwählen
        Bild_aufgebaut[6] = false;          //Bildschirm IO Tester aufgebaut zurücksetzen
      }
    }
    
/********************************************************************************************************************/

    /* Touch Feld abfragen [Magnetpolanzeige] Taste gedrückt */
    if ((X_Pos_Touch >= 0) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 270) && (Y_Pos_Touch <= 330))    //Überwachung Touch Feld
    {
      /* Touch Feld [Magnetpolanzeige] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 300, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Magnetpolanzeige");               //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 4;               //Menü Magnetpolanzeige anwählen
        Bild_aufgebaut[4] = false;          //Bildschirm Magnetpolanzeige aufgebaut zurücksetzen
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Speed Sensor] Taste gedrückt */
    if ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 799) && (Y_Pos_Touch >= 270) && (Y_Pos_Touch <= 330))    //Überwachung Touch Feld
    {
      /* Touch Feld [Speed Sensor] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 500, 300, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Speed Sensor");                  //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 8;               //Menü Einstellungen anwählen
        Bild_aufgebaut[8] = false;          //Bildschirm Einstellungen aufgebaut zurücksetzen
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Einstellungen] Taste gedrückt */
    if ((X_Pos_Touch >= 0) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 350) && (Y_Pos_Touch <= 410))    //Überwachung Touch Feld
    {
      /* Touch Feld [Einstellungen] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 380, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Einstellungen");                  //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 5;               //Menü Einstellungen anwählen
        Bild_aufgebaut[5] = false;          //Bildschirm Einstellungen aufgebaut zurücksetzen
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Distanz Sensor] Taste gedrückt */
    if ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 799) && (Y_Pos_Touch >= 350) && (Y_Pos_Touch <= 410))    //Überwachung Touch Feld
    {
      /* Touch Feld [Distanz Sensor] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 500, 380, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Distanz Sensor");                  //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 9;               //Menü Einstellungen anwählen
        Bild_aufgebaut[9] = false;          //Bildschirm Einstellungen aufgebaut zurücksetzen
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
        Letztes_Menue = 0;                  //Letztes angewähltes Menü
        Info_Seite = 0;                     //Info Seite anwählen
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [▼] Taste gedrückt */
    if ((X_Pos_Touch >= 350) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 500))    //Überwachung Touch Feld
    {
      /* Touch Feld [▼] Taste ausführen */
      if (Status_Touch_Taste)
      {
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 50;               //Menü Info anwählen
        Bild_aufgebaut[50] = false;          //Bildschirm Info aufgebaut zurücksetzen
      }
    }

/********************************************************************************************************************/
    
  }     //Touch Freigabe Ende
    
/********************************************************************************************************************/
    
}
