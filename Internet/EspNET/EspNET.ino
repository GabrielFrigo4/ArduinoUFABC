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












#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

// Instantiate RF24 class with CE and CSN values
RF24 radio(2, 15);
// Address to devices comunicate each other (same in both)
const byte _address[6] = "00002";
// A variable to hold some info
boolean testInfo = false;

void setup() {
  // Setup serial output
  Serial.begin(9600);
  // Start RF
  radio.begin();
  // Setup the channel to work within, number 100
  radio.setChannel(100);
  // Open recept pipe
  radio.openReadingPipe(1, _address[0]);
  // Start to listen
  radio.startListening();
}

void loop() {
  // Wait until some data
  if (radio.available()) {
    // Read payload, and check if it finished
    radio.read(&testInfo, sizeof(testInfo));
    // Manage info
    if (testInfo) {
      Serial.println("We received positive!");
    } else {
      Serial.println("We received negative!");
    }
  }
  // Wait a bit
  delay(50);
}
