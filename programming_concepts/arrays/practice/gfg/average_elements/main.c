/* Given an array arr of size N, the task is to calculate
 * the average of all the elements of the given array.
 */
#include <stdio.h>
#define SIZE 30
float average(float *array, int array_size);
int main(void)
{
    float array[30] = { 42, 93, 15, 77, 84, 55, 37, 68, 19, 24,
                        91, 73, 28, 64, 38, 10, 45, 82, 13, 59,
                        97, 30, 47, 76, 21, 62, 33, 88, 52, 17};
    float get_average = 0;
    printf("The average of elements = %f\n", get_average = average(array, SIZE));
    return 0;
}
float average(float *array, int array_size)
{
    float total = 0, average = 0;
    for(int elements = 0; elements < array_size; elements++)
    {
        total += *(array + elements);
        printf("total = %f, array[%d] = %.2f\n", total, elements, *(array + elements));
    }
    return average = total/array_size;
}
