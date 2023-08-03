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
https://maniacbug.github.io/RF24/classRF24.html
======================================================================================================================================= */

/* INCLUDE */
#include "LibUFABC.h"
#include "SensorHumidade.h"

/* DATA */
Sensor sensor = {};

/* CODE */
void setup()
{
  initSystem();
  initSensor(sensor);
  initRadio(RADIO_WRITE);
}

void loop()
{
  updateSensor(sensor);
  updateRadio(RADIO_WRITE);
  
  ubyte buf[16] = "Hello World!!";
  setRadioBuffer(buf, sizeof(buf));
  
  Serial.print("Umidade do solo: "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(sensor.valorLido); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
  Serial.println("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
  radioDelay(RADIO_WRITE);
}
