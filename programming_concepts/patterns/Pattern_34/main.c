/* A c program to display the following pattern :

   E D C B A
   D C B A
   C B A
   B A
   A

*/
#include <stdio.h>
int main(void)
{
	int user_input = 0;
	printf("Enter the desried number of rows/columns : ");
	scanf("%d", &user_input);

	int character = 69;
	for(int out_loop = 0; out_loop < user_input; out_loop++)
	{
		for(int in_loop = 0; in_loop < user_input - out_loop; in_loop++)
		{
			printf("%c", character - in_loop);
		}
		printf("\n");
		character--;
	}
	return 0;
}
