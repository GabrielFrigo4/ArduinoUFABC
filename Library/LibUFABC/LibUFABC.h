/* INCLUDE */
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define RADIO_READ 0
#define RADIO_WRITE 1

/* FUNC */
void initSystem();
void initRadio(int mode);
void updateRadio(int mode);
void getDataRadio();
void setDataRadio();
