/* INCLUDE */
#include "LibUFABC.h"

/* DATA */
#if ESP8266
RF24 radio(1, 2); // CE, CSN
#else
RF24 radio(7, 8); // CE, CSN
#endif
const byte address[6] = "00001";

/* CODE */
void initSystem(){
  Serial.begin(9600);
  #if ESP8266
  Serial.println("ESP8266");
  #else
  Serial.println("ARDUINO");  
  #endif
}

// RADIO
void initRadio(int mode){
  radio.begin();
  if(mode == RADIO_READ){
    radio.openReadingPipe(0, address);
  }
  else if(mode == RADIO_WRITE){
    radio.openWritingPipe(address);
  }  
  radio.setPALevel(RF24_PA_MIN);
  if(mode == RADIO_READ){
    radio.startListening();
  }
  else if(mode == RADIO_WRITE){
    radio.stopListening(); 
  }  
}

void updateRadio(int mode){
  if(mode == RADIO_WRITE){
    const char text[] = "Hello World";
    if(radio.write(&text, sizeof(text)) == true){
      Serial.println("write ok");
    } else {
      Serial.println("write failed");
    }
    delay(1000);    
  }

  if(mode == RADIO_READ){
    char text[32] = "";
    if(radio.read(&text, sizeof(text)) == true){
      Serial.println("read ok");
    } else {
      Serial.println("read failed");
    }
    Serial.println(text);
  }
}

void getDataRadio(){

}

void setDataRadio(){

}
