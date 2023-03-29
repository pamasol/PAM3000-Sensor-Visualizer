/* Flanke Positiv 

   Ist Ein aktiv, wird die Flanke nur einmal gesetzt,
   egal wie lange Ein aktiv ist.   
*/

void Flanke_Pos(bool Ein, bool Flanke)
{

  /* Flanke beim nächsten Zyklus zurücksetzen */
  if ((Ein == true) && (Flanke == true))
  {
    Flanke = false;
  }

  /* Flanke für einen Zyklus setzen */
  if ((Ein == true) && (Flanke == false))
  {
    Flanke = true;
  }

  /* Flanke zurücksetzen */
  if (Ein == false)
  {
    Flanke = false;    
  }  
}
