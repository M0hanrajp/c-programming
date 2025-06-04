#ifndef MINI_PACKET_ANALYZER_H
#define MINI_PACKET_ANALYZER_H

typedef struct miniPacketHeader {
    unsigned sourcePort: 16;           // 16 bits for the source port number
    unsigned destinaionPort: 16;       // 16 bits for the destination port number
    unsigned sequenceNumber: 8;        // 8 bits for the sequence number
    unsigned acknowledgementNumber: 8; // 8 bits for the acknowledgment number
    unsigned dataOffset: 4;            // 4 bits for the data offset (header length in 32-bit words)
    unsigned reserved: 3;              // 3 bits reserved for future use (should be set to 0)
    unsigned ack: 1;                   // 1 bit for the ACK (Acknowledgment) flag
    unsigned syn: 1;                   // 1 bit for the SYN (Synchronize) flag
    unsigned fin: 1;                   // 1 bit for the FIN (Finish) flag
} miniPacketHeader;

/**
 * @brief  Constructs a minimal packet header by populating the provided miniPacketHeader structure.
 *
 * This function initializes all fields of a miniPacketHeader (e.g., for a simplified TCP-like protocol)
 * based on the supplied parameter values. The caller is responsible for allocating the miniPacketHeader
 * structure pointed to by @p pkt before calling this function.
 *
 * @param sourcePort             The 16-bit source port number from which the packet originates.
 * @param destinationPort        The 16-bit destination port number to which the packet is sent.
 * @param sequenceNumber         The 32-bit sequence number of the first data byte in this packet.
 * @param acknowledgementNumber  The 32-bit acknowledgment number (next expected sequence number), 
 *                               valid if the ACK flag is set.
 * @param dataOffset             The 4-bit header length in 32-bit words (i.e., the number of 4-byte words 
 *                               comprising the header). Minimum value is 5 (for a 20-byte header).
 * @param reserved               A 3-bit field reserved for future use; typically set to 0.
 * @param ack                    The ACK flag (1 if this packet contains a valid acknowledgment number,
 *                               0 otherwise).
 * @param syn                    The SYN flag (1 to request a new connection, 0 otherwise).
 * @param fin                    The FIN flag (1 if this packet requests connection termination,
 *                               0 otherwise).
 * @param pkt                    Pointer to a pre-allocated miniPacketHeader structure that will be populated.
 * @note   Only the above flags (ACK, SYN, FIN) are supported in this minimal header. Other bits in the 
 *         flag/reserved fields are assumed to be zero.
 * @warning The caller must ensure that the miniPacketHeader pointed to by @p pkt is valid and large 
 *          enough to hold all header fields. This function does not perform any memory allocation.
 */
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
    miniPacketHeader *pkt);

/**
 * @brief  Prints the contents of a miniPacketHeader in a human-readable format.
 *
 * This function takes a pointer to a filled miniPacketHeader structure (e.g., created by
 * createPacketHeader) and displays each of its fields—source port, destination port, sequence
 * number, acknowledgment number, data offset, reserved bits, and individual flags (ACK, SYN, FIN)—
 * to stdout or another chosen output stream. It is primarily used for debugging or logging packet
 * details in a simple TCP-like protocol.
 *
 * @param pkt   Pointer to an initialized miniPacketHeader whose fields will be displayed.
 *              The structure should have been populated prior to calling this function.
 *
 * @note   The function assumes that pkt points to a valid miniPacketHeader. It does not modify
 *         the header; it only reads and prints its fields.
 *
 * @warning If pkt is NULL, the behavior is undefined. The caller should ensure pkt is non-NULL.
 */
void displayPacketHeader(miniPacketHeader *pkt);

#endif
