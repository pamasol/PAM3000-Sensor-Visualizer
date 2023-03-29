 /* 15.Geschwindigkeitsanzeige Sortierer Liste  */

 void  Geschw_Sort_Liste(bool Bildaufbau, bool Werte_Reset)   //Funktion Geschwindigkeitsanzeige Sortierer Liste
 {
  
/********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[15] == false)           //Überwachung Bildschirm aufgebaut
  {
    Display.gfx_Cls();            //Display löschen
    Statusanzeige();              //Aufruf Funktion Statusanzeige
  
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige Sortierer Liste");   //Funktion Namen anzeigen
    
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
<<<<<<< HEAD
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");                                           //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                                                                     //Taste anzeigen ungedrückt
    if (Listen_Startwert_Gesch_Sort > 0) Display.gfx_Button(Status_Touch_Taste, 50, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, " -20 ");      //Taste anzeigen ungedrückt
    if (Listen_Startwert_Gesch_Sort < 40) Display.gfx_Button(Status_Touch_Taste, 200, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, " +20 ");    //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 500, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                                                                      //Taste anzeigen ungedrückt
=======
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");                                           //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                                                                     //Taste anzeigen ungedrückt
    if (Listen_Startwert_Gesch_Sort > 0) Display.gfx_Button(Status_Touch_Taste, 50, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, " -20 ");      //Taste anzeigen ungedrückt
    if (Listen_Startwert_Gesch_Sort < 40) Display.gfx_Button(Status_Touch_Taste, 200, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, " +20 ");    //Taste anzeigen ungedrückt
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                                                           //Taste anzeigen gedrückt

    /* Grafik anzeigen */
    Display.gfx_Rectangle(0, 70, 395, 380, Texthintergrund_Menue);            //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_Rectangle(403, 70, 799, 380, Texthintergrund_Menue);          //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_Circle(767, 30, 22, WHITE);                                   //Info Kreis zeichnen (Kreis x,y,r)
    
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
    Liste(20, 120, (Listen_Startwert_Gesch_Sort + 0), 10, Zaehlwerte_Geschw_Sort_1, Mittelwert_Geschw_Sort_1, 0, RED, "cpm");         //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
    Liste(200, 120, (Listen_Startwert_Gesch_Sort + 10), 10, Zaehlwerte_Geschw_Sort_1, Mittelwert_Geschw_Sort_1, 0, RED, "cpm");       //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)

    Liste(420, 120, (Listen_Startwert_Gesch_Sort + 0), 10, Zaehlwerte_Geschw_Sort_2, Mittelwert_Geschw_Sort_2, 0, RED, "cpm");        //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
    Liste(600, 120, (Listen_Startwert_Gesch_Sort + 10), 10, Zaehlwerte_Geschw_Sort_2, Mittelwert_Geschw_Sort_2, 0, RED, "cpm");       //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
       
    Log_X = 10;
    Log_Y = 300;
    Display.gfx_Line(Log_X,Log_Y,(Log_X + 1),(Log_Y + 1),RED) ;      //Linie x1,y1,x2,y2,farbe
   
    Bild_aufgebaut[15] = true;                //Bildschirm aufgebaut setzen
  }

/********************************************************************************************************************/

  Statusanzeige();              //Aufruf Funktion Statusanzeige

/********************************************************************************************************************/

  Datenschreiber(Log_X,Log_Y,RED);             //Aufruf Funktion Datenschreiber(word x, word y, word farbe)
  
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
    
<<<<<<< HEAD
    /* Touch Feld abfragen [Zrugg] Taste gedrückt */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrugg] Taste ausführen */
      if (Status_Touch_Taste)
      {      
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");  //Taste anzeigen gedrückt
=======
    /* Touch Feld abfragen [Zrug] Taste gedrückt */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrug] Taste ausführen */
      if (Status_Touch_Taste)
      {      
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");  //Taste anzeigen gedrückt
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e

        /* Buzzer */
        Buzzer(100);                                    //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Listen_Startwert_Gesch_Sort = 0;                //Listen Startwert zurücksetzen
        Menue_angewaehlt = 10;                          //Menü Geschwindigkeitsanzeige Sortierer anwählen
        Bild_aufgebaut[10] = false;                     //Bildschirm aufgebaut zurücksetzen       
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
          Zaehlwerte_Geschw_Sort_1[i] = 0;                //Zählwerte Geschwindigkeit Sortierer 1 0-59 zurücksetzen
          Zaehlwerte_Geschw_Sort_2[i] = 0;                //Zählwerte Geschwindigkeit Sortierer 2 0-59 zurücksetzen 
        }

        Zaehlwert_Geschw_Sort_1 = 0;                      //Zählwert Geschwindigkeit Sortierer 1 zurücksetzen
        Zaehlwert_Geschw_Sort_2 = 0;                      //Zählwert Geschwindigkeit Sortierer 2 zurücksetzen

        Stoppzeit_Geschw_Sort_1 = 0;                      //Stoppzeit Geschwindigkeit Sortierer 1 zurücksetzen
        Stoppzeit_Geschw_Sort_2 = 0;                      //Stoppzeit Geschwindigkeit Sortierer 2 zurücksetzen

        Hoechstwert_Geschw_Sort_1 = 0;                    //Höchstwert Geschwindigkeit Sortierer 1 zurücksetzen
        Hoechstwert_Geschw_Sort_2 = 0;                    //Höchstwert Geschwindigkeit Sortierer 2 zurücksetzen

        Messungen_Geschw_Sort_1 = 0;                      //Messungen Geschwindigkeit Sortierer 1 zurücksetzen
        Messungen_Geschw_Sort_2 = 0;                      //Messungen Geschwindigkeit Sortierer 2 zurücksetzen

        Summe_Mittelwert_Geschw_Sort_1 = 0;               //Summe Mittelwert Geschwindigkeit Sortierer 1 zurücksetzen 
        Summe_Mittelwert_Geschw_Sort_2 = 0;               //Summe Mittelwert Geschwindigkeit Sortierer 2 zurücksetzen

        Mittelwert_Geschw_Sort_1 = 0;                     //Mittelwert Geschwindigkeit Sortierer 1 zurücksetzen 
        Mittelwert_Geschw_Sort_2 = 0;                     //Mittelwert Geschwindigkeit Sortierer 2 zurücksetzen

        Kleinstwert_Geschw_Sort_1 = 9999;                 //Kleinstwert Geschwindigkeit Sortierer 1 auf maximumwert setzen
        Kleinstwert_Geschw_Sort_2 = 9999;                 //Kleinstwert Geschwindigkeit Sortierer 2 auf maximumwert setzen

        Listen_Startwert_Gesch_Sort = 0;                  //Listen Startwert zurücksetzen
        
        /* Buzzer */
        Buzzer(100);                                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Bild_aufgebaut[15] = false;                       //Bildschirm aufgebaut zurücksetzen        
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [-20] Taste gedrückt */
    if ((Listen_Startwert_Gesch_Sort > 0) && (X_Pos_Touch >= 20) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [-20] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 50, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, " -20 ");     //Taste anzeigen gedrückt

        Listen_Startwert_Gesch_Sort = Listen_Startwert_Gesch_Sort - 20;

        //Listen Startwert begrenzen
        if (Listen_Startwert_Gesch_Sort <= 0) Listen_Startwert_Gesch_Sort = 0;        //Listen Startwert begrenzen

        /* Buzzer */
        Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Bild_aufgebaut[15] = false;                 //Bildschirm aufgebaut zurücksetzen              
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [+20] Taste gedrückt */
    if ((Listen_Startwert_Gesch_Sort < 40) && (X_Pos_Touch >= 150) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [+20] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 200, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, " +20 ");    //Taste anzeigen gedrückt

        Listen_Startwert_Gesch_Sort = Listen_Startwert_Gesch_Sort + 20;

        //Listen Startwert begrenzen
        if (Listen_Startwert_Gesch_Sort >= 40) Listen_Startwert_Gesch_Sort = 40;        //Listen Startwert begrenzen

        /* Buzzer */
        Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Bild_aufgebaut[15] = false;                //Bildschirm aufgebaut zurücksetzen                
      }
    }

/********************************************************************************************************************/

<<<<<<< HEAD
   /* Touch Feld abfragen [Export] Taste gedrückt */
    if ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {     
      /* Touch Feld [Export] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 500, 420, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Export");                  //Taste anzeigen gedrückt 
        
        /* Datenausgabe auf USB Schnittstelle */  
        if (!SerialUSB)      //Überwachung Schnittstelle nicht verfügbar
        {
          Display.gfx_Button(Status_Touch_Taste, 500, 420, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                   //Taste anzeigen Funktion nicht aktiv
          Buzzer(1000);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        } 
             
        if (SerialUSB)      //Überwachung Schnittstelle verfügbar
        {
          /* [Export] Taste anzeigen Funktion aktiv */
          Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, BLACK, Schrifttyp, Textbreite, Textrahmen, "Export");                   //Taste anzeigen Funktion aktiv

          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
          /* Befehl Zeilen löschen */ 
          SerialUSB.println("CLEARSHEET");      

          /* Checkboxen Namen definieren */
          SerialUSB.println("CUSTOMBOX1,LABEL,Option 1");     //Serial.println("CUSTOMBOX1,LABEL,Text");
          SerialUSB.println("CUSTOMBOX2,LABEL,Option 2");     //Serial.println("CUSTOMBOX2,LABEL,Text");
          SerialUSB.println("CUSTOMBOX3,LABEL,Option 3");     //Serial.println("CUSTOMBOX3,LABEL,Text");

          /* Checkboxen Schalter definieren */
          SerialUSB.println("CUSTOMBOX1,SET,0");   //Schalter als schliesser definieren (0=öffner, 1=schliesser)
          SerialUSB.println("CUSTOMBOX2,SET,0");   //Schalter als schliesser definieren (0=öffner, 1=schliesser)
          SerialUSB.println("CUSTOMBOX3,SET,0");   //Schalter als öffner definieren (0=öffner, 1=schliesser)  

          /* Spalten Namen definieren */
          SerialUSB.println("LABEL,Datum,Zeit,Timer,Messung,cpm(1),cpm(2)");     //Serial.println("LABEL, Text Spalte 1, Text Spalte 2,....")

          /* Meldung ausgeben */
          SerialUSB.println("MSG,Export gestartet");    //Meldung ausgeben
          delay(1000);                                  //Verzögerung

          /* Daten ausgeben */
          for (int i = 0; i <= 59; i++)
          {   
            SerialUSB.println( (String) "DATA,DATE,TIME,TIMER," + i + "," + Zaehlwerte_Geschw_Sort_1[i] + "," + Zaehlwerte_Geschw_Sort_2[i]);
            delay(50);                                  //Verzögerung               
          }       
        }

      SerialUSB.println("MSG,Export beendet");    //Meldung ausgeben
      Display.gfx_Button(Status_Touch_Taste, 500, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                   //Taste anzeigen ungedrückt 
                                                
      }
    }
    
/********************************************************************************************************************/

=======
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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
        Letztes_Menue = 15;                   //Letztes angewähltes Menü   
        Info_Seite = 13;                      //Info Seite anwählen
      }
    }
    
/********************************************************************************************************************/
    
  }     //Touch Freigabe Ende
 
/********************************************************************************************************************/

}
