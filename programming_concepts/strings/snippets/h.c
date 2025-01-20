# include <stdio.h>
int main( ) {
    printf ( "%ld %ld %ld\n", sizeof ( '3' ), sizeof ( "3" ), sizeof (3) ) ;
    return 0 ;
}
// will print 4 2 4
// '3' is a character literal, but in C, a character literal is of type int, not char.
// This means '3' is treated as an integer value (with an ASCII value of 51) and 
// occupies the same size as an int. On most systems, the size of an int is 4 bytes.
// Therefore, sizeof('3') evaluates to 4.
// printf("%ld\n", sizeof((char)'3'));  // This will print 1
