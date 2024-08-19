/* A c program that explains the return type function */
#include <stdio.h>

// Function definition
int sum_numbers(int a, int b){
	return (printf("the sum of a + b is %d\n", a + b));
}
// main program
int main(void)
{
	int userInputVariableOne = 0, userInputVariableTwo = 0;
	printf("Enter value of a :");
	scanf("%d", &userInputVariableOne);
	printf("Enter value of b :");
	scanf("%d", &userInputVariableTwo);
	sum_numbers(userInputVariableOne, userInputVariableTwo);
	return 0;
}
