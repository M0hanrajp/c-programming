/* Basics of pointers */
#include <stdio.h>
int main(void)
{
    int variable = 8;
    /* declaration of integer with identifier variable
     * identifier is the name given to the location
     * at this location the value of variable is stored which is 8
     */

    printf("Address of variable = %u\n", &variable); // Not recommneded but done for understanding purpose
    printf("Value at address of variable = %u\n", *(&variable));
    printf("Address of variable without casting void* = %p\n", &variable);
    printf("Address of variable with casting void* = %p\n", (void*)&variable);
    /* Difference between with and without casting (void *) to a data pointer when using %p.
     *  all data pointers (int*, char*, struct foo*, …) have the same in-memory representation as void*
     *  Meaning: int * holds int, char * holds char, basically they hold the same bits that represent the same address
     *  when you pass an int * to %p it prints the address which is ok
     *  Since %p requires (void *) as it's argument it's generally good practice to cast any data pointer to (void *)
     */


    int stored_address = 0;
    
    /* The meaning of below declaration:
     * the variableTwo is an integer pointer that holds address of variable */
    int *variableTwo = &variable;
    printf("the address of variableTwo = %u\n", &variableTwo); // prints address in decimal format
    printf("the address of variableTwo (using p format specifier)= %p\n", (void *)&variableTwo);
    printf("the value of variableTwo (without deferencing operator) variableTwo = %u\n", variableTwo);
    printf("value of variable variableTwo (with deferencing operator) *variableTwo = %d\n", *variableTwo);
    printf("Alternate way of dereferencing *(*(&variableTwo)) = %d\n", *(*(&variableTwo)));
    /*                                         |-------------> address of variableTwo
     *                                       |---------------> value of variableTwo (address of variable)
     *                                     |-----------------> value at address of variable, 8
     */
    return 0;
}
