/* Given an unsorted array of 3 positive integers [ n1, n2, n3 ], determine if it is possible 
 * to form a Pythagorean Triple using those 3 integers. A Pythagorean Triple consists of 
 * arranging 3 integers, such that:
a2 + b2 = c2

Examples
[5, 3, 4] : it is possible to form a Pythagorean Triple using these 3 integers: 32 + 42 = 52
[3, 4, 5] : it is possible to form a Pythagorean Triple using these 3 integers: 32 + 42 = 52
[13, 12, 5] : it is possible to form a Pythagorean Triple using these 3 integers: 52 + 122 = 132
[100, 3, 999] : it is NOT possible to form a Pythagorean Triple using these 3 integers - no matter how you arrange them, you will never find a way to satisfy the equation a2 + b2 = c2
Return Values
For Python: return True or False
For JavaScript: return true or false
Other languages: return 1 or 0 or refer to Sample Tests. */
#include <stdbool.h>
bool pythagorean_triple(const unsigned sides[3]) {
 unsigned *ptr = sides;
 for(int i = 0; i < 3; i++) {
   unsigned temp = 0;
   for(int j = i + 1; j < 3; j++) {
     if(ptr[i] > ptr[j]) {
       temp = ptr[i];
       ptr[i] = ptr[j];
       ptr[j] = temp;
     }
   }
 }
 return ptr[0] * ptr[0] + ptr[1] * ptr[1] == ptr[2] * ptr[2];
}
