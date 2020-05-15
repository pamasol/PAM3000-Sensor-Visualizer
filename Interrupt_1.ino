void Interrupt ()

{
  



if (Stoppuhrinterrupt == true)


{
  Menue_angewaehlt = 6;                     //Menue_angewaehlt (6)
}


if (Geschwingigkeitinterrupt == true)
  {
  
    if(Geschwindigkeit_Stopp == true)
  
      {
        Menue_angewaehlt = 8;                     //Menue_angewaehlt (6) 
      }

      if(Geschwindigkeit_Stopp == false)
       {
       Menue_angewaehlt = 8;
       Geschwindigkeit_Stopp = true;
       }


  
  }

  if(Geschwingigkeitinterrupt3 == true && Interrupt_Durchschnitt == true)
  {
    Menue_angewaehlt = 11;

    Durchschnittanzahl = (Durchschnittanzahl + 1);

    Interrupt_Durchschnitt = false;
        
     
  }


}
