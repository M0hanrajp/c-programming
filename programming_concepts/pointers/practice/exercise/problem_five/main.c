/* A c program to find the area of triangle
 * NOTE: Requirements :
 * using formula, area = square root of s * s(s-a)(s-b)(s-c)
 * where s = a + b + c / 2
 */
#include <math.h>
#include <stdio.h>

// Function declaration
float area_of_triangle(float *a, float *b, float *c, float *area);

int main(void)
{
    // user input for triangle sides :
    float a = 0, b = 0, c = 0, area = 0;
    printf("Enter the value of sides of the triangle: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("The area of triangle is : %f\n", area_of_triangle(&a, &b, &c, &area));
    return 0;
}

// Function definition - for calculating area of triangle
float area_of_triangle(float *a, float *b, float *c, float *area)
{
    float s = (*a + *b + *c)/2;
    float calculation = s * (s - *a) * (s - *b) * (s - *c);
    float result = sqrt(calculation);
    area = &result;
    return *area;
}
    


