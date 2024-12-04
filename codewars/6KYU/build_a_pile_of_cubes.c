/* Your task is to construct a building which will be a 
 * pile of n cubes. The cube at the bottom will have a volume of
findNb(1071225) --> 45
findNb(91716553919377) --> -1 */
#include <math.h>
long long findNb(long long m) {
  long long n = 0;
  for(long long i = 0; n <= m; i++) {
    n = pow(((i * (i + 1)) / 2), 2);
    if(n >= m) {
      n = i;
      break;
    }
  }
  if(m == pow(((n * (n + 1)) / 2), 2))
    return n;
  else
    return -1;
}
