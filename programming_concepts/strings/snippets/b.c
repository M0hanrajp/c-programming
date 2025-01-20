# include <stdio.h>
int main( ) {
    char s[ ] = "Get organised! learn C!!" ;
    printf ( "%s\n", &s[ 2 ] ) ;
    printf ( "%s\n", s ) ;
    printf ( "%s\n", *s ) ;
    printf ( "%c\n", s[ 2 ] ) ;
    return 0 ;
}
// the output is ::
/* 
 * --> t organised! learn C!!
 * here s[2] is t, %s will start printing from this char to null terminator.
 *
 * --> Get organised! learn C!!
 * Normal functionality while printing s using %s.
 *
 * --> Get organised! learn C!!
 * %s and printing with &s gives a warning:
 * b.c:6:16: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[25]’ [-Wformat=]
 * &s is a pointer to the whole array (char (*)[25]), but when used as an argument to printf with the %s format specifier,
 * it decays to a char * (pointer to the first element of the array).
 * Since both s and &s point to the same memory location (the start of the string), printf prints the whole string starting
 * from the first character.
 *
 * --> t
 *  s[2] will yeild a character i.e. t
 *
 */
