## Project: Mini Packet Analyzer 📊

This project focuses on defining and manipulating the header of a simplified network packet. You'll use struct bit fields to represent the different fields within the header, mimicking how they are used in real network protocols to save space and precisely define data structures.

### Project Requirements

Your task is to define a simplified packet header structure and write functions to pack (create) and unpack (interpret) data into and out of this header.

**1. Define the Packet Header Structure (Simplified):**

   Create a C structure named `MiniPacketHeader` using bit fields to represent the following (you can choose either a TCP-like or UDP-like simplified header):

   **Option A: TCP-like Simplified Header**
   * **Source Port:** 16 bits
   * **Destination Port:** 16 bits
   * **Sequence Number (Simplified):** 8 bits (instead of 32)
   * **Acknowledgement Number (Simplified):** 8 bits (instead of 32)
   * **Data Offset (Header Length):** 4 bits (represents the number of 32-bit words in the header)
   * **Reserved:** 3 bits (set to 0)
   * **Flags (Pick 3-4 common TCP flags):**
        * **URG:** 1 bit
        * **ACK:** 1 bit
        * **PSH:** 1 bit
        * **RST:** 1 bit
        * **SYN:** 1 bit
        * **FIN:** 1 bit
        *(Choose any 3 or 4 of these to keep it simple, for a total of 3-4 bits for flags)*
   * **Window Size (Simplified):** 7 bits (instead of 16)

   **Option B: UDP-like Simplified Header**
   * **Source Port:** 16 bits
   * **Destination Port:** 16 bits
   * **Length:** 16 bits (total length of header and data)
   * **Checksum (Simplified):** 8 bits (instead of 16)

   **Important:** Choose **one** option (A or B) for your structure. The key is to use bit fields for each member according to the specified bit lengths.

**2. Implement Functionalities:**

   You'll need to write C functions to:

   * **`create_packet_header()`:**
        * Takes individual values for each field of your chosen header (e.g., source port, destination port, flags, etc.) as input.
        * Populates the `MiniPacketHeader` struct using these values.
        * Returns the populated struct.

   * **`display_packet_header()`:**
        * Takes a `MiniPacketHeader` struct as input.
        * Prints the values of each field in a readable format (e.g., "Source Port: 1024", "SYN Flag: 1").

---

### Core Concept: Struct Bit Fields

Struct bit fields allow you to declare members of a structure with a specific number of bits. This is incredibly useful when:

* **Memory is at a premium:** Especially in embedded systems or network protocols where every byte counts.
* **Hardware register mapping:** When interfacing with hardware that has registers with specific bit layouts.
* **Protocol definitions:** Network protocols like TCP, UDP, and IP define headers with fields of varying, often non-byte-aligned, lengths.

---


