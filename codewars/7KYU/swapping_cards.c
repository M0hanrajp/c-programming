/* Paul's strategy is to always swap his lowest number with the opponent's ten's digit. 
 * Return whether this results in Paul winning the round.

n1 is Paul's number
n2 is his opponent's number
Worked Example
(41, 79) ➞ true
# Paul's lowest number is 1
# The opponent's ten's digit is 7
# After the swap: 47 > 19
# Paul wins the round
Examples
(41, 98) ➞ true

(12, 28) ➞ true

(67, 53) ➞ false

(77, 54) ➞ false
Notes
If both of Paul's digits are the same, swap the ten's digit with the opponent's (paul likes to live riskily).
The cards don't include the number 0.
11 <= All numbers <= 99 (excluding numbers containing 0) */
#include <stdbool.h>
#include <stdint.h>
bool swap_cards(uint8_t a, uint8_t b) {
  uint8_t tens_a = a / 10;
  uint8_t units_a = a % 10;
  bool result = false;
  if(tens_a > units_a) {a = tens_a * 10 + (b / 10);b = units_a * 10 + (b % 10);}
  else {a = ((b / 10) * 10) + units_a;b = tens_a * 10 + (b % 10);}
  return (result = a > b ? true : false);
}
