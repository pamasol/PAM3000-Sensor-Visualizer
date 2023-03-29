/* Funktion Interrupt Pin 9
 
   Sobald der Pin 9 von LOW auf HIGH geht aktiviert der Interrupt2 der im Void Setup deklariert ist. 
   Nach dem Interrupt läuft das Programm am "alten" Ort weiter.
<<<<<<< HEAD

   Mode: Definiert, wann der Interrupt getriggert werden soll. 4 Konstanten sind dafür definiert:

   LOW Interrupt wird getriggert, wenn der Pin LOW ist,
   CHANGE Interrupt wird getriggert, wenn der Pin den Wert ändert
   RISING Interrupt wird getriggert, wenn der Pin von LOW auf HIGH wechselt,
   FALLING Interrupt wird getriggert, wenn der Pin von HIGH auf LOW wechselt.

   Die Due-, Zero- und MKR1000-Boards erlauben zusätzlich:
   HIGH Interrupt wird getriggert, wenn der Pin HIGH ist

=======
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
*/

void Interrupt_Pin_9()      //Funktion Interrupt Pin 9
{
    
/********************************************************************************************************************/

  /* Sollte das Programm vorher im void Geschwindigkeitsanzeige Sortierer gewesen sein, wir dies ausgeführt */
<<<<<<< HEAD
  if (Messung_Ein_Geschw_Sort == true)        //Überwachung Geschwindigkeitsanzeige Sortierer aktiv
  {
    /* Zähler 
       Flankenauswertung */ 
    if (Freigabe_Interrupt_Geschw_Sort_2 == true)
    {
      /* Zähler */
      Zaehlwert_Geschw_Sort_2++;       //Zählwert addieren Geschwindigkeit Sortierer 2 
=======
  if (Menue_angewaehlt == 10)                    //Überwachung Menü Geschwindigkeitsanzeige Sortierer aktiv
  {
    /* Zähler 
       Flankenauswertung */ 
    if (Zaehler_Geschw_Sort_2 == true)
    {
      /* Zähler */
      Zaehlwert_Geschw_Sort_2 = ++Zaehlwert_Geschw_Sort_2;        //Zählwert Geschwindigkeit Sortierer 2 
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        
      /* Wertbegrenzung */
      if (Zaehlwert_Geschw_Sort_2 >= Wertbegrenzung_Geschw_Sort) Zaehlwert_Geschw_Sort_2 = Wertbegrenzung_Geschw_Sort;

      /* Zählwert addiert */  
<<<<<<< HEAD
      Freigabe_Interrupt_Geschw_Sort_2 = false;         //Zählwert addiert      
    }          
  }

/********************************************************************************************************************/

  /* Sollte das Programm vorher im void Zähler gewesen sein, wir dies ausgeführt */
  if ((High_Speed_Zaehler == true) && (Messung_Ein_Zaehler == true) && (Master_1_Zaehler == false))      //Überwachung Zähler aktiv
  {
    /* Zähler 
       Flankenauswertung */ 
    if (Freigabe_Interrupt_Zaehler_2 == true)
    {
      /* Zähler */
      Zaehlwert_Zaehler_2++;       //Zählwert addieren Zähler 2 
        
      /* Wertbegrenzung */
      if (Zaehlwert_Zaehler_2 >= Wertbegrenzung_Zaehler) Zaehlwert_Zaehler_2 = Wertbegrenzung_Zaehler;

      /* Zählwert addiert */  
      Freigabe_Interrupt_Zaehler_2 = false;         //Zählwert addiert      
=======
      Zaehler_Geschw_Sort_2 = false;         //Zählwert addiert      
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
    }          
  }

/********************************************************************************************************************/
  
}
