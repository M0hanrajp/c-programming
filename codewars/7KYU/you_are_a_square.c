/* In mathematics, a square number or perfect square is an integer that is 
 * the square of an integer; in other words, it is the product of some integer
 * with itself.
The tests will always use some integral number, so don't worry about that in dynamic typed languages.
Examples
-1  =>  false
 0  =>  true
 3  =>  false
 4  =>  true
25  =>  true
26  =>  false */
#include <stdbool.h>
#include <math.h>
bool is_square(int n) {
  if(n < 0)
    return false;
  int check = sqrt(n);
  if(check * check == n)
    return true;
  else
    return false;
}
