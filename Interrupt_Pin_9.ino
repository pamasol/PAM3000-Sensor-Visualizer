/* Funktion Interrupt Pin 9
 
   Sobald der Pin 9 von LOW auf HIGH geht aktiviert der Interrupt2 der im Void Setup deklariert ist. 
   Nach dem Interrupt läuft das Programm am "alten" Ort weiter.
*/

void Interrupt_Pin_9()      //Funktion Interrupt Pin 9
{
    
/********************************************************************************************************************/

  /* Sollte das Programm vorher im void Geschwindigkeitsanzeige Sortierer gewesen sein, wir dies ausgeführt */
  if (Menue_angewaehlt == 10)                    //Überwachung Menü Geschwindigkeitsanzeige Sortierer aktiv
  {
    /* Zähler 
       Flankenauswertung */ 
    if (Zaehler_Geschw_Sort_2 == true)
    {
      /* Zähler */
      Zaehlwert_Geschw_Sort_2 = ++Zaehlwert_Geschw_Sort_2;        //Zählwert Geschwindigkeit Sortierer 2 
        
      /* Wertbegrenzung */
      if (Zaehlwert_Geschw_Sort_2 >= Wertbegrenzung_Geschw_Sort) Zaehlwert_Geschw_Sort_2 = Wertbegrenzung_Geschw_Sort;

      /* Zählwert addiert */  
      Zaehler_Geschw_Sort_2 = false;         //Zählwert addiert      
    }          
  }

/********************************************************************************************************************/
  
}
