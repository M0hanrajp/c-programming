/* Rules

If the given value is 0 then it should return "0.00".
You will only be given Natural Numbers as arguments.
Examples (Input --> Output)
n
1 --> 1 --> "1.00"
2 --> 1 + 1/4 --> "1.25"
5 --> 1 + 1/4 + 1/7 + 1/10 + 1/13 --> "1.57" */
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
char *series_sum(size_t n) {
  char *res = (char *)calloc(5, sizeof(char));
  double num = 0;
  for(int i = n; i > 0; i--) {
    num += 1 / ((3.0 * (i - 1)) + 1);
  }
  sprintf(res, "%.2f", round(num * 100) / 100);
  res[5] = '\0';
  return res;
}
