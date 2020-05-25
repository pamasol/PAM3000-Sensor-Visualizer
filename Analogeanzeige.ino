void Analogeanzeige()
{

  Displaystopp = true;                        //Displaystopp setzen


    if (Bild_aufgebaut[6] == false)           //Überwachung Bildschirm aufgebaut
    {

    Display.gfx_Cls();                        //Display löschen

    Display.gfx_Button(Status_Taste, 40, 10, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Analogeanzeige");   //Funktion Namen anzeigen

    Status_Taste = BUTTON_UP;

    Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Zrug");           //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 350, 400, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                       //Taste anzeigen ungedrückt
    Display.gfx_Rectangle(10, 70, 790, 280, AQUA);                                                                                //Rahmen zeichnen (Rechteck x1,y1,x2,y2)
    //Display.gfx_Rectangle(10, 70, 790, 310, AQUA);
    
    Display.txt_Height(3);                     //Texthöhe
    Display.txt_Width(3);                      //Textweite
    Display.txt_Inverse(OFF);                  //Text invetieren
    Display.txt_Bold(OFF);
    Display.txt_Set(TEXT_COLOUR, WHITE);       //Textfarbe Weiss
    Display.gfx_MoveTo(200, 100);              //Text Position x,y
    Display.print("Spannung: ");
    Display.print("0.00");                     //Wert Anzeigen
    Display.print(" V    ");
    Display.gfx_MoveTo(200, 150);              //Text Position x,y
    Display.print("Strom   : ");
    Display.print("0.00");                     //Wert Anzeigen
    Display.print(" mA    ");
    Display.gfx_MoveTo(200, 200);              //Text Position x,y
    Display.print("Leistung: ");
    Display.print("0.00");                     //Wert Anzeigen
    Display.print(" W     ");

/*  Display.gfx_MoveTo(200, 250);              //Text Position x,y
    Display.print("Druck   : ");
    Display.print("0.00");                      //Wert Anzeigen
    Display.print(" Bar     ");
*/

    Bild_aufgebaut[6] = true;                  //Bildschirm aufgebaut6 setzen

    current = 0;
    }

    if ((sensor219.getCurrent_mA()>=current+0.5)||(sensor219.getCurrent_mA()<=current-0.5)||(sensor219.getBusVoltage_V()>=busVoltage+0.5)||(sensor219.getBusVoltage_V()<=busVoltage-0.5))   
    {
    
    Max_Bar = 10;                              //Wert eintragen von Max Bar Wert bei Sensor
    Max_mA = 20;                               //Wert eintragen vom Max Strom ausgabe von Sensor
    Min_mA = 4;                                //Wert eintragen von Min Strom ausgabe von Sensor
  
    busVoltage = sensor219.getBusVoltage_V();  //Ausgabe Sensorwert
    current = sensor219.getCurrent_mA();       //Ausgabe Sensorwert
    power = busVoltage * (current/1000);       //Leistng Ausrechnen

/* DruckSensor kann in Display Ausgabe eingesetzt werden, wenn gebraucht*/
    
    DruckSensor = ((current-Min_mA)*Max_Bar/(Max_mA-Min_mA));       //Variable für Druck Sensor. Werte einzugeben, Max Bar, Max Strom, Min Strom

    Display.txt_Height(3);                     //Texthöhe
    Display.txt_Width(3);                      //Textweite
    Display.txt_Inverse(OFF);                  //Text invetieren
    Display.txt_Bold(OFF);
    Display.txt_Set(TEXT_COLOUR, WHITE);       //Textfarbe Weiss
    Display.gfx_MoveTo(200, 100);              //Text Position x,y
    Display.print("Spannung: ");
    Display.print(busVoltage);                 //Wert Anzeigen
    Display.print(" V    ");
    Display.gfx_MoveTo(200, 150);              //Text Position x,y
    Display.print("Strom   : ");
    Display.print(current);                    //Wert Anzeigen
    Display.print(" mA    ");
    Display.gfx_MoveTo(200, 200);              //Text Position x,y
    Display.print("Leistung: ");
    Display.print(power);                      //Wert Anzeigen
    Display.print(" W     ");

/*  Display.gfx_MoveTo(200, 250);              //Text Position x,y
    Display.print("Druck   : ");
    Display.print(DruckSensor);                //Wert Anzeigen
    Display.print(" Bar     ");
*/
    }   
     
    Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen

 
    if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))    //Überwachung Touch gedrückt oder bewegt
    {

    X_Pos = Display.touch_Get(TOUCH_GETX);     //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);     //Y Position auslesen
    }

    if (Status_Display == TOUCH_RELEASED)      //Überwachung Touch Freigabe
    {

/* Hier wir nach der Zrug Taste abgefragt */

      if ((X_Pos >= 620) && (X_Pos <= 790) && (Y_Pos >= 370) && (Y_Pos <= 430))   //Überwachung Touch Feld
      {

      Status_Taste = !Status_Taste;                                               //Status_Taste Invertieren

      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Zrug");   //Taste anzeigen gedrückt

/* Das wird ausgeführt sobald die Zrug Taste betätigt wird */

        if (Status_Taste)
        {

        Menue_angewaehlt = 0;                  //Menü angewählt (0)

        Bild_aufgebaut[0] = false;             //Bildschirm aufgebaut0 zurücksetzen
        }
      }

/* Hier wir nach der Reset Taste abgefragt */

      if ((X_Pos >= 320) && (X_Pos <= 500) && (Y_Pos >= 370) && (Y_Pos <= 430))   //Überwachung Touch Feld
      {

      Status_Taste = !Status_Taste;                                               //Status_Taste Invertieren
      
      Display.gfx_Button(Status_Taste, 350, 400, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET");                   //Taste anzeigen gedrückt
      
/* Das wird ausgeführt sobald die Reset Taste betätigt wird */

        if (Status_Taste)
        {
          
        Menue_angewaehlt = 3;                 //Menü angewählt (3)
        
        Bild_aufgebaut[6] = false;            //Bildschirm aufgebaut6 zurücksetzen
        }
      }
    }  
}
