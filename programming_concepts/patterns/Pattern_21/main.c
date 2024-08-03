/* A C program to print the following pattern
       1
       2  3
       4  5  6
       7  8  9  10
       11 12 13 14 15
*/
#include <stdio.h>
int main(void)
{
	int user_input = 0;
	printf("Enter the desired rows/columns : ");
	scanf("%d", &user_input);

	int numbers = 1;
	for(int out_loop = 0; out_loop < user_input; out_loop++)
	{
		for(int in_loop = 0; in_loop < out_loop + 1; in_loop++)
		{
			printf(" %d", numbers++);
		}
		printf("\n");
	}
	return 0;
}
