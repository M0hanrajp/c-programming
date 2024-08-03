/* A c program for right-angle triangle */
/* pattern:
  1 1 1 1 1 1
  2 2 2 2 2
  3 3 3 3
  4 4 4
  5 5
  6
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
			for(int inside = 0; inside < user_integer - outside; inside ++)
			{
				printf("%d", outside + 1);
			}
			printf("\n");
	}
	return 0;
}
