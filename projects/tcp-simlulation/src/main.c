#include <stdio.h>
#include "client.h"
#include "server.h"
#include "tcp_packet.h"

void sendPacketToNetwork(tcpPacket* packet, int isClientDestination) {
    printf(", packet is sent\n");

    if(isClientDestination) {
        clientReceivePacket(packet->source,
                            packet->destination,
                            packet);
    } else {
        serverReceivePacket(packet->destination,
                            packet->source,
                            packet);
    }
}

int main(void) {
    client clientCtx;
    server serverCtx;
    clientInit(&clientCtx, 0);
    serverInit(&serverCtx, 0);
    serverStartListening();
    clientConnect(&clientCtx, &serverCtx);
    return 0;
}
