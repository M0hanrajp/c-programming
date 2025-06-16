## TCP 3-Way Handshake Simulator

This project is a straightforward C program designed to help you understand the fundamental TCP 3-Way Handshake process. It simulates how a client and a server establish a connection before any data is exchanged.

_project is purely done for simulation purpose, there is no client server connection_

### What It Does

At its core, this simulation demonstrates the three crucial steps involved in setting up a TCP connection:

- SYN (Synchronize): The Client initiates the connection by sending a SYN packet to the Server, proposing an initial sequence number.
- SYN-ACK (Synchronize-Acknowledgment): The Server responds to the client's SYN with a SYN-ACK packet. This acknowledges the client's SYN and sends its own initial sequence number.
- ACK (Acknowledgment): Finally, the Client sends an ACK packet back to the Server, acknowledging the server's SYN.

Once these three steps are complete, both the Client and Server transition into an ESTABLISHED state, signifying that a connection has been successfully formed.


### Build & Run

```bash
make build
make run
```

### Key Features

- Focused Simulation: Specifically models the TCP 3-way handshake.
- Clear Output: Provides console output to show each packet exchange and state change.
- Educational Tool: Ideal for learning the basic principles of TCP connection establishment.

This project deliberately simplifies real-world networking complexities, omitting features like data transfer, error handling, retransmissions, packet loss, or network delays, to provide a clear and direct illustration of the handshake.

### File tree

```bash
$ tree .
.
├── Makefile
├── README.md
├── build
│   ├── client.o
│   ├── main.o
│   ├── server.o
│   └── tcp_sim
├── log
│   └── tcp_sim.log
└── src
    ├── client.c
    ├── client.h
    ├── main.c
    ├── server.c
    ├── server.h
    └── tcp_packet.h
```
