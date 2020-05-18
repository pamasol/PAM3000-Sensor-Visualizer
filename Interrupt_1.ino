/* Sobald der Pin 8 von LOW auf HIGH geht aktiviert der Interrupt der im Void Setup deklariert ist. 
   Nach dem Interrupt läuft das Programm beim void Interrupt weiter.*/

void Interrupt ()
{

/* Sollte das Programm vorher im void Stoppuhr gewesen sein, wir dies ausgeführt*/

  if (Stoppuhrinterrupt == true)
  {
    
  Menue_angewaehlt = 6;                               //Menue_angewaehlt (6)
  }

/* Sollte das Programm vorher im void Geschwindigkeitsanzeige gewesen sein, wir dies ausgeführt*/

  if (Geschwingigkeitinterrupt == true)
  {

  
    if(Geschwindigkeit_Stopp == true)
  
    {
      
    Menue_angewaehlt = 8;                             //Menue_angewaehlt (8) 
    }

      if(Geschwindigkeit_Stopp == false)
      {
        
       Menue_angewaehlt = 8;                          //Menue_angewaehlt (8)
       
       Geschwindigkeit_Stopp = true;                  //Geschwindigkeit_Stopp setzen
      }
  }

/* Sollte das Programm vorher im void Geschwindigkeitsanzeige Durchschnitt gewesen sein, wir dies ausgeführt*/

  if(Geschwingigkeitinterrupt3 == true && Interrupt_Durchschnitt == true)
  {
    
    Menue_angewaehlt = 11;                            //Menue_angewaehlt (11)

    Durchschnittanzahl = (Durchschnittanzahl + 1);    //Durchschnittanzahl um 1 erhöhen

    Interrupt_Durchschnitt = false;                   //Interrupt_Durchschnitt auf fasle setzen
  }
}
