/* =======================================================================================================================================
https://www.robocore.net/tutoriais/programando-o-esp8266-pela-arduino-ide
https://blog.zerokol.com/2018/08/nrf24l01-com-nodemcu.html
https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/
https://forum.arduino.cc/t/nrf24l01-not-working-solved/697425
https://forum.arduino.cc/t/simple-nrf24l01-2-4ghz-transceiver-demo/405123
======================================================================================================================================= */

#include "FireBase.h"
#define WIFI_SSID "Wi-Fé"
#define WIFI_PASSWORD "manoelgomes"

void setup()
{
  FireBase_Init(WIFI_SSID, WIFI_PASSWORD);
}

void loop()
{
  int umidade = Serial.parseInt();
  Serial.println(umidade);
  FireBase_SetInt("sensors/sensor_01/humidity", umidade);
}
