#include <stdio.h>

/* Given a number , return the number of steps required to reduce it to zero
 * In one step, if current number is even, you have to divide it by 2
 * otherwise you have to subtract 1 from it.
 */

int reduceToZero(int num,  int count) {
    if(num == 0) {
        return count;
    }
    if(num % 2 == 0)
        return reduceToZero(num / 2, count + 1);
    return reduceToZero(num - 1, count + 1);
}

int main(void) {
    int num = 14;
    printf("The number of steps taken to reduce %d to zero is %d\n", num, reduceToZero(num, 0));
    return 0;
}
