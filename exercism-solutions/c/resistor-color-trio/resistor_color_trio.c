#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t color[]) {
   static resistor_value_t some;
   if(color[2] == BLACK) {
      some.value = (color[0] * 10) + color[1];
   }
   if(color[2] != BLACK) {
      some.value = (color[0] * 10) + color[1];
      some.value *= pow(10, color[2]);
      if(color[2] > 1 && color[2] < 6)
         some.value /= 1000;
      if(color[2] > 5 && color[2] < 9)
         some.value /= 1000000;
      if(color[2] > 8)
         some.value /= 1000000000;
   }
   some.unit = color[2] < 2 ? OHMS : color[2] < 6 ? KILOOHMS : color[2] < 9 ? MEGAOHMS : GIGAOHMS;
   return some;
}
