 /* 14.Geschwindigkeitsanzeige Takt Liste */

 void Geschw_Takt_Liste(bool Bildaufbau, bool Werte_Reset)   //Funktion Geschwindigkeitsanzeige Takt Liste
 {

  int Listen_Startwert;        //Listen Startwert
  
  /********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */     
  if (Bild_aufgebaut[14] == false)           //Überwachung Bildschirm aufgebaut
  {
    Display.gfx_Cls();            //Display löschen    
    Statusanzeige();              //Aufruf Funktion Statusanzeige
  
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige Takt Liste");   //Funktion Namen anzeigen
    
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");                                         //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                                                                   //Taste anzeigen ungedrückt
    if (Listen_Startwert_Gesch_Takt > 0) Display.gfx_Button(Status_Touch_Taste, 50, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, " -20 ");    //Taste anzeigen ungedrückt
    if (Listen_Startwert_Gesch_Takt < 40) Display.gfx_Button(Status_Touch_Taste, 200, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, " +20 ");  //Taste anzeigen ungedrückt    
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                                                         //Taste anzeigen gedrückt
    
    /* Grafik anzeigen */
    Display.gfx_Rectangle(0, 70, 395, 380, Texthintergrund_Menue);          //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_Rectangle(403, 70, 799, 380, Texthintergrund_Menue);        //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_Circle(767, 30, 22, WHITE);                                 //Info Kreis zeichnen (Kreis x,y,r)
    
    /* Listen Darstellung           
             1                      
    0. 0 cpm    10. 0 cpm         
    1. 0 cpm    11. 0 cpm
    2. 0 cpm    12. 0 cpm
    3. 0 cpm    13. 0 cpm
    4. 0 cpm    14. 0 cpm
    5. 0 cpm    15. 0 cpm
    6. 0 cpm    16. 0 cpm
    7. 0 cpm    17. 0 cpm
    8. 0 cpm    18. 0 cpm
    9. 0 cpm    19. 0 cpm
    */

    /* Liste */
    Display.txt_Height(2);                                      //Texthöhe
    Display.txt_Width(2);                                       //Textweite
    Display.txt_Set(TEXT_COLOUR, Texthintergrund_Menue);        //Textfarbe
    Display.gfx_MoveTo(180, 88);                                //Text Position (x,y)
    Display.print("1");                                         //Text anzeigen
    Display.gfx_Circle(186, 98, 16, Texthintergrund_Menue);     //Kreis zeichnen (Kreis x,y,r)
        
    Display.gfx_MoveTo(580, 88);                                //Text Position (x,y)
    Display.print("2");                                         //Text anzeigen
    Display.gfx_Circle(586, 98, 16, Texthintergrund_Menue);     //Kreis zeichnen (Kreis x,y,r)
        
    Display.txt_Set(TEXT_COLOUR, Textfarbe);        //Textfarbe
    Liste(20, 120, (Listen_Startwert_Gesch_Takt + 0), 10, Zeiten_Geschw_Takt_1, 0, 0, RED, "cpm");        //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
    Liste(200, 120, (Listen_Startwert_Gesch_Takt + 10), 10, Zeiten_Geschw_Takt_1, 0, 0, RED, "cpm");      //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)

    Liste(420, 120, (Listen_Startwert_Gesch_Takt + 0), 10, Zeiten_Geschw_Takt_2, 0, 0, RED, "cpm");       //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
    Liste(600, 120, (Listen_Startwert_Gesch_Takt + 10), 10, Zeiten_Geschw_Takt_2, 0, 0, RED, "cpm");      //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)

    Bild_aufgebaut[14] = true;                //Bildschirm aufgebaut setzen
  }

/********************************************************************************************************************/

  Statusanzeige();              //Aufruf Funktion Statusanzeige

/********************************************************************************************************************/

  /* Touch Screen handling */
  Status_Display = Display.touch_Get(TOUCH_STATUS);   //Status Touch Screen

  /* Touch Positionen auslesen */
  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))    //Überwachung Touch gedrückt oder bewegt
  {
    X_Pos_Touch = Display.touch_Get(TOUCH_GETX);            //X Position auslesen
    Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);            //Y Position auslesen
  }

  /* Touch Freigabe */
  if (Status_Display == TOUCH_RELEASED)             //Überwachung Touch Freigabe
  {
    
/********************************************************************************************************************/ 
   
    /* Touch Feld abfragen [Zrug] Taste gedrückt */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrug] Taste ausführen */
      if (Status_Touch_Taste)
      {      
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");  //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          
        Menue_angewaehlt = 2;                 //Menü Geschwindigkeitsanzeige anwählen
        Bild_aufgebaut[2] = false;            //Bildschirm aufgebaut zurücksetzen       
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Reset] Taste gedrückt */
    if ((X_Pos_Touch >= 320) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Reset] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET");                  //Taste anzeigen gedrückt
        
        /* Alle Zeiten zurücksetzen */
        for (int i = 0; i <= 59; i++)
        {
          Zeiten_Geschw_Takt_1[i] = 0;              //Zeit Geschwindigkeit Takt 1 0-59 zurücksetzen
          Zeiten_Geschw_Takt_2[i] = 0;              //Zeit Geschwindigkeit Takt 2 0-59 zurücksetzen 
        }

        /* Buzzer */
        Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Bild_aufgebaut[14] = false;                 //Bildschirm aufgebaut zurücksetzen         
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [-20] Taste gedrückt */
    if ((Listen_Startwert_Gesch_Takt > 0) && (X_Pos_Touch >= 20) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [-20] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 50, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, " -20 ");     //Taste anzeigen gedrückt

        Listen_Startwert_Gesch_Takt = Listen_Startwert_Gesch_Takt - 20;

        //Listen Startwert begrenzen
        if (Listen_Startwert_Gesch_Takt <= 0) Listen_Startwert_Gesch_Takt = 0;        //Listen Startwert begrenzen

        /* Buzzer */
        Buzzer(100);                              //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          
        Bild_aufgebaut[14] = false;               //Bildschirm aufgebaut zurücksetzen             
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [+20] Taste gedrückt */
    if ((Listen_Startwert_Gesch_Takt < 40) && (X_Pos_Touch >= 150) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [+20] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 200, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, " +20 ");    //Taste anzeigen gedrückt

        Listen_Startwert_Gesch_Takt = Listen_Startwert_Gesch_Takt + 20;

        //Listen Startwert begrenzen
        if (Listen_Startwert_Gesch_Takt >= 40) Listen_Startwert_Gesch_Takt = 40;        //Listen Startwert begrenzen

        /* Buzzer */
        Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          
        Bild_aufgebaut[14] = false;                //Bildschirm aufgebaut zurücksetzen                
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
        Buzzer(100);                        //Aufruf Funktion Buzzer(int Buzzer_Zeit)
      
        Menue_angewaehlt = 7;               //Menü Info anwählen
        Bild_aufgebaut[7] = false;          //Bildschirm Info aufgebaut zurücksetzen
        Letztes_Menue = 14;                 //Letztes angewähltes Menü   
        Info_Seite = 12;                    //Info Seite anwählen
      }
    }
      
/********************************************************************************************************************/  
  
  }     //Touch Freigabe Ende 

/********************************************************************************************************************/
 
}
