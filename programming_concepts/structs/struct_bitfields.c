#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

/* https://stackoverflow.com/questions/4129961/how-is-the-size-of-a-struct-with-bit-fields-determined-measured
 * https://stackoverflow.com/questions/45403919/size-of-a-struct-with-bitfields-not-aligned-on-byte-boundary
 * https://stackoverflow.com/questions/50041152/inaccurate-size-of-a-struct-with-bit-fields-in-my-book
 * https://stackoverflow.com/questions/16692699/bit-field-padding-in-c
 * https://stackoverflow.com/questions/16803397/can-endianness-refer-to-bits-order-in-a-byte
 * https://stackoverflow.com/questions/47586786/big-endian-and-little-endian-little-confusion
 * https://stackoverflow.com/questions/26842043/memory-layout-of-bitfield-in-c-cant-understand-the-output
 * https://jkz.wtf/bit-field-packing-in-gcc-and-clang
 * 6.7.2.1 C spec for struct bit field
 */

int main(void) {

/*     // For checking endianess
    typedef struct ByteExample{
        uint16_t a;  // 2 bytes
        uint32_t b;  // 4 bytes
        uint8_t c;   // 1 byte
    } checkEndianess;

    checkEndianess example;
    example.a = 0x1234;
    example.b = 0x56789ABC;
    example.c = 0xDE; */
    /* Note, the current system is little endian hence lsb is placed at lowest memory address */

    typedef struct football_game {
        unsigned short      num_players  : 4;
        unsigned int        num_managers : 1;
        unsigned short      num_cameras  : 8;
        long int            num_vip      : 16;
        //unsigned int        num_screens  : 4;
    } statistics;

    // How the bits are filled
    // How the GDB displays it (based on endianess)
    // How the bits are packed laid out in memory is it based on the largest members size
    // currently the spec does not say anything on how bits should be padded or how the memory is laid out

    statistics week_a;
    week_a.num_players = 0xf;week_a.num_managers = 1; week_a.num_cameras = 0xff;
    week_a.num_vip = 0xfff;//, week_a.num_screens = 0xf;
    printf("sizeof week_a : %zu\n", sizeof(week_a));
    unsigned char *ptr = (unsigned char *)&week_a;
/*     for (int i = 0; i < sizeof(week_a); i++) {
        printf("Memory loc: %u has value %x\n", (ptr + i), *(ptr + i));
    } */

    typedef struct bf_struct1
    {
        uint64_t bf1 : 1;
        uint64_t bf2 : 6;
        uint64_t bf3 : 2;
        uint64_t bf4 : 55;
    } bf1;

    typedef struct bf_struct2
    {
        uint8_t bf1 : 1;
        uint8_t bf2 : 6;
        uint8_t bf3 : 2;
        uint64_t bf4 : 55;
    } bf2;

    bf1 ex = {1, 1, 1, 0xf};
    bf2 ez = {1, 1, 1, 0xf};
    printf("%lu ", sizeof(struct bf_struct1));
    printf("%lu ", sizeof(struct bf_struct2));

/*  # How the output looks without packing
    (gdb) x/8bx &ex
    0x7fffffffdf70: 0x83    0x1e    0x00    0x00    0x00    0x00    0x00    0x00

    (gdb) x/16bx &ez
    0x7fffffffdf80: 0x03    0x01    0x00    0x00    0x00    0x00    0x00    0x00
    0x7fffffffdf88: 0x0f    0x00    0x00    0x00    0x00    0x00    0x00    0x00
    ^--- need to check why bits were padded

    # How the output looks with packing i.e. __attribute__((packed)) 
    (gdb) x/8bx &ex
    0x7fffffffdf88: 0x83    0x1e    0x00    0x00    0x00    0x00    0x00    0x00

    (gdb) x/8bx &ez
    0x7fffffffdf90: 0x83    0x1e    0x00    0x00    0x00    0x00    0x00    0x00

 */
    return 0;
}
