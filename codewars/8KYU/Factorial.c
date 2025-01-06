// calculate factorial of number
unsigned __int128 factorial(unsigned n) {
  static unsigned __int128 result = 1;
  result = 1;
  while(n > 0) {result *= n;n--;}
  return result;
}
