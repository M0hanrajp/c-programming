# include <stdio.h>
int main( ) {
    char arr[ 8 ] = "Rhombus" ;
    int i ;
    for ( i = 0 ; i <= 7 ; i++ )
        printf ( "%d", *arr ) ; // will always print R's ascii value
    arr++ ; // arr is a const pointer to char, increment is not allowed
    return 0 ;
}
/* :~/c-programming/programming_concepts/strings/snippets$ gcc -g -Wall b_c.c
b_c.c: In function ‘main’:
b_c.c:7:8: error: lvalue required as increment operand
    7 |     arr++ ;
      |        ^~ */
