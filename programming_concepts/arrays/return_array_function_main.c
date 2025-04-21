#include <stdio.h>
int* f();
int main(void)
{
    int *arr = f();
    printf("arr is passed from f() to main()\n");
    for(int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d & address: %p\n", i, *(arr + i), (arr + i));
    }
    return 0;
}
int* f()
{
    static int arr[5] = {1, 2, 3, 4, 5};
    printf("Address of arr in f(), %p\n", arr);
    return arr;
}
// output
/*
Address of arr in f(), 0x55900ff6a010
arr is passed from f() to main()
arr[0] = 1 & address: 0x55900ff6a010
arr[1] = 2 & address: 0x55900ff6a014
arr[2] = 3 & address: 0x55900ff6a018
arr[3] = 4 & address: 0x55900ff6a01c
arr[4] = 5 & address: 0x55900ff6a020
*/
