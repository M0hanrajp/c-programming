#include "resistor_color_duo.h"

short int color_code(resistor_band_t color[]) {
   return ((color[0] * 10) + (color[1]));
}
