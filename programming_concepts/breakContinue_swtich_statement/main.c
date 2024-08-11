/* A c program to understand the switch statement
 * 18th March
 */
#include <stdio.h>

int main(void)
{
	// user_variable for getting input from the user
	int user_variable = 0;
	printf("Enter any number : ");
	scanf("%d", &user_variable);

	switch(user_variable > 20 && user_variable < 40)
	{
		case 1:
			printf("User entered variable is greater than 20\n");
			break;
	}
	switch(user_variable > 40 && user_variable < 60)
	{
		case 1:
			printf("User entered variable is greater than 40\n");
			break;
	}
	switch(user_variable > 60)
	{
		case 1:
			printf("User entered variable is greater than 60\n");
			break;
	}
	return 0;
}


