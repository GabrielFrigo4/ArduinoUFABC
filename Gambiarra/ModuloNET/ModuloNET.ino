/* =======================================================================================================================================
https://stackoverflow.com/questions/62363122/how-to-transfer-an-integer-from-an-arduino-to-another-arduino
https://forum.arduino.cc/t/serial-communication-from-arduino-nano-to-esp8266/615666
https://docs.arduino.cc/tutorials/nano-33-ble/i2c
https://docs.arduino.cc/learn/communication/wire
https://github.com/mobizt/Firebase-ESP8266
======================================================================================================================================= */

/* INCLUDE */
#include <Wire.h>
#define PIN_DATA 4
#define SET_VALUE(x) x + 1024

/* DATA */
int umidade;

/* CODE */
void setup()
{
  delay(4096);
  initWire(PIN_DATA);
  Serial.println("INIT");
}

void loop()
{
  Serial.println(SET_VALUE(umidade));
  delay(512);
}

void initWire(int init)
{
  Serial.begin(9600);
  Wire.begin(init);
  Wire.onReceive(receiveEvent);
}

void receiveEvent(int howMany)
{
  umidade = Wire.read();
}
