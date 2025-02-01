/* How many bytes in memory would be occupied by the following
array of pointers to strings? How many bytes would be required to
store the same strings, if they are stored in a two-dimensional
character array? */
#include <stdio.h>
#include <string.h>

unsigned calculateMemory(char **array, unsigned size) {
  unsigned memory = 0;
  for(int i = 0; i < size; i++)
    memory += strlen(array[i]);
  return memory;
}

int main(void) {
  char *mess[ ] = {
    "Hammer and tongs",
    "Tooth and nail",
    "Spit and polish",
    "You and C"
  };
  printf("total amount of memory used by *mess[] = %u\n", calculateMemory(mess, sizeof(mess)/sizeof(*mess)));
  return 0;
}
