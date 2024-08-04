/* C program to understand structure logic */
#include <stdio.h>
// Define a structure with two integers
struct Point {
    int x, y;
};
// Initialize an array of structures
struct Point s[] = { {10, 20}, {15, 25}, {8, 75}, {6, 2} };
// Declare a pointer to an integer
int *i;

int main(void) {
    // Point the integer pointer to the first element of the structure array cast to int*
    i = (int *)s;

    printf("the value of *(i+3) = %d\n", *(i+3));
    printf("The value of s[i[7]].x = %d\n", s[i[7]].x);

    return 0;
}
