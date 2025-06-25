#include <stdio.h>

int calFibonacci(int term) {
    if(term == 0)
        return 0;
    if(term == 1)
        return 1;
    return calFibonacci(term - 2) + calFibonacci(term - 1);
}

int main(void) {
    /* input will be what term to print
     * output will be the fibonacci number at that term,
     * for example, 8th term is 21
     * n =	0	1	2	3	4	5	6	7	8	9	10	 11	  12	13	  14	...
     * f =	0	1	1	2	3	5	8	13	21	34	55	 89	 144	233	  377	...
     */
    int n = 5;
    printf("%d Fibonacci term is %d\n", n, calFibonacci(n));
/*  normal thinking
    int arr[10] = {0};
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i < 10; i++) {
        arr[i] = arr[i-2] + arr[i-1];
        printf("%d ", arr[i]);
    }
    printf("\n"); 
    */
    return 0;
}
