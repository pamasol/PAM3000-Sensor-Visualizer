/* Funktion Filter ABS   
   Bildet Mittelwert aus X Werten, um "spitzen" zu Filter.
*/
int16_t Filter_ABS(int Anzahl, int16_t Ist)     //Funktion Filter ABS
{ 
  long long_ABS;            //long ABS -> Achtung: Maximum Wert beim addieren nicht überschreiten!!!
  int16_t ABS;              //ABS
  int i;                    //Index

  /* Werte addieren */ 
  if (i <= Anzahl)                //Überwachung Index
  {         
    i++;                          //Index addieren
    long_ABS = long_ABS + Ist;    //Werte addieren
  }

  /* Mittelwert berechnen */
  if (i >= Anzahl)                //Überwachung Index 
  {
    ABS = long_ABS / Anzahl;      //Mittelwert berechnen
    long_ABS = 0;                 //long ABS zurücksetzen
    i = 0;                        //Index zurücksetzen
  }
    
  return ABS;                     //Rückwert Resultat ABS
}
