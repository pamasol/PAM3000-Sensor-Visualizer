void mycallback(int ErrCode, unsigned char Errorbyte)

{

#ifdef LOG_MESSAGES

  const char*Error4DTeX_Post[] = {"OK\0", "Timeout\0", "NAK\0", "Length\0", "Invalid\0"};

  Serial.print(F("Serial 4D Library reports error "));
  Serial.print(Error4DTeX_Post[ErrCode]);


  if (ErrCode == Err4D_NAK)

  {

    Serial.print(F(" returned data= "));
    Serial.println(Errorbyte);

  }

  else

    Serial.println(F(""));

  while (1);                   //you can return here, or you can loop

#else


                               //Pin 13 has an LED connected on most Arduino boards. Just give it a name


#define led 13

  while (1)

  {

    digitalWrite(led, HIGH);   //turn the LED on (HIGH is the voltage level)
    delay(200);                //Verzögerung 200ms
    digitalWrite(led, LOW);    //turn the LED off by making the voltage LOW
    delay(200);                //Verzögerung 200ms

  }

#endif

}
