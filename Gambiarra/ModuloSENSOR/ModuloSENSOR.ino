/* =======================================================================================================================================
https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-medidor-de-umidade-do-solo-higrometro
https://br-arduino.org/2014/12/arduino-e-bateria-providencias-simples-para-reduzir-o-consumo.html
https://eletronicaparaartistas.com.br/arduino-2-configuracao-do-arduino-nano/
======================================================================================================================================= */

/* INCLUDE */
#include <Wire.h>
#include "SensorHumidade.h"
#define PIN_DATA 4

/* DATA */
Sensor sensor = {};

/* CODE */
void setup()
{
  initWire(PIN_DATA);
  initSensor(sensor);
  Serial.println("INIT");
}

void loop()
{
  updateSensor(sensor);  
  delay(256);
}

void initWire(int init){
  Wire.begin(init);
}

void sendWire(int value){
  Wire.beginTransmission(PIN_DATA);
  Wire.write(sensor.valorLido);
  Wire.endTransmission();
}
