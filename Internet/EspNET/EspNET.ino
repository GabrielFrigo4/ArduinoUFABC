/* =======================================================================================================================================
https://www.robocore.net/tutoriais/programando-o-esp8266-pela-arduino-ide
======================================================================================================================================= */

/*



#include "FireBase.h"
#define WIFI_SSID "Wi-Fé"
#define WIFI_PASSWORD "manoelgomes"

void setup() {
  FireBase_Init(WIFI_SSID, WIFI_PASSWORD);
  FireBase_SetInt("sensors/sensor_01/humidity", 969);
}

void loop() {

}






*/











/* =======================================================================================================================================
https://www.robocore.net/tutoriais/programando-o-esp8266-pela-arduino-ide
https://blog.zerokol.com/2018/08/nrf24l01-com-nodemcu.html
======================================================================================================================================= */

/*
#include "LibUFABC.h"
#include "FireBase.h"
#define WIFI_SSID "Wi-Fé"
#define WIFI_PASSWORD "manoelgomes"

void setup() {
  //initSystem();
  //FireBase_Init(WIFI_SSID, WIFI_PASSWORD);
  //FireBase_SetInt("sensors/sensor_01/humidity", 969);
  //initRadio(RADIO_READ);
  Serial.begin(9600);
  #if ESP8266
  Serial.println("ESP8266");
  #else
  Serial.println("ARDUINO");  
  #endif
  Serial.println("AAAAAA");
  Serial.println("DDDDDD");
  Serial.println("SSSSSS");
  Serial.println("SSSSSSS");
  Serial.println("AAAAAA");
  Serial.println("DDDDD");
}

void loop() {
  //updateRadio(RADIO_READ);
}
*/



/*


#include <SPI.h> //INCLUSÃO DE BIBLIOTECA
#include <nRF24L01.h> //INCLUSÃO DE BIBLIOTECA
#include <RF24.h> //INCLUSÃO DE BIBLIOTECA
 
RF24 _radio(1, 2); //CRIA UMA INSTÂNCIA UTILIZANDO OS PINOS (CE, CSN)
 
const byte _address[6] = "00002"; //CRIA UM ENDEREÇO PARA ENVIO DOS
//DADOS (O TRANSMISSOR E O RECEPTOR DEVEM SER CONFIGURADOS COM O MESMO ENDEREÇO)
 
void setup() {
  Serial.begin(9600); //INICIALIZA A SERIAL
  Serial.println("START1");
  _radio.begin();
  _radio.setChannel(1);
  _radio.setPALevel(RF24_PA_MIN);
  _radio.setDataRate(RF24_250KBPS);
  _radio.setAutoAck(false);
  _radio.openReadingPipe(0, _address[0]);
  _radio.startListening();

  // Start RF
  _radio.begin();
  // Setup the channel to work within, number 100
  _radio.setChannel(100);
  // Open recept pipe
  _radio.openReadingPipe(1, _address);
  // Start to listen
  _radio.startListening();

  Serial.println("START2");
  #if ESP8266
  Serial.println("ESP8266");
  #else
  Serial.println("ARDUINO");  
  #endif
}

void loop() {
  if (_radio.available()) { //SE A COMUNICAÇÃO ESTIVER HABILITADA, FAZ
    char text[32] = ""; //VARIÁVEL RESPONSÁVEL POR ARMAZENAR OS DADOS RECEBIDOS
    _radio.read(&text, sizeof(text)); 



    
    if(_radio.read(&text, sizeof(text)) == true){
      Serial.println("read ok");
    } else {
      Serial.println("read failed");
    }



    
    Serial.println(text); //IMPRIME NA SERIAL OS DADOS RECEBIDOS
  } else {
    Serial.println(":(");
  }
  delay(1000);
}




*/













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
