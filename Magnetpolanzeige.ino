void Magnetpolanzeige()
{

  int SensorValue = digitalRead(HALL_SENSOR);         //SensorValue auf digitalen Ausgang vom Hallsensor

  Displaystopp = true;


    if (Bild_aufgebaut[4] == false)                   //Überwachung Bildschirm aufgebaut
    {
  
      Display.gfx_Cls();                              //Display löschen

      Display.gfx_Button(Status_Taste, 40, 10, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Magnetpolanzeige");         //Funktion Namen anzeigen
  
      Status_Taste = BUTTON_UP;
  
      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Zrug");     //Taste anzeigen ungedrückt
      Display.gfx_Button(Status_Taste, 350, 400, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                 //Taste anzeigen ungedrückt
      Display.gfx_Rectangle(10, 70, 790, 200, AQUA);                                                                          //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
      Display.gfx_CircleFilled(40, 120, 20, RED);                                                                             //Status Anzeigen roter Punkt (Kreis x,y,r)
  
      Bild_aufgebaut[4] = true;                       //Bildschirm aufgebaut setzen
    }



/* Sobald der Hallsensor in die Nähe eines Südpols ist. Zeigt er LOW an und Südpol wird angezeigt. Ansonsten zeigt es Nordpol an. 
   Siehe Programm von Hersteller auf Beilage*/

    if(SensorValue == LOW)
  
    {
  
      Display.gfx_CircleFilled(40, 120, 20, GREEN);   //Status Anzeigen grüner Punkt (Kreis x,y,r)  
      Display.txt_Height(4);                          //Texthöhe  
      Display.txt_Width(3);                           //Textweite  
      Display.txt_Inverse(OFF);                       //Text invetieren  
      Display.txt_Bold(OFF);  
      Display.txt_Set(TEXT_COLOUR, WHITE);            //Textfarbe Weiss
      Display.gfx_MoveTo(80, 100);                    //Text Position x,y
  
      Display.print("  ");  
      Display.print("Suedpol");                       //Wert Anzeigen
    }

    else

    {

      Display.gfx_CircleFilled(40, 120, 20, RED);     //Status Anzeigen roter Punkt (Kreis x,y,r)
      Display.txt_Height(4);                          //Texthöhe
      Display.txt_Width(3);                           //Textweite
      Display.txt_Inverse(OFF);                       //Text invetieren
      Display.txt_Bold(OFF);
      Display.txt_Set(TEXT_COLOUR, WHITE);            //Textfarbe Weiss
      Display.gfx_MoveTo(80, 100);                    //Text Position x,y
      Display.print("  ");
      Display.print("Nordpol");                       //Wert Anzeigen

    }

  Status_Display = Display.touch_Get(TOUCH_STATUS);   //Status Touch Screen


    if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING)) //Überwachung Touch gedrückt oder bewegt
    {

    X_Pos = Display.touch_Get(TOUCH_GETX);                                      //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);                                      //Y Position auslesen
    }
    

  if (Status_Display == TOUCH_RELEASED)                                         //Überwachung Touch Freigabe
  {

/* Hier wir nach der Zrug Taste abgefragt */
   
    if ((X_Pos >= 620) && (X_Pos <= 790) && (Y_Pos >= 370) && (Y_Pos <= 430))   //Überwachung Touch Feld
    {

      Status_Taste = !Status_Taste;                   //Status_Taste Invertieren

      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Zrug");   //Taste anzeigen gedrückt

/* Das wird ausgeführt sobald die Zrug Taste betätigt wird */

      if (Status_Taste)
      {

        Menue_angewaehlt = 0;               //Menü anwählen

        Bild_aufgebaut[0] = false;          //Bildschirm aufgebaut zurücksetzen
      }
    }

/* Hier wir nach der Reset Taste abgefragt */

    if ((X_Pos >= 320) && (X_Pos <= 500) && (Y_Pos >= 370) && (Y_Pos <= 430))   //Überwachung Touch Feld
    {

      Status_Taste = !Status_Taste;                   //Status_Taste Invertieren

      Display.gfx_Button(Status_Taste, 350, 400, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET");                   //Taste anzeigen gedrückt

/* Das wird ausgeführt sobald die Reset Taste betätigt wird */

      if (Status_Taste)
      {

        Menue_angewaehlt = 4;               //Menü anwählen

        Bild_aufgebaut[4] = false;          //Bildschirm aufgebaut zurücksetzen
      }
    }
  }
}
