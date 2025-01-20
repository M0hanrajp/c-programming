# include <stdio.h>
int main( ) {
    printf ( "%c\n", "abcdefgh"[ 4 ] ) ;
    return 0 ;
}
// prints e.
// "abcdefgh"[4] can be expanded to: *("abcdefgh" + 4)
// "abcdefgh" is a pointer to the first character 'a'
