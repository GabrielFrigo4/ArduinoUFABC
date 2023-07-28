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

/*
#include "LibUFABC.h"
#include "SensorHumidade.h"

Sensor sensor = {};

void setup(){
  initSystem();
  initSensor(sensor);
  initRadio(RADIO_WRITE);
  Serial.println("Lendo a umidade do solo..."); //IMPRIME O TEXTO NO MONITOR SERIAL
  delay(2000); //INTERVALO DE 2 SEGUNDOS
}

void loop(){
  updateSensor(sensor);
  updateRadio(RADIO_WRITE);

  Serial.print("Umidade do solo: "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(sensor.valorLido); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
  Serial.println("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
  delay(100);
}
*/

#include <SPI.h>      //INCLUSÃO DE BIBLIOTECA
#include <nRF24L01.h> //INCLUSÃO DE BIBLIOTECA
#include <RF24.h>     //INCLUSÃO DE BIBLIOTECA

RF24 _radio(7, 8); // CRIA UMA INSTÂNCIA UTILIZANDO OS PINOS (CE, CSN)

const byte _address[6] = "00002"; // CRIA UM ENDEREÇO PARA ENVIO DOS
// DADOS (O TRANSMISSOR E O RECEPTOR DEVEM SER CONFIGURADOS COM O MESMO ENDEREÇO)

void setup()
{
  Serial.begin(9600); // INICIALIZA A SERIAL
  _radio.begin();
  _radio.setChannel(100);
  _radio.setPALevel(RF24_PA_MIN);
  _radio.setDataRate(RF24_250KBPS);
  _radio.setAutoAck(false);
  _radio.openWritingPipe(_address[0]);
  Serial.println("START!!!!!!!!");
}

void loop()
{
  const char text[] = "MasterWalker Shop"; // VARIÁVEL RECEBE A MENSAGEM A SER TRANSMITIDA
  if (_radio.write(&text, sizeof(text)) == true)
  {
    Serial.println("write ok");
  }
  else
  {
    Serial.println("write failed");
  }
  delay(1000); // INTERVALO DE 1 SEGUNDO
}
