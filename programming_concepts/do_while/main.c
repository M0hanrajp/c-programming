// Usage of do while loop

#include <stdio.h>

int countDigits(int number) {
    int dig = 0;
    do {
        number = number / 10;
        dig++;
    } while(number != 0);
    return dig;
}

int main(void) {
    // Write a function to count the number of digits in a given number.
    printf("The total number of digits are : %d\n", countDigits(1234512345));
    return 0;
}

// syntax
/* 
 * The body of do...while loop is executed once. Only then, the testExpression is evaluated.
 * If testExpression is true, the body of the loop is executed again and testExpression is evaluated once more.
 * This process goes on until testExpression becomes false. 
 * the statement will execute atleast one time, as we know in a while loop the condition is checked first 
 * then the statement is executed later.
     * do{
    statement(x);

    }while(condition);

 * */
