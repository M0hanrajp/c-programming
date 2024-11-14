#include "darts.h"
#include <math.h>
float score(coordinate_t landing_position) {
   float pointScored = 0;
   pointScored = pow((landing_position.x - 0), 2) + pow((landing_position.y - 0), 2);
   if(pointScored > 25 && pointScored <= 100)
      return 1;
   if(pointScored > 1 && pointScored <= 25)
      return 5;
   if(pointScored >= 0 && pointScored <= 1)
      return 10;
   return 0;
}
