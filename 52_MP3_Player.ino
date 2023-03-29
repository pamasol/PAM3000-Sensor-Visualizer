/* 52.MP3 Player 

- MicroSD Format FAT16, FAT32, maximum 32GB
  Samplingrate 8, 11.025, 12, 16, 22.05, 24, 32, 44.1, 48kHz
  maxiumum 100 Verzeichnisse mit je maximum 255 Files.

*/

void MP3_Player(bool Bildaufbau, bool Werte_Reset)          //Funktion MP3 Player
{

/********************************************************************************************************************/

  /* Bildaufbau 
     Statischen Texte und Grafiken beim Bildaufau einmal darstellen,
     um die Display Geschwindigkeit zu erhöhen! */ 
  if (Bild_aufgebaut[52] == false)                    //Überwachung Bildschirm aufgebaut
  {   
    Display.gfx_Cls();            //Display löschen
    Statusanzeige();              //Aufruf Funktion Statusanzeige
    
    /* Titel anzeigen */
    Display.gfx_Button(Status_Touch_Taste, 0, 38, Texthintergrund_Menue, Textfarbe_Menue, Schrifttyp, Textbreite, Textrahmen, "MP3 Player");  //Funktion Namen anzeigen

    /* Touch Screen handling */
    Display.touch_Set(TOUCH_ENABLE);
    Status_Touch_Taste = BUTTON_UP; 
    
    /* Touch Tasten ungedrückt anzeigen */
    Status_Touch_Taste = BUTTON_UP;   
    Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, WHITE, Schrifttyp, Textbreite, Textrahmen, "i");                                         //Taste anzeigen gedrückt

    Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_Taster, Textfarbe_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");         //Taste anzeigen ungedrückt        
    Display.gfx_Button(Status_Touch_Taste, 105, 200, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");                                       //Taste anzeigen ungedrückt (+ Lautstärke)
    Display.gfx_Button(Status_Touch_Taste, 200, 200, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");                                       //Taste anzeigen ungedrückt (- Lautstärke)
    Display.gfx_Button(Status_Touch_Taste, 360, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Zufall");                                    //Taste anzeigen ungedrückt (Wiederholung zufall)

    /* Lautstärke */
    Display.gfx_Slider(0, 110, 160, 250, 180, BLUE, 30, MP3_Lautstaerke);           //Slider Lautstärker (Modus, x, y, x2, y2, Farbe, Max Wert, Aktueller Wert)

    /* Playlist */
    switch(Playlist)               //Playlist anzeige
    {
      /*Rock */
      case 0:
        Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Rock    ");      //Taste anzeigen ungedrückt        
        break;
          
      /* Pop */
      case 1:
        Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Pop     ");      //Taste anzeigen ungedrückt
        break;

      /* Jazz */
      case 2:
        Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Jazz    ");      //Taste anzeigen ungedrückt
        break;

      /* Classic */
      case 3:
        Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Country ");      //Taste anzeigen ungedrückt
        break;    

      /* Mix */
      case 4:
        Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Mix     ");      //Taste anzeigen ungedrückt
        break;    
    }

    /* Equalizer */
    switch(Equalizer)               //Überwachen letztes Menü
    {
      /* Normal */
      case 0:          
        DFMP3_Player.EQ(DFPLAYER_EQ_NORMAL);
        Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Normal  ");      //Taste anzeigen ungedrückt       
        break;

      /* Pop */
      case 1:
        DFMP3_Player.EQ(DFPLAYER_EQ_POP);
        Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Pop     ");      //Taste anzeigen ungedrückt
        break;

      /*Rock */
      case 2:
        DFMP3_Player.EQ(DFPLAYER_EQ_ROCK);
        Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Rock    ");      //Taste anzeigen ungedrückt           
        break;

      /* Jazz */
      case 3:
        DFMP3_Player.EQ(DFPLAYER_EQ_JAZZ);
        Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Jazz    ");      //Taste anzeigen ungedrückt
        break;

      /* Classic */
      case 4:
        DFMP3_Player.EQ(DFPLAYER_EQ_CLASSIC);
        Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Classic ");      //Taste anzeigen ungedrückt
        break;

      /* Bass */        
      case 5:
        DFMP3_Player.EQ(DFPLAYER_EQ_BASS);
        Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Bass    ");      //Taste anzeigen ungedrückt
        break;
    }

    Display.txt_Height(2);                      //Texthöhe
    Display.txt_Width(2);                       //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);    //Textfarbe
    Display.txt_Inverse(OFF);                   //Text invetieren
    Display.txt_Bold(OFF);                      //Text fett

    Display.gfx_MoveTo(110, 120);               //Text Position (x,y)
    Display.print("Lautstaerke");               //Text anzeigen

    Display.gfx_MoveTo(520, 120);               //Text Position (x,y)
    Display.print("Play");                      //Text anzeigen

    Display.gfx_MoveTo(110, 270);               //Text Position (x,y)
    Display.print("Playlist");                  //Text anzeigen
    
    Display.gfx_MoveTo(110, 370);               //Text Position (x,y)
    Display.print("Equalizer");                 //Text anzeigen

    Display.gfx_MoveTo(490, 270);               //Text Position (x,y)
    Display.print("Lied Nr: ");                 //Aktuelle File Nummer anzeigen

    Display.gfx_MoveTo(540, 310);               //Text Position (x,y)
    Display.print(MP3_File_Nr);                 //Aktuelle MP3 File Nummer anzeigen
    Display.print("    "); 
          
    /* Grafik anzeigen */
    Display.gfx_Circle(767, 30, 22, WHITE);                                   //Info Kreis zeichnen (Kreis x,y,r)
    if (MP3_aktiv == false) Display.gfx_CircleFilled(550, 200, 40, BLUE);     //MP3 Player auf Pause, Play Kreis zeichnen (Kreis x,y,r)
    if (MP3_aktiv == true) Display.gfx_CircleFilled(550, 200, 40, GREEN);     //MP3 Player auf Play, Play Kreis zeichnen (Kreis x,y,r)
      
    Display.gfx_Circle(550, 200, 40, WHITE);                                //Play Kreis zeichnen (Kreis x,y,r)
    Display.gfx_Triangle(530, 185, 530, 215, 560, 200, WHITE);              //Dreieck Play zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_Line(565, 185, 565, 215, WHITE);                            //Pause Linie zeichnen (Linie x1,y1,x2,y2)
    Display.gfx_Line(575, 185, 575, 215, WHITE);                            //Pause Linie zeichnen (Linie x1,y1,x2,y2)
       
    Display.gfx_TriangleFilled(620, 170, 620, 230, 660, 200, BLUE);         //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_Triangle(620, 170, 620, 230, 660, 200, WHITE);              //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_TriangleFilled(480, 170, 480, 230, 440, 200, BLUE);         //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_Triangle(480, 170, 480, 230, 440, 200, WHITE);              //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)

    /* Playlist Graphik */
    Display.gfx_TriangleFilled(260, 300, 260, 340, 300, 320, BLACK);        //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_Triangle(260, 300, 260, 340, 300, 320, WHITE);              //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_TriangleFilled(100, 300, 100, 340, 60, 320, BLACK);         //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_Triangle(100, 300, 100, 340, 60, 320, WHITE);               //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)
    
    /* Equalizer Graphik */
    Display.gfx_TriangleFilled(260, 400, 260, 440, 300, 420, BLACK);        //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_Triangle(260, 400, 260, 440, 300, 420, WHITE);              //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_TriangleFilled(100, 400, 100, 440, 60, 420, BLACK);         //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)
    Display.gfx_Triangle(100, 400, 100, 440, 60, 420, WHITE);               //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)
    
    Bild_aufgebaut[52] = true;                                            //Bildschirm aufgebaut setzen
  }

/********************************************************************************************************************/
  
  Statusanzeige();              //Aufruf Funktion Statusanzeige
  
/********************************************************************************************************************/

  /* Aktuelle MP3 File Nummer auslesen 
     Alle Sekunden aktuelle MP3 File Nummer auslesen   
  */
  if (millis() >= (letzte_millis_MP3_File_Nr + 1000))  //Überwachung Intervall
  {
    letzte_millis_MP3_File_Nr = millis();      //Letzter Wert speichern

    /* Aktuelle MP3 File Nummer auslesen  */
    if (MP3_File_Nr != DFMP3_Player.readCurrentFileNumber())
    {
      MP3_File_Nr = DFMP3_Player.readCurrentFileNumber();       //MP3 File Nummer auslesen
    
      Display.txt_Height(2);                                    //Texthöhe
      Display.txt_Width(2);                                     //Textweite
      Display.txt_Set(TEXT_COLOUR, Textfarbe);                  //Textfarbe
      Display.txt_Inverse(OFF);                                 //Text invetieren
      Display.txt_Bold(OFF);                                    //Text fett

      Display.gfx_MoveTo(540, 310);                             //Text Position (x,y)
      Display.print(MP3_File_Nr);                               //Aktuelle MP3 File Nummer anzeigen
      Display.print("    ");   
    }
  }
  
/********************************************************************************************************************/

  /* Doppeltaste Goto */
  Doppeltaste_Betaetigt:                     //Doppeltaste Goto
  
  /* Touch Screen handling */
  Status_Display = Display.touch_Get(TOUCH_STATUS);    //Status Touch Screen

  /* Touch Positionen auslesen */
  if ((Status_Display == TOUCH_PRESSED) || (Status_Display == TOUCH_MOVING))      //Überwachung Touch gedrückt oder bewegt
  {
    X_Pos_Touch = Display.touch_Get(TOUCH_GETX);            //X Position auslesen
    Y_Pos_Touch = Display.touch_Get(TOUCH_GETY);            //Y Position auslesen
  }

  /* Touch Freigabe */
  if (Status_Display == TOUCH_RELEASED)                     //Überwachung Touch Freigabe
  {

/********************************************************************************************************************/
    
    /* Touch Feld abfragen [Zrugg] Taste gedrückt */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 750) && (Y_Pos_Touch >= 390) && (Y_Pos_Touch <= 450))     //Überwachung Touch Feld
    {
      /* Touch Feld [Zrugg] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 650, 420, Texthintergrund_2_Taster, Textfarbe_2_Taster, Schrifttyp, Textbreite, Textrahmen, "Zrugg");   //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                                    //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 50;                          //Hauptmenü anwählen
        Bild_aufgebaut[50] = false;                     //Bildschirm aufgebaut zurücksetzen
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [-] Taste gedrückt (Lautstärke) */
    if ((X_Pos_Touch >= 100) && (X_Pos_Touch <= 190) && (Y_Pos_Touch >= 170) && (Y_Pos_Touch <= 230))     //Überwachung Touch Feld
    {
      /* Touch Feld [-] Taste ausführen (Lautstärke) */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 110, 200, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen gedrückt

        /* Lautstärke */
        MP3_Lautstaerke--;
        if (MP3_Lautstaerke <= 1) MP3_Lautstaerke = 1;      //Verstellwert begrenzen
        DFMP3_Player.volume(MP3_Lautstaerke);               //Lautstärke 0-30
        Display.gfx_Slider(0, 110, 160, 250, 180, BLUE, 30, MP3_Lautstaerke);           //Slider Lautstärker (Modus, x, y, x2, y2, Farbe, Max Wert, Aktueller Wert)
        
        /* Buzzer */
        Buzzer(100);                                        //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 110, 200, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " - ");   //Taste anzeigen ungedrückt          
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [+] Taste gedrückt (Lautstärke) */
    if ((X_Pos_Touch >= 190) && (X_Pos_Touch <= 280) && (Y_Pos_Touch >= 170) && (Y_Pos_Touch <= 230))     //Überwachung Touch Feld
    {
      /* Touch Feld [+] Taste ausführen (Lautstärke) */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 200, 200, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen gedrückt

        /* Lautstärke */
        MP3_Lautstaerke++;
        if (MP3_Lautstaerke >= 30) MP3_Lautstaerke = 30;      //Verstellwert begrenzen
        DFMP3_Player.volume(MP3_Lautstaerke);                 //Lautstärke 0-30        
        Display.gfx_Slider(0, 110, 160, 250, 180, BLUE, 30, MP3_Lautstaerke);           //Slider Lautstärker (Modus, x, y, x2, y2, Farbe, Max Wert, Aktueller Wert)

        /* Buzzer */
        Buzzer(100);                                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 200, 200, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " + ");   //Taste anzeigen ungedrückt         
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Zufall] Taste gedrückt (Wiederholen zufall) */
    if ((X_Pos_Touch >= 330) && (X_Pos_Touch <= 460) && (Y_Pos_Touch >= 375) && (Y_Pos_Touch <= 435))     //Überwachung Touch Feld
    {
      /* Touch Feld [Zufall] Taste ausführen (Wiederholen zufall) */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 360, 405, BLUE, BLACK, Schrifttyp, Textbreite, Textrahmen, "Zufall");   //Taste anzeigen gedrückt

        MP3_Zufall_aktiv = true;              //MP3 Zufall setzen
        DFMP3_Player.randomAll();             //Zufallsgenerator alle Files
        
        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Button(Status_Touch_Taste, 360, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, "Zufall");   //Taste anzeigen ungedrückt          
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Play] Taste gedrückt (Abspielen) */
    if ((MP3_aktiv == false) && (X_Pos_Touch >= 530) && (X_Pos_Touch <= 590) && (Y_Pos_Touch >= 180) && (Y_Pos_Touch <= 220))     //Überwachung Touch Feld
    {
      /* Touch Feld [Play] Taste ausführen (Abspielen) */
      if (Status_Touch_Taste)
      {
        Display.gfx_CircleFilled(550, 200, 40, GREEN);                        //Play Kreis zeichnen (Kreis x,y,r)              
        Display.gfx_Circle(550, 200, 40, BLACK);                             //Play Kreis zeichnen (Kreis x,y,r)
        Display.gfx_Triangle(530, 185, 530, 215, 560, 200, BLACK);           //Dreieck Play zeichnen (x, y, x2, y2, x3, y3, Farbe)
        Display.gfx_Line(565, 185, 565, 215, BLACK);                         //Pause Linie zeichnen (Linie x1,y1,x2,y2)
        Display.gfx_Line(575, 185, 575, 215, BLACK);                         //Pause Linie zeichnen (Linie x1,y1,x2,y2)
     
        MP3_aktiv = true;                       //MP3 aktiv setzen       
        DFMP3_Player.start();                   //MP3 Start
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

        Display.gfx_Circle(550, 200, 40, WHITE);                             //Play Kreis zeichnen (Kreis x,y,r)
        Display.gfx_Triangle(530, 185, 530, 215, 560, 200, WHITE);           //Dreieck Play zeichnen (x, y, x2, y2, x3, y3, Farbe)
        Display.gfx_Line(565, 185, 565, 215, WHITE);                         //Pause Linie zeichnen (Linie x1,y1,x2,y2)
        Display.gfx_Line(575, 185, 575, 215, WHITE);                         //Pause Linie zeichnen (Linie x1,y1,x2,y2)
        
        /* Doppeltaste Auschaltverhinderung bis erneut gedrückt */
        goto Doppeltaste_Betaetigt;       //Doppeltaste betätigt      
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [Stopp] Taste gedrückt (Pause) */
    if ((MP3_aktiv == true) && (X_Pos_Touch >= 530) && (X_Pos_Touch <= 590) && (Y_Pos_Touch >= 180) && (Y_Pos_Touch <= 220))     //Überwachung Touch Feld
    {
      /* Touch Feld [Stopp] Taste ausführen (Pause) */
      if (Status_Touch_Taste)
      {
        Display.gfx_CircleFilled(550, 200, 40, BLUE);                        //Play Kreis zeichnen (Kreis x,y,r
        Display.gfx_Circle(550, 200, 40, BLACK);                             //Play Kreis zeichnen (Kreis x,y,r)
        Display.gfx_Triangle(530, 185, 530, 215, 560, 200, BLACK);           //Dreieck Play zeichnen (x, y, x2, y2, x3, y3, Farbe)
        Display.gfx_Line(565, 185, 565, 215, BLACK);                         //Pause Linie zeichnen (Linie x1,y1,x2,y2)
        Display.gfx_Line(575, 185, 575, 215, BLACK);                         //Pause Linie zeichnen (Linie x1,y1,x2,y2)
        
        MP3_aktiv = false;                  //MP3 aktiv zurücksetzen 
        DFMP3_Player.pause();               //MP3 Pause
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

        Display.gfx_Circle(550, 200, 40, WHITE);                             //Play Kreis zeichnen (Kreis x,y,r)
        Display.gfx_Triangle(530, 185, 530, 215, 560, 200, WHITE);           //Dreieck Play zeichnen (x, y, x2, y2, x3, y3, Farbe)
        Display.gfx_Line(565, 185, 565, 215, WHITE);                         //Pause Linie zeichnen (Linie x1,y1,x2,y2)
        Display.gfx_Line(575, 185, 575, 215, WHITE);                         //Pause Linie zeichnen (Linie x1,y1,x2,y2)
        
        /* Doppeltaste Auschaltverhinderung bis erneut gedrückt */
        goto Doppeltaste_Betaetigt;       //Doppeltaste betätigt     
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [<] Taste gedrückt (Next) */
    if ((X_Pos_Touch >= 420) && (X_Pos_Touch <= 480) && (Y_Pos_Touch >= 150) && (Y_Pos_Touch <= 250))     //Überwachung Touch Feld
    {
      /* Touch Feld [<] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Triangle(480, 170, 480, 230, 440, 200, BLACK);           //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)
        
        DFMP3_Player.previous();              //Play next mp3
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)  

        Display.gfx_Triangle(480, 170, 480, 230, 440, 200, WHITE);           //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [>] Taste gedrückt (Next) */
    if ((X_Pos_Touch >= 620) && (X_Pos_Touch <= 680) && (Y_Pos_Touch >= 150) && (Y_Pos_Touch <= 250))     //Überwachung Touch Feld
    {
      /* Touch Feld [>] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Triangle(620, 170, 620, 230, 660, 200, BLACK);           //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)

        DFMP3_Player.next();                  //Play next mp3
  
        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)   

        Display.gfx_Triangle(620, 170, 620, 230, 660, 200, WHITE);           //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [< Playlist] Taste gedrückt */
    if ((X_Pos_Touch >= 40) && (X_Pos_Touch <= 120) && (Y_Pos_Touch >= 280) && (Y_Pos_Touch <= 360))     //Überwachung Touch Feld
    {
      /* Touch Feld [< Playlist] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Triangle(100, 300, 100, 340, 60, 320, BLACK);           //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)
        
        Playlist--;                             //Playlist runter zählen
        if (Playlist < 0) Playlist = 4;         //Verstellwert begrenzen

        switch(Playlist)                        //Überwachen letztes Menü
        {
          /*Rock */
          case 0:
            DFMP3_Player.loopFolder(1);  //play mp3; Folder Name(1~99); File Name(1~255)
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Rock    ");      //Taste anzeigen ungedrückt         
            break;
          
          /* Pop */
          case 1:
            DFMP3_Player.loopFolder(2);  //play mp3; Folder Name(1~99); File Name(1~255)
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Pop     ");      //Taste anzeigen ungedrückt
            break;

          /* Jazz */
          case 2:
            DFMP3_Player.loopFolder(3);  //play mp3; Folder Name(1~99); File Name(1~255)
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Jazz    ");      //Taste anzeigen ungedrückt
            break;

          /* Classic */
          case 3:
            DFMP3_Player.loopFolder(4);  //play mp3; Folder Name(1~99); File Name(1~255)
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Cauntry ");      //Taste anzeigen ungedrückt
            break;

          /* Mix */
          case 4:
            DFMP3_Player.loopFolder(5);  //play mp3; Folder Name(1~99); File Name(1~255)
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Mix     ");      //Taste anzeigen ungedrückt
            break;                
        }
          
        /* Buzzer */
        Buzzer(100);                                                        //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Display.gfx_Triangle(100, 300, 100, 340, 60, 320, WHITE);           //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)  
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [> Playlist] Taste gedrückt */
    if ((X_Pos_Touch >= 240) && (X_Pos_Touch <= 320) && (Y_Pos_Touch >= 280) && (Y_Pos_Touch <= 360))     //Überwachung Touch Feld
    {
      /* Touch Feld [> Playlist] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Triangle(260, 300, 260, 340, 300, 320, BLACK);           //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)

        Playlist++;                         //Playlist hoch zählen
        if (Playlist > 4) Playlist = 0;     //Verstellwert begrenzen  
        
        switch(Playlist)                    //Überwachen letztes Menü
        {
          /*Rock */
          case 0:
            DFMP3_Player.loopFolder(1);  //play mp3; Folder Name(1~99); File Name(1~255)
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Rock    ");      //Taste anzeigen ungedrückt          
            break;
          
          /* Pop */
          case 1:
            DFMP3_Player.loopFolder(2);  //play mp3; Folder Name(1~99); File Name(1~255)
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Pop     ");      //Taste anzeigen ungedrückt
            break;

          /* Jazz */
          case 2:
            DFMP3_Player.loopFolder(3);  //play mp3; Folder Name(1~99); File Name(1~255)
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Jazz    ");      //Taste anzeigen ungedrückt
            break;

          /* Classic */
          case 3:
            DFMP3_Player.loopFolder(4);  //play mp3; Folder Name(1~99); File Name(1~255)
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Cauntry ");      //Taste anzeigen ungedrückt
            break;

          /* Mix */
          case 4:
            DFMP3_Player.loopFolder(5);  //play mp3; Folder Name(1~99); File Name(1~255)
            Display.gfx_Button(Status_Touch_Taste, 110, 305, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Mix     ");      //Taste anzeigen ungedrückt
            break;                
        }
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

        Display.gfx_Triangle(260, 300, 260, 340, 300, 320, WHITE);           //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [< Equalizer] Taste gedrückt */
    if ((X_Pos_Touch >= 40) && (X_Pos_Touch <= 120) && (Y_Pos_Touch >= 380) && (Y_Pos_Touch <= 460))     //Überwachung Touch Feld
    {
      /* Touch Feld [< Equalizer] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Triangle(100, 400, 100, 440, 60, 420, BLACK);           //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)
        
        Equalizer--;                          //Equalizer runter zählen
        if (Equalizer < 0) Equalizer = 5;     //Verstellwert begrenzen     
        
        switch(Equalizer)                     //Überwachen letztes Menü
        {
          /* Normal */
          case 0:          
            DFMP3_Player.EQ(DFPLAYER_EQ_NORMAL);
            Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Normal  ");      //Taste anzeigen ungedrückt       
            break;

          /* Pop */
          case 1:
            DFMP3_Player.EQ(DFPLAYER_EQ_POP);
            Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Pop     ");      //Taste anzeigen ungedrückt
            break;

          /*Rock */
          case 2:
            DFMP3_Player.EQ(DFPLAYER_EQ_ROCK);
            Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Rock    ");      //Taste anzeigen ungedrückt           
            break;

          /* Jazz */
          case 3:
            DFMP3_Player.EQ(DFPLAYER_EQ_JAZZ);
            Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Jazz    ");      //Taste anzeigen ungedrückt
            break;

          /* Classic */
          case 4:
            DFMP3_Player.EQ(DFPLAYER_EQ_CLASSIC);
            Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Classic ");      //Taste anzeigen ungedrückt
            break;

          /* Bass */        
          case 5:
            DFMP3_Player.EQ(DFPLAYER_EQ_BASS);
            Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Bass    ");      //Taste anzeigen ungedrückt
            break;
        }
        
        /* Buzzer */
        Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

        Display.gfx_Triangle(100, 400, 100, 440, 60, 420, WHITE);           //Dreieck Previous zeichnen (x, y, x2, y2, x3, y3, Farbe)
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [> Equalizer] Taste gedrückt */
    if ((X_Pos_Touch >= 240) && (X_Pos_Touch <= 320) && (Y_Pos_Touch >= 380) && (Y_Pos_Touch <= 460))     //Überwachung Touch Feld
    {
      /* Touch Feld [> Equalizer] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Triangle(260, 400, 260, 440, 300, 420, BLACK);           //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)

        Equalizer++;                          //Equalizer hoch zählen
        if (Equalizer > 5) Equalizer = 0;     //Verstellwert begrenzen
        
        switch(Equalizer)                     //Überwachen letztes Menü
        {
          /* Normal */
          case 0:          
            DFMP3_Player.EQ(DFPLAYER_EQ_NORMAL);
            Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Normal  ");      //Taste anzeigen ungedrückt (Equalizer)       
            break;

          /* Pop */
          case 1:
            DFMP3_Player.EQ(DFPLAYER_EQ_POP);
            Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Pop     ");      //Taste anzeigen ungedrückt (Equalizer)
            break;

          /*Rock */
          case 2:
            DFMP3_Player.EQ(DFPLAYER_EQ_ROCK);
            Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Rock    ");      //Taste anzeigen ungedrückt (Equalizer)           
            break;

          /* Jazz */
          case 3:
            DFMP3_Player.EQ(DFPLAYER_EQ_JAZZ);
            Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Jazz    ");      //Taste anzeigen ungedrückt (Equalizer)
            break;

          /* Classic */
          case 4:
            DFMP3_Player.EQ(DFPLAYER_EQ_CLASSIC);
            Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Classic ");      //Taste anzeigen ungedrückt (Equalizer)
            break;

          /* Bass */        
          case 5:
            DFMP3_Player.EQ(DFPLAYER_EQ_BASS);
            Display.gfx_Button(Status_Touch_Taste, 110, 405, BLUE, WHITE, Schrifttyp, Textbreite, Textrahmen, " Bass    ");      //Taste anzeigen ungedrückt (Equalizer)
            break;
        }
             
        /* Buzzer */
        Buzzer(100);            //Aufruf Funktion Buzzer(int Buzzer_Zeit) 

        Display.gfx_Triangle(260, 400, 260, 440, 300, 420, WHITE);           //Dreieck Next zeichnen (x, y, x2, y2, x3, y3, Farbe)
      }
    }

/********************************************************************************************************************/

    /* Touch Feld abfragen [i] Taste gedrückt */
    if ((X_Pos_Touch >= 720) && (X_Pos_Touch <= 799) && (Y_Pos_Touch >= 0) && (Y_Pos_Touch <= 45))    //Überwachung Touch Feld
    {
      /* Touch Feld [i] Taste ausführen */
      if (Status_Touch_Taste)
      {
        Display.gfx_Button(Status_Touch_Taste, 755, 15, BLACK, GRAY, Schrifttyp, Textbreite, Textrahmen, "i");                  //Taste anzeigen gedrückt

        /* Buzzer */
        Buzzer(100);                          //Aufruf Funktion Buzzer(int Buzzer_Zeit)
        
        Menue_angewaehlt = 7;                 //Menü Info anwählen
        Bild_aufgebaut[7] = false;            //Bildschirm Info aufgebaut zurücksetzen
        Letztes_Menue = 52;                   //Letztes angewähltes Menü   
        Info_Seite = 21;                      //Info Seite anwählen
      }
    }

/********************************************************************************************************************/
  
  }       //Touch Freigabe Ende

/********************************************************************************************************************/
  
}

void printDetail(uint8_t type, int value)
{
  switch (type) 
  {
    case TimeOut:
      SerialUSB.println(F("Time Out!"));
      break;
    
    case WrongStack:
      SerialUSB.println(F("Stack Wrong!"));
      break;
    
    case DFPlayerCardInserted:
      SerialUSB.println(F("Card Inserted!"));
      break;
    
    case DFPlayerCardRemoved:
      SerialUSB.println(F("Card Removed!"));
      break;
    
    case DFPlayerCardOnline:
      SerialUSB.println(F("Card Online!"));
      break;
    
    case DFPlayerPlayFinished:
      SerialUSB.print(F("Number:"));
      SerialUSB.print(value);
      SerialUSB.println(F(" Play Finished!"));
      break;
    
    case DFPlayerError:
      SerialUSB.print(F("DFPlayerError:"));
      switch (value) {        
        case Busy:
          SerialUSB.println(F("Card not found"));
          break;
        
        case Sleeping:
          SerialUSB.println(F("Sleeping"));
          break;
        
        case SerialWrongStack:
          SerialUSB.println(F("Get Wrong Stack"));
          break;
        
        case CheckSumNotMatch:
          SerialUSB.println(F("Check Sum Not Match"));
          break;
        
        case FileIndexOut:
          SerialUSB.println(F("File Index Out of Bound"));
          break;
        
        case FileMismatch:
          SerialUSB.println(F("Cannot Find File"));
          break;
        
        case Advertise:
          SerialUSB.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
