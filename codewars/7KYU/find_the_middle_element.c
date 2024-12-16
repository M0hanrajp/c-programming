/* The input to the function will be an array of three distinct numbers (Haskell: a tuple).

For example:
gimme([2, 3, 1]) => 0
2 is the number that fits between 1 and 3 and the index of 2 in the input array is 0.

Another example (just to make sure it is clear):
gimme([5, 10, 14]) => 1
10 is the number that fits between 5 and 14 and the index of 10 in the input array is 1. */
int gimme (const int triplet[3]) {
  int index = 0;
  if((triplet[0] > triplet[1] && triplet[0] < triplet[2]) || (triplet[0] < triplet[1] && triplet[0] > triplet[2]))
    return index;
  if((triplet[1] > triplet[0] && triplet[1] < triplet[2]) || (triplet[1] < triplet[0] && triplet[1] > triplet[2]))
    return index = 1; 
  else
    return index = 2;
}
