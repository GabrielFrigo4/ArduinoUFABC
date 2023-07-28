#include <Arduino.h>

struct Sensor {
  const int pinoSensor = A0; //PINO UTILIZADO PELO SENSOR
  const int analogSoloSeco = 623; //VALOR MEDIDO COM O SOLO SECO (VOCÊ PODE FAZER TESTES E AJUSTAR ESTE VALOR)
  const int analogSoloMolhado = 340; //VALOR MEDIDO COM O SOLO MOLHADO (VOCÊ PODE FAZER TESTES E AJUSTAR ESTE VALOR)
  const int percSoloSeco = 0; //MENOR PERCENTUAL DO SOLO SECO (0% - NÃO ALTERAR)
  const int percSoloMolhado = 100; //MAIOR PERCENTUAL DO SOLO MOLHADO (100% - NÃO ALTERAR)  

  int valorLido = 0; //VARIÁVEL QUE ARMAZENA O PERCENTUAL DE UMIDADE DO SOLO
};

void initSensor(Sensor &sensor);
void updateSensor(Sensor &senso);
