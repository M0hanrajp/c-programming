// The following program is written to clarify the difference between 
// constant pointer and pointer to a constant

int main(void) {
    // constant pointer to a string
    char str[5] = "Linux";
    // When you define an array, the memory for the array is allocated at compile time, 
    // and the name of the array (str) acts as a constant pointer to the first element of the array.
    // in other words - char *const str = 'a'; (read it backwards)
    // str is a constant pointer to a char
    // Address is immuatable, value is mutable.
    // For arrays, the immutability of the address is due to how arrays are implemented in C. 
    // The array name directly refers to a fixed memory location, and there is no mechanism to 
    // reassign the base address of the array.

    str[1]++; // no errors, value is mutable.
/*     (gdb) p str
        $8 = "Ljnux" 
        it printed "Ljnux" because str[1] gives i and then char is incremented giving j*/
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
    // the pointer s points directly to the string literal, which is read-only. The pointer can be 
    // reassigned (e.g., s = "Other";), but the contents of the string literal cannot be modified.

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
    // the reason why it prints nix is you have performed s++ so s moves 1 byte ahead.
    // 'p' in gdb prints the string till it encounters null char, hence nix is printed.
    return 0;
}
