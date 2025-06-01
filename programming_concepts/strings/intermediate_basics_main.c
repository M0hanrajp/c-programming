// pointers and strings
#include <stdio.h>

int main(void) {
    char word[] = "something";
    char *words = "Code Code Code";
    char copy[20];
    char *newString = NULL;
	/* there is a fundamental difference between char[] and char * declaraton
	 * read it at char_array_vs_char_pointer.md */

    // assigning to a new char array using = operator
    copy = word;
/*     intermediate_basics_main.c:11:10: error: assignment to expression with array type
       11 |     copy = word;
          |          ^ 
       - array name represents a fixed memory address (a pointer to the first element of the array). 
       - This memory is allocated during compile time, and you cannot reassign it. */

    // assign string literal to an already allocated word[]
    word = "computer";
/*     intermediate_basics_main.c:14:10: error: assignment to expression with array type
       14 |     word = "computer";
          |
       - word[] is a statically allocated array, and as such, its memory location cannot be changed 
       after its declaration.
       - When you declare char word[] = "something";, the compiler allocates enough memory for "something" 
       (including the null terminator \0) and initializes the array. However, the array itself is not a 
       pointer, so you cannot reassign it to another string. */

    // assign new string literal to char *
    // previously 
/*  words was assigned "Code Code Code"
    (gdb) printf"%p\n", words
    0x555555556004    
    (gdb) printf"%s\n", words
    Code Code Code */
    words = "Keep coding";
    // Change in address for words after it is assigned new string literal
/*  (gdb) printf"%p\n", words
    0x555555556013
    (gdb) printf"%s\n", words
    Keep coding */
    // Since words is a char pointer it can be assigned different address.

    // assign char * to a new char * with string literal
    newString = words;
    // new string is a char *, hence it can hold any char *'s address.
/*  (gdb) printf"%p\n", newString
    0x555555556013
    (gdb) printf"%s\n", newString
    Keep coding */
    return 0;
}
