// Write and read multiple type of data from terminal to file
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
        fr = fprintf(fp, "%s %.2f %d\n", info.name, info.version, info.price);
        /* int fprintf( FILE* restrict stream, const char* restrict format, ... ); (since C99)
         *  > Writes the results to the output stream (specified in first argument)
         *  > format:: all the format specifiers
         *  > returns :number of characters transmitted to the output stream or negative value if an 
         *  output error or an encoding error (for string and character conversion specifiers) occurred.
         */
        printf("fprintf function returned :: %u\n", fr);
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
    while ((fr = fscanf(fp, "%s %f %d", info.name, &info.version, &info.price)) != EOF) {
        /* int fscanf( FILE *restrict stream, const char *restrict format, ... );(since C99)
         * reads the data from file stream
         * function returns :: Number of receiving arguments successfully assigned (which may be 
         * zero in case a matching failure occurred before the first receiving argument was 
         * assigned), or EOF if input failure occurs before the first receiving argument was assigned.
         */
        printf("%s %f %d\n", info.name, info.version, info.price);
        printf("fscanf function returned :: %d\n", fr);
    }
    fclose(fp);
}

int main(void) {
    readFromTermWriteToFile("fdir/multi_data_type.log", "w");
    readFromFileWriteToTerm("fdir/multi_data_type.log", "r");
    return 0;
}
