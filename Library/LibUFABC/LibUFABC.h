/* INCLUDE */
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

typedef unsigned char ubyte;

#define RADIO_READ 0
#define RADIO_WRITE 1
#define RADIO_BUFFER(x) (ubyte *)(x)
#define RADIO_STRING(x) (const char *)(x)
#define RADIO_TYPE(x) &x, sizeof(x)

/* FUNC */
void initSystem();
void initRadio(int mode);
void updateRadio(int mode);

void getRadioBufferEx(ubyte *buffer, int lenght, int offset_buffer, int offset_radio);
void setRadioBufferEx(ubyte *buffer, int lenght, int offset_buffer, int offset_radio);
void getRadioBuffer(ubyte *buffer, int lenght);
void setRadioBuffer(ubyte *buffer, int lenght);
int getRaioBufferLenght();
void cleanRadioBuffer();
int getRadioBufferInt(int offset);
void setRadioBufferInt(int value, int offset);
void radioDelay(int mode);
