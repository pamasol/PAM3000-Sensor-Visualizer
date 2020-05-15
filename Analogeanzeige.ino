void Analogeanzeige()

{

  Displaystopp = true;

  if (Bild_aufgebaut[6] == false) //Überwachung Bildschirm aufgebaut

   {

    Display.gfx_Cls();                //Display löschen

    Display.gfx_Button(Status_Taste, 40, 10, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Analogeanzeige");

    Status_Taste = BUTTON_UP;

    Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen ungedrückt
    Display.gfx_Button(Status_Taste, 350, 400, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset"); //Taste anzeigen ungedrückt
    Display.gfx_Rectangle(10, 70, 790, 280, AQUA); //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    

    Bild_aufgebaut[6] = true;                   //Bildschirm aufgebaut setzen

    

  }

  

  DruckSensor = 0;
  Max_Bar = 10;
  Max_mA = 20;
  Min_mA = 4;
  
  busVoltage = sensor219.getBusVoltage_V();
  current = sensor219.getCurrent_mA();
  power = busVoltage * (current/1000); // Calculate the Power

  DruckSensor = ((current-Min_mA)*(Max_Bar/(Max_mA-Min_mA)));       //Variable für Druck Sensor. Werte einzugeben, Max Bar, Max Strom, Min Strom

   Display.txt_Height(3);                        //Texthöhe
   Display.txt_Width(3);                         //Textweite
   Display.txt_Inverse(OFF);                     //Text invetieren
   Display.txt_Bold(OFF);
   Display.txt_Set(TEXT_COLOUR, WHITE);
   Display.gfx_MoveTo(200, 100);        //Text Position x,y
   Display.print("Spannung: ");
   Display.print(busVoltage);          //Wert Anzeigen
   Display.print(" V    ");
   Display.gfx_MoveTo(200, 150);                 //Text Position x,y
   Display.print("Strom   : ");
   Display.print(current);          //Wert Anzeigen
   Display.print(" mA    ");
   Display.gfx_MoveTo(200, 200);                 //Text Position x,y
   Display.print("Leistung: ");
   Display.print(power);          //Wert Anzeigen
   Display.print(" W     ");
   
     
    
    Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen

  

  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING)) //Überwachung Touch gedrückt oder bewegt

  {

    X_Pos = Display.touch_Get(TOUCH_GETX);    //X Position auslesen
    Y_Pos = Display.touch_Get(TOUCH_GETY);    //Y Position auslesen

  }


  //Touch Schalter auswertung


  if (Status_Display == TOUCH_RELEASED)                       //Überwachung Touch Freigabe

  {

    
    //Touch Feld Zurück


    if ((X_Pos >= 620) && (X_Pos <= 790) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;

      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Zrug"); //Taste anzeigen gedrückt


      //Menü Hauptmenü anwählen


      if (Status_Taste)

      {

        Menue_angewaehlt = 0;        //Menü anwählen

        Bild_aufgebaut[0] = false;  //Bildschirm aufgebaut zurücksetzen

      }

    }
     if ((X_Pos >= 320) && (X_Pos <= 500) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld

    {

      Status_Taste = !Status_Taste;
      
      Display.gfx_Button(Status_Taste, 350, 400, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET"); //Taste anzeigen gedrückt
      

      if (Status_Taste)

      {
        Menue_angewaehlt = 3;        //Menü anwählen
        Bild_aufgebaut[6] = false;  //Bildschirm aufgebaut zurücksetzen
      }



    }
 
  }  
}
