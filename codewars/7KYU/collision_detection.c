/* Create a function to determine whether or not two circles are colliding. 
 * You will be given the position of both circles in addition to their radii:

bool IsCollision(float x1, float y1, float r1, float x2, float y2, float r2)
  // collision?
}
If a collision is detected, return true. If not, return false.

Here's a geometric diagram of what the circles passed in represent: */
#include <stdbool.h>    /* bool */
#include <math.h>
bool IsCollision(float x1, float y1, float r1, float x2, float y2, float r2) {
  float d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));    
  return d > r1 + r2 ? false : true;
}
