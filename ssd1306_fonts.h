#ifndef _FONTS_H
#define _FONTS_H

#include <stdint.h>

//
//  Structure used to define fonts
//
typedef struct {
    const uint8_t FontWidth;    /* Font width in pixels */
    uint8_t FontHeight;         /* Font height in pixels */
    const uint16_t *data;       /* Pointer to data font data array */
} ssd1306_FontDef;

//
//  Export the 3 available fonts
//
extern ssd1306_FontDef ssd1306_Font_7x10;
extern ssd1306_FontDef ssd1306_Font_11x18;
extern ssd1306_FontDef ssd1306_Font_16x26;

#endif  // _FONTS_H
