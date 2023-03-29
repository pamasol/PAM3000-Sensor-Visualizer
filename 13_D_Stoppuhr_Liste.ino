 /* 13.Doppel-Stoppuhr Liste */

 void D_Stoppuhr_Liste(bool Bildaufbau, bool Werte_Reset)   //Funktion  Doppel-Stoppuhr Liste
 {

  int Listen_Startwert;        //Listen Startwert
  
/********************************************************************************************************************/
  
  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */     
  if (Bild_aufgebaut[13] == false)           //Überwachung Bildschirm aufgebaut
  {
    Display.gfx_Cls();              //Display löschen
    Statusanzeige();                //Aufruf Funktion Statusanzeige
    
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Doppel-Stoppuhr Liste");   //Funktion Namen anzeigen
    
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
<<<<<<< HEAD
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");                                       //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                                                                 //Taste anzeigen ungedrückt
    if (Listen_Startwert_Stoppuhr > 0) Display.gfx_Button(Status_Touch_Taste, 50, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, " -20 ");    //Taste anzeigen ungedrückt
    if (Listen_Startwert_Stoppuhr < 40) Display.gfx_Button(Status_Touch_Taste, 200, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, " +20 ");  //Taste anzeigen ungedrückt   
    Display.gfx_Button(Status_Touch_Taste, 500, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                                                                  //Taste anzeigen ungedrückt
=======
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");                                       //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                                                                 //Taste anzeigen ungedrückt
    if (Listen_Startwert_Stoppuhr > 0) Display.gfx_Button(Status_Touch_Taste, 50, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, " -20 ");    //Taste anzeigen ungedrückt
    if (Listen_Startwert_Stoppuhr < 40) Display.gfx_Button(Status_Touch_Taste, 200, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, " +20 ");  //Taste anzeigen ungedrückt   
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                                                       //Taste anzeigen gedrückt

    /* Grafik anzeigen */
    Display.gfx_Rectangle(0, 70, 395, 380, Texthintergrund_Menue);        //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_Rectangle(403, 70, 799, 380, Texthintergrund_Menue);      //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_Circle(767, 30, 22, WHITE);                               //Info Kreis zeichnen (Kreis x,y,r)
    
    /* Listen Darstellung           
             1                      
    0. 0 ms     10. 0 ms         
    1. 0 ms     11. 0 ms
    2. 0 ms     12. 0 ms
    3. 0 ms     13. 0 ms
    4. 0 ms     14. 0 ms
    5. 0 ms     15. 0 ms
    6. 0 ms     16. 0 ms
    7. 0 ms     17. 0 ms
    8. 0 ms     18. 0 ms
    9. 0 ms     19. 0 ms
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
    Liste(20, 120, (Listen_Startwert_Stoppuhr + 0), 10, Zeiten_D_Stoppuhr_1, Mittelwert_D_Stoppuhr_1, 1, BLUE, "ms");         //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
    Liste(200, 120, (Listen_Startwert_Stoppuhr + 10), 10, Zeiten_D_Stoppuhr_1, Mittelwert_D_Stoppuhr_1, 1, BLUE, "ms");       //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)

    Liste(420, 120, (Listen_Startwert_Stoppuhr + 0), 10, Zeiten_D_Stoppuhr_2, Mittelwert_D_Stoppuhr_2, 1, BLUE, "ms");        //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
    Liste(600, 120, (Listen_Startwert_Stoppuhr + 10), 10, Zeiten_D_Stoppuhr_2, Mittelwert_D_Stoppuhr_2, 1, BLUE, "ms");       //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
    
    Bild_aufgebaut[13] = true;                //Bildschirm aufgebaut setzen
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
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          
        Menue_angewaehlt = 1;                 //Menü Stoppuhr anwählen
        Bild_aufgebaut[1] = false;            //Bildschirm aufgebaut zurücksetzen       
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
          Zeiten_D_Stoppuhr_1[i] = 0;                     //Zeiten Doppel-Stoppuhr 1 0-59 zurücksetzen
          Zeiten_D_Stoppuhr_2[i] = 0;                     //Zeiten Doppel-Stoppuhr 2 0-59 zurücksetzen
        }

        Hoechstwert_D_Stoppuhr_1 = 0;                    //Höchstwert Doppel-Stoppuhr 1 zurücksetzen
        Hoechstwert_D_Stoppuhr_2 = 0;                    //Höchstwert Doppel-Stoppuhr 2 zurücksetzen

        Messungen_D_Stoppuhr_1 = 0;                      //Messungen Doppel-Stoppuhr 1 zurücksetzen
        Messungen_D_Stoppuhr_2 = 0;                      //Messungen Doppel-Stoppuhr 2 zurücksetzen

        Summe_Mittelwert_D_Stoppuhr_1 = 0;               //Summe Mittelwert Doppel-Stoppuhr 1 zurücksetzen 
        Summe_Mittelwert_D_Stoppuhr_2 = 0;               //Summe Mittelwert Doppel-Stoppuhr 2 zurücksetzen

        Mittelwert_D_Stoppuhr_1 = 0;                     //Mittelwert Doppel-Stoppuhr 1 zurücksetzen 
        Mittelwert_D_Stoppuhr_2 = 0;                     //Mittelwert Doppel-Stoppuhr 2 zurücksetzen

        Kleinstwert_D_Stoppuhr_1 = 9999;                 //Kleinstwert Doppel-Stoppuhr 1 auf maximumwert setzen
        Kleinstwert_D_Stoppuhr_2 = 9999;                 //Kleinstwert Doppel-Stoppuhr 2 auf maximumwert setzen

        /* Buzzer */
        Buzzer(100);                                    //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Bild_aufgebaut[13] = false;                     //Bildschirm aufgebaut zurücksetzen            
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [-20] Taste gedrückt */
    if ((Listen_Startwert_Stoppuhr > 0) && (X_Pos_Touch >= 20) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [-20] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 50, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, " -20 ");     //Taste anzeigen gedrückt

        Listen_Startwert_Stoppuhr = Listen_Startwert_Stoppuhr - 20;

        //Listen Startwert begrenzen
        if (Listen_Startwert_Stoppuhr <= 0) Listen_Startwert_Stoppuhr = 0;        //Listen Startwert begrenzen

        /* Buzzer */
        Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          
        Bild_aufgebaut[13] = false;                 //Bildschirm aufgebaut zurücksetzen             
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [+20] Taste gedrückt */
    if ((Listen_Startwert_Stoppuhr < 40) && (X_Pos_Touch >= 150) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [+20] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 200, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, " +20 ");    //Taste anzeigen gedrückt

        Listen_Startwert_Stoppuhr = Listen_Startwert_Stoppuhr + 20;

        //Listen Startwert begrenzen
        if (Listen_Startwert_Stoppuhr >= 40) Listen_Startwert_Stoppuhr = 40;        //Listen Startwert begrenzen

        /* Buzzer */
        Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          
        Bild_aufgebaut[13] = false;                 //Bildschirm aufgebaut zurücksetzen                
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
          SerialUSB.println("LABEL,Datum,Zeit,Timer,Messung,ms(1),ms(2)");     //Serial.println("LABEL, Text Spalte 1, Text Spalte 2,....")
        
          /* Meldung ausgeben */
          SerialUSB.println("MSG,Export gestartet");    //Meldung ausgeben
          delay(1000);                                  //Verzögerung

          /* Daten ausgeben */
          for (int i = 0; i <= 59; i++)
          {   
            SerialUSB.println( (String) "DATA,DATE,TIME,TIMER," + i + "," + Zeiten_D_Stoppuhr_1[i] + "," + Zeiten_D_Stoppuhr_2[i]);
 //         SerialUSB.println( (String) "DATA,DATE,TIME,TIMER," + i + "," + Zeiten_D_Stoppuhr_1[i] + "," + Zeiten_D_Stoppuhr_2[i] + "," + ",AUTOSCROLL_20" );
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
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 7;               //Menü Info anwählen
        Bild_aufgebaut[7] = false;          //Bildschirm Info aufgebaut zurücksetzen
        Letztes_Menue = 13;                 //Letztes angewähltes Menü
<<<<<<< HEAD
        Info_Seite = 13;                    //Info Seite anwählen             
=======
        Info_Seite = 11;                    //Info Seite anwählen             
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      }
    }
      
/********************************************************************************************************************/ 

 }      //Touch Freigabe Ende  

/********************************************************************************************************************/

}
