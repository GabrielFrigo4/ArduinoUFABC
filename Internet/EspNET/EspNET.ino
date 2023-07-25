/* =======================================================================================================================================
https://www.robocore.net/tutoriais/programando-o-esp8266-pela-arduino-ide
======================================================================================================================================= */

#include "FireBase.h"
#define WIFI_SSID "Wi-Fé"
#define WIFI_PASSWORD "manoelgomes"

void setup() {
  FireBase_Init(WIFI_SSID, WIFI_PASSWORD);
  FireBase_SetInt("sensors/sensor_01/humidity", 969);
}

void loop() {

}