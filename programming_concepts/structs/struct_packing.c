#include <stdio.h>
#pragma pack(1)

/* some references
 * https://stackoverflow.com/questions/14179748/what-is-the-difference-between-pragma-pack-and-attribute-aligned
 * https://stackoverflow.com/questions/232785/use-of-pragma-in-c
 * https://stackoverflow.com/questions/8568432/is-gccs-attribute-packed-pragma-pack-unsafe
 */

int main(void) {

    // structure A
    typedef struct structa_tag {
        char c;
        short int s;
    } structa_t;

    // structure B
    typedef struct structb_tag {
        short int s;
        char c;
        int i;
    } structb_t;

    // structure C
    typedef struct structc_tag {
        char c;
        double d;
        int s;
    } structc_t;

    // structure D
    typedef struct structd_tag {
        double d;
        int s;
        char c;
    } __attribute__((packed)) structd_t;

/*  Usage of __attribute__((packed))

    // structure D
    typedef struct __attribute__((packed)) structd_tag {
        double d;
        int s;
        char c;
    } structd_t;

    // structure D
    typedef struct structd_tag {
        double d;
        int s;
        char c;
    } __attribute__((packed)) structd_t; */

    // structure E
    typedef struct structe_tag {
        char name[10]; // 10 bytes
        int s; // 4 bytes
        char c; // 1 byte
    } structe_t;

    // structure F
    typedef struct structf_tag {
        double *d;
        int *s;
        char *c;
        short int *i;
    } structf_t;

    printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));
    printf("sizeof(structe_t) = %lu\n", sizeof(structe_t));
    printf("sizeof(structf_t) = %lu\n", sizeof(structf_t));
/*
    >> output: entire output is 1 byte aligned
    sizeof(structa_t) = 3
    sizeof(structb_t) = 7
    sizeof(structc_t) = 13
    sizeof(structd_t) = 13
    sizeof(structe_t) = 15 
*/
    return 0;
}
