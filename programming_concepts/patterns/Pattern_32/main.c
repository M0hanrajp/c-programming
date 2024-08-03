/* A C program to print the following pattern :
       E
       D E
       C D E
       B C D E
       A B C D E
*/
#include <stdio.h>
int main(void)
{
	int user_integer = 0;
	printf("Enter variable = ");
	scanf("%d", &user_integer);
	
	for(int outside = 0; outside < user_integer; outside ++)
	{
		// Inside * print for each expression
		for(int inside = 0; inside < outside + 1; inside ++)
		{
			printf("%c", 70 - (outside + 1 - inside));
		}
		printf("\n");
	}
	return 0;
}
