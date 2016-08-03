int http_init()
{
  int stat = YES;
  int count;
  myserial.println("AT+HTTPINIT");// initialise HTTP connection
  char back = myserial.read();
  for (count = 0; back != 'K' && back != 'E'; count++) // read until an ERROR/OK recive
  {
    back = myserial.read();
  }
  if (back == 'E') // IF ERROR TERMINATE INITIALISATION AND RE INITIALISE ONE MORE TIME
  {
    myserial.println("AT+HTTPTERM");
    back = myserial.read();
    for (count = 0; back != 'K' && back != 'E'; count++)
    {
      back = myserial.read();
    }
    myserial.println("AT+HTTPINIT");//RE INITIALISATION
    back = myserial.read();
    for (count = 0; back != 'K' && back != 'E'; count++)
    {
      back = myserial.read();
    }
    if (back == 'E')
    {
      stat = NO;
    }
  }
  else
  {
    Serial.println("done http init");
  }
  return stat;
}
