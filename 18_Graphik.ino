/* 18.Graphik
Zeichnet einen Graph auf mit den angegebenen Parameter, Max Bar und Zeit
*/

void Graphik(bool Bildaufbau, bool Werte_Reset)           //Funktion Graphik    
{     
  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[18] == false)           //Überwachung Bildschirm aufgebaut
  {    
    Display.gfx_Cls();            //Display löschen
    Statusanzeige();              //Aufruf Funktion Statusanzeige
      
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Analogeanzeige Graphik");   //Funktion Namen anzeigen
    
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");     //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                                 //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Start");                                //Taste anzeigen ungedrückt 
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                     //Taste anzeigen gedrückt
    Display.gfx_Button(Status_Touch_Taste, 200, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Analog");                                //Taste anzeigen ungedrückt

    /* Touch Zeit Achse Tasten ungedrückt anzeigen */
    if(Graphik_Freigabe == false)
    {
      Display.gfx_Button(Status_Touch_Taste, 50, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "2s");                       //Taste anzeigen ungedrückt
      Display.gfx_Button(Status_Touch_Taste, 200, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "5s");                      //Taste anzeigen ungedrückt
      Display.gfx_Button(Status_Touch_Taste, 350, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "10s");                     //Taste anzeigen ungedrückt
      Display.gfx_Button(Status_Touch_Taste, 500, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "30s");                     //Taste anzeigen ungedrückt 
      Display.gfx_Button(Status_Touch_Taste, 650, 150, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "60s");                     //Taste anzeigen gedrückt

      Display.gfx_Button(Status_Touch_Taste, 50, 200, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "2min");                     //Taste anzeigen ungedrückt
      Display.gfx_Button(Status_Touch_Taste, 200, 200, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "5min");                    //Taste anzeigen ungedrückt
      Display.gfx_Button(Status_Touch_Taste, 350, 200, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "10min");                   //Taste anzeigen ungedrückt
      Display.gfx_Button(Status_Touch_Taste, 500, 200, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "30min");                   //Taste anzeigen ungedrückt
      Display.gfx_Button(Status_Touch_Taste, 650, 200, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "60min");                   //Taste anzeigen ungedrückt
      Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Strom Sensor     ");      //Taste anzeigen ungedrückt

      Display.gfx_TriangleFilled(385, 300, 385, 340, 425, 320, BLUE);      //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
      Display.gfx_Triangle(385, 300, 385, 340, 425, 320, WHITE);           //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
      Display.gfx_TriangleFilled(100, 300, 100, 340, 60, 320, BLUE);       //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)
      Display.gfx_Triangle(100, 300, 100, 340, 60, 320, WHITE);            //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)

      Display.txt_Height(2);                      //Texthöhe
      Display.txt_Width(2);                       //Textweite
      Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
      Display.txt_Inverse(OFF);                   //Text invetieren
      Display.txt_Bold(OFF);                      //Text fett
      
      Display.gfx_MoveTo(110, 115);               //Text Position (x,y)
      Display.print("Zeit Auswahl");              //Text anzeigen
          
      Display.gfx_MoveTo(110, 270);               //Text Position (x,y)
      Display.print("Port Auswahl");              //Text anzeigen
    }

    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);       //Info Kreis zeichnen (Kreis x,y,r)
    
    /* Buzzer */
    Buzzer(100);                                  //Aufruf Funktion Buzzer(int Buzzer_Zeit)
    
    Bild_aufgebaut[18] = true;                    //Bildschirm aufgebaut setzen   
  }
  
/********************************************************************************************************************/

  /* Graphik Raster Aufbauen */
  if (Graphik_Freigabe == true && Graph_Raster == false)         //Überwachung Zeit ausgewählt und Graphik noch nicht gezeichnet
  {
    Display.gfx_Button(Status_Touch_Taste, 700, 70, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Endlos");       //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 700, 120, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Filter");       //Taste anzeigen ungedrückt

    Display.gfx_Line(100, 390, 650, 390, WHITE);                //x Linie zeichnen (Linie x1,y1,x2,y2)
    Display.gfx_Line(100, 390, 100, 100, WHITE);                //y Linie zeichnen (Linie x1,y1,x2,y2) 
            
    /* Text anzeigen */
    Display.txt_Height(2);                                //Texthöhe
    Display.txt_Width(2);                                 //Textweite
    Display.txt_Set(TEXT_COLOUR, WHITE);                  //Textfarbe
    Display.gfx_MoveTo(50, 75);                           //Text Position (x,y)

    if ((Einheit_Analog >= 30) && (Einheit_Analog <= 39))
    {
      Display.print("5");                         //Text anzeigen
      Display.print("\t");                        //Text anzeigen   
    }
    else
    {
      Display.print(Max_Wert_Analog);             //Text anzeigen
      Display.print("\t");                        //Text anzeigen 
    }
    
    if (Einheit_Analog <= 9)
    {
      Display.print("bar");                       //Text anzeigen 
    }

    if ((Einheit_Analog >= 10) && (Einheit_Analog <= 19))
    {
      Display.print("Nl/min");                    //Text anzeigen 
    }

    if ((Einheit_Analog >= 20) && (Einheit_Analog <= 29))
    {
      Display.print("Grad");                      //Text anzeigen 
    }
    
    if ((Einheit_Analog >= 30) && (Einheit_Analog <= 39))
    {
      Display.print("V");                         //Text anzeigen 
    }
    
    Display.gfx_MoveTo(660, 385);                 //Text Position (x,y)
    Display.print(Graphik_Text_Anzeige);          //Text anzeigen 
    Display.print("\t");                          //Text anzeigen 

    /* Einheit anzeigen */
    if (Einheit_Abfrage == false)             //Überwachung Graphik Einheit Abfrage s
    {        
      Display.print("s");                     //Text anzeigen        
    }
     
    if (Einheit_Abfrage == true)              //Überwachung Graphik Einheit Abfrage min
    {
      Display.print("min");                   //Text anzeigen                
    }

    Graph_Raster = true;                      //Graphik Raster gezeichnet setzen      
  }

/********************************************************************************************************************/

  /* Graph Aufzeichnen */
  while (Messung_Ein_Analog == true)             //Überwachung Messung aktiv
  {    
    switch (Ports_Graphik)                       //Überwachen letztes Menü
    {
      /* Strom Sensor */  
      case 0:
        current = offset_current + sensor219.getCurrent_mA();                                                         //Strom berechnen
        Aktueller_Wert_Analog = ((current - Min_mA_Analog) * Max_Wert_Analog / (Max_mA_Analog - Min_mA_Analog));      //Analog Wert Ausrechnen
        
        /* Analog Filter */
        Filter_Wert_Analog.Filter(Aktueller_Wert_Analog);                                                             //Analoger Wert filtern

        /* Filter ausschalten */
        if (Analog_Filter_Ein == false)         //Überwachung Filter ausgeschalten
        {
          y_Achse_Float = (Aktueller_Wert_Analog / (Max_Wert_Analog / 290.0));          //y Achse mit Kommastellen berechnen
        }

        /* Filter einschalten */
        if (Analog_Filter_Ein == true)          //Überwachung Filter eingeschalten
        {
          y_Achse_Float = (Filter_Wert_Analog.Current() / (Max_Wert_Analog / 290.0));   //y Achse mit Kommastellen berechnen
        }     
        break;

      /* Akkuladestand */    
      case 1:
        /* Analog Filter */
        Filter_Wert_Analog.Filter(analogRead(AD_Akkuladestand));                        //Analoger Wert filtern
      
        /* Filter ausschalten */
        if (Analog_Filter_Ein == false)       //Überwachung Filter ausgeschalten
        {
          y_Achse_Float = (analogRead(AD_Akkuladestand) / (1023 / 290));                //y Achse mit Kommastellen berechnen
        }

        /* Filter einschalten */
        if (Analog_Filter_Ein == true)        //Überwachung Filter eingeschalten
        {
          y_Achse_Float = (Filter_Wert_Analog.Current() / (1023 / 290));                //y Achse mit Kommastellen berechnen
        }  
        break;
    
      /* Magnetfeldsensor */
      case 2:
        /* Analog Filter */
        Filter_Wert_Analog.Filter(analogRead(AD_Magnetfeldsensor));                     //Analoger Wert filtern
        
        /* Filter ausschalten */
        if (Analog_Filter_Ein == false)       //Überwachung Filter ausgeschalten
        {
          y_Achse_Float = (analogRead(AD_Magnetfeldsensor) / (1023 / 290));            //y Achse mit Kommastellen berechnen
        }

        /* Filter einschalten */
        if(Analog_Filter_Ein == true)         //Überwachung Filter eingeschalten
        {
          y_Achse_Float = (Filter_Wert_Analog.Current() / (1023 / 290));              //y Achse mit Kommastellen berechnen
        }       
        break;
    
      /* AD_Adapter_Typ */
      case 3:    
        /* Analog Filter */
        Filter_Wert_Analog.Filter(analogRead(AD_Adapter_Typ));                //Analoger Wert filtern
      
        /* Filter ausschalten */
        if (Analog_Filter_Ein == false)         //Überwachung Filter ausgeschalten
        {
          y_Achse_Float = (analogRead(AD_Adapter_Typ) / (1023 / 290));        //y Achse mit Kommastellen berechnen
        }

        /* Filter einschalten */
        if(Analog_Filter_Ein == true)           //Überwachung Filter eingeschalten
        {
          y_Achse_Float = (Filter_Wert_Analog.Current() / (1023 / 290));      //y Achse mit Kommastellen berechnen
        } 
        break;
      
      /* Buzzer */
      case 4: 
        y_Achse_Float = (digitalRead(DA_Buzzer) * 290);               //y Achse berechnen    
        break;
    
      /* Hauptschalter LED */  
      case 5:
        y_Achse_Float = (digitalRead(DA_Hauptschalter_LED) * 290);    //y Achse berechnen     
        break;
      
      /* Display Reset */    
      case 6:
        y_Achse_Float = (digitalRead(DA_Display_Reset) * 290);        //y Achse berechnen
        break;
    
      /* Versorgung 24VDC */
      case 7:
        y_Achse_Float = (digitalRead(DA_Versorgung_24VDC) * 290);     //y Achse berechnen
        break;
      
      /* Hallsensor */
      case 8:
        y_Achse_Float = (digitalRead(DE_Hallsensor) * 290);           //y Achse berechnen
        break;
      
      /* Sensor 1 */
      case 9:
        y_Achse_Float = (digitalRead(DE_Sensor_1) * 290);             //y Achse berechnen     
        break;
      
      /* Sensor 2 */    
      case 10:
        y_Achse_Float = (digitalRead(DE_Sensor_2) * 290);             //y Achse berechnen
        break;   
    }
    
    int y = (390 - round(y_Achse_Float));                           //y Achse Drucksensor Wert in Pixel
    unsigned long Aktuelle_Zeit_Graphik = millis();                 //Zeit seit start Arduino

    long Zeit_Verzeogerung = (Graphik_Zeit / 550);                  //x Achse Zeit Verzögerung
           
    if (Graph_Messung_Start == false)                            //Graphik Messung noch nicht begonnen
    {
      x = 101;                                                  //x Achse start Position
      Display.gfx_MoveTo(101, y);                               //Text Position (x,y)
      Display.gfx_Set(OBJECT_COLOUR, YELLOW);                   //Objektfarbe

      Graph_Messung_Start = true;                               //Graphik Messuung Start setzen
    }

    if (Graphik_Stopp == true)
    {
      Display.gfx_MoveTo(x, y);                                 //Text Position (x,y)
      Display.gfx_Set(OBJECT_COLOUR, YELLOW);                   //Objektfarbe

      Graphik_Stopp = false;                                    //Graphik Messung Stopp zurücksetzen
    }
      
    if ((Aktuelle_Zeit_Graphik - Vorherige_Zeit_Graphik) >= Zeit_Verzeogerung)   //Aktuelle Zeit zu Vorheringen Zeit kleiner als Zeitverzögerung
    {  
      Display.gfx_LineTo(x, y);                                         //Graphik Zeichnen        
      
      x++;
      Vorherige_Zeit_Graphik = Aktuelle_Zeit_Graphik;                   //Zeit seit Start an Vorherige Zeit anpassen

      switch(Ports_Graphik)                    //Überwachen letztes Menü
      {
        /* Strom Sensor */  
        case 0:
          Analogwert[Messungen_Analog] = Aktueller_Wert_Analog;                 //Aktueller Wert Analog speichern in Liste 
          break;
      
        /* Akkuladestand */    
        case 1:
          Analogwert[Messungen_Analog] = ((analogRead(AD_Akkuladestand) * 5) / 1023);          //Aktueller Wert Analog speichern in Liste
          break;
      
        /* Magnetfeldsensor */
        case 2:
          Analogwert[Messungen_Analog] = ((analogRead(AD_Magnetfeldsensor) / 1023.0) * 5.0);       //Aktueller Wert Analog speichern in Liste 
          break;
      
        /* AD_Adapter_Typ */
        case 3: 
          Analogwert[Messungen_Analog] = ((analogRead(AD_Adapter_Typ) / 1023) * 5.00);            //Aktueller Wert Analog speichern in Liste   
          break;
      
        /* Buzzer */
        case 4: 
          Analogwert[Messungen_Analog] = digitalRead(DA_Buzzer);                //Aktueller Wert speichern in Liste   
          break;
      
        /* Hauptschalter LED */  
        case 5:
          Analogwert[Messungen_Analog] = digitalRead(DA_Hauptschalter_LED);     //Aktueller Wert speichern in Liste     
          break;
      
        /* Display Reset */    
        case 6:
          Analogwert[Messungen_Analog] = digitalRead(DA_Display_Reset);         //Aktueller Wert speichern in Liste 
          break;
      
        /* Versorgung 24VDC */
        case 7:
          Analogwert[Messungen_Analog] = digitalRead(DA_Versorgung_24VDC);      //Aktueller Wert speichern in Liste 
          break;
      
        /* Hallsensor */
        case 8:
          Analogwert[Messungen_Analog] = digitalRead(DE_Hallsensor);              //Aktueller Wert speichern in Liste 
          break;
        
        /* Sensor 1 */        
        case 9:
          Analogwert[Messungen_Analog] = digitalRead(DE_Sensor_1);                //Aktueller Wert speichern in Liste     
          break;

        /* Sensor 2 */    
        case 10:
          Analogwert[Messungen_Analog] = digitalRead(DE_Sensor_2);                //Aktueller Wert speichern in Liste 
          break;   
      }

      Zeit_Messung[Messungen_Zeit_Analog] = (Zeit_Verzeogerung * Messungen_Zeit_Analog) / 1000.0;    //Zeit Messung der Liste hinzufügen
      
      Messungen_Analog++;                                               //Messungs Anzahl hochzählen
      Messungen_Zeit_Analog++;                                          //Messungen Zeit Analog hochzählen
      Anzahl_Messungen++;                                               //Messungen hochzählen
      
      if (Anzahl_Messungen > 10000)
      {
        Anzahl_Messungen_Merker = true;                                 //Anzahl Messungen Merker setzen
        Anzahl_Messungen = 0;                                           //Messungen zurücksetzen
        Messungen_Analog = 0;                                           //Messungs Anzahl zurücksetzen
      }
      
      if (Messungen_Zeit_Analog > 10000)
      {
        Messungen_Zeit_Analog = 0;                                      //Messungen zurücksetzen
      }
    }

    if ((Endlos_Ein == true) && (x >= 650))                             //Endlos Button Ein und Graphik fertig
    {
      Display.gfx_RectangleFilled(101, 389, 650, 100, BLACK);           //Graphlinien übermalen
      Display.gfx_MoveTo(101, y);                                       //Text Position (x,y)
      Display.gfx_Set(OBJECT_COLOUR, YELLOW);                           //Objektfarbe       
      x = 101;                                                          //x Achse zurücksetzen
    }

/********************************************************************************************************************/

  /* Touch Screen handling */   
  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen

  /* Touch Positionen auslesen */
  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))    //Überwachung Touch gedrückt oder bewegt
  {
    X_Pos_Touch = Display.touch_Get(TOUCH_GETX);     //X Position auslesen
    Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);     //Y Position auslesen
  }

  /* Touch Freigabe */
  if (((Endlos_Ein == false) && (x >= 650)) || (Status_Display == TOUCH_RELEASED))      //Überwachung Touch Freigabe
  {

/********************************************************************************************************************/    

    /* Touch Feld abfragen [Stopp] Taste gedrückt (Doppel Taste Start/Stopp)
       Es wird die Start Taste angezeigt! */
    if (((Endlos_Ein == false) && (x >= 650)) || (((Messung_Ein_Analog == true) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))))   //Überwachung Touch Feld
    {          
      /* Touch Feld [Stopp] Taste ausführen */
      if ((((Endlos_Ein == false) && (x >= 650))) || (Status_Touch_Taste))
      { 
        Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Start");                                //Taste anzeigen gedrückt
          
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");     //Taste anzeigen ungedrückt
        Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
        Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                                 //Taste anzeigen ungedrückt 
        Display.gfx_Button(Status_Touch_Taste, 200, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Graphik");                               //Taste anzeigen ungedrückt
     
        /* Messung Aus */      
        Messung_Ein_Analog = false;           //Messung Ein Analogeanzeige zurücksetzen 
        Graphik_Stopp = true;                 //Graphik Stopp setzen
                    
        /* Buzzer */
        Buzzer(500);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)             
      }
    }
        
/********************************************************************************************************************/

  }   //Touch Freigabe Ende

/********************************************************************************************************************/
      
  }   //Messung aktiv Ende
    
/********************************************************************************************************************/
  
  Statusanzeige();              //Aufruf Funktion Statusanzeige
  
/********************************************************************************************************************/

  /* Doppeltaste Goto */
  Doppeltaste_Betaetigt:                     //Doppeltaste Goto
  
  /* Touch Screen handling */   
  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen

  /* Touch Positionen auslesen */
  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))    //Überwachung Touch gedrückt oder bewegt
  {
    X_Pos_Touch = Display.touch_Get(TOUCH_GETX);     //X Position auslesen
    Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);     //Y Position auslesen
  }
  
  /* Touch Freigabe */
  if (Status_Display == TOUCH_RELEASED)      //Überwachung Touch Freigabe
  {

/********************************************************************************************************************/    

    /* Touch Feld abfragen [Zrug] Taste gedrückt */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrug] Taste ausführen */
       if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");   //Taste anzeigen gedrückt

        Graph_Raster = false;                         //Graphik Raster zurücksetzen
        Messung_Ein_Analog = false;                   //Messung Ein Analogeanzeige zurücksetzen
        Graph_Messung_Start = false;                  //Graphik Messung Start zurücksetzen
        Graphik_Stopp = false;                        //Graphik Stopp zurücksetzen 
        Graphik_Freigabe = false;                     //Graphik Freigabe zurücksetzen 
        Analog_Filter_Ein = false;                    //Analog Filter Ein zurücksetzen
        
        /* Buzzer */
        Buzzer(100);                                  //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 0;                         //Hauptmenü anwählen
        Bild_aufgebaut[0] = false;                    //Bildschirm aufgebaut zurücksetzen
        Bild_aufgebaut[18] = false;                   //Bildschirm aufgebaut zurücksetzen 
        
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
        Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET");                   //Taste anzeigen gedrückt
                            
        /* Messwerte zurücksetzen */
        for (int i = 0; i <= 10000; i++)
        {            
          Analogwert[i] = 0;            //Messwerte zurücksetzen
        } 

        Messungen_Analog = 0;               //Anzahl Messungen zurücksetzen
        
        Graph_Raster = false;               //Graphik Raster zurücksetzen
        Messung_Ein_Analog = false;         //Messung Ein Analogeanzeige zurücksetzen  
        Graph_Messung_Start = false;        //Graphik Messung Start zurücksetzen
        Graphik_Stopp = false;              //Graphik Stopp zurücksetzen
        Analog_Filter_Ein = false;          //Analog Filter Ein zurücksetzen

        /* Buzzer */
        Buzzer(100);                        //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 18;              //Menü Analogeanzeige anwählen       
        Bild_aufgebaut[18] = false;         //Bildschirm aufgebaut zurücksetzen
      }
    }
    
/********************************************************************************************************************/ 

    /* Touch Feld abfragen [Export] Taste gedrückt */
    if ((X_Pos_Touch >= 20) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {    
      /* Touch Feld [Export] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Export");                  //Taste anzeigen gedrückt 

        /* Buzzer */
        Buzzer(100);                                  //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        if (Anzahl_Messungen_Merker == true)
        {
          Anzahl_Messungen = 10000;                   //Anzahl Messungen auf Max setzen
        }

        /* Graphik Messungen auf SD Karte schreiben */
        SD.remove("Graphik/Messung.txt");                                 //File löschen
        File Messung = SD.open("Graphik/Messung.txt", FILE_WRITE);        //File in Ordner im Schreibmodus auf SD Karte öffnen      
        
        if (Messung) 
        {
          SerialUSB.println("Messungen");
          SerialUSB.println("");
          Messung.println("Messungen;Zeit;Einheit");

          Anzahl_Messungen--;                                               //Messungen runter zählen
          Messungen_Zeit_Analog = 0;                                        //Messungen Zeit Analog zurücksetzen
      
          for (Messungen_Analog = 0; Messungen_Analog <= Anzahl_Messungen; Messungen_Analog++)
          {  
            SerialUSB.println(Analogwert[Messungen_Analog]);                //Ausgabe Aktueller Messwert auf USB Schnittstelle
            Messung.print(Analogwert[Messungen_Analog]);                    //Analogwert auf SD Karte schreiben
            Messung.print(";");                                             //Semikolon auf SD Karte schreiben
            Messung.print(Zeit_Messung[Messungen_Zeit_Analog]);             //Zeit Messung auf SD Karte schreiben
            Messungen_Zeit_Analog++;                                        //Messung Zeit Analog hochzählen
            
            if (Einheit_Analog <= 9)
            {
              Messung.println(";1");                                    //Einheit bar auf SD Karte schreiben
            }

            if ((Einheit_Analog >= 10) && (Einheit_Analog <= 19))
            {
              Messung.println(";2");                                    //Einheit Nl/min auf SD Karte schreiben
            }

            if ((Einheit_Analog >= 20) && (Einheit_Analog <= 29))
            {
              Messung.println(";3");                                    //Einheit °C auf SD Karte schreiben
            }
    
            if ((Einheit_Analog >= 30) && (Einheit_Analog <= 39))
            {
              Messung.println(";4");                                    //Einheit V auf SD Karte schreiben
            }
          }
          Messung.close();                                              //File schliessen
        } 

        Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                   //Taste anzeigen ungedrückt                                         
      }
    }
    
/********************************************************************************************************************/

      /* Touch Feld abfragen [Analog] Taste gedrückt
         Es wird die Graphik Taste angezeigt! */
      if ((X_Pos_Touch >= 170) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {          
        /* Touch Feld [Analog] Taste ausführen */
        if (Status_Touch_Taste)
        { 
          Display.gfx_Button(Status_Touch_Taste, 200, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Analog");                  //Taste anzeigen gedrückt

          Graph_Raster = false;             //Graphik Raster zurücksetzen
          Messung_Ein_Analog = false;       //Messung Ein Analogeanzeige zurücksetzen  
          Graph_Messung_Start = false;      //Graphik Messung Start zurücksetzen
          Graphik_Freigabe = false;         //Graphik Freigabe zurücksetzen
          Graph_Raster = false;             //Graphik Raster gezeichnet zurücksetzen
          Graphik_Stopp = false;            //Graphik Stopp zurücksetzen 
          Analog_Filter_Ein = false;        //Analog Filter Ein zurücksetzen 

          /* Buzzer */
          Buzzer(100);                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          Menue_angewaehlt = 3;             //Menü Graphik anwählen
          Bild_aufgebaut[3] = false;        //Überwachung Bildschirm aufgebaut                
        }
      }
        
/********************************************************************************************************************/

     /* Touch Feld abfragen [Endlos] Taste gedrückt (Doppel Taste Endlos)
         Es wird die Endlos Taste angezeigt! */
      if ((Endlos_Ein == false) && (X_Pos_Touch >= 670) && (X_Pos_Touch <= 800) && (Y_Pos_Touch >= 40) && (Y_Pos_Touch <= 100))   //Überwachung Touch Feld
      {     
        
        /* Touch Feld [Endlos] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 700, 70, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Endlos");                  //Taste anzeigen gedrückt 

          /* Endlos Ein */
          Endlos_Ein = true;         //Endlos Funktion setzen

          /* Buzzer */
          Buzzer(100);                //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          /* Doppeltaste Auschaltverhinderung bis erneut gedrückt */
          goto Doppeltaste_Betaetigt;       //Doppeltaste betätigt
        }
      }
    
/********************************************************************************************************************/

      /* Touch Feld abfragen [Endlos] Taste gedrückt (Doppel Taste Endlos)
         Es wird die Endlos Taste angezeigt! */
      if ((Endlos_Ein == true) && (X_Pos_Touch >= 670) && (X_Pos_Touch <= 800) && (Y_Pos_Touch >= 40) && (Y_Pos_Touch <= 100))   //Überwachung Touch Feld
      {    
        /* Touch Feld [Endlos] Taste ausführen */
        if (Status_Touch_Taste)
        { 
          Display.gfx_Button(Status_Touch_Taste, 700, 70, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Endlos");                  //Taste anzeigen gedrückt
      
          /* Endlos Aus */      
          Endlos_Ein = false;          //Messung Ein Analogeanzeige zurücksetzen 

          /* Buzzer */
          Buzzer(500);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          /* Doppeltaste Auschaltverhinderung bis erneut gedrückt */
          goto Doppeltaste_Betaetigt;       //Doppeltaste betätigt     
        }
      }
        
/********************************************************************************************************************/


      /* Touch Feld abfragen [Filter] Taste gedrückt (Doppel Taste Filter)
         Es wird die Stopp Taste angezeigt! */
      if ((Analog_Filter_Ein == false) && (X_Pos_Touch >= 670) && (X_Pos_Touch <= 800) && (Y_Pos_Touch >= 90) && (Y_Pos_Touch <= 150))   //Überwachung Touch Feld
      {     
        /* Touch Feld [Filter] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 700, 120, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Filter");                  //Taste anzeigen gedrückt 

          /* Analog Filter Ein */
          Analog_Filter_Ein = true;                   //Buzzer Ein setzen
          
          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          /* Doppeltaste Auschaltverhinderung bis erneut gedrückt */
          goto Doppeltaste_Betaetigt;       //Doppeltaste betätigt
        }
      }
    
/********************************************************************************************************************/

      /* Touch Feld abfragen [Filter] Taste gedrückt (Doppel Taste Filter)
         Es wird die Start Taste angezeigt! */
      if ((Analog_Filter_Ein == true) && (X_Pos_Touch >= 670) && (X_Pos_Touch <= 800) && (Y_Pos_Touch >= 90) && (Y_Pos_Touch <= 150))   //Überwachung Touch Feld
      {   
        /* Touch Feld Filter] Taste ausführen */
        if (Status_Touch_Taste)
        { 
          Display.gfx_Button(Status_Touch_Taste, 700, 120, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Filter");                                //Taste anzeigen gedrückt
               
          /* Analog Filter Ein */
          Analog_Filter_Ein = false;                 //Analog Filter Ein zurücksetzen

          /* Buzzer */
          Buzzer(500);                        //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

          /* Doppeltaste Auschaltverhinderung bis erneut gedrückt */
          goto Doppeltaste_Betaetigt;       //Doppeltaste betätigt       
        }
      }
        
/********************************************************************************************************************/

     /* Touch Feld abfragen [Start] Taste gedrückt (Doppel Taste Start/Stopp)
         Es wird die Stopp Taste angezeigt! */
      if ((Graph_Raster == true) && (Messung_Ein_Analog == false) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {     
        /* Touch Feld [Start] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 500, 420, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Stopp");                  //Taste anzeigen gedrückt 

          Display.gfx_Button(Status_Touch_Taste, 650, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Zrug");                  //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 350, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                 //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 50, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Export");                 //Taste anzeigen nicht drückbar 
          Display.gfx_Button(Status_Touch_Taste, 200, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Graphik");               //Taste anzeigen nicht drückbar

          /* Messung Ein */
          Messung_Ein_Analog = true;         //Messung Ein Analogeanzeige setzen
          Messungen_Analog = 0;              //Messungs Anzahl zurücksetzen
          Messungen_Zeit_Analog = 0;                                      //Messungen Zeit Analog zurücksetzen

          for (Messungen_Analog = 0; Messungen_Analog <= 10000; Messungen_Analog++)
          {
             Analogwert[Messungen_Analog] = 0;                            //Aktueller Wert Analog zurücksetzen   
          }
          
          for (Messungen_Zeit_Analog = 0; Messungen_Zeit_Analog <= 10000; Messungen_Zeit_Analog++)
          {
             Zeit_Messung[Messungen_Zeit_Analog] = 0;                            //Zeit Messung zurücksetzen 
          }

          Anzahl_Messungen_Merker = false;                                //Anzahl Messungen Merker zurücksetzen
          Anzahl_Messungen = 0;                                           //Messungen zurücksetzen
          Messungen_Zeit_Analog = 0;                                      //Messungen Zeit Analog zurücksetzen
          Messungen_Analog = 0;                                           //Messungs Anzahl zurücksetzen

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

        Graph_Raster = false;               //Graphik Raster setzen
        Menue_angewaehlt = 7;               //Menü Info anwählen
        Bild_aufgebaut[7] = false;          //Bildschirm Info aufgebaut zurücksetzen
        Letztes_Menue = 18;                 //Letztes angewähltes Menü
        Info_Seite = 16;                    //Info Seite anwählen
      }
    }
      
/********************************************************************************************************************/

    /* Touch Feld abfragen [2s] Taste gedrückt */
    if ((Graphik_Freigabe == false) && (X_Pos_Touch >= 20) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))   //Überwachung Touch Feld
    {
      /* Touch Feld [2s] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 50, 150, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "2s");   //Taste anzeigen gedrückt

        Graphik_Zeit = 2000;
        Graphik_Text_Anzeige = 2;
        Einheit_Abfrage = false;            //Graphik Einheit Abfrage true = min false = s
        Graphik_Freigabe = true;

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Bild_aufgebaut[18] = false;                //Bildschirm aufgebaut setzen 
      }
    }
 
/********************************************************************************************************************/

    /* Touch Feld abfragen [5s] Taste gedrückt */
    if ((Graphik_Freigabe == false) && (X_Pos_Touch >= 170) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))   //Überwachung Touch Feld
    {
      /* Touch Feld [5s] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 200, 150, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "5s");   //Taste anzeigen gedrückt

        Graphik_Zeit = 5000;
        Graphik_Text_Anzeige = 5;
        Einheit_Abfrage = false;            //Graphik Einheit Abfrage true = min false = s
        Graphik_Freigabe = true;

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
       
        Bild_aufgebaut[18] = false;                //Bildschirm aufgebaut setzen
      }
    }
 
/********************************************************************************************************************/

    /* Touch Feld abfragen [10s] Taste gedrückt */
    if ((Graphik_Freigabe == false) && (X_Pos_Touch >= 330) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))   //Überwachung Touch Feld
    {
      /* Touch Feld [10s] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 350, 150, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "10s");   //Taste anzeigen gedrückt

        Graphik_Zeit = 10000;
        Graphik_Text_Anzeige = 10;
        Einheit_Abfrage = false;            //Graphik Einheit Abfrage true = min false = s
        Graphik_Freigabe = true;

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Bild_aufgebaut[18] = false;                //Bildschirm aufgebaut setzen
      }
    }
 
/********************************************************************************************************************/

    /* Touch Feld abfragen [30s] Taste gedrückt */
    if ((Graphik_Freigabe == false) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 600) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))   //Überwachung Touch Feld
    {
      /* Touch Feld [30s] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 500, 150, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "30s");   //Taste anzeigen gedrückt

        Graphik_Zeit = 30000;
        Graphik_Text_Anzeige = 30;
        Einheit_Abfrage = false;            //Graphik Einheit Abfrage true = min false = s
        Graphik_Freigabe = true;

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Bild_aufgebaut[18] = false;                //Bildschirm aufgebaut setzen
      }
    }
 
/********************************************************************************************************************/

    /* Touch Feld abfragen [60s] Taste gedrückt */
    if ((Graphik_Freigabe == false) && (X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 120) && (Y_Pos_Touch <= 180))   //Überwachung Touch Feld
    {
      /* Touch Feld [60s] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 150, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "60s");   //Taste anzeigen gedrückt

        Graphik_Zeit = 60000;
        Graphik_Text_Anzeige = 60;
        Einheit_Abfrage = false;            //Graphik Einheit Abfrage true = min false = s
        Graphik_Freigabe = true;

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Bild_aufgebaut[18] = false;                //Bildschirm aufgebaut setzen
      }
    }
 
/********************************************************************************************************************/

    /* Touch Feld abfragen [2min] Taste gedrückt */
    if ((Graphik_Freigabe == false) && (X_Pos_Touch >= 20) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 170) && (Y_Pos_Touch <= 230))   //Überwachung Touch Feld
    {
      /* Touch Feld [2min] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 50, 200, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "2min");   //Taste anzeigen gedrückt

        Graphik_Zeit = 120000;
        Graphik_Text_Anzeige = 2;
        Einheit_Abfrage = true;             //Graphik Einheit Abfrage true = min false = s
        Graphik_Freigabe = true;

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Bild_aufgebaut[18] = false;                //Bildschirm aufgebaut setzen
      }
    }
 
/********************************************************************************************************************/

    /* Touch Feld abfragen [5min] Taste gedrückt */
    if ((Graphik_Freigabe == false) && (X_Pos_Touch >= 170) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 170) && (Y_Pos_Touch <= 230))   //Überwachung Touch Feld
    {
      /* Touch Feld [5min] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 200, 200, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "5min");   //Taste anzeigen gedrückt

        Graphik_Zeit = 300000;
        Graphik_Text_Anzeige = 5;
        Einheit_Abfrage = true;             //Graphik Einheit Abfrage true = min false = s
        Graphik_Freigabe = true;

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Bild_aufgebaut[18] = false;                //Bildschirm aufgebaut setzen
      }
    }
 
/********************************************************************************************************************/

    /* Touch Feld abfragen [10min] Taste gedrückt */
    if ((Graphik_Freigabe == false) && (X_Pos_Touch >= 320) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 170) && (Y_Pos_Touch <= 230))   //Überwachung Touch Feld
    {
      /* Touch Feld [10min] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 350, 200, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "10min");   //Taste anzeigen gedrückt

        Graphik_Zeit = 600000;
        Graphik_Text_Anzeige = 10;
        Einheit_Abfrage = true;             //Graphik Einheit Abfrage true = min false = s
        Graphik_Freigabe = true;

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Bild_aufgebaut[18] = false;                //Bildschirm aufgebaut setzen
      }
    }
 
/********************************************************************************************************************/

    /* Touch Feld abfragen [30min] Taste gedrückt */
    if ((Graphik_Freigabe == false) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 600) && (Y_Pos_Touch >= 170) && (Y_Pos_Touch <= 230))   //Überwachung Touch Feld
    {
      /* Touch Feld [30min] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 500, 200, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "30min");   //Taste anzeigen gedrückt

        Graphik_Zeit = 1800000;
        Graphik_Text_Anzeige = 30;
        Einheit_Abfrage = true;             //Graphik Einheit Abfrage true = min false = s
        Graphik_Freigabe = true;

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Bild_aufgebaut[18] = false;                //Bildschirm aufgebaut setzen
      }
    }
 
/********************************************************************************************************************/

    /* Touch Feld abfragen [60min] Taste gedrückt */
    if ((Graphik_Freigabe == false) && (X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 170) && (Y_Pos_Touch <= 230))   //Überwachung Touch Feld
    {
      /* Touch Feld [60min] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 200, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "60min");   //Taste anzeigen gedrückt

        Graphik_Zeit = 3600000;
        Graphik_Text_Anzeige = 60;
        Einheit_Abfrage = true;             //Graphik Einheit Abfrage true = min false = s
        Graphik_Freigabe = true;
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Bild_aufgebaut[18] = false;                //Bildschirm aufgebaut setzen
      }
    }
 
/********************************************************************************************************************/

    /* Touch Feld abfragen [ < Ports ] Taste gedrückt ( < Ports) */
    if ((Graphik_Freigabe == false) && (X_Pos_Touch >= 40) && (X_Pos_Touch <= 120) && (Y_Pos_Touch >= 280) && (Y_Pos_Touch <= 360))     //Überwachung Touch Feld
    {
      /* Touch Feld [ < Ports ] Taste ausführen ( < Ports) */
      if (Status_Touch_Taste)
      {
        Display.gfx_Triangle(100, 300, 100, 340, 60, 320, BLACK);           //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)

        Ports_Graphik--; 
        
        if (Ports_Graphik < 0) Ports_Graphik = 10;     //Verstellwert begrenzen

        SerialUSB.println(Ports_Graphik);
 
        switch(Ports_Graphik)                    //Überwachen letztes Menü
        {
          /* Strom Sensor */
          case 0:
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Strom Sensor     ");      //Taste anzeigen ungedrückt         
            break;

          /* Akkuladestand */
          case 1:
            Einheit_Analog = 30;              //Einheit Analog vorgeben
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Akkuladestand    ");      //Taste anzeigen ungedrückt
            break;

          /* Magnetfeldsensor */
          case 2:
            Einheit_Analog = 30;              //Einheit Analog vorgeben
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Magnetfeldsensor ");      //Taste anzeigen ungedrückt
            break;

          /* Adapter Typ */
          case 3:
          Einheit_Analog = 30;              //Einheit Analog vorgeben
          Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Adapter Typ   ");      //Taste anzeigen ungedrückt
          break;

          /* Buzzer */
          case 4:         
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Buzzer           ");      //Taste anzeigen ungedrückt
            break;

          /* Hauptschalter LED */
          case 5:        
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Hauptschalter LED");      //Taste anzeigen ungedrückt      
            break;

          /* Display Reset */
          case 6:
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Display Reset    ");      //Taste anzeigen ungedrückt
            break;

          /* Versorgung 24VDC */
          case 7:          
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Versorgung 24VDC ");      //Taste anzeigen ungedrückt
            break;

          /* Hallsensor */
          case 8:         
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Hallsensor       ");      //Taste anzeigen ungedrückt
            break;

          /* Sesnsor 1 */
          case 9:        
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Sensor 1         ");      //Taste anzeigen ungedrückt        
            break;

          /* Sesnor 2 */
          case 10:         
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Sensor 2        ");      //Taste anzeigen ungedrückt
            break;   
        }
          
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Triangle(100, 300, 100, 340, 60, 320, WHITE);           //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)  
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [ > Ports ] Taste gedrückt ( > Ports) */
    if ((Graphik_Freigabe == false) && (X_Pos_Touch >= 365) && (X_Pos_Touch <= 445) && (Y_Pos_Touch >= 280) && (Y_Pos_Touch <= 360))     //Überwachung Touch Feld
    {
      /* Touch Feld [ > Ports ] Taste ausführen ( > Ports) */
      if (Status_Touch_Taste)
      {
        Display.gfx_Triangle(385, 300, 385, 340, 425, 320, BLACK);           //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
        
        Ports_Graphik++; 
        if (Ports_Graphik > 10) Ports_Graphik = 0;     //Verstellwert begrenzen

        SerialUSB.println(Ports_Graphik);
 
        switch(Ports_Graphik)                    //Überwachen letztes Menü
        {
          /* Strom Sesnor */
          case 0:
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Strom Sensor     ");      //Taste anzeigen ungedrückt          
            break;

          /* Akkuladestand */
          case 1:
            Einheit_Analog = 30;              //Einheit Analog vorgeben
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Akkuladestand    ");      //Taste anzeigen ungedrückt
            break;

          /* Magnetfeldsensor */
          case 2:
            Einheit_Analog = 30;              //Einheit Analog vorgeben
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Magnetfeldsensor ");      //Taste anzeigen ungedrückt
            break;

          /* Adapter Typ */
          case 3:
            Einheit_Analog = 30;              //Einheit Analog vorgeben
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Adapter Typ   ");      //Taste anzeigen ungedrückt
            break;

          /* Buzzer */
          case 4:      
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Buzzer           ");      //Taste anzeigen ungedrückt
            break;

          /* Haupschalter LED */
          case 5:       
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Hauptschalter LED");      //Taste anzeigen ungedrückt           
            break;

          /* Display Reset */
          case 6:        
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Display Reset    ");      //Taste anzeigen ungedrückt
            break;

          /* Versorgung 24VDC */
          case 7:        
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Versorgung 24VDC ");      //Taste anzeigen ungedrückt
            break;

          /* Hallsensor */
          case 8:     
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Hallsensor       ");      //Taste anzeigen ungedrückt
            break;

          /* Sensor 1 */
          case 9:     
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Sensor 1         ");      //Taste anzeigen ungedrückt           
            break;

          /* Sensor 2 */
          case 10:        
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Sensor 2        ");      //Taste anzeigen ungedrückt
            break;   
        }
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

        Display.gfx_Triangle(385, 300, 385, 340, 425, 320, WHITE);           //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
      }
    }

/********************************************************************************************************************/

  }     //Touch Freigabe Ende
  
/********************************************************************************************************************/
  
}
