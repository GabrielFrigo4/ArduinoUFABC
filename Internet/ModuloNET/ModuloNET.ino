/* =======================================================================================================================================
======================================================================================================================================= */

/* INCLUDE */
#include "LibUFABC.h"

/* CODE */
void setup()
{
  initSystem();
  initRadio(RADIO_READ);
}

void loop()
{
  updateRadio(RADIO_READ);
  
  ubyte buf[32];
  getRadioBuffer(buf, sizeof(buf));
  Serial.println(RADIO_STRING(buf));
  radioDelay(RADIO_READ);
}
