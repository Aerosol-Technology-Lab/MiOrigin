// common properties shared by factory and ota firmware

#pragma once

#define RX2 27
#define TX2 26

#define VSPI_MISO MISO
#define VSPI_MOSI MOSI
#define VSPI_SCLK SCK
#define VSPI_SS SS

#define HSPI_MISO 25
#define HSPI_MOSI 13
#define HSPI_SCLK 14
#define HSPI_SS 17

#define SD_CS 17
#define LCD_CS 4

#define LCD_DC 15

#include <Arduino.h>
#include <SPI.h>

extern SPIClass *vspi;
extern SPIClass *hspi;

void Common_Init();

void readUntilEnd(char *buffer, Stream &stream);

void Common_USBC_Handler(void *params);
