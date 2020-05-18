/* Einstellungen hatt momentan noch keine Funktion*/

void Einstellungen()
{

/* Hier wird der Displayhintergrund aufgebaut */

    if (Bild_aufgebaut[5] == false)                    //Überwachung Bildschirm aufgebaut
    {

    Display.gfx_Cls();                                 //Display löschen

    Display.gfx_Button(Status_Taste, 30, 10, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Einstellungen");  //Funktion Namen anzeigen

    Status_Taste = BUTTON_UP;
    
    Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Zrug");         //Taste anzeigen ungedrückt

    Bild_aufgebaut[5] = true;                          //Bildschirm aufgebaut5 setzen
    }

  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen


    if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))      //Überwachung Touch gedrückt oder bewegt
    {

    X_Pos = Display.touch_Get(TOUCH_GETX);            //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);            //Y Position auslesen
    }

    if (Status_Display == TOUCH_RELEASED)             //Überwachung Touch Freigabe
    {

/* Hier wir nach der Zrug Taste abgefragt */

      if ((X_Pos >= 620) && (X_Pos <= 790) && (Y_Pos >= 370) && (Y_Pos <= 430))     //Überwachung Touch Feld
      {

      Status_Taste = !Status_Taste;                   //Status_Taste Invertieren

      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Zrug");   //Taste anzeigen gedrückt

/* Das wird ausgeführt sobald die Zrug Taste betätigt wird */

        if (Status_Taste)
        {

        Menue_angewaehlt = 0;                         //Menü angewählt zurücksetzen

        Bild_aufgebaut[0] = false;                    //Bildschirm aufgebaut0 zurücksetzen
        }
      }
    }
}
