/* Funktion Statusanzeige

*/

void Statusanzeige()
{

/********************************************************************************************************************/

  /* Kontrast Display */
  Display.gfx_Contrast(Kontrast_Display);       //Kontrast Display

/********************************************************************************************************************/

  /* Text Format definieren */
  Display.txt_Height(2);                            //Texthöhe
  Display.txt_Width(2);                             //Textweite

  /* Text ausblenden damit Messungen nicht beeinflusst werden! 
  */
  if (Messung_Ein_Geschw_Sort == true) 
  {
    Text_ausblenden = true;     //Text ausblenden setzen (Textfarbe schwarz)   
  }
  else
  {
    Text_ausblenden = false;     //Text ausblenden zurücksetzen (Textfarbe schwarz)
  }
  
/********************************************************************************************************************/

  /* Akkuladestand 
     Der Ladestand wir mittels eines Lichtsenors via den LED's vom Akkupack erfasst!
     
     Es gibt folgende zustände: - Keine Last am Akku, alle 4 LED's dunkel.
                                - eine LED blinkt, Akkustand sehr schwach.
                                - Laden LED's blinken, die Anzahl abhänig vom Ladestand.
                                - Last am Akku, LED's leuchten, die Anzahl abhänig vom Ladestand.
  */
  
  /* Ladestand einlesen */
  Sensor_Akkuladestand = analogRead(AD_Akkuladestand);    //Sensor Akkuladestand am Pin A0 einlesen

  /* Anzahl Mittelwert */
  Anzahl_Mittelwert_Sensor_Akkuladestand = 100;      // Anzahl Mittelwert

  /* Wert addieren */
  if (Zaehler_Mittelwert_Sensor_Akkuladestand <= Anzahl_Mittelwert_Sensor_Akkuladestand)          //Überwachung Zähler Mittelwert
  {         
    Zaehler_Mittelwert_Sensor_Akkuladestand++;                                                              //Zähler Mittelwert
    Temp_Mittelwert_Sensor_Akkuladestand = Temp_Mittelwert_Sensor_Akkuladestand + Sensor_Akkuladestand;     //Werte addieren
  }

  /* Mittelwert berechnen */
  if (Zaehler_Mittelwert_Sensor_Akkuladestand >= Anzahl_Mittelwert_Sensor_Akkuladestand)    //Überwachung Zähler Mittelwert 
  {
    Mittelwert_Sensor_Akkuladestand = Temp_Mittelwert_Sensor_Akkuladestand / Anzahl_Mittelwert_Sensor_Akkuladestand;  //Mittelwert berechnen

    /* Akkugrenzwerte */
    Akku_leer = 0;                //Akkugrenzwert leer  -> alle 4 LED's dunkel
    Akku_laden = 10; //10;        //Akkugrenzwert laden -> 1 LED leuchtet
    Akku_voll = 170; //170;       //Akkugrenzwert voll  -> alle 4 LED's leuchten 
  
    /* Akkuladestand umrechnen */
    Mittelwert_Sensor_Akkuladestand = constrain(Mittelwert_Sensor_Akkuladestand,0,Akku_voll);       //Wert begrenzung
    Akkuladestand = map(Mittelwert_Sensor_Akkuladestand, 0, Akku_voll, 0, 100);    //Akkuladestand in 0-100% umrechnen   
        
    /* Werte zurücksetzen */
    Temp_Mittelwert_Sensor_Akkuladestand = 0;         //Temporärer Mittelwert zurücksetzen
    Zaehler_Mittelwert_Sensor_Akkuladestand = 0;      //Zähler zurücksetzen
  }
                               
// duration = pulseIn(pin, HIGH);

  /* Akkuladestand auswerten
  Wartet bis alle Werte für den Mittelwert eingelesen sind,
  erst dann den Akkuladestand auswerten.
  */
  if (Akkuladestand_auswerten <= Anzahl_Mittelwert_Sensor_Akkuladestand) ++Akkuladestand_auswerten;    //Warten auf Mittelwert
  
  /* Akkuladestand auswerten */  
  if (Akkuladestand_auswerten >= Anzahl_Mittelwert_Sensor_Akkuladestand)            //Überwachung Akkuladestand 
  {
    /* Warnung Akku schwach */
    if (Akkuladestand <= Akku_laden)            //Überwachung Akkuladestand 
    {
      Display.txt_Height(2);                    //Texthöhe
      Display.txt_Width(2);                     //Textweite
      Display.txt_Set(TEXT_COLOUR, RED);        //Textfarbe
      Display.gfx_MoveTo(200,35);               //Text Position (x,y)
      Display.print("Akku laden!");             //Text anzeigen
           
      /* Buzzer */
      digitalWrite(DA_Buzzer, HIGH);            //Buzzer setzen
      delay(100);                               //Verzögerung 100ms 
      digitalWrite(DA_Buzzer, LOW);             //Buzzer zurücksetzen
          
      delay(500);                               //Verzögerung 500ms       
      Display.gfx_MoveTo(200, 35);              //Text Position (x,y) 
      Display.print("           ");             //Text löschen     
    }
   
    /* Anzeige Akkuladestand */
    Display.txt_Height(2);                            //Texthöhe
    Display.txt_Width(2);                             //Textweite
    Display.txt_Set(TEXT_COLOUR, Textfarbe);          //Textfarbe
    if (Text_ausblenden == true) Display.txt_Set(TEXT_COLOUR, BLACK);                //Text ausblenden      

    /* Batterien Symbol */
    Display.gfx_Rectangle(425, 13, 452, 27, WHITE);               //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    Display.gfx_RectangleFilled(452, 17, 456, 23, WHITE);         //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)

    /* Akkuladestand 75-100% */
    if ((Akkuladestand <= 100) && (Akkuladestand >= 75))          //Überwachung Akkuladestand
    {
      Display.gfx_RectangleFilled(426, 14, 451, 26, BLACK);       //Rahmen zeichnen  (Rechteck x1,y1,x2,y2))
      Display.gfx_RectangleFilled(426, 14, 451, 26, GREEN);       //Rahmen zeichnen  (Rechteck x1,y1,x2,y2))
    }

    /* Akkuladestand 50-75% */
    if ((Akkuladestand <= 75) && (Akkuladestand >= 50))           //Überwachung Akkuladestand
    {
      Display.gfx_RectangleFilled(426, 14, 451, 26, BLACK);       //Rahmen zeichnen  (Rechteck x1,y1,x2,y2))
      Display.gfx_RectangleFilled(426, 14, 445, 26, GREEN);       //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    }
    
    /* Akkuladestand 25-50% */
    if ((Akkuladestand <= 50) && (Akkuladestand >= 25))           //Überwachung Akkuladestand
    {
      Display.gfx_RectangleFilled(426, 14, 451, 26, BLACK);       //Rahmen zeichnen  (Rechteck x1,y1,x2,y2))
      Display.gfx_RectangleFilled(426, 14, 440, 26, GREEN);       //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    }

    /* Akkuladestand -25% */
    if ((Akkuladestand <= 25) && (Akkuladestand >= Akku_laden))   //Überwachung Akkuladestand
    {
      Display.gfx_RectangleFilled(426, 14, 451, 26, BLACK);       //Rahmen zeichnen  (Rechteck x1,y1,x2,y2))
      Display.gfx_RectangleFilled(426, 14, 435, 26, YELLOW);      //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    }

    /* Akkuladestand laden */
    if(Akkuladestand <= Akku_laden)                               //Überwachung Akkuladestand
    {
      Display.gfx_RectangleFilled(426, 14, 451, 26, BLACK);       //Rahmen zeichnen  (Rechteck x1,y1,x2,y2))
      Display.gfx_RectangleFilled(426, 14, 430, 26, RED);         //Rahmen zeichnen  (Rechteck x1,y1,x2,y2)
    }
  
    Display.gfx_MoveTo(465, 10);                      //Text Position (x,y)
    Display.print(Akkuladestand);                     //Text anzeigen
    Display.print("%  ");                             //Text anzeigen

    Akkuladestand_auswerten = 0;         //Akkuladestand auswerten zurücksetzen 
  }
    
/********************************************************************************************************************/

  /* Adapter Typ einlesen */
  Spannung_Adapter_Typ = analogRead(AD_Adapter_Typ);    //Spannungsteiler Adapter Typ am Pin A8 einlesen

  //SerialUSB.println();                                 
  //SerialUSB.print(Spannung_Adapter_Typ);                      //Ausgabe Aktuelle Messung

  /* Adapter Typ anzeigen */
  Display.txt_Set(TEXT_COLOUR, Textfarbe);          //Textfarbe
  Display.gfx_MoveTo(580, 10);                      //Text Position (x,y)

  switch (Spannung_Adapter_Typ)
  {  
     /* Adapter - */
    case 0 ... 9:   
      Display.print("Adapter -");                       //Text anzeigen    
      break;
     
     /* Adapter A */
    case 10 ... 85:   
      Display.print("Adapter A");                       //Text anzeigen    
      break;

     /* Adapter B */
    case 86 ... 170:   
      Display.print("Adapter B");                       //Text anzeigen    
      break;

     /* Adapter C */
    case 171 ... 255:   
      Display.print("Adapter C");                       //Text anzeigen    
      break;

     /* Adapter D */
    case 256 ... 340:   
      Display.print("Adapter D");                       //Text anzeigen    
      break;

     /* Adapter F */
    case 341 ... 425:   
      Display.print("Adapter F");                       //Text anzeigen    
      break;

     /* Adapter N */
    case 426 ... 510:   
      Display.print("Adapter N");                       //Text anzeigen    
      break;

     /* Adapter U */
    case 511 ... 595:   
      Display.print("Adapter U");                       //Text anzeigen    
      break;

     /* Adapter V */
    case 596 ... 680:   
      Display.print("Adapter V");                       //Text anzeigen    
      break;

     /* Adapter I2C */
    case 681 ... 765:   
      Display.print("Adapter I2C");                       //Text anzeigen    
      break;

     /* Adapter P */
    case 766 ... 850:   
      Display.print("Adapter P");                       //Text anzeigen    
      break;

     /* Adapter - */
    case 851 ... 935:   
      Display.print("Adapter -");                       //Text anzeigen    
      break;

     /* Adapter - */
    case 936 ... 1023:   
      Display.print("Adapter -");                       //Text anzeigen    
      break;

     /* Adapter Fehlt */
    default:   
      Display.print("Adapter ?");                       //Text anzeigen    
      break;

     /* Falscher Adapter */
//    case 20:   
        Display.txt_Set(TEXT_COLOUR, RED);                //Textfarbe
//      Display.print("Adapter X");                       //Text anzeigen    
//      break; 
  }

/********************************************************************************************************************/

  /* 24V Versorgung 
     Aus = weiss
     Ein = grün
  */
  Display.txt_Set(TEXT_COLOUR, Textfarbe);          //Textfarbe
  Display.gfx_MoveTo(580, 35);                      //Text Position (x,y)
  
  if (digitalRead(DA_Versorgung_24VDC) == HIGH)     //Überwachung Digital Ausgang 24VDC Versorgung gesetzt
  {
    Display.txt_Set(TEXT_COLOUR, GREEN);            //Textfarbe
  }
  
  Display.print("24V");                     //Text anzeigen

/********************************************************************************************************************/

  /* SD Karte Status 
     weiss = Keine Karte nötig
       rot = Karte fehlt
      grün = Karte gesteckt        
  */
  Display.txt_Set(TEXT_COLOUR, Textfarbe);          //Textfarbe
  Display.gfx_MoveTo(640, 35);                      //Text Position (x,y)  
  
  /* Keine Karte gesteckt */
  if (!SD.begin(10)) Display.txt_Set(TEXT_COLOUR, RED);          //Textfarbe

  /* Karte gesteckt */
  if (SD.begin(10)) Display.txt_Set(TEXT_COLOUR, GREEN);          //Textfarbe

  Display.print("SD");                              //Text anzeigen

/********************************************************************************************************************/
  
  /* Echtzeituhr DS1307 */
  Uhr.getTime();                          //Zeit lesen

  /* Zeit anzeigen */
  Display.txt_Set(TEXT_COLOUR, Textfarbe);      //Textfarbe
  if (Text_ausblenden == true) Display.txt_Set(TEXT_COLOUR, BLACK);                //Text ausblenden 
  Display.gfx_MoveTo(0, 10);                   //Text Position (x,y)
  if (Uhr.hour < 10) Display.print("0");        //Bei einstelligen Zahlen eine 0 davor setzen
  Display.print(Uhr.hour, DEC);
  Display.print(":");
  if (Uhr.minute < 10) Display.print("0");      //Bei einstelligen Zahlen eine 0 davor setzen
  Display.print(Uhr.minute, DEC);
  Display.print(":");
  if (Uhr.second < 10) Display.print("0");      //Bei einstelligen Zahlen eine 0 davor setzen
  Display.print(Uhr.second, DEC);
  Display.print(" ");
  if (Uhr.dayOfMonth < 10) Display.print("0");  //Bei einstelligen Zahlen eine 0 davor setzen
  Display.print(Uhr.dayOfMonth, DEC);
  Display.print("/");
  if (Uhr.month < 10) Display.print("0");       //Bei einstelligen Zahlen eine 0 davor setzen
  Display.print(Uhr.month, DEC);
  Display.print("/");
  Display.print(Uhr.year+2000, DEC);
  Display.print(" ");

  /* Wochentag anzeigen */
  switch (Uhr.dayOfWeek)      //Wochentag anzeigen
  {
    case MON:
      Display.print("Mo");
      break;
      
    case TUE:
      Display.print("Di");
      break;
      
    case WED:
      Display.print("Mi");
      break;
      
    case THU:
      Display.print("Do");
      break;
      
    case FRI:
      Display.print("Fr");
      break;
      
    case SAT:
      Display.print("Sa");
      break;
      
    case SUN:
      Display.print("Su");
      break;
  }

/********************************************************************************************************************/

  /* Alarm 
     Es können zehn Alarmzeiten eingestellt werden, 
     der Alarm ist jeweils zehn Sekunde aktiv!  
  */  
  Alarm_Ein[0] = true;      //Morgen Pause 9:00
  Alarm_Stunden[0] = 9;
  Alarm_Minuten[0] = 0;

  Alarm_Ein[1] = true;      //Mittag Pause 12:00
  Alarm_Stunden[1] = 12;
  Alarm_Minuten[1] = 0;

  Alarm_Ein[2] = true;      //Nachmittag Pause 15:00
  Alarm_Stunden[2] = 15;
  Alarm_Minuten[2] = 0;

  Alarm_Ein[3] = false;      
  Alarm_Stunden[3] = 0;
  Alarm_Minuten[3] = 0;
  
  Alarm_Ein[4] = false;
  Alarm_Stunden[4] = 0;
  Alarm_Minuten[4] = 0;

  Alarm_Ein[5] = false;
  Alarm_Stunden[5] = 0;
  Alarm_Minuten[5] = 0;
    
  Alarm_Ein[6] = false;
  Alarm_Stunden[6] = 0;
  Alarm_Minuten[6] = 0;
  
  Alarm_Ein[7] = false;
  Alarm_Stunden[7] = 0;
  Alarm_Minuten[7] = 0;
  
  Alarm_Ein[8] = false;
  Alarm_Stunden[8] = 0;
  Alarm_Minuten[8] = 0;
  
  Alarm_Ein[9] = false;  
  Alarm_Stunden[9] = 0;
  Alarm_Minuten[9] = 0;
  
  Alarm_Wochentag = WED;     //MON, TUE, WED, THU, FRI, SAT, SUN

  /* Alarm anzeigen */
  for (int i = 0; i <= 9; i++)
  {
    if ((Alarm_Ein[i] == true) && (Uhr.hour == Alarm_Stunden[i]) && (Uhr.minute == Alarm_Minuten[i]) && (Uhr.second > 0)&& (Uhr.second < 10))  //&& (Uhr.dayOfWeek == MON))
    {
      Display.txt_Height(2);                            //Texthöhe
      Display.txt_Width(2);                             //Textweite
      Display.txt_Set(TEXT_COLOUR, RED);                //Textfarbe
      Display.gfx_MoveTo(200, 35);                      //Text Position (x,y)
      if (Alarm_Stunden[i] < 10) Display.print("0");    //Bei einstelligen Zahlen eine 0 davor setzen    
      Display.print(Alarm_Stunden[i]);
      Display.print(":");
      if (Alarm_Minuten[i] < 10) Display.print("0");    //Bei einstelligen Zahlen eine 0 davor setzen    
      Display.print(Alarm_Minuten[i]);   
      Display.print(" Pause!"); 
    
      /* Buzzer */
      Buzzer(50);                                       //Aufruf Funktion Buzzer(int Buzzer_Zeit)
      delay(50);                                        //Verzögerung 50ms
      Display.gfx_MoveTo(200, 35);                      //Text Position (x,y) 
      Display.print("                 ");               //Text löschen        
    }
  }
   
/********************************************************************************************************************/
  
}
