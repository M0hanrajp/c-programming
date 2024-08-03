/* A c program to print the following pattern
	*****
	****
	***
	**
	*
*/
#include <stdio.h>
int main(void)
{
        // user inputs the number of columns/rows the pattern will consist of
        int user_range = 0;
        printf("Enter the desired number of columns and rows : ");
        scanf("%d", &user_range);

        for(int out_loop = 0; out_loop <  user_range; out_loop++)
        {
                for(int in_loop = 0; in_loop < user_range - out_loop; in_loop++)
                {
                        printf("*");
                }
                printf("\n");
        }
        return 0;
}
