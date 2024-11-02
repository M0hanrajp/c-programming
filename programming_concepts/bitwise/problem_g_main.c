/* YPK - problem g
 * take 8 bit number as input and set it's odd bits to 1 */
#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint8_t inputNumber = 0xf0;
    printf("Set odd bits to 1 :: %x\n", inputNumber | 0xaa);
    return 0;
}
