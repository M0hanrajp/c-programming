#include <stdio.h>

int sum = 0;
int checkPalindrome(int num) {
    if(num == 0) {
        return 0;
    }
    int rem = num % 10;
    sum = sum * 10 + rem;
    checkPalindrome(num / 10);
    return sum;
}

int main(void) {
    int num = 1231;
    checkPalindrome(num) == num ? printf("%d is palindrome\n", num) :
                                  printf("%d is not palindrome\n", num);
    return 0;
}
