// program that uses fread and fwrite
/* Usually when fputc is used it writes the numbers as chars to the file stream.
 * So an int (4 bytes in size), the number 12345 will take 5 bytes instead of 4.
 * In order to overcome this we can use fread and fwrite, which store data in thier original size.
 */
#include <stdio.h>

typedef struct os {
    float version;
    int   price;
    char  name[10];
} osInformation;

void readFromTermWriteToFile(const char *file_stream, const char *mode) {
    FILE *fp = fopen(file_stream, mode);
    osInformation info;
    char inputExit = 'y';
    unsigned fr = 0;
    while(inputExit != 'n') {
        printf("Enter the infomration on operating systems:\n");
        scanf("%s %f %d", info.name, &info.version, &info.price);
        fr = fwrite(&info, sizeof(info), 1, fp);
        /* size_t fwrite( const void* restrict buffer, size_t size, size_t count,
               FILE* restrict stream );
         * Writes count of objects from the given array buffer to the output stream
         * The file position indicator for the stream is advanced by the number of characters written.
         * If an error occurs, the resulting value of the file position indicator for the stream is indeterminate.
         * 
            buffer	-	pointer to the first object in the array to be written
            size	-	size of each object
            count	-	the number of the objects to be written
            stream	-	pointer to the output stream
         *  Return value, The number of objects written successfully, which may be less than count 
         *  if an error occurs. If size or count is zero, fwrite returns zero and performs no other action.
         */
        printf("fwrite function returned :: %u\n", fr);
        printf("Want program to continue ? (y/n):");
        scanf(" %c", &inputExit); // The leading space tells scanf to skip any whitespace characters 
                                  // (including the newline) before reading the actual character.
    }
    fclose(fp);
}

void readFromFileWriteToTerm(const char *file_stream, const char *mode) {
    FILE *fp = fopen(file_stream, mode);
    osInformation info;
    int fr = 0;
    while ((fr = fread(&info, sizeof(info), 1, fp)) == 1) {
        /* Reads up to count objects into the array buffer from the given input stream
         * The file position indicator for the stream is advanced by the number of characters read.
         * If an error occurs, the resulting value of the file position indicator for the stream is 
         * indeterminate. If a partial element is read, its value is indeterminate.
            buffer	-	pointer to the array where the read objects are stored
            size	-	size of each object in bytes
            count	-	the number of the objects to be read
            stream	-	the stream to read  
         * Return value, Number of objects read successfully, which may be less than count if an 
         * error or end-of-file condition occurs. If size or count is zero, fread returns zero and 
         * performs no other action.
         * fread does not distinguish between end-of-file and error, and callers must use feof and ferror to determine which occurred.
         */
        printf("%s %f %d\n", info.name, info.version, info.price);
        printf("fread function returned :: %d\n", fr);
    }
    fclose(fp);
}

int main(void) {
    readFromTermWriteToFile("fdir/fwrite", "wb");
    readFromFileWriteToTerm("fdir/fwrite", "rb");
    return 0;
}

/* Remeber the file that is being written to is in binary format hence using cat to view
 * file contents may not work properly
   $ cat fdir/fwrite
   �A      Ubuntu << unformated input
 *
 * when we use fread to read from file and print contents it prints it exactly as intended
    $ ./a.out
    Enter the infomration on operating systems:
    Ubuntu 22 9
    fwrite function returned :: 1
    Want program to continue ? (y/n):n
    Ubuntu 22.000000 9
    fscanf function returned :: 1
 */

// Using hexadecimal format to read the characters
/* 
$ hexdump -C fdir/fwrite
00000000  00 00 b0 41 ff 00 00 00  55 62 75 6e 74 75 00 00  |...A....Ubuntu..|
00000010  00 00 00 00                                       |....|
00000014

Identical to
(gdb) x/20bx &info
0x7fffffffdf60: 0x00    0x00    0xb0    0x41    0xff    0x00    0x00    0x00
0x7fffffffdf68: 0x55    0x62    0x75    0x6e    0x74    0x75    0x00    0x00
0x7fffffffdf70: 0x00    0x00    0x00    0x00

Bytes 0x00 - 0x03 (00 00 b0 41):

Field: version (float)
Interpretation: In little-endian order, these bytes represent 0x41b00000.
Float Value: 22.0 (in IEEE 754 format)
Bytes 0x04 - 0x07 (09 00 00 00):

Field: price (int)
Interpretation: This is the integer 9 stored in little-endian format.
Bytes 0x08 - 0x11:

Field: name[10] (char array)
Breakdown:
The bytes at offset 0x08 to 0x0D represent the characters:
0x55 → 'U'
0x62 → 'b'
0x75 → 'u'
0x6e → 'n'
0x74 → 't'
0x75 → 'u'
Following these, you see a series of 00 bytes:
The first 00 acts as the null terminator for the string "Ubuntu".
The remaining bytes (if any) fill out the 10-byte array.
In the hexdump, you see:
From offset 0x08 to 0x0F: 55 62 75 6e 74 75 00 00 (8 bytes)
From offset 0x10 to 0x11: 00 00 (the remaining 2 bytes)
Result: The name field contains the string "Ubuntu", padded with null characters.

*/
