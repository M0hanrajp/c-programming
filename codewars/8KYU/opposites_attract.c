/* Timmy & Sarah think they are in love, but around where they live, 
 * they will only know once they pick a flower each. If one of the 
 * flowers has an even number of petals and the other has an odd number 
 * of petals it means they are in love.
 * Write a function that will take the number of petals of each flower 
 * and return true if they are in love and false if they aren't.
 */
#include <stdbool.h>

bool lovefunc(int flower1, int flower2) {
  if(flower1 % 2 == 0 && flower2 % 2 != 0)
    return true;
  if(flower1 % 2 != 0 && flower2 % 2 == 0)
    return true;
  return false;
}
// Example test cases:
  // cr_assert(lovefunc(1, 4));
  // cr_assert(lovefunc(0, 1));
  // cr_assert_not(lovefunc(2, 2));
  // cr_assert_not(lovefunc(0, 0));
