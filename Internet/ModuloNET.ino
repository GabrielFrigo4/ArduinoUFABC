/* INCLUDE */
#include "LibUFABC.h"

/* CODE */
void setup(){
  initSystem();
  initWifi();
  initRadio(RADIO_READ);
}

void loop(){
  updateWifi();
  updateRadio(RADIO_READ);
}
