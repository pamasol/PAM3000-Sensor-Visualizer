/* 16.Stoppuhr
   
   Im void Stoppuhr wird nur das Display aufgebaut. Die Funktion der Zeitmessung ist im void Loop Case 6 und 7. 
*/

void Stoppuhr(bool Bildaufbau, bool Werte_Reset)       //Funktion Stoppuhr
{
   
/********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[16] == false)     //Überwachung Bildschirm aufgebaut
  {    
    Display.gfx_Cls();            //Display löschen     
    Statusanzeige();              //Aufruf Funktion Statusanzeige
       
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Stoppuhr");   //Funktion Namen anzeigen
    
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
<<<<<<< HEAD
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");    //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Liste");                                  //Taste anzeigen ungedrückt 
    Display.gfx_Button(Status_Touch_Taste, 180, 420, ORANGE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Referenz");                            //Taste anzeigen ungedrückt 
    Display.gfx_Button(Status_Touch_Taste, 500, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Live");                                  //Taste anzeigen ungedrückt
=======
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");     //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Liste");                                  //Taste anzeigen ungedrückt 
    Display.gfx_Button(Status_Touch_Taste, 180, 420, ORANGE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Referenz");                            //Taste anzeigen ungedrückt 
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                     //Taste anzeigen gedrückt

    /* Text anzeigen */
    Display.txt_Height(2);                                    //Texthöhe
    Display.txt_Width(2);                                     //Textweite
    Display.txt_Set(TEXT_COLOUR, Texthintergrund_Menue);      //Textfarbe
       
    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);                                 //Info Kreis zeichnen (Kreis x,y,r)
        
    Display.gfx_Rectangle(0, 70, 799, 295, Texthintergrund_Menue);          //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 106, 20, RED);                             //Status anzeigen roter Punkt (Kreis x,y,r)
    Display.gfx_Circle(40, 106, 21, GRAY);                                  //Kreis zeichnen (Kreis x,y,r)
           
    /* Letzte 5 Werte anzeigen */ 
    Liste(540, 92, 0, 5, Zeiten_Stoppuhr, Mittelwert_Stoppuhr, 1, BLUE, "ms     ");       //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
 
    Display.txt_Height(4);                    //Texthöhe
    Display.txt_Width(3);                     //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);  //Textfarbe
    Display.txt_Inverse(OFF);                 //Text invetieren
    Display.txt_Bold(OFF);                    //Text fett
    
    Display.gfx_MoveTo(80, 85);               //Text Position (x,y)
    Display.print("0 ms       ");             //Text anzeigen
  
    Display.txt_Height(2);                    //Texthöhe
    Display.txt_Width(2);                     //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);  //Textfarbe
    
    Display.gfx_MoveTo(300, 85);              //Text Position (x,y)
    Display.print("0 : 0 : 0     ");          //Text anzeigen
  
    /* Höchstwert anzeigen */
    Display.gfx_MoveTo(83, 145);                      //Text Position (x,y)
    Display.print(Hoechstwert_Stoppuhr);              //Wert anzeigen
    Display.print(" Hoechstwert    ");                //Text anzeigen
    
    /* Mittelwert anzeigen */
    Display.gfx_MoveTo(83, 170);                    //Text Position (x,y)
    Display.print(Mittelwert_Stoppuhr);             //Wert anzeigen
    Display.print(" Mittelwert (");                 //Text anzeigen
    Display.print(Messungen_Stoppuhr);              //Wert anzeigen
    Display.print(" Werte) ");                      //Text anzeigen

    /* Kleinstwert anzeigen 
       0 anzeigen damit nicht 9999 angezeigt wird! */
    Display.gfx_MoveTo(83, 195);                    //Text Position (x,y)
    if (Kleinstwert_Stoppuhr < 9999)                //Werte kleiner 9999 angezeigen!
    {
      Display.print(Kleinstwert_Stoppuhr);          //Wert anzeigen
      Display.print(" Kleinstwert    ");            //Text anzeigen
    }
    else
    {
      Display.print("0 Kleinstwert    ");           //Text anzeigen              
    }

    /* Referenzwert anzeigen
       Nur Anzeigen wenn ein Referenzwert gespeichert wurde */
    Display.gfx_MoveTo(83, 235);                    //Text Position (x,y)
    if (Ref_Wert_Stoppuhr > 0)                      //Werte grösser 0 angezeigen!
    {   
      Display.print(Ref_Wert_Stoppuhr);             //Wert anzeigen
      Display.print(" Referenzwert     ");          //Text anzeigen

      Display.gfx_MoveTo(67, 260);                  //Text Position (x,y) 

      /* kein Vorzeichen anzeigen */
      if (Zeit_Stoppuhr == Ref_Wert_Stoppuhr)
      { 
        Display.print(" ");                //Text anzeigen                     
      }
          
      /* Vorzeichen + anzeigen */
      if (Zeit_Stoppuhr > Ref_Wert_Stoppuhr)
      {                    
        Display.print("+");                //Text anzeigen                     
      }

      /* Vorzeichen - anzeigen */
      if (Zeit_Stoppuhr < Ref_Wert_Stoppuhr)
      {                        
        Display.print("-");                //Text anzeigen
      }
            
      Display.print(Ref_Wert_abweichung_Stoppuhr);      //Wert anzeigen
      Display.print(" Abweichung     ");                //Text anzeigen                   
    }
    else  /* Ist kein Referenzwert gespeichert, nur ein - als Platzhalter anzeigen */
    {
      Display.print("-");          //Text anzeigen      
    }
        
    /* Interrupte stoppen 
       Wenn Interrupte aktiviert sind stimmen die millis nicht mehr!! */
    detachInterrupt(DE_Sensor_1); //Interrupt Funktion -> Void (Interrupt_Pin_8) stoppen
    detachInterrupt(DE_Sensor_2); //Interrupt Funktion -> Void (Interrupt_Pin_9) stoppen
  
    digitalWrite(DA_Versorgung_24VDC, HIGH);    //Digital Ausgang Versorgung 24VDC setzen 

    /* Buzzer */
    Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

    Bild_aufgebaut[16] = true;                  //Bildschirm aufgebaut setzen       
  }

/********************************************************************************************************************/

 // Statusanzeige();              //Aufruf Funktion Statusanzeige
  
/********************************************************************************************************************/

//  do
//  {

/********************************************************************************************************************/

    /* Freigabe Messung */
    if ((digitalRead(DE_Sensor_1) == LOW) && (digitalRead(DE_Sensor_2) == LOW) && (Messung_aktiv_Stoppuhr == false))          //Überwachung Eingang Pin 8 und Pin 9
    {
      Freigabe_Messung_Stoppuhr = true;       //Freigabe Messung setzen
    }

/********************************************************************************************************************/

    /* Messung aktiv Stoppuhr */
    if ((digitalRead(DE_Sensor_1) == HIGH) && (digitalRead(DE_Sensor_2) == LOW) && (Messung_aktiv_Stoppuhr == false) && (Freigabe_Messung_Stoppuhr == true))          //Überwachung Eingang Pin 8 und Pin 9
    {
      //Messung aktiv Stoppuhr
      Messung_aktiv_Stoppuhr = true;                //Messung aktiv Stoppuhr
      
      /* Texteinstellungen Aktueller Wert anzeigen */
      Display.txt_Height(4);                        //Texthöhe
      Display.txt_Width(3);                         //Textweite
      Display.txt_Inverse(OFF);                     //Text invetieren
      Display.txt_Bold(OFF);                        //Text fett
      Display.txt_Set(TEXT_COLOUR, GRAY);           //Textfarbe grau   
    }
           
    /* Stoppuhr gestartet */
    if (Messung_aktiv_Stoppuhr == true) 
    {   
       /* Flankenauswertung Startzeit speichern und Grüner Punkt um es als aktiv anzuzeigen. */
      if (Startzeit_speichern_Stoppuhr == true)
      {              
        /* Startzeit speichern */
        Startzeit_Stoppuhr = millis();                    //Startzeit Stoppuhr auslesen
        Startzeit_speichern_Stoppuhr = false;             //Startzeit speichern Stoppuhr zurücksetzen
        Stoppzeit_speichern_Stoppuhr = true;              //Stoppzeit speichern Stoppuhr setzen

        /* Grüner Punkt anzeigen */
        Display.gfx_CircleFilled(40, 106, 20, GREEN);     //Status anzeigen grüner Punkt (Kreis x,y,r)           
      }      

/********************************************************************************************************************/

      /* Aktuelle Zeit anzeigen Stoppuhr */
      Zeit_Stoppuhr = (millis())- Startzeit_Stoppuhr;          //Stoppzeit berechnen 
    }

/********************************************************************************************************************/
      
    /* Stoppuhr gestoppt
       Werte erst anzeigen wenn beide Stoppuhren auf Low sind, sonst kann es beim jeweiligen anderen Zähler einen Messfehler geben! */  
    if ((Messung_aktiv_Stoppuhr == true) && (digitalRead(DE_Sensor_2) == HIGH))            //Überwachung Eingang Pin 9
    {   
      /* Stoppzeit speichern Stoppuhr */
      if (Stoppzeit_speichern_Stoppuhr == true)
      {       
        Startzeit_speichern_Stoppuhr = true;              //Startzeit speichern Stoppuhr setzen   
        
        /* Roter Punkt anzeigen */
        Display.gfx_CircleFilled(40, 106, 20, RED);       //Status anzeigen roter Punkt (Kreis x,y,r)

        /* Höchsterwert berechnen */        
        if (Zeit_Stoppuhr >= Hoechstwert_Stoppuhr)
        {           
          Hoechstwert_Stoppuhr = Zeit_Stoppuhr;         //Höchstwert übernehmen
          
          /* Höchstwert anzeigen */
          Display.txt_Height(2);                        //Texthöhe
          Display.txt_Width(2);                         //Textweite
          Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe
        
          Display.gfx_MoveTo(83, 145);                  //Text Position (x,y)
          Display.print(Hoechstwert_Stoppuhr);          //Wert anzeigen
          Display.print(" Hoechstwert    ");            //Text anzeigen
        }

        /* Mittelwert berechnen */
        Messungen_Stoppuhr = ++Messungen_Stoppuhr;                                      //Messungen zählen
        Summe_Mittelwert_Stoppuhr = Summe_Mittelwert_Stoppuhr + Zeit_Stoppuhr;          //Summe Mittelwert
        Mittelwert_Stoppuhr = Summe_Mittelwert_Stoppuhr / Messungen_Stoppuhr;           //Mittelwert berechnen

        /* Mittelwert anzeigen */
        Display.txt_Height(2);                          //Texthöhe
        Display.txt_Width(2);                           //Textweite
        Display.txt_Set(TEXT_COLOUR, Textfarbe);        //Textfarbe
      
        Display.gfx_MoveTo(83, 170);                    //Text Position (x,y)
        Display.print(Mittelwert_Stoppuhr);             //Wert anzeigen
        Display.print(" Mittelwert (");                 //Text anzeigen
        Display.print(Messungen_Stoppuhr);              //Wert anzeigen
        Display.print(" Werte) ");                      //Text anzeigen
      
        /* Kleinsterwert berechnen */
        if (Zeit_Stoppuhr <= Kleinstwert_Stoppuhr)
        {
          Kleinstwert_Stoppuhr = Zeit_Stoppuhr;         //Kleinstwert übernehmen

          /* Kleinstwert anzeigen */
          Display.txt_Height(2);                          //Texthöhe
          Display.txt_Width(2);                           //Textweite
          Display.txt_Set(TEXT_COLOUR, Textfarbe);        //Textfarbe
        
          Display.gfx_MoveTo(83, 195);                    //Text Position (x,y)
          Display.print(Kleinstwert_Stoppuhr);            //Wert anzeigen
          Display.print(" Kleinstwert    ");              //Text anzeigen
        }

        /* Referenz Abweichung anzeigen
           Wert nur anzeigen wenn einer gespeichert wurde */
        if (Ref_Wert_Stoppuhr > 0)                      //Werte grösser 0 angezeigen!
        {   
          Display.gfx_MoveTo(67, 260);                      //Text Position (x,y) 

          /* Abweichung berechnen gleich als Referenzwert */
          if (Zeit_Stoppuhr == Ref_Wert_Stoppuhr)
          { 
            Ref_Wert_abweichung_Stoppuhr = 0;
            
            /* kein Vorzeichen anzeigen */
            Display.print(" ");                //Text anzeigen                     
          }
          
          /* Abweichung berechnen grösser als Referenzwert */
          if (Zeit_Stoppuhr > Ref_Wert_Stoppuhr)
          { 
            Ref_Wert_abweichung_Stoppuhr = Zeit_Stoppuhr - Ref_Wert_Stoppuhr;
            
            /* Vorzeichen + anzeigen */
            Display.print("+");                //Text anzeigen                     
          }

          /* Abweichung berechnen kleiner als Referenzwert */
          if (Zeit_Stoppuhr < Ref_Wert_Stoppuhr)
          {
            Ref_Wert_abweichung_Stoppuhr = Ref_Wert_Stoppuhr - Zeit_Stoppuhr;
                        
            /* Vorzeichen - anzeigen */
            Display.print("-");                //Text anzeigen
          }
            
          Display.print(Ref_Wert_abweichung_Stoppuhr);      //Wert anzeigen
          Display.print(" Abweichung     ");                //Text anzeigen       
        }

        /* History 
           Schieberegister letzten Werte. */
        Zeiten_Stoppuhr[59] = Zeiten_Stoppuhr[58]; 
        Zeiten_Stoppuhr[58] = Zeiten_Stoppuhr[57]; 
        Zeiten_Stoppuhr[57] = Zeiten_Stoppuhr[56]; 
        Zeiten_Stoppuhr[56] = Zeiten_Stoppuhr[55]; 
        Zeiten_Stoppuhr[55] = Zeiten_Stoppuhr[54]; 
        Zeiten_Stoppuhr[54] = Zeiten_Stoppuhr[53]; 
        Zeiten_Stoppuhr[53] = Zeiten_Stoppuhr[52]; 
        Zeiten_Stoppuhr[52] = Zeiten_Stoppuhr[51]; 
        Zeiten_Stoppuhr[51] = Zeiten_Stoppuhr[50]; 
        Zeiten_Stoppuhr[50] = Zeiten_Stoppuhr[49];
        
        Zeiten_Stoppuhr[49] = Zeiten_Stoppuhr[48]; 
        Zeiten_Stoppuhr[48] = Zeiten_Stoppuhr[47]; 
        Zeiten_Stoppuhr[47] = Zeiten_Stoppuhr[46]; 
        Zeiten_Stoppuhr[46] = Zeiten_Stoppuhr[45]; 
        Zeiten_Stoppuhr[45] = Zeiten_Stoppuhr[44]; 
        Zeiten_Stoppuhr[44] = Zeiten_Stoppuhr[43]; 
        Zeiten_Stoppuhr[43] = Zeiten_Stoppuhr[42]; 
        Zeiten_Stoppuhr[42] = Zeiten_Stoppuhr[41]; 
        Zeiten_Stoppuhr[41] = Zeiten_Stoppuhr[40]; 
        Zeiten_Stoppuhr[40] = Zeiten_Stoppuhr[39];
        
        Zeiten_Stoppuhr[39] = Zeiten_Stoppuhr[38]; 
        Zeiten_Stoppuhr[38] = Zeiten_Stoppuhr[37]; 
        Zeiten_Stoppuhr[37] = Zeiten_Stoppuhr[36]; 
        Zeiten_Stoppuhr[36] = Zeiten_Stoppuhr[35]; 
        Zeiten_Stoppuhr[35] = Zeiten_Stoppuhr[34]; 
        Zeiten_Stoppuhr[34] = Zeiten_Stoppuhr[33]; 
        Zeiten_Stoppuhr[33] = Zeiten_Stoppuhr[32]; 
        Zeiten_Stoppuhr[32] = Zeiten_Stoppuhr[31]; 
        Zeiten_Stoppuhr[31] = Zeiten_Stoppuhr[30]; 
        Zeiten_Stoppuhr[30] = Zeiten_Stoppuhr[29];
        
        Zeiten_Stoppuhr[29] = Zeiten_Stoppuhr[28]; 
        Zeiten_Stoppuhr[28] = Zeiten_Stoppuhr[27]; 
        Zeiten_Stoppuhr[27] = Zeiten_Stoppuhr[26]; 
        Zeiten_Stoppuhr[26] = Zeiten_Stoppuhr[25]; 
        Zeiten_Stoppuhr[25] = Zeiten_Stoppuhr[24]; 
        Zeiten_Stoppuhr[24] = Zeiten_Stoppuhr[23]; 
        Zeiten_Stoppuhr[23] = Zeiten_Stoppuhr[22]; 
        Zeiten_Stoppuhr[22] = Zeiten_Stoppuhr[21]; 
        Zeiten_Stoppuhr[21] = Zeiten_Stoppuhr[20]; 
        Zeiten_Stoppuhr[20] = Zeiten_Stoppuhr[19];
        
<<<<<<< HEAD
=======
        /* History 
           Schieberegister letzten zwanzig Werte. */
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        Zeiten_Stoppuhr[19] = Zeiten_Stoppuhr[18]; 
        Zeiten_Stoppuhr[18] = Zeiten_Stoppuhr[17]; 
        Zeiten_Stoppuhr[17] = Zeiten_Stoppuhr[16]; 
        Zeiten_Stoppuhr[16] = Zeiten_Stoppuhr[15]; 
        Zeiten_Stoppuhr[15] = Zeiten_Stoppuhr[14]; 
        Zeiten_Stoppuhr[14] = Zeiten_Stoppuhr[13]; 
        Zeiten_Stoppuhr[13] = Zeiten_Stoppuhr[12]; 
        Zeiten_Stoppuhr[12] = Zeiten_Stoppuhr[11]; 
        Zeiten_Stoppuhr[11] = Zeiten_Stoppuhr[10]; 
        Zeiten_Stoppuhr[10] = Zeiten_Stoppuhr[9]; 
          
        Zeiten_Stoppuhr[9] = Zeiten_Stoppuhr[8];                                                    
        Zeiten_Stoppuhr[8] = Zeiten_Stoppuhr[7];
        Zeiten_Stoppuhr[7] = Zeiten_Stoppuhr[6];
        Zeiten_Stoppuhr[6] = Zeiten_Stoppuhr[5];
        Zeiten_Stoppuhr[5] = Zeiten_Stoppuhr[4];
        Zeiten_Stoppuhr[4] = Zeiten_Stoppuhr[3];
        Zeiten_Stoppuhr[3] = Zeiten_Stoppuhr[2];
        Zeiten_Stoppuhr[2] = Zeiten_Stoppuhr[1];
        Zeiten_Stoppuhr[1] = Zeiten_Stoppuhr[0];
        Zeiten_Stoppuhr[0] = Zeit_Stoppuhr;              

        /* Letzte 5 Werte anzeigen */ 
        Liste(540, 92, 0, 5, Zeiten_Stoppuhr, Mittelwert_Stoppuhr, 1, BLUE, "ms     ");       //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)

        /* Aktueller Wert anzeigen */
        Display.txt_Height(4);                        //Texthöhe
        Display.txt_Width(3);                         //Textweite
        Display.txt_Inverse(OFF);                     //Text invetieren
        Display.txt_Bold(OFF);                        //Text fett
        Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe weiss
    
        Display.gfx_MoveTo(80, 85);                   //Text Position (x,y)
        Display.print(Zeit_Stoppuhr);                 //Wert anzeigen
        Display.print(" ms       ");                  //Text anzeigen

        /* Umrechnung Millisekunden in Stunden, Minuten, Sekunden */
        Stunden_Stoppuhr = (Zeit_Stoppuhr / 3600000) %24;     //Stunden, Minuten, Sekunden, Millisekunden berechnen
        Minuten_Stoppuhr = (Zeit_Stoppuhr / 60000) %60;       //Das Zeichen: "%" ist der Modulo-Operator
        Sekunden_Stoppuhr = (Zeit_Stoppuhr /1000) %60;
        Millisekunden_Stoppuhr = Zeit_Stoppuhr;

        /* Aktuelle Werte anzeigen */
        Display.txt_Height(2);                  //Texthöhe
        Display.txt_Width(2);                   //Textweite
    
        Display.gfx_MoveTo(300, 85);            //Text Position (x,y)
        Display.print(Stunden_Stoppuhr);        //Wert anzeigen
        Display.print(" : ");                   //Text anzeigen
        Display.print(Minuten_Stoppuhr);        //Wert anzeigen
        Display.print(" : ");                   //Text anzeigen
        Display.print(Sekunden_Stoppuhr);       //Wert anzeigen
        Display.print("    ");                  //Text anzeigen  
       
        Stoppzeit_speichern_Stoppuhr = false;         //Stoppzeit speichern Stoppuhr zurücksetzen
        Messung_aktiv_Stoppuhr = false;               //Messung aktiv Stoppuhr zurücksetzen
        Freigabe_Messung_Stoppuhr = false;            //Freigabe Messung zurücksetzen
      }       
    }

/********************************************************************************************************************/

    /* Warten bis Signale bereit sind für nächste Messung */
//    if (((digitalRead(DE_Sensor_1) == HIGH) || (digitalRead(DE_Sensor_2) == HIGH)) && (Messung_aktiv_Stoppuhr == true))          //Überwachung Eingang Pin 8 und Pin 9
//    {
//       Messung_aktiv_Stoppuhr = false;                    //Messung aktiv Stoppuhr zurücksetzen
       
        /* Oranger Punkt anzeigen */
//        Display.gfx_CircleFilled(40, 106, 20, ORANGE);     //Status anzeigen grüner Punkt (Kreis x,y,r)
//    }
                   
/********************************************************************************************************************/

    /* Touch Screen handling */
    Status_Display = Display.touch_Get(TOUCH_STATUS);     //Status Touch Screen

    /* Touch Positionen auslesen */
    if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))  //Überwachung Touch gedrückt oder bewegt  
    {
      X_Pos_Touch = Display.touch_Get(TOUCH_GETX);                                    //X Position auslesen
      Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);                                    //Y Position auslesen
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
          Buzzer(100);                                  //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          Menue_angewaehlt = 0;                         //Menü Hauptmenue anwählen
          Bild_aufgebaut[0] = false;                    //Bildschirm aufgebaut zurücksetzen

          digitalWrite(DA_Versorgung_24VDC, LOW);       //Digital Ausgang 24VDC Versorgung zurücksetzen                
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
            Zeiten_Stoppuhr[i] = 0;       //Zeiten Stoppuhr 0-19 zurücksetzen
          }

          Hoechstwert_Stoppuhr = 0;                   //Höchstwert Stoppuhr zurücksetzen
          Messungen_Stoppuhr = 0;                     //Messungen Stoppuhr zurücksetzen
          Summe_Mittelwert_Stoppuhr = 0;              //Summe Mittelwert Stoppuhr zurücksetzen 
          Mittelwert_Stoppuhr = 0;                    //Mittelwert Stoppuhr zurücksetzen 
          Kleinstwert_Stoppuhr = 9999;                //Kleinstwert Stoppuhr auf maximumwert setzen
          Ref_Wert_Stoppuhr = 0;                      //Rererenzwert Stoppuhr zurücksetzen
          Ref_Wert_abweichung_Stoppuhr = 0;           //Rererenzwert Abweichung Stoppuhr zurücksetzen
          
          /* Buzzer */
          Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          Bild_aufgebaut[16] = false;                 //Bildschirm aufgebaut zurücksetzen           
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

          Menue_angewaehlt = 17;                        //Menü Stoppuhr Liste anwählen
          Bild_aufgebaut[17] = false;                   //Bildschirm aufgebaut zurücksetzen                                                        
        }
      }
      
/********************************************************************************************************************/

      /* Touch Feld abfragen [Referenz] Taste gedrückt 
         Taste nur auswerten, wenn Messung nicht mehr aktiv ist */
      if ((X_Pos_Touch >= 150) && (X_Pos_Touch <= 330) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450) && (Messung_aktiv_Stoppuhr == false))   //Überwachung Touch Feld
      {     
        /* Touch Feld [Referenz] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 180, 420, ORANGE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Referenz");                  //Taste anzeigen gedrückt 

          /* Referenzwert speichern */
          Ref_Wert_Stoppuhr = Zeiten_Stoppuhr[0];     //Referenzwert speichern  
          Ref_Wert_abweichung_Stoppuhr = 0;           //Rererenzwert Abweichung Stoppuhr zurücksetzen

          /* Buzzer */
          Buzzer(100);                                //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          
          Menue_angewaehlt = 16;                      //Menü Stoppuhr anwählen
          Bild_aufgebaut[16] = false;                 //Bildschirm aufgebaut zurücksetzen                                                                      
        }
      }

/********************************************************************************************************************/

<<<<<<< HEAD

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
          Letztes_Menue = 16;                   //Letztes angewähltes Menü   
<<<<<<< HEAD
          Info_Seite = 2;                       //Info Seite anwählen
=======
          Info_Seite = 14;                      //Info Seite anwählen
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        }
      }

/********************************************************************************************************************/
                 
   }        //Touch Freigabe Ende
   
/********************************************************************************************************************/
   
}
