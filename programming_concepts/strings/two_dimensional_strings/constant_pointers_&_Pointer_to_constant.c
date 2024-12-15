// The following program is written to clarify the difference between 
// constant pointer and pointer to a constant

int main(void) {
    // constant pointer to a string
    char str[5] = "Linux";
    // in other words - char *const str = 'a'; (read it backwards)
    // str is a constant pointer to a char
    // Address is immuatable, value is mutable.
    
    str[1]++; // no errors, value is mutable.
    str++; // Will give below error as str is constant pointer, address is immutable.
    /*     constant_pointers_&_Pointer_to_constant.c:13:8: error: lvalue required as increment operand
    13 |     str++;
       |        ^~ */
    
    char var = 'I';
    str = &var; // Will give below error as str is constant pointer and cannot point to any other address
    /* constant_pointers_&_Pointer_to_constant.c:19:9: error: assignment to expression with array type
        19 |     str = &var;
           | */   
    // but
    str[1] = var; // assigning a char, is possible as value is mutable.

    // pointer to a constant string
    char *s = "Unix";
    // in other words - char const *p = 'a'; (read it backwards)
    // This can also be written as const char *p = 'a'
    // p is a pointer to a const char.
    // Address is mutable, value is immutable.

    *s = 'a'; // will get below error as value is immutable
    /* Program received signal SIGSEGV, Segmentation fault.
    0x000055555555518c in main () at constant_pointers_&_Pointer_to_constant.c:32
    32          *s = 'a';
    (gdb) n
    Program terminated with signal SIGSEGV, Segmentation fault. */

    s++; // no errors as address is mutable, moved by 1 char as s is a pointer to a constant char (1 byte)
    /* 40          s++;
    (gdb) p s
    $1 = 0x555555556004 "Unix"
    (gdb) n
    41      }
    (gdb) p s
    $2 = 0x555555556005 "nix" */
    return 0;
}
