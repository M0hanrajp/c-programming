/* Looks like some hoodlum plumber and his brother has been running around and damaging your stages again.
The pipes connecting your level's stages together need to be fixed before you receive any more complaints.
The pipes are correct when each pipe after the first is 1 more than the previous one.
Task
Given a list of unique numbers sorted in ascending order, return a new list so that the values increment by 1 for each index from the minimum value up to the maximum value (both included).
Example
Input:  1,3,5,6,7,8 Output: 1,2,3,4,5,6,7,8 */
#include <stddef.h>
#include <stdlib.h>
//  return a dynamically allocated int array
//  set the pointer sz_out to size of output
//  return array will be freed by the tester
int *pipe_fix(size_t sz_in, const int input[sz_in], size_t *sz_out) {	
  size_t index = 0;
  int *output = (int *)calloc(input[sz_in - 1] + 1, sizeof(int));
  for(int i = input[0]; i <= input[sz_in - 1]; i++)
    output[index++] = i;
  *sz_out = index;
	return output;
}
