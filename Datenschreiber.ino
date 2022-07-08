/* Datenschreiber */

void Datenschreiber(word x, word y, word farbe)     //Funktion Datenschreiber
{

  /* Kurve anzeigen */    
  Display.gfx_Line(x,y,(x + 1),(y + 1),RED);      //Linie (x1,y1,x2,y2,farbe)

  x++; //(millis() / 1000);
  if (x == 10) y = y - 50;
  if (x == 20) y = y + 20;
  if (x == 100) y = y -70;

  delay(100);
  /* Buzzer */
//  Buzzer(100);                         //Aufruf Funktion Buzzer(int Buzzer_Zeit)
}
