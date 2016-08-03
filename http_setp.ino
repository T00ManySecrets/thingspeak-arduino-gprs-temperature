// HTTP INITIALISATION IF OK RETURN 'YES'
int http_setup()
{
  int stat = YES;
  char back;
  unsigned long int count;
  myserial.println("AT+SAPBR=0,1");  //bearer profile
  back = myserial.read();
  for (count = 0; back != 'K' && back != 'E'; count++)
  {
    back = myserial.read();
    if (back == 'K')
    {
      Serial.println("profile 1 close ok");
      delay(1000);
    }
  }
  myserial.println("AT+SAPBR=0,2");  //bearer profile
  back = myserial.read();
  for (count = 0; back != 'K' && back != 'E'; count++)
  {
    back = myserial.read();
    if (back == 'K')
    {
      Serial.println("profile 2 close ok");
      delay(2000);
    }
  }
  myserial.println("AT+SAPBR=0,3");  //bearer profile
  back = myserial.read();
  for (count = 0; back != 'K' && back != 'E'; count++)
  {
    back = myserial.read();
    if (back == 'K')
    {
      Serial.println("profile 3 close ok");
      delay(2000);
    }
  }
  myserial.println("AT+SAPBR=1,1");  //bearer profile
  back = myserial.read();
  for (count = 0; back != 'K' && back != 'E'; count++)
  {
    back = myserial.read();
    if (back == 'K')
    {
      Serial.println("profile 1 open ok");
      delay(2000);
    }
  }
  myserial.println("AT+SAPBR=2,1");  //bearer profile
  back = myserial.read();
  for (count = 0; back != 'K' && back != 'E'; count++)
  {
    back = myserial.read();
    if (back == 'K')
    {
      Serial.println("query profile 1 ok");
      delay(2000);
    }
  }
  myserial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");  //bearer profile
  back = myserial.read();
  for (count = 0; back != 'K' && back != 'E'; count++)
  {
    back = myserial.read();
    if (back == 'K')
    {
      Serial.println("GPRS MODE SET");
    }
  }
  myserial.println("AT+SAPBR=3,1,\"APN\",\"" + APN + "\""); //bearer profile
  back = myserial.read();
  for (count = 0; back != 'K' && back != 'E'; count++)
  {
    back = myserial.read();
    if (back == 'K')
    {
      Serial.println("APN set ok");
    }
  }
}
