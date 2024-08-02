/* NOTE:
 * The following program finds the smallest element in an array of 25 integers
 */
#include <stdio.h>
#define SIZE 25
// Funciton prototype - get smallest element
int SmallestElementOfArray(int *ArrayInput, int ArraySize);
// Function prototype - get largest element 
int LargestElementOfArray(int *ArrayInput, int ArraySize);
int main(void)
{
    int Array[SIZE] = {45, 67, 12, 89, 34, 23, 78, 56, 90, 12, 
                       34, 65, 87, 43, 21, 76, 54, 98, 31, 49, 
                       68, 23, 57, 81, 121};
    int SmallestElement = 0, LargestElement = 0;
    printf("Array with 25 random elements:\n");
    for(int elements = 0; elements < SIZE; elements++)
    {
        printf("Array[%2d] = %2d & Address: %p :: %u\n", elements, Array[elements], &Array[elements], &Array[elements]);
    }
    printf("The smallest integer in the above array was found to be %d\n", 
            SmallestElement = SmallestElementOfArray(Array, SIZE));

    printf("The largest integer in the above array was found to be %d\n",
            LargestElement = LargestElementOfArray(Array, SIZE));
    return 0;
}
// Function definition - get smallest element
int SmallestElementOfArray(int *ArrayInput, int ArraySize)
{
    int small = *ArrayInput;
    for(int elements = 0; elements < ArraySize; elements++)
    {
        if(*(ArrayInput + elements) < small){small = *(ArrayInput + elements);}
    }
    return small;
}
// Function definition - get largest element
int LargestElementOfArray(int *ArrayInput, int ArraySize)
{
    int large = *ArrayInput;
    for(int elements = 0; elements < ArraySize; elements++)
    {
        if(*(ArrayInput + elements) > large){large = *(ArrayInput + elements);}
    }
    return large;
}
