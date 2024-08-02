/* A C program to circularly shift values - 
 * Requirements:
 * if x = 5, y = 8, z = 10
 * then after circular shift
 * x = 10, y = 5, z = 8
 */

#include <stdio.h>

// Funciton prototype
void circularshift(int *a, int *b, int *c);

int main(void)
{
    int x = 0, y = 0, z = 0;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);
    printf("Enter the value of z: ");
    scanf("%d", &z); 
    // Funciton called for circular shift
    circularshift(&x, &y, &z);
    printf("After circular shift:\nx = %d, y = %d, z = %d\n", x, y, z);
    return 0;
}

// Function definition
void circularshift(int *a, int *b, int *c)
{
    int temp = 0;
    temp = *c;
    *c = *b;
    *b = *a;
    *a = temp;
}

