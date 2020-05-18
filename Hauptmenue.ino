void Hauptmenue()
{

  Stoppuhrinterrupt = false;                             //Stoppuhrinterrupt zurücksetzen
  Stoppuhrinterrupt2 = false;                            //Stoppuhrinterrupt2 zurücksetzen
  Geschwingigkeitinterrupt = false;                      //Geschwindigkeitsiterrupt zurücksetzen
  Geschwingigkeitinterrupt2 = false;                     //Geschwindigkeitsiterrupt2 zurücksetzen

  Stopp_Zeit_Geschwindigkeit = 0;                        //Stopp_Zeit_Geschwindikeit zurücksetzen
  Stopp_Zeit_Geschwindigkeit2 = 0;                       //Stopp_Zeit_Geschwindikeit2 zurücksetzen
  
  Displaystopp = false;                                  //Displaystopp zurücksetzen

/* Hier wird der Displayhintergrund aufgebaut */ 

    if (Bild_aufgebaut[0] == false)                      //Überwachung Bildschirm aufgebaut
    {

    Display.gfx_Cls();                                   //Display löschen
    Display.gfx_Button(Status_Taste, 30, 60, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Stoppuhr");                         //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 30, 140, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige c to c");  //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 500, 140, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Durchschnitt");                   //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 30, 220, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Analogeanzeige");                  //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 30, 300, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Magnetpolanzeige");                //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 30, 380, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Einstellungen");                   //Taste anzeigen ungedrückt
    
    Bild_aufgebaut[0] = true;                            //Bildschirm aufgebaut setzen
    }

    Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen


    if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))    //Überwachung Touch gedrückt oder bewegt

    {

    X_Pos = Display.touch_Get(TOUCH_GETX);               //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);               //Y Position auslesen
    }

    if (Status_Display == TOUCH_RELEASED)                //Überwachung Touch Freigabe

    {

/* Abfragen Stoppuhr gedrückt*/

      if ((X_Pos >= 10) && (X_Pos <= 790) && (Y_Pos >= 30) && (Y_Pos <= 90))      //Überwachung Touch Feld

      {

      Status_Taste = !Status_Taste;                      //Status_Taste Invertieren
      
      Display.gfx_Button(Status_Taste, 30, 60, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Stoppuhr");                        //Taste anzeigen gedrückt

/* Das wird ausgeführt sobald die Stoppuhr Taste betätigt wird */
   
        if (Status_Taste)

        {

        Menue_angewaehlt = 1;                            //Menü angewählt (1)

        Bild_aufgebaut[1] = false;                       //Bildschirm aufgebaut zurücksetzen
        }
      }

/* Abfragen Geschwindigkeitsanzeige gedrückt*/

      if ((X_Pos >= 10) && (X_Pos <= 490) && (Y_Pos >= 110) && (Y_Pos <= 170))    //Überwachung Touch Feld
      {

      Status_Taste = !Status_Taste;                     //Status_Taste Invertieren

      Display.gfx_Button(Status_Taste, 30, 140, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige c to c"); //Taste anzeigen gedrückt

/* Das wird ausgeführt sobald die Geschwindigkeitsanzeige Taste betätigt wird */

        if (Status_Taste) 
        {

        Menue_angewaehlt = 2;                           //Menü angewählt (2)
        
        Bild_aufgebaut[2] = false;                      //Bildschirm aufgebaut2 zurücksetzen
        }
      }

/* Abfragen Geschwindigkeits Durchschnitt gedrückt*/

      if ((X_Pos >= 500) && (X_Pos <= 790) && (Y_Pos >= 110) && (Y_Pos <= 170))   //Überwachung Touch Feld
      {

      Status_Taste = !Status_Taste;                     //Status_Taste Invertieren

      Display.gfx_Button(Status_Taste, 500, 140, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Durchschnitt");                  //Taste anzeigen gedrückt

/* Das wird ausgeführt sobald die Durchschnitt Taste betätigt wird */

        if (Status_Taste)
        {

        Menue_angewaehlt = 10;                          //Menü angewählt (10)
        
        Bild_aufgebaut[3] = false;                      //Bildschirm aufgebaut3 zurücksetzen
        }
      
      }

/* Abfragen Analogeanzeige gedrückt*/

      if ((X_Pos >= 10) && (X_Pos <= 790) && (Y_Pos >= 190) && (Y_Pos <= 250))    //Überwachung Touch Feld
      {
        
      Status_Taste = !Status_Taste;                     //Status_Taste Invertieren
      
      Display.gfx_Button(Status_Taste, 30, 220, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Analogeanzeige");                 //Taste anzeigen gedrückt

/* Das wird ausgeführt sobald die Analogeanzeige Taste betätigt wird */

        if (Status_Taste)
        {

        Menue_angewaehlt = 3;                           //Menü angewählt (3)
        
        Bild_aufgebaut[6] = false;                      //Bildschirm aufgebaut6 zurücksetzen
        }
      }

/* Abfragen Magnetpolanzeige gedrückt*/

      if ((X_Pos >= 10) && (X_Pos <= 790) && (Y_Pos >= 270) && (Y_Pos <= 330))    //Überwachung Touch Feld
      {

      Status_Taste = !Status_Taste;                     //Status_Taste Invertieren

      Display.gfx_Button(Status_Taste, 30, 300, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Magnetpolanzeige");               //Taste anzeigen gedrückt

/* Das wird ausgeführt sobald die Magnetpolanzeige Taste betätigt wird */

        if (Status_Taste)
        {

        Menue_angewaehlt = 4;                           //Menü angewählt (4)

        Bild_aufgebaut[4] = false;                      //Bildschirm aufgebaut4 zurücksetzen
        }
      }

/* Abfragen Einstellungen gedrückt*/

      if ((X_Pos >= 10) && (X_Pos <= 790) && (Y_Pos >= 350) && (Y_Pos <= 410))    //Überwachung Touch Feld
      {

      Status_Taste = !Status_Taste;                     //Status_Taste Invertieren

      Display.gfx_Button(Status_Taste, 30, 380, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Einstellungen");                  //Taste anzeigen gedrückt

/* Das wird ausgeführt sobald die Einstellungen Taste betätigt wird */

        if (Status_Taste)
        {

        Menue_angewaehlt = 5;                           //Menü angewählt (5)

        Bild_aufgebaut[5] = false;                      //Bildschirm aufgebaut5 zurücksetzen
        }
      }
    }
}
