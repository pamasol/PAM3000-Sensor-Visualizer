/* 7.Info 
   Die Texte werden im zugehörigen Exel-File geschrieben,
   das vereinfacht das programmieren.
   Der Programmcode kann dann 1:1 reinkopiert werden.

*/

void Info()               //Funktion Info
{

/********************************************************************************************************************/

  /* Bildaufbau
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */      
  if (Bild_aufgebaut[7] == false)                         //Überwachung Bildschirm aufgebaut
  {
    Display.gfx_Cls();            //Display löschen
    Statusanzeige();              //Aufruf Funktion Statusanzeige

    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "Info ");   //Funktion Namen anzeigen

    /* Text Format */
    Display.txt_Height(2);                                      //Texthöhe
    Display.txt_Width(2);                                       //Textweite
    Display.txt_Set(TEXT_COLOUR, WHITE);                        //Textfarbe
    Display.gfx_MoveTo(130, 45);                                //Text Position (x,y)

    Display.print("Seite: ");
    Display.print(Info_Seite);
    Display.print('/');
    Display.print(Info_Seite_Max);
    
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;      
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");           //Taste anzeigen ungedrückt

    /* Grafik anzeigen */
    if(Info_Seite != 0)
    {
      Display.gfx_Triangle(400, 20, 380, 40, 420, 40, WHITE);         //Dreieck Seite hoch zeichnen (x, y, x2, y2, x3, y3, Farbe)
    }
    if(Info_Seite != 19)
    {
      Display.gfx_Triangle(400, 470, 380, 450, 420, 450, WHITE);      //Dreieck Seite runter zeichnen (x, y, x2, y2, x3, y3, Farbe)
    }

/********************************************************************************************************************/

    /* Text Format */
    Display.txt_Height(2);                                      //Texthöhe
    Display.txt_Width(2);                                       //Textweite
    Display.txt_Set(TEXT_COLOUR, Texthintergrund_Menue);        //Textfarbe
    Display.gfx_MoveTo(10, 100);                                //Text Position (x,y)
        
    /* Anwahl Info Seite */
    switch(Info_Seite)               //Überwachen Anwahl Info Seite
    {

/********************************************************************************************************************/

      case 0:        //Seite 0

        /* Hauptmenü */
        Display.println("Doppel-Stoppuhr: Zeitmessung von Absenkstationen");
        Display.println("mit Adapter A.");
        Display.println("Stoppuhr: Zeitmessung mit Start und Stop");
        Display.println("");
        Display.println("Geschwindigkeitsanzeige Takt: Geschwindigkeits-");
        Display.println("messung von Maschinen wo einen Takt Sensor");
        Display.println("eingebaut haben mit Adapter B.");
        Display.println("");
        Display.println("Geschwindigkeitsanzeige Sortierer:");
        Display.println("Geschwindigkeitsmessung mit Lichtschranke");
        Display.println("Auslaufseitig Sortierer");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 1:        //Seite 1

        /* Steckerbelegung */
        Display.println("Steckerbelegung:");
        Display.println("  1. +24VDC");
        Display.println("  2. +5VDC");
        Display.println("  3. GND");
        Display.println("  4. IC2 SDA");
        Display.println("  5. IC2 SCL ");
        Display.println("  6. Adapter Erkennung");
        Display.println("  7. Eingang 1 0-20mA (IC2)");
        Display.println("  8. Eingang 2 0-20mA (IC2)");
        Display.println("  9. Eingang 1 Digital/Analog Port 8");
        Display.println(" 10. Eingang 2 Digital/Analog Port 9");
        Display.println(" 11. Eingang 3");
        break;

/********************************************************************************************************************/

      case 2:        //Seite 2

        /*  */
        Display.println(" 12. Eingang 4");
        Display.println(" 13. Ausgang 1");
        Display.println(" 14. Ausgang 2");
        Display.println(" 15. Ausgang 3");
        Display.println("");
        Display.println("Achtung: Eingaenge maximum 5VDC!");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 3:        //Seite 3

        /* Doppel-Stoppuhr */
        Display.println("Doppel-Stoppuhr:");
        Display.println("");
        Display.println("Benoetigter Adapter A");
        Display.println("");
        Display.println("Alle ueber Mittelwert werden blau markiert!");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 4:        //Seite 4

        /* Geschwindigkeit Takt */
        Display.println("Geschwindigkeit Takt:");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 5:        //Seite 5

        /* Analogeanzeige */
        Display.println("Analogeanzeige:");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 6:        //Seite 6

        /* Magnetpolanzeige */
        Display.println("Magnetpolanzeige:");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 7:        //Seite 7

        /* Einstellungen */
        Display.println("Einstellungen:");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 8:        //Seite 8

        /* IO Tester */
        Display.println("IO Tester:");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 9:        //Seite 9

        /* Speed Sensor */
        Display.println("Speed Sensor:");
        Display.println("");
        Display.println("Benoetigter Adapter Speed Sensor");
        Display.println("");
        Display.println("1. Start Taste druecken");
        Display.println("2. Das Speed-Sensor Rad auf die zu messende");
        Display.println("   Flaeche halten ");
        Display.println("3. Geschwindigkeit wird in m/min angezeigt");
        Display.println("");
        Display.println("Option Referenz: Speichert Geschwindigkeit bei");
        Display.println("betaetigung. Gibt nach erneuter Geschwindigkeits-");
        Display.println("messung bei 50Hz, die benoetigte Freqeunz");
        break;

/********************************************************************************************************************/

      case 10:        //Seite 10

        /* Speed Sensor */
        Display.println("anpassung am FU aus.");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 11:        //Seite 11

        /* Distanz Sensor */
        Display.println("Distanz Sensor:");
        Display.println("");
        Display.println("Benoetigter Adapter Distanz Sensor");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 12:        //Seite 12

        /* Geschwindigkeit Sortierer */
        Display.println("Geschwindigkeit Sortierer:");
        Display.println("");
        Display.println("Benoetigter Adapter B");
        Display.println("");
        Display.println("Es werden nur Werte gerechnet wo mindestens");
        Display.println("50% vom aktuellen Hoechstwert erreichen!");
        Display.println("");
        Display.println("Alle unter Mittelwert werden rot markiert!");
        Display.println("");
        Display.println("Lichtschrankentyp:");
        Display.println("[- o -] Lichtschranke auf unterbruch");
        Display.println("[= o  ] Lichtschranke auf reflektion");
        break;

/********************************************************************************************************************/

      case 13:        //Seite 13

        /* Dioppel-Stoppuhr Liste */
        Display.println("Doppel-Stoppuhr Liste:");
        Display.println("");
        Display.println("[+20] auf die naechsten 20 Werte vorwaerts");
        Display.println("Blaettern.");
        Display.println("[-20] auf die naechsten 20 Werte rueckwaerts");
        Display.println("Blaettern.");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 14:        //Seite 14

        /* Geschwindigkeit Takt Liste */
        Display.println("Geschwindigkeit Takt Liste:");
        Display.println("");
        Display.println("[+20] auf die naechsten 20 Werte vorwaerts");
        Display.println("Blaettern.");
        Display.println("[-20] auf die naechsten 20 Werte rueckwaerts");
        Display.println("Blaettern.");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 15:        //Seite 15

        /* Geschwindigkeit Sortierer Liste */
        Display.println("Geschwindigkeit Sortierer Liste:");
        Display.println("");
        Display.println("[+20] auf die naechsten 20 Werte vorwaerts");
        Display.println("Blaettern.");
        Display.println("[-20] auf die naechsten 20 Werte rueckwaerts");
        Display.println("Blaettern.");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 16:        //Seite 16

        /* Stoppuhr */
        Display.println("Stoppuhr:");
        Display.println("");
        Display.println("Benoetigter Adapter...");
        Display.println("");
        Display.println("Sensor 1 = Start");
        Display.println("Sensor 2 = Stop");
        Display.println("");
        Display.println("Alle ueber Mittelwert werden blau markiert!");
        Display.println("");
        Display.println("[Referenz] = Speichert den Aktuellenwert");
        Display.println("als Referenz, und berechntet die Differenz.");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 17:        //Seite 17

        /* Stoppuhr Liste */
        Display.println("Stoppuhr Liste:");
        Display.println("");
        Display.println("[+20] auf die naechsten 20 Werte vorwaerts");
        Display.println("Blaettern.");
        Display.println("[-20] auf die naechsten 20 Werte rueckwaerts");
        Display.println("Blaettern.");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 18:        //Seite 18

        /* Graphik */
        Display.println("Graphik:");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 19:        //Seite 19

        /* Berechnung */
        Display.println("Berechnung:");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 20:        //Seite 20

        /* Neigungs Sensor */
        Display.println("Neigungs Sensor:");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 21:        //Seite 21

        /* MP3 Player */
        Display.println("MP3 Player:");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 22:        //Seite 22

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 23:        //Seite 23

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 24:        //Seite 24

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 25:        //Seite 25

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 26:        //Seite 26

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 27:        //Seite 27

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 28:        //Seite 28

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 29:        //Seite 29

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 30:        //Seite 30

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 31:        //Seite 31

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 32:        //Seite 32

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 33:        //Seite 33

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 34:        //Seite 34

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 35:        //Seite 35

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 36:        //Seite 36

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 37:        //Seite 37

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 38:        //Seite 38

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 39:        //Seite 39

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 40:        //Seite 40

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 41:        //Seite 41

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 42:        //Seite 42

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 43:        //Seite 43

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 44:        //Seite 44

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 45:        //Seite 45

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 46:        //Seite 46

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 47:        //Seite 47

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 48:        //Seite 48

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 49:        //Seite 49

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 50:        //Seite 50

        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

    }

/********************************************************************************************************************/

    Bild_aufgebaut[7] = true;                            //Bildschirm aufgebaut setzen
  }

/********************************************************************************************************************/

  Statusanzeige();              //Aufruf Funktion Statusanzeige

/********************************************************************************************************************/

  /* Touch Screen handling */
  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen
  
  /* Touch Positionen auslesen */
  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))    //Überwachung Touch gedrückt oder bewegt
  {
    X_Pos_Touch = Display.touch_Get(TOUCH_GETX);               //X Position auslesen
    Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);               //Y Position auslesen
  }

  /* Touch Freigabe */
  if (Status_Display == TOUCH_RELEASED)                //Überwachung Touch Freigabe
  {

/********************************************************************************************************************/

    /* Touch Feld abfragen [▲] Taste gedrückt */
    if ((Info_Seite != 0) && (X_Pos_Touch >= 350) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 0) && (Y_Pos_Touch <= 70))    //Überwachung Touch Feld
    {
      /* Touch Feld [▲] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Triangle(400, 20, 380, 40, 420, 40, BLACK);         //Dreieck Seite hoch zeichnen (x, y, x2, y2, x3, y3, Farbe)
    
        Info_Seite--;

        //Listen Startwert begrenzen
        if (Info_Seite <= 0) Info_Seite = 0;        //Listen Startwert begrenzen

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

        Display.gfx_Triangle(400, 20, 380, 40, 420, 40, WHITE);         //Dreieck Seite hoch zeichnen (x, y, x2, y2, x3, y3, Farbe)
        
        Bild_aufgebaut[7] = false;                //Bildschirm aufgebaut zurücksetzen             
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [▼] Taste gedrückt */
    if ((Info_Seite != 19) && (X_Pos_Touch >= 350) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 500))    //Überwachung Touch Feld
    {
      /* Touch Feld [▼] Taste ausführen */
      if (Status_Touch_Taste)
      {       
        Display.gfx_Triangle(400, 470, 380, 450, 420, 450, BLACK);    //Dreieck Seite runter zeichnen (x, y, x2, y2, x3, y3, Farbe)
        
        Info_Seite++;

        //Info Seiten begrenzen
        if (Info_Seite >= Info_Seite_Max) Info_Seite = Info_Seite_Max;        //Info Seiten begrenzen

        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

        Display.gfx_Triangle(400, 470, 380, 450, 420, 450, WHITE);    //Dreieck Seite runter zeichnen (x, y, x2, y2, x3, y3, Farbe)
        
        Bild_aufgebaut[7] = false;         //Bildschirm aufgebaut zurücksetzen                       
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Zrug] Taste gedrückt */  
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrug] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");   //Taste anzeigen gedrückt
    
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
          
        Menue_angewaehlt = Letztes_Menue;             //Hauptmenü anwählen
        Bild_aufgebaut[Letztes_Menue] = false;        //Bildschirm aufgebaut zurücksetzen
      }
    }
    
/********************************************************************************************************************/

  }     //Touch Freigabe Ende
  
/********************************************************************************************************************/
  
}
