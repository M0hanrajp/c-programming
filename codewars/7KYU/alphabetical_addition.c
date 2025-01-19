/* Your task is to add up letters to one letter.
The function will be given the array size, and an array of characters, each one being a letter to add.

Notes:
Letters will always be lowercase.
Letters can overflow (see second to last example of the description)
If no letters are given, the function should return 'z'
Examples:
add_letters(3, {'a', 'b', 'c'}) == 'f'
add_letters(2, {'a', 'b'})      == 'c'
add_letters(1, {'z'})           == 'z'
add_letters(2, {'z', 'a'})      == 'a'
add_letters(3, {'y', 'c', 'b'}) == 'd' // notice letters overflowing
add_letters(0, {})              == 'z' */
#include <stddef.h>
char add_letters(size_t n, const char *letters) {
  size_t letter = 0;
  for(size_t i = 0; i < n; i++)
    letter += (letters[i] - 96);
  while(letter > 26){letter -= 26;}
  return n > 1 ? 96 + letter : n == 0 ? 'z' : letters[0];
}
