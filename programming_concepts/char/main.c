#include <stdio.h>

int main(void)
{
	char c = 'a';// char declaration
	printf("The integer value of char is %d\n", c);
	printf("The symbol of ASCII value %d is %c\n", c, c);
	printf("Consecutive 3 characters from the defined character:\n is %c, %c & %c\n", c, c + 1, c + 2);
	printf("the three bell ring characters are %c, %c & %c\n", '\a', '\a', '\a');
	return 0;
}
