#include <stdbool.h>
#include <math.h>
bool equable_triangle(unsigned a, unsigned b, unsigned c) {
  unsigned s = 0;s = (a + b + c) / 2;
  return (sqrt((s * (s - a) * (s - b) * (s - c)))) == (a + b + c);
}
