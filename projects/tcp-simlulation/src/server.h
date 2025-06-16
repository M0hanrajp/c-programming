#ifndef SERVER_H
#define SERVER_H

// forward declaration
#include "tcp_packet.h"
typedef struct client client;

typedef enum serverState {LISTEN, SYN_RECEIVED,
                          SERVER_ESTABLISHED} serverState;

typedef struct server {
    serverState state;
    int seqNum;
    int ackNum;
} server;

void serverInit(server *server, int initialSeqNum);
void serverStartListening(/*server* server*/);
void serverReceivePacket(server* server, client *client, tcpPacket *packet);

#endif
