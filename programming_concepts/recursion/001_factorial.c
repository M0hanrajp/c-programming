#include <stdio.h>

int calFactorial(int number) {
    if(number <= 1)
        return 1;
    return number * calFactorial(number - 1);
}

int main(void) {
    printf(":: %d\n", calFactorial(3));
    return 0;
}
