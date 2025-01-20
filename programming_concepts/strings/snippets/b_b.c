# include <stdio.h>
int main( ) {
    int arr[ ] = { 'A', 'B', 'C', 'D' } ;
    int i ;
    for ( i = 0 ; i <= 3 ; i++ )
        printf ( "%d", arr[ i ] ) ;
    printf ( "\n" ) ;
    return 0 ;
}
// as character literal is of type int, 65 to 68 will printed without space.
