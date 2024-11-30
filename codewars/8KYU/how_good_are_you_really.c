#include <stdbool.h>

bool better_than_average(const int class_points[], int class_size, int your_points) {
  int class_avg = 0;
  for(int i = 0; i < class_size; i++) {
    class_avg += class_points[i];
  }
  return your_points >= (float )class_avg/class_size;
}
/* There was a test in your class and you passed it. Congratulations!
But you're an ambitious person. You want to know if you're better than the average student in your class.
You receive an array with your peers' test scores. Now calculate the average and compare your score!
Return true if you're better, else false!
  fixed_test(((int[])
    {12, 23, 34, 45, 56, 67, 78, 89, 90}),
    9, false */
