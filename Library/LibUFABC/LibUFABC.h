/* INCLUDE */
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

/* TYPE */
typedef unsigned char ubyte;

/* DEFINE */
#define RADIO_READ 0
#define RADIO_WRITE 1
#define RADIO_BUFFER(x) (ubyte *)(x)
#define RADIO_STRING(x) (const char *)(x)
#define RADIO_TYPE(x) &x, sizeof(x)

/* FUNC */
// RADIO
void initSystem();
void initRadio(int mode);
void updateRadio(int mode);
// RADIO BUFFER
void getRadioBufferEx(ubyte *buffer, int lenght_buffer, int offset_buffer, int offset_radio, int lenght);
void setRadioBufferEx(ubyte *buffer, int lenght_buffer, int offset_buffer, int offset_radio, int lenght);
void getRadioBuffer(ubyte *buffer, int lenght);
void setRadioBuffer(ubyte *buffer, int lenght);
int getRadioBufferIntEx(int offset);
void setRadioBufferIntEx(int value, int offset);
int getRadioBufferInt();
void setRadioBufferInt(int value);
int getRaioBufferLenght();
bool getIsDataUpdated();
void cleanRadioBuffer();
// RADIO UTILS
void radioCopyMemory(ubyte *buffer_source, ubyte *buffer_copy, int lenght_source, int lenght_copy, int offset_source, int offset_copy, int lenght);
void radioDelay(int mode);
