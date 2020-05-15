void Interrupt2 ()

{

  

if (Stoppuhrinterrupt == true)
{
  Menue_angewaehlt = 7;                     //Menue_angewaehlt (7) 
}


if (Geschwingigkeitinterrupt2 == true)
{
  Menue_angewaehlt = 9;                     //Menue_angewaehlt (6) 

  
  if(Geschwindigkeit_Stopp2 == true)
  
      {
        Menue_angewaehlt = 9;                  
      }

      
    if(Geschwindigkeit_Stopp2 == false)
           {
           Menue_angewaehlt = 9;
           Geschwindigkeit_Stopp2 = true;
           }
      
  }

    if(Geschwingigkeitinterrupt4 == true && Interrupt_Durchschnitt2 == true)
  {
    Menue_angewaehlt = 12;

    Durchschnittanzahl2 = (Durchschnittanzahl2 + 1);

    Interrupt_Durchschnitt2 = false;
        
     
  }



}
