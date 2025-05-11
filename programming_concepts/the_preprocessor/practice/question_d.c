/* Write the macro definitions for the following
 * a. arithmetic mean of two numbers.
 * b. absolute value of a number.
 * c. convert and upper case alphabet to lowercase.
 * d. to obtain biggest of three numbers.
 */

#include <stdio.h>

// Macros
// a & b
#define ARITHMETICMEAN(a, b) ((a + b) / 2.0)
#define ABSOLUTENUMBER(a) (a < 0 ? (a * -1) : a)
// c
#define SMALLCASE(c) (c > 96 && c < 123)
#define UPPERCASE(c) (c > 64 && c < 92)
#define CHECKALPHABET(c) (SMALLCASE(c) || UPPERCASE(c))
#define CONVERTUPPERCASETOLOWERCASE(c) (CHECKALPHABET(c) ? SMALLCASE(c) ? (c - 32) : c : -1)
// d
#define BIGGESTOFTHREENUMBERS(a, b, c) (a > b && a > c ? a : b > a && b > c ? b : c > a && c > b ? c : -1)

int main(void) {
    printf("Arithmetic mean :: %.2f\n", ARITHMETICMEAN(2, 2));
    printf("Absolute number :: %d\n", ABSOLUTENUMBER(-5));
    printf("convert small case to upper case %c\n", CONVERTUPPERCASETOLOWERCASE('m'));
    printf("Biggest of three numbers 3, 4, 5 :: %d\n", BIGGESTOFTHREENUMBERS(3, 4, 5));
    return 0;
}
