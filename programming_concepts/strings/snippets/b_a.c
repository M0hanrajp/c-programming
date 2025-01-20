# include <stdio.h>
# include <string.h>
int main( ) {
    char *str1 = "United" ; // read only string
    char *str2 = "Front" ;  // read only string
    char *str3 ; // pointer is uninitialized
    str3 = strcat ( str1, str2 ) ; // seg fault, program exits
    printf ( "%s\n", str3 ) ;
    return 0 ;
}
// the only way to make this work is
// str1 should be a constant pointer to a char meaning string should be mutable.
// str3 should be allocated enough space to hold both str1 and str2 strings.
// then str3 = strcat ( str1, str2 ) will work as strcat returns the address of 
// destination char array i.e. str1, str3 being char pointer will point to str1.
// and print the array

