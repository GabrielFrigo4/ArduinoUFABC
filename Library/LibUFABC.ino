/* INCLUDE */
#include "LibUFABC.h"

/* DATA */
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

/* CODE */
void initSystem(){
  Serial.begin(9600);
}

void initWifi(){

}

void initSensor(Sensor &sensor){
  Serial.println("Lendo a umidade do solo..."); //IMPRIME O TEXTO NO MONITOR SERIAL
  delay(2000); //INTERVALO DE 2 SEGUNDOS
}

void initRadio(int mode){
  radio.begin();
  if(init == RADIO_READ){
    radio.openReadingPipe(0, address);
  }
  else if(init == RADIO_WRITE){
    radio.openWritingPipe(address);
  }  
  radio.setPALevel(RF24_PA_MIN);
  if(init == INIT_RADIO_READ){
    radio.startListening();
  }
  else if(init == RADIO_WRITE){
    radio.stopListening(); 
  }  
}

void updateWifi(){

}

void updateSensor(Sensor &senso){
  valorLido = constrain(analogRead(pinoSensor),analogSoloMolhado,analogSoloSeco); //MANTÉM valorLido DENTRO DO INTERVALO (ENTRE analogSoloMolhado E analogSoloSeco)
  valorLido = map(valorLido,analogSoloMolhado,analogSoloSeco,percSoloMolhado,percSoloSeco); //EXECUTA A FUNÇÃO "map" DE ACORDO COM OS PARÂMETROS PASSADOS
  Serial.print("Umidade do solo: "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(valorLido); //IMPRIME NO MONITOR SERIAL O PERCENTUAL DE UMIDADE DO SOLO
  Serial.println("%"); //IMPRIME O CARACTERE NO MONITOR SERIAL
  delay(1000);  //INTERVALO DE 1 SEGUNDO
}

void updateRadio(int mode){
  if(mode == RADIO_WRITE){
    const char text[] = "Hello World";
    radio.write(&text, sizeof(text));
    delay(1000);    
  }

  if(mode == RADIO_READ){
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
