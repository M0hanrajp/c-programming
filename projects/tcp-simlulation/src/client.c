#include "client.h"
#include "server.h"
#include "tcp_packet.h"
#include <stdio.h>

void clientInit(client* client, int initialSeqNum) {
    client->state = CLOSED;
    client->seqNum = initialSeqNum;
    printf("[INFO]: CLIENT initialized\n");
}

void clientConnect(client* client, server* server) {
    client->state = SYN_SENT;
    // creates syn packet, packet.h
    tcpPacket synPacket;
    synPacket.seqNum = client->seqNum;
    synPacket.flag = SYN;
    synPacket.source = client;
    synPacket.destination = server;
    printf("[INFO]: CLIENT sent SYN");

    printf(" [CLIENT]: SEQ: %d & ACK: %d", 
            synPacket.seqNum,
            synPacket.ackNum);

    // Calls send_packet_to_network(&syn_packet, server_entity, 0 /* not client */) to send the SYN to the server.
    // sending packet to server
    sendPacketToNetwork(&synPacket, 0);
}

void clientReceivePacket(client *client, server *server, tcpPacket *packet) {
    if(client->state == SYN_SENT && packet->flag == SYN_ACK) {
        // check if server sent ACK set to 1
        if(packet->ackNum == client->seqNum + 1)
            printf("[INFO]: CLIENT received SYN-ACK\n");

        // prepare ACK packet from client POV
        client->ackNum = packet->seqNum + 1;
        client->state = CLIENT_ESTABLISHED;

        tcpPacket ackPacket;
        ackPacket.flag = ACK;
        ackPacket.seqNum = client->seqNum + 1;
        ackPacket.ackNum = client->ackNum;
        ackPacket.source = client;
        ackPacket.destination = server;
        printf("[INFO]: CLIENT sent ACK");

        printf(" [CLIENT]: SEQ: %d & ACK: %d", 
        ackPacket.seqNum,
        ackPacket.ackNum);

        sendPacketToNetwork(&ackPacket, 0);
    }
}
