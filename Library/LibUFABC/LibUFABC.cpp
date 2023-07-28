/* INCLUDE */
#include "LibUFABC.h"

/* DATA */
#if ESP8266
RF24 radio(1, 2); // CE, CSN
#else
RF24 radio(7, 8); // CE, CSN
#endif
const ubyte address[6] = "00001";
const ubyte radio_buffer[64] = {0};
const int radio_buffer_lenght = 64;

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
  radio.setPALevel(RF24_PA_MIN);
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
    // const char text[] = "Hello World";
    if (radio.write(radio_buffer_size, radio_buffer_size) == true)
    {
      Serial.println("write ok");
    }
    else
    {
      Serial.println("write failed");
    }
    delay(1000);
  }

  if (mode == RADIO_READ)
  {
    // char text[32] = "";
    if (radio.read(radio_buffer_size, radio_buffer_size) == true)
    {
      Serial.println("read ok");
    }
    else
    {
      Serial.println("read failed");
    }
    Serial.println(radio_buffer_size);
  }
}

// RADIO BUFFER
void getRadioBuffer(ubyte *buffer, int lenght, int offset_buffer, int offset_radio)
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

void setRadioBuffer(ubyte *buffer, int lenght, int offset_buffer, int offset_radio)
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
  getRadioBuffer(&value, sizeof(int), 0, offset);
  return value;
}

void setRadioBufferInt(int value, int offset)
{
  setRadioBuffer(&value, sizeof(int), 0, offset);
}