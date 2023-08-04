/* =======================================================================================================================================
https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-medidor-de-umidade-do-solo-higrometro
https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/
https://docs.arduino.cc/learn/contributions/arduino-creating-library-guide
https://maniacbug.github.io/RF24/classRF24.html

https://br-arduino.org/2014/12/arduino-e-bateria-providencias-simples-para-reduzir-o-consumo.html
https://eletronicaparaartistas.com.br/arduino-2-configuracao-do-arduino-nano/
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

  Serial.print("Umidade do solo: "); // IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(sensor.valorLido);    // IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
  Serial.println("%");               // IMPRIME O CARACTERE NO MONITOR SERIAL
  setRadioBufferInt(sensor.valorLido);

  radioDelay(RADIO_WRITE);
}
