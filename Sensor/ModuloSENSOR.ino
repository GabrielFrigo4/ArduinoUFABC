/* =======================================================================================================================================
https://github.com/mobizt/Firebase-ESP8266
#if defined(PICO_RP2040)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-medidor-de-umidade-do-solo-higrometro
https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/
https://docs.arduino.cc/learn/contributions/arduino-creating-library-guide
======================================================================================================================================= */

/* INCLUDE */
#include "LibUFABC.h"

/* DATA */
Sensor sensor;

/* CODE */
void setup(){
  initSensor(&sensor);
  initRadio();
}

void loop(){
  updateSensor(&sensor);
  updateRadio();
}
