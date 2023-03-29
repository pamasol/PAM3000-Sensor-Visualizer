/* 7.Info 
   Die Texte werden im zugehörigen Exel-File geschrieben,
   das vereinfacht das programmieren.
   Der Programmcode kann dann 1:1 reinkopie rt werden.

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
    Display.txt_Height(2);                        //Texthöhe
    Display.txt_Width(2);                         //Textweite
    Display.txt_Set(TEXT_COLOUR, WHITE);          //Textfarbe
    Display.gfx_MoveTo(130, 45);                  //Text Position (x,y)

    /* Seitenzahl anzeigen */
    Display.print("Seite: ");                     //Text anzeigen
    Display.print(Info_Seite);                    //Wert anzeigen
    Display.print("/");                           //Text anzeigen
    Display.print(Info_Seite_Max);                //Wert anzeigen
    
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;      
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");           //Taste anzeigen ungedrückt

    /* Grafik anzeigen */
    if(Info_Seite != 0)                                               //Überwachen aktuelle Seite
    {
      Display.gfx_Triangle(400, 20, 380, 40, 420, 40, WHITE);         //Dreieck Seite hoch zeichnen (x, y, x2, y2, x3, y3, Farbe)
    }
    if(Info_Seite != Info_Seite_Max)                                  //Überwachen aktuelle Seite
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
        Display.println("PAM3000 Anleitung Version 1.4 / 17.01.2023");
        Display.println("");
        Display.println("Das PAM3000 ist ein Universalmessgeraet, welches");
        Display.println("auf die verschiedenen Anwendungen der Firma");
        Display.println("PAMASOL Willi Maeder AG zugeschnitten wurde.");
        Display.println("");
        Display.println("Fuer jede spezielle Anwendung gibt es einen");
        Display.println("Adapter, welches moeglichst unkomplizierte und");
        Display.println("schnelle Messungen ermoeglicht.");
        Display.println("");
        Display.println("Weitere Informationen:");
        Display.println("github.com/pamasol/PAM3000-Sensor-Visualizer");
        break;

/********************************************************************************************************************/

      case 1:        //Seite 1

        /* Doppel-Stoppuhr: */
        Display.println("Doppel-Stoppuhr:");
        Display.println("Zeitmessung von Absenkstationen.");
        Display.println("Alle ueber Mittelwert werden blau markiert!");
        Display.println("");
        Display.println("Benoetigter Adapter Typ A");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 2:        //Seite 2

        /* Stoppuhr */
        Display.println("Stoppuhr:");
        Display.println("Zeitmessung mit Start und Stopp.");
        Display.println("");
        Display.println("Sensor 1 = Start-Signal");
        Display.println("Sensor 2 = Stopp-Signal");
        Display.println("");
        Display.println("Alle ueber Mittelwert werden blau markiert!");
        Display.println("");
        Display.println("Die Taste [Referenz] speichert den aktuellen");
        Display.println("Wert als Referenz und zeigt die jeweilige");
        Display.println("Differenz zu den nachfolgenden Werten an.");
        Display.println("Benoetigter Adapter Typ A");
        break;

/********************************************************************************************************************/

      case 3:        //Seite 3

        /* Geschwindigkeitsanzeige Takt */
        Display.println("Geschwindigkeitsanzeige Takt:");
        Display.println("Geschwindigkeitsmessung von Maschinen mit");
        Display.println("eingebautem Taktsensor.");
        Display.println("");
        Display.println("Benoetigter Adapter Typ ?");
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

        /* Sortierer */
        Display.println("Sortierer:");
        Display.println("Geschwindigkeitsmessung mit Lichtschranke");
        Display.println("auslaufseitig des Sortierers.");
        Display.println("");
        Display.println("Es werden nur Werte gerechnet, die mindestens");
        Display.println("50% des aktuellen Hoechstwerts erreichen.");
        Display.println("Alle unter diesem Mittelwert werden rot");
        Display.println("markiert.");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("...");
        break;

/********************************************************************************************************************/

      case 5:        //Seite 5

        /* Sortierer */
        Display.println("Lichtschrankentyp:");
        Display.println("[= o  ] Lichtschranke auf Reflektion");
        Display.println("[- o -] Lichtschranke auf Unterbruch");
        Display.println("");
        Display.println("Benoetigter Adapter Typ B");
        Display.println("Wichtig: Die Lichtleiter muessen richtig");
        Display.println("ausgerichtet sein! Siehe Kopf des Licht-");
        Display.println("leiters.");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 6:        //Seite 6

        /* Analoganzeige */
        Display.println("Analoganzeige:");
        Display.println("Druckmessung:");
        Display.println("10bar, 20bar, 40bar, 50bar, 100bar");
        Display.println("");
        Display.println("Benoetigter Adapter Typ C");
        Display.println("");
        Display.println("");
        Display.println("Temperaturmessung: (Celsius)");
        Display.println("100, 150, 350");
        Display.println("");
        Display.println("Benoetigter Adapter Typ C");
        Display.println("…");
        break;

/********************************************************************************************************************/

      case 7:        //Seite 7

        /* Analogeanzeige */
        Display.println("Durchflussmessungsbereich:");
        Display.println("bis 2500 Nl/min");
        Display.println("");
        Display.println("Benoetigter Adapter Typ F");
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

        /* IO-Tester */
        Display.println("IO-Tester:");
        Display.println("Fuer Signaltests von Sensoren");
        Display.println("");
        Display.println("Benoetigter Adapter Typ U");
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

        /* Magnetpolanzeige */
        Display.println("Magnetpolanzeige:");
        Display.println("Anzeige von Suedpol/Norpol.");
        Display.println("Der Sensor ist seitlich am PAM3000 eingebaut.");
        Display.println("Das Magnet wird innerhalb der Kreisflaeche");
        Display.println("detektiert.");
        Display.println("");
        Display.println("");
        Display.println("Magnetfeldsensor:");
        Display.println("Anzeige von Suedpol/Norpol und Feldstaerke");
        Display.println("");
        Display.println("Benoetigter Adapter Typ option");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 10:        //Seite 10

        /* Speedsensor */
        Display.println("Speed-Sensor:");
        Display.println("Anzeige von Bandgeschwindigkeit.");
        Display.println("1. Start-Taste druecken");
        Display.println("2. Das Speed-Sensorrad auf die zu messende");
        Display.println("   Flaeche halten ");
        Display.println("3. Geschwindigkeit wird in m/min angezeigt");
        Display.println("");
        Display.println("Option Referenz: Speichert Geschwindigkeit bei");
        Display.println("Betaetigung. Gibt nach erneuter Geschwindig-");
        Display.println("keitsmessung bei 50Hz die benoetigte Frequenz-");
        Display.println("anpassung am FU aus.");
        Display.println("");
        Display.println("Benoetigter Adapter Typ V");
        break;

/********************************************************************************************************************/

      case 11:        //Seite 11

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

      case 12:        //Seite 12

        /* Distanzsensor */
        Display.println("Distanzsensor:");
        Display.println("Misst Distanzen von 30...1000mm");
        Display.println("Genauigkeit: 1mm");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("Benoetigter Adapter Typ D");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 13:        //Seite 13

        /* Liste */
        Display.println("Liste:");
        Display.println("Anzeige der letzten 60 Messwerte.");
        Display.println("Je nach Funktion werden die Werte farblich");
        Display.println("markiert.");
        Display.println("Mit den Tasten [+20] und [-20] werden die");
        Display.println("naechsten oder voherigen 20 Messwerte");
        Display.println("angezeigt.");
        Display.println("");
        Display.println("Mit der [Export] Taste kann die ganze listerei");
        Display.println("via USB Kabel in den PC exportiert werden.");
        Display.println("Beim PAM3000 wird das USB-Kabel an der Ext");
        Display.println("angeschlossen, beim PC an einer freien Schnitt-");
        break;

/********************************************************************************************************************/

      case 14:        //Seite 14

        /*  */
        Display.println("stelle.");
        Display.println("Vorgang Export:");
        Display.println("1. USB-Kabel an PAM3000 Ext Schnittselle");
        Display.println("anstecken.");
        Display.println("2. Das andere Ende am PC an einer freien USB");
        Display.println("Schnittstelle anstecken.");
        Display.println("3. Exel File PAM3000-Data oeffnen.");
        Display.println("4. Unter Einstellungen den Richtigen Port");
        Display.println("einstellen.");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 15:        //Seite 15

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

      case 16:        //Seite 16

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

      case 17:        //Seite 17

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

        /* Neigungssensor */
        Display.println("Neigungssensor:");
        Display.println("");
        Display.println("Benoetigter Adapter Typ N");
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

        /* MP3-Player */
        Display.println("MP3-Player:");
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

        /* Zaehler: */
        Display.println("Zaehler:");
        Display.println("Zaehlfunktion mit Master Zaehler.");
        Display.println("");
        Display.println("");
        Display.println("Master 1: Zaehler 1 wird als Doppelzaehler,");
        Display.println("so wird die zweite Anzeige zum Beispiel als ");
        Display.println("Tageszaehler.");
        Display.println("Mit Reset wird die Funktion wieder aus-");
        Display.println("geschalten.");
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

        /* Einstellungen */
        Display.println("Einstellungen:");
        Display.println("");
        Display.println("I2C-Scanner");
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

        /* Steckerbelegung */
        Display.println("Steckerbelegung:");
        Display.println("  1. +24VDC");
        Display.println("  2. +5VDC");
        Display.println("  3. GND");
        Display.println("  4. IC2 SDA");
        Display.println("  5. IC2 SCL ");
        Display.println("  6. Adapter-Erkennung");
        Display.println("  7. Eingang 1 0-20mA (IC2)");
        Display.println("  8. Eingang 2 0-20mA (IC2)");
        Display.println("  9. Eingang 1 Digital/Analog Port 8");
        Display.println(" 10. Eingang 2 Digital/Analog Port 9");
        Display.println(" 11. Eingang 3");
        break;

/********************************************************************************************************************/

      case 26:        //Seite 26

        /* Steckerbelegung */
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

        /* Adapter */
        Display.println("Adapter:");
        Display.println("Die Adapter sind gekennzeichnet mit Buchstaben");
        Display.println("");
        Display.println("Adapter Typ A:");
        Display.println("Adapter mit zwei PE-Wandler fuer");
        Display.println("pneumatische Messungen");
        Display.println("");
        Display.println("Adapter Typ B:");
        Display.println("Adapter fuer zwei Matrix-Lichtschranken");
        Display.println("");
        Display.println("Adapter Typ C:");
        Display.println("Adapter fuer analoge 0-20mA Signale");
        break;

/********************************************************************************************************************/

      case 29:        //Seite 29

        /*  */
        Display.println("Adapter Typ D:");
        Display.println("Adapter fuer Distanzmessungen 30...1000mm");
        Display.println("");
        Display.println("Adapter Typ F:");
        Display.println("Adapter fuer Durchflussmessung mit ifm SD9000-");
        Display.println("Sensor");
        Display.println("");
        Display.println("Adapter Typ N:");
        Display.println("Adapter zum Ausrichten von Maschinen");
        Display.println("");
        Display.println("Adapter Typ U:");
        Display.println("Universeller Klemmenadapter");
        break;

/********************************************************************************************************************/

      case 30:        //Seite 30

        /*  */
        Display.println("Adapter Typ V:");
        Display.println("Adapter für Bandgeschwindigeitsmessungen");
        Display.println("");
        Display.println("Adapter Typ Y:");
        Display.println("Bietet die Moeglichkeit, verschiedene");
        Display.println("Adapter zu kombinieren");
        Display.println("");
        Display.println("Adapter Typ I2C:");
        Display.println("Fuer externen Anschluss von I2C-Sensoren");
        Display.println("");
        Display.println("Adapter Typ Klemmen:");
        Display.println("Universeller Klemmenadapter");
        break;

/********************************************************************************************************************/

      case 31:        //Seite 31

        /*  */
        Display.println("Messadapter:");
        Display.println("Bietet die Moeglichkeit, die Messungen mit einem");
        Display.println("externen Messgeraet zu kontrollieren");
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
    if ((Info_Seite != Info_Seite_Max) && (X_Pos_Touch >= 350) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 500))    //Überwachung Touch Feld
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

    /* Touch Feld abfragen [Zrugg] Taste gedrückt */  
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrugg] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");   //Taste anzeigen gedrückt
    
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
