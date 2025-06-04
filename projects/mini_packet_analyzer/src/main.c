#include "mini_packet_analyzer.h"

int main(void) {

    miniPacketHeader ctx;
    createPacketHeader(443, 
                       44331, 
                       23452, 
                       0, 
                       2, 
                       4, 
                       1234,
                       2342, 
                       1232,
                       &ctx);
    displayPacketHeader(&ctx);
    return 0;
}
