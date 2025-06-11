#include <stdio.h>

void eightBitRepresentation() {
    unsigned char c = 0xF1;
    printf("8 bit binary representation\n76543210\n");
    for(int i = 7; i >= 0; i--) {
        (c & (1u << i)) ? printf("1") : printf("0");
        if(i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

void sixteenBitRepresentation() {
    unsigned short c = 0xF0AB;
    printf("\n16 bit binary representation\n76543210 76543210\n");
    for(int i = 15; i >= 0; i--) {
        (c & (1u << i)) ? printf("1") : printf("0");
        if(i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

void thirtyTwoBitRepresentation() {
    unsigned int c = 0xF0ABF0CD;
    printf("\n32 bit binary representation\n76543210 76543210 76543210 76543210\n");
    for(int i = 31; i >= 0; i--) { 
        (c & (1u << i)) ? printf("1") : printf("0");
        if(i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

void sixtyFourBitRepresentation() {
    unsigned long c = 0xF0F0F0F0F0F0F0F0;
    printf("\n64 bit binary representation\n76543210 76543210 76543210 76543210 76543210 76543210 76543210 76543210\n");
    for(int i = 63; i >= 0; i--) { 
        (c & (1ul << i)) ? printf("1") : printf("0");
        if(i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

int main(void) {
    eightBitRepresentation();
    sixteenBitRepresentation();
    thirtyTwoBitRepresentation();
    sixtyFourBitRepresentation();
    return 0;
}
