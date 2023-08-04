/* =======================================================================================================================================
https://github.com/mobizt/Firebase-ESP8266
======================================================================================================================================= */

/* INCLUDE */
#include "LibUFABC.h"
#define TEST

/* CODE */
void setup()
{
  initSystem();
  initRadio(RADIO_READ);
}

void loop()
{
  updateRadio(RADIO_READ);

  int umidade = getRadioBufferInt();
  Serial.println(umidade);
  radioDelay(RADIO_READ);
}
