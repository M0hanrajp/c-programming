#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

/* Understand bit field 
 * ====================
 * 6.7.2.1 C spec for struct bit field
 * Fig 3.2 SYSV-ABI-AMD64 spec, regarding bit field rules.
 * Understand bit alignment rules : https://stackoverflow.com/questions/79472611/clarification-struct-bitfield-memory-layout
 * Understand struct size with Bitfield POV: https://stackoverflow.com/questions/4129961/how-is-the-size-of-a-struct-with-bit-fields-determined-measured
 */

int main(void) {

/* Note, the current system is little endian hence lsb is placed at lowest memory address
    typedef struct ByteExample{
        uint16_t a;  // 2 bytes
        uint32_t b;  // 4 bytes
        uint8_t c;   // 1 byte
    } checkEndianess;
    checkEndianess example; example.a = 0x1234;example.b = 0x56789ABC;example.c = 0xDE;
    // Observe that lsb is arranged at the lowest address
    HEX:       34       12       BC       9A       78       56       DE
    BINARY:    00110100 00010010 10111100 10011010 01111000 01010110 11011110
               low address ------------------------------------> High address
*/

    typedef struct football_game {
        unsigned short      num_players  : 4;
        unsigned int        num_managers : 1;
        unsigned short      num_cameras  : 8;
        long int            num_vip      : 16;
        unsigned int        num_screens  : 4; // this field will be aligned to next boundary, an example, 
                                              // sizeof the struct will not change as it's included in 8 byte.
    } statistics;

    /* Q: How the bits are filled
     * Ans: Bits are filled from right to left (lsb to msb)
     *
     * Q: How the GDB displays struct memory layout when examining the struct
     * Ans: GDB displays the struct based on system endianess, if system is little endian
     * then lsb is stored in lowest memory address.
     *
     * Q: How the bits are packed/laid out in memory ? what are the bit alignmnet rules
     * Ans: Based on SYSV-ABI-AMD64
     * bit-fields must be contained in a storage unit appropriate for its declared type
     * So what is the meaning here ?
     * When a bit-field is declared as short (which is a 16-bit type on this platform), then 
     * that bit-field will fit inside a single aligned 16-bit storage unit.
     * a bit-field declared as short must correspond to bits that do not cross through a multiple of 16
     * What does cross through mean ?
     * It means the field declared as short with n bits must be aligned with bits multiple of 16.
     * For example consider if 10 bits are allocated for the field member that is declared of type short.
     * it can be allocated from 0 - 9 or 16 - 25
     * because 10 bits need to be within 16 byte boundary, it cannot be alligned from 7 - 16 because here
     * It is crossing 16 byte boundary, consider this boundary lies between 15 & 16.
     *
     * More clarification at https://stackoverflow.com/questions/79472611/clarification-struct-bitfield-memory-layout
     */

    // example A
    statistics week_a;
    week_a.num_players = 0xf;week_a.num_managers = 1; week_a.num_cameras = 0xff;
    week_a.num_vip = 0xfff, week_a.num_screens = 0xf;
    printf("sizeof week_a : %zu\n", sizeof(week_a));

/*  GDB memory layout 0x7fffffffdf88: 0xff    0xff    0xff    0x01    0x0f    0x00    0x00    0x00
 *
 *  0x7fffffffdf88 0xff = num_cameras(3 bits) + num_managers(1 bit) + num_players(4 bits)
    0x7fffffffdf89 0xff = num_vip(3 bits) + num_cameras(5 bits)
    0x7fffffffdf8a 0xff = num_vip(8 bits)
    0x7fffffffdf8b 0x01 = (4 bits are 0) + num_vip(5 bits (of which 4 are 0))
    0x7fffffffdf8c 0x0f = (4 bits are 0) + num_screens(4 bits)
    0x7fffffffdf8d 0x00 = 8 bits padding
    0x7fffffffdf8e 0x00 = 8 bits padding
    0x7fffffffdf8f 0x00 = 8 bits padding 
 
    > unsigned short num_players : 4 can occupy bits 0 through 3. This does not cross any multiple 
      of 16 so that's fine.
 
    > unsigned int num_managers : 1 occupies bit 4. The rule is that it should not cross a multiple 
      of 32, which is trivially satisfied.
 
    > unsigned short num_cameras : 8 occupies bits 5 through 12. Again, no multiple of 16 is crossed.
 
    > long int num_vip : 16 occupies bits 13 through 28. Since long int is 64 bits, the only requirement 
      here is that a multiple of 64 should not be crossed, and that's satisfied.

    > unsigned int num_screens : 4 cannot occupy bits 29 through 32 as you propose, because it would cross 
      a 32-bit boundary. This situation is at 0x7fffffffdf8b in above layout (You can think of the boundary 
      as being between bits 31 and 32.) Instead, it must occupy bits 32 through 35. Hence it is aligned at
      0x7fffffffdf8c (0x0f)
*/

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

    typedef struct bf_struct3
    {
        uint8_t bf1 : 1;
        uint8_t bf2 : 6;
        uint8_t bf3 : 2;
        uint32_t bf4 : 32;
    } __attribute__((packed)) bf3;

    bf1 a = {1, 0x1F, 3, 0x780000000000F0};
    bf2 b = {1, 0x1F, 3, 0x780000000000F0};
    bf3 c = {1, 0x1F, 3, 0x780000F0};
    printf("Size of bf1 %lu\n", sizeof(a));
    printf("Size of bf2 %lu\n", sizeof(b));
    printf("Size of bf2 %lu\n", sizeof(c));

/*  All the below layouts are of 64 bit ELF format
 *  # How the output looks without packing (padding is performed)
    (gdb) x/8bx &a
    0x7fffffffdf88: 0xbf    0xe1    0x01    0x00    0x00    0x00    0x00    0xf0
    
    // size of struct is 8 byte
    0x7fffffffdf88 0xbf = bf3(1 bit: 1) + bf2(6 bits: 0b011111 [bit6:0, bit5:1, bit4:1, bit3:1, bit2:1, bit1:1]) + bf1(1 bit: 1)
    0x7fffffffdf89 0xe1 = bf4(7 bits: 0b1110000 [bit7:1, bit6:1, bit5:1, bit4:0, bit3:0, bit2:0, bit1:0]) + bf3(1 bit: 1)
    0x7fffffffdf8a 0x01 = bf4(8 bits: 0b00000001)
    0x7fffffffdf8b 0x00 = bf4(8 bits: 0b00000000)
    0x7fffffffdf8c 0x00 = bf4(8 bits: 0b00000000)
    0x7fffffffdf8d 0x00 = bf4(8 bits: 0b00000000)
    0x7fffffffdf8e 0x00 = bf4(8 bits: 0b00000000)
    0x7fffffffdf8f 0xf0 = bf4(8 bits: 0b11110000) 
    note last 8 bytes of bf4 are 0x78 i.e. 0111(7 in Dec) 1000 (8 in Dec) but since bits are assigned from right to left.
    due to alignment all the high bits came together in this situation becoming F, and got stored in little endian format.
    

    (gdb) x/16bx &b
    0x7fffffffdf90: 0x3f    0x03    0x00    0x00    0x00    0x00    0x00    0x00
    0x7fffffffdf98: 0xf0    0x00    0x00    0x00    0x00    0x00    0x78    0x00

    // size of struct is 16 byte
    0x7fffffffdf90: 0x3F = bf2(6 bits: 0b011111 [bits1–6]) + bf1(1 bit: 1)  [bit7 unused]
    0x7fffffffdf91: 0x03 = bf3(2 bits: 0b11) + (6 bits unused: 0)
    0x7fffffffdf92: 0x00 = padding (8 bits)
    0x7fffffffdf93: 0x00 = padding (8 bits)
    0x7fffffffdf94: 0x00 = padding (8 bits)
    0x7fffffffdf95: 0x00 = padding (8 bits)
    0x7fffffffdf96: 0x00 = padding (8 bits)
    0x7fffffffdf97: 0x00 = padding (8 bits)
    0x7fffffffdf98: 0xF0 = bf4 (bits   0–7)
    0x7fffffffdf99: 0x00 = bf4 (bits  8–15)
    0x7fffffffdf9A: 0x00 = bf4 (bits 16–23)
    0x7fffffffdf9B: 0x00 = bf4 (bits 24–31)
    0x7fffffffdf9C: 0x00 = bf4 (bits 32–39)
    0x7fffffffdf9D: 0x00 = bf4 (bits 40–47)
    0x7fffffffdf9E: 0x78 = bf4 (bits 48–54)
    0x7fffffffdf9F: 0x00 = padding for bf4 (bits 55–63)
    Note in the above struct bf4's 55 bits cross 64 bit boundary if they are aligned at 0x7fffffffdf91.
    that is the reason why 6 bits are unused and there is padding till the next 8 byte boundary alignment.
    there is 8 byte boundary alingment as largest member would be 8 byte.
    Hence bf4 is alinged from 0x7fffffffdf98

    // the below example int is used instead of long so struct is 4 byte aligned
    (gdb) x/8bx &c
    0x7fffffffdf98: 0x3f    0x03    0x00    0x00    0xf0    0x00    0x00    0x78

    // size of struct is 8 bytes
    0x7fffffffdf98: 0x3F = bf2(6 bits: 0b011111 [bits1–6]) + bf1(1 bit: 1) + (unused 1 bit)
    0x7fffffffdf99: 0x03 = bf3(2 bits: 0b11) + (unused 6 bits)
    0x7fffffffdf9A: 0x00 = padding (8 bits)
    0x7fffffffdf9B: 0x00 = padding (8 bits)
    0x7fffffffdf9C: 0xF0 = bf4 (bits   0–7: 0b11110000)
    0x7fffffffdf9D: 0x00 = bf4 (bits  8–15: 0b00000000)
    0x7fffffffdf9E: 0x00 = bf4 (bits 16–23: 0b00000000)
    0x7fffffffdf9F: 0x78 = bf4 (bits 24–31: 0b01111000)
    Note bf4 if it starts aligning at df99 address it would cross the 32 bit boundary hence it
    is aligned from df9C an extra 4 byte.

    # How the output looks with packing i.e. __attribute__((packed))
    // when struct is packed, it sees 1 byte alignment and there is no padding
    // Hence we see a & b output the same struct with 8 byte size
    (gdb) x/8bx &a
    0x7fffffffdf90: 0xbf    0xe1    0x01    0x00    0x00    0x00    0x00    0xf0

    (gdb) x/8bx &b
    0x7fffffffdf98: 0xbf    0xe1    0x01    0x00    0x00    0x00    0x00    0xf0

    (gdb) x/6bx &c (size is 6 bytes as we need one extra bit which is aligned in next 1 byte)
    0x7fffffffdf82: 0xbf    0xe1    0x01    0x00    0xf0    0x00
    - if you check the number of bits it's 41, 5 byte for 40 bits and 1 byte extra for the 1 bit.
    0x7fffffffdf82: 0xBF = [Combined bf1+bf2+bf3, lower 8 bits: 0xBF]
    0x7fffffffdf83: 0xE1 = [Combined field’s 9th bit (bf3’s 2nd bit, =1) +
                            bf4’s lower 7 bits: 0x70 (0b1110000)]
    0x7fffffffdf84: 0x01 = bf4  (next 8 bits: bits 8–15)
    0x7fffffffdf85: 0x00 = bf4 (next 8 bits: bits 16–23)
    0x7fffffffdf86: 0xF0 = bf4 (next 8 bits: bits 24–31)
    0x7fffffffdf87: 0x00 = bf4 (remaining bits, upper bits unused)
 */
    return 0;
}
