# include <stdio.h>
int main( ) {
    char s[ ] = "Churchgate: no church no gate" ;
    char t[ 25 ] ;
    char *ss, *tt = t;
    ss = s ;
    t[0] = 'C';
    while ( *ss != '\0' )
     *++tt = *++ss ;
    printf ( "%s\n", t ) ;
    return 0 ;
}
/* Program received signal SIGSEGV, Segmentation fault.
main () at d.c:8
8            *tt++ = *ss++ ;
(gdb)

Program terminated with signal SIGSEGV, Segmentation fault.
The program no longer exists. 
- tt is declared as a pointer (char *tt) but is not initialized to point to a 
  valid memory location.
- When you attempt to dereference tt with *tt, it leads to undefined behavior,
  and in this case, a segmentation fault. 
- refer notes.md in root folder of strings for more info */

// In the above program if *tt is assigned t i.e. base address of t[25].
/* the output will be the whole string:Churchgate: no church no gate
 * but this will be depending on systems they might 
 * Appear to work correctly (as in your case).
 * Cause a segmentation fault.
 * Lead to unpredictable behavior.
 */

// How *tt++ works ? 
/* Postfix increment guarantees that the value before incrementing is used for 
 * the current operation, and the increment happens after the expression is evaluated.
 *  char s[] = "Hello";
    // Step-by-step execution of *tt++ = *ss++
    *tt++ = *ss++; // Step 1: 'H' from s[0] copied to t[0], increment is applied ss = &s[1], tt = &t[1]
    *tt++ = *ss++; // Step 2: 'e' from s[1] copied to t[1], increment is applied ss = &s[2], tt = &t[2]
    *tt++ = *ss++; // Step 3: 'l' from s[2] copied to t[2], increment is applied ss = &s[3], tt = &t[3] */

// if it was *++t then ++ is first preference and t moves to next address, then value will be copied to
// next address instead of first element address.
