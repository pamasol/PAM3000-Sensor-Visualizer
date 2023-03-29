/* 1.Doppel-Stoppuhr
   
   Im void Doppel-Stoppuhr wird nur das Display aufgebaut. Die Funktion der Zeitmessung ist im void Loop Case 6 und 7. 
*/

void D_Stoppuhr(bool Bildaufbau, bool Werte_Reset)       //Funktion Doppel-Stoppuhr
{
   
/********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[1] == false)     //Überwachung Bildschirm aufgebaut
  { 
    Display.gfx_Cls();            //Display löschen     
    Statusanzeige();              //Aufruf Funktion Statusanzeige
       
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Doppel-Stoppuhr");   //Funktion Namen anzeigen
    
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
    Display.gfx_Circle(767, 30, 22, WHITE);                                 //Info Kreis zeichnen (Kreis x,y,r)
        
    Display.gfx_Rectangle(0, 70, 799, 230, Texthintergrund_Menue);          //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 106, 20, RED);                             //Status anzeigen roter Punkt (Kreis x,y,r)
    Display.gfx_Circle(40, 106, 21, GRAY);                                  //Kreis zeichnen (Kreis x,y,r)
        
    Display.gfx_Rectangle(0, 390, 799, 230, Texthintergrund_Menue);         //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 266, 20, RED);                             //Status anzeigen roter Punkt (Kreis x,y,r)
    Display.gfx_Circle(40, 266, 21, GRAY);                                  //Kreis zeichnen (Kreis x,y,r)
    
    /* Letzte 5 Werte anzeigen */ 
    Liste(540, 92, 0, 5, Zeiten_D_Stoppuhr_1, Mittelwert_D_Stoppuhr_1, 1, BLUE, "ms     ");       //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
    Liste(540, 250, 0, 5, Zeiten_D_Stoppuhr_2, Mittelwert_D_Stoppuhr_2, 1, BLUE, "ms     ");      //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
 
    Display.txt_Height(4);                    //Texthöhe
    Display.txt_Width(3);                     //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);  //Textfarbe
    Display.txt_Inverse(OFF);                 //Text invetieren
    Display.txt_Bold(OFF);                    //Text fett
    
    Display.gfx_MoveTo(80, 85);               //Text Position (x,y)
    Display.print("0 ms       ");             //Text anzeigen

    Display.gfx_MoveTo(80, 245);              //Text Position (x,y)
    Display.print("0 ms       ");             //Text anzeigen
  
    Display.txt_Height(2);                    //Texthöhe
    Display.txt_Width(2);                     //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);  //Textfarbe
    
    Display.gfx_MoveTo(300, 85);              //Text Position (x,y)
    Display.print("0 : 0 : 0     ");          //Text anzeigen
  
    Display.gfx_MoveTo(300, 245);             //Text Position (x,y)
    Display.print("0 : 0 : 0     ");          //Text anzeigen

    /* Höchstwert anzeigen */
    Display.gfx_MoveTo(83, 145);                      //Text Position (x,y)
    Display.print(Hoechstwert_D_Stoppuhr_1);          //Wert anzeigen
    Display.print(" Hoechstwert    ");                //Text anzeigen

    Display.gfx_MoveTo(83, 305);                      //Text Position (x,y)
    Display.print(Hoechstwert_D_Stoppuhr_2);          //Wert anzeigen
    Display.print(" Hoechstwert    ");                //Text anzeigen
    
    /* Mittelwert anzeigen */
    Display.gfx_MoveTo(83, 170);                    //Text Position (x,y)
    Display.print(Mittelwert_D_Stoppuhr_1);         //Wert anzeigen
    Display.print(" Mittelwert (");                 //Text anzeigen
    Display.print(Messungen_D_Stoppuhr_1);          //Wert anzeigen
    Display.print(" Werte) ");                      //Text anzeigen

    Display.gfx_MoveTo(83, 330);                    //Text Position (x,y)
    Display.print(Mittelwert_D_Stoppuhr_2);         //Wert anzeigen
    Display.print(" Mittelwert (");                 //Text anzeigen
    Display.print(Messungen_D_Stoppuhr_2);          //Wert anzeigen
    Display.print(" Werte) ");                      //Text anzeigen

    /* Kleinstwert anzeigen 
       0 anzeigen damit nicht 9999 angezeigt wird! */
    Display.gfx_MoveTo(83, 195);                    //Text Position (x,y)
    if (Kleinstwert_D_Stoppuhr_1 < 9999)            //Werte kleiner 9999 angezeigen!
    {
      Display.print(Kleinstwert_D_Stoppuhr_1);      //Wert anzeigen
      Display.print(" Kleinstwert    ");            //Text anzeigen
    }
    else
    {
      Display.print("0 Kleinstwert    ");           //Text anzeigen              
    }
    
    Display.gfx_MoveTo(83, 355);                    //Text Position (x,y)       
    if (Kleinstwert_D_Stoppuhr_2 < 9999)            //Werte kleiner 9999 angezeigen!
    { 
      Display.print(Kleinstwert_D_Stoppuhr_2);      //Wert anzeigen
      Display.print(" Kleinstwert    ");            //Text anzeigen
    }
    else
    {
      Display.print("0 Kleinstwert    ");            //Text anzeigen              
    }

    /* Interrupte stoppen 
       Wenn Interrupte aktiviert sind stimmen die millis nicht mehr!! */
    detachInterrupt(DE_Sensor_1); //Interrupt Funktion -> Void (Interrupt_Pin_8) stoppen
    detachInterrupt(DE_Sensor_2); //Interrupt Funktion -> Void (Interrupt_Pin_9) stoppen
  
    digitalWrite(DA_Versorgung_24VDC, HIGH);                  //Digital Ausgang Versorgung 24VDC setzen    

    /* Buzzer */
    Buzzer(100);                              //Aufruf Funktion Buzzer(int Buzzer_Zeit)

    Bild_aufgebaut[1] = true;                 //Bildschirm aufgebaut setzen       
  }

/********************************************************************************************************************/

 // Statusanzeige();              //Aufruf Funktion Statusanzeige
  
/********************************************************************************************************************/

//  do
//  {

/********************************************************************************************************************/

    /* Messung aktiv Doppel-Stoppuhr 1 oder 2 */
    if ((digitalRead(DE_Sensor_1) == HIGH) || (digitalRead(DE_Sensor_2) == HIGH))           //Überwachung Eingang Pin 8 und Pin 9
    {
      /* Texteinstellungen Aktueller Wert anzeigen */
      Display.txt_Height(4);                        //Texthöhe
      Display.txt_Width(3);                         //Textweite
      Display.txt_Inverse(OFF);                     //Text invetieren
      Display.txt_Bold(OFF);                        //Text fett
      Display.txt_Set(TEXT_COLOUR, GRAY);           //Textfarbe grau   
       
      /* Stoppuhr 1 und 2 gestartet
         Flankenauswertung Startzeit speichern und Grüner Punkt um es als aktiv anzuzeigen. */
      if ((digitalRead(DE_Sensor_1) == HIGH) && (Startzeit_speichern_D_Stoppuhr_1 == true) && (digitalRead(DE_Sensor_2) == HIGH) && (Startzeit_speichern_D_Stoppuhr_2 == true))
      {           
        /* Startzeit speichern */
        Startzeit_D_Stoppuhr_1 = millis();                    //Startzeit Doppel-Stoppuhr 1 auslesen
        Startzeit_D_Stoppuhr_2 = Startzeit_D_Stoppuhr_1;      //Startzeit Doppel-Stoppuhr 2 auslesen
        Startzeit_speichern_D_Stoppuhr_1 = false;             //Startzeit speichern Doppel-Stoppuhr 1 zurücksetzen
        Stoppzeit_speichern_D_Stoppuhr_1 = true;              //Stoppzeit speichern Doppel-Stoppuhr 1 setzen
        Startzeit_speichern_D_Stoppuhr_2 = false;             //Startzeit speichern Doppel-Stoppuhr 2 zurücksetzen
        Stoppzeit_speichern_D_Stoppuhr_2 = true;              //Stoppzeit speichern Doppel-Stoppuhr 2 setzen
      
        /* Grüner Punkt anzeigen */
        Display.gfx_CircleFilled(40, 106, 20, GREEN);         //Status anzeigen grüner Punkt (Kreis x,y,r)
        Display.gfx_CircleFilled(40, 266, 20, GREEN);         //Status anzeigen grüner Punkt (Kreis x,y,r)              
      }

/********************************************************************************************************************/

      /* Doppel-Stoppuhr 1 gestartet
         Flankenauswertung Startzeit speichern und Grüner Punkt um es als aktiv anzuzeigen. */
      if ((digitalRead(DE_Sensor_1) == HIGH) && (Startzeit_speichern_D_Stoppuhr_1 == true))
      {           
        /* Startzeit speichern */
        Startzeit_D_Stoppuhr_1 = millis();                    //Startzeit Doppel-Stoppuhr 1 auslesen
        Startzeit_speichern_D_Stoppuhr_1 = false;             //Startzeit speichern Doppel-Stoppuhr 1 zurücksetzen
        Stoppzeit_speichern_D_Stoppuhr_1 = true;              //Stoppzeit speichern Doppel-Stoppuhr 1 setzen

        /* Grüner Punkt anzeigen */
        Display.gfx_CircleFilled(40, 106, 20, GREEN);         //Status anzeigen grüner Punkt (Kreis x,y,r)           
      }

/********************************************************************************************************************/

      /* Doppel-Stoppuhr 2 gestartet
         Flankenauswertung Startzeit speichern und Grüner Punkt um es als aktiv anzuzeigen. */
      if ((digitalRead(DE_Sensor_2) == HIGH) && (Startzeit_speichern_D_Stoppuhr_2 == true))
      {           
        /* Startzeit speichern */
        Startzeit_D_Stoppuhr_2 = millis();                    //Startzeit Doppel-Stoppuhr 2 auslesen
        Startzeit_speichern_D_Stoppuhr_2 = false;             //Startzeit speichern Doppel-Stoppuhr 2 zurücksetzen
        Stoppzeit_speichern_D_Stoppuhr_2 = true;              //Stoppzeit speichern Doppel-Stoppuhr 2 setzen

        /* Grüner Punkt anzeigen */
        Display.gfx_CircleFilled(40, 266, 20, GREEN);         //Status anzeigen grüner Punkt (Kreis x,y,r)      
      }

/********************************************************************************************************************/

      /* Aktuelle Zeit anzeigen Doppel-Stoppuhr 1 und 2 */
      if ((digitalRead(DE_Sensor_1) == HIGH) && (digitalRead(DE_Sensor_2) == HIGH))
      {
        /* Stoppzeit berechnen */
        Zeit_D_Stoppuhr_1 = (millis())- Startzeit_D_Stoppuhr_1;         //Stoppzeit berechnen
        Zeit_D_Stoppuhr_2 = (millis())- Startzeit_D_Stoppuhr_2;         //Stoppzeit berechnen
      }

/********************************************************************************************************************/

      /* Aktuelle Zeit anzeigen Doppel-Stoppuhr 1 */
      if ((digitalRead(DE_Sensor_1) == HIGH) && (digitalRead(DE_Sensor_2) == LOW)) Zeit_D_Stoppuhr_1 = (millis())- Startzeit_D_Stoppuhr_1;         //Stoppzeit berechnen  

/********************************************************************************************************************/

      /* Aktuelle Zeit anzeigen Doppel-Stoppuhr 2 */
      if ((digitalRead(DE_Sensor_1) == LOW) && (digitalRead(DE_Sensor_2) == HIGH)) Zeit_D_Stoppuhr_2 = (millis())- Startzeit_D_Stoppuhr_2;         //Stoppzeit berechnen       
    }

/********************************************************************************************************************/

    /* Doppel-Stoppuhr 1 gestoppt
       Werte erst anzeigen wenn beide Stoppuhren auf Low sind, sonst kann es beim jeweiligen anderen Zähler einen Messfehler geben! */  
    if ((digitalRead(DE_Sensor_1) == LOW) && (digitalRead(DE_Sensor_2) == LOW))           //Überwachung Eingang Pin 8 und Pin 9
    {   
      /* Stoppzeit speichern Doppel-Stoppuhr 1 */
      if (Stoppzeit_speichern_D_Stoppuhr_1 == true)
      {       
        Startzeit_speichern_D_Stoppuhr_1 = true;             //Startzeit speichern Doppel-Stoppuhr 1 setzen   
        
        /* Roter Punkt anzeigen */
        Display.gfx_CircleFilled(40, 106, 20, RED);         //Status anzeigen roter Punkt (Kreis x,y,r)

        /* Höchsterwert berechnen */        
        if (Zeit_D_Stoppuhr_1 >= Hoechstwert_D_Stoppuhr_1)
        {           
          Hoechstwert_D_Stoppuhr_1 = Zeit_D_Stoppuhr_1;      //Höchstwert übernehmen
          
          /* Höchstwert anzeigen */
          Display.txt_Height(2);                        //Texthöhe
          Display.txt_Width(2);                         //Textweite
          Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe
        
          Display.gfx_MoveTo(83, 145);                  //Text Position (x,y)
          Display.print(Hoechstwert_D_Stoppuhr_1);      //Wert anzeigen
          Display.print(" Hoechstwert    ");            //Text anzeigen
        }

        /* Mittelwert berechnen */
        Messungen_D_Stoppuhr_1 = ++Messungen_D_Stoppuhr_1;                                        //Messungen zählen
        Summe_Mittelwert_D_Stoppuhr_1 = Summe_Mittelwert_D_Stoppuhr_1 + Zeit_D_Stoppuhr_1;        //Summe Mittelwert
        Mittelwert_D_Stoppuhr_1 = Summe_Mittelwert_D_Stoppuhr_1 / Messungen_D_Stoppuhr_1;         //Mittelwert berechnen

        /* Mittelwert anzeigen */
        Display.txt_Height(2);                          //Texthöhe
        Display.txt_Width(2);                           //Textweite
        Display.txt_Set(TEXT_COLOUR, Textfarbe);        //Textfarbe
      
        Display.gfx_MoveTo(83, 170);                    //Text Position (x,y)
        Display.print(Mittelwert_D_Stoppuhr_1);         //Wert anzeigen
        Display.print(" Mittelwert (");                 //Text anzeigen
        Display.print(Messungen_D_Stoppuhr_1);          //Wert anzeigen
        Display.print(" Werte) ");                      //Text anzeigen
      
        /* Kleinsterwert berechnen */
        if (Zeit_D_Stoppuhr_1 <= Kleinstwert_D_Stoppuhr_1)
        {
          Kleinstwert_D_Stoppuhr_1 = Zeit_D_Stoppuhr_1;        //Kleinstwert übernehmen

          /* Kleinstwert anzeigen */
          Display.txt_Height(2);                          //Texthöhe
          Display.txt_Width(2);                           //Textweite
          Display.txt_Set(TEXT_COLOUR, Textfarbe);        //Textfarbe
        
          Display.gfx_MoveTo(83, 195);                    //Text Position (x,y)
          Display.print(Kleinstwert_D_Stoppuhr_1);        //Wert anzeigen
          Display.print(" Kleinstwert    ");              //Text anzeigen
        }

        /* History 
           Schieberegister letzten Werte. */
        Zeiten_D_Stoppuhr_1[59] = Zeiten_D_Stoppuhr_1[58]; 
        Zeiten_D_Stoppuhr_1[58] = Zeiten_D_Stoppuhr_1[57]; 
        Zeiten_D_Stoppuhr_1[57] = Zeiten_D_Stoppuhr_1[56]; 
        Zeiten_D_Stoppuhr_1[56] = Zeiten_D_Stoppuhr_1[55]; 
        Zeiten_D_Stoppuhr_1[55] = Zeiten_D_Stoppuhr_1[54]; 
        Zeiten_D_Stoppuhr_1[54] = Zeiten_D_Stoppuhr_1[53]; 
        Zeiten_D_Stoppuhr_1[53] = Zeiten_D_Stoppuhr_1[52]; 
        Zeiten_D_Stoppuhr_1[52] = Zeiten_D_Stoppuhr_1[51]; 
        Zeiten_D_Stoppuhr_1[51] = Zeiten_D_Stoppuhr_1[50]; 
        Zeiten_D_Stoppuhr_1[50] = Zeiten_D_Stoppuhr_1[49];
        
        Zeiten_D_Stoppuhr_1[49] = Zeiten_D_Stoppuhr_1[48]; 
        Zeiten_D_Stoppuhr_1[48] = Zeiten_D_Stoppuhr_1[47]; 
        Zeiten_D_Stoppuhr_1[47] = Zeiten_D_Stoppuhr_1[46]; 
        Zeiten_D_Stoppuhr_1[46] = Zeiten_D_Stoppuhr_1[45]; 
        Zeiten_D_Stoppuhr_1[45] = Zeiten_D_Stoppuhr_1[44]; 
        Zeiten_D_Stoppuhr_1[44] = Zeiten_D_Stoppuhr_1[43]; 
        Zeiten_D_Stoppuhr_1[43] = Zeiten_D_Stoppuhr_1[42]; 
        Zeiten_D_Stoppuhr_1[42] = Zeiten_D_Stoppuhr_1[41]; 
        Zeiten_D_Stoppuhr_1[41] = Zeiten_D_Stoppuhr_1[40]; 
        Zeiten_D_Stoppuhr_1[40] = Zeiten_D_Stoppuhr_1[39];
        
        Zeiten_D_Stoppuhr_1[39] = Zeiten_D_Stoppuhr_1[38]; 
        Zeiten_D_Stoppuhr_1[38] = Zeiten_D_Stoppuhr_1[37]; 
        Zeiten_D_Stoppuhr_1[37] = Zeiten_D_Stoppuhr_1[36]; 
        Zeiten_D_Stoppuhr_1[36] = Zeiten_D_Stoppuhr_1[35]; 
        Zeiten_D_Stoppuhr_1[35] = Zeiten_D_Stoppuhr_1[34]; 
        Zeiten_D_Stoppuhr_1[34] = Zeiten_D_Stoppuhr_1[33]; 
        Zeiten_D_Stoppuhr_1[33] = Zeiten_D_Stoppuhr_1[32]; 
        Zeiten_D_Stoppuhr_1[32] = Zeiten_D_Stoppuhr_1[31]; 
        Zeiten_D_Stoppuhr_1[31] = Zeiten_D_Stoppuhr_1[30]; 
        Zeiten_D_Stoppuhr_1[30] = Zeiten_D_Stoppuhr_1[29];
        
        Zeiten_D_Stoppuhr_1[29] = Zeiten_D_Stoppuhr_1[28]; 
        Zeiten_D_Stoppuhr_1[28] = Zeiten_D_Stoppuhr_1[27]; 
        Zeiten_D_Stoppuhr_1[27] = Zeiten_D_Stoppuhr_1[26]; 
        Zeiten_D_Stoppuhr_1[26] = Zeiten_D_Stoppuhr_1[25]; 
        Zeiten_D_Stoppuhr_1[25] = Zeiten_D_Stoppuhr_1[24]; 
        Zeiten_D_Stoppuhr_1[24] = Zeiten_D_Stoppuhr_1[23]; 
        Zeiten_D_Stoppuhr_1[23] = Zeiten_D_Stoppuhr_1[22]; 
        Zeiten_D_Stoppuhr_1[22] = Zeiten_D_Stoppuhr_1[21]; 
        Zeiten_D_Stoppuhr_1[21] = Zeiten_D_Stoppuhr_1[20]; 
        Zeiten_D_Stoppuhr_1[20] = Zeiten_D_Stoppuhr_1[19];
        
        Zeiten_D_Stoppuhr_1[19] = Zeiten_D_Stoppuhr_1[18]; 
        Zeiten_D_Stoppuhr_1[18] = Zeiten_D_Stoppuhr_1[17]; 
        Zeiten_D_Stoppuhr_1[17] = Zeiten_D_Stoppuhr_1[16]; 
        Zeiten_D_Stoppuhr_1[16] = Zeiten_D_Stoppuhr_1[15]; 
        Zeiten_D_Stoppuhr_1[15] = Zeiten_D_Stoppuhr_1[14]; 
        Zeiten_D_Stoppuhr_1[14] = Zeiten_D_Stoppuhr_1[13]; 
        Zeiten_D_Stoppuhr_1[13] = Zeiten_D_Stoppuhr_1[12]; 
        Zeiten_D_Stoppuhr_1[12] = Zeiten_D_Stoppuhr_1[11]; 
        Zeiten_D_Stoppuhr_1[11] = Zeiten_D_Stoppuhr_1[10]; 
        Zeiten_D_Stoppuhr_1[10] = Zeiten_D_Stoppuhr_1[9]; 
          
        Zeiten_D_Stoppuhr_1[9] = Zeiten_D_Stoppuhr_1[8];                                                    
        Zeiten_D_Stoppuhr_1[8] = Zeiten_D_Stoppuhr_1[7];
        Zeiten_D_Stoppuhr_1[7] = Zeiten_D_Stoppuhr_1[6];
        Zeiten_D_Stoppuhr_1[6] = Zeiten_D_Stoppuhr_1[5];
        Zeiten_D_Stoppuhr_1[5] = Zeiten_D_Stoppuhr_1[4];
        Zeiten_D_Stoppuhr_1[4] = Zeiten_D_Stoppuhr_1[3];
        Zeiten_D_Stoppuhr_1[3] = Zeiten_D_Stoppuhr_1[2];
        Zeiten_D_Stoppuhr_1[2] = Zeiten_D_Stoppuhr_1[1];
        Zeiten_D_Stoppuhr_1[1] = Zeiten_D_Stoppuhr_1[0];
        Zeiten_D_Stoppuhr_1[0] = Zeit_D_Stoppuhr_1;              

        /* Letzte 5 Werte anzeigen */ 
        Liste(540, 92, 0, 5, Zeiten_D_Stoppuhr_1, Mittelwert_D_Stoppuhr_1, 1, BLUE, "ms     ");       //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)

        /* Aktueller Wert anzeigen */
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);                        //Text fett
        Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe weiss
    
        Display.gfx_MoveTo(80, 85);                   //Text Position (x,y)
        Display.print(Zeit_D_Stoppuhr_1);             //Wert anzeigen
        Display.print(" ms       ");                  //Text anzeigen

        /* Umrechnung Millisekunden in Stunden, Minuten, Sekunden */
        Stunden_D_Stoppuhr_1 = (Zeit_D_Stoppuhr_1 / 3600000) %24;     //Stunden, Minuten, Sekunden, Millisekunden berechnen
        Minuten_D_Stoppuhr_1 = (Zeit_D_Stoppuhr_1 / 60000) %60;       //Das Zeichen: "%" ist der Modulo-Operator
        Sekunden_D_Stoppuhr_1 = (Zeit_D_Stoppuhr_1 /1000) %60;
        Millisekunden_D_Stoppuhr_1 = Zeit_D_Stoppuhr_1;

        /* Aktuelle Werte anzeigen */
        Display.txt_Height(2);                  //Texthöhe
        Display.txt_Width(2);                   //Textweite
    
        Display.gfx_MoveTo(300, 85);            //Text Position (x,y)
        Display.print(Stunden_D_Stoppuhr_1);    //Wert anzeigen
        Display.print(" : ");                   //Text anzeigen
        Display.print(Minuten_D_Stoppuhr_1);    //Wert anzeigen
        Display.print(" : ");                   //Text anzeigen
        Display.print(Sekunden_D_Stoppuhr_1);   //Wert anzeigen
        Display.print("    ");                  //Text anzeigen  

        Stoppzeit_speichern_D_Stoppuhr_1 = false;            //Stoppzeit speichern Doppel-Stoppuhr 1 zurücksetzen
      }       
    }
           
/********************************************************************************************************************/

    /* Doppel-Stoppuhr 2 gestoppt
       Werte erst anzeigen wenn beide Stoppuhren auf Low sind, sonst kann es beim jeweiligen anderen Zähler einen Messfehler geben! */  
    if ((digitalRead(DE_Sensor_1) == LOW) && (digitalRead(DE_Sensor_2) == LOW))           //Überwachung Eingang Pin 8 und Pin 9
    {    
      /* Stoppzeit speichern Doppel-Stoppuhr 2 */
      if (Stoppzeit_speichern_D_Stoppuhr_2 == true)
      {           
        Startzeit_speichern_D_Stoppuhr_2 = true;            //Startzeit speichern Doppel-Stoppuhr 2 setzen
      
        /* Roter Punkt anzeigen */
        Display.gfx_CircleFilled(40, 266, 20, RED);         //Status anzeigen roter Punkt (Kreis x,y,r)

        /* Höchsterwert berechnen */        
        if (Zeit_D_Stoppuhr_2 >= Hoechstwert_D_Stoppuhr_2)
        {           
          Hoechstwert_D_Stoppuhr_2 = Zeit_D_Stoppuhr_2;     //Höchstwert übernehmen
          
          /* Höchstwert anzeigen */
          Display.txt_Height(2);                        //Texthöhe
          Display.txt_Width(2);                         //Textweite
          Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe
        
          Display.gfx_MoveTo(83, 305);                  //Text Position (x,y)
          Display.print(Hoechstwert_D_Stoppuhr_2);      //Wert anzeigen
          Display.print(" Hoechstwert    ");            //Text anzeigen
        }

        /* Mittelwert berechnen */
        Messungen_D_Stoppuhr_2 = ++Messungen_D_Stoppuhr_2;                                      //Messungen zählen
        Summe_Mittelwert_D_Stoppuhr_2 = Summe_Mittelwert_D_Stoppuhr_2 + Zeit_D_Stoppuhr_2;      //Summe Mittelwert
        Mittelwert_D_Stoppuhr_2 = Summe_Mittelwert_D_Stoppuhr_2 / Messungen_D_Stoppuhr_2;       //Mittelwert berechnen

        /* Mittelwert anzeigen */
        Display.txt_Height(2);                          //Texthöhe
        Display.txt_Width(2);                           //Textweite
        Display.txt_Set(TEXT_COLOUR, Textfarbe);        //Textfarbe
      
        Display.gfx_MoveTo(83, 330);                    //Text Position (x,y)
        Display.print(Mittelwert_D_Stoppuhr_2);         //Wert anzeigen
        Display.print(" Mittelwert (");                 //Text anzeigen
        Display.print(Messungen_D_Stoppuhr_2);          //Wert anzeigen
        Display.print(" Werte) ");                      //Text anzeigen
      
        /* Kleinsterwert berechnen */
        if (Zeit_D_Stoppuhr_2 <= Kleinstwert_D_Stoppuhr_2)
        {
          Kleinstwert_D_Stoppuhr_2 = Zeit_D_Stoppuhr_2;        //Kleinstwert übernehmen

          /* Kleinstwert anzeigen */
          Display.txt_Height(2);                          //Texthöhe
          Display.txt_Width(2);                           //Textweite
          Display.txt_Set(TEXT_COLOUR, Textfarbe);        //Textfarbe
        
          Display.gfx_MoveTo(83, 355);                    //Text Position (x,y)
          Display.print(Kleinstwert_D_Stoppuhr_2);        //Wert anzeigen
          Display.print(" Kleinstwert    ");              //Text anzeigen
        }

        /* History 
           Schieberegister der letzen Werte. */
        Zeiten_D_Stoppuhr_2[59] = Zeiten_D_Stoppuhr_2[58]; 
        Zeiten_D_Stoppuhr_2[58] = Zeiten_D_Stoppuhr_2[57]; 
        Zeiten_D_Stoppuhr_2[57] = Zeiten_D_Stoppuhr_2[56]; 
        Zeiten_D_Stoppuhr_2[56] = Zeiten_D_Stoppuhr_2[55]; 
        Zeiten_D_Stoppuhr_2[55] = Zeiten_D_Stoppuhr_2[54]; 
        Zeiten_D_Stoppuhr_2[54] = Zeiten_D_Stoppuhr_2[53]; 
        Zeiten_D_Stoppuhr_2[53] = Zeiten_D_Stoppuhr_2[52]; 
        Zeiten_D_Stoppuhr_2[52] = Zeiten_D_Stoppuhr_2[51]; 
        Zeiten_D_Stoppuhr_2[51] = Zeiten_D_Stoppuhr_2[50]; 
        Zeiten_D_Stoppuhr_2[50] = Zeiten_D_Stoppuhr_2[49];
        
        Zeiten_D_Stoppuhr_2[49] = Zeiten_D_Stoppuhr_2[48]; 
        Zeiten_D_Stoppuhr_2[48] = Zeiten_D_Stoppuhr_2[47]; 
        Zeiten_D_Stoppuhr_2[47] = Zeiten_D_Stoppuhr_2[46]; 
        Zeiten_D_Stoppuhr_2[46] = Zeiten_D_Stoppuhr_2[45]; 
        Zeiten_D_Stoppuhr_2[45] = Zeiten_D_Stoppuhr_2[44]; 
        Zeiten_D_Stoppuhr_2[44] = Zeiten_D_Stoppuhr_2[43]; 
        Zeiten_D_Stoppuhr_2[43] = Zeiten_D_Stoppuhr_2[42]; 
        Zeiten_D_Stoppuhr_2[42] = Zeiten_D_Stoppuhr_2[41]; 
        Zeiten_D_Stoppuhr_2[41] = Zeiten_D_Stoppuhr_2[40]; 
        Zeiten_D_Stoppuhr_2[40] = Zeiten_D_Stoppuhr_2[39];
        
        Zeiten_D_Stoppuhr_2[39] = Zeiten_D_Stoppuhr_2[38]; 
        Zeiten_D_Stoppuhr_2[38] = Zeiten_D_Stoppuhr_2[37]; 
        Zeiten_D_Stoppuhr_2[37] = Zeiten_D_Stoppuhr_2[36]; 
        Zeiten_D_Stoppuhr_2[36] = Zeiten_D_Stoppuhr_2[35]; 
        Zeiten_D_Stoppuhr_2[35] = Zeiten_D_Stoppuhr_2[34]; 
        Zeiten_D_Stoppuhr_2[34] = Zeiten_D_Stoppuhr_2[33]; 
        Zeiten_D_Stoppuhr_2[33] = Zeiten_D_Stoppuhr_2[32]; 
        Zeiten_D_Stoppuhr_2[32] = Zeiten_D_Stoppuhr_2[31]; 
        Zeiten_D_Stoppuhr_2[31] = Zeiten_D_Stoppuhr_2[30]; 
        Zeiten_D_Stoppuhr_2[30] = Zeiten_D_Stoppuhr_2[29];
        
        Zeiten_D_Stoppuhr_2[29] = Zeiten_D_Stoppuhr_2[28]; 
        Zeiten_D_Stoppuhr_2[28] = Zeiten_D_Stoppuhr_2[27]; 
        Zeiten_D_Stoppuhr_2[27] = Zeiten_D_Stoppuhr_2[26]; 
        Zeiten_D_Stoppuhr_2[26] = Zeiten_D_Stoppuhr_2[25]; 
        Zeiten_D_Stoppuhr_2[25] = Zeiten_D_Stoppuhr_2[24]; 
        Zeiten_D_Stoppuhr_2[24] = Zeiten_D_Stoppuhr_2[23]; 
        Zeiten_D_Stoppuhr_2[23] = Zeiten_D_Stoppuhr_2[22]; 
        Zeiten_D_Stoppuhr_2[22] = Zeiten_D_Stoppuhr_2[21]; 
        Zeiten_D_Stoppuhr_2[21] = Zeiten_D_Stoppuhr_2[20]; 
        Zeiten_D_Stoppuhr_2[20] = Zeiten_D_Stoppuhr_2[19];
        
        Zeiten_D_Stoppuhr_2[19] = Zeiten_D_Stoppuhr_2[18]; 
        Zeiten_D_Stoppuhr_2[18] = Zeiten_D_Stoppuhr_2[17]; 
        Zeiten_D_Stoppuhr_2[17] = Zeiten_D_Stoppuhr_2[16]; 
        Zeiten_D_Stoppuhr_2[16] = Zeiten_D_Stoppuhr_2[15]; 
        Zeiten_D_Stoppuhr_2[15] = Zeiten_D_Stoppuhr_2[14]; 
        Zeiten_D_Stoppuhr_2[14] = Zeiten_D_Stoppuhr_2[13]; 
        Zeiten_D_Stoppuhr_2[13] = Zeiten_D_Stoppuhr_2[12]; 
        Zeiten_D_Stoppuhr_2[12] = Zeiten_D_Stoppuhr_2[11]; 
        Zeiten_D_Stoppuhr_2[11] = Zeiten_D_Stoppuhr_2[10]; 
        Zeiten_D_Stoppuhr_2[10] = Zeiten_D_Stoppuhr_2[9]; 
          
        Zeiten_D_Stoppuhr_2[9] = Zeiten_D_Stoppuhr_2[8];                                                    
        Zeiten_D_Stoppuhr_2[8] = Zeiten_D_Stoppuhr_2[7];
        Zeiten_D_Stoppuhr_2[7] = Zeiten_D_Stoppuhr_2[6];
        Zeiten_D_Stoppuhr_2[6] = Zeiten_D_Stoppuhr_2[5];
        Zeiten_D_Stoppuhr_2[5] = Zeiten_D_Stoppuhr_2[4];
        Zeiten_D_Stoppuhr_2[4] = Zeiten_D_Stoppuhr_2[3];
        Zeiten_D_Stoppuhr_2[3] = Zeiten_D_Stoppuhr_2[2];
        Zeiten_D_Stoppuhr_2[2] = Zeiten_D_Stoppuhr_2[1];
        Zeiten_D_Stoppuhr_2[1] = Zeiten_D_Stoppuhr_2[0];
        Zeiten_D_Stoppuhr_2[0] = Zeit_D_Stoppuhr_2;              

        /* Letzte 5 Werte anzeigen */ 
        Liste(540, 250, 0, 5, Zeiten_D_Stoppuhr_2, Mittelwert_D_Stoppuhr_2, 1, BLUE, "ms     ");      //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)

        /* Aktueller Wert anzeigen */
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);                        //Text fett
        Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe 
    
        Display.gfx_MoveTo(80, 245);                  //Text Position (x,y)
        Display.print(Zeit_D_Stoppuhr_2);             //Wert anzeigen
        Display.print(" ms       ");                  //Text anzeigen

        /* Umrechnung Millisekunden in Stunden, Minuten, Sekunden */
        Stunden_D_Stoppuhr_2 = (Zeit_D_Stoppuhr_2 / 3600000) %24;     //Stunden, Minuten, Sekunden, Millisekunden berechnen 
        Minuten_D_Stoppuhr_2 = (Zeit_D_Stoppuhr_2 / 60000) %60;       //Das Zeichen: "%" ist der Modulo-Operator
        Sekunden_D_Stoppuhr_2 = (Zeit_D_Stoppuhr_2 / 1000) %60;
        Millisekunden_D_Stoppuhr_2 = Zeit_D_Stoppuhr_2;

        /* Aktuelle Werte anzeigen */
        Display.txt_Height(2);                        //Texthöhe 
        Display.txt_Width(2);                         //Textweite
    
        Display.gfx_MoveTo(300, 245);                 //Text Position (x,y)
        Display.print(Stunden_D_Stoppuhr_2);          //Wert anzeigen
        Display.print(" : ");                         //Text anzeigen
        Display.print(Minuten_D_Stoppuhr_2);          //Wert anzeigen
        Display.print(" : ");                         //Text anzeigen
        Display.print(Sekunden_D_Stoppuhr_2);         //Wert anzeigen
        Display.print("    ");                        //Text anzeigen 

        Stoppzeit_speichern_D_Stoppuhr_2 = false;            //Stoppzeit speichern Doppel-Stoppuhr 2 zurücksetzen
      }         
    }
    
/********************************************************************************************************************/

    /* Touch Screen handling */
    Status_Display = Display.touch_Get(TOUCH_STATUS);     //Status Touch Screen

    /* Touch Positionen auslesen */
    if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))        //Überwachung Touch gedrückt oder bewegt  
    {
      X_Pos_Touch = Display.touch_Get(TOUCH_GETX);                                    //X Position auslesen
      Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);                                    //Y Position auslesen
    }

    /* Touch Freigabe */
    if (Status_Display == TOUCH_RELEASED)                                             //Überwachung Touch Freigabe
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
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          
          Menue_angewaehlt = 0;               //Menü Hauptmenue anwählen
          Bild_aufgebaut[0] = false;          //Bildschirm aufgebaut zurücksetzen

          digitalWrite(DA_Versorgung_24VDC, LOW);               //Digital Ausgang 24VDC Versorgung zurücksetzen                
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
  
          /* Alle Zeiten zurücksetzen */
          for (int i = 0; i <= 59; i++)
          {
            Zeiten_D_Stoppuhr_1[i] = 0;       //Zeiten Doppel-Stoppuhr 1 0-19 zurücksetzen
            Zeiten_D_Stoppuhr_2[i] = 0;       //Zeiten Doppel-Stoppuhr 2 0-19 zurücksetzen
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
        
          Bild_aufgebaut[1] = false;                      //Bildschirm aufgebaut zurücksetzen           
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
          Buzzer(100);                                  //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
          Menue_angewaehlt = 13;                        //Menü Doppel-Stoppuhr Liste anwählen
          Bild_aufgebaut[13] = false;                   //Bildschirm aufgebaut zurücksetzen                                                        
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
          Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
          Menue_angewaehlt = 7;                 //Menü Info anwählen
          Bild_aufgebaut[7] = false;            //Bildschirm Info aufgebaut zurücksetzen
          Letztes_Menue = 1;                    //Letztes angewähltes Menü   
          Info_Seite = 1;                       //Info Seite anwählen
        }
      }

/********************************************************************************************************************/
                 
   }      //Touch Freigabe Ende

/********************************************************************************************************************/

//  } while ((digitalRead(DE_Sensor_1) == HIGH) || (digitalRead(DE_Sensor_2) == HIGH));     /* Überwachung Eingang Pin 8 oder Pin 9 Messung eingeschaltet, 
//                                                                                             Schlaufe wird wiederholt bis gestoppt wird! */

/********************************************************************************************************************/
  
}
