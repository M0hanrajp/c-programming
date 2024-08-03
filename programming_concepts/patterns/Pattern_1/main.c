/* This is a C program that prints the below pattern:
    *****
    *****
    *****
    *****
    *****
*/
#include <stdio.h>
int main(void)
{
	int input_range = 0;
	printf("Enter the desired input range : ");
	scanf("%d", & input_range);

	for(int out_loop = 0; out_loop < input_range; out_loop++)
	{
		for(int in_loop = 0; in_loop < input_range; in_loop++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
