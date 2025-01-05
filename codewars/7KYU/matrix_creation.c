/* (1)  =>  [[1]]
 * Create an identity matrix of the specified size ( >= 0 ).

(2) => [ [1,0],
         [0,1] ]

       [ [1,0,0,0,0],
         [0,1,0,0,0],
(5) =>   [0,0,1,0,0],
         [0,0,0,1,0],
         [0,0,0,0,1] ]   */
#include <stddef.h>

// don't allocate memory for the result
// assign values to the provided matrix

void get_matrix(size_t n, int matrix[n][n]) {

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        if (i == j) {
          matrix[i][j] = 1;
        }
        else {
          matrix[i][j] = 0;
        }
      }
    }

}
