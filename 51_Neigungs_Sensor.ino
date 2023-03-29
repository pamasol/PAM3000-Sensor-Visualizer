 /* 51.Neigungs Sensor */

 void Neigungs_Sensor(bool Bildaufbau, bool Werte_Reset)   //Funktion Neiguns Sensor
 {

/********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[51] == false)     //Überwachung Bildschirm aufgebaut
  { 
    Display.gfx_Cls();            //Display löschen     
    Statusanzeige();              //Aufruf Funktion Statusanzeige
       
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Neigungs Sensor");   //Funktion Namen anzeigen

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
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 200, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Buzzer");                               //Taste anzeigen ungedrückt 
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                     //Taste anzeigen gedrückt

    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);       //Info Kreis zeichnen (Kreis x,y,r)

    /* Buzzer */
    Buzzer(100);                                  //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

    Bild_aufgebaut[51] = true;                    //Bildschirm aufgebaut setzen
  }

/********************************************************************************************************************/

  Statusanzeige();              //Aufruf Funktion Statusanzeige
  
/********************************************************************************************************************/

/*
                                        Gerade
                                        0bit
                                        
                                         |
                                         |
         nach hinten neigen -2000bit ----|---- +2000bit nach vorne neigen
                                         |
                                         |
                               -4000bit     +4000bit

*/

   unsigned long Aktuelle_Zeit = millis();                 //Zeit seit start Arduino

  if ((Aktuelle_Zeit - Vorherige_Zeit) >= 500)            //If Aktuelle Zeit zu Vorheringen Zeit kleiner als Zeitverzögerung
  {
    Vorherige_Zeit = Aktuelle_Zeit;                       //Zeit seit Start an Vorherige Zeit anpassen
  
//***************************************************************************************************************

    /* Ist Wert X Achse Gyro */
    if (Gyro.readRegisterInt16(&Ist_X_Gyro, LSM6DS3_ACC_GYRO_OUTX_L_XL) != 0) Gyro_Fehlerzaehler++;   //Ist Wert X Achse Gyro
   
    /* Filter ABS */
    Ist_X_Filter_Gyro.Filter(Ist_X_Gyro);                               //Analoger Wert filtern

    /* Umrechnen in Grad */
    Ist_X_Grad_Gyro = (Ist_X_Filter_Gyro.Current() / 22.22222222);      //Umrechnen in Grad 
  
//***************************************************************************************************************

    /* Ist Wert Y Achse Gyro */ 
    if (Gyro.readRegisterInt16(&Ist_Y_Gyro, LSM6DS3_ACC_GYRO_OUTY_L_XL) != 0) Gyro_Fehlerzaehler++;  //Ist Wert Y Achse Gyro

    /* Filter ABS */
    Ist_Y_Filter_Gyro.Filter(Ist_Y_Gyro);                               //Analoger Wert filtern

    /* Umrechnen in Grad */
    Ist_Y_Grad_Gyro = (Ist_Y_Filter_Gyro.Current() / 22.22222222);      //Umrechnen in Grad
  
//***************************************************************************************************************
    
    /* Ist Wert Z Achse Gyro */ 
    if (Gyro.readRegisterInt16(&Ist_Z_Gyro, LSM6DS3_ACC_GYRO_OUTZ_L_XL) != 0) Gyro_Fehlerzaehler++;  //Ist Wert Z Achse Gyro

    /* Filter ABS */
    Ist_Z_Filter_Gyro.Filter(Ist_Z_Gyro);                               //Analoger Wert filtern

    /* Umrechnen in Grad */
    Ist_Z_Grad_Gyro = (Ist_Z_Filter_Gyro.Current() / 22.22222222);      //Umrechnen in Grad
  
//***************************************************************************************************************
  
    /* Aktuelle Werte anzeigen */
    Display.txt_Height(3);                      //Texthöhe
    Display.txt_Width(3);                       //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
    Display.txt_Inverse(OFF);                   //Text invetieren
    Display.txt_Bold(OFF);                      //Text fett
    
    Display.gfx_MoveTo(50, 90);                 //Text Position (x,y)
    Display.print("X ");                        //Text anzeigen
    Display.print(Ist_X_Grad_Gyro);             //Wert anzeigen
    Display.print(" Grad          ");           //Text anzeigen
        
    Display.gfx_MoveTo(450, 90);                //Text Position (x,y)
    Display.print("Y ");                        //Text anzeigen
    Display.print(Ist_Y_Grad_Gyro);             //Wert anzeigen
    Display.print(" Grad          ");           //Text anzeigen
  }

  /* Buzzer Taste Ein */
  if (Buzzer_Ein == true)
  {
    /* Buzzer um Nullpunkt zu signalisieren */
    if (((Ist_X_Grad_Gyro > 0.5) || (Ist_X_Grad_Gyro < -0.5)) && (millis() >= Buzzer_Gyro))
    {       
      /* Buzzer */
      Buzzer_Gyro = (millis() + (Ist_X_Grad_Gyro * 50.0));       //Buzzer interval
      Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit)
    }
  }
          /* Buzzer um Nullpunkt zu signalisieren */
/*        if (Is_X_Grad_Gyro > 0.5)
        {        
          /* Buzzer */
/*          Buzzer_Gyro = Ist_X_Grad_Gyro * 7.0;      //Buzzer interval
          Buzzer(30.0 + Buzzer_Gyro);               //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          delay(Buzzer_Gyro);
        }

        if (Ist_X_Grad_Gyro < -0.5)
        {
          /* Buzzer */
/*          Buzzer_Gyro = (Ist_X_Grad_Gyro * -1.0) * 7.0;       //Buzzer interval
          Buzzer(30.0 + Buzzer_Gyro);                       //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          delay(Buzzer_Gyro);
        }

/********************************************************************************************************************/

    /* Diagram Ausrechnen */
    int radius = 400;

    float x_Linie_1_float = (400 - (radius * sin((Ist_X_Grad_Gyro - 90) * 0.01745329)));              //x Achse Linie 1 berechnen
    float y_Linie_1_float = (270 - (radius * cos((Ist_X_Grad_Gyro - 90) * 0.01745329)));              //y Achse Linie 1 berechnen
    float x_Linie_2_float = (400 + (radius * sin((Ist_X_Grad_Gyro - 90) * 0.01745329)));              //x Achse Linie 2 berechnen
    float y_Linie_2_float = (270 + (radius * cos((Ist_X_Grad_Gyro - 90) * 0.01745329)));              //y Achse Linie 2 berechnen
    
    int x_Linie_1 = round(x_Linie_1_float);       //x Achse Linie 1 berechnen
    int y_Linie_1 = round(y_Linie_1_float);       //y Achse Linie 1 berechnen
    int x_Linie_2 = round(x_Linie_2_float);       //x Achse Linie 2 berechnen
    int y_Linie_2 = round(y_Linie_2_float);       //y Achse Linie 2 berechnen

    int y_Linie_3 = (y_Linie_1 - (130 / 90 * Ist_Y_Grad_Gyro));     //y Achse Linie 3 berechnen
    int y_Linie_4 = (y_Linie_2 - (130 / 90 * Ist_Y_Grad_Gyro));     //y Achse Linie 4 berechnen

/********************************************************************************************************************/

  /* Diagram Aufzeichnen */
  if ((Ist_X_Grad_Gyro_Merker >= (Ist_X_Grad_Gyro + 0.5)) || (Ist_X_Grad_Gyro_Merker <= (Ist_X_Grad_Gyro - 0.5)) || (Ist_Y_Grad_Gyro_Merker >= (Ist_Y_Grad_Gyro + 0.5)) || (Ist_Y_Grad_Gyro_Merker <= (Ist_Y_Grad_Gyro - 0.5)))
  {
    Display.gfx_Clipping(1);                                                                      //Cliping aktivieren
    Display.gfx_ClipWindow(0, 140, 800, 400);                                                     //Linien werden nur in diesem Fenster gezeichnet
    Display.gfx_RectangleFilled(0, 140, 800, 400, BLACK);                                         //Graphlinien übermalen

    if ((Ist_X_Grad_Gyro <= 0.5) && (Ist_X_Grad_Gyro >= (-0.5)) && (Ist_Y_Grad_Gyro <= 0.5) && (Ist_Y_Grad_Gyro >= (-0.5)))
    {
      Display.gfx_Line(400, (270 - (130 / 90 * Ist_Y_Grad_Gyro)), x_Linie_1, y_Linie_3, GREEN);     //Line 1
      Display.gfx_Line(400, (270 - (130 / 90 * Ist_Y_Grad_Gyro)), x_Linie_2, y_Linie_4, GREEN);     //Line 2      
    }
    else
    {
      Display.gfx_Line(400, (270 - (130 / 90 * Ist_Y_Grad_Gyro)), x_Linie_1, y_Linie_3, WHITE);     //Line 1
      Display.gfx_Line(400, (270 - (130 / 90 * Ist_Y_Grad_Gyro)), x_Linie_2, y_Linie_4, WHITE);     //Line 2      
    }

    Display.gfx_Clipping(0);                                                                        //Cliping deaktivieren
    Ist_X_Grad_Gyro_Merker = Ist_X_Grad_Gyro;   
    Ist_Y_Grad_Gyro_Merker = Ist_Y_Grad_Gyro;
  }
   
/********************************************************************************************************************/

    /* Doppeltaste Goto */
    Doppeltaste_Betaetigt:                     //Doppeltaste Goto
  
    /* Touch Screen handling */
    Status_Display = Display.touch_Get(TOUCH_STATUS);     //Status Touch Screen

    /* Touch Positionen auslesen */
    if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))  //Überwachung Touch gedrückt oder bewegt  
    {
      X_Pos_Touch = Display.touch_Get(TOUCH_GETX);                              //X Position auslesen
      Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);                              //Y Position auslesen
    }
    
    /* Touch Freigabe */
    if (Status_Display == TOUCH_RELEASED)                                       //Überwachung Touch Freigabe
    {
    
/********************************************************************************************************************/  
    
<<<<<<< HEAD
      /* Touch Feld abfragen [Zrugg] Taste gedrückt */       
      if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))     //Überwachung Touch Feld^
      {      
        /* Touch Feld [Zrugg] Taste ausführen */    
        if (Status_Touch_Taste)
        {      
          Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");  //Zurücktaste anzeigen gedrückt
=======
      /* Touch Feld abfragen [Zrug] Taste gedrückt */       
      if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))     //Überwachung Touch Feld^
      {      
        /* Touch Feld [Zrug] Taste ausführen */    
        if (Status_Touch_Taste)
        {      
          Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");  //Zurücktaste anzeigen gedrückt
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        
          /* Buzzer */
          Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
          Menue_angewaehlt = 50;                //Menü Hauptmenue anwählen
          Bild_aufgebaut[50] = false;           //Bildschirm aufgebaut zurücksetzen              
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
          Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
          Bild_aufgebaut[51] = false;                //Bildschirm aufgebaut zurücksetzen           
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
          Letztes_Menue = 51;                   //Letztes angewähltes Menü   
<<<<<<< HEAD
          Info_Seite = 20;                      //Info Seite anwählen
=======
          Info_Seite = 18;                      //Info Seite anwählen
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        }
      }

/********************************************************************************************************************/

      /* Touch Feld abfragen [Buzzer] Taste gedrückt (Doppel Taste Buzzer)
         Es wird die Stopp Taste angezeigt! */
      if ((Buzzer_Ein == false) && (X_Pos_Touch >= 170) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {     
        /* Touch Feld [Buzzer] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 200, 420, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Buzzer");                  //Taste anzeigen gedrückt 

          /* Buzzer Ein */
          Buzzer_Ein = true;                    //Buzzer Ein setzen
          
          /* Buzzer */
          Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          /* Doppeltaste Auschaltverhinderung bis erneut gedrückt */
          goto Doppeltaste_Betaetigt;           //Doppeltaste betätigt  
        }
      }
    
/********************************************************************************************************************/

      /* Touch Feld abfragen [Buzzer] Taste gedrückt (Doppel Taste Buzzer)
         Es wird die Start Taste angezeigt! */
      if ((Buzzer_Ein == true) && (X_Pos_Touch >= 170) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {
        Status_Touch_Taste = !Status_Touch_Taste;                                               //Status Taste Invertieren
        /* Touch Feld [Buzzer] Taste ausführen */
        if (Status_Touch_Taste)
        { 
          Display.gfx_Button(Status_Touch_Taste, 200, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Buzzer");                                //Taste anzeigen gedrückt
               
          /* Buzzer Ein */
          Buzzer_Ein = false;                   //Buzzer Ein zurücksetzen

          /* Buzzer */
          Buzzer(500);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)   

          /* Doppeltaste Auschaltverhinderung bis erneut gedrückt */
          goto Doppeltaste_Betaetigt;           //Doppeltaste betätigt                      
        }
      }
        
/********************************************************************************************************************/
                 
   }      //Touch Freigabe Ende

/********************************************************************************************************************/   
}
