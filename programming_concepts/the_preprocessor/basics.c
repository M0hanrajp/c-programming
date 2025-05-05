#include <stdio.h>

// macro templates and their expansions
#define PI 3.14 // a constant PI
#define AREAOFCIRCLE(r) (PI * r * r) // macro with arguments
/* AREAOFCIRCLE - macro template that takes one argument r (radii)
 * this template expands to code (PI * r * r)
 */
#define PRINT(a) printf("Area of circle is :: %.2f\n", a)

int main(void) {
    float c1 = AREAOFCIRCLE(3);
    PRINT(c1);
    // or we can do it this way
    PRINT(AREAOFCIRCLE(4));
    return 0;
}
