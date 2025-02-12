#include <stdio.h>

// This section is to learn how we can access field members from struct
// Basics on the type of fields and what is offset.

int main(void) {

    struct books {
        char name[4];
        int pages;
        double price;
    } harry_potter = {"GOF", 1900, 85.75};
    /* Following is the struct memory layout
     * (gdb) x/16bx &harry_potter
     * 0x7fffffffdf60: 0x47    0x4f    0x46    0x00    0x6c    0x07    0x00    0x00
     * 0x7fffffffdf68: 0x00    0x00    0x00    0x00    0x00    0x70    0x55    0x40
     *        Address        Data
     *    0x7fffffffdf60     0x47 <--- char name offset **
     *    0x7fffffffdf61     0x4f
     *    0x7fffffffdf62     0x46
     *    0x7fffffffdf63     0x00 <--- char name[4]
     *    0x7fffffffdf64     0x6c <--- int pages offset **
     *    0x7fffffffdf65     0x07
     *    0x7fffffffdf66     0x00 
     *    0x7fffffffdf67     0x00 <--- int pages
     *    0x7fffffffdf68     0x00 <--- double price offset **
     *    0x7fffffffdf69     0x00 
     *    0x7fffffffdf6a     0x00 
     *    0x7fffffffdf6b     0x00 
     *    0x7fffffffdf6c     0x00 
     *    0x7fffffffdf6d     0x70 
     *    0x7fffffffdf6e     0x55 
     *    0x7fffffffdf6f     0x40 <--- double price
     */

    // Note: Is harry_potter a variable ? a instance or a pointer ? ans at Learnings.md [2]
    printf("What is the size of struct ? sizeof(harry_potter) :: %zu\n", sizeof(harry_potter));
    // note that the size of the struct is alligned to multiple of 8 (double data type occupying 8 bytes)

    // harry_potter is an instance/object/variable of type struct books
    // The struct instance is stored at its base address, the following gives me the base address.
    printf("What is the address of struct ? &harry_potter :: %p\n", &harry_potter);
    /*  (gdb) p &harry_potter
        $1 = (struct books *) 0x7fffffffdf60 <--- base address of struct
        (gdb) whatis &harry_potter
        type = struct books *    <---- accessing through & operator it becomes pointer to a struct type
        (gdb) whatis harry_potter
        type = struct books  <--- it is of type struct books
    */

    // What is the dot operator and how element access works in struct ?
    /* WKT harry_potter is an instance/object/variable of type struct books stored at base address.
     * all the fields can be accessed by their respective offsets from the base address 
     * The formula is :
     * ===============================================================================================
     * struct-base address + field offset address (start address of the field) ---> struct field value
     * ===============================================================================================
     * > Accessing a struct field:
     * > struct base address + field offset = field address
     * > *(struct base address + field offset) = field value
     */

    printf("What is the value of name field ? harry_potter.name :: %s\n", harry_potter.name);
    // output :: "GOF"
    printf("What is the address of name field ? &harry_potter.name :: %p\n", &harry_potter.name);
    // output :: 0x7fffffffdf60
    // this will be of type char (*)[4] a pointer to a whole array since & operator is used.

    /* Explanation of harry_potter.name
     * ================================
     *
     * Accessing field member "name" from struct books, which is of type char [4], a string, (array of char)
     * 
     * (gdb) whatis harry_potter.name
     * type = char [4]
     * here name[4] is char array that can hold 3 chars plus one NULL char (A string).
     *
     * In order to print a string using %s operator the argument must be of type char * (pointer to a char)
     * Why because :: when base address of the array is passed, string is printed from base address till it 
     * encounters the null character. if it does not enconter the null char behavior is undefined.
     * 
     * What is offset and who remembers it ?
     * > Offset refers to the difference (in bytes) between a struct field's memory location 
     * and the base address of the struct.
     * > The compiler calculates struct offsets at compile time, based on:
     * Field order in the struct.
     * Size of each field.
     * Alignment requirements of each data type.
     * Padding (if needed) to ensure efficient memory access.
     * You can verify offsets using offsetof(struct_name, field), #include <stddef.h>  // Required for offsetof
     *
     * so when harry_potter.name is used to print out the value.
     * 0x7fffffffdf60 + offset of name (which is 0) = char [4] = "GOF" as the output
     * since harry_potter.name is of type char [4], &harry_potter.name gives you a pointer to the whole array
     *
     * (gdb) whatis harry_potter.name[0] type = char, $4 = 71 'G'
     * Here harry_potter (base address) + name[0] which is of type char, will give the first char of string "GOF"
     *
     * (gdb) p &harry_potter.name[1] $7 = 0x7fffffffdf61 "OF", whatis &harry_potter.name[1] type = char *
     */

    printf("What is the value of pages field ? harry_potter.pages :: %d\n", harry_potter.pages);
    // output :: 1900
    // (gdb) whatis harry_potter.pages type = int
    printf("What is the address of pages field ? &harry_potter.pages :: %p\n", &harry_potter.pages);
    // output :: 0x7fffffffdf64
    // (gdb) p &harry_potter.pages $11 = (int *) 0x7fffffffdf64 
    // (gdb) whatis &harry_potter.pages type = int *

    /* Explanation: 
     * base address : 0x7fffffffdf60 + 4 [ offset of pages field (0x7fffffffdf64 - 0x7fffffffdf60) ]
     * => 0x7fffffffdf64, at this address the field member is of type int.
     * Check the memory layout at the top to get more info 
     * Notice 'pages' starts from 0x7fffffffdf64 which is in favor of 4 byte allignment based on its type
     *
     * (gdb) p sizeof(harry_potter.pages) $12 = 4
     * so when using dot operator to get the field member as a whole it becomes data type int.
     *
     */

    printf("What is the value of price field ? harry_potter.price :: %lf\n", harry_potter.price);
    // output :: 85.75
    // whatis harry_potter.price type = doubles 
    // harry_potter.pages type = int
    printf("What is the address of price field ? &harry_potter.price :: %p\n", &harry_potter.price);
    // output :: 0x7fffffffdf68
    // (gdb) p &harry_potter.price 
    // $11 = (double *) 0x7fffffffdf68
    // (gdb) whatis &harry_potter.price
    // type = double *

    /* Explanation: 
     * base address : 0x7fffffffdf60 + 8 [ offset of price field (0x7fffffffdf68 - 0x7fffffffdf60) ]
     * => 0x7fffffffdf68, at this address the field member is of type double.
     * Check the memory layout at the top to get more info 
     * Notice 'price' starts from 0x7fffffffdf68 which is in favor of 8 byte allignment based on its type
     *
     * (gdb) p sizeof(harry_potter.price) $12 = 8
     * so when using dot operator to get the field member as a whole it becomes data type double.
     */
    return 0;
}
