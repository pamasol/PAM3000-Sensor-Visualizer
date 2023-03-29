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
      delay(Buzzer_Zeit);                               //Verzögerung
    }
}
