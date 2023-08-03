/* INCLUDE */
#include "SensorHumidade.h"

void initSensor(Sensor &sensor)
{
  Serial.println("Lendo a umidade do solo..."); // IMPRIME O TEXTO NO MONITOR SERIAL
  delay(2000); //INTERVALO DE 2 SEGUNDOS
}

/* CODE */
void updateSensor(Sensor &sensor)
{
  sensor.valorLido = constrain(
      analogRead(sensor.pinoSensor),
      sensor.analogSoloMolhado,
      sensor.analogSoloSeco); // MANTÉM valorLido DENTRO DO INTERVALO (ENTRE analogSoloMolhado E analogSoloSeco)

  sensor.valorLido = map(
      sensor.valorLido,
      sensor.analogSoloMolhado,
      sensor.analogSoloSeco,
      sensor.percSoloMolhado,
      sensor.percSoloSeco); // EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS

  Serial.print("Umidade do solo: "); // IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(sensor.valorLido);    // IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
  Serial.println("%");               // IMPRIME O CARACTERE NO MONITOR SERIAL
}
