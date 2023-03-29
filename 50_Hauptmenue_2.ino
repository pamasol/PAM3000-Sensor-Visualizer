/* 50.Hauptmenü 2 

  Funktionsanwahl */

void Hauptmenue2(bool Bildaufbau, bool Werte_Reset)         //Funktion Hauptmenu
{
  
/********************************************************************************************************************/

  /* Bildaufbau
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */      
  if (Bild_aufgebaut[50] == false)                         //Überwachung Bildschirm aufgebaut
  {
    Display.gfx_Cls();            //Display löschen
    Statusanzeige();              //Aufruf Funktion Statusanzeige
  
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP;  

    /* Touch Tasten ungedrückt anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 30, 60, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Neigungs Sensor");          //Taste anzeigen ungedrückt 
    Display.gfx_Button(Status_Touch_Taste, 500, 60, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "MP3 Player");              //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 30, 140, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zaehler");                 //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                                   //Taste anzeigen gedrückt

    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);                         //Info Kreis zeichnen (Kreis x,y,r)
    Display.gfx_Triangle(400, 20, 380, 40, 420, 40, WHITE);         //Dreieck Seite hoch zeichnen (x, y, x2, y2, x3, y3, Farbe)
    //Display.gfx_Triangle(400, 470, 380, 450, 420, 450, WHITE);    //Dreieck Seite runter zeichnen (x, y, x2, y2, x3, y3, Farbe)
    
    Bild_aufgebaut[50] = true;                                      //Bildschirm aufgebaut setzen
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
  if (Status_Display == TOUCH_RELEASED)                       //Überwachung Touch Freigabe
  {

/********************************************************************************************************************/

    /* Touch Feld abfragen [▲] Taste gedrückt */
    if ((X_Pos_Touch >= 350) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 0) && (Y_Pos_Touch <= 70))    //Überwachung Touch Feld
    {
      /* Touch Feld [▲] Taste ausführen */
      if (Status_Touch_Taste)
      {
        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 0;                 //Menü Info anwählen
        Bild_aufgebaut[0] = false;            //Bildschirm Info aufgebaut zurücksetzen
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Neigung Sensor] Taste gedrückt */
    if ((X_Pos_Touch >= 0) && (X_Pos_Touch <= 130) && (Y_Pos_Touch >= 30) && (Y_Pos_Touch <= 90))    //Überwachung Touch Feld
    {
      /* Touch Feld [Neigungs Sensor] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 60, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Neigungs Sensor");                  //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 51;                //Menü Neiguns Sensor anwählen
        Bild_aufgebaut[51] = false;           //Bildschirm Neigungs Sensor aufgebaut zurücksetzen
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [MP3 Player] Taste gedrückt */
    if ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 799) && (Y_Pos_Touch >= 30) && (Y_Pos_Touch <= 90))      //Überwachung Touch Feld
    { 
      /* Touch Feld [MP3 Player] Taste ausführen */       
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 500, 60, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "MP3 Player");                        //Taste anzeigen gedrückt
        
        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 52;                //Menü Stoppuhr anwählen
        Bild_aufgebaut[52] = false;           //Bildschirm Stoppuhr aufgebaut zurücksetzen
      }
    }

 /********************************************************************************************************************/

    /* Touch Feld abfragen [Zaehler] Taste gedrückt */
    if ((X_Pos_Touch >= 0) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 110) && (Y_Pos_Touch <= 170))    //Überwachung Touch Feld
    {
      /* Touch Feld [Zaehler] Taste ausführen */
      if (Status_Touch_Taste) 
      {
        Display.gfx_Button(Status_Touch_Taste, 30, 140, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zaehler"); //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 53;               //Menü Zähler anwählen
        Bild_aufgebaut[53] = false;          //Bildschirm Zähler aufgebaut zurücksetzen
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
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 7;                 //Menü Info anwählen
        Bild_aufgebaut[7] = false;            //Bildschirm Info aufgebaut zurücksetzen
        Letztes_Menue = 50;                   //Letztes angewähltes Menü
        Info_Seite = 0;                       //Info Seite anwählen
      }
    }

/********************************************************************************************************************/   
  }       //Touch Freigabe Ende
    
/********************************************************************************************************************/
    
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
