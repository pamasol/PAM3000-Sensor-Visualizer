/* 4.Magnetpolanzeige */

void Magnetpolanzeige(bool Bildaufbau, bool Werte_Reset)         //Funktion Magnetpolanzeige
{

/********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[4] == false)                   //Überwachung Bildschirm aufgebaut
  { 
    Display.gfx_Cls();            //Display löschen  
    Statusanzeige();              //Aufruf Funktion Statusanzeige
  
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Magnetpolanzeige");         //Funktion Namen anzeigen
    Display.gfx_Button(Status_Touch_Taste, 0, 200, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Magnetfeldsensor");         //Funktion Namen anzeigen
    
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
    Display.gfx_Button(Status_Touch_Taste, 630, 302, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Set 0");                                 //Taste anzeigen ungedrückt 
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                     //Taste anzeigen gedrückt
        
    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);                                 //Info Kreis zeichnen (Kreis x,y,r)
        
    Display.gfx_Rectangle(0, 70, 799, 190, Texthintergrund_Menue);          //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_Circle(767, 30, 22, WHITE);                                 //Info Kreis zeichnen (Kreis x,y,r)

    Display.gfx_Rectangle(0, 232, 799, 352, Texthintergrund_Menue);         //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_Circle(40, 289, 21, GRAY);                                  //Kreis zeichnen (Kreis x,y,r)
  
    /* Buzzer */
    Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)  

    Bild_aufgebaut[4] = true;                       //Bildschirm aufgebaut setzen    
  }

/********************************************************************************************************************/
  
  Statusanzeige();              //Aufruf Funktion Statusanzeige
  
/********************************************************************************************************************/

  /* Sobald der Hallsensor in die Nähe eines Südpols ist. Zeigt er LOW an und Südpol wird angezeigt. Ansonsten zeigt es Nordpol an. 
   Siehe Programm von Hersteller auf Beilage*/

  Display.txt_Height(4);                          //Texthöhe  
  Display.txt_Width(3);                           //Textweite
  Display.txt_Set(TEXT_COLOUR, Textfarbe);        //Textfarbe  
  Display.txt_Inverse(OFF);                       //Text invetieren  
  Display.txt_Bold(OFF);                          //Text fett
  
  /* Südpol anzeigen */
  if (digitalRead(DE_Hallsensor) == LOW)            //Überwachung Digital Eingang Hallsensor
  {
    Display.gfx_CircleFilled(40, 127, 20, GREEN);   //Status anzeigen grüner Punkt (Kreis x,y,r)    
    Display.gfx_MoveTo(80, 105);                    //Text Position (x,y)  
    Display.print("Suedpol");                       //Text anzeigen
  }
  
  /* Nordpol anzeigen */
  else
  {
    Display.gfx_CircleFilled(40, 127, 20, RED);     //Status anzeigen roter Punkt (Kreis x,y,r)   
    Display.gfx_MoveTo(80, 105);                    //Text Position (x,y)
    Display.print("Nordpol");                       //Text anzeigen
  }

/********************************************************************************************************************/

  /* Magnetfeldsensor SS495A

     Sensorauflösung:      3.125 mV/Gs
     Magnetischer Bereich: -670 Gs bis 670 Gs (-67 mT bis 67 mT)
     Reaktionszeit:        3 uS  
    
     Auflösung Analoger Eingang bei 4.89mV (Versorgung 5V)
        
     Positive Werte = Südpol (Grün)
     Negative Werte = Nordpol (Rot)           
  */
  
  //Nullpunkt_Magnetfeld_bit = 715.0;           //Korrekturwert um Nullpunkt einzustellen
  Offset_Magnetfeld_bit = 1.5648;               //Umrechnungsfaktor bit in Gs (Offset = 4.89mV / 3.125mV)
  
  Magnetfeld_bit = analogRead(AD_Magnetfeldsensor);                                       //Magnetfeldsensor am Pin A1 einlesen
  Magnetfeld_Gs = (Magnetfeld_bit - Nullpunkt_Magnetfeld_bit) * Offset_Magnetfeld_bit;    //bit in Gs umrechnen
  
  /* Aktuelle Werte anzeigen */
  Display.txt_Height(4);                      //Texthöhe
  Display.txt_Width(3);                       //Textweite
  Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
  Display.txt_Inverse(OFF);                   //Text invetieren
  Display.txt_Bold(OFF);                      //Text fett

  /* Südpol anzeigen */
  if (Magnetfeld_Gs >= 20.0)
  {
    Display.gfx_CircleFilled(40, 289, 20, GREEN);   //Status anzeigen grüner Punkt (Kreis x,y,r)    
    Display.gfx_MoveTo(80, 267);                    //Text Position (x,y)  
    Display.print("Suedpol");                       //Text anzeigen          
  }

  /* Nullpunkt anzeigen */
  if ((Magnetfeld_Gs > -20.0) && (Magnetfeld_Gs < 20.0))
  {
    Display.gfx_CircleFilled(40, 289, 20, BLACK);   //Status anzeigen grüner Punkt (Kreis x,y,r)    
    Display.gfx_MoveTo(80, 267);                    //Text Position (x,y)  
    Display.print("-       ");                      //Text anzeigen          
  }
  
  /* Nordpol anzeigen */
  if (Magnetfeld_Gs <= -20.0)
  {
    Display.gfx_CircleFilled(40, 289, 20, RED);     //Status anzeigen roter Punkt (Kreis x,y,r)   
    Display.gfx_MoveTo(80, 267);                    //Text Position (x,y)
    Display.print("Nordpol");                       //Text anzeigen             
  }
 
  Display.gfx_MoveTo(300, 267);       //Text Position (x,y)
  Display.print(Magnetfeld_Gs);       //Wert anzeigen
  Display.print(" Gs  ");           //Text anzeigen

  Display.txt_Height(2);                      //Texthöhe
  Display.txt_Width(2);                       //Textweite
  Display.gfx_MoveTo(630, 247);               //Text Position (x,y)
  Display.print(Nullpunkt_Magnetfeld_bit);    //Wert anzeigen
  Display.print(" bit ");                     //Text anzeigen
  
/********************************************************************************************************************/

  /* Touch Screen handling */
  Status_Display = Display.touch_Get(TOUCH_STATUS);   //Status Touch Screen

  /* Touch Positionen auslesen */
  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING)) //Überwachung Touch gedrückt oder bewegt
  {
    X_Pos_Touch = Display.touch_Get(TOUCH_GETX);                                      //X Position auslesen
    Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);                                      //Y Position auslesen
  }

  /* Touch Freigabe */
  if (Status_Display == TOUCH_RELEASED)                                               //Überwachung Touch Freigabe
  {

/********************************************************************************************************************/

     /* Touch Feld abfragen [Set 0] Taste gedrückt */
    if ((X_Pos_Touch >= 600) && (X_Pos_Touch <= 700) && (Y_Pos_Touch >= 272) && (Y_Pos_Touch <= 332))   //Überwachung Touch Feld
    {     
      /* Touch Feld [Set 0] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        /* [Set 0] Taste anzeigen Funktion aktiv */
        Display.gfx_Button(Status_Touch_Taste, 630, 302, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Set 0");                  //Taste anzeigen gedrückt

        /* Nullpunkt berechnen */
        Nullpunkt_Magnetfeld_bit = (0.0 - Magnetfeld_bit) * -1.0;       //Nullpunkt berechnen

        delay(1000);  //Verzögerung 1000ms
        Display.gfx_Button(Status_Touch_Taste, 630, 302, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Set 0");                     //Taste anzeigen ungedrückt

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)                                                                           
      }
    }

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

        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 0;                 //Hauptmenü anwählen
        Bild_aufgebaut[0] = false;            //Bildschirm aufgebaut zurücksetzen
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
        Letztes_Menue = 4;                    //Letztes angewähltes Menü   
<<<<<<< HEAD
        Info_Seite = 9;                       //Info Seite anwählen
=======
        Info_Seite = 5;                       //Info Seite anwählen
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      }
    }
      
/********************************************************************************************************************/
    
  }     //Touch Freigabe Ende

/********************************************************************************************************************/

}
