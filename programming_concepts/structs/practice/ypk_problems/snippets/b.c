# include <stdio.h>
# include <string.h>
int main( ) {
    struct part {
        char partname[ 50 ] ;
        int partnumber ;
    } ;

    struct part p, *ptrp ;
    ptrp = &p ;
    strcpy ( p.partname, "CrankShaft" ) ;
    p.partnumber = 102133 ;
    printf ( "%s %d\n", p.partname, p.partnumber ) ;
    printf ( "%s %d\n", (*ptrp).partname, (*ptrp).partnumber ) ;
    printf ( "%s %d\n", ptrp->partname, ptrp->partnumber ) ;
    return 0 ;
}
/* My answer
 * CrankShaft 102133
 * CrankShaft 102133
 * CrankShaft 102133
 */
// This is correct
