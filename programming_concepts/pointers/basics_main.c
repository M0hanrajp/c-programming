/* Basics of pointers */
#include <stdio.h>
int main(void)
{
    int variable = 8;
    /* declaration of integer with identifier variable
     * identifier is the name given to the location
     * at this location the value of variable is stored which is 8
     */

    printf("Address of variable = %u\n", &variable);
    printf("Value at address of variable = %u\n", *(&variable));
    printf("Address of variable without casting void* = %p\n", &variable);
    printf("Address of variable with casting void* = %p\n", (void*)&variable);    

    int stored_address = 0;
    
    /* The meaning of below declaration:
     * the "value of address" > * contained in j is an int */
    int *variableTwo = &variable;
    printf("the address of variableTwo = %u\n", &variableTwo);
    printf("the address of variableTwo (using p)= %p\n", (void *)&variableTwo);
    printf("the value of variableTwo = %u\n", variableTwo);
    printf("value of variable using variableTwo = %d\n", *variableTwo);
    printf("value of variable using double reference to address of variableTwo = %d\n", *(*(&variableTwo)));
    return 0;
}
