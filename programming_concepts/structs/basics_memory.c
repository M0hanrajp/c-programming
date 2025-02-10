#include <stdio.h>

// program to understand structure memory and padding

// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes

int main()
{
    // structure A
    typedef struct structa_tag {
        char c;
        short int s;
    } structa_t;

    // structure B
    typedef struct structb_tag {
        short int s;
        char c;
        int i;
    } structb_t;

    // structure C
    typedef struct structc_tag {
        char c;
        double d;
        int s;
    } structc_t;

    // structure D
    typedef struct structd_tag {
        double d;
        int s;
        char c;
    } structd_t;

    typedef struct structe_tag {
        char name[10]; // 10 bytes
        //int s; // 4 bytes
        char c; // 1 byte
    } structe_t;
    structe_t check_mem = {"RamRamRam", 'A'};
    /* Output
     * p check_mem
     * $1 = {name = "RamRamRam", c = 65 'A'}
     * (gdb) x/12bx &check_mem
       0x7fffffffdf6d: 0x52    0x61    0x6d    0x52    0x61    0x6d    0x52    0x61
       0x7fffffffdf75: 0x6d    0x00    0x41    0x00
                        ^---------------------------------> 'm' 109 in dec
                                ^-------------------------> NULL
                                         ^----------------> 'A' 65 in dec
     * Since there are no strict alignment requirements for char, the compiler does not add padding.
     * Total size is reported to be 11 bytes.
     * //   Address                 Data
       //      0x7fffffffdf6d   0x52 > 'R'
       //      0x7fffffffdf6e   0x61 > 'a'
       //      0x7fffffffdf6f   0x6d > 'm'
       //      0x7fffffffdf70   0x52 > 'R' 4 bytes
       //      -----------------------------------
       //      0x7fffffffdf71   0x61 > 'a'
       //      0x7fffffffdf72   0x6d > 'm'
       //      0x7fffffffdf73   0x52 > 'R'
       //      0x7fffffffdf74   0x61 > 'a' 4 bytes
       //      -----------------------------------
       //      0x7fffffffdf75   0x6d > 'm'
       //      0x7fffffffdf76   0x00 > NULL
       //      0x7fffffffdf77   0x41 > 'A'          === 11 bytes at this mark which is sizeof check_mem
       //      0x7fffffffdf78   0x00 > NULL 4 bytes === 12 bytes at this mark
       //      ------------------------------------
     */
    printf("sizeof(check_mem) = %lu\n", sizeof(check_mem));
    printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));

    return 0;
}
