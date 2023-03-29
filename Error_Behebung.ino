/* Void mycallback wurde von Martin Ruoss geschrieben.
   Wird gegen einen Hochladefehler gebraucht.*/

void mycallback(int ErrCode, unsigned char Errorbyte)
{

#ifdef LOG_MESSAGES

  const char*Error4DTeX_Post[] = {"OK\0", "Timeout\0", "NAK\0", "Length\0", "Invalid\0"};

  SerialUSB.print(F("Serial 4D Library reports error "));
  SerialUSB.print(Error4DTeX_Post[ErrCode]);


    if (ErrCode == Err4D_NAK)
    {
      SerialUSB.print(F(" returned data= "));
      SerialUSB.println(Errorbyte);
    }

    else
      SerialUSB.println(F(""));
    while (1);               

#else
                               
#define led 13            

        while (1)
        {
          digitalWrite(led, HIGH);   //LED 13 auf HIGH
          delay(200);                //Verzögerung 200ms
          digitalWrite(led, LOW);    //LED 13 auf LOW
          delay(200);                //Verzögerung 200ms
        }

#endif

}
