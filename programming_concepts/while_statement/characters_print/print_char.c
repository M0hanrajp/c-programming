#include <stdio.h>

int main(void)
{
	int blanks = 0, digits = 0, alphabets = 0, special_characters = 0;
	int c = 0;
	while((c = getchar()) != EOF)
	{
		if(c == ' '){
			++blanks;
			printf("The blank character that was read: %c & Number of blank(s):%d\n", c, blanks);
		}
		else if(c >= '0' && c <= '9'){
			++digits;
			printf("The digit character that was read: %c & Number of digit(s):%d\n", c, digits);
		}
		else if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
			++alphabets;
			printf("The alphabet character that was read: %c & Number of alphabet(s):%d\n", c, alphabets);
		}
		else 
			++special_characters;
			printf("The other character that was read: %c & Number of other character(s):%d\n", c, special_characters);
	}
	printf("Blanks:%d, digits:%d, alphabets:%d, special characters:%d\n", blanks, digits, alphabets, special_characters);
	printf("The total characters read = %d\n", blanks + digits + alphabets + special_characters);
	return 0;
}

