/* 53.Zähler

   Misst die Stückzahl und zeigt dann die Anzahl an. 
   Diese Funktion startet sobald der Pin 8 oder 9 auf HIGH sind. 

   Mit Umschaltung "Normal" oder "High Speed Zähler" und Master Zähler.
   
   Achtung: Bei Verwendung von PE-Wandler nur im "Normal" Zählmodus messen
            da die Wandler prellen!

*/

  void Zaehler(bool Bildaufbau, bool Werte_Reset)           //Funktion Zähler
{

/********************************************************************************************************************/

  /* Bildaufbau
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[53] == false)                   //Überwachung Bildschirm aufgebaut
  {        
    Display.gfx_Cls();            //Display löschen
    Statusanzeige();              //Aufruf Funktion Statusanzeige
  
    High_Speed_Zaehler = false;       //High Speed Zähler ausschalten
    Messung_Ein_Zaehler = false;      //Messung Ein Zähler zurücksetzen

    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Zaehler");   //Funktion Namen anzeigen

    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");            //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                                       //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 182, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset 1");                                     //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 342, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset 2");                                     //Taste anzeigen ungedrückt
    if (Master_1_Zaehler == false) Display.gfx_Button(Status_Touch_Taste, 180, 420, ORANGE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Master 1");     //Taste anzeigen ungedrückt 
    if (Master_1_Zaehler == true) Display.gfx_Button(Status_Touch_Taste, 180, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Master 1");       //Taste anzeigen geschalten
    Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Liste");                                          //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Start");                                        //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                             //Taste anzeigen gedrückt

    /* Text anzeigen */
    Display.txt_Height(2);                                      //Texthöhe
    Display.txt_Width(2);                                       //Textweite
    Display.txt_Set(TEXT_COLOUR, Texthintergrund_Menue);        //Textfarbe

    /* Sensor Bezeichung */
    Display.gfx_MoveTo(33, 182);                                //Text Position (x,y)
    Display.print("1");                                         //Text anzeigen
    Display.gfx_Circle(40, 192, 20, Texthintergrund_Menue);     //Kreis zeichnen (Kreis x,y,r)

    Display.gfx_MoveTo(33, 342);                                //Text Position (x,y)
    if (Master_1_Zaehler == false) 
    {
      Display.print("2");          //Text anzeigen  
      Display.gfx_Circle(40, 352, 20, Texthintergrund_Menue);     //Kreis zeichnen (Kreis x,y,r)
    }

    /* Normal-High Speed Anzeige */
    Display.gfx_MoveTo(80, 182);              //Text Position (x,y)  
    if (High_Speed_Zaehler == false) Display.print("L");    //Text anzeigen
    if (High_Speed_Zaehler == true) Display.print("H");     //Text anzeigen   

    Display.gfx_MoveTo(80, 342);
    if (Master_1_Zaehler == false)
    {
      if (High_Speed_Zaehler == false) Display.print("L");    //Text anzeigen
      if (High_Speed_Zaehler == true) Display.print("H");     //Text anzeigen   
    }

    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);                         //Info Kreis zeichnen (Kreis x,y,r)
        
    Display.gfx_Rectangle(0, 70, 799, 230, Texthintergrund_Menue);                //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
//    Display.gfx_Rectangle(0, 180, 65, 230, Texthintergrund_Menue);              //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 106, 20, RED);                                   //Status anzeigen roter Punkt (Kreis x,y,r)
    Display.gfx_Circle(40, 106, 21, GRAY);                                        //Kreis zeichnen (Kreis x,y,r)

    Display.gfx_Rectangle(0, 390, 799, 230, Texthintergrund_Menue);               //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
//    Display.gfx_Rectangle(0, 390, 65, 340, Texthintergrund_Menue);              //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    if (Master_1_Zaehler == false) 
    {
      Display.gfx_CircleFilled(40, 266, 20, RED);                                   //Status anzeigen roter Punkt (Kreis x,y,r)
      Display.gfx_Circle(40, 266, 21, GRAY);                                        //Kreis zeichnen (Kreis x,y,r)
    }

    /* Letzte 5 Werte anzeigen */   
    Liste(590, 92, 0, 5, Zaehlwerte_Zaehler_1,0, 0, RED, "St.   ");      //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
    if (Master_1_Zaehler == false) Liste(590, 250, 0, 5, Zaehlwerte_Zaehler_2, 0, 0, RED, "St.   ");     //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)

    Display.txt_Height(4);                            //Texthöhe
    Display.txt_Width(3);                             //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);          //Textfarbe
    Display.txt_Inverse(OFF);                         //Text invetieren
    Display.txt_Bold(OFF);                            //Text fett

    /* Aktueller Wert anzeigen */
    Display.gfx_MoveTo(80, 85);                       //Text Position (x,y)
    Display.print(Zaehlwert_Zaehler_1);               //Wert anzeigen
    Display.print(" St.   ");                         //Text anzeigen 

    Display.gfx_MoveTo(80, 245);                      //Text Position (x,y)
    Display.print(Zaehlwert_Zaehler_2);               //Wert anzeigen
    Display.print(" St.   ");                         //Text anzeigen 
    
    /* High Speed Zähler
       Für manche Anwendungen sind die Interrupte zu schnell!
     
      RISING Interrupt wird getriggert, wenn der Pin von LOW auf HIGH wechselt.   
      FALLING Interrupt wird getriggert, wenn der Pin von HIGH auf LOW wechselt. */  

    if (High_Speed_Zaehler == true)   //Mit Interrupt 
    {
      attachInterrupt(digitalPinToInterrupt(DE_Sensor_1), Interrupt_Pin_8, RISING);                                   //Interrupt Funktion -> Void (Interrupt_Pin_8)
      if (Master_1_Zaehler == false) attachInterrupt(digitalPinToInterrupt(DE_Sensor_2), Interrupt_Pin_9, RISING);    //Interrupt Funktion -> Void (Interrupt_Pin_9)
      if (Master_1_Zaehler == true)  detachInterrupt(DE_Sensor_2);                                                    //Interrupt Funktion -> Void (Interrupt_Pin_9) stoppen
    }
    
    else       //Ohne Interrupt 
    {
      detachInterrupt(DE_Sensor_1); //Interrupt Funktion -> Void (Interrupt_Pin_8) stoppen
      detachInterrupt(DE_Sensor_2); //Interrupt Funktion -> Void (Interrupt_Pin_9) stoppen
    }


 //   digitalWrite(DA_Versorgung_24VDC, HIGH);     //Digital Ausgang Versorgung 24VDC setzen
 //   delay(1000);                                //Verzögerung 1000ms 

    /* Buzzer */
    Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

    Bild_aufgebaut[53] = true;               //Bildschirm aufgebaut setzen    
  }

/********************************************************************************************************************/

  Statusanzeige();              //Aufruf Funktion Statusanzeige

/********************************************************************************************************************/

  do
  {

/********************************************************************************************************************/

    /* Messung Ein */
    if (Messung_Ein_Zaehler == true)
    { 
      Zaehlwerte_gespeichert_Zaehler = false;         //Zählwerte gespeichert Zähler zurücksetzen

/********************************************************************************************************************/

       /* Zähler 1 und 2 gestartet
       Flankenauswertung und grüner Punkt um es als aktiv anzuzeigen. */
      if ((digitalRead(DE_Sensor_1) == HIGH) && (Wert_addiert_Zaehler_1 == false) && (digitalRead(DE_Sensor_2) == HIGH) && (Wert_addiert_Zaehler_2 == false) && (Master_1_Zaehler == false))  //Überwachung Eingang Pin 8 und Pin 9
      {                              
        /* Zähler ohne Interrupt */
        if (High_Speed_Zaehler == false) Zaehlwert_Zaehler_1++;   //Zähler
        if (High_Speed_Zaehler == false) Zaehlwert_Zaehler_2++;   //Zähler    
        
        /* Grüner Punkt anzeigen */
        Display.gfx_CircleFilled(40, 106, 20, GREEN);       //Status anzeigen grüner Punkt (Kreis x,y,r)                                                          
        Display.gfx_CircleFilled(40, 266, 20, GREEN);       //Status anzeigen grüner Punkt (Kreis x,y,r) 

        /* Aktuelle Wert anzeigen Zähler 1 */
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);                        //Text fett
        Display.txt_Set(TEXT_COLOUR, GRAY);          //Textfarbe grau

        Display.gfx_MoveTo(80, 85);                   //Text Position (x,y)
        Display.print("");
        Display.print(Zaehlwert_Zaehler_1);           //Wert anzeigen
        Display.print(" St.   ");                     //Text anzeigen  

        Display.gfx_MoveTo(80, 245);                  //Text Position (x,y)
        Display.print("");
        Display.print(Zaehlwert_Zaehler_2);           //Wert anzeigen
        Display.print(" St.   ");                     //Text anzeigen   

        Wert_addiert_Zaehler_1 = true;                //Wert addiert Zähler 1 setzen
        Wert_addiert_Zaehler_2 = true;                //Wert addiert Zähler 2 setzen
      }
 
 /********************************************************************************************************************/

      /* Zähler 1 gestartet
       Flankenauswertung und grüner Punkt um es als aktiv anzuzeigen. */
      if ((digitalRead(DE_Sensor_1) == HIGH) && (digitalRead(DE_Sensor_2) == LOW) && (Wert_addiert_Zaehler_1 == false) && (Master_1_Zaehler == false))  //Überwachung Eingang Pin 8
      {                      
        /* Zähler ohne Interrupt */
        if (High_Speed_Zaehler == false) Zaehlwert_Zaehler_1++;   //Zähler

        /* Grüner Punkt anzeigen */
        Display.gfx_CircleFilled(40, 106, 20, GREEN);       //Status anzeigen grüner Punkt (Kreis x,y,r)                                                          

        /* Aktuelle Wert anzeigen Zähler 1 */
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);                        //Text fett
         Display.txt_Set(TEXT_COLOUR, GRAY);          //Textfarbe grau

        Display.gfx_MoveTo(80, 85);                   //Text Position (x,y)
        Display.print("");
        Display.print(Zaehlwert_Zaehler_1);           //Wert anzeigen
        Display.print(" St.   ");                     //Text anzeigen  

        Wert_addiert_Zaehler_1 = true;                //Wert addiert Zähler 1 setzen
      }

/********************************************************************************************************************/

      /* Zähler 2 gestartet
         Flankenauswertung Startzeit speichern und grüner Punkt um es als aktiv anzuzeigen. */
      if ((digitalRead(DE_Sensor_2) == HIGH) && (digitalRead(DE_Sensor_1) == LOW) && (Wert_addiert_Zaehler_2 == false) && (Master_1_Zaehler == false))    //Überwachung Eingang Pin 9
      {          
        /* Zähler ohne Interrupt */
        if (High_Speed_Zaehler == false) Zaehlwert_Zaehler_2++;   //Zähler  

        /* Grüner Punkt anzeigen */
        Display.gfx_CircleFilled(40, 266, 20, GREEN);       //Status anzeigen grüner Punkt (Kreis x,y,r)                                                            
 
        /* Aktuelle Wert anzeigen Zähler 2 */
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);                        //Text fett
        Display.txt_Set(TEXT_COLOUR, GRAY);           //Textfarbe grau

        Display.gfx_MoveTo(80, 245);                  //Text Position (x,y)
        Display.print("");
        Display.print(Zaehlwert_Zaehler_2);           //Wert anzeigen
        Display.print(" St.   ");                     //Text anzeigen   
        
        Wert_addiert_Zaehler_2 = true;                //Wert addiert Zähler 2 setzen
      }

/********************************************************************************************************************/ 

      /* Master Zähler 1 gestartet
       Flankenauswertung und grüner Punkt um es als aktiv anzuzeigen. */
      if ((digitalRead(DE_Sensor_1) == HIGH) && (Wert_addiert_Zaehler_1 == false) && (Master_1_Zaehler == true))  //Überwachung Eingang Pin 8
      {                      
        /* Zähler ohne Interrupt */
        if (High_Speed_Zaehler == false) 
        {
          Zaehlwert_Zaehler_1++;   //Zähler
          Zaehlwert_Zaehler_2++;   //Zähler
        }

        /* Grüner Punkt anzeigen */
        Display.gfx_CircleFilled(40, 106, 20, GREEN);       //Status anzeigen grüner Punkt (Kreis x,y,r)                                                          

        /* Aktuelle Wert anzeigen Zähler 1 */
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);                        //Text fett
         Display.txt_Set(TEXT_COLOUR, GRAY);          //Textfarbe grau

        Display.gfx_MoveTo(80, 85);                   //Text Position (x,y)
        Display.print("");
        Display.print(Zaehlwert_Zaehler_1);           //Wert anzeigen
        Display.print(" St.   ");                     //Text anzeigen  

        Display.gfx_MoveTo(80, 245);                  //Text Position (x,y)
        Display.print("");
        Display.print(Zaehlwert_Zaehler_2);           //Wert anzeigen
        Display.print(" St.   ");                     //Text anzeigen  

        Wert_addiert_Zaehler_1 = true;                //Wert addiert Zähler 1 setzen
      }

/********************************************************************************************************************/

      /* Zählwert addiert Zähler 1 zurücksetzen */
      if (digitalRead(DE_Sensor_1) == LOW)// && (digitalRead(DE_Sensor_2) == HIGH))
      {
        Freigabe_Interrupt_Zaehler_1 = true;        //Freigabe Interrupt Zähler 1 setzen
        Wert_addiert_Zaehler_1 = false;             //Wert addiert Zähler 1 zurücksetzen
      }

/********************************************************************************************************************/

      /* Zählwert addiert Zähler 2 zurücksetzen */
      if (digitalRead(DE_Sensor_2) == LOW)// && (digitalRead(DE_Sensor_1) == HIGH))
      {
        Freigabe_Interrupt_Zaehler_2 = true;        //Freigabe Interrupt Zähler 2 setzen
        Wert_addiert_Zaehler_2 = false;             //Wert addiert Zähler 2 zurücksetzen
      }

 /********************************************************************************************************************/

    }   

/********************************************************************************************************************/
        
    /* Messung gestoppt */
    if (Messung_Ein_Zaehler == false)              //Messung gestoppt
    {              
      /* Zählwerte speichern */
      if (Zaehlwerte_gespeichert_Zaehler == false)
      {
        /* Roter Punkt anzeigen */
        Display.gfx_CircleFilled(40, 106, 20, RED);       //Status anzeigen roter Punkt (Kreis x,y,r)  
        if (Master_1_Zaehler == false) Display.gfx_CircleFilled(40, 266, 20, RED);       //Status anzeigen roter Punkt (Kreis x,y,r)

        /* History 
           Schieberegister letzten Werte. */
        Zaehlwerte_Zaehler_1[59] = Zaehlwerte_Zaehler_1[58];
        Zaehlwerte_Zaehler_1[58] = Zaehlwerte_Zaehler_1[57];
        Zaehlwerte_Zaehler_1[57] = Zaehlwerte_Zaehler_1[56];
        Zaehlwerte_Zaehler_1[56] = Zaehlwerte_Zaehler_1[55];
        Zaehlwerte_Zaehler_1[55] = Zaehlwerte_Zaehler_1[54];
        Zaehlwerte_Zaehler_1[54] = Zaehlwerte_Zaehler_1[53];
        Zaehlwerte_Zaehler_1[53] = Zaehlwerte_Zaehler_1[52];
        Zaehlwerte_Zaehler_1[52] = Zaehlwerte_Zaehler_1[51];
        Zaehlwerte_Zaehler_1[51] = Zaehlwerte_Zaehler_1[50];
        Zaehlwerte_Zaehler_1[50] = Zaehlwerte_Zaehler_1[49];
               
        Zaehlwerte_Zaehler_1[49] = Zaehlwerte_Zaehler_1[48];
        Zaehlwerte_Zaehler_1[48] = Zaehlwerte_Zaehler_1[47];
        Zaehlwerte_Zaehler_1[47] = Zaehlwerte_Zaehler_1[46];
        Zaehlwerte_Zaehler_1[46] = Zaehlwerte_Zaehler_1[45];
        Zaehlwerte_Zaehler_1[45] = Zaehlwerte_Zaehler_1[44];
        Zaehlwerte_Zaehler_1[44] = Zaehlwerte_Zaehler_1[43];
        Zaehlwerte_Zaehler_1[43] = Zaehlwerte_Zaehler_1[42];
        Zaehlwerte_Zaehler_1[42] = Zaehlwerte_Zaehler_1[41];
        Zaehlwerte_Zaehler_1[41] = Zaehlwerte_Zaehler_1[40];
        Zaehlwerte_Zaehler_1[40] = Zaehlwerte_Zaehler_1[39];
               
        Zaehlwerte_Zaehler_1[39] = Zaehlwerte_Zaehler_1[38];
        Zaehlwerte_Zaehler_1[38] = Zaehlwerte_Zaehler_1[37];
        Zaehlwerte_Zaehler_1[37] = Zaehlwerte_Zaehler_1[36];
        Zaehlwerte_Zaehler_1[36] = Zaehlwerte_Zaehler_1[35];
        Zaehlwerte_Zaehler_1[35] = Zaehlwerte_Zaehler_1[34];
        Zaehlwerte_Zaehler_1[34] = Zaehlwerte_Zaehler_1[33];
        Zaehlwerte_Zaehler_1[33] = Zaehlwerte_Zaehler_1[32];
        Zaehlwerte_Zaehler_1[32] = Zaehlwerte_Zaehler_1[31];
        Zaehlwerte_Zaehler_1[31] = Zaehlwerte_Zaehler_1[30];
        Zaehlwerte_Zaehler_1[30] = Zaehlwerte_Zaehler_1[29];
                           
        Zaehlwerte_Zaehler_1[29] = Zaehlwerte_Zaehler_1[28];
        Zaehlwerte_Zaehler_1[28] = Zaehlwerte_Zaehler_1[27];
        Zaehlwerte_Zaehler_1[27] = Zaehlwerte_Zaehler_1[26];
        Zaehlwerte_Zaehler_1[26] = Zaehlwerte_Zaehler_1[25];
        Zaehlwerte_Zaehler_1[25] = Zaehlwerte_Zaehler_1[24];
        Zaehlwerte_Zaehler_1[24] = Zaehlwerte_Zaehler_1[23];
        Zaehlwerte_Zaehler_1[23] = Zaehlwerte_Zaehler_1[22];
        Zaehlwerte_Zaehler_1[22] = Zaehlwerte_Zaehler_1[21];
        Zaehlwerte_Zaehler_1[21] = Zaehlwerte_Zaehler_1[20];
        Zaehlwerte_Zaehler_1[20] = Zaehlwerte_Zaehler_1[19];

        Zaehlwerte_Zaehler_1[19] = Zaehlwerte_Zaehler_1[18];
        Zaehlwerte_Zaehler_1[18] = Zaehlwerte_Zaehler_1[17];
        Zaehlwerte_Zaehler_1[17] = Zaehlwerte_Zaehler_1[16];
        Zaehlwerte_Zaehler_1[16] = Zaehlwerte_Zaehler_1[15];
        Zaehlwerte_Zaehler_1[15] = Zaehlwerte_Zaehler_1[14];
        Zaehlwerte_Zaehler_1[14] = Zaehlwerte_Zaehler_1[13];
        Zaehlwerte_Zaehler_1[13] = Zaehlwerte_Zaehler_1[12];
        Zaehlwerte_Zaehler_1[12] = Zaehlwerte_Zaehler_1[11];
        Zaehlwerte_Zaehler_1[11] = Zaehlwerte_Zaehler_1[10];
        Zaehlwerte_Zaehler_1[10] = Zaehlwerte_Zaehler_1[9];
                   
        Zaehlwerte_Zaehler_1[9] = Zaehlwerte_Zaehler_1[8];                      
        Zaehlwerte_Zaehler_1[8] = Zaehlwerte_Zaehler_1[7];
        Zaehlwerte_Zaehler_1[7] = Zaehlwerte_Zaehler_1[6];
        Zaehlwerte_Zaehler_1[6] = Zaehlwerte_Zaehler_1[5];
        Zaehlwerte_Zaehler_1[5] = Zaehlwerte_Zaehler_1[4];
        Zaehlwerte_Zaehler_1[4] = Zaehlwerte_Zaehler_1[3];
        Zaehlwerte_Zaehler_1[3] = Zaehlwerte_Zaehler_1[2];
        Zaehlwerte_Zaehler_1[2] = Zaehlwerte_Zaehler_1[1];
        Zaehlwerte_Zaehler_1[1] = Zaehlwerte_Zaehler_1[0];
        Zaehlwerte_Zaehler_1[0] = Zaehlwert_Zaehler_1;             

        /* History 
           Schieberegister letzten Werte. */
        Zaehlwerte_Zaehler_2[59] = Zaehlwerte_Zaehler_2[58];
        Zaehlwerte_Zaehler_2[58] = Zaehlwerte_Zaehler_2[57];
        Zaehlwerte_Zaehler_2[57] = Zaehlwerte_Zaehler_2[56];
        Zaehlwerte_Zaehler_2[56] = Zaehlwerte_Zaehler_2[55];
        Zaehlwerte_Zaehler_2[55] = Zaehlwerte_Zaehler_2[54];
        Zaehlwerte_Zaehler_2[54] = Zaehlwerte_Zaehler_2[53];
        Zaehlwerte_Zaehler_2[53] = Zaehlwerte_Zaehler_2[52];
        Zaehlwerte_Zaehler_2[52] = Zaehlwerte_Zaehler_2[51];
        Zaehlwerte_Zaehler_2[51] = Zaehlwerte_Zaehler_2[50];
        Zaehlwerte_Zaehler_2[50] = Zaehlwerte_Zaehler_2[49];

        Zaehlwerte_Zaehler_2[49] = Zaehlwerte_Zaehler_2[48];
        Zaehlwerte_Zaehler_2[48] = Zaehlwerte_Zaehler_2[47];
        Zaehlwerte_Zaehler_2[47] = Zaehlwerte_Zaehler_2[46];
        Zaehlwerte_Zaehler_2[46] = Zaehlwerte_Zaehler_2[45];
        Zaehlwerte_Zaehler_2[45] = Zaehlwerte_Zaehler_2[44];
        Zaehlwerte_Zaehler_2[44] = Zaehlwerte_Zaehler_2[43];
        Zaehlwerte_Zaehler_2[43] = Zaehlwerte_Zaehler_2[42];
        Zaehlwerte_Zaehler_2[42] = Zaehlwerte_Zaehler_2[41];
        Zaehlwerte_Zaehler_2[41] = Zaehlwerte_Zaehler_2[40];
        Zaehlwerte_Zaehler_2[40] = Zaehlwerte_Zaehler_2[39];

        Zaehlwerte_Zaehler_2[39] = Zaehlwerte_Zaehler_2[38];
        Zaehlwerte_Zaehler_2[38] = Zaehlwerte_Zaehler_2[37];
        Zaehlwerte_Zaehler_2[37] = Zaehlwerte_Zaehler_2[36];
        Zaehlwerte_Zaehler_2[36] = Zaehlwerte_Zaehler_2[35];
        Zaehlwerte_Zaehler_2[35] = Zaehlwerte_Zaehler_2[34];
        Zaehlwerte_Zaehler_2[34] = Zaehlwerte_Zaehler_2[33];
        Zaehlwerte_Zaehler_2[33] = Zaehlwerte_Zaehler_2[32];
        Zaehlwerte_Zaehler_2[32] = Zaehlwerte_Zaehler_2[31];
        Zaehlwerte_Zaehler_2[31] = Zaehlwerte_Zaehler_2[30];
        Zaehlwerte_Zaehler_2[30] = Zaehlwerte_Zaehler_2[29];
               
        Zaehlwerte_Zaehler_2[29] = Zaehlwerte_Zaehler_2[28];
        Zaehlwerte_Zaehler_2[28] = Zaehlwerte_Zaehler_2[27];
        Zaehlwerte_Zaehler_2[27] = Zaehlwerte_Zaehler_2[26];
        Zaehlwerte_Zaehler_2[26] = Zaehlwerte_Zaehler_2[25];
        Zaehlwerte_Zaehler_2[25] = Zaehlwerte_Zaehler_2[24];
        Zaehlwerte_Zaehler_2[24] = Zaehlwerte_Zaehler_2[23];
        Zaehlwerte_Zaehler_2[23] = Zaehlwerte_Zaehler_2[22];
        Zaehlwerte_Zaehler_2[22] = Zaehlwerte_Zaehler_2[21];
        Zaehlwerte_Zaehler_2[21] = Zaehlwerte_Zaehler_2[20];
        Zaehlwerte_Zaehler_2[20] = Zaehlwerte_Zaehler_2[19];
      
        Zaehlwerte_Zaehler_2[19] = Zaehlwerte_Zaehler_2[18];
        Zaehlwerte_Zaehler_2[18] = Zaehlwerte_Zaehler_2[17];
        Zaehlwerte_Zaehler_2[17] = Zaehlwerte_Zaehler_2[16];
        Zaehlwerte_Zaehler_2[16] = Zaehlwerte_Zaehler_2[15];
        Zaehlwerte_Zaehler_2[15] = Zaehlwerte_Zaehler_2[14];
        Zaehlwerte_Zaehler_2[14] = Zaehlwerte_Zaehler_2[13];
        Zaehlwerte_Zaehler_2[13] = Zaehlwerte_Zaehler_2[12];
        Zaehlwerte_Zaehler_2[12] = Zaehlwerte_Zaehler_2[11];
        Zaehlwerte_Zaehler_2[11] = Zaehlwerte_Zaehler_2[10];
        Zaehlwerte_Zaehler_2[10] = Zaehlwerte_Zaehler_2[9];
         
        Zaehlwerte_Zaehler_2[9] = Zaehlwerte_Zaehler_2[8];                 
        Zaehlwerte_Zaehler_2[8] = Zaehlwerte_Zaehler_2[7];
        Zaehlwerte_Zaehler_2[7] = Zaehlwerte_Zaehler_2[6];
        Zaehlwerte_Zaehler_2[6] = Zaehlwerte_Zaehler_2[5];
        Zaehlwerte_Zaehler_2[5] = Zaehlwerte_Zaehler_2[4];
        Zaehlwerte_Zaehler_2[4] = Zaehlwerte_Zaehler_2[3];
        Zaehlwerte_Zaehler_2[3] = Zaehlwerte_Zaehler_2[2];
        Zaehlwerte_Zaehler_2[2] = Zaehlwerte_Zaehler_2[1];
        Zaehlwerte_Zaehler_2[1] = Zaehlwerte_Zaehler_2[0];              
        Zaehlwerte_Zaehler_2[0] = Zaehlwert_Zaehler_2; 

        /* Letzte 5 Werte anzeigen */
        Liste(590, 92, 0, 5, Zaehlwerte_Zaehler_1, 0, 0, RED, "St.   ");     //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
        if (Master_1_Zaehler == false) Liste(590, 250, 0, 5, Zaehlwerte_Zaehler_2, 0, 0, RED, "St.   ");     //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)

        /* Aktueller Wert anzeigen */
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);                        //Text fett
        Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe
      
        Display.gfx_MoveTo(80, 85);                   //Text Position (x,y)
        Display.print("");
        Display.print(Zaehlwert_Zaehler_1);           //Wert anzeigen
        Display.print(" St.   ");                     //Text anzeigen
      
        Display.gfx_MoveTo(80, 245);                  //Text Position (x,y)
        Display.print("");
        Display.print(Zaehlwert_Zaehler_2);           //Wert anzeigen
        Display.print(" St.   ");                     //Text anzeigen

        /* Verzögerung für nächste Messung */
        delay(100);                                   //Verzögerung 100ms

        Zaehlwerte_gespeichert_Zaehler = true;        //Zählwerte gespeichert Zähler setzen
      }
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

      /* Touch Feld abfragen [Start] Taste gedrückt (Doppel Taste Start/Stopp)
         Es wird die Stopp Taste angezeigt! */
      if ((Messung_Ein_Zaehler == false) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {     
        /* Touch Feld [Start] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 500, 420, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Stopp");                  //Taste anzeigen gedrückt 

          /* Taste anzeigen nicht drückbar */
          Display.gfx_Button(Status_Touch_Taste, 650, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Zrugg");           //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 350, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");           //Taste anzeigen ungedrückt
          Display.gfx_Button(Status_Touch_Taste, 350, 182, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset 1");         //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 350, 342, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset 2");         //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 180, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Master 1");        //Taste anzeigen geschalten
          Display.gfx_Button(Status_Touch_Taste, 50, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Liste");            //Taste anzeigen nicht drückbar

          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          digitalWrite(DA_Versorgung_24VDC, HIGH);      //Digital Ausgang Versorgung 24VDC setzen
          delay(1000);                                  //Verzögerung 1000ms
          
          /* Messung Ein */
          Messung_Ein_Zaehler = true;             //Messung Ein Zähler setzen
          Freigabe_Interrupt_Zaehler_1 = true;    //Freigabe Interrupt Zähler 1 setzen
          Freigabe_Interrupt_Zaehler_2 = true;    //Freigabe Interrupt Zähler 2 setzen

          Statusanzeige();              //Aufruf Funktion Statusanzeige           
        }
      }
    
/********************************************************************************************************************/

      /* Touch Feld abfragen [Stopp] Taste gedrückt (Doppel Taste Start/Stopp)
         Es wird die Start Taste angezeigt! */
      if ((Messung_Ein_Zaehler == true) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {
        Status_Touch_Taste = !Status_Touch_Taste;                                               //Status Taste Invertieren
           
        /* Touch Feld [Stopp] Taste ausführen */
        if (Status_Touch_Taste)
        { 
          Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Start");                  //Taste anzeigen gedrückt

          /* Taste anzeigen ungedrückt anzeigen */
          Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");    //Taste anzeigen ungedrückt
          Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt          
          Display.gfx_Button(Status_Touch_Taste, 350, 182, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset 1");                              //Taste anzeigen ungedrückt
          Display.gfx_Button(Status_Touch_Taste, 350, 342, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset 2");                             //Taste anzeigen ungedrückt
          if (Master_1_Zaehler == false) Display.gfx_Button(Status_Touch_Taste, 180, 420, ORANGE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Master 1");     //Taste anzeigen ungedrückt 
          if (Master_1_Zaehler == true) Display.gfx_Button(Status_Touch_Taste, 180, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Master 1");       //Taste anzeigen geschalten
          Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Liste");                                  //Taste anzeigen ungedrückt

          /* Messung Aus */      
          Messung_Ein_Zaehler = false;              //Messung Ein Zähler zurücksetzen      
          Freigabe_Interrupt_Zaehler_1 = false;     //Freigabe Interrupt Zähler 1 zurücksetzen
          Freigabe_Interrupt_Zaehler_2 = false;     //Freigabe Interrupt Zähler 2 zurücksetzen

          /* Buzzer */
          Buzzer(500);                        //Aufruf Funktion Buzzer(int Buzzer_Zeit) 
          
          delay(1000);                                  //Verzögerung 1000ms
          digitalWrite(DA_Versorgung_24VDC, LOW);     //Digital Ausgang Versorgung 24VDC zurücksetzen                       
        }
      }
        
/********************************************************************************************************************/

      /* Touch Feld abfragen [Zrugg] Taste gedrückt */
      if ((Messung_Ein_Zaehler == false) && (X_Pos_Touch >= 620) && (X_Pos_Touch <= 720) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {
        /* Touch Feld [Zrugg] Taste ausführen */
        if (Status_Touch_Taste)
        {     
          Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");     //Taste anzeigen gedrückt
        
          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          
          Menue_angewaehlt = 50;               //Hauptmenü anwählen
          Bild_aufgebaut[50] = false;          //Bildschirm aufgebaut zurücksetzen

          digitalWrite(DA_Versorgung_24VDC, LOW);               //Digital Ausgang 24VDC Versorgung zurücksetzen         
        }
      }
    
/********************************************************************************************************************/
      
      /* Touch Feld abfragen [Reset 1] Taste gedrückt */
      if ((Messung_Ein_Zaehler == false) && (X_Pos_Touch >= 320) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 152) && (Y_Pos_Touch <= 212))   //Überwachung Touch Feld
      {
        /* Touch Feld [Reset 1] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 350, 182, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET 1");                     //Taste anzeigen gedrückt

          Wert_addiert_Zaehler_1 = true;            //Wert addiert Zähler 1 zurücksetzen

          /* Alle Zählwerte zurücksetzen */
          for (int i = 0; i <= 59; i++)
          {
            Zaehlwerte_Zaehler_1[i] = 0;            //Zählwerte Zähler 1 0-59 zurücksetzen
          }

          Zaehlwert_Zaehler_1 = 0;                  //Zählwert Zähler 1 zurücksetzen
          
          /* Buzzer */
          Buzzer(100);                              //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
          /* Bildschirm neu aufbauen */
          Bild_aufgebaut[53] = false;               //Bildschirm aufgebaut zurücksetzen
        }
      }

/********************************************************************************************************************/

      /* Touch Feld abfragen [Reset 2] Taste gedrückt */
      if ((Messung_Ein_Zaehler == false) && (X_Pos_Touch >= 320) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 312) && (Y_Pos_Touch <= 372))   //Überwachung Touch Feld
      {
        /* Touch Feld [Reset 2] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 350, 342, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET 2");                     //Taste anzeigen gedrückt

          Wert_addiert_Zaehler_2 = true;                //Wert addiert Zähler 2 zurücksetzen

          /* Alle Zählwerte zurücksetzen */
          for (int i = 0; i <= 59; i++)
          {
            Zaehlwerte_Zaehler_2[i] = 0;                //Zählwerte Zähler 2 0-59 zurücksetzen 
          }

          Zaehlwert_Zaehler_2 = 0;                      //Zählwert Zähler 2 zurücksetzen
          
          /* Buzzer */
          Buzzer(100);                                  //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
          /* Bildschirm neu aufbauen */
          Bild_aufgebaut[53] = false;                   //Bildschirm aufgebaut zurücksetzen
        }
      }

 /********************************************************************************************************************/

    /* Touch Feld abfragen [Reset] Taste gedrückt */
    if ((Messung_Ein_Zaehler == false) && (X_Pos_Touch >= 320) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Reset] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET");                  //Taste anzeigen gedrückt

        /* Alle Zeiten zurücksetzen */
        for (int i = 0; i <= 59; i++)
        {
          Zaehlwerte_Zaehler_1[i] = 0;                //Zählwerte Zähler 1 0-59 zurücksetzen
          Zaehlwerte_Zaehler_2[i] = 0;                //Zählwerte Zähler 2 0-59 zurücksetzen 
        }

        Zaehlwert_Zaehler_1 = 0;                      //Zählwert Zähler 1 zurücksetzen
        Zaehlwert_Zaehler_2 = 0;                      //Zählwert Zähler 2 zurücksetzen

        Listen_Startwert_Zaehler = 0;                 //Listen Startwert zurücksetzen
        
        Master_1_Zaehler = false;                     //Master 1 Zähler zurücksetzen

        /* Buzzer */
        Buzzer(100);                                  //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Bild_aufgebaut[53] = false;                   //Bildschirm aufgebaut zurücksetzen        
      }
    } 

/********************************************************************************************************************/

    /* Touch Feld abfragen [Master 1] Taste gedrückt 
       Taste nur auswerten, wenn Messung nicht mehr aktiv ist */
    if ((Messung_Ein_Zaehler == false) && (X_Pos_Touch >= 150) && (X_Pos_Touch <= 330) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450) && (Messung_aktiv_Stoppuhr == false))   //Überwachung Touch Feld
    {     
      /* Touch Feld [Referenz] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 180, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Master 1");                  //Taste anzeigen gedrückt 

        Master_1_Zaehler = true;                    //Master 1 Zähler setzen

        /* Buzzer */
        Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit)  
        
        Bild_aufgebaut[53] = false;                   //Bildschirm aufgebaut zurücksetzen                                                                          
      }
    }

/********************************************************************************************************************/

      /* Touch Feld abfragen [Liste] Taste gedrückt */
      /* Feld Grösse bestimmen:  X von Pos. = Feld Pos. -30 / X bis Pos. = Feld Pos. +100                         
                                 Y von Pos. = Feld Pos. -30 / Y bis Pos. = Feld Pos. +30   
      */
      if ((Messung_Ein_Zaehler == false) && (X_Pos_Touch >= 20) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {     
        /* Touch Feld [Liste] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Liste");                  //Taste anzeigen gedrückt 
          
          /* Messung stoppen */
          Messung_Ein_Zaehler = false;        //Messung Ein Zähler zurücksetzen 

          /* Buzzer */
          Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
          Menue_angewaehlt = 54;                //Menü Zähler Liste anwählen
          Bild_aufgebaut[54] = false;           //Bildschirm aufgebaut zurücksetzen    
        }
      }

/********************************************************************************************************************/

      /* Touch Feld abfragen [i] Taste gedrückt */
      if ((Messung_Ein_Zaehler == false) && (X_Pos_Touch >= 720) && (X_Pos_Touch <= 799) && (Y_Pos_Touch >= 0) && (Y_Pos_Touch <= 45))    //Überwachung Touch Feld
      {
        /* Touch Feld [i] Taste ausführen */
        if (Status_Touch_Taste)
        {
          Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, GRAY, Schrifttyp, Textbreite, Textrahmen, "i");                  //Taste anzeigen gedrückt

          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
          Menue_angewaehlt = 7;               //Menü Info anwählen
          Bild_aufgebaut[7] = false;          //Bildschirm Info aufgebaut zurücksetzen
          Letztes_Menue = 53;                 //Letztes angewähltes Menü
          Info_Seite = 22;                    //Info Seite anwählen        
        }
      }
            
/********************************************************************************************************************/

    }       //Touch Freigabe Ende

/********************************************************************************************************************/
  
  } while (Messung_Ein_Zaehler == true);        /* Überwachung Messung eingeschaltet, 
                                                       Schlaufe wird wiederholt bis gestoppt wird! */

/********************************************************************************************************************/

  /* Daten Speichern */
//  File dataFile = SD.open("log.txt", FILE_WRITE);
//  if(dataFile)
//  {
    /* SD Karte Status OK anzeigen */
//    Display.txt_Height(2);                            //Texthöhe
//    Display.txt_Width(2);                             //Textweite
//    Display.txt_Set(TEXT_COLOUR, GREEN);              //Textfarbe

//    Display.gfx_MoveTo(710, 35);                      //Text Position (x,y)
//    Display.print("SD");                              //Text anzeigen
       
//    dataFile.println(Zaehlwert_Zaehler_1);
//    dataFile.println(Zaehlwert_Zaehler_2);    
//    dataFile.close();  
//    delay (3000);
//  }
//  else
//  {
    /* SD Karte Status Error anzeigen */    
//    Display.txt_Height(2);                            //Texthöhe
//    Display.txt_Width(2);                             //Textweite
//    Display.txt_Set(TEXT_COLOUR, RED);                //Textfarbe

//    Display.gfx_MoveTo(710, 35);                      //Text Position (x,y)
//    Display.print("SD");                              //Text anzeigen
      
//    Serial.println("error opening serlog.txt");
//  }

/********************************************************************************************************************/
  
}
