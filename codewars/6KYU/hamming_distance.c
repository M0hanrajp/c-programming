/* The Hamming Distance is a measure of similarity between two strings of 
 * equal length. Complete the function so that it returns the number of 
 * positions where the input strings do not match.

Examples:
a = "I like turtles"
b = "I like turkeys"
Result: 3

a = "Hello World"
b = "Hello World"
Result: 0

a = "espresso"
b = "Expresso"
Result: 2
You can assume that the two inputs are ASCII strings of equal length. */
#include <stddef.h>
size_t hamming_distance (const char *a, const char *b){
  size_t hamming_distance = 0;
  while(*a && *b) {
    if(*a != *b)
      hamming_distance++;
    a++;
    b++;
  }
	return hamming_distance;
}
