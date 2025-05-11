/* Calculate area and perimeter of square, triangle, circle
 * define the formulas as preprocessor directive and a separate file
 * include that in the main program and execute
 */

#include <stdio.h>
#include "question_c.h"

int main(void) {
    printf("Ar.Triangle :: %.2f, Ar.Circle :: %.2f, Ar.Square :: %d\n",
            AREAOFTRIANGLE(10, 5), AREAOFCIRCLE(7), AREAOFSQUARE(6));

    printf("Peri.Triangle :: %d, Peri.Circle :: %.2f, Peri.Square :: %d\n",
            PERIMETEROFTRIANGLE(10, 8, 7), PERIMETEROFCIRCLE(7), PERIMETEROFSQUARE(6));
    return 0;
}
