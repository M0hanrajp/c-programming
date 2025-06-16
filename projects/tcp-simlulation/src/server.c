#include "server.h"
#include "tcp_packet.h"
#include <stdio.h>

void serverInit(server *server, int initialSeqNum) {
    server->state = LISTEN;
    server->seqNum = initialSeqNum;
}

void serverStartListening(/*server* server*/) {
    printf("[INFO]: SERVER has started listening\n");
}

void serverReceivePacket(server* server, client * client, tcpPacket *packet) {
    if(server->state == LISTEN && packet->flag == SYN) {
        // acknowledge client's SYN
        server->ackNum = packet->seqNum + 1;
        server->state = SYN_RECEIVED;
        printf("[INFO]: SERVER received SYN\n");

        // prepare SYN-ACK
        tcpPacket synAckPacket;
        synAckPacket.flag = SYN_ACK;
        synAckPacket.seqNum = server->seqNum;
        synAckPacket.ackNum = server->ackNum;
        synAckPacket.source = client;
        synAckPacket.destination = server;

        printf("[INFO]: SERVER sent SYN-ACK");

        printf(" [SERVER]: SEQ: %d & ACK: %d", 
            synAckPacket.seqNum,
            synAckPacket.ackNum);
        sendPacketToNetwork(&synAckPacket, 1);
    }

    if(server->state == SYN_RECEIVED && packet->flag == ACK) {
        if(packet->ackNum == server->seqNum + 1) {
            printf("[INFO]: SERVER received ACK\n");

            server->state = SERVER_ESTABLISHED;
        }
        printf("[INFO]: CLIENT-SERVER connection established\n");
    }
}
