/* A C program that displays the following pattern :
    *
    **
    ***
    ****
    *****
    ****
    ***
    **
    *
*/
#include <stdio.h>
int main(void)
{
	// get input
	int user_input = 0;
	printf("Enter the desired Columns/rows : ");
	scanf("%d", &user_input);

	for(int out_loop = 0; out_loop < user_input; out_loop++)
	{
		if(out_loop < user_input / 2)
		{
			for(int in_loop = 0; in_loop < out_loop + 1; in_loop++)
			{
				printf("*");
			}
			printf("\n");
		}
		if(out_loop > user_input / 2)
		{
			for(int in_loop = 0; in_loop < user_input - out_loop; in_loop++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
