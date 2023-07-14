/* INCLUDE */
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define RADIO_READ 0
#define RADIO_WRITE 1

/* TYPES */
struct Sensor {
  const int pinoSensor = A0; //PINO UTILIZADO PELO SENSOR
  int valorLido; //VARIÁVEL QUE ARMAZENA O PERCENTUAL DE UMIDADE DO SOLO

  int analogSoloSeco = 400; //VALOR MEDIDO COM O SOLO SECO (VOCÊ PODE FAZER TESTES E AJUSTAR ESTE VALOR)
  int analogSoloMolhado = 150; //VALOR MEDIDO COM O SOLO MOLHADO (VOCÊ PODE FAZER TESTES E AJUSTAR ESTE VALOR)
  int percSoloSeco = 0; //MENOR PERCENTUAL DO SOLO SECO (0% - NÃO ALTERAR)
  int percSoloMolhado = 100; //MAIOR PERCENTUAL DO SOLO MOLHADO (100% - NÃO ALTERAR)  
};

/* FUNC */
void initSystem();
void initSensor(Sensor &sensor);
void initRadio(int mode);
void updateSensor(Sensor &senso);
void updateRadio(int mode);
