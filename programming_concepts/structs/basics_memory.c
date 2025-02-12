#include <stdio.h>

// This is the part 1 of struct memory basics which discusses on memory layout and padding.
// For learning how address is calculated and what struct decays to please check part 2.
// program to understand structure memory layout and padding

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
        int s; // 4 bytes
        char c; // 1 byte
    } structe_t;

    /* Important
     *
     * Each member within the structure is aligned according to its own type's alignment 
     * requirements, while the overall structure size is aligned to the largest member’s 
     * alignment requirement. */

    /* The overall structure size must be a multiple of the largest member’s alignment 
     * (which is double, requiring 8-byte alignment). This ensures that if an array of 
     * structc_t is created, every instance is properly aligned. */

    structa_t structA = {'M', 0xFFFF};
    /* Output
     * (gdb) p structA
     * $1 =   {c = 77 'M', s = -1}
     * (gdb) x/4bx &structA
     * 0x7fffffffdf5c: 0x4d    0x00    0xff    0xff
     * Here short int is data type has largest size hence 2 byte allignment is prefered.
     * Total size is reported to be 4 bytes.
     *        Address                 Data
     *        0x7fffffffdf5c   0x4d > 'M'
     *        0x7fffffffdf5d   0x00 > NULL 2 bytes ---> because of 2 byte allignment
     *        ------------------------------------
     *        0x7fffffffdf5e   0xff > FF
     *        0x7fffffffdf5d   0xff > FF   2 bytes
     *        ------------------------------------
     *        // offsets
     *        (gdb) p &structA.c
     *        $5 = 0x7fffffffdf5c "M"
     *        (gdb) p &structA.s
     *        $6 = (short *) 0x7fffffffdf5e
     */

    structb_t structB = {0xFFFF, 'M', 0xFFFFFFFF};
    /* Output
     * (gdb) p structB
     * $1 = {s = -1, c = 77 'M', i = -1}
     * (gdb) x/8bx &structB
     * 0x7fffffffdf58: 0xff    0xff    0x4d    0x00    0xff    0xff    0xff    0xff
     * Int is the data type with largest size of 4 byte hence 4 byte allignemnt will be used
     * Total size is reported to be 8 bytes.
     * (gdb) x/8bx &structB
     * 0x7fffffffdf58: 0xff    0xff    0x4d    0x00    0xff    0xff    0xff    0xff
     *        Address                 Data
     *        0x7fffffffdf58   0xff > FF
     *        0x7fffffffdf59   0xff > FF
     *        0x7fffffffdf5a   0x4d > 'M' --> char element has not strict allignment requirement
     *        0x7fffffffdf5b   0x00 > NULL  4 bytes
     *        -------------------------------------
     *        0x7fffffffdf5c   0xff > FF
     *        0x7fffffffdf5d   0xff > FF
     *        0x7fffffffdf5e   0xff > FF
     *        0x7fffffffdf5f   0xff > FF    4 bytes
     *        -------------------------------------
     * // offsets
     * (gdb) p &structB.s
     * $3 = (short *) 0x7fffffffdf58
     * (gdb) p &structB.c
     * $4 = 0x7fffffffdf5a "M"
     * (gdb) p &structB.i
     * $5 = (int *) 0x7fffffffdf5c
     */

    structc_t structC = {'M', 45555.55555, 0xFFFFFFFF};
    /* Output
     * (gdb) p structC
     * $1 = {c = 77 'M', d = 45555.555549999997, s = -1}
     * (gdb) x/24bx &structC
     * 0x7fffffffdf40: 0x4d    0x00    0x00    0x00    0x00    0x00    0x00    0x00
     * 0x7fffffffdf48: 0x29    0xcb    0x10    0xc7    0x71    0x3e    0xe6    0x40
     * 0x7fffffffdf50: 0xff    0xff    0xff    0xff    0x00    0x00    0x00    0x00
     * This struct has char, int and double
     * based on the important note please note
     * each and every data type will be alligned according to it's byte allignment
     * the whole struct size will be alligned according to the largest data type size.
     * so here largest size is double which is of 8 bytes, hence the struct size will 
     * be in multiple of 8 bytes.
     * So here the size of the struct is 24 bytes
     *        Address                 Data
     *        0x7fffffffdf40   0x4d > 'M'
     *        0x7fffffffdf41   0x00 > NULL
     *        0x7fffffffdf42   0x00 > NULL
     *        0x7fffffffdf43   0x00 > NULL
     *        0x7fffffffdf44   0x00 > NULL
     *        0x7fffffffdf45   0x00 > NULL
     *        0x7fffffffdf46   0x00 > NULL
     *        0x7fffffffdf47   0x00 > NULL 8 bytes
     *        ------------------------------------
     *        0x7fffffffdf48   0x29 > float-point
     *        0x7fffffffdf49   0xcb > float-point
     *        0x7fffffffdf4a   0x10 > float-point
     *        0x7fffffffdf4b   0xc7 > float-point
     *        0x7fffffffdf4c   0x71 > float-point 
     *        0x7fffffffdf4d   0x3e > float-point 
     *        0x7fffffffdf4e   0xe6 > float-point 
     *        0x7fffffffdf4f   0x40 > float-point  8 bytes
     *        --------------------------------------------
     *        0x7fffffffdf50   0xff > FF
     *        0x7fffffffdf51   0xff > FF
     *        0x7fffffffdf52   0xff > FF
     *        0x7fffffffdf53   0xff > FF
     *        0x7fffffffdf54   0x00 > NULL
     *        0x7fffffffdf55   0x00 > NULL
     *        0x7fffffffdf56   0x00 > NULL
     *        0x7fffffffdf57   0x00 > NULL  8 bytes
     *        -------------------------------------
     * // offsets
     * (gdb) p &structC.c
     * $2 = 0x7fffffffdf40 "M"
     * (gdb) p &structC.d
     * $3 = (double *) 0x7fffffffdf48
     * (gdb) p &structC.s
     * $4 = (int *) 0x7fffffffdf50
     *
     * for the struct declaration in this part, the order of data type declared is
     * char, double, int
     *
     * What if we change the order to
     * char, int, double
     *
     * Then the struct will hold 16 bytes.
     * because, char - 1 byte + 3 padding only (consider address is at 0)
     * because, int - 4 byte can be alligned after char. (now address is at 7)
     * Then double can be alligned from address 8 till 15.
     * the whole struct size is 16 bytes which is a multiple of 8
     * then next offset it can begin with is 16.
     * 
     * // alignment of above situation
     * (gdb) x/16bx &structC.c
     * 0x7fffffffdf50: 0x4d    0x00    0x00    0x00    0xff    0xff    0xff    0x00
     * 0x7fffffffdf58: 0x29    0xcb    0x10    0xc7    0x71    0x3e    0xe6    0x40
     *
     * // offsets
     * (gdb) p &structC.c
     * $1 = 0x7fffffffdf50 "M"
     * (gdb) p &structC.s
     * $2 = (int *) 0x7fffffffdf54
     * (gdb) p &structC.d
     * $3 = (double *) 0x7fffffffdf58 
     */

    structd_t structD = {45555.55555, 0xFFFFFFFF, 'M'};
    /* Output
     * (gdb) p structD
     * $1 = {d = 45555.555549999997, s = -1, c = 77 'M'}
     * the order of the data types is 
     * double, int, char
     * largest data type is 8, size of struct will be multiple of 8.
     * rest all data type inside will be alligned according to their size.
     * 
     * // struct layout
     * (gdb) x/16bx &structD
     * 0x7fffffffdf30: 0x29    0xcb    0x10    0xc7    0x71    0x3e    0xe6    0x40
     * 0x7fffffffdf38: 0xff    0xff    0xff    0xff    0x4d    0x00    0x00    0x00
     *        Address                 Data
     *        0x7fffffffdf30   0x29 > float-point
     *        0x7fffffffdf31   0xcb > float-point
     *        0x7fffffffdf32   0x10 > float-point
     *        0x7fffffffdf33   0xc7 > float-point
     *        0x7fffffffdf34   0x71 > float-point
     *        0x7fffffffdf35   0x3e > float-point
     *        0x7fffffffdf36   0xe6 > float-point
     *        0x7fffffffdf37   0x40 > float-point  8 bytes
     *        --------------------------------------------
     *        0x7fffffffdf38   0xff > FF ----> int is of 4 byte allignment it can start from offset 8
     *        0x7fffffffdf39   0xff > FF
     *        0x7fffffffdf3a   0xff > FF
     *        0x7fffffffdf3b   0xff > FF           4 bytes
     *        --------------------------------------------
     *        0x7fffffffdf3c   0x4d > 'M' ----> no strict allignment for char, 1 byte
     *        [so till here it's 13 bytes in total which is not a multiple of 8 hence we add 3 padding bits]
     *        0x7fffffffdf3d   0x00 > NULL
     *        0x7fffffffdf3e   0x00 > NULL
     *        0x7fffffffdf3f   0x00 > NULL         4 bytes --> now total size of struct is 16.
     *        --------------------------------------------
     *
     * // offsets
     * (gdb) p &structD.d
     * $2 = (double *) 0x7fffffffdf30
     * (gdb) p &structD.s
     * $3 = (int *) 0x7fffffffdf38
     * (gdb) p &structD.c
     * $4 = 0x7fffffffdf3c "M"
     */

    structe_t structE = {"RamRamRam", 255, 'A'};
    /* Output
     * p structE
     * $1 = {name = "RamRamRam", c = 65 'A'}
     * (gdb) x/20bx &check_mem
       0x7fffffffdf60: 0x52    0x61    0x6d    0x52    0x61    0x6d    0x52    0x61
       0x7fffffffdf68: 0x6d    0x00    0x00    0x00    0xff    0x00    0x00    0x00
       0x7fffffffdf70: 0x41    0x00    0x00    0x00
     * Int is the data type with largest size of 4 byte hence 4 byte allignemnt will be used
     * Since there are no strict alignment requirements for char, the compiler does not add padding.
     * Total size is reported to be 20 bytes.
     *        Address                 Data
     *        0x7fffffffdf60   0x52 > 'R'
     *        0x7fffffffdf61   0x61 > 'a'
     *        0x7fffffffdf62   0x6d > 'm'
     *        0x7fffffffdf63   0x52 > 'R' 4 bytes 
     *        -----------------------------------
     *        0x7fffffffdf64   0x61 > 'a'
     *        0x7fffffffdf65   0x6d > 'm'
     *        0x7fffffffdf66   0x52 > 'R'
     *        0x7fffffffdf67   0x61 > 'a' 4 bytes
     *        -----------------------------------
     *        0x7fffffffdf68   0x6d > 'm'
     *        0x7fffffffdf69   0x00 > NULL
     *        0x7fffffffdf6a   0x00 > NULL
     *        0x7fffffffdf6b   0x00 > NULL 4 bytes
     *        ------------------------------------
     *        0x7fffffffdf6c   0xff >  255
     *        0x7fffffffdf6d   0x00 > NULL
     *        0x7fffffffdf6e   0x00 > NULL
     *        0x7fffffffdf6f   0x00 > NULL 4 bytes
     *        ------------------------------------
     *        0x7fffffffdf70   0x41 > 'A' > 65
     *        0x7fffffffdf71   0x00 > NULL
     *        0x7fffffffdf72   0x00 > NULL
     *        0x7fffffffdf73   0x00 > NULL 4 bytes
     *        ------------------------------------
     *        // offsets in gdb
     *        (gdb) p &check_mem.name
     *        $2 = (char (*)[10]) 0x7fffffffdf60
     *        (gdb) p &check_mem.s
     *        $3 = (int *) 0x7fffffffdf6c
     *        (gdb) p &check_mem.c
     *        $4 = 0x7fffffffdf70 "A"
     *        sizeof(structe_t) = 20 <--- stdout
     */
    printf("sizeof(structa_t) = %lu\n", sizeof(structA));
    printf("sizeof(structb_t) = %lu\n", sizeof(structB));
    printf("sizeof(structc_t) = %lu\n", sizeof(structC));
    printf("sizeof(structd_t) = %lu\n", sizeof(structD));
    printf("sizeof(structe_t) = %lu\n", sizeof(structE));

    return 0;
}

// Note: one can find many examples here https://github.com/portfoliocourses/c-example-code/blob/main/structure_padding.c
