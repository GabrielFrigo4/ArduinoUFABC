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
#define GET_VALUE(x) x-1024

/* CODE */
void setup()
{
  delay(2000);
  FireBase_Init(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("INIT");
}

void loop()
{
  int umidade = Serial.parseInt();
  if(umidade >= 1024){
    umidade = GET_VALUE(umidade);
    Serial.println(umidade);
    FireBase_SetInt("sensors/sensor_01/humidity", umidade);
  }
  delay(128);
}
