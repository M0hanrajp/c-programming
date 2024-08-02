/* NOTE:
 * This is the perfect program for passing array elements to function
 * and printing their address and this does not have any error */
#include <stdio.h>
#define SIZE 5
// display funciton
void display(int *array_input, int array_size);
// main funciton
int main(void)
{
    int main_array[SIZE] = {1, 2, 3, 4, 5};
    display(main_array, SIZE);
    return 0;
}
// function definition
void display(int *array_input, int array_size)
{
    for(int element = 0; element < array_size; element++, array_input++)
    {
        printf("Address:%u & element:%d\n", array_input, *array_input);
    }
}
