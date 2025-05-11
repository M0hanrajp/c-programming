/* Write a program to calculate simple interest
 * use preprocessor directives, store definitions in a separate header file 
 * use the file to generate the executable
 */

#include <stdio.h>
#include "question_e.h"

int main(void) {
    /* Question: R takes a loan of Rs 20000 from a bank for a period of 1 year. 
     * The rate of interest is 10% per annum. Find the simple interest and the 
     * total amount he has to pay at the end of a year.
     */
    float si = SIMPLEINTREST(20000, 10, 1);
    printf("Simple intrest :: %f, amount :: %f\n", si, AMOUNT(20000, si));
    return 0;
}
