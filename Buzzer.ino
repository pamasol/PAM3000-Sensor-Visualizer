<<<<<<< HEAD
/* Funktion Buzzer 
   Der Buzzer kann mit 0 ausgeschalten werden, mit Werte 1-255 wird er eingeschalten,
   je grösser der Wert umso lauter.
*/

void Buzzer(int Buzzer_Zeit)
{
    /* Buzzer eingeschalten */
    if (Buzzer_Einstellungen == 1)                      //Überwachung Buzzer eingeschalten
    {
      analogWrite(DA_Buzzer, Buzzer_Lautstaerke);       //Analog Ausgang Buzzer setzen (0=Aus, 5-255=Ein)
      delay(Buzzer_Zeit);                               //Verzögerung
      analogWrite(DA_Buzzer, 0);                        //Analog Ausgang Buzzer zurücksetzen
    }

    /* Buzzer ausgeschalten */
    else
    {
      /* Verzögerung wenn Buzzer ausgeschalten ist,
         damit die Verzögerung bleibt! */
=======
/* Funktion Buzzer */

void Buzzer(int Buzzer_Zeit)
{
    if(Buzzer_Einstellungen == 0)
    {
      analogWrite(DA_Buzzer, Buzzer_Lautstaerke);       //Analog Ausgang Buzzer setzen 0 = Aus 255 = An
      delay(Buzzer_Zeit);                               //Verzögerung
      analogWrite(DA_Buzzer, 0);                        //Analog Ausgang Buzzer setzen 0 = Aus 255 = An
    }
    else
    {
>>>>>>> d61c2949d2cb683a9d6c18a7d70fbc5298e0635e
      delay(Buzzer_Zeit);                               //Verzögerung
    }
}
