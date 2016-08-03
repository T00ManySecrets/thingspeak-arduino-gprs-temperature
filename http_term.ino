// HTTP TERMINATION
void http_termination()
{
  char back;
  myserial.println("AT+HTTPTERM");
  back = myserial.read();
  for (int i = 0; back != 'K' && back != 'E'; i++)
  {
    back = myserial.read();
  }
  Serial.println("DONE HTTP TERMINATION");
}
