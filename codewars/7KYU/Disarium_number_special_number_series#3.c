/* Input >> Output Examples
disariumNumber(89) ==> return "Disarium !!"
Explanation:
Since , 81 + 92 = 89 , thus output is "Disarium !!"
disariumNumber(564) ==> return "Not !!"
Explanation:
Since , 51 + 62 + 43 = 105 != 564 , thus output is "Not !!" */
//returned string should be statically allocated, it will not be freed
#include <math.h>
const char *disariumNumber(int number) {
  if(number < 10){return "Disarium !!";}
  long int copy = number * 1, sum = 0;
  unsigned long div = 10, exp = 1;
  while(number / div > 9)
    div *= 10;  
  while(number > 0) {
    sum += pow((number / div), exp++);
    number %= div;
    div /= 10;
  }
  return sum == copy ? "Disarium !!" : "Not !!";
}
