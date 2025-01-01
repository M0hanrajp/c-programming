/* Information
To find the mean (average) of a set of numbers add all of the numbers together and divide by the number of values in the list.

For an example list of 1, 3, 5, 7

1. Add all of the numbers

1+3+5+7 = 16
2. Divide by the number of values in the list. In this example there are 4 numbers in the list.

16/4 = 4
3. The mean (or average) of this list is 4 */
#include <stddef.h>
double find_average(size_t length, const int nums[length]) {
  static double avg = 0;avg = 0;
  for(size_t i = 0; i < length; i++)
    avg += nums[i];
  return avg / length * 1.0;
}
