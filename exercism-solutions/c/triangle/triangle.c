#include "triangle.h"
#include <stdbool.h>

bool is_equilateral(triangle_t sides) {
   bool checkLength = sides.a && sides.b && sides.c != 0;
   if(checkLength) {
      if(sides.a == sides.b && sides.a == sides.c && sides.b == sides.c)
         return true;
      else
         return false;
   }
   return false;
}

bool is_isosceles(triangle_t sides) {
   bool checkLength = sides.a && sides.b && sides.c != 0;
   bool triangleInequality = (sides.a + sides.b >= sides.c) && (sides.b + sides.c >= sides.a) && (sides.a + sides.c >= sides.b);
   if(checkLength && triangleInequality) {
      if(sides.a == sides.b || sides.a == sides.c || sides.b == sides.c)
         return true;
      else
         return false;
   }
   return false;
}

bool is_scalene(triangle_t sides) {
   bool checkLength = sides.a && sides.b && sides.c != 0;
   bool triangleInequality = (sides.a + sides.b >= sides.c) && (sides.b + sides.c >= sides.a) && (sides.a + sides.c >= sides.b);
   if(checkLength && triangleInequality) {
      if(sides.a != sides.b && sides.a != sides.c && sides.b != sides.c)
         return true;
      else
         return false;
   }
   return false;
}
