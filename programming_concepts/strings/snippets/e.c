# include <stdio.h>
int main( ) {
    char str1[ ] = { 'H', 'e', 'l', 'l', 'o', 0 } ;
    char str2[ ] = "Hello" ;
    printf ( "%s\n", str1 ) ;
    printf ( "%s\n", str2 ) ;
    return 0 ;
}
// both str1 and str2 print hello as str1 ends will 0 i.e. null
