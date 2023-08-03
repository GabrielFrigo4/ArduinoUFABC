/* INCLUDE */
#include "LibUFABC.h"
#define CHANNEL 0xFC
#define ADDRESS 0xFABC0BABACA0FEDE

/* DATA */
#if ESP8266
RF24 radio(1, 2); // CE, CSN
#else
RF24 radio(7, 8); // CE, CSN
#endif

#if BUFFER_SIZE
ubyte radio_buffer[BUFFER_SIZE] = {0};
int radio_buffer_lenght = BUFFER_SIZE;
#else
ubyte radio_buffer[32] = {0};
const int radio_buffer_lenght = 32;
#endif
const uint64_t address = ADDRESS;

/* CODE */
void initSystem()
{
  Serial.begin(9600);
#if ESP8266
  Serial.println("ESP8266");
#else
  Serial.println("ARDUINO");
#endif
}

// RADIO
void initRadio(int mode)
{
  radio.begin();
  if (mode == RADIO_READ)
  {
    radio.openReadingPipe(0, address);
  }
  else if (mode == RADIO_WRITE)
  {
    radio.openWritingPipe(address);
  }
  radio.setChannel(CHANNEL);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  if (mode == RADIO_READ)
  {
    radio.startListening();
  }
  else if (mode == RADIO_WRITE)
  {
    radio.stopListening();
  }
}

void updateRadio(int mode)
{
  if (mode == RADIO_WRITE)
  {
    radio.write(radio_buffer, radio_buffer_lenght);
  }

  if (mode == RADIO_READ)
  {
    radio.read(radio_buffer, radio_buffer_lenght);
  }
}

// RADIO BUFFER
void getRadioBufferEx(ubyte *buffer, int lenght, int offset_buffer, int offset_radio)
{
  if (lenght > radio_buffer_lenght - offset_radio)
  {
    lenght = radio_buffer_lenght - offset_radio;
  }
  for (int i = 0; i < lenght; i++)
  {
    buffer[i + offset_buffer] = radio_buffer[i + offset_radio];
  }
}

void setRadioBufferEx(ubyte *buffer, int lenght, int offset_buffer, int offset_radio)
{
  if (lenght > radio_buffer_lenght - offset_radio)
  {
    lenght = radio_buffer_lenght - offset_radio;
  }
  for (int i = 0; i < lenght; i++)
  {
    radio_buffer[i + offset_radio] = buffer[i + offset_buffer];
  }
}

void getRadioBuffer(ubyte *buffer, int lenght)
{
  getRadioBufferEx(buffer, lenght, 0, 0);
}

void setRadioBuffer(ubyte *buffer, int lenght)
{
  setRadioBufferEx(buffer, lenght, 0, 0);
}

int getRaioBufferLenght()
{
  return radio_buffer_lenght;
}

void cleanRadioBuffer()
{
  for (int i = 0; i < radio_buffer_lenght; i++)
  {
    radio_buffer[i] = 0;
  }
}

int getRadioBufferInt(int offset)
{
  int value;
  getRadioBufferEx(RADIO_BUFFER(&value), sizeof(int), 0, offset);
  return value;
}

void setRadioBufferInt(int value, int offset)
{
  setRadioBufferEx(RADIO_BUFFER(&value), sizeof(int), 0, offset);
}

// RADIO UTILS
void radioDelay(int mode)
{
  if (mode == RADIO_READ)
  {
    delay(550);
  }
  else if (mode == RADIO_WRITE)
  {
    delay(500);
  }
}
