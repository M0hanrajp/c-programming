/* A c program to print the following pattern
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
*/
#include <stdio.h>
int main(void)
{
        // user inputs the number of columns/rows the pattern will consist of
        int user_range = 0;
        printf("Enter the desired number of columns and rows : ");
        scanf("%d", &user_range);

        //int number = 1;
		for(int out_loop = 0; out_loop <  user_range; out_loop++)
        {
                for(int in_loop = 0; in_loop < out_loop + 1; in_loop++)
                {
                        printf("%d", in_loop + 1);
                }
                printf("\n");
        }
        return 0;
}
