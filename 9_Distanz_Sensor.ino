 /* 9.Distanz Sensor */

 void Distanz_Sensor(bool Bildaufbau, bool Werte_Reset)   //Funktion Distanz Sensor
 {

/********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[9] == false)     //Überwachung Bildschirm aufgebaut
  { 
    Display.gfx_Cls();            //Display löschen     
    Statusanzeige();              //Aufruf Funktion Statusanzeige
       
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Distanz Sensor");   //Funktion Namen anzeigen

    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");     //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Liste");                                  //Taste anzeigen ungedrückt 
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                     //Taste anzeigen gedrückt

    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);         //Info Kreis zeichnen (Kreis x,y,r) 

    /* Buzzer */
    Buzzer(100);                                    //Aufruf Funktion Buzzer(int Buzzer_Zeit) 
    
    Bild_aufgebaut[9] = true;                       //Bildschirm aufgebaut setzen 
  }

/********************************************************************************************************************/

  Statusanzeige();              //Aufruf Funktion Statusanzeige
  
/********************************************************************************************************************/

  /* Distanzsensor */
  Display.txt_Height(3);                        //Texthöhe
  Display.txt_Width(3);                         //Textweite
  Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe
  Display.txt_Inverse(OFF);                     //Text invetieren
  Display.txt_Bold(OFF);                        //Text fett
 
  Display.gfx_MoveTo(50, 350);                  //Text Position (x,y)

  if (!lox.begin())        //Überwachung Distanzsensor nicht bereit
  {
    Display.txt_Set(TEXT_COLOUR, RED);                  //Textfarbe    
    Display.print("Distanzsensor nicht bereit!");       //Text anzeigen
  }

  Display.gfx_MoveTo(50, 350);                          //Text Position (x,y)
  
  if (lox.begin()) 
  {
    Display.txt_Set(TEXT_COLOUR, Textfarbe);            //Textfarbe
    Display.print("Distanz: ");                         //Text anzeigen

    VL53L0X_RangingMeasurementData_t measure;   
    lox.rangingTest(&measure, false);                   //pass in 'true' to get debug data printout!
  
    if (measure.RangeStatus != 4)
    {        
      Display.print(measure.RangeMilliMeter);           //Wert anzeigen
      Display.print(" mm            ");                 //Text anzeigen
    }
    else
    { 
      Display.txt_Set(TEXT_COLOUR, RED);                //Textfarbe    
      Display.print(" out of range!");                  //Text anzeigen 
    }
  } 

/********************************************************************************************************************/

    /* Touch Screen handling */
    Status_Display = Display.touch_Get(TOUCH_STATUS);     //Status Touch Screen

    /* Touch Positionen auslesen */
    if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))  //Überwachung Touch gedrückt oder bewegt  
    {
      X_Pos_Touch = Display.touch_Get(TOUCH_GETX);                //X Position auslesen
      Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);                //Y Position auslesen
    }

    /* Touch Freigabe */
    if (Status_Display == TOUCH_RELEASED)                         //Überwachung Touch Freigabe
    {
    
/********************************************************************************************************************/  
    
      /* Touch Feld abfragen [Zrug] Taste gedrückt */       
      if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))     //Überwachung Touch Feld^
      {      
        /* Touch Feld [Zrug] Taste ausführen */    
        if (Status_Touch_Taste)
        {      
          Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");  //Zurücktaste anzeigen gedrückt

          /* Buzzer */
          Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit) 
        
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
          Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit) 
        
          Bild_aufgebaut[9] = false;            //Bildschirm aufgebaut zurücksetzen           
        }          
      }  

/********************************************************************************************************************/

      /* Touch Feld abfragen [Liste] Taste gedrückt */
      if ((X_Pos_Touch >= 20) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {     
        /* Touch Feld [Liste] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Liste");                  //Taste anzeigen gedrückt 

          /* Buzzer */
          Buzzer(100);                            //Aufruf Funktion Buzzer(int Buzzer_Zeit) 
        
//          Menue_angewaehlt = 13;                //Menü Distanz Sensor Liste anwählen
//          Bild_aufgebaut[13] = false;           //Bildschirm aufgebaut zurücksetzen                                                        
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
          Letztes_Menue = 9;                    //Letztes angewähltes Menü   
          Info_Seite = 9;                       //Info Seite anwählen
        }
      }

/********************************************************************************************************************/

  }       //Touch Freigabe Ende
    
/********************************************************************************************************************/
}
