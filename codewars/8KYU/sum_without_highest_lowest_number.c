/* Sum all the numbers of a given array ( cq. list ), except the highest and the 
 * lowest element ( by value, not by index! ).
The highest or lowest element respectively is a single element at each edge, even 
if there are more than one with the same value.
Mind the input validation.
Example
{ 6, 2, 1, 8, 10 } => 16
{ 1, 1, 11, 2, 3 } => 6
Input validation
If an empty value ( null, None, Nothing, nil etc. ) is given instead of an array, 
or the given array is an empty list or a list with only 1 element, return 0. */
int sum(const int numbers[/*length*/], int length) {
  int sum = 0, hi = 0, li = 0, hn = 0, ln = 0;
  if(length > 2) {
    hn = numbers[0];
    ln = numbers[0];
    for(int i = 0; i < length; i++) {
      if(numbers[i] < ln) {
        ln = numbers[i];
        li = i;
      }
      if(numbers[i] > hn) {
        hn = numbers[i];
        hi = i;
      }
    }
    for(int i = 0; i < length; i++) {
      if(i == li || i == hi)
        continue;
      sum += numbers[i];
    }
  }
  return sum;
}
