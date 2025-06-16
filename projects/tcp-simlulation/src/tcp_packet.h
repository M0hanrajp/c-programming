#ifndef TCP_PACKET_H
#define TCP_PACKET_H

typedef enum flags {SYN, SYN_ACK, ACK} flags;

typedef struct client client;
typedef struct server server;

typedef struct tcpPacket {
    int seqNum;
    int ackNum;
    flags flag;
    client *source;
    server *destination;
} tcpPacket;

void sendPacketToNetwork(tcpPacket* packet, int isClientDestination);

#endif
