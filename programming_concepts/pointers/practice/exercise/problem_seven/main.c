/* A c program :
 * Requirements:
 * Funciton to calculate distance between two points.
 * Use the above function to calculate the area of triangle with vertices
 * use the above two functions to calculate if a point x,y lies inside the trianlge */

#include <math.h>
#include <stdio.h>

// Function declaration - distance between two points
float distance_between_two_points(float *a_one, float *b_one, float *a_two, float *b_two);
// Function declaration - Area of triangle
float area_of_triangle(float *a, float *b, float *c, float *area);
// Function Main
int main(void)
{
    // Distance between the sides of the triangle :
    float distance_ab = 0, distance_ac = 0, distance_bc = 0, area = 0;
    // Declaration of distance between a & 4th vertice
    float distance_ad = 0, distance_bd = 0, distance_dc = 0, area_abd = 0, area_bdc = 0, area_adc = 0;
    // user input for getting values of 3 vertices in the plane :
    float x_one = 0, y_one = 0, x_two = 0, y_two = 0, x_three = 0, y_three = 0, x_four = 0, y_four = 0;
    printf("Enter the value of vertices of A: ");
    scanf("%f %f", &x_one, &y_one);
    printf("Enter the value of vertices of B: ");
    scanf("%f %f", &x_two, &y_two);
    printf("Enter the value of vertices of C: ");
    scanf("%f %f", &x_three, &y_three);
    
    // get distnace between triangle sides :
    distance_ab = distance_between_two_points(&x_one, &y_one, &x_two, &y_two);
    distance_bc = distance_between_two_points(&x_two, &y_two, &x_three, &y_three);
    distance_ac = distance_between_two_points(&x_one, &y_one, &x_three, &y_three);
    printf("Distance between A & B = %f\n", distance_ab);
    printf("Distance between B & C = %f\n", distance_bc);
    printf("Distance between A & C = %f\n", distance_ac);

    // Area of triangle :
    printf("Area of triangle = %f square units\n\n", area_of_triangle(&distance_ab, &distance_bc, &distance_ac, &area));
    
    printf("Enter a new vertice to check if lies inside triangle: ");
    scanf("%f %f", &x_four, &y_four);
    
    // checking if point lies inside or outside the triangle :
    distance_ad = distance_between_two_points(&x_one, &y_one, &x_four, &y_four);
    distance_bd = distance_between_two_points(&x_two, &y_two, &x_four, &y_four);
    distance_dc = distance_between_two_points(&x_four, &y_four, &x_three, &y_three);

    area_abd = area_of_triangle(&distance_ab, &distance_bd, &distance_ad, &area_abd);
    printf("Area of ABD = %f\n", area_abd);
    area_bdc = area_of_triangle(&distance_bd, &distance_dc, &distance_bc, &area_bdc);
    printf("Area of BDC = %f\n", area_bdc);
    area_adc = area_of_triangle(&distance_ad, &distance_ac, &distance_dc, &area_abd);
    printf("Area of ADC = %f\n", area_adc);

    if(area_abd + area_bdc + area_adc <= area_of_triangle(&distance_ab, &distance_bc, &distance_ac, &area))
    {
        printf("The entered fourth vertice lies inside the triangle\n");
    }
    else
        printf("The entered fourth vertice lies outside the triangle\n");
    return 0;
}
// Function for calculating distance between two points:
float distance_between_two_points(float *a_one, float *b_one, float *a_two, float *b_two)
{
    float delta_a = *a_two - *a_one;
    float delta_b = *b_two - *b_one;
    float result = sqrt(pow(delta_a, 2) + pow(delta_b, 2));
    return result;
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
