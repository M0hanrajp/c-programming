/* C program to print pattern of type:
       a
       B c
       D e F
       g H i J
       k L m N o
*/
#include <stdio.h>
int main(void)
{
	int user_integer = 0;
	printf("Enter variable = ");
	scanf("%d", &user_integer);

	int alphabet = 97;
	for(int outside = 0; outside < user_integer; outside ++)
	{
		for(int inside = 0; inside < outside + 1; inside ++)
		{
			printf("%c", alphabet++);
		}
		printf("\n");
	}
	return 0;
}
