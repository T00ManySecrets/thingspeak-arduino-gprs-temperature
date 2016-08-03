//data senting
int sent_dat()
{

  //  Serial.println("AT+HTTPPARA=\"URL\",\"http://techant.co.in/ext/botz/p1/pg1.aspx?a=" + String(latt) + "&b=" + String(longi) + " \"");
  myserial.print("AT+HTTPPARA=\"URL\",\"http://api.thingspeak.com/update?api_key=YOUR API KEY HERE&field1=");
  myserial.print(temp1);
  myserial.print("&&field2=");
  myserial.print(batt1);
  myserial.println("\"");
  char back = myserial.read();
  while (back != 'E' && back != 'K')   // wait until a ERROR/OK return
  {
    back = myserial.read();
  }
  if (back == 'E')   // if error is got then retun NO
  {
    return NO;
  }
  else               // if OK is got then retun YES
  {
    Serial.println("connecting to send");
    myserial.println("AT+HTTPPARA=\"CID\",1");
    char back = myserial.read();
    while (back != 'E' && back != 'K')   // wait until a ERROR/OK return
    {
      back = myserial.read();
      if (back == 'K')
      {
        Serial.println("done para");
      }
    }
    if (back == 'E')   // if error is got then retun NO
    {
      return NO;
    }
    else
    {
      myserial.println("AT+HTTPACTION=0");
      char back = myserial.read();
      while (back != 'E' && back != 'K')   // wait until a ERROR/OK return
      {
        back = myserial.read();
      }
      if (back == 'E')   // if error is got then retun NO
      {
        return NO;
      }
      else
      {
        Serial.println("done para");
        Serial.println("wait for conformation");
        back = myserial.read();
        while (back != '+' && back != 'H')   // wait until a ERROR/OK return
        {
          back = myserial.read();
        }
        Serial.println("DONE SENT");
        while (myserial.available())
        {
          myserial.read();
        }
        return YES;
      }
    }
  }
}
