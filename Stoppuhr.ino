/* Im void Stoppuhr wird nur das Display aufgebaut. Die funktion der Zeit messung ist im void Loop Case 6 und 7. */

void Stoppuhr()

{

  Stoppuhrinterrupt = true;

  Displaystopp = true;

/* Hier wird der Displayhintergrund aufgebaut */  

    if (Bild_aufgebaut[1] == false)     //Überwachung Bildschirm aufgebaut
    {
      
      Display.gfx_Cls();                //Display löschen
      
      Display.gfx_Button(Status_Taste, 40, 10, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Stoppuhr");   //Funktion Namen anzeigen
  
      Status_Taste = BUTTON_UP;
  
      Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund, Textfarbe, Schrifttyp, Textbreite, Textrahmen, "Zrug");     //Taste anzeigen ungedrückt
      Display.gfx_Button(Status_Taste, 350, 400, YELLOW, BLACK, Schrifttyp, Textbreite, Textrahmen, "Reset");                 //Taste anzeigen ungedrückt
      Display.gfx_Rectangle(10, 70, 790, 200, AQUA);                                                                          //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
      Display.gfx_CircleFilled(40, 120, 20, RED);                                                                             //Status Anzeigen roter Punkt (Kreis x,y,r)
      Display.gfx_Rectangle(10, 330, 790, 200, AQUA);                                                                         //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
      Display.gfx_CircleFilled(40, 250, 20, RED);                                                                             //Status Anzeigen roter Punkt (Kreis x,y,r)
  
      Bild_aufgebaut[1] = true;                         //Bildschirm aufgebaut setzen
  
    }

  Status_Display = Display.touch_Get(TOUCH_STATUS);     //Status Touch Screen

/* Hier werden alle anzeigabre werte als 0 angezeigt. Solange kein Wert von Stoppuhr 1 oder 2 angegeben wird. 
   Reset1 wird gebraucht für die Reset Taste und die Zrug Taste */

    if ((Stop_Zeit_Stoppuhr[0]== 0) && (Zeiten_Stoppuhr_2[0]== 0) && (Reset1 == true))
    {
  
      for (int i = 0; i <= 9; i++)
      {
            Zeiten_Stoppuhr_1[i] = 0;     //Zeiten Stoppuhr 1 0-9 zurücksetzen
            Zeiten_Stoppuhr_2[i] = 0;     //Zeiten Stoppuhr 2 0-9 zurücksetzen
      }
          
          Display.txt_Height(2);          //Texthöhe
          Display.txt_Width(2);           //Textweite
          Display.gfx_MoveTo(580, 100);   //Text Position x,y
          Display.print("00");            //Anfangswert Anzeigen
          Display.print(" ms    ");
          Display.gfx_MoveTo(580, 125);   //Text Position x,y
          Display.print("00");            //Anfangswert Anzeigen
          Display.print(" ms    ");
          Display.gfx_MoveTo(580, 150);   //Text Position x,y
          Display.print("00");            //Anfangswert Anzeigen
          Display.print(" ms    ");
  
          Display.txt_Height(4);                       //Texthöhe
          Display.txt_Width(3);                        //Textweite
          Display.txt_Inverse(OFF);                    //Text invetieren
          Display.txt_Bold(OFF);
          Display.txt_Set(TEXT_COLOUR, WHITE);         //Textfarbe Weiss
          Display.gfx_MoveTo(80, 100);                 //Text Position x,y
          Display.print("");
          Display.print("000");                        //Anfangswert Anzeigen
          Display.print(" ms       ");
  
          Display.txt_Height(2);                       //Texthöhe
          Display.txt_Width(2);                        //Textweite
          Display.gfx_MoveTo(80, 150);                 //Text Position x,y
          Display.print("0");                          //Anfangswert Anzeigen
          Display.print(" : ");             
          Display.print("0");                          //Anfangswert Anzeigen
          Display.print(" : ");
          Display.print("0");                          //Anfangswert Anzeigen
          Display.print("      ");
  
          Display.txt_Height(2);                       //Texthöhe
          Display.txt_Width(2);                        //Textweite
          Display.gfx_MoveTo(580, 225);                //Text Position x,y
          Display.print("00");                         //Anfangswert Anzeigen
          Display.print(" ms    ");
          Display.gfx_MoveTo(580, 250);                //Text Position x,y
          Display.print("00");                         //Anfangswert Anzeigen
          Display.print(" ms    ");
          Display.gfx_MoveTo(580, 275);                //Text Position x,y
          Display.print("00");                         //Anfangswert Anzeigen
          Display.print(" ms    ");
  
          Display.txt_Height(4);                       //Texthöhe
          Display.txt_Width(3);                        //Textweite
          Display.txt_Inverse(OFF);                    //Text invetieren
          Display.txt_Bold(OFF);
          Display.txt_Set(TEXT_COLOUR, WHITE);         //Textfarbe Weiss
          Display.gfx_MoveTo(80, 230);                 //Text Position x,y
          Display.print("");
          Display.print("000");                        //Anfangswert Anzeigen 
          Display.print(" ms       ");
          
          Display.txt_Height(2);                       //Texthöhe 
          Display.txt_Width(2);                        //Textweite
          Display.gfx_MoveTo(80, 280);                 //Text Position x,y
          Display.print("0");                          //Anfangswert Anzeigen
          Display.print(" : ");
          Display.print("0");                          //Anfangswert Anzeigen
          Display.print(" : ");
          Display.print("0");                          //Anfangswert Anzeigen
          Display.print("      ");
  
          Reset1 = false;
          
          }


      if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))  //Überwachung Touch gedrückt oder bewegt
    
      {
        X_Pos = Display.touch_Get(TOUCH_GETX);                                    //X Position auslesen
        Y_Pos = Display.touch_Get(TOUCH_GETY);                                    //Y Position auslesen
      }


      if (Status_Display == TOUCH_RELEASED)                                       //Überwachung Touch Freigabe
      {
    
/* Hier wir nach der Zrug Taste abgefragt */
        
        if ((X_Pos >= 620) && (X_Pos <= 790) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld^
        {
   
          Status_Taste = !Status_Taste;
          
          Display.gfx_Button(Status_Taste, 650, 400, Texthintergrund_2, Textfarbe_2, Schrifttyp, Textbreite, Textrahmen, "Zrug");  //Zurücktaste anzeigen gedrückt
    
/* Das wird ausgeführt sobald die Zrug Taste betätigt wird */
    
          if (Status_Taste)
          {
    
            Menue_angewaehlt = 0;          //Menü anwählen Hauptmenue
            
            Stop_Zeit_Stoppuhr[0]= 0;  
           
            Zeiten_Stoppuhr_2[0]= 0; 
    
            Reset1 = true;
    
            Bild_aufgebaut[0] = false;     //Bildschirm aufgebaut zurücksetzen    
          }
    
        }

/* Hier wir nach der Reset Taste abgefragt */

        if ((X_Pos >= 320) && (X_Pos <= 500) && (Y_Pos >= 370) && (Y_Pos <= 430)) //Überwachung Touch Feld    
        {
    
          Status_Taste = !Status_Taste;
    
          Display.gfx_Button(Status_Taste, 350, 400, YELLOW, WHITE, Schrifttyp, Textbreite, Textrahmen, "RESET");                  //Taste anzeigen gedrückt
    
/* Das wird ausgeführt sobald die Reset Taste betätigt wird */
    
          if (Status_Taste)   
          {
            
            Menue_angewaehlt = 1;         //Menü anwählen Stoppuhr
    
            Stop_Zeit_Stoppuhr[0]= 0;  
            
            Zeiten_Stoppuhr_2[0]= 0; 
    
            Reset1 = true;
    
            Bild_aufgebaut[1] = false;    //Bildschirm aufgebaut zurücksetzen
            
          }
          
        }     
        
      } 
}
