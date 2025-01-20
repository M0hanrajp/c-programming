# include <stdio.h>
void main( ) {
    printf ( 5 + "Good Morning " ) ;
    return 0 ;
}
// the function is void type, it does not expect any return value 
/* the following error is observed:
 * f.c:2:6: warning: return type of ‘main’ is not ‘int’ [-Wmain]
    2 | void main( ) {
      |      ^~~~
f.c: In function ‘main’:
f.c:4:12: warning: ‘return’ with a value, in function returning void [-Wreturn-type]
    4 |     return 0 ;
      |            ^
f.c:2:6: note: declared here
    2 | void main( ) {
      |
*/

 // Regarding  printf ( 5 + "Good Morning " ) ;
/* Index:  0   1   2   3   4   5   6   7   8   9  10  11   12
   Value: 'G' 'o' 'o' 'd' ' ' 'M' 'o' 'r' 'n' 'i' 'n' 'g' '\0'
   When "Good Morning " is passed to a function like printf, it decays to a pointer to 
   the first character ('G')
   Adding an integer to a pointer moves the pointer forward by that many elements in the array.
   5 + "Good Morning " means:
   Start at the beginning of the string ('G') and move 5 characters forward.
   The pointer now points to the 'M' in "Morning ".
*/

