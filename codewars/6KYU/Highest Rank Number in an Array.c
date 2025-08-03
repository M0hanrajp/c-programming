/* Complete the method which returns the number which is most frequent in the 
 * given input array. If there is a tie for most frequent number, return the 
 * largest number among them.

Note: no empty arrays will be given.

Examples
[12, 10, 8, 12, 7, 6, 4, 10, 12]              -->  12
[12, 10, 8, 12, 7, 6, 4, 10, 12, 10]          -->  12
[12, 10, 8, 8, 3, 3, 3, 3, 2, 4, 10, 12, 10]  -->   3 */
#include <stddef.h>

int get_most_frequent (size_t length, const int array[length]) {
	  int count_t = 0, num_t = 0, count = 0;
    for(size_t i = 0; i < length; i++) {
        if(array[i] == num_t){continue;}
        for(size_t j = 0; j < length; j++) {
            if(array[i] == array[j]){count++;}
        }
        if(count > count_t) {
            count_t = count;
            num_t = array[i];
        }
        if(count == count_t) {
            if(array[i] > num_t) {
                num_t = array[i];
            }
        }
        count = 0;
    }
  return num_t;
}
