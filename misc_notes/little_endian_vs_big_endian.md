### big endian vs Little endian

![image](https://github.com/user-attachments/assets/4ce3546f-a32c-4ee4-a04d-d01f46b46003)

- When machines communicate over internet over internet they must agree on endianness.
- All the fields in network header must be big endian.
- Endianess is about byte ordering not bit ordering
- Endianess applies to multi byte values.

[Endianness and byte order, Bit order, Bit significance, Bit labels or bit numbering](https://stackoverflow.com/a/49622327/22135402)

[Practical example of big-endian and little-endian](https://stackoverflow.com/a/78830673/22135402)

```c
    typedef struct ByteExample{
        uint16_t a;  // 2 bytes
        uint32_t b;  // 4 bytes
        uint8_t c;   // 1 byte
    } checkEndianess;

    checkEndianess example;
    example.a = 0x1234;
    example.b = 0x56789ABC;
    example.c = 0xDE;
```
### Little endian
```bash
(gdb) x/12bx &example
0x7fffffffdf94: 0x34 lsb of example.a
0x7fffffffdf95: 0x12 msb of example.a
0x7fffffffdf96: 0x00 pad
0x7fffffffdf97: 0x00 pad
0x7fffffffdf98: 0xBC 
0x7fffffffdf99: 0x9A
0x7fffffffdf9a: 0x78
0x7fffffffdf9b: 0x56
0x7fffffffdf9c: 0xDE
0x7fffffffdf9d: 0x00 pad
0x7fffffffdf9e: 0x00 pad
0x7fffffffdf9f: 0x00 pad
# note that 0x00 are NULL, i.e. padding
34       12       BC       9A       78       56       DE
00110100 00010010 10111100 10011010 01111000 01010110 11011110
```

### Big endian
```bash
# Not executed on a actual big endian system just an example
0x7fffffffdf94: 0x12
0x7fffffffdf95: 0x34
0x7fffffffdf96: 0x00 pad
0x7fffffffdf97: 0x00 pad
0x7fffffffdf98: 0x56 
0x7fffffffdf99: 0x78
0x7fffffffdf9a: 0x9A
0x7fffffffdf9b: 0xBC
0x7fffffffdf9c: 0xDE
0x7fffffffdf9d: 0x00 pad
0x7fffffffdf9e: 0x00 pad
0x7fffffffdf9f: 0x00 pad
Big-Endian Byte will look like this:
12       34       56       78       9A       BC       DE
00010010 00110100 01010110 01111000 10011010 10111100 11011110
```
