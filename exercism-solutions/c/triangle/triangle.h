#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdbool.h>

typedef struct {
   double a;
   double b;
   double c;
} triangle_t;

// Below function were not added in the program
bool is_equilateral(triangle_t sides);
bool is_isosceles(triangle_t sides);
bool is_scalene(triangle_t sides);

#endif
