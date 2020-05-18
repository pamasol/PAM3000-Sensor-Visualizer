/* Sobald der Pin 9 von LOW auf HIGH geht aktiviert der Interrupt2 der im Void Setup deklariert ist. 
   Nach dem Interrupt läuft das Programm beim void Interrupt2 weiter.*/

void Interrupt2 ()
{
  
/* Sollte das Programm vorher im void Stoppuhr gewesen sein, wir dies ausgeführt*/

  if (Stoppuhrinterrupt == true)
  {
    
  Menue_angewaehlt = 7;                                 //Menue_angewaehlt (7) 
  }
  
/* Sollte das Programm vorher im void Geschwindigkeitsanzeige gewesen sein, wir dies ausgeführt*/

  if (Geschwingigkeitinterrupt2 == true)
  {
    
  Menue_angewaehlt = 9;                                 //Menue_angewaehlt (9) 

  
    if(Geschwindigkeit_Stopp2 == true)
  
    {
      
    Menue_angewaehlt = 9;                               //Menue_angewaehlt (9)          
    }

      
    if(Geschwindigkeit_Stopp2 == false)
    {
      
    Menue_angewaehlt = 9;                               //Menue_angewaehlt (9)
    
    Geschwindigkeit_Stopp2 = true;                      //Geschwindigkeit_Stopp2 setzem
    }      
  }

/* Sollte das Programm vorher im void Geschwindigkeitsanzeige Durchschnitt gewesen sein, wir dies ausgeführt*/

  if(Geschwingigkeitinterrupt4 == true && Interrupt_Durchschnitt2 == true)
  {
    
    Menue_angewaehlt = 12;                              //Menue_angewaehlt (12)

    Durchschnittanzahl2 = (Durchschnittanzahl2 + 1);    //Durchschnittanzahl2 um 1 erhöhen

    Interrupt_Durchschnitt2 = false;                    //Interrupt_Durchschnitt2 auf false setzen
  }
}
