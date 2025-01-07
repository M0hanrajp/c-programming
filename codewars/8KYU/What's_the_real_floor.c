/* Americans are odd people: in their buildings, the first floor is actually 
 * the ground floor and there is no 13th floor (due to superstition).
Write a function that given a floor in the american system returns the floor 
in the european system.
With the 1st floor being replaced by the ground floor and the 13th floor being 
removed, the numbers move down to take their place. In case of above 13, they 
move down by two because there are two omitted numbers below them.
Basements (negatives) stay the same as the universal level.
More information here

Examples
1  =>  0 
0  =>  0
5  =>  4
15  =>  13
-3  =>  -3 */
int get_real_floor(int n) {
  if(n > -1) {
    switch(n) {
      case 0: return 0;break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12: return n - 1;break;
      default: return n - 2;break;
    }
  }
  return n;
}
