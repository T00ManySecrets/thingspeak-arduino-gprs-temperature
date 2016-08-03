#include <Arduino.h>
#include <avr/wdt.h>
#include <SoftwareSerial.h>
#define DS18S20_ID 0x10
#define DS18B20_ID 0x28
#include <OneWire.h>
OneWire  ds(5);  // on pin 5 (a 4.7K resistor is necessary)

SoftwareSerial myserial(6, 7);
const int YES = 1;
const int NO = 0;
const String APN = "YOUR APN";
float temp;
float temp1;
float batt1;
const int batt_sens_input_pin = A0;
void setup()
{
  wdt_disable();
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  delay(3000);
  digitalWrite(8, LOW);

  Serial.begin(9600);
  myserial.begin(9600);
  Serial.println("waiting for modem");
  delay(8000);
  gsm_init();
  Serial.println("GSM INITIALISATION COMPLETE");
  http_setup();
  Serial.println("HTTP SETUP COMPLETE");
  http_init();
  Serial.println("HTTP INITIALISATION COMPLETE");
}
void loop()
{
  wdt_enable(WDTO_8S);
  ///////////////////////////////////////////////////////////

  if ( getTemperature() == YES) // only send data if sensor working
  {

    temp1 = temp;  // YOU CAN ADD THE SENSOR READ FUNCTION HERE
    batt1 = analogRead(batt_sens_input_pin);
    batt1 = (batt1 * 4.5) / 1023;

    wdt_disable();
    wdt_enable(WDTO_8S);
    if (sent_dat() == YES)
    {
      wdt_disable();
      delay(60000);
    }
    else
    {
      wdt_disable();
      wdt_enable(WDTO_8S);
      gsm_init();  // repeated gsm initialisation
      wdt_disable();
      wdt_enable(WDTO_8S);
      http_termination();  // repeated http termination
      wdt_disable();
      wdt_enable(WDTO_8S);
      http_setup();   // repeated http setup
      wdt_disable();
      wdt_enable(WDTO_8S);
      Serial.println("HTTP SETUP COMPLETE");
      http_init();         // repeated http initialisation
      wdt_disable();
      wdt_enable(WDTO_8S);
      Serial.println("HTTP INITIALISATION COMPLETE");
      wdt_disable();
      delay(2000);
    }
  }
}


