/* Funktion Interrupt Pin 8
   
   Sobald der Pin 8 von LOW auf HIGH geht aktiviert der Interrupt der im Void Setup deklariert ist. 
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

void Interrupt_Pin_8()                //Funktion Interrupt Pin 8
{
  
/********************************************************************************************************************/

  /* Sollte das Programm vorher im void Geschwindigkeitsanzeige Sortierer gewesen sein, wir dies ausgeführt */
<<<<<<< HEAD
  if (Messung_Ein_Geschw_Sort == true)        //Überwachung Geschwindigkeitsanzeige Sortierer aktiv
  {
    /* Zähler 
       Flankenauswertung */ 
    if (Freigabe_Interrupt_Geschw_Sort_1 == true)
    {
      /* Zähler */
      Zaehlwert_Geschw_Sort_1++;       //Zählwert addieren Geschwindigkeit Sortierer 1 
=======
  if (Menue_angewaehlt == 10)                    //Überwachung Menü Geschwindigkeitsanzeige Sortierer aktiv
  {
    /* Zähler 
       Flankenauswertung */ 
    if (Zaehler_Geschw_Sort_1 == true)
    {
      /* Zähler */
      Zaehlwert_Geschw_Sort_1 = ++Zaehlwert_Geschw_Sort_1;        //Zählwert Geschwindigkeit Sortierer 1 
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
        
      /* Wertbegrenzung */
      if (Zaehlwert_Geschw_Sort_1 >= Wertbegrenzung_Geschw_Sort) Zaehlwert_Geschw_Sort_1 = Wertbegrenzung_Geschw_Sort; 

      /* Zählwert addiert */  
<<<<<<< HEAD
      Freigabe_Interrupt_Geschw_Sort_1 = false;         //Zählwert addiert      
    }          
  }

/********************************************************************************************************************/

  /* Sollte das Programm vorher im void Zähler gewesen sein, wir dies ausgeführt */
  if ((High_Speed_Zaehler == true) && (Messung_Ein_Zaehler == true))      //Überwachung Zähler aktiv
  {
    /* Zähler 
       Flankenauswertung */ 
    if (Freigabe_Interrupt_Zaehler_1 == true)
    {
      /* Zähler */
      Zaehlwert_Zaehler_1++;      //Zählwert addieren Zähler 1        
      if (Master_1_Zaehler == true)  Zaehlwert_Zaehler_2++;      //Zählwert addieren Zähler 2 

      /* Wertbegrenzung */
      if (Zaehlwert_Zaehler_1 >= Wertbegrenzung_Zaehler) Zaehlwert_Zaehler_1 = Wertbegrenzung_Zaehler; 

      /* Zählwert addiert */  
      Freigabe_Interrupt_Zaehler_1 = false;               //Zählwert addiert      
=======
      Zaehler_Geschw_Sort_1 = false;         //Zählwert addiert      
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
    }          
  }

/********************************************************************************************************************/
  
}
