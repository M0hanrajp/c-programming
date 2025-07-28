#include <stdio.h>

// the below case does not work when the number has zero
int reverseNum(int num) {
    if(num < 9) {
        return num;
    }
    int d = 1;
    while (num / d > 9) {
        d *= 10;
    }
    return ((reverseNum(num % d) * 10) + (num / d));
}

// this is better
int sum = 0;
int revNum(int num) {

    if(num == 0) {
        return 0;
    }
    int rem = num % 10;
    sum = sum * 10 + rem;
    revNum(num / 10);
    return sum;
}

int main(void) {
    printf("Reverse Num is :: %d\n", reverseNum(104));
    printf("Reverse method 2 :: %d\n", revNum(12304));
    return 0;
}
