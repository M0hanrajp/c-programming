#include <stdio.h>

int main(void)
{
	int love = 0;
	printf("How much do you love me (Enter any number) = ");
	scanf("%d", &love);
	printf("I Love you");
	while(love > 0)
	{
		printf(" very");
		love--;
	}
	printf(" much\n");
	return 0;
}
