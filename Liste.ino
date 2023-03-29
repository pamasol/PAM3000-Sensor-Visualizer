/* Liste

   Funktion = 0 -> Aktuelle Wert kleiner als Mittelwert werden Rot dargestellt. 
   Funktion = 1 -> Aktuelle Wert grösser als Mittelwert werden Rot dargestellt.
                              
   Darstellung:     0. 0 ms             
                    1. 0 ms     
                    2. 0 ms     
                    3. 0 ms    
                    4. 0 ms     
                    5. 0 ms     
                    6. 0 ms    
                    7. 0 ms       
                    8. 0 ms   
                    9. 0 ms    
*/

void Liste(int X_Pos, int Y_Pos, int Start, int Anzahl, unsigned long Wert[],unsigned long Mittelwert, int Funktion, word Grenzwert_Farbe, char Einheit[])    //Funktion Liste
{         
    /* Text Format */
    Display.txt_Height(2);                        //Texthöhe
    Display.txt_Width(2);                         //Textweite
//    Display.txt_Set(TEXT_COLOUR, WHITE);          //Textfarbe

    /* Schlaufe */
    for (int i = Start; i < (Start + Anzahl); i++)      //Schlaufe 
    {             
      Display.txt_Set(TEXT_COLOUR, WHITE);        //Textfarbe   
      Display.gfx_MoveTo(X_Pos, Y_Pos);           //Text Position (x,y)
      Display.print(i);                           //Text anzeigen
      Display.print(". ");                        //Text anzeigen

      /* Aktuelle Wert kleiner als Mittelwert werden Rot dargestellt */
      if (Funktion == 0)
      {
        if ((Wert[i] > 0) && (Wert[i] < Mittelwert)) Display.txt_Set(TEXT_COLOUR, Grenzwert_Farbe);           //Textfarbe
        if ((Wert[i] == 0) || (Wert[i] >= Mittelwert)) Display.txt_Set(TEXT_COLOUR, WHITE);                   //Textfarbe         
      }

      /* Aktuelle Wert grösser als Mittelwert werden Rot dargestellt */
      if (Funktion == 1)
      {
        if ((Wert[i] > 0) && (Wert[i] > Mittelwert)) Display.txt_Set(TEXT_COLOUR, Grenzwert_Farbe);           //Textfarbe
        if ((Wert[i] == 0) || (Wert[i] <= Mittelwert)) Display.txt_Set(TEXT_COLOUR, WHITE);                   //Textfarbe         
      }
           
      Display.print(Wert[i]);                     //Wert anzeigen
      Display.txt_Set(TEXT_COLOUR, WHITE);        //Textfarbe   
      Display.print(" ");                         //Text anzeigen
      Display.print(Einheit);                     //Text anzeigen      
      Y_Pos = Y_Pos + 25;                         //Nächste y Position berechnen 
    }
}
