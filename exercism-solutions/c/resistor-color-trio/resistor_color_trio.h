#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <math.h>
typedef enum { BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE } resistor_band_t;
typedef enum { OHMS, KILOOHMS, MEGAOHMS, GIGAOHMS } resistor_unit;
typedef struct { unsigned long int value; resistor_unit unit; } resistor_value_t;
resistor_value_t color_code(resistor_band_t color[]);
#endif
