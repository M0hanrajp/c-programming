#include "space_age.h"

float age(planet_t planet, int64_t seconds) {
   switch (planet) {
      case 0:
         return seconds/(31557600 * 0.2408467);
      case 1:
         return seconds/(31557600 * 0.61519726);
      case 2:
         return seconds/(31557600 * 1.0);
      case 3:
         return seconds/(31557600.0 * 1.8808158);
      case 4:
         return seconds/(31557600.0 * 11.862615);
      case 5:
         return seconds/(31557600.0 * 29.447498);
      case 6:
         return seconds/(31557600.0 * 84.016846);
      case 7:
         return seconds/(31557600.0 * 164.79132);
      default:
         return -1;
   }
}
