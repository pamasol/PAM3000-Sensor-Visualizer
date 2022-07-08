/* 10.Geschwindigkeitsanzeige Sortierer

   Misst über eine Minute die Stückzahl und zeigt dann die Anzahl an. 
   Diese Funktion startet sobald der Pin 8 oder 9 auf HIGH sind. 
*/

void Geschwindigkeitsanzeige_Sort(bool Bildaufbau, bool Werte_Reset)           //Funktion Geschwindigkeitsanzeige Sortierer
{

/********************************************************************************************************************/

  /* Bildaufbau
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[10] == false)                   //Überwachung Bildschirm aufgebaut
  {        
    Display.gfx_Cls();            //Display löschen
    Statusanzeige();              //Aufruf Funktion Statusanzeige
  
    Messung_Ein_Geschw_Sort = false;                  //Messung Ein Geschwindigkeit Sortierer zurücksetzen
    Messung_aktiv_Geschw_Sort_1 = false;              //Messung aktiv Geschwindigkeit Sortierer 1 zurücksetzen
    Messung_aktiv_Geschw_Sort_2 = false;              //Messung aktiv Geschwindigkeit Sortierer 2 zurücksetzen

    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige Sortierer");   //Funktion Namen anzeigen

    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");   //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                             //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Liste");                                //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Start");                              //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                   //Taste anzeigen gedrückt

    /* [- o -] Taste aktiv */
    if (Sensor_Logik_Sort_1 == 0)         //Überwachung Sensor Logik Geschwindigkeit Sortierer 1 (0= - o -, 1= = o)
    {
      /* [= o  ] Taste anzeigen Funktion deaktiviert */
      Display.gfx_Button(Status_Touch_Taste, 480, 195, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "= o  ");                  //Taste anzeigen ungedrückt 
                   
      /* [- o -] Taste anzeigen Funktion aktiv */         
      Display.gfx_Button(Status_Touch_Taste, 380, 195, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "- o -");                  //Taste anzeigen gedrückt             
    }

    /* [= o  ] Taste aktiv */
    if (Sensor_Logik_Sort_1 == 1)         //Überwachung Sensor Logik Geschwindigkeit Sortierer 1 (0= - o -, 1= = o)
    {                   
      /* [- o -] Taste anzeigen Funktion deaktiviert */         
      Display.gfx_Button(Status_Touch_Taste, 380, 195, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "- o -");                  //Taste anzeigen ungedrückt 

      /* [= o  ] Taste anzeigen Funktion aktiv */
      Display.gfx_Button(Status_Touch_Taste, 480, 195, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "= o  ");                  //Taste anzeigen gedrückt             
    }

    /* [- o -] Taste aktiv */
    if (Sensor_Logik_Sort_2 == 0)       //Überwachung Sensor Logik Geschwindigkeit Sortierer 1 (0= - o -, 1= = o)
    {
      /* [= o  ] Taste anzeigen Funktion deaktiviert */
      Display.gfx_Button(Status_Touch_Taste, 480, 355, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "= o  ");                  //Taste anzeigen ungedrückt 
                   
      /* [- o -] Taste anzeigen Funktion aktiv */         
      Display.gfx_Button(Status_Touch_Taste, 380, 355, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "- o -");                  //Taste anzeigen gedrückt                 
    }

    /* [= o  ] Taste aktiv */
    if (Sensor_Logik_Sort_2 == 1)         //Überwachung Sensor Logik Geschwindigkeit Sortierer 1 (0= - o -, 1= = o)
    {
      /* [- o -] Taste anzeigen Funktion deaktiviert */         
      Display.gfx_Button(Status_Touch_Taste, 380, 355, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "- o -");                  //Taste anzeigen ungedrückt 

      /* [= o  ] Taste anzeigen Funktion aktiv */
      Display.gfx_Button(Status_Touch_Taste, 480, 355, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "= o  ");                  //Taste anzeigen gedrückt                
    }

    /* Text anzeigen */
    Display.txt_Height(2);                                              //Texthöhe
    Display.txt_Width(2);                                               //Textweite
    Display.txt_Set(TEXT_COLOUR, Texthintergrund_Menue);                //Textfarbe

    /* Sensor Bezeichung */
    Display.gfx_MoveTo(33, 182);                                //Text Position (x,y)
    Display.print("1");                                         //Text anzeigen
    Display.gfx_Circle(40, 192, 20, Texthintergrund_Menue);     //Kreis zeichnen (Kreis x,y,r)

    Display.gfx_MoveTo(33, 342);                                //Text Position (x,y)
    Display.print("2");                                         //Text anzeigen
    Display.gfx_Circle(40, 352, 20, Texthintergrund_Menue);     //Kreis zeichnen (Kreis x,y,r)
   
    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);                         //Info Kreis zeichnen (Kreis x,y,r)
        
    Display.gfx_Rectangle(0, 70, 799, 230, Texthintergrund_Menue);                //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
//    Display.gfx_Rectangle(0, 180, 65, 230, Texthintergrund_Menue);              //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 106, 20, RED);                                   //Status anzeigen roter Punkt (Kreis x,y,r)
    Display.gfx_Circle(40, 106, 21, GRAY);                                        //Kreis zeichnen (Kreis x,y,r)

    Display.gfx_Rectangle(0, 390, 799, 230, Texthintergrund_Menue);               //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
//    Display.gfx_Rectangle(0, 390, 65, 340, Texthintergrund_Menue);              //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 266, 20, RED);                                   //Status anzeigen roter Punkt (Kreis x,y,r)
    Display.gfx_Circle(40, 266, 21, GRAY);                                        //Kreis zeichnen (Kreis x,y,r)

    /* Zeitsäulerahmen anzeigen */
    Display.gfx_Rectangle(349, 85, 551, 120, Texthintergrund_Menue);               //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    Display.gfx_Rectangle(349, 245, 551, 280, Texthintergrund_Menue);              //Rahmen zeichnen (Rechteck x1,y1,x2,y2)

    Display.txt_Height(1);                            //Texthöhe
    Display.txt_Width(1);                             //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);          //Textfarbe

    /* Zeitsäulenbeschriftung anzeigen */
    Display.gfx_MoveTo(340, 130);               //Text Position (x,y)
    Display.print("0s");                        //Text anzeigen
    Display.gfx_MoveTo(540, 130);               //Text Position (x,y)
    Display.print("60s");                       //Text anzeigen

    Display.gfx_MoveTo(340, 290);               //Text Position (x,y)
    Display.print("0s");                        //Text anzeigen
    Display.gfx_MoveTo(540, 290);               //Text Position (x,y)
    Display.print("60s");                       //Text anzeigen

    /* Letzte 5 Werte anzeigen */   
    Liste(590, 92, 0, 5, Zaehlwerte_Geschw_Sort_1, Mittelwert_Geschw_Sort_1, 0, RED, "cpm   ");      //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
    Liste(590, 250, 0, 5, Zaehlwerte_Geschw_Sort_2, Mittelwert_Geschw_Sort_2, 0, RED, "cpm   ");     //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)

    Display.txt_Height(4);                            //Texthöhe
    Display.txt_Width(3);                             //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);          //Textfarbe
    Display.txt_Inverse(OFF);                         //Text invetieren
    Display.txt_Bold(OFF);                            //Text fett

    /* Aktueller Wert anzeigen */
    Display.gfx_MoveTo(80, 85);                       //Text Position (x,y)
    Display.print("");
    Display.print("0 cpm   ");                        //Text anzeigen

    Display.gfx_MoveTo(80, 245);                      //Text Position (x,y)
    Display.print("");
    Display.print("0 cpm   ");                        //Text anzeigen

    Display.txt_Height(2);                            //Texthöhe
    Display.txt_Width(2);                             //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);          //Textfarbe

    /* Höchstwert anzeigen */
    Display.gfx_MoveTo(83, 145);                      //Text Position (x,y)
    Display.print(Hoechstwert_Geschw_Sort_1);         //Wert anzeigen
    Display.print(" Hoechstwert    ");                //Text anzeigen

    Display.gfx_MoveTo(83, 305);                      //Text Position (x,y)
    Display.print(Hoechstwert_Geschw_Sort_2);         //Wert anzeigen
    Display.print(" Hoechstwert    ");                //Text anzeigen
    
    /* Mittelwert anzeigen */
    Display.gfx_MoveTo(83, 170);                    //Text Position (x,y)
    Display.print(Mittelwert_Geschw_Sort_1);        //Wert anzeigen
    Display.print(" Mittelwert (");                 //Text anzeigen
    Display.print(Messungen_Geschw_Sort_1);         //Wert anzeigen
    Display.print(" Werte) ");                      //Text anzeigen

    Display.gfx_MoveTo(83, 330);                    //Text Position (x,y)
    Display.print(Mittelwert_Geschw_Sort_2);        //Wert anzeigen
    Display.print(" Mittelwert (");                 //Text anzeigen
    Display.print(Messungen_Geschw_Sort_2);         //Wert anzeigen
    Display.print(" Werte) ");                      //Text anzeigen

    /* Kleinstwert anzeigen 
       0 anzeigen damit nicht 9999 angezeigt wird! */
    Display.gfx_MoveTo(83, 195);                      //Text Position (x,y)
    if (Kleinstwert_Geschw_Sort_1 < 9999)            //Werte kleiner 9999 angezeigen!
    {
      Display.print(Kleinstwert_Geschw_Sort_1);       //Wert anzeigen
      Display.print(" Kleinstwert    ");              //Text anzeigen
    }
    else
    {
      Display.print("0 Kleinstwert    ");             //Text anzeigen              
    }
    
    Display.gfx_MoveTo(83, 355);                    //Text Position (x,y)       
    if (Kleinstwert_Geschw_Sort_2 < 9999)            //Werte kleiner 9999 angezeigen!
    { 
      Display.print(Kleinstwert_Geschw_Sort_2);     //Wert anzeigen
      Display.print(" Kleinstwert    ");            //Text anzeigen
    }
    else
    {
      Display.print("0 Kleinstwert    ");            //Text anzeigen              
    }
    
    /* Interrupt
       Sensor Logik:  Unterbruch - O -   getriggert LOW auf HIGH
                      Reflektion = O     getriggert HIGH auf LOW
    
     RISING Interrupt wird getriggert, wenn der Pin von LOW auf HIGH wechselt.   
     FALLING Interrupt wird getriggert, wenn der Pin von HIGH auf LOW wechselt. */  
     
    attachInterrupt(DE_Sensor_1, Interrupt_Pin_8, RISING);      //Interrupt Funktion -> Void (Interrupt_Pin_8)
    attachInterrupt(DE_Sensor_2, Interrupt_Pin_9, RISING);      //Interrupt Funktion -> Void (Interrupt_Pin_9)

//    attachInterrupt(DE_Sensor_1, Interrupt_Pin_8, FALLING);      //Interrupt Funktion -> Void (Interrupt_Pin_8)
//    attachInterrupt(DE_Sensor_2, Interrupt_Pin_9, FALLING);      //Interrupt Funktion -> Void (Interrupt_Pin_9)    
    
//    digitalWrite(DA_Versorgung_24VDC, HIGH);     //Digital Ausgang Versorgung 24VDC setzen
//    delay(1000);                              //Verzögerung 1000ms   

    /* Buzzer */
    Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

    Bild_aufgebaut[10] = true;               //Bildschirm aufgebaut setzen    
  }

/********************************************************************************************************************/

  Statusanzeige();              //Aufruf Funktion Statusanzeige

/********************************************************************************************************************/

  do
  {

/********************************************************************************************************************/

    /* Messung aktiv Geschwindigkeit Sortierer 1 */
    if ((Messung_Ein_Geschw_Sort == true) && ((digitalRead(DE_Sensor_1) == HIGH) || (digitalRead(DE_Sensor_2) == HIGH)))           //Überwachung Eingang Pin 8 und Pin 9
    {    
      /* Geschwindigkeit Sortierer 1 und 2 gestartet
         Flankenauswertung Startzeit speichern und grüner Punkt um es als aktiv anzuzeigen. */
      if ((digitalRead(DE_Sensor_1) == HIGH) && (Startzeit_speichern_Geschw_Sort_1 == true) && (digitalRead(DE_Sensor_2) == HIGH) && (Startzeit_speichern_Geschw_Sort_2 == true))
      {          
        /* Messung aktiv setzen */
        Messung_aktiv_Geschw_Sort_1 = true;           //Messung aktiv Geschwindgkeit Sortierer 1 setzen     
        Messung_aktiv_Geschw_Sort_2 = true;           //Messung aktiv Geschwindgkeit Sortierer 2 setzen       
     
        /* Startzeit speichern */
        Startzeit_Geschw_Sort_1 = millis();                   //Startzeit Geschwindigkeit Sortierer 1 auslesen
        Startzeit_Geschw_Sort_2 = Startzeit_Geschw_Sort_1;    //Startzeit Geschwindigkeit Sortierer 2 auslesen
        Startzeit_speichern_Geschw_Sort_1 = false;            //Startzeit speichern Geschwindigkeit Sortierer 1 zurücksetzen   
        Startzeit_speichern_Geschw_Sort_2 = false;            //Startzeit speichern Geschwindigkeit Sortierer 2 zurücksetzen      
        Stoppzeit_Geschw_Sort_1 = 0;                          //Stoppzeit Geschwindigkeit Sortierer 1 zurücksetzen
        Zaehlwert_Geschw_Sort_1 = 0;                          //Zählwert Geschwindigkeit Sortierer 1 zurücksetzen
        Zeitsaeule_Gesch_Sort_1 = 0;                          //Zeitsäule Geschwindigkeit Sortierer 1 zurücksetzen
        Stoppzeit_Geschw_Sort_2 = 0;                          //Stoppzeit Geschwindigkeit Sortierer 2 zurücksetzen
        Zaehlwert_Geschw_Sort_2 = 0;                          //Zählwert Geschwindigkeit Sortierer 2 zurücksetzen
        Zeitsaeule_Gesch_Sort_2 = 0;                          //Zeitsäule Geschwindigkeit Sortierer 2 zurücksetzen
      
        /* Grüner Punkt anzeigen */
        Display.gfx_CircleFilled(40, 106, 20, GREEN);       //Status anzeigen grüner Punkt (Kreis x,y,r) 
        Display.gfx_CircleFilled(40, 266, 20, GREEN);       //Status anzeigen grüner Punkt (Kreis x,y,r)

        /* Zeitsäule löschen */
        Display.gfx_RectangleFilled(350, 86, 550, 119, BLACK);         //0s = 350, 60s = 550      //Status anzeigen Zeit (Rechteck x1,y1,x2,y2)
        Display.gfx_RectangleFilled(350, 246, 550, 279, BLACK);        //0s = 350, 60s = 550      //Status anzeigen Zeit (Rechteck x1,y1,x2,y2)                                                               
      }

/********************************************************************************************************************/

      /* Geschwindigkeit Sortierer 1 gestartet
         Flankenauswertung Startzeit speichern und grüner Punkt um es als aktiv anzuzeigen. */
      if ((digitalRead(DE_Sensor_1) == HIGH) && (Startzeit_speichern_Geschw_Sort_1 == true))
      {          
        /* Messung aktiv setzen */
        Messung_aktiv_Geschw_Sort_1 = true;           //Messung aktiv Geschwindgkeit Sortierer 1 setzen 
          
        /* Startzeit speichern */
        Startzeit_Geschw_Sort_1 = millis();                   //Startzeit Geschwindigkeit Sortierer 1 auslesen
        Startzeit_speichern_Geschw_Sort_1 = false;            //Startzeit speichern Geschwindigkeit Sortierer 1 zurücksetzen    
        Stoppzeit_Geschw_Sort_1 = 0;                          //Stoppzeit Geschwindigkeit Sortierer 1 zurücksetzen
        Zaehlwert_Geschw_Sort_1 = 0;                          //Zählwert Geschwindigkeit Sortierer 1 zurücksetzen
        Zeitsaeule_Gesch_Sort_1 = 0;                          //Zeitsäule Geschwindigkeit Sortierer 1 zurücksetzen
      
        /* Grüner Punkt anzeigen */
        Display.gfx_CircleFilled(40, 106, 20, GREEN);       //Status anzeigen grüner Punkt (Kreis x,y,r) 

        /* Zeitsäule löschen */
        Display.gfx_RectangleFilled(350, 86, 550, 119, BLACK);         //0s = 350, 60s = 550      //Status anzeigen Zeit (Rechteck x1,y1,x2,y2)                                                             
      }

/********************************************************************************************************************/

      /* Geschwindigkeit Sortierer 2 gestartet
         Flankenauswertung Startzeit speichern und grüner Punkt um es als aktiv anzuzeigen. */
      if ((digitalRead(DE_Sensor_2) == HIGH) && (Startzeit_speichern_Geschw_Sort_2 == true))
      {          
        /* Messung aktiv setzen */
        Messung_aktiv_Geschw_Sort_2 = true;           //Messung aktiv Geschwindgkeit Sortierer 2 setzen 
     
        /* Startzeit speichern */
        Startzeit_Geschw_Sort_2 = millis();                   //Startzeit Geschwindigkeit Sortierer 2 auslesen
        Startzeit_speichern_Geschw_Sort_2 = false;            //Startzeit speichern Geschwindigkeit Sortierer 2 zurücksetzen    
        Stoppzeit_Geschw_Sort_2 = 0;                          //Stoppzeit Geschwindigkeit Sortierer 2 zurücksetzen
        Zaehlwert_Geschw_Sort_2 = 0;                          //Zählwert Geschwindigkeit Sortierer 2 zurücksetzen
        Zeitsaeule_Gesch_Sort_2 = 0;                          //Zeitsäule Geschwindigkeit Sortierer 2 zurücksetzen
              
        /* Grüner Punkt anzeigen */
        Display.gfx_CircleFilled(40, 266, 20, GREEN);       //Status anzeigen grüner Punkt (Kreis x,y,r)
      
        /* Zeitsäule löschen */
        Display.gfx_RectangleFilled(350, 246, 550, 279, BLACK);        //0s = 350, 60s = 550      //Status anzeigen Zeit (Rechteck x1,y1,x2,y2)                                                             
      }
    }

/********************************************************************************************************************/

    /* Zählwert addiert Geschwindigkeit Sortierer 1 zurücksetzen */
    if ((Messung_aktiv_Geschw_Sort_1 == true) && (digitalRead(DE_Sensor_1) == LOW)) Zaehler_Geschw_Sort_1 = true;         //Zählwert addiert zurücksetzen
  
    /* Zählwert addiert Geschwindigkeit Sortierer 2 zurücksetzen */
    if ((Messung_aktiv_Geschw_Sort_2 == true) && (digitalRead(DE_Sensor_2) == LOW)) Zaehler_Geschw_Sort_2 = true;         //Zählwert addiert zurücksetzen
 
/********************************************************************************************************************/

    /* Aktuelle Wert anzeigen Geschwindigkeit Sortierer 1 */
    if (Messung_aktiv_Geschw_Sort_1 == true)
    {      
      /* Stoppzeit berechnen */
      Stoppzeit_Geschw_Sort_1 = (millis() - Startzeit_Geschw_Sort_1);             //Stoppzeit Geschwindigkeit Sortierer 1 berechnen

      /* Zeitsäule berechnen */    
      Zeitsaeule_Gesch_Sort_1 = map((Stoppzeit_Geschw_Sort_1/1000), 0, 60, 0, 200);       //Zeitsäule = map(value, fromLow, fromHigh, toLow, toHigh)
      /* Achtung: map hat nur 8bit!  */

      /* Zeitsäulen anzeigen */
      Display.gfx_RectangleFilled(350, 86, (Zeitsaeule_Gesch_Sort_1 + 350), 119, Texthintergrund_Menue);         //0s = 350, 60s = 550      //Status anzeigen Zeit (Rechteck x1,y1,x2,y2)

      /* Aktueller Wert anzeigen */
      Display.txt_Height(4);                        //Texthöhe
      Display.txt_Width(3);                         //Textweite
      Display.txt_Inverse(OFF);                     //Text invetieren
      Display.txt_Bold(OFF);                        //Text fett
      Display.txt_Set(TEXT_COLOUR, GRAY);           //Textfarbe grau

      /* Wertbegrenzung
      Die Anzeige auf 9999 begrenzen */    
      if (Zaehlwert_Geschw_Sort_1 >= Wertbegrenzung_Geschw_Sort)
      {
        Display.txt_Set(TEXT_COLOUR, RED);          //Textfarbe rot
        Zaehlwert_Geschw_Sort_1 = Wertbegrenzung_Geschw_Sort;         
      }

      /* Aktuelle Wert anzeigen Geschwindigkeit Sortierer 1 */
      Display.gfx_MoveTo(80, 85);                   //Text Position (x,y)
      Display.print("");
      Display.print(Zaehlwert_Geschw_Sort_1);       //Wert anzeigen
      Display.print(" cpm   ");                     //Text anzeigen        
    }

/********************************************************************************************************************/

    /* Aktuelle Wert anzeigen Geschwindigkeit Sortierer 2 */
    if (Messung_aktiv_Geschw_Sort_2 == true)
    {
      /* Stoppzeit berechnen */
      Stoppzeit_Geschw_Sort_2 = (millis() - Startzeit_Geschw_Sort_2);             //Stoppzeit Geschwindigkeit Sortierer 2 berechnen

      /* Zeitsäule berechnen */    
      Zeitsaeule_Gesch_Sort_2 = map((Stoppzeit_Geschw_Sort_2/1000), 0, 60, 0, 200);       //Zeitsäule = map(value, fromLow, fromHigh, toLow, toHigh)
      /* Achtung: map hat nur 8bit!  */

      /* Zeitsäulen anzeigen */
      Display.gfx_RectangleFilled(350, 246, (Zeitsaeule_Gesch_Sort_2 + 350), 279, Texthintergrund_Menue);        //0s = 350, 60s = 550      //Status anzeigen Zeit (Rechteck x1,y1,x2,y2)

      /* Aktueller Wert anzeigen */
      Display.txt_Height(4);                        //Texthöhe
      Display.txt_Width(3);                         //Textweite
      Display.txt_Inverse(OFF);                     //Text invetieren
      Display.txt_Bold(OFF);                        //Text fett
      Display.txt_Set(TEXT_COLOUR, GRAY);           //Textfarbe grau

      /* Wertbegrenzung
      Die Anzeige auf 9999 begrenzen */    
      if (Zaehlwert_Geschw_Sort_2 >= Wertbegrenzung_Geschw_Sort)
      {
        Display.txt_Set(TEXT_COLOUR, RED);          //Textfarbe rot
        Zaehlwert_Geschw_Sort_2 = Wertbegrenzung_Geschw_Sort;         
      }

      /* Aktuelle Wert anzeigen Geschwindigkeit Sortierer 2 */
      Display.gfx_MoveTo(80, 245);                  //Text Position (x,y)
      Display.print("");
      Display.print(Zaehlwert_Geschw_Sort_2);       //Wert anzeigen
      Display.print(" cpm   ");                     //Text anzeigen     
    }
        
/********************************************************************************************************************/
        
      /* Geschwindigkeit Sortierer 1 gestoppt */
      if ((Messung_aktiv_Geschw_Sort_1 == true) && ((Stoppzeit_Geschw_Sort_1 >= 60000) || (Messung_Ein_Geschw_Sort == false)))               //Zeit abfragen nach 60s
      {    
        /* Messung aktiv zurücksetzen */ 
        Messung_aktiv_Geschw_Sort_1 = false;          //Messung aktiv Geschwindgkeit Sortierer 1 zurücksetzen
      
        /* Roter Punkt anzeigen */
        Display.gfx_CircleFilled(40, 106, 20, RED);       //Status anzeigen roter Punkt (Kreis x,y,r)  

        /* Wert nur übernehmen wenn volle Messzeit abgelaufen ist! */
        if(Messung_Ein_Geschw_Sort == true)       
        {
          /* Höchsterwert berechnen */        
          if (Zaehlwert_Geschw_Sort_1 >= Hoechstwert_Geschw_Sort_1)
          {           
            Hoechstwert_Geschw_Sort_1 = Zaehlwert_Geschw_Sort_1;      //Höchstwert übernehmen

            /* Höchstwert 50% */
            Hoechstwert_50_Geschw_Sort_1 = Hoechstwert_Geschw_Sort_1 * 5 / 10;  //50% vom Höchstwert berechnen
          
            /* Höchstwert anzeigen */
            Display.txt_Height(2);                        //Texthöhe
            Display.txt_Width(2);                         //Textweite
            Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe
        
            Display.gfx_MoveTo(83, 145);                  //Text Position (x,y)
            Display.print(Hoechstwert_Geschw_Sort_1);     //Wert anzeigen
            Display.print(" Hoechstwert    ");            //Text anzeigen
          }

          /* Filter
             Filtert automatisch alle die unter 50% vom aktuellen Höchstwert sind! */
          if (Zaehlwert_Geschw_Sort_1 >= Hoechstwert_50_Geschw_Sort_1)
          {
            /* Mittelwert berechnen */
            Messungen_Geschw_Sort_1 = ++Messungen_Geschw_Sort_1;          //Messungen zählen
            Summe_Mittelwert_Geschw_Sort_1 = Summe_Mittelwert_Geschw_Sort_1 + Zaehlwert_Geschw_Sort_1;        //Summe Mittelwert
            Mittelwert_Geschw_Sort_1 = Summe_Mittelwert_Geschw_Sort_1 / Messungen_Geschw_Sort_1;        //Mittelwert berechnen

            /* Mittelwert anzeigen */
            Display.txt_Height(2);                          //Texthöhe
            Display.txt_Width(2);                           //Textweite
            Display.txt_Set(TEXT_COLOUR, Textfarbe);        //Textfarbe
      
            Display.gfx_MoveTo(83, 170);                    //Text Position (x,y)
            Display.print(Mittelwert_Geschw_Sort_1);        //Wert anzeigen
            Display.print(" Mittelwert (");                 //Text anzeigen
            Display.print(Messungen_Geschw_Sort_1);         //Wert anzeigen
            Display.print(" Werte) ");                      //Text anzeigen
      
            /* Kleinsterwert berechnen */
            if (Zaehlwert_Geschw_Sort_1 <= Kleinstwert_Geschw_Sort_1)
            {
              Kleinstwert_Geschw_Sort_1 = Zaehlwert_Geschw_Sort_1;        //Kleinstwert übernehmen

              /* Kleinstwert anzeigen */
              Display.txt_Height(2);                          //Texthöhe
              Display.txt_Width(2);                           //Textweite
              Display.txt_Set(TEXT_COLOUR, Textfarbe);        //Textfarbe
        
              Display.gfx_MoveTo(83, 195);                    //Text Position (x,y)
              Display.print(Kleinstwert_Geschw_Sort_1);       //Wert anzeigen
              Display.print(" Kleinstwert    ");              //Text anzeigen
            }

            /* History 
               Schieberegister letzten Werte. */
            Zaehlwerte_Geschw_Sort_1[59] = Zaehlwerte_Geschw_Sort_1[58];
            Zaehlwerte_Geschw_Sort_1[58] = Zaehlwerte_Geschw_Sort_1[57];
            Zaehlwerte_Geschw_Sort_1[57] = Zaehlwerte_Geschw_Sort_1[56];
            Zaehlwerte_Geschw_Sort_1[56] = Zaehlwerte_Geschw_Sort_1[55];
            Zaehlwerte_Geschw_Sort_1[55] = Zaehlwerte_Geschw_Sort_1[54];
            Zaehlwerte_Geschw_Sort_1[54] = Zaehlwerte_Geschw_Sort_1[53];
            Zaehlwerte_Geschw_Sort_1[53] = Zaehlwerte_Geschw_Sort_1[52];
            Zaehlwerte_Geschw_Sort_1[52] = Zaehlwerte_Geschw_Sort_1[51];
            Zaehlwerte_Geschw_Sort_1[51] = Zaehlwerte_Geschw_Sort_1[50];
            Zaehlwerte_Geschw_Sort_1[50] = Zaehlwerte_Geschw_Sort_1[49];
               
            Zaehlwerte_Geschw_Sort_1[49] = Zaehlwerte_Geschw_Sort_1[48];
            Zaehlwerte_Geschw_Sort_1[48] = Zaehlwerte_Geschw_Sort_1[47];
            Zaehlwerte_Geschw_Sort_1[47] = Zaehlwerte_Geschw_Sort_1[46];
            Zaehlwerte_Geschw_Sort_1[46] = Zaehlwerte_Geschw_Sort_1[45];
            Zaehlwerte_Geschw_Sort_1[45] = Zaehlwerte_Geschw_Sort_1[44];
            Zaehlwerte_Geschw_Sort_1[44] = Zaehlwerte_Geschw_Sort_1[43];
            Zaehlwerte_Geschw_Sort_1[43] = Zaehlwerte_Geschw_Sort_1[42];
            Zaehlwerte_Geschw_Sort_1[42] = Zaehlwerte_Geschw_Sort_1[41];
            Zaehlwerte_Geschw_Sort_1[41] = Zaehlwerte_Geschw_Sort_1[40];
            Zaehlwerte_Geschw_Sort_1[40] = Zaehlwerte_Geschw_Sort_1[39];
               
            Zaehlwerte_Geschw_Sort_1[39] = Zaehlwerte_Geschw_Sort_1[38];
            Zaehlwerte_Geschw_Sort_1[38] = Zaehlwerte_Geschw_Sort_1[37];
            Zaehlwerte_Geschw_Sort_1[37] = Zaehlwerte_Geschw_Sort_1[36];
            Zaehlwerte_Geschw_Sort_1[36] = Zaehlwerte_Geschw_Sort_1[35];
            Zaehlwerte_Geschw_Sort_1[35] = Zaehlwerte_Geschw_Sort_1[34];
            Zaehlwerte_Geschw_Sort_1[34] = Zaehlwerte_Geschw_Sort_1[33];
            Zaehlwerte_Geschw_Sort_1[33] = Zaehlwerte_Geschw_Sort_1[32];
            Zaehlwerte_Geschw_Sort_1[32] = Zaehlwerte_Geschw_Sort_1[31];
            Zaehlwerte_Geschw_Sort_1[31] = Zaehlwerte_Geschw_Sort_1[30];
            Zaehlwerte_Geschw_Sort_1[30] = Zaehlwerte_Geschw_Sort_1[29];
                           
            Zaehlwerte_Geschw_Sort_1[29] = Zaehlwerte_Geschw_Sort_1[28];
            Zaehlwerte_Geschw_Sort_1[28] = Zaehlwerte_Geschw_Sort_1[27];
            Zaehlwerte_Geschw_Sort_1[27] = Zaehlwerte_Geschw_Sort_1[26];
            Zaehlwerte_Geschw_Sort_1[26] = Zaehlwerte_Geschw_Sort_1[25];
            Zaehlwerte_Geschw_Sort_1[25] = Zaehlwerte_Geschw_Sort_1[24];
            Zaehlwerte_Geschw_Sort_1[24] = Zaehlwerte_Geschw_Sort_1[23];
            Zaehlwerte_Geschw_Sort_1[23] = Zaehlwerte_Geschw_Sort_1[22];
            Zaehlwerte_Geschw_Sort_1[22] = Zaehlwerte_Geschw_Sort_1[21];
            Zaehlwerte_Geschw_Sort_1[21] = Zaehlwerte_Geschw_Sort_1[20];
            Zaehlwerte_Geschw_Sort_1[20] = Zaehlwerte_Geschw_Sort_1[19];
                  
            /* History 
               Schieberegister letzten zwanzig Werte. */
            Zaehlwerte_Geschw_Sort_1[19] = Zaehlwerte_Geschw_Sort_1[18];
            Zaehlwerte_Geschw_Sort_1[18] = Zaehlwerte_Geschw_Sort_1[17];
            Zaehlwerte_Geschw_Sort_1[17] = Zaehlwerte_Geschw_Sort_1[16];
            Zaehlwerte_Geschw_Sort_1[16] = Zaehlwerte_Geschw_Sort_1[15];
            Zaehlwerte_Geschw_Sort_1[15] = Zaehlwerte_Geschw_Sort_1[14];
            Zaehlwerte_Geschw_Sort_1[14] = Zaehlwerte_Geschw_Sort_1[13];
            Zaehlwerte_Geschw_Sort_1[13] = Zaehlwerte_Geschw_Sort_1[12];
            Zaehlwerte_Geschw_Sort_1[12] = Zaehlwerte_Geschw_Sort_1[11];
            Zaehlwerte_Geschw_Sort_1[11] = Zaehlwerte_Geschw_Sort_1[10];
            Zaehlwerte_Geschw_Sort_1[10] = Zaehlwerte_Geschw_Sort_1[9];
                   
            Zaehlwerte_Geschw_Sort_1[9] = Zaehlwerte_Geschw_Sort_1[8];                      
            Zaehlwerte_Geschw_Sort_1[8] = Zaehlwerte_Geschw_Sort_1[7];
            Zaehlwerte_Geschw_Sort_1[7] = Zaehlwerte_Geschw_Sort_1[6];
            Zaehlwerte_Geschw_Sort_1[6] = Zaehlwerte_Geschw_Sort_1[5];
            Zaehlwerte_Geschw_Sort_1[5] = Zaehlwerte_Geschw_Sort_1[4];
            Zaehlwerte_Geschw_Sort_1[4] = Zaehlwerte_Geschw_Sort_1[3];
            Zaehlwerte_Geschw_Sort_1[3] = Zaehlwerte_Geschw_Sort_1[2];
            Zaehlwerte_Geschw_Sort_1[2] = Zaehlwerte_Geschw_Sort_1[1];
            Zaehlwerte_Geschw_Sort_1[1] = Zaehlwerte_Geschw_Sort_1[0];
            Zaehlwerte_Geschw_Sort_1[0] = Zaehlwert_Geschw_Sort_1;             

          //Schieberegister  
/*          for (int i = 0; i <= 59; i++)
          {            
            Zaehlwerte_Geschw_Sort_1[i+1] = Zaehlwerte_Geschw_Sort_1[i];
            Zaehlwerte_Geschw_Sort_1[0] = Zaehlwert_Geschw_Sort_1;            //Wertübergabe Schieberegister Position 0               
          }
*/
            /* Letzte 5 Werte anzeigen */
            Liste(590, 92, 0, 5, Zaehlwerte_Geschw_Sort_1, Mittelwert_Geschw_Sort_1, 0, RED, "cpm   ");     //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
          }
             
          /* Aktueller Wert anzeigen */
          Display.txt_Height(4);                        //Texthöhe
          Display.txt_Width(3);                         //Textweite
          Display.txt_Inverse(OFF);                     //Text invetieren
          Display.txt_Bold(OFF);                        //Text fett
          Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe
      
          Display.gfx_MoveTo(80, 85);                   //Text Position (x,y)
          Display.print("");
          Display.print(Zaehlwert_Geschw_Sort_1);       //Wert anzeigen
          Display.print(" cpm   ");                     //Text anzeigen
        }
     
        /* Verzögerung für nächste Messung */
        delay(100);                                   //Verzögerung 100ms
      
        Zaehler_Geschw_Sort_1 = true;
        Startzeit_speichern_Geschw_Sort_1 = true;     //Startzeit speichern Geschwindigkeit Sortierer 1 setzen     
      }  
  
/********************************************************************************************************************/
    
      /* Geschwindigkeit Sortierer 2 gestoppt */
      if ((Messung_aktiv_Geschw_Sort_2 == true) && ((Stoppzeit_Geschw_Sort_2 >= 60000) || (Messung_Ein_Geschw_Sort == false)))       //Zeit abfragen nach 60s
      {    
        /* Messung aktiv zurücksetzen */ 
        Messung_aktiv_Geschw_Sort_2 = false;          //Messung aktiv Geschwindgkeit Sortierer 2 zurücksetzen
      
        /* Roter Punkt anzeigen */
        Display.gfx_CircleFilled(40, 266, 20, RED);                               //Status anzeigen roter Punkt (Kreis x,y,r)

        /* Wert nur übernehmen wenn volle Messzeit abgelaufen ist! */
        if (Messung_Ein_Geschw_Sort == true)       
        {
          /* Höchsterwert berechnen */           
          if ((Messung_Ein_Geschw_Sort == true) && (Zaehlwert_Geschw_Sort_2 >= Hoechstwert_Geschw_Sort_2))
          {                 
            Hoechstwert_Geschw_Sort_2 = Zaehlwert_Geschw_Sort_2;        //Höchstwert übernehmen

            /* Höchstwert 50% */
            Hoechstwert_50_Geschw_Sort_2 = Hoechstwert_Geschw_Sort_2 * 5 / 10;  //50% vom Höchstwert berechnen
          
            /* Höchstwert anzeigen */
            Display.txt_Height(2);                        //Texthöhe
            Display.txt_Width(2);                         //Textweite
            Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe
        
            Display.gfx_MoveTo(83, 305);                  //Text Position (x,y)
            Display.print(Hoechstwert_Geschw_Sort_2);     //Wert anzeigen
            Display.print(" Hoechstwert    ");            //Text anzeigen
          }

          /* Filter
             Filtert automatisch alle die unter 50% vom aktuellen Höchstwert sind! */
          if (Zaehlwert_Geschw_Sort_2 >= Hoechstwert_50_Geschw_Sort_2)
          {
            /* Mittelwert berechnen */
            Messungen_Geschw_Sort_2 = ++Messungen_Geschw_Sort_2;          //Messungen zählen
            Summe_Mittelwert_Geschw_Sort_2 = Summe_Mittelwert_Geschw_Sort_2 + Zaehlwert_Geschw_Sort_2;        //Summe Mittelwert
            Mittelwert_Geschw_Sort_2 = Summe_Mittelwert_Geschw_Sort_2 / Messungen_Geschw_Sort_2;        //Mittelwert berechnen
      
            /* Mittelwert anzeigen */
            Display.txt_Height(2);                          //Texthöhe
            Display.txt_Width(2);                           //Textweite
            Display.txt_Set(TEXT_COLOUR, Textfarbe);        //Textfarbe
      
            Display.gfx_MoveTo(83, 330);                    //Text Position (x,y)
            Display.print(Mittelwert_Geschw_Sort_2);        //Wert anzeigen
            Display.print(" Mittelwert (");                 //Text anzeigen
            Display.print(Messungen_Geschw_Sort_2);         //Wert anzeigen
            Display.print(" Werte) ");                      //Text anzeigen

            /* Kleinsterwert berechnen */
            if (Zaehlwert_Geschw_Sort_2 <= Kleinstwert_Geschw_Sort_2)
            {
              Kleinstwert_Geschw_Sort_2 = Zaehlwert_Geschw_Sort_2;        //Kleinstwert übernehmen
        
              /* Kleinstwert anzeigen */
              Display.txt_Height(2);                          //Texthöhe
              Display.txt_Width(2);                           //Textweite
              Display.txt_Set(TEXT_COLOUR, Textfarbe);        //Textfarbe
        
              Display.gfx_MoveTo(83, 355);                    //Text Position (x,y)
              Display.print(Kleinstwert_Geschw_Sort_2);       //Wert anzeigen
              Display.print(" Kleinstwert    ");              //Text anzeigen
            }

            /* History 
               Schieberegister letzten Werte. */
            Zaehlwerte_Geschw_Sort_2[59] = Zaehlwerte_Geschw_Sort_2[58];
            Zaehlwerte_Geschw_Sort_2[58] = Zaehlwerte_Geschw_Sort_2[57];
            Zaehlwerte_Geschw_Sort_2[57] = Zaehlwerte_Geschw_Sort_2[56];
            Zaehlwerte_Geschw_Sort_2[56] = Zaehlwerte_Geschw_Sort_2[55];
            Zaehlwerte_Geschw_Sort_2[55] = Zaehlwerte_Geschw_Sort_2[54];
            Zaehlwerte_Geschw_Sort_2[54] = Zaehlwerte_Geschw_Sort_2[53];
            Zaehlwerte_Geschw_Sort_2[53] = Zaehlwerte_Geschw_Sort_2[52];
            Zaehlwerte_Geschw_Sort_2[52] = Zaehlwerte_Geschw_Sort_2[51];
            Zaehlwerte_Geschw_Sort_2[51] = Zaehlwerte_Geschw_Sort_2[50];
            Zaehlwerte_Geschw_Sort_2[50] = Zaehlwerte_Geschw_Sort_2[49];

            Zaehlwerte_Geschw_Sort_2[49] = Zaehlwerte_Geschw_Sort_2[48];
            Zaehlwerte_Geschw_Sort_2[48] = Zaehlwerte_Geschw_Sort_2[47];
            Zaehlwerte_Geschw_Sort_2[47] = Zaehlwerte_Geschw_Sort_2[46];
            Zaehlwerte_Geschw_Sort_2[46] = Zaehlwerte_Geschw_Sort_2[45];
            Zaehlwerte_Geschw_Sort_2[45] = Zaehlwerte_Geschw_Sort_2[44];
            Zaehlwerte_Geschw_Sort_2[44] = Zaehlwerte_Geschw_Sort_2[43];
            Zaehlwerte_Geschw_Sort_2[43] = Zaehlwerte_Geschw_Sort_2[42];
            Zaehlwerte_Geschw_Sort_2[42] = Zaehlwerte_Geschw_Sort_2[41];
            Zaehlwerte_Geschw_Sort_2[41] = Zaehlwerte_Geschw_Sort_2[40];
            Zaehlwerte_Geschw_Sort_2[40] = Zaehlwerte_Geschw_Sort_2[39];

            Zaehlwerte_Geschw_Sort_2[39] = Zaehlwerte_Geschw_Sort_2[38];
            Zaehlwerte_Geschw_Sort_2[38] = Zaehlwerte_Geschw_Sort_2[37];
            Zaehlwerte_Geschw_Sort_2[37] = Zaehlwerte_Geschw_Sort_2[36];
            Zaehlwerte_Geschw_Sort_2[36] = Zaehlwerte_Geschw_Sort_2[35];
            Zaehlwerte_Geschw_Sort_2[35] = Zaehlwerte_Geschw_Sort_2[34];
            Zaehlwerte_Geschw_Sort_2[34] = Zaehlwerte_Geschw_Sort_2[33];
            Zaehlwerte_Geschw_Sort_2[33] = Zaehlwerte_Geschw_Sort_2[32];
            Zaehlwerte_Geschw_Sort_2[32] = Zaehlwerte_Geschw_Sort_2[31];
            Zaehlwerte_Geschw_Sort_2[31] = Zaehlwerte_Geschw_Sort_2[30];
            Zaehlwerte_Geschw_Sort_2[30] = Zaehlwerte_Geschw_Sort_2[29];
               
            Zaehlwerte_Geschw_Sort_2[29] = Zaehlwerte_Geschw_Sort_2[28];
            Zaehlwerte_Geschw_Sort_2[28] = Zaehlwerte_Geschw_Sort_2[27];
            Zaehlwerte_Geschw_Sort_2[27] = Zaehlwerte_Geschw_Sort_2[26];
            Zaehlwerte_Geschw_Sort_2[26] = Zaehlwerte_Geschw_Sort_2[25];
            Zaehlwerte_Geschw_Sort_2[25] = Zaehlwerte_Geschw_Sort_2[24];
            Zaehlwerte_Geschw_Sort_2[24] = Zaehlwerte_Geschw_Sort_2[23];
            Zaehlwerte_Geschw_Sort_2[23] = Zaehlwerte_Geschw_Sort_2[22];
            Zaehlwerte_Geschw_Sort_2[22] = Zaehlwerte_Geschw_Sort_2[21];
            Zaehlwerte_Geschw_Sort_2[21] = Zaehlwerte_Geschw_Sort_2[20];
            Zaehlwerte_Geschw_Sort_2[20] = Zaehlwerte_Geschw_Sort_2[19];
      
            /* History 
               Schieberegister letzten zwanzig Werte. */
            Zaehlwerte_Geschw_Sort_2[19] = Zaehlwerte_Geschw_Sort_2[18];
            Zaehlwerte_Geschw_Sort_2[18] = Zaehlwerte_Geschw_Sort_2[17];
            Zaehlwerte_Geschw_Sort_2[17] = Zaehlwerte_Geschw_Sort_2[16];
            Zaehlwerte_Geschw_Sort_2[16] = Zaehlwerte_Geschw_Sort_2[15];
            Zaehlwerte_Geschw_Sort_2[15] = Zaehlwerte_Geschw_Sort_2[14];
            Zaehlwerte_Geschw_Sort_2[14] = Zaehlwerte_Geschw_Sort_2[13];
            Zaehlwerte_Geschw_Sort_2[13] = Zaehlwerte_Geschw_Sort_2[12];
            Zaehlwerte_Geschw_Sort_2[12] = Zaehlwerte_Geschw_Sort_2[11];
            Zaehlwerte_Geschw_Sort_2[11] = Zaehlwerte_Geschw_Sort_2[10];
            Zaehlwerte_Geschw_Sort_2[10] = Zaehlwerte_Geschw_Sort_2[9];
          
            Zaehlwerte_Geschw_Sort_2[9] = Zaehlwerte_Geschw_Sort_2[8];                 
            Zaehlwerte_Geschw_Sort_2[8] = Zaehlwerte_Geschw_Sort_2[7];
            Zaehlwerte_Geschw_Sort_2[7] = Zaehlwerte_Geschw_Sort_2[6];
            Zaehlwerte_Geschw_Sort_2[6] = Zaehlwerte_Geschw_Sort_2[5];
            Zaehlwerte_Geschw_Sort_2[5] = Zaehlwerte_Geschw_Sort_2[4];
            Zaehlwerte_Geschw_Sort_2[4] = Zaehlwerte_Geschw_Sort_2[3];
            Zaehlwerte_Geschw_Sort_2[3] = Zaehlwerte_Geschw_Sort_2[2];
            Zaehlwerte_Geschw_Sort_2[2] = Zaehlwerte_Geschw_Sort_2[1];
            Zaehlwerte_Geschw_Sort_2[1] = Zaehlwerte_Geschw_Sort_2[0];              
            Zaehlwerte_Geschw_Sort_2[0] = Zaehlwert_Geschw_Sort_2; 
    
            /* Letzte 5 Werte anzeigen */
            Liste(590, 250, 0, 5, Zaehlwerte_Geschw_Sort_2, Mittelwert_Geschw_Sort_2, 0, RED, "cpm   ");     //Aufruf Funktion Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[20], unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit)
          }
        
          /* Aktueller Wert anzeigen */
          Display.txt_Height(4);                        //Texthöhe
          Display.txt_Width(3);                         //Textweite
          Display.txt_Inverse(OFF);                     //Text invetieren
          Display.txt_Bold(OFF);                        //Text fett
          Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe weiss
      
          Display.gfx_MoveTo(80, 245);                  //Text Position (x,y)
          Display.print("");
          Display.print(Zaehlwert_Geschw_Sort_2);       //Wert anzeigen
          Display.print(" cpm   ");                     //Text anzeigen
        }
      
        /* Verzögerung für nächste Messung */
        delay(100);                                   //Verzögerung 100ms

        Zaehler_Geschw_Sort_2 = true;
        Startzeit_speichern_Geschw_Sort_2 = true;     //Startzeit speichern Geschwindigkeit Sortierer 2 setzen
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
      if ((Messung_Ein_Geschw_Sort == false) && (Messung_aktiv_Geschw_Sort_1 == false) && (Messung_aktiv_Geschw_Sort_2 == false) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {     
        /* Touch Feld [Start] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 500, 420, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Stopp");                  //Taste anzeigen gedrückt 

          /* Taste anzeigen nicht drückbar */
          Display.gfx_Button(Status_Touch_Taste, 650, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Zrug");        //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 350, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");       //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 50, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Liste");        //Taste anzeigen nicht drückbar

          Display.gfx_Button(Status_Touch_Taste, 480, 195, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "= o  ");       //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 380, 195, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "- o -");       //Taste anzeigen nicht drückbar

          Display.gfx_Button(Status_Touch_Taste, 480, 355, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "= o  ");       //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 380, 355, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "- o -");       //Taste anzeigen ungedrückt

          /* Messung Ein */
          Messung_Ein_Geschw_Sort = true;         //Messung Ein Geschwindigkeit Sortierer setzen

          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          digitalWrite(DA_Versorgung_24VDC, HIGH);      //Digital Ausgang Versorgung 24VDC setzen
          delay(1000);                                  //Verzögerung 1000ms
          
          Statusanzeige();              //Aufruf Funktion Statusanzeige           
        }
      }
    
/********************************************************************************************************************/

      /* Touch Feld abfragen [Stopp] Taste gedrückt (Doppel Taste Start/Stopp)
         Es wird die Start Taste angezeigt! */
      if ((Messung_Ein_Geschw_Sort == true) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {
        Status_Touch_Taste = !Status_Touch_Taste;                                               //Status Taste Invertieren
           
        /* Touch Feld [Stopp] Taste ausführen */
        if (Status_Touch_Taste)
        { 
          Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Start");                  //Taste anzeigen gedrückt

          /* Taste anzeigen ungedrückt anzeigen */
          Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");   //Taste anzeigen ungedrückt
          Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");               //Taste anzeigen ungedrückt
          Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Liste");                  //Taste anzeigen ungedrückt

          /* [- o -] Taste aktiv */
          if (Sensor_Logik_Sort_1 ==0)       //Überwachung Sensor Logik Geschwindigkeit Sortierer 1 (0= - o -, 1= = o)
          {
            /* [= o  ] Taste anzeigen Funktion deaktiviert */
            Display.gfx_Button(Status_Touch_Taste, 480, 195, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "= o  ");                  //Taste anzeigen ungedrückt 
                   
            /* [- o -] Taste anzeigen Funktion aktiv */         
            Display.gfx_Button(Status_Touch_Taste, 380, 195, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "- o -");                  //Taste anzeigen gedrückt             
          }

          /* [= o  ] Taste aktiv */
          if (Sensor_Logik_Sort_1 ==1)       //Überwachung Sensor Logik Geschwindigkeit Sortierer 1 (0= - o -, 1= = o)
          {                   
            /* [- o -] Taste anzeigen Funktion deaktiviert */         
            Display.gfx_Button(Status_Touch_Taste, 380, 195, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "- o -");                  //Taste anzeigen ungedrückt 

            /* [= o  ] Taste anzeigen Funktion aktiv */
            Display.gfx_Button(Status_Touch_Taste, 480, 195, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "= o  ");                  //Taste anzeigen gedrückt             
          }

          /* [- o -] Taste aktiv */
          if (Sensor_Logik_Sort_2 ==0)       //Überwachung Sensor Logik Geschwindigkeit Sortierer 1 (0= - o -, 1= = o)
          {
            /* [= o  ] Taste anzeigen Funktion deaktiviert */
            Display.gfx_Button(Status_Touch_Taste, 480, 355, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "= o  ");                  //Taste anzeigen ungedrückt 
                   
            /* [- o -] Taste anzeigen Funktion aktiv */         
            Display.gfx_Button(Status_Touch_Taste, 380, 355, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "- o -");                  //Taste anzeigen gedrückt                 
          }

          /* [= o  ] Taste aktiv */
          if(Sensor_Logik_Sort_2 ==1)     //Überwachung Sensor Logik Geschwindigkeit Sortierer 1 (0= - o -, 1= = o)
          {
            /* [- o -] Taste anzeigen Funktion deaktiviert */         
            Display.gfx_Button(Status_Touch_Taste, 380, 355, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "- o -");                  //Taste anzeigen ungedrückt 

            /* [= o  ] Taste anzeigen Funktion aktiv */
            Display.gfx_Button(Status_Touch_Taste, 480, 355, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "= o  ");                  //Taste anzeigen gedrückt                
          }
      
          /* Messung Aus */      
          Messung_Ein_Geschw_Sort = false;          //Messung Ein Geschwindigkeit Sortierer zurücksetzen      
          
          /* Buzzer */
          Buzzer(500);                        //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

          digitalWrite(DA_Versorgung_24VDC, LOW);     //Digital Ausgang Versorgung 24VDC setzen
          delay(1000);                                //Verzögerung 1000ms                        
        }
      }
        
/********************************************************************************************************************/

      /* Touch Feld abfragen [Zrug] Taste gedrückt */
      if ((Messung_Ein_Geschw_Sort == false) && (X_Pos_Touch >= 620) && (X_Pos_Touch <= 720) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {
        /* Touch Feld [Zrug] Taste ausführen */
        if (Status_Touch_Taste)
        {     
          Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");     //Taste anzeigen gedrückt
        
          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          
          Menue_angewaehlt = 0;               //Hauptmenü anwählen
          Bild_aufgebaut[0] = false;          //Bildschirm aufgebaut zurücksetzen

          digitalWrite(DA_Versorgung_24VDC, LOW);               //Digital Ausgang 24VDC Versorgung zurücksetzen         
        }
     }
    
/********************************************************************************************************************/
      
      /* Touch Feld abfragen [Reset] Taste gedrückt */
      if ((Messung_Ein_Geschw_Sort == false) && (X_Pos_Touch >= 320) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {
        /* Touch Feld [Reset] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET");                     //Taste anzeigen gedrückt
          
          Messung_aktiv_Geschw_Sort_1 = false;              //Messung aktiv Geschwindigkeit Sortierer 1 zurücksetzen
          Messung_aktiv_Geschw_Sort_2 = false;              //Messung aktiv Geschwindigkeit Sortierer 2 zurücksetzen
     
          /* Alle Zählwerte zurücksetzen */
          for (int i = 0; i <= 59; i++)
          {
            Zaehlwerte_Geschw_Sort_1[i] = 0;                //Zählwerte Geschwindigkeit Sortierer 1 0-19 zurücksetzen
            Zaehlwerte_Geschw_Sort_2[i] = 0;                //Zählwerte Geschwindigkeit Sortierer 2 0-19 zurücksetzen 
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

          Startzeit_speichern_Geschw_Sort_1 = true;                                 //Startzeit speichern Geschwindigkeit Sortierer 1 setzen
          Startzeit_speichern_Geschw_Sort_2 = true;                                 //Startzeit speichern Geschwindigkeit Sortierer 2 setzen
          
          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
          /* Bildschirm neu aufbauen */
          Bild_aufgebaut[10] = false;                //Bildschirm aufgebaut zurücksetzen
        }
      }
    
/********************************************************************************************************************/

      /* Touch Feld abfragen [Liste] Taste gedrückt */
      /* Feld Grösse bestimmen:  X von Pos. = Feld Pos. -30 / X bis Pos. = Feld Pos. +100                         
                                 Y von Pos. = Feld Pos. -30 / Y bis Pos. = Feld Pos. +30   
      */
      if ((Messung_Ein_Geschw_Sort == false) && (X_Pos_Touch >= 20) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {     
        /* Touch Feld [Liste] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Liste");                  //Taste anzeigen gedrückt 
          
          /* Messung stoppen */
          Messung_Ein_Geschw_Sort = false;        //Messung Ein Geschwindigkeit Sortierer zurücksetzen 

          Messung_aktiv_Geschw_Sort_1 = false;              //Messung aktiv Geschwindigkeit Sortierer 1 zurücksetzen
          Messung_aktiv_Geschw_Sort_2 = false;              //Messung aktiv Geschwindigkeit Sortierer 2 zurücksetzen

          Zaehler_Geschw_Sort_1 = false;
          Zaehler_Geschw_Sort_2 = false;

          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
          Menue_angewaehlt = 15;                                                    //Menü Geschwindigkeitsanzeige Sortierer Liste anwählen
          Bild_aufgebaut[15] = false;                                               //Bildschirm aufgebaut zurücksetzen    
        }
      }

/********************************************************************************************************************/

      /* Touch Feld abfragen [i] Taste gedrückt */
      if ((Messung_Ein_Geschw_Sort == false) && (X_Pos_Touch >= 720) && (X_Pos_Touch <= 799) && (Y_Pos_Touch >= 0) && (Y_Pos_Touch <= 45))    //Überwachung Touch Feld
      {
        /* Touch Feld [i] Taste ausführen */
        if (Status_Touch_Taste)
        {
          Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, GRAY, Schrifttyp, Textbreite, Textrahmen, "i");                  //Taste anzeigen gedrückt

          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
          Menue_angewaehlt = 7;               //Menü Info anwählen
          Bild_aufgebaut[7] = false;          //Bildschirm Info aufgebaut zurücksetzen
          Letztes_Menue = 10;                 //Letztes angewähltes Menü
          Info_Seite = 10;                    //Info Seite anwählen        
        }
      }
            
/********************************************************************************************************************/

      /* Touch Feld abfragen [- o -] Taste gedrückt */
      if ((Messung_Ein_Geschw_Sort == false) && (X_Pos_Touch >= 350) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 165) && (Y_Pos_Touch <= 225))   //Überwachung Touch Feld
      {      
        /* Touch Feld [- o -] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          /* [= o  ] Taste anzeigen Funktion deaktiviert */
          Display.gfx_Button(Status_Touch_Taste, 480, 195, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "= o  ");                  //Taste anzeigen ungedrückt 
                   
          /* [- o -] Taste anzeigen Funktion aktiv */         
          Display.gfx_Button(Status_Touch_Taste, 380, 195, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "- o -");                  //Taste anzeigen gedrückt 

          Sensor_Logik_Sort_1 = 0;                //Sensor Logik Geschwindigkeit Sortierer 1 (0= - o -, 1= = o)
          
          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        }
      }
            
/********************************************************************************************************************/

      /* Touch Feld abfragen [= o  ] Taste gedrückt */
      if ((Messung_Ein_Geschw_Sort == false) && (X_Pos_Touch >= 450) && (X_Pos_Touch <= 580) && (Y_Pos_Touch >= 165) && (Y_Pos_Touch <= 225))   //Überwachung Touch Feld
      {     
        /* Touch Feld [= o  ] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          /* [- o -] Taste anzeigen Funktion deaktiviert */
          Display.gfx_Button(Status_Touch_Taste, 380, 195, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "- o -");                  //Taste anzeigen ungedrückt 
          
          /* [= o  ] Taste anzeigen Funktion aktiv */          
          Display.gfx_Button(Status_Touch_Taste, 480, 195, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "= o  ");                  //Taste anzeigen gedrückt 

          Sensor_Logik_Sort_1 = 1;                //Sensor Logik Geschwindigkeit Sortierer 1 (0= - o -, 1= = o)
                    
          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit) 
        }
      }
            
/********************************************************************************************************************/

      /* Touch Feld abfragen [- o -] Taste gedrückt */
      if ((Messung_Ein_Geschw_Sort == false) && (X_Pos_Touch >= 350) && (X_Pos_Touch <= 480) && (Y_Pos_Touch >= 325) && (Y_Pos_Touch <= 385))   //Überwachung Touch Feld
      {      
        /* Touch Feld [- o -] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          /* [= o  ] Taste anzeigen Funktion deaktiviert */
          Display.gfx_Button(Status_Touch_Taste, 480, 355, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "= o  ");                  //Taste anzeigen ungedrück
                    
          /* [- o -] Taste anzeigen Funktion aktiv */
          Display.gfx_Button(Status_Touch_Taste, 380, 355, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "- o -");                  //Taste anzeigen gedrückt 

          Sensor_Logik_Sort_2 = 0;                //Sensor Logik Geschwindigkeit Sortierer 2 (0= - o -, 1= = o)
                    
          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit) 
        }
      }
            
/********************************************************************************************************************/

      /* Touch Feld abfragen [= o ] Taste gedrückt */
      if ((Messung_Ein_Geschw_Sort == false) && (X_Pos_Touch >= 450) && (X_Pos_Touch <= 580) && (Y_Pos_Touch >= 325) && (Y_Pos_Touch <= 385))   //Überwachung Touch Feld
      {     
        /* Touch Feld [= o  ] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          /* [- o -] Taste anzeigen Funktion deaktiviert */
          Display.gfx_Button(Status_Touch_Taste, 380, 355, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "- o -");                  //Taste anzeigen ungedrückt 
                    
          /* [= o  ] Taste anzeigen Funktion aktiv */
          Display.gfx_Button(Status_Touch_Taste, 480, 355, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "= o  ");                  //Taste anzeigen gedrückt 

          Sensor_Logik_Sort_2 = 1;                //Sensor Logik Geschwindigkeit Sortierer 2 (0= - o -, 1= = o)
                    
          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit) 
        }
      }
            
/********************************************************************************************************************/

    }       //Touch Freigabe Ende

/********************************************************************************************************************/
  
  } while (Messung_Ein_Geschw_Sort == true);        /* Überwachung Messung eingeschaltet, 
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
       
//    dataFile.println(Zaehlwert_Geschw_Sort_1);
//    dataFile.println(Zaehlwert_Geschw_Sort_2);    
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
