#include "mini_packet_analyzer.h"
#include <stdio.h>

void createPacketHeader(
    unsigned sourcePort,
    unsigned destinaionPort,
    unsigned sequenceNumber,
    unsigned acknowledgementNumber,
    unsigned dataOffset, // header length
    unsigned reserved,
    unsigned ack,
    unsigned syn,
    unsigned fin,
    miniPacketHeader *pkt) {

    pkt->sourcePort = sourcePort;
    pkt->destinaionPort = destinaionPort;
    pkt->sequenceNumber = sequenceNumber;
    pkt->acknowledgementNumber = acknowledgementNumber;
    pkt->dataOffset = dataOffset;
    pkt->reserved = reserved;
    pkt->ack = ack;
    pkt->syn = syn;
    pkt->fin = fin;
}


void displayPacketHeader(miniPacketHeader *pkt) {
    printf("Transmission Control Protocol, Src Port: %u, Dst Port: %u, Seq: %u, Len: %u\n",
            pkt->sourcePort, pkt->destinaionPort, pkt->sequenceNumber & 1, pkt->dataOffset);
    printf("\tSource Port: %u\n", pkt->sourcePort);
    printf("\tDestination Port: %u\n", pkt->destinaionPort);
    printf("\t[Conversation completeness: Complete, WITH_DATA (31)]\n");
    printf("\t\t...%u .... = FIN: %s\n", pkt->fin, pkt->fin == 1 ? "Present" : "Absent");
    printf("\t\t...%u .... = ACK: %s\n", pkt->ack, pkt->ack == 1 ? "Present" : "Absent");
    printf("\t\t...%u .... = SYN: %s\n", pkt->syn, pkt->syn == 1 ? "Present" : "Absent");
    printf("\tSequence Number (raw): %u\n", pkt->sequenceNumber);
    printf("\tAcknowledgment Number: %u\n", pkt->acknowledgementNumber & 1);
    printf("\tAcknowledgment number (raw): %u\n", pkt->acknowledgementNumber);
    printf("\tBIN_REP .... = Header Length: %zu bytes (%u)\n", sizeof(unsigned), pkt->dataOffset); 
    printf("\tFlags: %X (SYN)\n", pkt->syn);
    printf("\t.... ....%u .... = Acknowledgment: Not set\n", pkt->ack & 1);
    printf("\t.... .... ..%u. = Syn: Set\n", pkt->syn & 1);
    printf("\t.... .... ...%u = fyn: Set\n", pkt->fin & 1);
}
