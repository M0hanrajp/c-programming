/* You've just discovered a square (NxN) field and you notice a warning sign. 
 * The sign states that there's a single bomb in the 2D grid-like field in 
 * front of you.
Write a function mineLocation/MineLocation that accepts a 2D array, and returns 
the location of the mine. The mine is represented as the integer 1 in the 2D array.
Areas in the 2D array that are not the mine will be represented as 0s.
The location returned should be an array (Tuple<int, int> in C#, RAX:RDX in NASM) 
where the first element is the row index, and the second element is the column index 
of the bomb location (both should be 0 based). All 2D arrays passed into your function 
will be square (NxN), and there will only be one mine in the array.

Examples:
mineLocation( [ [1, 0, 0], [0, 0, 0], [0, 0, 0] ] ) => returns [0, 0]
mineLocation( [ [0, 0, 0], [0, 1, 0], [0, 0, 0] ] ) => returns [1, 1]
mineLocation( [ [0, 0, 0], [0, 0, 0], [0, 1, 0] ] ) => returns [2, 1] */
#include <stdlib.h>
size_t *mine_location(size_t n, const int field[n][n]) {
  size_t *grid = (size_t *)calloc(n, sizeof(size_t ));
  size_t r = 0 ,c = 0;
  for(r = 0; r < n; r++) {
    for(c = 0; c < n; c++) {
      grid[0] = r;grid[1] = c;
      if(field[r][c] == 1){return grid;}
    }
  }
  return 0;
}
