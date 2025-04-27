#include <stdio.h>
#include <stdlib.h>

#define PRINT_DELIMITER() printf("------------------------\n");
#define PRINT_MEM_SEG(seg, addr) printf("[%s]: %p\n", seg, addr);
/* PRINT_MEM_SEG > is a macro definition using #define preprocessor
 * It's a text substitution, there is no checking when macro is defined
 * the errors are pointed out by the compiler if only the printf does not have
 * the expected arguments */

static void func(void)
{
    printf("hello\n");
}

int main(int argc, char *argv[])
{
    PRINT_DELIMITER();
    PRINT_MEM_SEG("CMD LINE ARGS", &argv[0]);

    int stack_var = 25;
    PRINT_DELIMITER();
    PRINT_MEM_SEG("STACK", &stack_var);

    int *heap_ptr = malloc(sizeof(int));
    PRINT_DELIMITER();
    PRINT_MEM_SEG("HEAP", heap_ptr);

    static int bss_var;
    PRINT_DELIMITER();
    PRINT_MEM_SEG("BSS DATA", &bss_var);

    static int data_var = 10;
    PRINT_DELIMITER();
    PRINT_MEM_SEG("INITIALISED DATA", &data_var);

    PRINT_DELIMITER();
    PRINT_MEM_SEG("TEXT", func);
    return 0;
}
// output
/*
------------------------
[CMD LINE ARGS]: 0x7ffc847f85f8 << higher address
------------------------
[STACK]: 0x7ffc847f84cc
------------------------ << Major difference between stack and heap address
[HEAP]: 0x563714bda6b0
------------------------
[BSS DATA]: 0x5636eb4f9018
------------------------
[INITIALISED DATA]: 0x5636eb4f9010
------------------------
[TEXT]: 0x5636eb4f61a9 << lower address
*/
