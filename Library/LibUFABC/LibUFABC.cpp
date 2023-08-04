/* INCLUDE */
#include "LibUFABC.h"
#define CHANNEL 0xFC
#define ADDRESS 0xFABC0BABACA0FEDE

/* DATA */
RF24 radio(7, 8); // CE, CSN

/* DEFINE */
#define BUFFER_TO_REALBUFFER(x) x - 1
#define REALBUFFER_TO_BUFFER(x) x + 1
#define BUFFERSIZE_TO_REALBUFFERSIZE(x) x + 1
#define REALBUFFERSIZE_TO_BUFFERSIZE(x) x - 1
#define BUFFER_INIT 0xFF
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif
#define BUFFER_REAL_SIZE BUFFERSIZE_TO_REALBUFFERSIZE(BUFFER_SIZE)

/* DATA */
ubyte radio_buffer[BUFFER_REAL_SIZE] = {0};
const uint64_t address = ADDRESS;
bool is_data_updated = false;

/* CODE */
void initSystem()
{
  Serial.begin(9600);
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
    radio.write(radio_buffer, BUFFER_SIZE);
  }

  if (mode == RADIO_READ)
  {
    ubyte buf[BUFFER_REAL_SIZE] = {0};
    radio.read(buf, BUFFER_REAL_SIZE);
    if (buf[0] == BUFFER_INIT)
    {
      radioCopyMemory(buf, radio_buffer, BUFFER_REAL_SIZE, BUFFER_REAL_SIZE, 0, 0, BUFFER_REAL_SIZE);
      is_data_updated = true;
    }
    else
    {
      is_data_updated = false;
    }
  }
}

// RADIO BUFFER
void getRadioBufferEx(ubyte *buffer, int lenght_buffer, int offset_buffer, int offset_radio, int lenght)
{
  radioCopyMemory(REALBUFFER_TO_BUFFER(radio_buffer), buffer, BUFFER_SIZE, lenght_buffer, offset_radio, offset_buffer, lenght);
}

void setRadioBufferEx(ubyte *buffer, int lenght_buffer, int offset_buffer, int offset_radio, int lenght)
{
  radio_buffer[0] = BUFFER_INIT;
  radioCopyMemory(buffer, REALBUFFER_TO_BUFFER(radio_buffer), lenght_buffer, BUFFER_SIZE, offset_buffer, offset_radio, lenght);
}

void getRadioBuffer(ubyte *buffer, int lenght)
{
  getRadioBufferEx(buffer, lenght, 0, 0, lenght);
}

void setRadioBuffer(ubyte *buffer, int lenght)
{
  setRadioBufferEx(buffer, lenght, 0, 0, lenght);
}

int getRadioBufferIntEx(int offset)
{
  int value;
  getRadioBufferEx(RADIO_BUFFER(&value), sizeof(int), 0, offset, sizeof(int));
  return value;
}

void setRadioBufferIntEx(int value, int offset)
{
  setRadioBufferEx(RADIO_BUFFER(&value), sizeof(int), 0, offset, sizeof(int));
}

int getRadioBufferInt()
{
  return getRadioBufferIntEx(0);
}

void setRadioBufferInt(int value)
{
  setRadioBufferIntEx(value, 0);
}

int getRaioBufferLenght()
{
  return BUFFER_SIZE;
}

bool getIsDataUpdated()
{
  return is_data_updated;
}

void cleanRadioBuffer()
{
  for (int i = 0; i < BUFFER_SIZE; i++)
  {
    radio_buffer[i] = 0;
  }
}

// RADIO UTILS
void radioCopyMemory(ubyte *buffer_source, ubyte *buffer_copy, int lenght_source, int lenght_copy, int offset_source, int offset_copy, int lenght)
{
  if (lenght > lenght_source - offset_source)
  {
    lenght = lenght_source - offset_source;
  }
  if (lenght > lenght_copy - offset_copy)
  {
    lenght = lenght_copy - offset_copy;
  }
  for (int i = 0; i < lenght; i++)
  {
    buffer_copy[i + offset_copy] = buffer_source[i + offset_source];
  }
}

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
