# include <stdio.h>
int main( ) {
    char c[ 2 ] = "A";
    printf ( "%c\n", c[0] ) ;
    printf ( "%s\n", c ) ;
    return 0 ;
}
// my ans
// should print 
// A
// A
// ============
// c[0] access first element, %s prints string until it encounters null character.
