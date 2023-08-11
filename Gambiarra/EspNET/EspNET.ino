/* =======================================================================================================================================
https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/
https://www.robocore.net/tutoriais/programando-o-esp8266-pela-arduino-ide
https://forum.arduino.cc/t/simple-nrf24l01-2-4ghz-transceiver-demo/405123
https://forum.arduino.cc/t/nrf24l01-not-working-solved/697425
https://blog.zerokol.com/2018/08/nrf24l01-com-nodemcu.html
======================================================================================================================================= */

/* INCLUDE */
#include "FireBase.h"
#define WIFI_SSID "wif"
#define WIFI_PASSWORD "manuelgumes"
#define GET_VALUE(x) x - 1024

/* DATA */
int umidade;

/* CODE */
void setup()
{
  delay(256);
  FireBase_Init(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("INIT");
  Serial.flush();
}

void loop()
{
  int _umidade = Serial.parseInt();
  if (_umidade >= 1024)
  {
    _umidade = GET_VALUE(_umidade);
    if (_umidade != umidade)
    {
      umidade = _umidade;
      Serial.println(umidade);
      FireBase_SetInt("sensors/sensor_01/humidity", umidade);
    }
  }
  delay(16);
}
