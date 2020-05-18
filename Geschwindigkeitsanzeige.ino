/* Diese Funktion startet sobal der Pin 8 oder 9 auf HIGH sind. 
   Die Funktion der Messung ist void Loop Case 8 und 9.*/

void Geschwindigkeitsanzeige()
{
  
  Displaystopp = true;                                //Displaystopp setzen
  Geschwingigkeitinterrupt = true;                    //Geschwingigkeitinterrupt setzen
  Geschwingigkeitinterrupt2 = true;                   //Geschwingigkeitinterrupt2 setzen

/* Hier wird der Displayhintergrund aufgebaut */ 
  
    if (Bild_aufgebaut[2] == false)                   //Überwachung Bildschirm aufgebaut
    {

    Display.gfx_Cls();                                //Display löschen

    Display.gfx_Button(Status_Taste, 40, 10, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Geschwindigkeitsanzeige");    //Funktion Namen anzeigen

    Status_Taste = BUTTON_UP;

    Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Zrug");   //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 350, 400, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");               //Taste anzeigen ungedrückt
    Display.gfx_Rectangle(10, 70, 790, 200, AQUA);                                                                        //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 120, 20, RED);                                                                           //Status Anzeigen roter Punkt (Kreis x,y,r)
    Display.gfx_Rectangle(10, 330, 790, 200, AQUA);                                                                       //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_CircleFilled(40, 250, 20, RED);                                                                           //Status Anzeigen roter Punkt (Kreis x,y,r)

    Bild_aufgebaut[2] = true;                         //Bildschirm aufgebaut2 setzen
    }

/* Hier werden die Zahlen und Werte als 0 angezeigt. Der Speicher wird auf 0 gesetzt */ 

    if ((Stopp_Zeit_Geschwindigkeit== 0) && (Stopp_Zeit_Geschwindigkeit2== 0) && (Reset2 == true))

    {

      for (int i = 0; i <= 9; i++)
      {

      Zeiten_Geschwindigkeit_1[i] = 0;                //Zeiten Geschwindigkeit 1 0-9 zurücksetzen
      Zeiten_Geschwindigkeit_2[i] = 0;                //Zeiten Geschwindigkeit 2 0-9 zurücksetzen 
      }
        
    Display.txt_Height(2);                            //Texthöhe
    Display.txt_Width(2);                             //Textweite
    Display.gfx_MoveTo(580, 100);                     //Text Position x,y
    Display.print("00");                              //Wert Anzeigen
    Display.print(" cpm    ");
    Display.gfx_MoveTo(580, 125);                     //Text Position x,y
    Display.print("00");                              //Wert Anzeigen
    Display.print(" cpm    ");
    Display.gfx_MoveTo(580, 150);                     //Text Position x,y
    Display.print("00");                              //Wert Anzeigen
    Display.print(" cpm    ");

    Display.txt_Height(4);                            //Texthöhe
    Display.txt_Width(3);                             //Textweite
    Display.txt_Inverse(OFF);                         //Text invetieren
    Display.txt_Bold(OFF);
    Display.txt_Set(TEXT_COLOUR, WHITE);              //Textfarbe Weiss
    Display.gfx_MoveTo(80, 100);                      //Text Position x,y
    Display.print("");
    Display.print("000");                             //Wert Anzeigen
    Display.print(" cpm       ");

    Display.txt_Height(2);                            //Texthöhe
    Display.txt_Width(2);                             //Textweite
    Display.gfx_MoveTo(580, 225);                     //Text Position x,y
    Display.print("00");                              //Wert Anzeigen
    Display.print(" cpm    ");
    Display.gfx_MoveTo(580, 250);                     //Text Position x,y
    Display.print("00");                              //Wert Anzeigen
    Display.print(" cpm    ");
    Display.gfx_MoveTo(580, 275);                     //Text Position x,y
    Display.print("00");                              //Wert Anzeigen
    Display.print(" cpm    ");

    Display.txt_Height(4);                            //Texthöhe
    Display.txt_Width(3);                             //Textweite
    Display.txt_Inverse(OFF);                         //Text invetieren
    Display.txt_Bold(OFF);
    Display.txt_Set(TEXT_COLOUR, WHITE);              //Textfarbe Weiss
    Display.gfx_MoveTo(80, 230);                      //Text Position x,y
    Display.print("");
    Display.print("000");                             //Wert Anzeigen
    Display.print(" cpm       ");

    Display.txt_Height(2);                            //Texthöhe
    Display.txt_Width(2);                             //Textweite
    Display.gfx_MoveTo(83, 160);                      //Text Position x,y
    Display.print("00");
    Display.print(" Hoechstwert  ");

    Display.txt_Height(2);                            //Texthöhe
    Display.txt_Width(2);                             //Textweite
    Display.gfx_MoveTo(83, 290);                      //Text Position x,y
    Display.print("00");
    Display.print(" Hoechstwert  ");

    Reset2 = false;                                   //Reset2 auf fasle setzen
    }

  Status_Display = Display.touch_Get(TOUCH_STATUS);   //Status Touch Screen


    if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))    //Überwachung Touch gedrückt oder bewegt
    {

    X_Pos = Display.touch_Get(TOUCH_GETX);            //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);            //Y Position auslesen
    }

    if (Status_Display == TOUCH_RELEASED)             //Überwachung Touch Freigabe

    {

/* Hier wir nach der Zrug Taste abgefragt */

      if ((X_Pos >= 620) && (X_Pos <= 790) && (Y_Pos >= 370) && (Y_Pos <= 430))   //Überwachung Touch Feld
      {

      Status_Taste = !Status_Taste;                                               //Status_Taste Invertieren

      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Zrug");  //Taste anzeigen gedrückt

/* Das wird ausgeführt sobald die Zrug Taste betätigt wird */

        if (Status_Taste)
        {

        Menue_angewaehlt = 0;                         //Menü anwählen
        Reset2 = true;                                //Reset2 setzen
        
        Bild_aufgebaut[0] = false;                    //Bildschirm aufgebaut0 zurücksetzen
        
        Stopp_Zeit_Geschwindigkeit = 0;               //Stopp_Zeit_Geschwindigkeit zurücksetzen
        Stopp_Zeit_Geschwindigkeit2 = 0;              //Stopp_Zeit_Geschwindigkeit2 zurücksetzen

        Hoechstwert = 0;                              //Hoechstwert zurücksetzen
        Hoechstwert2 = 0;                             //Hoechstwert2 zurücksetzen
        }

      }

/* Hier wir nach der Reset Taste abgefragt */

      if ((X_Pos >= 320) && (X_Pos <= 500) && (Y_Pos >= 370) && (Y_Pos <= 430))   //Überwachung Touch Feld
      {

      Status_Taste = !Status_Taste;                                               //Status_Taste Invertieren

      Display.gfx_Button(Status_Taste, 350, 400, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET");                  //Taste anzeigen gedrückt

/* Das wird ausgeführt sobald die Reset Taste betätigt wird */

        if (Status_Taste)
        {
        
        Menue_angewaehlt = 2;                         //Menü angewählt (2)

        Reset2 = true;                                //Reset2 setzen      

        Bild_aufgebaut[2] = false;                    //Bildschirm aufgebaut2 zurücksetzen
        
        Stopp_Zeit_Geschwindigkeit = 0;               //Stopp_Zeit_Geschwindigkeit zurücksetzen
        Stopp_Zeit_Geschwindigkeit2 = 0;              //Stopp_Zeit_Geschwindigkeit2 zurücksetzen

        Hoechstwert = 0;                              //Hoechstwert zurücksetzen
        Hoechstwert2 = 0;                             //Hoechstwert2 zurücksetzen
        }
      }
    }
}
