/* A c program that explains the local variable not being changed */
#include <stdio.h>

// Funciton prototype
int calculateSumToN(int local_n);
// Main Funciton
int main(void)
{
	int main_n = 10;
	printf("The sum of 0 to %d is = %d\n", main_n, calculateSumToN(main_n));
	return 0;
}
// Funciton definiion
int calculateSumToN(int local_n)
{
	int sum = 0;
	for(; local_n > 0; local_n--)
		sum += local_n;
	return sum;
}
