/* In mathematics, the factorial of a non-negative integer n, denoted by n!, is 
 * the product of all positive integers less than or equal to n. 
 * For example: 5! = 5 * 4 * 3 * 2 * 1 = 120. By convention the value of 0! is 1.

Write a function to calculate factorial for a given input. If input is below 0 or above 12
throw an exception return -1 (C).
More details about factorial can be found here. */
int factorial(int n) {
  static int result = 0;
  result = -1;
  if(n < 13 && n > -1){result = 1;while(n > 0) {result *= n;n--;}}
  return result;
}
