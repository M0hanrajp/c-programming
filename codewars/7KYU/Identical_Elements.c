/* Given two arrays of integers m and n, test if they contain at least one 
 * identical element. Return true if they do; false if not.
Your code must handle any value within the range of a 32-bit integer, and 
must be capable of handling either array being empty (which is a false result, 
as there are no duplicated elements). */
#include <stdbool.h>
#include <stddef.h>

bool duplicate_elements(size_t m_size, const int *m_array, size_t n_size, const int *n_array) {
  for(size_t i = 0; i < m_size; i++) {
    for(size_t j = 0; j < n_size; j++)
      if(m_array[i] == n_array[j]){return true;}
  }
  return false;
}
