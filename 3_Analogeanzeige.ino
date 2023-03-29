/* 3.Analogeanzeige */

void Analogeanzeige(bool Bildaufbau, bool Werte_Reset)         //Funktion Analogeanzeige
{

/********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[3] == false)           //Überwachung Bildschirm aufgebaut
  {
    Display.gfx_Cls();                      //Display löschen
    Statusanzeige();                        //Aufruf Funktion Statusanzeige

    Messung_Ein_Analog = false;             //Messung Ein Analogeanzeige zurücksetzen
      
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Analogeanzeige");   //Funktion Namen anzeigen
    
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");     //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                                 //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Start");                                //Taste anzeigen ungedrückt 
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                     //Taste anzeigen gedrückt
    Display.gfx_Button(Status_Touch_Taste, 200, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Graphik");                               //Taste anzeigen ungedrückt
    if (Einheit_Analog == 10) Display.gfx_Button(Status_Touch_Taste, 50, 360, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Berechnung");   //Taste anzeigen ungedrückt
    if (Einheit_Analog != 10) Display.gfx_Button(Status_Touch_Taste, 50, 360, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Berechnung");   //Taste anzeigen nicht drückbar
    Display.gfx_Button(Status_Touch_Taste, 50, 300, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Set 0");                                  //Taste anzeigen ungedrückt 
   
    /* Grafik zu Tasten anzeigen */    
    Display.gfx_Triangle(200, 130, 180, 150, 220, 150, WHITE);      //Dreieck Seite hoch zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_Triangle(200, 220, 180, 200, 220, 200, WHITE);      //Dreieck Seite runter zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_Circle(767, 30, 22, WHITE);                         //Info Kreis zeichnen (Kreis x,y,r)
    
    /* Text anzeigen */
    Display.txt_Height(3);                        //Texthöhe
    Display.txt_Width(3);                         //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe
    Display.txt_Inverse(OFF);                     //Text invetieren
    Display.txt_Bold(OFF);                        //Text fett
    
    Display.gfx_MoveTo(260, 100);                 //Text Position (x,y)
    Display.print("Spannung: 0.00 V    ");        //Text anzeigen
    Display.gfx_MoveTo(260, 150);                 //Text Position (x,y)
    Display.print("Strom   : 0.00 mA    ");       //Text anzeigen
    Display.gfx_MoveTo(260, 200);                 //Text Position (x,y)
    Display.print("Leistung: 0.00 W    ");        //Text anzeigen

//    Display.gfx_MoveTo(260, 300);               //Text Position (x,y)
//    Display.print("?????   : ");
//    Display.print("0.00");                      //Text anzeigen
//    Display.print(" ???  ");

    digitalWrite(DA_Versorgung_24VDC, HIGH);      //Digital Ausgang Versorgung 24VDC setzen
    delay(1000);                                  //Verzögerung 1000ms   
      
    current = 0;
    //offset_current = 0;
    
    /* Grundeinstellung */   
    Max_mA_Analog = 20;         //Maximum Strom Grenzwert 20mA
    Min_mA_Analog = 4;          //Minimum Strom Grenzwert 4mA   
        
    Zeitraster_Messung = 1;     //100ms

    /* Buzzer */
    Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

    Bild_aufgebaut[3] = true;             //Bildschirm aufgebaut setzen         
  }

/********************************************************************************************************************/

  /* Anzeige Mess Auswahl Liste */
  if (Mess_Auswahl_Liste_aufgebaut == false)      //Überwachung Mess Auswahl Liste angewählt
  {
    /* Mess Auswahl Liste */
    switch (Mess_Auswahl_Liste)
    {
      
/********************************************************************************************************************/
     
    /* 0.Druck Liste 1 */
    case 0:   
      Display.gfx_RectangleFilled(0, 80, 180, 270, BLACK);           //Graphik Linien übermalen
      if (Einheit_Analog != 1) Display.gfx_Button(Status_Touch_Taste, 0, 85, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "10 bar");          //Taste anzeigen ungedrückt
      if (Einheit_Analog == 1) Display.gfx_Button(Status_Touch_Taste, 0, 85, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "10 bar");         //Taste anzeigen angewählt

      if (Einheit_Analog != 2) Display.gfx_Button(Status_Touch_Taste, 0, 135, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "20 bar");         //Taste anzeigen ungedrückt 
      if (Einheit_Analog == 2) Display.gfx_Button(Status_Touch_Taste, 0, 135, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "20 bar");        //Taste anzeigen angewählt

      if (Einheit_Analog != 3) Display.gfx_Button(Status_Touch_Taste, 0, 185, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "40 bar");         //Taste anzeigen ungedrückt 
      if (Einheit_Analog == 3) Display.gfx_Button(Status_Touch_Taste, 0, 185, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "40 bar");        //Taste anzeigen angewählt 

      if (Einheit_Analog != 4) Display.gfx_Button(Status_Touch_Taste, 0, 235, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "50 bar");         //Taste anzeigen ungedrückt
      if (Einheit_Analog == 4) Display.gfx_Button(Status_Touch_Taste, 0, 235, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "50 bar");        //Taste anzeigen angewählt 
 
      Mess_Auswahl_Liste_aufgebaut = true;      //Mess Auswahl Liste aufgebaut setzen

      Druck_Liste_1_anzeigen = true;            //Druck List 1 anzeigen setzen

      Druck_Liste_2_anzeigen = false;           //Druck List 1 anzeigen zurücksetzen              
      Durchfluss_Liste_1_anzeigen = false;      //Durchfluss Liste 1 anzeigen zurücksetzen
      Temperatur_Liste_1_anzeigen = false;      //Temperatur Liste 1 anzeigen zurücksetzen      
      break;

/********************************************************************************************************************/

    /* 1.Druck Liste 2 */
    case 1:   
      Display.gfx_RectangleFilled(0, 80, 180, 270, BLACK);           //Graphik Linien übermalen     
      if (Einheit_Analog != 5) Display.gfx_Button(Status_Touch_Taste, 0, 85, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "100 bar");         //Taste anzeigen ungedrückt
      if (Einheit_Analog == 5) Display.gfx_Button(Status_Touch_Taste, 0, 85, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "100 bar");        //Taste anzeigen angewählt 

      Mess_Auswahl_Liste_aufgebaut = true;      //Mess Auswahl Liste aufgebaut setzen

      Druck_Liste_2_anzeigen = true;            //Druck List 2 anzeigen setzen

      Druck_Liste_1_anzeigen = false;           //Druck List 1 anzeigen zurücksetzen         
      Durchfluss_Liste_1_anzeigen = false;      //Durchfluss Liste 1 anzeigen zurücksetzen
      Temperatur_Liste_1_anzeigen = false;      //Temperatur Liste 1 anzeigen zurücksetzen      
      break;

/********************************************************************************************************************/

    /* 2.Durchfluss Liste */
    case 2:  
      Display.gfx_RectangleFilled(0, 80, 180, 270, BLACK);           //Graphlinien übermalen 
      if (Einheit_Analog != 10) Display.gfx_Button(Status_Touch_Taste, 0, 85, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "2500 Nl/min");      //Taste anzeigen ungedrückt
      if (Einheit_Analog == 10) Display.gfx_Button(Status_Touch_Taste, 0, 85, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "2500 Nl/min");     //Taste anzeigen angewählt 

      Mess_Auswahl_Liste_aufgebaut = true;      //Mess Auswahl Liste aufgebaut setzen

      Durchfluss_Liste_1_anzeigen = true;       //Durchfluss List 1 anzeigen setzen

      Druck_Liste_1_anzeigen = false;           //Druck List 1 anzeigen zurücksetzen      
      Druck_Liste_2_anzeigen = false;           //Druck Liste 2 anzeigen zurücksetzen
      Temperatur_Liste_1_anzeigen = false;      //Temperatur Liste 1 anzeigen zurücksetzen     
      break;

/********************************************************************************************************************/
     
    /* 3.Temperatur Liste */
    case 3:  
      Display.gfx_RectangleFilled(0, 80, 180, 270, BLACK);           //Graphlinien übermalen
      if (Einheit_Analog != 20) Display.gfx_Button(Status_Touch_Taste, 0, 85, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "100 Grad");       //Taste anzeigen ungedrückt
      if (Einheit_Analog == 20) Display.gfx_Button(Status_Touch_Taste, 0, 85, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "100 Grad");      //Taste anzeigen angewählt
 
      if (Einheit_Analog != 21) Display.gfx_Button(Status_Touch_Taste, 0, 135, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "150 Grad");      //Taste anzeigen ungedrückt 
      if (Einheit_Analog == 21) Display.gfx_Button(Status_Touch_Taste, 0, 135, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "150 Grad");     //Taste anzeigen angewählt 
     
      if (Einheit_Analog != 22) Display.gfx_Button(Status_Touch_Taste, 0, 185, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "350 Grad");      //Taste anzeigen ungedrückt     
      if (Einheit_Analog == 22) Display.gfx_Button(Status_Touch_Taste, 0, 185, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "350 Grad");     //Taste anzeigen angewählt 

      Mess_Auswahl_Liste_aufgebaut = true;      //Mess Auswahl Liste aufgebaut setzen

      Temperatur_Liste_1_anzeigen = true;       //Temperatur Liste 1 anzeigen setzen

      Druck_Liste_1_anzeigen = false;           //Druck List 1 anzeigen zurücksetzen      
      Druck_Liste_2_anzeigen = false;           //Druck Liste 2 anzeigen zurücksetzen
      Durchfluss_Liste_1_anzeigen = false;      //Durchfluss Liste anzeigen zurücksetzen       
      break;
      
/********************************************************************************************************************/

    }
  }
  
/********************************************************************************************************************/

  Statusanzeige();              //Aufruf Funktion Statusanzeige
  
/********************************************************************************************************************/

      /* Stromsensor INA219 einlesen */

//      if ((sensor219.getCurrent_mA()>=current+0.5)||(sensor219.getCurrent_mA()<=current-0.5)||(sensor219.getBusVoltage_V()>=busVoltage+0.5)||(sensor219.getBusVoltage_V()<=busVoltage-0.5))   
//      { 

        if ((sensor219.getCurrent_mA()>=current+0.5)||(sensor219.getCurrent_mA()<=current-0.5))   
        { 

        busVoltage = sensor219.getBusVoltage_V();                   //Spannung berechnen
        current = offset_current + sensor219.getCurrent_mA();       //Strom berechnen
        power = busVoltage * (current / 1000.0);                      //Leistung berechnen

        /* Aktuelle Werte anzeigen */
        Display.txt_Height(3);                      //Texthöhe
        Display.txt_Width(3);                       //Textweite
        Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
        Display.txt_Inverse(OFF);                   //Text invetieren
        Display.txt_Bold(OFF);                      //Text fett
    
        Display.gfx_MoveTo(260, 100);               //Text Position (x,y)
        Display.print("Spannung: ");                //Text anzeigen
        Display.print(busVoltage);                  //Wert anzeigen
        Display.print(" V    ");                    //Text anzeigen
        Display.gfx_MoveTo(260, 150);               //Text Position (x,y)
        Display.print("Strom   : ");                //Text anzeigen
        Display.print(current);                     //Wert anzeigen
        Display.print(" mA    ");                   //Text anzeigen
        Display.gfx_MoveTo(260, 200);               //Text Position (x,y)
        Display.print("Leistung: ");                //Text anzeigen
        Display.print(power);                       //Wert anzeigen
        Display.print(" W     ");                   //Text anzeigen

/********************************************************************************************************************/

        /* Aktuelle Einheit       
           0=Nichts Angewählt           
           
           Druck           
           1=10bar, 2=20bar, 3=40bar, 4=50bar, 5=100bar, 6=?, 7=?, 8=?, 9=? 
           
           Durchfluss
           10=10000Nl/min, 11=?, 12=?, 13=?, 14=?, 15=?, 16=?, 17=?, 18=?, 19=?
          
           Temperatur
           20=100Grad, 21=150Grad, 22=350Grad, 23=?, 24=?, 25=?, 26=?, 27=?, 28=?, 29=?  
                 
        */
        Display.gfx_MoveTo(260, 300);               //Text Position (x,y)        
        
        switch (Einheit_Analog)
        {
          /* Einheit ? noch nichts angewählt */
          case 0:       
            Display.print("?????   : ");                //Text anzeigen
            Display.print(Aktueller_Wert_Analog);       //Wert anzeigen
            Display.print(" ???  ");                    //Text anzeigen
            break;

          /* Einheit Druck */
          case 1 ... 9:
            
            /* Druck berechnen */   
            Aktueller_Wert_Analog = ((current - Min_mA_Analog) * Max_Wert_Analog / (Max_mA_Analog - Min_mA_Analog));       //Druck berechnen

            /* Druck anzeigen */
            Display.print("Druck   : ");                //Text anzeigen
            Display.print(Aktueller_Wert_Analog);       //Wert anzeigen
            Display.print(" bar  ");                    //Text anzeigen
            break;

          /* Einheit Durchfluss */
          case 10 ... 19:
            
            /* Durchfluss berechnen */   
            Aktueller_Wert_Analog = ((current - Min_mA_Analog) * Max_Wert_Analog / (Max_mA_Analog - Min_mA_Analog));       //Durchfluss berechnen

            /* Durchfluss anzeigen */
            Display.print("Durchf. : ");                //Text anzeigen
            Display.print(Aktueller_Wert_Analog);       //Wert anzeigen
            Display.print(" Nl/min  ");                 //Text anzeigen
            break;

          /* Einheit Temperatur */
          case 20 ... 29:
            
            /* Temperatur berechnen */   
            Aktueller_Wert_Analog = ((current - Min_mA_Analog) * Max_Wert_Analog / (Max_mA_Analog - Min_mA_Analog));       //Temperatur berechnen

            /* Temperatur anzeigen */
            Display.print("Temp.   : ");                //Text anzeigen
            Display.print(Aktueller_Wert_Analog);       //Wert anzeigen
            Display.print(" Grad  ");                   //Text anzeigen
            break;
        }
    
/********************************************************************************************************************/
        
        //Messung aktiv
        if (Messung_Ein_Analog == true)                     //Überwachung Messung aktiv
        {
          Messungen_Analog++;
          Analogwert[Messungen_Analog] = Aktueller_Wert_Analog;           //Messwert übergeben
        }
        
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
  if (Status_Display == TOUCH_RELEASED)             //Überwachung Touch Freigabe
  {

/********************************************************************************************************************/
    
    /* Touch Feld abfragen [Zrugg] Taste gedrückt */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrugg] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");   //Taste anzeigen gedrückt

        //offset_current = 0;                               //offset Zurücksetzen 
        Mess_Auswahl_Liste_aufgebaut = false;             //Mess Auswahl Liste aufgebaut zurücksetzen

        /* Buzzer */
        Buzzer(100);                                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)

        Menue_angewaehlt = 0;                             //Hauptmenü anwählen
        Bild_aufgebaut[0] = false;                        //Bildschirm aufgebaut zurücksetzen

        digitalWrite(DA_Versorgung_24VDC, LOW);           //Digital Ausgang Versorgung 24VDC zurücksetzen  
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
          
          Analogwert[i] = 0;                              //Messwerte zurücksetzen
        }              
        
        Messungen_Analog = 0;                             //Anzahl Messungen zurücksetzen  
        offset_current = 0;                               //offset Zurücksetzen  
        Einheit_Analog = 0;                               //Einheit Analog zurücksetzen
        Mess_Auswahl_Liste_aufgebaut = false;             //Mess Auswahl Liste aufgebaut zurücksetzen    

        /* Buzzer */
        Buzzer(100);                                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 3;                             //Menü Analogeanzeige anwählen       
        Bild_aufgebaut[3] = false;                        //Bildschirm aufgebaut zurücksetzen        
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
        
        /* Datenausgabe auf USB Schnittstelle */  
   //     if (SerialUSB.available())      //Überwachung Schnittstelle verfügbar
   //     {

        /* [Export] Taste anzeigen Funktion aktiv */
        Display.gfx_Button(Status_Touch_Taste, 50, 420, GREEN, BLACK, Schrifttyp, Textbreite, Textrahmen, "Export");                   //Taste anzeigen Funktion aktiv

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        for (Messungen_Analog = 0; Messungen_Analog <= 10000; Messungen_Analog++)
        {  
          Analogwert[Messungen_Analog] = Aktueller_Wert_Analog;         //Messwert übergeben
          SerialUSB.println();                                 
          SerialUSB.print(Messungen_Analog);                            //Ausgabe Aktuelle Messung
          SerialUSB.print(" Messung ");                                 //Ausgabe Text
          SerialUSB.print(Analogwert[Messungen_Analog]);                //Ausgabe Aktueller Messwert auf USB Schnittstelle
          SerialUSB.print(" bar");                                      //Ausgabe Text
 //         delay(Zeitraster_Messung);                                  //Zeitraster (Verzögerung für nächste Messung)                
        }      
  //      }

      Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                   //Taste anzeigen ungedrückt 
                                                
      }
    }
    
/********************************************************************************************************************/

      /* Touch Feld abfragen [Graphik] Taste gedrückt */
      if ((X_Pos_Touch >= 170) && (X_Pos_Touch <= 300) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {         
        /* Touch Feld [Graphik] Taste ausführen */
        if (Status_Touch_Taste)
        { 
          Display.gfx_Button(Status_Touch_Taste, 200, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Graphik");                  //Taste anzeigen gedrückt

          /* Buzzer */
          Buzzer(100);                                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          Mess_Auswahl_Liste_aufgebaut = false;             //Mess Auswahl Liste aufgebaut zurücksetzen
        
          Menue_angewaehlt = 18;                            //Menü Graphik anwählen          
          Bild_aufgebaut[18] = false;                       //Bildschirm aufgebaut setzen               
        }
      }
        
/********************************************************************************************************************/

      /* Touch Feld abfragen [Berechnung] Taste gedrückt */
      if ((X_Pos_Touch >= 20) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 330) && (Y_Pos_Touch <= 390) && (Einheit_Analog == 10))   //Überwachung Touch Feld
      {         
        /* Touch Feld [Berechnung] Taste ausführen */
        if (Status_Touch_Taste)
        { 
          Display.gfx_Button(Status_Touch_Taste, 50, 360, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Berechnung");                  //Taste anzeigen gedrückt

          /* Buzzer */
          Buzzer(100);                                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)

          Mess_Auswahl_Liste_aufgebaut = false;             //Mess Auswahl Liste aufgebaut zurücksetzen
        
          Menue_angewaehlt = 19;                            //Menü Graphik anwählen          
          Bild_aufgebaut[19] = false;                       //Bildschirm aufgebaut setzen               
        }
      }
        
/********************************************************************************************************************/

    /* Touch Feld abfragen [10 bar] Taste gedrückt */
    if ((Druck_Liste_1_anzeigen == true) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 65) && (Y_Pos_Touch <= 105))   //Überwachung Touch Feld
    {     
      /* Touch Feld [10 bar] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 0, 135, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "20 bar");        //Taste anzeigen ungedrückt   
        Display.gfx_Button(Status_Touch_Taste, 0, 185, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "40 bar");        //Taste anzeigen ungedrückt     
        Display.gfx_Button(Status_Touch_Taste, 0, 235, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "50 bar");        //Taste anzeigen ungedrückt             

        Display.gfx_Button(Status_Touch_Taste, 0, 85, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "10 bar");        //Taste anzeigen gedrückt               

        Display.gfx_Button(Status_Touch_Taste, 50, 360, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Berechnung");   //Taste anzeigen nicht drückbar

        /* Vorgaben */
        Einheit_Analog = 1;               //Einheit Analog vorgeben (1=Druck 10bar)
        Min_mA_Analog = 4;                //Minimum Strom Grenzwert 4mA  
        Max_mA_Analog = 20;               //Maximum Strom Grenzwert 20mA
        Max_Wert_Analog = 10;             //Maximum Analog Grenzwert
        
        /* Buzzer */
        Buzzer(100);                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)            
      }
    }
      
/********************************************************************************************************************/

    /* Touch Feld abfragen [20 bar] Taste gedrückt */
    if ((Druck_Liste_1_anzeigen == true) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 115) && (Y_Pos_Touch <= 155))   //Überwachung Touch Feld
    {      
      /* Touch Feld [20 bar] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 0, 85, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "10 bar");         //Taste anzeigen ungedrückt
        Display.gfx_Button(Status_Touch_Taste, 0, 185, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "40 bar");        //Taste anzeigen ungedrückt     
        Display.gfx_Button(Status_Touch_Taste, 0, 235, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "50 bar");        //Taste anzeigen ungedrückt             
                
        Display.gfx_Button(Status_Touch_Taste, 0, 135, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "20 bar");       //Taste anzeigen gedrückt               

        Display.gfx_Button(Status_Touch_Taste, 50, 360, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Berechnung");   //Taste anzeigen nicht drückbar

        /* Vorgaben */
        Einheit_Analog = 2;               //Einheit Analog vorgeben (2=Druck 20bar)
        Min_mA_Analog = 4;                //Minimum Strom Grenzwert 4mA  
        Max_mA_Analog = 20;               //Maximum Strom Grenzwert 20mA
        Max_Wert_Analog = 20;             //Maximum Analog Grenzwert
                        
        /* Buzzer */
        Buzzer(100);                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)                                                          
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [40 bar] Taste gedrückt */
    if ((Druck_Liste_1_anzeigen == true) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 165) && (Y_Pos_Touch <= 205))   //Überwachung Touch Feld
    {     
      /* Touch Feld [40 bar] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 0, 85, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "10 bar");         //Taste anzeigen ungedrückt     
        Display.gfx_Button(Status_Touch_Taste, 0, 135, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "20 bar");        //Taste anzeigen ungedrückt     
        Display.gfx_Button(Status_Touch_Taste, 0, 235, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "50 bar");        //Taste anzeigen ungedrückt     
               
        Display.gfx_Button(Status_Touch_Taste, 0, 185, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "40 bar");       //Taste anzeigen gedrückt         

        Display.gfx_Button(Status_Touch_Taste, 50, 360, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Berechnung");   //Taste anzeigen nicht drückbar

        /* Vorgaben */
        Einheit_Analog = 3;               //Einheit Analog vorgeben (3=Druck 50bar)
        Min_mA_Analog = 4;                //Minimum Strom Grenzwert 4mA  
        Max_mA_Analog = 20;               //Maximum Strom Grenzwert 20mA
        Max_Wert_Analog = 40;             //Maximum Analog Grenzwert
        
        /* Buzzer */
        Buzzer(100);                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)                                                         
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [50 bar] Taste gedrückt */
    if ((Druck_Liste_1_anzeigen == true) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 215) && (Y_Pos_Touch <= 255))   //Überwachung Touch Feld
    {     
      /* Touch Feld [50 bar] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 0, 85, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "10 bar");         //Taste anzeigen ungedrückt   
        Display.gfx_Button(Status_Touch_Taste, 0, 135, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "20 bar");        //Taste anzeigen ungedrückt 
        Display.gfx_Button(Status_Touch_Taste, 0, 185, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "40 bar");        //Taste anzeigen ungedrückt     
        
        Display.gfx_Button(Status_Touch_Taste, 0, 235, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "50 bar");       //Taste anzeigen gedrückt         

        Display.gfx_Button(Status_Touch_Taste, 50, 360, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Berechnung");   //Taste anzeigen nicht drückbar

        /* Vorgaben */
        Einheit_Analog = 4;               //Einheit Analog vorgeben (4=Druck 100bar)
        Min_mA_Analog = 4;                //Minimum Strom Grenzwert 4mA  
        Max_mA_Analog = 20;               //Maximum Strom Grenzwert 20mA
        Max_Wert_Analog = 50;             //Maximum Analog Grenzwert
        
        /* Buzzer */
        Buzzer(100);                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)                                                         
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [100 bar] Taste gedrückt */
    if ((Druck_Liste_2_anzeigen == true) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 65) && (Y_Pos_Touch <= 105))   //Überwachung Touch Feld
    {     
      /* Touch Feld [100 bar] Taste ausführen */
      if (Status_Touch_Taste)
      {           
        Display.gfx_Button(Status_Touch_Taste, 0, 85, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "100 bar");       //Taste anzeigen gedrückt         

        Display.gfx_Button(Status_Touch_Taste, 50, 360, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Berechnung");   //Taste anzeigen nicht drückbar

        /* Vorgaben */
        Einheit_Analog = 5;               //Einheit Analog vorgeben (4=Druck 100bar)
        Min_mA_Analog = 4;                //Minimum Strom Grenzwert 4mA  
        Max_mA_Analog = 20;               //Maximum Strom Grenzwert 20mA
        Max_Wert_Analog = 100;            //Maximum Analog Grenzwert
        
        /* Buzzer */
        Buzzer(100);                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)                                                         
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [2500 Nl/min] Taste gedrückt */
    if ((Durchfluss_Liste_1_anzeigen == true) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 65) && (Y_Pos_Touch <= 105))   //Überwachung Touch Feld
    {     
      /* Touch Feld [2500 Nl/min] Taste ausführen */
      if (Status_Touch_Taste)
      {                      
        Display.gfx_Button(Status_Touch_Taste, 0, 85, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "2500 Nl/min");   //Taste anzeigen gedrückt               
        
        Display.gfx_Button(Status_Touch_Taste, 50, 360, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Berechnung");   //Taste anzeigen ungedrückt

        /* Vorgaben */
        Einheit_Analog = 10;              //Einheit Analog vorgeben (10=Durchfluss 1000Nl/min)
        Min_mA_Analog = 4;                //Minimum Strom Grenzwert 4mA  
        Max_mA_Analog = 20;               //Maximum Strom Grenzwert 20mA
        Max_Wert_Analog = 2500;           //Maximum Analog Grenzwert

        /* Buzzer */
        Buzzer(100);                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)            
      }
    }
      
/********************************************************************************************************************/

     /* Touch Feld abfragen [100 Grad] Taste gedrückt */
    if ((Temperatur_Liste_1_anzeigen == true) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 65) && (Y_Pos_Touch <= 105))   //Überwachung Touch Feld
    {     
      /* Touch Feld [100 Grad] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 0, 135, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "150 Grad");      //Taste anzeigen ungedrückt 
        Display.gfx_Button(Status_Touch_Taste, 0, 185, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "350 Grad");      //Taste anzeigen ungedrückt     

        Display.gfx_Button(Status_Touch_Taste, 0, 85, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "100 Grad");      //Taste anzeigen gedrückt               

        Display.gfx_Button(Status_Touch_Taste, 50, 360, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Berechnung");   //Taste anzeigen nicht drückbar

        /* Vorgaben */
        Einheit_Analog = 20;              //Einheit Analog vorgeben (20=Temperatur 100Grad)
        Min_mA_Analog = 4;                //Minimum Strom Grenzwert 4mA  
        Max_mA_Analog = 20;               //Maximum Strom Grenzwert 20mA
        Max_Wert_Analog = 100;            //Maximum Analog Grenzwert
        
        /* Buzzer */
        Buzzer(100);                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)            
      }
    }
      
/********************************************************************************************************************/

    /* Touch Feld abfragen [150 Grad] Taste gedrückt */
    if ((Temperatur_Liste_1_anzeigen == true) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 115) && (Y_Pos_Touch <= 155))   //Überwachung Touch Feld
    {      
      /* Touch Feld [150 Grad] Taste ausführen */
      if (Status_Touch_Taste)
      {                   
        Display.gfx_Button(Status_Touch_Taste, 0, 85, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "100 Grad");       //Taste anzeigen ungedrückt
        Display.gfx_Button(Status_Touch_Taste, 0, 185, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "350 Grad");      //Taste anzeigen ungedrückt     

        Display.gfx_Button(Status_Touch_Taste, 0, 135, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "150 Grad");     //Taste anzeigen gedrückt               

        Display.gfx_Button(Status_Touch_Taste, 50, 360, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Berechnung");   //Taste anzeigen nicht drückbar

        /* Vorgaben */
        Einheit_Analog = 21;              //Einheit Analog vorgeben (21=Temperatur 150Grad)
        Min_mA_Analog = 4;                //Minimum Strom Grenzwert 4mA  
        Max_mA_Analog = 20;               //Maximum Strom Grenzwert 20mA
        Max_Wert_Analog = 150;            //Maximum Analog Grenzwert
        
        /* Buzzer */
        Buzzer(100);                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)            
      }
    }
      
/********************************************************************************************************************/

    /* Touch Feld abfragen [350 Grad] Taste gedrückt */
    if ((Temperatur_Liste_1_anzeigen == true) && (X_Pos_Touch >= 0) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 165) && (Y_Pos_Touch <= 205))   //Überwachung Touch Feld
    {     
      /* Touch Feld [350 Grad] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Button(Status_Touch_Taste, 0, 85, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "100 Grad");       //Taste anzeigen ungedrückt
        Display.gfx_Button(Status_Touch_Taste, 0, 135, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "150 Grad");      //Taste anzeigen ungedrückt 
                           
        Display.gfx_Button(Status_Touch_Taste, 0, 185, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "350 Grad");     //Taste anzeigen gedrückt               

        Display.gfx_Button(Status_Touch_Taste, 50, 360, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Berechnung");   //Taste anzeigen nicht drückbar

        /* Vorgaben */
        Einheit_Analog = 22;              //Einheit Analog vorgeben (22=Temperatur 350Grad)
        Min_mA_Analog = 4;                //Minimum Strom Grenzwert 4mA  
        Max_mA_Analog = 20;               //Maximum Strom Grenzwert 20mA
        Max_Wert_Analog = 350;            //Maximum Analog Grenzwert        

        /* Buzzer */
        Buzzer(100);                      //Aufruf Funktion Buzzer(int Buzzer_Zeit)            
      }
    }
      
/********************************************************************************************************************/

     /* Touch Feld abfragen [Set 0] Taste gedrückt */
    if ((X_Pos_Touch >= 0) && (X_Pos_Touch <= 150) && (Y_Pos_Touch >= 290) && (Y_Pos_Touch <= 310))   //Überwachung Touch Feld
    {     
      /* Touch Feld [Set 0] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        /* [Set 0] Taste anzeigen Funktion aktiv */
        Display.gfx_Button(Status_Touch_Taste, 50, 300, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Set 0");                  //Taste anzeigen gedrückt

        /* Offset berechnen */
        offset_current = 4.0 - sensor219.getCurrent_mA();       //Offset berechnen

        delay(1000);  //Verzögerung 1000ms
        Display.gfx_Button(Status_Touch_Taste, 50, 300, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Set 0");                     //Taste anzeigen ungedrückt

        SerialUSB.println(offset_current);    //Ausgabe auf USB zur testzwecke!

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)                                                                           
      }
    }
    
/********************************************************************************************************************/

      /* Touch Feld abfragen [Start] Taste gedrückt (Doppel Taste Start/Stopp)
         Es wird die Stopp Taste angezeigt! */
      if ((Messung_Ein_Analog == false) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {     
        /* Touch Feld [Start] Taste ausführen */
        if (Status_Touch_Taste)
        {       
          Display.gfx_Button(Status_Touch_Taste, 500, 420, RED, WHITE, Schrifttyp, Textbreite, Textrahmen, "Stopp");                  //Taste anzeigen gedrückt 

          Display.gfx_Button(Status_Touch_Taste, 650, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Zrugg");                  //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 350, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                 //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 50, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Export");                 //Taste anzeigen nicht drückbar 
          Display.gfx_Button(Status_Touch_Taste, 200, 420, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Graphik");               //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 50, 360, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Berechnung");             //Taste anzeigen nicht drückbar
          Display.gfx_Button(Status_Touch_Taste, 50, 300, GRAY, BLACK, Schrifttyp, Textbreite, Textrahmen, "Set 0");                  //Taste anzeigen nicht drückbar

          /* Messung Ein */
          Messung_Ein_Analog = true;         //Messung Ein Analogeanzeige setzen

          /* Buzzer */
          Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        }
      }
    
/********************************************************************************************************************/

      /* Touch Feld abfragen [Stopp] Taste gedrückt (Doppel Taste Start/Stopp)
         Es wird die Start Taste angezeigt! */
      if ((Messung_Ein_Analog == true) && (X_Pos_Touch >= 470) && (X_Pos_Touch <= 570) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
      {
        Status_Touch_Taste = !Status_Touch_Taste;                                               //Status Taste Invertieren
           
        /* Touch Feld [Stopp] Taste ausführen */
        if (Status_Touch_Taste)
        { 
          Display.gfx_Button(Status_Touch_Taste, 500, 420, GREEN, WHITE, Schrifttyp, Textbreite, Textrahmen, "Start");                                //Taste anzeigen gedrückt
          
          Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");     //Taste anzeigen ungedrückt
          Display.gfx_Button(Status_Touch_Taste, 350, 420, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                               //Taste anzeigen ungedrückt
          Display.gfx_Button(Status_Touch_Taste, 50, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Export");                                 //Taste anzeigen ungedrückt 
          Display.gfx_Button(Status_Touch_Taste, 200, 420, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Graphik");                               //Taste anzeigen ungedrückt
          Display.gfx_Button(Status_Touch_Taste, 50, 360, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Berechnung");                             //Taste anzeigen ungedrückt
          Display.gfx_Button(Status_Touch_Taste, 50, 300, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Set 0");                                  //Taste anzeigen ungedrückt 
      
          /* Messung Aus */      
          Messung_Ein_Analog = false;          //Messung Ein Analogeanzeige zurücksetzen      
          
          /* Buzzer */
          Buzzer(500);                        //Aufruf Funktion Buzzer(int Buzzer_Zeit)             
        }
      }
        
/********************************************************************************************************************/

    /* Touch Feld abfragen [▲] Taste gedrückt (Auswahlliste scrollen) */
    if ((X_Pos_Touch >= 150) && (X_Pos_Touch <= 250) && (Y_Pos_Touch >= 100) && (Y_Pos_Touch <= 180))    //Überwachung Touch Feld
    {
      /* Touch Feld [▲] Taste ausführen (Auswahlliste scrollen) */
      if (Status_Touch_Taste)
      {
        Mess_Auswahl_Liste_aufgebaut = false;           //Mess Auswahl Liste aufgebaut zurücksetzen

        Mess_Auswahl_Liste--;                           //Mess Auswahl Liste nach oben wechseln

        /* Mess Auswahl Listen Seiten begrenzen */
        if (Mess_Auswahl_Liste <= 0) Mess_Auswahl_Liste = 0;     //Mess Auswahl Liste anzahl Seiten begrenzen
       
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)            
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [▼] Taste gedrückt (Auswahlliste scrollen) */
    if ((X_Pos_Touch >= 150) && (X_Pos_Touch <= 250) && (Y_Pos_Touch >= 170) && (Y_Pos_Touch <= 250))    //Überwachung Touch Feld
    {
      /* Touch Feld [▼] Taste ausführen (Auswahlliste scrollen) */
      if (Status_Touch_Taste)
      {
        Mess_Auswahl_Liste_aufgebaut = false;             //Mess Auswahl Liste aufgebaut zurücksetzen

        Mess_Auswahl_Liste++;                             //Mess Auswahl Liste nach unten wechseln     

        /* Mess Auswahl Listen Seiten begrenzen */
        if (Mess_Auswahl_Liste >= 3) Mess_Auswahl_Liste = 3;    //Mess Auswahl Liste anzahl Seiten begrenzen     
      
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
        Letztes_Menue = 3;                  //Letztes angewähltes Menü   
        Info_Seite = 6;                     //Info Seite anwählen
      }
    }
      
/********************************************************************************************************************/
  }       //Touch Freigabe Ende

/********************************************************************************************************************/
   
}
