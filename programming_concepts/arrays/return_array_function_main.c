#include <stdio.h>

int* f();
int main(void)
{
    int *arr = f();
    for(int i = 0; i < 5; i++)
    {
        printf("Arra[%d] = %d & address: %u\n", i, *(arr + i), (arr + i));
    }
    return 0;
}
int* f()
{
    static int arr[5] = {1, 2, 3, 4, 5};
    return arr;
}
