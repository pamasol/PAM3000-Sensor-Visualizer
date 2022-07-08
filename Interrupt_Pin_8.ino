/* Funktion Interrupt Pin 8
   
   Sobald der Pin 8 von LOW auf HIGH geht aktiviert der Interrupt der im Void Setup deklariert ist. 
   Nach dem Interrupt läuft das Programm am "alten" Ort weiter.  
*/

void Interrupt_Pin_8()                //Funktion Interrupt Pin 8
{
  
/********************************************************************************************************************/

  /* Sollte das Programm vorher im void Geschwindigkeitsanzeige Sortierer gewesen sein, wir dies ausgeführt */
  if (Menue_angewaehlt == 10)                    //Überwachung Menü Geschwindigkeitsanzeige Sortierer aktiv
  {
    /* Zähler 
       Flankenauswertung */ 
    if (Zaehler_Geschw_Sort_1 == true)
    {
      /* Zähler */
      Zaehlwert_Geschw_Sort_1 = ++Zaehlwert_Geschw_Sort_1;        //Zählwert Geschwindigkeit Sortierer 1 
        
      /* Wertbegrenzung */
      if (Zaehlwert_Geschw_Sort_1 >= Wertbegrenzung_Geschw_Sort) Zaehlwert_Geschw_Sort_1 = Wertbegrenzung_Geschw_Sort; 

      /* Zählwert addiert */  
      Zaehler_Geschw_Sort_1 = false;         //Zählwert addiert      
    }          
  }

/********************************************************************************************************************/
  
}
