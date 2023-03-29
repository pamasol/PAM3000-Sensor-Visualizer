/* 2.Geschwindigkeitsanzeige Takt

   Misst die Zeit zwischen Takt zu Takt und berechnet daraus die Geschwindigkeit.
   Diese Funktion startet sobal der Pin 8 auf HIGH ist, und stoppt ebenso
   wenn Pin 8 HIGH ist. Das selbe gilt auch für Pin 9.
   
*/

void Geschw_Takt(bool Bildaufbau, bool Werte_Reset)      //Funktion Geschwindigkeitsanzeige Takt
{  

/********************************************************************************************************************/

  /* Bildaufbau
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */   
  if (Bild_aufgebaut[2] == false)                   //Überwachung Bildschirm aufgebaut
  {      
    Display.gfx_Cls();            //Display löschen
    Statusanzeige();              //Aufruf Funktion Statusanzeige
  
    Messung_aktiv_Geschw_Takt_1 = false;              //Messung aktiv Geschwindigkeit Takt 1 zurücksetzen
    Messung_aktiv_Geschw_Takt_2 = false;              //Messung aktiv Geschwindigkeit Takt 2 zurücksetzen
    
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige Takt");    //Funktion Namen anzeigen
    
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");    //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Liste");                                  //Taste anzeigen ungedrückt    
    Display.gfx_Button(Status_Touch_Taste, 500, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Live");                                  //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                     //Taste anzeigen gedrückt

    /* Text anzeigen */
    Display.txt_Height(2);                                      //Texthöhe
    Display.txt_Width(2);                                       //Textweite
    Display.txt_Set(TEXT_COLOUR, Texthintergrund_Menue);        //Textfarbe

    /* Sensor Bezeichung */
    Display.gfx_MoveTo(33, 182);                                //Text Position (x,y)
    Display.print("1");                                         //Text anzeigen
    Display.gfx_Circle(40, 192, 20, Texthintergrund_Menue);     //Kreis zeichnen (Kreis x,y,r)

    Display.gfx_MoveTo(33, 342);                                //Text Position (x,y)
    Display.print("2");                                         //Text anzeigen
    Display.gfx_Circle(40, 352, 20, Texthintergrund_Menue);     //Kreis zeichnen (Kreis x,y,r)
        
    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);                               //Info Kreis zeichnen (Kreis x,y,r)
        
    Display.gfx_Rectangle(0, 70, 799, 230, Texthintergrund_Menue);        //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 106, 20, RED);                           //Status anzeigen roter Punkt (Kreis x,y,r)
    Display.gfx_Circle(40, 106, 21, GRAY);                                //Kreis zeichnen (Kreis x,y,r)
        
    Display.gfx_Rectangle(0, 390, 799, 230, Texthintergrund_Menue);       //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 266, 20, RED);                           //Status anzeigen roter Punkt (Kreis x,y,r)
    Display.gfx_Circle(40, 266, 21, GRAY);                                //Kreis zeichnen (Kreis x,y,r)
    
    /* Letzte 5 Werte anzeigen */
    Liste(590, 92, 0, 5, Zeiten_Geschw_Takt_1, 0, 0, RED, "cpm   ");       //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
    Liste(590, 250, 0, 5, Zeiten_Geschw_Takt_2, 0, 0, RED, "cpm   ");      //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)

    Display.txt_Height(4);                            //Texthöhe
    Display.txt_Width(3);                             //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);          //Textfarbe
    Display.txt_Inverse(OFF);                         //Text invetieren
    Display.txt_Bold(OFF);                            //Text fett
    
    Display.gfx_MoveTo(80, 85);                       //Text Position (x,y)
    Display.print("0 cpm       ");                    //Text anzeigen

    Display.gfx_MoveTo(80, 245);                      //Text Position (x,y)
    Display.print("0 cpm       ");                    //Text anzeigen


    Display.txt_Height(2);                            //Texthöhe
    Display.txt_Width(2);                             //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);          //Textfarbe
    
    Display.gfx_MoveTo(83, 145);                      //Text Position (x,y)
    Display.print("0 Hoechsterwert    ");             //Text anzeigen

    Display.gfx_MoveTo(83, 305);                      //Text Position (x,y)
    Display.print("0 Hoechsterwert    ");             //Text anzeigen         

    /* Interrupte stoppen 
       Wenn Interrupte aktiviert sind stimmen die millis nicht mehr!! */
    detachInterrupt(DE_Sensor_1); //Interrupt Funktion -> Void (Interrupt_Pin_8) stoppen
    detachInterrupt(DE_Sensor_2); //Interrupt Funktion -> Void (Interrupt_Pin_9) stoppen
          
    digitalWrite(DA_Versorgung_24VDC, HIGH);    //Digital Ausgang Versorgung 24VDC setzen
    delay(1000);                                //Verzögerung 1000ms   
     
    /* Buzzer */
    Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

    Bild_aufgebaut[2] = true;                   //Bildschirm aufgebaut setzen         
  }

/********************************************************************************************************************/

  Statusanzeige();              //Aufruf Funktion Statusanzeige
  
/********************************************************************************************************************/

  /* Messung aktiv Geschwindigkeit Takt 1 */
  if ((digitalRead(DE_Sensor_1) == HIGH) || (digitalRead(DE_Sensor_2) == HIGH))          //Überwachung Eingang Pin 8 und Pin 9
  {
    /* Geschwindigkeit Takt 1 und 2 gestartet
       Flankenauswertung Startzeit speichern und grüner Punkt um es als aktiv anzuzeigen. */
    if ((digitalRead(DE_Sensor_1) == HIGH) && (Startzeit_speichern_Geschw_Takt_1 == true) && (digitalRead(DE_Sensor_2) == HIGH) && (Startzeit_speichern_Geschw_Takt_2 == true))
    {
      /* Messung aktiv setzen */
      Messung_aktiv_Geschw_Takt_1 = true;           //Messung aktiv Geschwindgkeit Takt 1 setzen     
      Messung_aktiv_Geschw_Takt_2 = true;           //Messung aktiv Geschwindgkeit Takt 2 setzen 

      /* Startzeit speichern */
      Startzeit_Geschw_Takt_1 = millis();                   //Startzeit Geschwindigkeit Takt 1 auslesen
      Startzeit_Geschw_Takt_2 = Startzeit_Geschw_Takt_1;    //Startzeit Geschwindigkeit Takt 2 auslesen
      Startzeit_speichern_Geschw_Takt_1 = false;            //Startzeit speichern Geschwindigkeit Takt 1 zurücksetzen   
      Startzeit_speichern_Geschw_Takt_2 = false;            //Startzeit speichern Geschwindigkeit Takt 2 zurücksetzen  

      /* Grüner Punkt anzeigen */
      Display.gfx_CircleFilled(40, 106, 20, GREEN);         //Status anzeigen grüner Punkt (Kreis x,y,r) 
      Display.gfx_CircleFilled(40, 266, 20, GREEN);         //Status anzeigen grüner Punkt (Kreis x,y,r)
    }

/********************************************************************************************************************/

    /* Geschwindigkeit Takt 1 gestartet
       Flankenauswertung Startzeit speichern und grüner Punkt um es als aktiv anzuzeigen. */
    if ((digitalRead(DE_Sensor_1) == HIGH) && (Startzeit_speichern_Geschw_Takt_1 == true))
    {
      /* Messung aktiv setzen */
      Messung_aktiv_Geschw_Takt_1 = true;           //Messung aktiv Geschwindgkeit Takt 1 setzen     

      /* Startzeit speichern */
      Startzeit_Geschw_Takt_1 = millis();                   //Startzeit Geschwindigkeit Takt 1 auslesen
      Startzeit_speichern_Geschw_Takt_1 = false;            //Startzeit speichern Geschwindigkeit Takt 1 zurücksetzen   

      /* Grüner Punkt anzeigen */
      Display.gfx_CircleFilled(40, 106, 20, GREEN);       //Status anzeigen grüner Punkt (Kreis x,y,r) 
    }

/********************************************************************************************************************/

    /* Geschwindigkeit Takt 2 gestartet
       Flankenauswertung Startzeit speichern und grüner Punkt um es als aktiv anzuzeigen. */
    if ((digitalRead(DE_Sensor_2) == HIGH) && (Startzeit_speichern_Geschw_Takt_2 == true))
    {
      /* Messung aktiv setzen */
      Messung_aktiv_Geschw_Takt_2 = true;           //Messung aktiv Geschwindgkeit Takt 2 setzen 

      /* Startzeit speichern */
      Startzeit_Geschw_Takt_2 = millis();                   //Startzeit Geschwindigkeit Takt 2 auslesen
      Startzeit_speichern_Geschw_Takt_2 = false;            //Startzeit speichern Geschwindigkeit Takt 2 zurücksetzen  

      /* Grüner Punkt anzeigen */
      Display.gfx_CircleFilled(40, 266, 20, GREEN);       //Status anzeigen grüner Punkt (Kreis x,y,r)
    }
  }

/********************************************************************************************************************/

  /* Aktuelle Wert anzeigen Geschwindigkeit Takt 1 */
//  if (Messung_aktiv_Geschw_Takt_1 == true)
//  {      
    /* Stoppzeit berechnen */
    /* 100ms = 600cpm 
       500ms = 120cpm
      1000ms =  60cpm
     60000ms =   1cpm      
    */    
//    Stoppzeit_Geschw_Takt_1 = (60000/(millis()- Startzeit_Geschw_Takt_1));                    //Stoppzeit Geschwindigkeit Takt 1 berechnen

    /* Aktueller Wert anzeigen */
//    Display.txt_Height(4);                        //Texthöhe
//    Display.txt_Width(3);                         //Textweite
//    Display.txt_Inverse(OFF);                     //Text invetieren
//    Display.txt_Bold(OFF);                        //Text fett
//    Display.txt_Set(TEXT_COLOUR, GRAY);           //Textfarbe grau

    /* Aktuelle Wert anzeigen Geschwindigkeit Takt 1 */
//    Display.gfx_MoveTo(80, 85);                   //Text Position (x,y)
//    Display.print("");
//    Display.print(Stoppzeit_Geschw_Takt_1);       //Wert anzeigen
//    Display.print(" cpm   ");                     //Text anzeigen        
//  }
  
/********************************************************************************************************************/

  /* Aktuelle Wert anzeigen Geschwindigkeit Takt 2 */
//  if (Messung_aktiv_Geschw_Takt_2 == true)
//  {      
    /* Stoppzeit berechnen */
    /* 100ms = 600cpm 
       500ms = 120cpm
      1000ms =  60cpm
     60000ms =   1cpm      
    */
//    Stoppzeit_Geschw_Takt_2 = (60000/(millis()- Startzeit_Geschw_Takt_2));                    //Stoppzeit Geschwindigkeit Takt 2 berechnen

    /* Aktueller Wert anzeigen */
//    Display.txt_Height(4);                        //Texthöhe
//    Display.txt_Width(3);                         //Textweite
//    Display.txt_Inverse(OFF);                     //Text invetieren
//    Display.txt_Bold(OFF);                        //Text fett
//    Display.txt_Set(TEXT_COLOUR, GRAY);           //Textfarbe grau

    /* Aktuelle Wert anzeigen Geschwindigkeit Takt 2 */
//    Display.gfx_MoveTo(80, 245);                  //Text Position (x,y)
//    Display.print("");
//    Display.print(Stoppzeit_Geschw_Takt_2);       //Wert anzeigen
//    Display.print(" cpm   ");                     //Text anzeigen        
//  }
  
/********************************************************************************************************************/

  /* Stopp Takt 1 */
  if ((Messung_aktiv_Geschw_Takt_1 == true) && (Startzeit_speichern_Geschw_Takt_1 == false) && (digitalRead(8) == LOW))
  {     
    Geschw_Stopp_Takt_1 = false;          //Stopp Takt 1 Geschwindigkeit Takt 1 zurücksetzen  
  }
      
  /* Geschwindigkeit Takt 1 gestoppt */
  if ((Messung_aktiv_Geschw_Takt_1 == true) && (Geschw_Stopp_Takt_1 == false) && (digitalRead(8) == HIGH))
  {        
    /* Stoppzeit berechnen */
    /* 100ms = 600cpm 
       500ms = 120cpm
      1000ms =  60cpm
     60000ms =   1cpm      
    */    
    Stoppzeit_Geschw_Takt_1 = (60000/(millis()- Startzeit_Geschw_Takt_1));                    //Stoppzeit Geschwindigkeit Takt 1 berechnen

    Geschw_Stopp_Takt_1 = true;                   //Stopp Takt 1 setzen     
    Messung_aktiv_Geschw_Takt_1 = false;          //Messung aktiv Geschwindgkeit Takt 1 zurücksetzen

    /* Roter Punkt anzeigen */
    Display.gfx_CircleFilled(40, 106, 20, RED);       //Status anzeigen roter Punkt (Kreis x,y,r) 

    /* Höchstwert berechnen */
    if (Stoppzeit_Geschw_Takt_1 >= Hoechstwert_Geschw_Takt_1)
    {           
      Hoechstwert_Geschw_Takt_1 = Stoppzeit_Geschw_Takt_1;     //Höchstwert übernehmen

      /* Höchstwert anzeigen */
      Display.txt_Height(2);                        //Texthöhe
      Display.txt_Width(2);                         //Textweite
      Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe
      
      Display.gfx_MoveTo(83, 145);                  //Text Position (x,y)
      Display.print(Hoechstwert_Geschw_Takt_1);     //Wert anzeigen
      Display.print(" Hoechstwert    ");            //Text anzeigen
    }

    /* History 
       Schieberegister letzten Werte. */
    Zeiten_Geschw_Takt_1[59] = Zeiten_Geschw_Takt_1[58];
    Zeiten_Geschw_Takt_1[58] = Zeiten_Geschw_Takt_1[57];
    Zeiten_Geschw_Takt_1[57] = Zeiten_Geschw_Takt_1[56];
    Zeiten_Geschw_Takt_1[56] = Zeiten_Geschw_Takt_1[55];
    Zeiten_Geschw_Takt_1[55] = Zeiten_Geschw_Takt_1[54];
    Zeiten_Geschw_Takt_1[54] = Zeiten_Geschw_Takt_1[53];
    Zeiten_Geschw_Takt_1[53] = Zeiten_Geschw_Takt_1[52];
    Zeiten_Geschw_Takt_1[52] = Zeiten_Geschw_Takt_1[51];
    Zeiten_Geschw_Takt_1[51] = Zeiten_Geschw_Takt_1[50];
    Zeiten_Geschw_Takt_1[50] = Zeiten_Geschw_Takt_1[49];
    
    Zeiten_Geschw_Takt_1[49] = Zeiten_Geschw_Takt_1[48];
    Zeiten_Geschw_Takt_1[48] = Zeiten_Geschw_Takt_1[47];
    Zeiten_Geschw_Takt_1[47] = Zeiten_Geschw_Takt_1[46];
    Zeiten_Geschw_Takt_1[46] = Zeiten_Geschw_Takt_1[45];
    Zeiten_Geschw_Takt_1[45] = Zeiten_Geschw_Takt_1[44];
    Zeiten_Geschw_Takt_1[44] = Zeiten_Geschw_Takt_1[43];
    Zeiten_Geschw_Takt_1[43] = Zeiten_Geschw_Takt_1[42];
    Zeiten_Geschw_Takt_1[42] = Zeiten_Geschw_Takt_1[41];
    Zeiten_Geschw_Takt_1[41] = Zeiten_Geschw_Takt_1[40];
    Zeiten_Geschw_Takt_1[40] = Zeiten_Geschw_Takt_1[39];
    
    Zeiten_Geschw_Takt_1[39] = Zeiten_Geschw_Takt_1[38];
    Zeiten_Geschw_Takt_1[38] = Zeiten_Geschw_Takt_1[37];
    Zeiten_Geschw_Takt_1[37] = Zeiten_Geschw_Takt_1[36];
    Zeiten_Geschw_Takt_1[36] = Zeiten_Geschw_Takt_1[35];
    Zeiten_Geschw_Takt_1[35] = Zeiten_Geschw_Takt_1[34];
    Zeiten_Geschw_Takt_1[34] = Zeiten_Geschw_Takt_1[33];
    Zeiten_Geschw_Takt_1[33] = Zeiten_Geschw_Takt_1[32];
    Zeiten_Geschw_Takt_1[32] = Zeiten_Geschw_Takt_1[31];
    Zeiten_Geschw_Takt_1[31] = Zeiten_Geschw_Takt_1[30];
    Zeiten_Geschw_Takt_1[30] = Zeiten_Geschw_Takt_1[29];
    
    Zeiten_Geschw_Takt_1[29] = Zeiten_Geschw_Takt_1[28];
    Zeiten_Geschw_Takt_1[28] = Zeiten_Geschw_Takt_1[27];
    Zeiten_Geschw_Takt_1[27] = Zeiten_Geschw_Takt_1[26];
    Zeiten_Geschw_Takt_1[26] = Zeiten_Geschw_Takt_1[25];
    Zeiten_Geschw_Takt_1[25] = Zeiten_Geschw_Takt_1[24];
    Zeiten_Geschw_Takt_1[24] = Zeiten_Geschw_Takt_1[23];
    Zeiten_Geschw_Takt_1[23] = Zeiten_Geschw_Takt_1[22];
    Zeiten_Geschw_Takt_1[22] = Zeiten_Geschw_Takt_1[21];
    Zeiten_Geschw_Takt_1[21] = Zeiten_Geschw_Takt_1[20];
    Zeiten_Geschw_Takt_1[20] = Zeiten_Geschw_Takt_1[19]; 
    
    Zeiten_Geschw_Takt_1[19] = Zeiten_Geschw_Takt_1[18];
    Zeiten_Geschw_Takt_1[18] = Zeiten_Geschw_Takt_1[17];
    Zeiten_Geschw_Takt_1[17] = Zeiten_Geschw_Takt_1[16];
    Zeiten_Geschw_Takt_1[16] = Zeiten_Geschw_Takt_1[15];
    Zeiten_Geschw_Takt_1[15] = Zeiten_Geschw_Takt_1[14];
    Zeiten_Geschw_Takt_1[14] = Zeiten_Geschw_Takt_1[13];
    Zeiten_Geschw_Takt_1[13] = Zeiten_Geschw_Takt_1[12];
    Zeiten_Geschw_Takt_1[12] = Zeiten_Geschw_Takt_1[11];
    Zeiten_Geschw_Takt_1[11] = Zeiten_Geschw_Takt_1[10];
    Zeiten_Geschw_Takt_1[10] = Zeiten_Geschw_Takt_1[9];          
          
    Zeiten_Geschw_Takt_1[9] = Zeiten_Geschw_Takt_1[8];                                      
    Zeiten_Geschw_Takt_1[8] = Zeiten_Geschw_Takt_1[7];
    Zeiten_Geschw_Takt_1[7] = Zeiten_Geschw_Takt_1[6];
    Zeiten_Geschw_Takt_1[6] = Zeiten_Geschw_Takt_1[5];
    Zeiten_Geschw_Takt_1[5] = Zeiten_Geschw_Takt_1[4];
    Zeiten_Geschw_Takt_1[4] = Zeiten_Geschw_Takt_1[3];
    Zeiten_Geschw_Takt_1[3] = Zeiten_Geschw_Takt_1[2];
    Zeiten_Geschw_Takt_1[2] = Zeiten_Geschw_Takt_1[1];
    Zeiten_Geschw_Takt_1[1] = Zeiten_Geschw_Takt_1[0];
    Zeiten_Geschw_Takt_1[0] = Stoppzeit_Geschw_Takt_1;                

    /* Letzte 5 Werte anzeigen */
    Liste(590, 92, 0, 5, Zeiten_Geschw_Takt_1, 0, 0, RED, "cpm   ");       //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
    
    /* Aktueller Wert anzeigen */
    Display.txt_Height(4);                        //Texthöhe
    Display.txt_Width(3);                         //Textweite
    Display.txt_Inverse(OFF);                     //Text invetieren
    Display.txt_Bold(OFF);                        //Text fett
    Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe Weiss
    
    Display.gfx_MoveTo(80, 85);                   //Text Position (x,y)
    Display.print(Stoppzeit_Geschw_Takt_1);       //Wert anzeigen
    Display.print(" cpm    ");                    //Text anzeigen

    Startzeit_speichern_Geschw_Takt_1 = true;     //Startzeit speichern Geschwindigkeit Takt 1 setzen
  }

/********************************************************************************************************************/

  /* Stopp Takt 2 */
  if ((Messung_aktiv_Geschw_Takt_2 == true) && (Startzeit_speichern_Geschw_Takt_2 == false) && (digitalRead(9) == LOW))
  {     
    Geschw_Stopp_Takt_2 = false;          //Stopp Takt 2 Geschwindigkeit Takt 2 zurücksetzen  
  }
      
  /* Geschwindigkeit Takt 2 gestoppt */
  if ((Messung_aktiv_Geschw_Takt_2 == true) && (Geschw_Stopp_Takt_2 == false) && (digitalRead(9) == HIGH))
  {        
    /* Stoppzeit berechnen */
    /* 100ms = 600cpm 
       500ms = 120cpm
      1000ms =  60cpm
     60000ms =   1cpm      
    */    
    Stoppzeit_Geschw_Takt_2 = (60000/(millis()- Startzeit_Geschw_Takt_2));                    //Stoppzeit Geschwindigkeit Takt 2 berechnen

    Geschw_Stopp_Takt_2 = true;                   //Stopp Takt 2 setzen     
    Messung_aktiv_Geschw_Takt_2 = false;          //Messung aktiv Geschwindgkeit Takt 2 zurücksetzen

    /* Roter Punkt anzeigen */
    Display.gfx_CircleFilled(40, 266, 20, RED);   //Status Anzeigen roter Punkt (Kreis x,y,r)      

    /* Höchstwert berechnen */
    if (Stoppzeit_Geschw_Takt_2 >= Hoechstwert_Geschw_Takt_2)
    {           
      Hoechstwert_Geschw_Takt_2 = Stoppzeit_Geschw_Takt_2;     //Höchstwert übernehmen

      /* Höchstwert anzeigen */
      Display.txt_Height(2);                        //Texthöhe
      Display.txt_Width(2);                         //Textweite
      Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe
      
      Display.gfx_MoveTo(83, 305);                  //Text Position (x,y)
      Display.print(Hoechstwert_Geschw_Takt_2);     //Wert anzeigen
      Display.print(" Hoechstwert    ");            //Text anzeigen
    }

    /* History 
       Schieberegister letzten Werte. */
    Zeiten_Geschw_Takt_2[59] = Zeiten_Geschw_Takt_2[58];
    Zeiten_Geschw_Takt_2[58] = Zeiten_Geschw_Takt_2[57];
    Zeiten_Geschw_Takt_2[57] = Zeiten_Geschw_Takt_2[56];
    Zeiten_Geschw_Takt_2[56] = Zeiten_Geschw_Takt_2[55];
    Zeiten_Geschw_Takt_2[55] = Zeiten_Geschw_Takt_2[54];
    Zeiten_Geschw_Takt_2[54] = Zeiten_Geschw_Takt_2[53];
    Zeiten_Geschw_Takt_2[53] = Zeiten_Geschw_Takt_2[52];
    Zeiten_Geschw_Takt_2[52] = Zeiten_Geschw_Takt_2[51];
    Zeiten_Geschw_Takt_2[51] = Zeiten_Geschw_Takt_2[50];
    Zeiten_Geschw_Takt_2[50] = Zeiten_Geschw_Takt_2[49];
    
    Zeiten_Geschw_Takt_2[49] = Zeiten_Geschw_Takt_2[48];
    Zeiten_Geschw_Takt_2[48] = Zeiten_Geschw_Takt_2[47];
    Zeiten_Geschw_Takt_2[47] = Zeiten_Geschw_Takt_2[46];
    Zeiten_Geschw_Takt_2[46] = Zeiten_Geschw_Takt_2[45];
    Zeiten_Geschw_Takt_2[45] = Zeiten_Geschw_Takt_2[44];
    Zeiten_Geschw_Takt_2[44] = Zeiten_Geschw_Takt_2[43];
    Zeiten_Geschw_Takt_2[43] = Zeiten_Geschw_Takt_2[42];
    Zeiten_Geschw_Takt_2[42] = Zeiten_Geschw_Takt_2[41];
    Zeiten_Geschw_Takt_2[41] = Zeiten_Geschw_Takt_2[40];
    Zeiten_Geschw_Takt_2[40] = Zeiten_Geschw_Takt_2[39];
    
    Zeiten_Geschw_Takt_2[39] = Zeiten_Geschw_Takt_2[38];
    Zeiten_Geschw_Takt_2[38] = Zeiten_Geschw_Takt_2[37];
    Zeiten_Geschw_Takt_2[37] = Zeiten_Geschw_Takt_2[36];
    Zeiten_Geschw_Takt_2[36] = Zeiten_Geschw_Takt_2[35];
    Zeiten_Geschw_Takt_2[35] = Zeiten_Geschw_Takt_2[34];
    Zeiten_Geschw_Takt_2[34] = Zeiten_Geschw_Takt_2[33];
    Zeiten_Geschw_Takt_2[33] = Zeiten_Geschw_Takt_2[32];
    Zeiten_Geschw_Takt_2[32] = Zeiten_Geschw_Takt_2[31];
    Zeiten_Geschw_Takt_2[31] = Zeiten_Geschw_Takt_2[30];
    Zeiten_Geschw_Takt_2[30] = Zeiten_Geschw_Takt_2[29];
    
    Zeiten_Geschw_Takt_2[29] = Zeiten_Geschw_Takt_2[28];
    Zeiten_Geschw_Takt_2[28] = Zeiten_Geschw_Takt_2[27];
    Zeiten_Geschw_Takt_2[27] = Zeiten_Geschw_Takt_2[26];
    Zeiten_Geschw_Takt_2[26] = Zeiten_Geschw_Takt_2[25];
    Zeiten_Geschw_Takt_2[25] = Zeiten_Geschw_Takt_2[24];
    Zeiten_Geschw_Takt_2[24] = Zeiten_Geschw_Takt_2[23];
    Zeiten_Geschw_Takt_2[23] = Zeiten_Geschw_Takt_2[22];
    Zeiten_Geschw_Takt_2[22] = Zeiten_Geschw_Takt_2[21];
    Zeiten_Geschw_Takt_2[21] = Zeiten_Geschw_Takt_2[20];
    Zeiten_Geschw_Takt_2[20] = Zeiten_Geschw_Takt_2[19];  
    
    Zeiten_Geschw_Takt_2[19] = Zeiten_Geschw_Takt_2[18];
    Zeiten_Geschw_Takt_2[18] = Zeiten_Geschw_Takt_2[17];
    Zeiten_Geschw_Takt_2[17] = Zeiten_Geschw_Takt_2[16];
    Zeiten_Geschw_Takt_2[16] = Zeiten_Geschw_Takt_2[15];
    Zeiten_Geschw_Takt_2[15] = Zeiten_Geschw_Takt_2[14];
    Zeiten_Geschw_Takt_2[14] = Zeiten_Geschw_Takt_2[13];
    Zeiten_Geschw_Takt_2[13] = Zeiten_Geschw_Takt_2[12];
    Zeiten_Geschw_Takt_2[12] = Zeiten_Geschw_Takt_2[11];
    Zeiten_Geschw_Takt_2[11] = Zeiten_Geschw_Takt_2[10];
    Zeiten_Geschw_Takt_2[10] = Zeiten_Geschw_Takt_2[9];          
          
    Zeiten_Geschw_Takt_2[9] = Zeiten_Geschw_Takt_2[8];                                      
    Zeiten_Geschw_Takt_2[8] = Zeiten_Geschw_Takt_2[7];
    Zeiten_Geschw_Takt_2[7] = Zeiten_Geschw_Takt_2[6];
    Zeiten_Geschw_Takt_2[6] = Zeiten_Geschw_Takt_2[5];
    Zeiten_Geschw_Takt_2[5] = Zeiten_Geschw_Takt_2[4];
    Zeiten_Geschw_Takt_2[4] = Zeiten_Geschw_Takt_2[3];
    Zeiten_Geschw_Takt_2[3] = Zeiten_Geschw_Takt_2[2];
    Zeiten_Geschw_Takt_2[2] = Zeiten_Geschw_Takt_2[1];
    Zeiten_Geschw_Takt_2[1] = Zeiten_Geschw_Takt_2[0];
    Zeiten_Geschw_Takt_2[0] = Stoppzeit_Geschw_Takt_2;

    /* Letzte 5 Werte anzeigen */
    Liste(590, 250, 0, 5, Zeiten_Geschw_Takt_2, 0, 0, RED, "cpm   ");      //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)

    /* Aktueller Wert anzeigen */
    Display.txt_Height(4);                        //Texthöhe
    Display.txt_Width(3);                         //Textweite
    Display.txt_Inverse(OFF);                     //Text invetieren
    Display.txt_Bold(OFF);                        //Text fett
    Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe weiss
    
    Display.gfx_MoveTo(80, 245);                  //Text Position (x,y)
    Display.print(Stoppzeit_Geschw_Takt_2);       //Wert anzeigen
    Display.print(" cpm   ");                     //Text anzeigen

    Startzeit_speichern_Geschw_Takt_2 = true;     //Startzeit speichern Geschwindigkeit Takt 2 setzen
  }
    
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
    
    /* Touch Feld abfragen [Zrugg] Taste gedrückt */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrugg] Taste ausführen */
      if (Status_Touch_Taste)
      {            
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");  //Taste anzeigen gedrückt

        Stoppzeit_Geschw_Takt_1 = 0;                  //Stoppzeit Geschwindigkeit Takt 1 zurücksetzen
        Stoppzeit_Geschw_Takt_2 = 0;                  //Stoppzeit Geschwindigkeit Takt 2 zurücksetzen

        Hoechstwert_Geschw_Takt_1 = 0;                //Höchstwert Geschwindigkeit Takt 1 zurücksetzen
        Hoechstwert_Geschw_Takt_2 = 0;                //Höchstwert Geschwindigkeit Takt 2 zurücksetzen

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 0;                         //Hauptmenü anwählen
        Bild_aufgebaut[0] = false;                    //Bildschirm aufgebaut zurücksetzen
          
        digitalWrite(DA_Versorgung_24VDC, LOW);       //Digital Ausgang Versorgung 24VDC zurücksetzen        
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

        Messung_aktiv_Geschw_Takt_1 = false;              //Messung aktiv Geschwindigkeit Takt 1 zurücksetzen
        Messung_aktiv_Geschw_Takt_2 = false;              //Messung aktiv Geschwindigkeit Takt 2 zurücksetzen
    
        /* Alle Zeiten zurücksetzen */
        for (int i = 0; i <= 59; i++)
        {
          Zeiten_Geschw_Takt_1[i] = 0;                      //Zeit Geschwindigkeit Takt 1 0-19 zurücksetzen
          Zeiten_Geschw_Takt_2[i] = 0;                      //Zeit Geschwindigkeit Takt 2 0-19 zurücksetzen 
        }

        Stoppzeit_Geschw_Takt_1 = 0;                        //Stoppzeit Geschwindigkeit Takt 1 zurücksetzen
        Stoppzeit_Geschw_Takt_2 = 0;                        //Stoppzeit Geschwindigkeit Takt 2 zurücksetzen

        Hoechstwert_Geschw_Takt_1 = 0;                      //Höchstwert Geschwindigkeit Takt 1 zurücksetzen
        Hoechstwert_Geschw_Takt_2 = 0;                      //Höchstwert Geschwindigkeit Takt 2 zurücksetzen

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Bild_aufgebaut[2] = false;                          //Bildschirm aufgebaut zurücksetzen            
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

        Messung_aktiv_Geschw_Takt_1 = false;              //Messung aktiv Geschwindigkeit Takt 1 zurücksetzen
        Messung_aktiv_Geschw_Takt_2 = false;              //Messung aktiv Geschwindigkeit Takt 2 zurücksetzen        

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
                       
        Menue_angewaehlt = 14;                                                    //Menü Geschwindigkeitsanzeige Liste anwählen
        Bild_aufgebaut[14] = false;                                               //Bildschirm aufgebaut zurücksetzen                                 
      }
    }
    
/********************************************************************************************************************/

  /* Touch Feld abfragen [Live] Taste gedrückt */
    if ((X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {     
      /* Touch Feld [Live] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 500, 420, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Live");                  //Taste anzeigen gedrückt 
        
        /* Datenausgabe auf USB Schnittstelle */  
   //     if (SerialUSB.available())      //Überwachung Schnittstelle verfügbar
   //     {

        /* [Export] Taste anzeigen Funktion aktiv */
        Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, BLACK, Schrifttyp, Textbreite, Textrahmen, "Live");                   //Taste anzeigen Funktion aktiv

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
       // for (Messungen_Analog = 0; Messungen_Analog <= Anzahl_Messungen; Messungen_Analog++)
       // {  
       //   Analogwert[Messungen_Analog] = Aktueller_Wert_Analog;         //Messwert übergeben
       //   SerialUSB.println();                                 
       //   SerialUSB.print(Messungen_Analog);                            //Ausgabe Aktuelle Messung
       //   SerialUSB.print(" Messung ");                                 //Ausgabe Text
       //   SerialUSB.print(Analogwert[Messungen_Analog]);                //Ausgabe Aktueller Messwert auf USB Schnittstelle
       //   SerialUSB.print(" bar");                                      //Ausgabe Text
 //         delay(Zeitraster_Messung);                                  //Zeitraster (Verzögerung für nächste Messung)                
       // }      
  //      }

      Display.gfx_Button(Status_Touch_Taste, 500, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Live");                   //Taste anzeigen ungedrückt 
                                                
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
        Letztes_Menue = 2;                  //Letztes angewähltes Menü          
        Info_Seite = 3;                     //Info Seite anwählen
      }
    }
    
/********************************************************************************************************************/ 
          
  }       //Touch Freigabe Ende

/********************************************************************************************************************/
 
}
