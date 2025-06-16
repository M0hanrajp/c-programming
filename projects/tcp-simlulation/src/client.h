#ifndef CLIENT_H
#define CLIENT_H

#include "server.h"
#include "tcp_packet.h"

// forward declaration
typedef struct server server;

typedef enum clientState {CLOSED, SYN_SENT, CLIENT_ESTABLISHED} clientState ;

typedef struct client {
    clientState state;
    int seqNum;
    int ackNum;
} client;

void clientInit(client *client, int initialSeqNum);
void clientConnect(client *client, server *server);
void clientReceivePacket(client *client, server *server, tcpPacket *packet);

#endif
