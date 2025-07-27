/* A c program to understand for loop
 * 10th March 
 */
#include <stdio.h>

int main(void)
{
	int initializer_expression = 0;
	int sum = 0;
	for(; initializer_expression < 5; initializer_expression++)
	{
		sum += initializer_expression;
	}
	printf("Sum = %d\n",sum);
	return 0;
}
