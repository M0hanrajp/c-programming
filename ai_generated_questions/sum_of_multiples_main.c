#include <stdio.h>

// function declaration
int sumOfMultiples(int *numMulitple, int *num);

int main(void) {
    int numMultiple = 0, num = 0;
    printf("Enter upper limit & multiple with a space: ");
    scanf("%d %d", &numMultiple, &num);
    printf("Sum of multiples of %d upto %d is: %d\n", num, numMultiple, sumOfMultiples(&numMultiple, &num));
    return 0;
}

// function definition
int sumOfMultiples(int *numMulitple, int *num) {
    int sum = 0, sum_alternative = 0, k = 0;
    for (int multipleNum = 1; multipleNum <= *numMulitple; multipleNum++) {
        if(multipleNum % *num == 0) {sum = multipleNum + sum;}
        // if(multipleNum % *num == 0) { printf("%2d\n", multipleNum);} // Statement for debugging purpose
    }
    // Logic 2
    k = *numMulitple / *num;
    sum_alternative = *num * ((k * (k+1))/2);
    return sum_alternative; // change as needed
}
