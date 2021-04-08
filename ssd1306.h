/**
 * This Library is written and optimized by Olivier Van den Eede(4ilo) in 2016
 * for Stm32 Uc and HAL-i2c lib's.
 *
 * To use this library with ssd1306 oled display you will need to customize the defines below.
 *
 * This library uses 2 extra files (fonts.c/h).
 * In this files are 3 different fonts you can use:
 *     - Font_7x10
 *     - Font_11x18
 *     - Font_16x26
 *	if (ssd1306_Init(12) != 0) {
		//Error_Handler();
	}
	
	//-------------SSD1306
	ssd1306_Fill(Black);
	ssd1306_UpdateScreen(12);

	delayMS(1000);

	// Write data to local screenbuffer
	ssd1306_SetCursor(0, 8);
	ssd1306_WriteString("ssd1306", ssd1306_Font_16x26, White);
	ssd1306_UpdateScreen(12);
 */

#ifndef _SSD1306_H
#define _SSD1306_H

#include "stm32f4xx_hal.h"
#include "ssd1306_fonts.h"

// I2c address
#ifndef SSD1306_I2C_ADDR
#define SSD1306_I2C_ADDR        0x3c
#endif // SSD1306_I2C_ADDR

// SSD1306 width in pixels
#ifndef SSD1306_WIDTH
#define SSD1306_WIDTH           128
#endif // SSD1306_WIDTH

// SSD1306 LCD height in pixels
#ifndef SSD1306_HEIGHT
#define SSD1306_HEIGHT          64
#endif // SSD1306_HEIGHT


//
//  Enumeration for screen colors
//
typedef enum {
    Black = 0x00,   // Black color, no pixel
    White = 0x01,   // Pixel is set. Color depends on LCD
} SSD1306_COLOR;

//
//  Struct to store transformations
//
typedef struct {
    uint16_t CurrentX;
    uint16_t CurrentY;
    uint8_t Inverted;
    uint8_t Initialized;
} SSD1306_t;

//
//  Function definitions
//

uint8_t ssd1306_Init(uint8_t hi2c);
void ssd1306_UpdateScreen(uint8_t hi2c);
void ssd1306_Fill(SSD1306_COLOR color);
void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color);
char ssd1306_WriteChar(char ch, ssd1306_FontDef Font, SSD1306_COLOR color);
char ssd1306_WriteString(char* str, ssd1306_FontDef Font, SSD1306_COLOR color);
void ssd1306_SetCursor(uint8_t x, uint8_t y);
void ssd1306_InvertColors(void);

#endif  // _SSD1306_H
