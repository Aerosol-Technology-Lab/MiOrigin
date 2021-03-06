// common properties shared by factory and ota firmware

#pragma once

#define RS232_RX2 27
#define RS232_TX2 26

#define I2C_SDA 21
#define I2C_SCL 22

#define VSPI_MISO MISO
#define VSPI_MOSI MOSI
#define VSPI_SCLK SCK
#define VSPI_SS 4

#define HSPI_MISO 25
#define HSPI_MOSI 13
#define HSPI_SCLK 14
#define HSPI_SS 17

#define SD_CS 17
#define LCD_CS 4
#define TCH_CS 16

#define LCD_DC 15

#define TCH_INT 32

#define LINE_TERMINATION    (uint16_t) 0x0D0A
#define FLUSH_SERIAL        (uint16_t) 0x0000

#include <Arduino.h>
#include <SPI.h>

extern SPIClass *vspi;
extern SPIClass *hspi;

void hardReset();

void Common_Init();

/**
 * @brief 
 * 
 * @param buffer 
 * @parstrcmpam stream 
 */
size_t readUntilEnd(char *buffer, size_t bufferSize, Stream &stream);

void Common_USBC_Handler(void *params);

void Common_HEX_print(char *cstr, Stream &stream = Serial);
