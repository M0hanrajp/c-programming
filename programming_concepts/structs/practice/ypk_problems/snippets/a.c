# include <stdio.h>
# include <string.h>
# include <stddef.h>
int main( ) {
    struct gospel {
        int num ;
        char mess1[ 50 ] ;
        char mess2[ 50 ] ;
    } m;
    m.num = 1 ;
    strcpy ( m.mess1, "If all that you have is hammer" ) ;
    strcpy ( m.mess2, "Everything looks like a nail" ) ;
    /* assume that the strucure is located at address 1004 */
    printf ( "%u %u %u\n", &m.num, m.mess1, m.mess2 ) ;
    // below is for verification.
    printf("Offset of num: %zu\n", offsetof(struct gospel, num));
    printf("Offset of mess1: %zu\n", offsetof(struct gospel, mess1));
    printf("Offset of mess2: %zu\n", offsetof(struct gospel, mess2));
    printf("Total size: %zu\n", sizeof(m));
    return 0 ;
}
// My answer
/*
 * 1004, 1008, 1060
 * this is wrong
 *
 * My mistake was to add 2 byte padding after mess1 in order to keep address
 * multiple of 4 but that does not matter.*/
    /* Important
     *
     * Each member within the structure is aligned according to its own type's alignment 
     * requirements, while the overall structure size is aligned to the largest member’s 
     * alignment requirement. */

    /* The overall structure size must be a multiple of the largest member’s alignment 
     * (which is double, requiring 8-byte alignment). This ensures that if an array of 
     * structc_t is created, every instance is properly aligned. */

