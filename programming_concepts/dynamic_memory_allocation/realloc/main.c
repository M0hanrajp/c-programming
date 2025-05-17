/* realloc example: rememb-o-matic */
#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */

int main ()
{
  int input,n;
  int count = 0;
  int* numbers = NULL;
  int* more_numbers = NULL;

  do {
     printf ("Enter an integer value (not 0): ");
     scanf ("%d", &input);
     count++;

     more_numbers = (int*) realloc (numbers, count * sizeof(int));
     // void* realloc (void* ptr, size_t size);
     // Changes the size of the memory block pointed to by ptr.
     // The function may move the memory block to a new location (whose address is returned by the function).
     // If the function fails to allocate the requested block of memory, a null pointer is returned, 
     // the memory block pointed to by argument ptr is not deallocated (it is still valid, and with its contents unchanged).

     if (more_numbers!=NULL) {
       numbers=more_numbers;
       // if realloc failed (returning NULL), you would lose the original address in numbers
       // therefore leak the previously allocated memory (because you no longer have any pointer to free it).
       numbers[count-1]=input;
     }
     else {
       free (numbers);
       puts ("Error (re)allocating memory");
       exit (1);
     }
  } while (input!=0);

  printf ("Numbers entered: ");
  for (n=0;n<count;n++) printf ("%d ",numbers[n]);
  free (numbers);

  return 0;
}
