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
      delay(Buzzer_Zeit);                               //Verzögerung
    }
}
