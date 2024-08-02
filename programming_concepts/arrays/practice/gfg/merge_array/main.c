/* C Program To Merge Two Arrays */
#include <stdio.h>
#define SIZE 5
int *merge_array(int *arr_one, int *arr_two);
int main(void)
{
    int arr_one[SIZE] = {0, 1, 2, 3, 4};
    int arr_two[SIZE] = {5, 6, 7, 8, 9};
    int *merge_arr = merge_array(arr_one, arr_two);
    for(int elements = 0; elements < 10; elements++)
    {
        printf("Merge array[%d] = %d\n", elements, *(merge_arr + elements));
    }
    return 0;
}
int *merge_array(int *arr_one, int *arr_two)
{
    static int arr[10] = {};
    for(int elements = 0; elements < 5; elements++)
    {
        arr[elements] = *(arr_one + elements);
    }
    for(int elements = 0; elements < 5; elements++)
    {
        arr[elements + 5] = *(arr_two + elements);
    }
    return arr;
}
