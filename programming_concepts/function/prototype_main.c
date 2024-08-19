/* A C program that explains the use of function protoypes */
#include <stdio.h>
#define PI 3.14245
// Function protoype
double volumeOfSphere(double radius);
// Main program
int main(void)
{
	double user_input_radius = 0.0;
	printf("Enter Radius : ");
	scanf("%lf", &user_input_radius);
	volumeOfSphere(user_input_radius);
	return 0;
}
// Funciotn definition
double volumeOfSphere(double radius)
{
	return (printf("The volume of sphere is = %lf\n", ((4 / 3.0) * PI * radius * radius * radius)));
}
