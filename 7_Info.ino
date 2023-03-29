/* 7.Info 
   Die Texte werden im zugehörigen Exel-File geschrieben,
   das vereinfacht das programmieren.
<<<<<<< HEAD
   Der Programmcode kann dann 1:1 reinkopie rt werden.
=======
   Der Programmcode kann dann 1:1 reinkopiert werden.
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e

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
<<<<<<< HEAD
    Display.txt_Height(2);                        //Texthöhe
    Display.txt_Width(2);                         //Textweite
    Display.txt_Set(TEXT_COLOUR, WHITE);          //Textfarbe
    Display.gfx_MoveTo(130, 45);                  //Text Position (x,y)

    /* Seitenzahl anzeigen */
    Display.print("Seite: ");                     //Text anzeigen
    Display.print(Info_Seite);                    //Wert anzeigen
    Display.print("/");                           //Text anzeigen
    Display.print(Info_Seite_Max);                //Wert anzeigen
=======
    Display.txt_Height(2);                                      //Texthöhe
    Display.txt_Width(2);                                       //Textweite
    Display.txt_Set(TEXT_COLOUR, WHITE);                        //Textfarbe
    Display.gfx_MoveTo(130, 45);                                //Text Position (x,y)

    Display.print("Seite: ");
    Display.print(Info_Seite);
    Display.print('/');
    Display.print(Info_Seite_Max);
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
    
    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;      
<<<<<<< HEAD
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");           //Taste anzeigen ungedrückt

    /* Grafik anzeigen */
    if(Info_Seite != 0)                                               //Überwachen aktuelle Seite
    {
      Display.gfx_Triangle(400, 20, 380, 40, 420, 40, WHITE);         //Dreieck Seite hoch zeichnen (x, y, x2, y2, x3, y3, Farbe)
    }
    if(Info_Seite != Info_Seite_Max)                                  //Überwachen aktuelle Seite
=======
    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");           //Taste anzeigen ungedrückt

    /* Grafik anzeigen */
    if(Info_Seite != 0)
    {
      Display.gfx_Triangle(400, 20, 380, 40, 420, 40, WHITE);         //Dreieck Seite hoch zeichnen (x, y, x2, y2, x3, y3, Farbe)
    }
    if(Info_Seite != 19)
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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
<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 1:        //Seite 1

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 2:        //Seite 2

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 3:        //Seite 3

<<<<<<< HEAD
        /* Geschwindigkeitsanzeige Takt */
        Display.println("Geschwindigkeitsanzeige Takt:");
        Display.println("Geschwindigkeitsmessung von Maschinen mit");
        Display.println("eingebautem Taktsensor.");
        Display.println("");
        Display.println("Benoetigter Adapter Typ ?");
=======
        /* Doppel-Stoppuhr */
        Display.println("Doppel-Stoppuhr:");
        Display.println("");
        Display.println("Benoetigter Adapter A");
        Display.println("");
        Display.println("Alle ueber Mittelwert werden blau markiert!");
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 5:        //Seite 5

<<<<<<< HEAD
        /* Sortierer */
        Display.println("Lichtschrankentyp:");
        Display.println("[= o  ] Lichtschranke auf Reflektion");
        Display.println("[- o -] Lichtschranke auf Unterbruch");
        Display.println("");
        Display.println("Benoetigter Adapter Typ B");
        Display.println("Wichtig: Die Lichtleiter muessen richtig");
        Display.println("ausgerichtet sein! Siehe Kopf des Licht-");
        Display.println("leiters.");
=======
        /* Analogeanzeige */
        Display.println("Analogeanzeige:");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 6:        //Seite 6

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 7:        //Seite 7

<<<<<<< HEAD
        /* Analogeanzeige */
        Display.println("Durchflussmessungsbereich:");
        Display.println("bis 2500 Nl/min");
        Display.println("");
        Display.println("Benoetigter Adapter Typ F");
=======
        /* Einstellungen */
        Display.println("Einstellungen:");
        Display.println("");
        Display.println("");
        Display.println("");
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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

<<<<<<< HEAD
        /* IO-Tester */
        Display.println("IO-Tester:");
        Display.println("Fuer Signaltests von Sensoren");
        Display.println("");
        Display.println("Benoetigter Adapter Typ U");
=======
        /* IO Tester */
        Display.println("IO Tester:");
        Display.println("");
        Display.println("");
        Display.println("");
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 10:        //Seite 10

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 11:        //Seite 11

<<<<<<< HEAD
        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
=======
        /* Distanz Sensor */
        Display.println("Distanz Sensor:");
        Display.println("");
        Display.println("Benoetigter Adapter Distanz Sensor");
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 13:        //Seite 13

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 14:        //Seite 14

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 15:        //Seite 15

<<<<<<< HEAD
        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
=======
        /* Geschwindigkeit Sortierer Liste */
        Display.println("Geschwindigkeit Sortierer Liste:");
        Display.println("");
        Display.println("[+20] auf die naechsten 20 Werte vorwaerts");
        Display.println("Blaettern.");
        Display.println("[-20] auf die naechsten 20 Werte rueckwaerts");
        Display.println("Blaettern.");
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        break;

/********************************************************************************************************************/

      case 16:        //Seite 16

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        Display.println("");
        break;

/********************************************************************************************************************/

      case 17:        //Seite 17

<<<<<<< HEAD
        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
=======
        /* Stoppuhr Liste */
        Display.println("Stoppuhr Liste:");
        Display.println("");
        Display.println("[+20] auf die naechsten 20 Werte vorwaerts");
        Display.println("Blaettern.");
        Display.println("[-20] auf die naechsten 20 Werte rueckwaerts");
        Display.println("Blaettern.");
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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

<<<<<<< HEAD
        /* Neigungssensor */
        Display.println("Neigungssensor:");
        Display.println("");
        Display.println("Benoetigter Adapter Typ N");
=======
        /* Neigungs Sensor */
        Display.println("Neigungs Sensor:");
        Display.println("");
        Display.println("");
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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

<<<<<<< HEAD
        /* MP3-Player */
        Display.println("MP3-Player:");
=======
        /* MP3 Player */
        Display.println("MP3 Player:");
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        Display.println("");
        Display.println("");
        Display.println("");
        break;

<<<<<<< HEAD

=======
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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

<<<<<<< HEAD
        /* Einstellungen */
        Display.println("Einstellungen:");
        Display.println("");
        Display.println("I2C-Scanner");
=======
        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 26:        //Seite 26

<<<<<<< HEAD
        /* Steckerbelegung */
        Display.println(" 12. Eingang 4");
        Display.println(" 13. Ausgang 1");
        Display.println(" 14. Ausgang 2");
        Display.println(" 15. Ausgang 3");
        Display.println("");
        Display.println("Achtung: Eingaenge maximum 5VDC!");
=======
        /*  */
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
        Display.println("");
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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

<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 29:        //Seite 29

        /*  */
<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 30:        //Seite 30

        /*  */
<<<<<<< HEAD
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
=======
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
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        break;

/********************************************************************************************************************/

      case 31:        //Seite 31

        /*  */
<<<<<<< HEAD
        Display.println("Messadapter:");
        Display.println("Bietet die Moeglichkeit, die Messungen mit einem");
        Display.println("externen Messgeraet zu kontrollieren");
=======
        Display.println("");
        Display.println("");
        Display.println("");
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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
<<<<<<< HEAD
    if ((Info_Seite != Info_Seite_Max) && (X_Pos_Touch >= 350) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 500))    //Überwachung Touch Feld
=======
    if ((Info_Seite != 19) && (X_Pos_Touch >= 350) && (X_Pos_Touch <= 450) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 500))    //Überwachung Touch Feld
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
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

<<<<<<< HEAD
    /* Touch Feld abfragen [Zrugg] Taste gedrückt */  
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrugg] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");   //Taste anzeigen gedrückt
=======
    /* Touch Feld abfragen [Zrug] Taste gedrückt */  
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))   //Überwachung Touch Feld
    {
      /* Touch Feld [Zrug] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrug");   //Taste anzeigen gedrückt
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
    
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
