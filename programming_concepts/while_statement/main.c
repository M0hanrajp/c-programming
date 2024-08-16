/* A c program to learn while loop */

#include <stdio.h>

int main(void)
{
	int variable = 0;
	int expression = 0;
	
	// user input
	printf("Enter the value of variable = ");
	scanf("%d", &variable);
	if(variable > 10)
		printf("The program has exited because you have entered the value of variable that is invalid for the program\n");
		/* the identifier variable should be less than 10 before entering the loop
		* if the variable is more than 10 then the loop is never entered.
		*/
	else
	{
		while(expression = variable < 10)
		{
			// display the value of identifier
			printf("Value of variable = %d\n", variable);
			// identifier is incremented by 1
			variable++; 
		}
		printf("The program has exited the loop, program was executed successfuly\n");
	}
	return 0;
}
