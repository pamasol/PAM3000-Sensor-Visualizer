 /* 8.Speed Sensor */

void Speed_Sensor(bool Bildaufbau, bool Werte_Reset)   //Funktion Speed Sensor
{

/********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[8] == false)     //Überwachung Bildschirm aufgebaut
  { 
    Display.gfx_Cls();            //Display löschen     
    Statusanzeige();              //Aufruf Funktion Statusanzeige
       
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Speed Sensor");   //Funktion Namen anzeigen

    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");     //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Start");                                //Taste anzeigen ungedrückt 
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                     //Taste anzeigen gedrückt
    Display.gfx_Button(Status_Touch_Taste, 50, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Referenz");                               //Taste anzeigen ungedrückt 

    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);   //Info Kreis zeichnen (Kreis x,y,r)

    /* Aktuelle Werte anzeigen */
    Display.txt_Height(3);                      //Texthöhe
    Display.txt_Width(3);                       //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
    Display.txt_Inverse(OFF);                   //Text invetieren
    Display.txt_Bold(OFF);                      //Text fett
    
    Display.gfx_MoveTo(90, 150);                //Text Position (x,y)
    Display.print("Geschwindigkeit ");          //Text anzeigen
    Display.print(Speed);                       //Wert anzeigen
    Display.print(" m/min     ");               //Text anzeigen 
    
    Display.txt_Height(2);                      //Texthöhe
    Display.txt_Width(2);                       //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
    Display.txt_Inverse(OFF);                   //Text invetieren
    
    Display.gfx_MoveTo(90, 240);                //Text Position (x,y)
    Display.print("Referenz 50Hz: ");           //Text anzeigen
    Display.print(Ref_Wert_Speed);              //Wert anzeigen
    Display.print(" m/min    ");                //Text anzeigen 

    Display.gfx_MoveTo(90, 280);                //Text Position (x,y)
    Display.print("Frequenz Anpassung:  ");     //Text anzeigen
    Display.print(Frequenz_Anpassung);          //Wert anzeigen
    Display.print(" Hz    ");                   //Text anzeigen 

    /* Buzzer */
    Buzzer(100);                              //Aufruf Funktion Buzzer(int Buzzer_Zeit)
    
    Bild_aufgebaut[8] = true;                 //Bildschirm aufgebaut setzen    
  }

/********************************************************************************************************************/

  Statusanzeige();              //Aufruf Funktion Statusanzeige
  
/********************************************************************************************************************/


  while (Speed_Messung_Ein == true)
  {
    
    if ((Speed_Merker == false) && (digitalRead(DE_Sensor_2) == HIGH))
    {
      Speed_Inputs++;                                         //Speed Input + 1
      Speed_Merker = true;                                    //Speed Merker setzen
    }
    
    if (digitalRead(DE_Sensor_2) == LOW)
    {
      Speed_Merker = false;                                   //Speed Merker zurücksetzen
    }

    if ((millis() - Speed_Zeit) >= 1000)
    {  

      /* Geschwindigkeit berechnen */
      float Korrektur_Faktor = 1.075;                                         //Korrektur Faktor 
      Speed = ((12.00 * (Speed_Inputs / 20.00)) * Korrektur_Faktor);          //Distanz nach 1s ausrechnen 1/Umdrehung = 0.2m 
 
      Speed_Inputs = 0;                                                       //Speed Impuls zurücksetzen
      Speed_Zeit = millis();                                                  //Speed Zeit auf aktuelle Arduino Zeit setzen

      if ((Ref_Wert_Speed > 0.00) && (Speed > 0.00))
      {
        Frequenz_Anpassung = round((Ref_Wert_Speed / (Speed / 50.00)) - 50.00);     //Frequenz Anpassung berechnen
      }
      else
      {
        Frequenz_Anpassung = 0;               //Frequenz Anpassung zurücksetzen
      }

      /* Aktuelle Werte anzeigen */
      Display.txt_Height(3);                      //Texthöhe
      Display.txt_Width(3);                       //Textweite
      Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
      Display.txt_Inverse(OFF);                   //Text invetieren
      Display.txt_Bold(OFF);                      //Text fett
    
      Display.gfx_MoveTo(90, 150);                //Text Position (x,y)
      Display.print("Geschwindigkeit ");          //Text anzeigen
      Display.print(Speed);                       //Wert anzeigen
      Display.print(" m/min     ");               //Text anzeigen  

      Display.txt_Height(2);                      //Texthöhe
      Display.txt_Width(2);                       //Textweite
      Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
      Display.txt_Inverse(OFF);                   //Text invetieren
    
      Display.gfx_MoveTo(90, 240);                //Text Position (x,y)
      Display.print("Referenz 50Hz: ");           //Text anzeigen
      Display.print(Ref_Wert_Speed);              //Wert anzeigen
      Display.print(" m/min     ");               //Text anzeigen 

      Display.gfx_MoveTo(90, 280);                //Text Position (x,y)
      Display.print("Frequenz Anpassung:  ");     //Text anzeigen
      Display.print(Frequenz_Anpassung);          //Wert anzeigen
      Display.print(" Hz    ");                   //Text anzeigen            
    }
    
/********************************************************************************************************************/

    /* Touch Screen handling */   
    Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen

    /* Touch Positionen auslesen */
    if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))    //Überwachung Touch gedrückt oder bewegt
    {
      X_Pos_Touch = Display.touch_Get(TOUCH_GETX);      //X Position auslesen
      Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);      //Y Position auslesen
    }

    /* Touch Freigabe */
    if (Status_Display == TOUCH_RELEASED)               //Überwachung Touch Freigabe
    {

/********************************************************************************************************************/    

      /* Touch Feld abfragen [Stopp] Taste gedrückt (Doppel Taste Start/Stopp)
      Es wird die Start Taste angezeigt! */
      if ((Speed_Messung_Ein == true) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 600) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))                //Überwachung Touch Feld
      {          
        /* Touch Feld [Stopp] Taste ausführen */
        if (Status_Touch_Taste)
        { 
          Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");     //Taste anzeigen ungedrückt
          Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
          Display.gfx_Button(Status_Touch_Taste, 50, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Referenz");                               //Taste anzeigen ungedrückt 
          Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Start");                                //Taste anzeigen ungedrückt
      
          /* Messung Aus */      
          Speed_Messung_Ein = false;          //Speed Messung Ein zurücksetzen
                    
          /* Buzzer */
          Buzzer(500);                        //Aufruf Funktion Buzzer(int Buzzer_Zeit)             
        }
      }      
/********************************************************************************************************************/

      /* Touch Feld abfragen [Referenz] Taste gedrückt 
         Taste nur auswerten, wenn Messung nicht mehr aktiv ist */
      if ((X_Pos_Touch >= 20) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))                                      //Überwachung Touch Feld
      {     
        /* Touch Feld [Referenz] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 50, 420, ORANGE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Referenz");                  //Taste anzeigen gedrückt 

          /* Referenzwert speichern */
          Ref_Wert_Speed = Speed;                       //Referenzwert speichern  
          //Ref_Wert_abweichung_Stoppuhr = 0;           //Rererenzwert Abweichung Stoppuhr zurücksetzen

          /* Buzzer */
          Buzzer(100);                                  //Aufruf Funktion Buzzer(int Buzzer_Zeit)                                                               
        }
      }

/********************************************************************************************************************/

     }        //Touch Freigabe Ende

/********************************************************************************************************************/
     
  }       //Messung aktiv Ende
  
/********************************************************************************************************************/

    /* Touch Screen handling */
    Status_Display = Display.touch_Get(TOUCH_STATUS);     //Status Touch Screen

    /* Touch Positionen auslesen */
    if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))  //Überwachung Touch gedrückt oder bewegt  
    {
      X_Pos_Touch = Display.touch_Get(TOUCH_GETX);              //X Position auslesen
      Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);              //Y Position auslesen
    }

    /* Touch Freigabe */
    if (Status_Display == TOUCH_RELEASED)                       //Überwachung Touch Freigabe
    {
    
/********************************************************************************************************************/  
    
      /* Touch Feld abfragen [Zrugg] Taste gedrückt */       
      if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))     //Überwachung Touch Feld^
      {      
        /* Touch Feld [Zrugg] Taste ausführen */    
        if (Status_Touch_Taste)
        {      
          Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");  //Zurücktaste anzeigen gedrückt

          /* Buzzer */
          Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          Ref_Wert_Speed = 0;                   //Referenzwert zurücksetzen           
          Frequenz_Anpassung = 0;               //Frequenz Anpassung zurücksetzen
          Menue_angewaehlt = 0;                 //Menü Hauptmenue anwählen
          Bild_aufgebaut[0] = false;            //Bildschirm aufgebaut zurücksetzen              
        }   
      }

/********************************************************************************************************************/

      /* Touch Feld abfragen [Reset] Taste gedrückt */
      if ((X_Pos_Touch >= 320) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450)) //Überwachung Touch Feld    
      {     
        /* Touch Feld [Reset] Taste ausführen */
        if (Status_Touch_Taste)   
        {
          Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET");                  //Taste anzeigen gedrückt
  
          /* Buzzer */
          Buzzer(100);                              //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

          Ref_Wert_Speed = 0;                       //Referenzwert zurücksetzen
          Frequenz_Anpassung = 0;                   //Frequenz Anpassung zurücksetzen
          Bild_aufgebaut[8] = false;                //Bildschirm aufgebaut zurücksetzen           
        }          
      }  

/********************************************************************************************************************/

      /* Touch Feld abfragen [Start] Taste gedrückt (Doppel Taste Start/Stopp)
         Es wird die Stopp Taste angezeigt! */
      if ((Speed_Messung_Ein == false) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 600) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {     
        /* Touch Feld [Start] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 500, 420, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Stopp");                  //Taste anzeigen gedrückt
          Display.gfx_Button(Status_Touch_Taste, 50, 420, ORANGE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Referenz");             //Taste anzeigen ungedrückt 

          Display.gfx_Button(Status_Touch_Taste, 650, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Zrugg");                  //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 350, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                 //Taste anzeigen nicht drückbar

          /* Messung Ein */
          Speed_Messung_Ein = true;          //Speed Messung Ein setzen
          
          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
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
          Letztes_Menue = 8;                  //Letztes angewähltes Menü   
          Info_Seite = 10;                    //Info Seite anwählen
        }
      }

/********************************************************************************************************************/
                
    }       //Touch Freigabe Ende
    
/********************************************************************************************************************/
    
}
