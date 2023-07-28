/* INCLUDE */
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define RADIO_READ 0
#define RADIO_WRITE 1
typedef ubyte unsigned char;

/* FUNC */
void initSystem();
void initRadio(int mode);
void updateRadio(int mode);

void getRadioBuffer(ubyte *buffer, int lenght, int offset_buffer, int offset_radio);
void setRadioBuffer(ubyte *buffer, int lenght, int offset_buffer, int offset_radio);
int getRaioBufferLenght();
void cleanRadioBuffer();
int getRadioBufferInt(int offset);
void setRadioBufferInt(int value, int offset);