//GSM INITIALISATION IF OK RETURN 'YES'
int gsm_init(void)
{
  int stat = YES;
  unsigned long int count;
  myserial.println("AT");
  char back = myserial.read();
  for (count = 0; back != 'K' && back != 'E'; count++)
  {
    back = myserial.read();
  }
  if (back == 'E')
  {
    stat = NO;
  }
  myserial.println("AT+CREG?");
  back = myserial.read();
  for (count = 0; back != 'K' ; count++) // in trhis case 'E' cannot be checked due to "+CREG" response
  {
    back = myserial.read();
  }
  if (back == 'E' )
  {
    stat = NO;
  }
  myserial.println("AT+CMGF=1");
  back = myserial.read();
  for (count = 0; back != 'K' && back != 'E' ; count++)
  {
    back = myserial.read();
  }
  if (back == 'E' )
  {
    stat = NO;
  }
  myserial.println("AT+CNMI=1,0,0,0,0");
  back = myserial.read();
  for (count = 0; back != 'K' && back != 'E' ; count++)
  {
    back = myserial.read();
  }
  if (back == 'E' )
  {
    stat = NO;
  }
  myserial.println("ATE0");
  back = myserial.read();
  for (count = 0; back != 'K' && back != 'E'; count++)
  {
    back = myserial.read();
  }
  if (back == 'E' )
  {
    stat = NO;
  }
  myserial.println("AT+CSCLK=0");    // to turn off sleepmode
  back = myserial.read();
  for (count = 0; back != 'K' && back != 'E' ; count++)
  {
    back = myserial.read();
  }
  if (back == 'E' )
  {
    stat = NO;
  }
  return stat;
}

