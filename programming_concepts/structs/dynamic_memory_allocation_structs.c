#include <stdio.h>
#include <stdlib.h>

int main(void) {



    typedef struct natural_num{
        int a;
        int b;
    } values;

    values set_a = {.a = 10, .b = 18};

    // allocate the size of values, dynamic allocation
    values *set_b = (values *)calloc(1, sizeof(values));
    *set_b = set_a;
    printf("The values copied from set_a :: %d & %d\n", set_b->a, set_b->b);
    // changing the values in set_b to check if the values are reflected in set_a
    set_b->a = 18; set_b->b = 10;
    printf("The values reflected from set_a after changing in set_b ?? :: %d & %d\n", set_a.a, set_a.b);

/* Here set_b is dynamically allocated memory of size values.
 * when set_a (struct instance) is assigned directly to *set_b it behaves normally as *set_b is of type values
 * the assignment works as normal as we are assigning from type values (a struct) to type values (a struct)
 * Since set_b is a pointer and *set_b is a struct, the assignment works as expected, copying field values.

    (gdb) p &set_b.a
    $14 = (int *) 0x5555555592a0
    (gdb) p &set_b.b
    $15 = (int *) 0x5555555592a4

    (gdb) p &set_a.a
    $17 = (int *) 0x7fffffffdf98
    (gdb) p &set_a.b
    $18 = (int *) 0x7fffffffdf9c
*/

    // Create set_c a pointer to values
    values *set_c = NULL;
    // set_b is of type values * & set_c is of type values *, they are assigned
    set_c = set_b;
    /* Remeber we cannot dereference *set_c here as it's a pointer and is not allocated any memory.
     * if dereferenced then seg fualt is declared. */
    printf("The values reflected from set_c after assigning from set_b :: %d & %d\n", set_c->a, set_c->b);
    set_c->a = 88; set_c->b = 88;
    printf("The values reflected from set_b after changing in set_c ?? :: %d & %d\n", set_b->a, set_b->b);
/* set_c is of type values * and it is assigned set_b's value which is nonthing but again values * type.
 * we are just assigning an address from one struct variable to other, this is not struct copying but 
 * copying pointer.
 * But keep in mind: pointer assignment only copies the address, not the data.

    values *set_c = NULL;
    (gdb) p set_c
    $1 = (values *) 0x0 // not pointing to any address
        ...
        ...
    (gdb) p set_c
    $3 = (values *) 0x5555555592a0 // assigned address from set_b
    (gdb) p set_b
    $4 = (values *) 0x5555555592a0

    (gdb) p *set_c
    $5 = {a = 18, b = 10}
    (gdb) p *set_b
    $6 = {a = 18, b = 10}
    
    set_c now points to the same memory as set_b, meaning changes to *set_c 
    affect *set_b since they refer to the same struct instance.
*/
//==========================================================================

    // How to read this struct ?
    // the memory of this struct is actually a pointer to the array
    typedef struct {
        int *array;
        char c;
    } x;
/* 
    (gdb) p &a.array
    $21 = (int **) 0x7fffffffdf80 ------> the is the memory of the struct instance
    (gdb) p a.array
    $20 = (int *) 0x5555555596d0 ----> the memory of the struct instance holds int *
                                    --> which is a pointer to the first element of array. */

    x a; x b;
    a.array = (int *)calloc(2, sizeof(int));
    b.array = (int *)calloc(2, sizeof(int));
    a.array[0] = 8;
    a.array[1] = 9;
    a.c = 'M';
    b = a;

    printf("Values of b :: %d & %d\n", b.array[0], b.array[1]);
    b.array[0] = 18;
    b.array[1] = 25;
    printf("Values of a after modifying values in b :: %d & %d\n", a.array[0], a.array[1]);
/*
 * Explanation
    (gdb) p a
    $1 = {array = 0x0}
    (gdb) p b
    $2 = {array = 0x0}

    (gdb) p b
    $17 = {array = 0x5555555596f0} // note the memory address 
    (gdb) p a
    $18 = {array = 0x5555555596d0}

    (gdb) p a.array[0] // per assigned values
    $6 = 8
    (gdb) p a.array
    $7 = (int *) 0x5555555596d0 // a.array is pointer to the first element of the array
    (gdb) whatis a.array
    type = int *
    (gdb) p b.array
    $8 = (int *) 0x5555555596f0 // b.array is pointer to the first element of the array
    (gdb) p b.array[0]          // value of b.array[0] is 0 as it's not assigned any value and memory
     $9 = 0                     // is allocated by calloc.

    // b = a is performed
     (gdb) p b
    $20 = {array = 0x5555555596d0} // b which is of type x, address is changed to a's

    // consider a case where there are more than two elements
    // initial values
    (gdb) p a
    $3 = {array = 0x5555555596d0, c = 77 'M'}
    (gdb) p b
    $4 = {array = 0x5555555596f0, c = 0 '\000'}

    // after b = a is performed
    (gdb) p a
    $5 = {array = 0x5555555596d0, c = 77 'M'}
    (gdb) p b
    $6 = {array = 0x5555555596d0, c = 77 'M'}
    (gdb) p a.array
    $7 = (int *) 0x5555555596d0
    (gdb) p b.array
    $8 = (int *) 0x5555555596d0
    (gdb) p &a.c
    $9 = 0x7fffffffdf88 "M"
    (gdb) p &b.c
    $10 = 0x7fffffffdf98 "M"

    - thing is the first element in the structure is of type int *array.
    - and we have dynamically allcoated memory to this array.
    - two structs are declared a & b, since the first struct field is an array the 
      struct acts like pointer to the first element of the array.
    - since array is of type int *, a & b are of type x, since the first element is 
      is of type int *, the struct address starts at this point.
    - Hence when I assigned b = a, it was like assigning int * from int * hence the address
      are assigned.
    - When memory copy happens what happens is actually the pointer to which b is pointing 
      to gets copied to a.

 */

    // if values k[5] is declared then the memory needs to be assigned in a loop
    // value k[0] = (values *)calloc(1, sizeof(values))
    // value k[1] = (values *)calloc(1, sizeof(values))
    return 0;
}
