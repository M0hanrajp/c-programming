/* Given an array of integers.
 * Return an array, where the first element is the count of positives numbers and the second element is
 * sum of negative numbers. 0 is neither positive nor negative.
 * If the input is an empty array or is null, return an empty array.
 */
#include <stddef.h>

void count_positives_sum_negatives(int *values, size_t count, int *positivesCount, int *negativesSum) {
  // Please store the positives count in the memory, pointed to
  // by the positivesCount parameter.
  // Please store the negatives sum in the memory, pointed to
  // by the negativesSum parameter.
  unsigned long posCount = 0, negSum = 0;
  for (unsigned long index = 0; index < count; index++) {
    if(values[index] > 0)
      posCount++;
    if(values[index] < 0)
      negSum -= values[index];   
  }
  *positivesCount = posCount;
  *negativesSum = -negSum;
}

    // int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15 };
    // 
    // int posCountExpected = 10;
    // int negSumExpected = -65;
    //
    // int values[] = { 0, 2, 3, 0, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14 };
    // 
    // int posCountExpected = 8;
    // int negSumExpected = -50;
