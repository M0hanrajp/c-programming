/* realloc example: rememb-o-matic */
#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */

int main ()
{
  int input,n;
  int count = 0;
  int* numbers = NULL;
  int* more_numbers = NULL;

/*   do {
     printf ("Enter an integer value (not 0): ");
     scanf ("%d", &input);
     count++; */

     //more_numbers = (int*) realloc (numbers, count * sizeof(int));
     // void* realloc (void* ptr, size_t size);
     // Changes the size of the memory block pointed to by ptr.
     // The function may move the memory block to a new location (whose address is returned by the function).
     // If the function fails to allocate the requested block of memory, a null pointer is returned, 
     // the memory block pointed to by argument ptr is not deallocated (it is still valid, and with its contents unchanged).
/* 
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
*/
  // printf ("Numbers entered: ");
  for (n=0;n<count;n++) printf ("%d ",numbers[n]);
  free (numbers);

  // the scenario
  int *a = (int *)calloc(10, sizeof(int));
  printf("a :: %p\n", a);
  
  for(int i = 0; i < 10; i++) a[i] = i;

  for(int i = 0; i < 10; i++) printf("a[%i] = %d at %p\n", i, a[i], a + i);

  int *b = (int *)calloc(10, sizeof(int));
  printf("b :: %p\n", b);

  for(int i = 0; i < 10; i++) b[i] = i;

  int *oldMemory = a;
  a = (int *)realloc(a, 30 * sizeof(int));
  printf("a :: after realloc %p\n", a);

  for(int i = 0; i < 30; i++) printf("a[%i] = %d at %p\n", i, a[i], a + i);

  printf("old memory::\n");
  for(int i = 0; i < 10; i++) printf("oldMemory[%i] = %d at %p\n", i, oldMemory[i], oldMemory + i);

/* Output
a :: 0x55f5adce52a0
a[0] = 0 at 0x55f5adce52a0
a[1] = 1 at 0x55f5adce52a4
a[2] = 2 at 0x55f5adce52a8
a[3] = 3 at 0x55f5adce52ac
a[4] = 4 at 0x55f5adce52b0
a[5] = 5 at 0x55f5adce52b4
a[6] = 6 at 0x55f5adce52b8
a[7] = 7 at 0x55f5adce52bc
a[8] = 8 at 0x55f5adce52c0
a[9] = 9 at 0x55f5adce52c4
b :: 0x55f5adce56e0
a :: after realloc 0x55f5adce5710
a[0] = 0 at 0x55f5adce5710
...
...
oldMemory[0] = 1599790309 at 0x55f5adce52a0
oldMemory[1] = 5 at 0x55f5adce52a4
oldMemory[2] = 291789320 at 0x55f5adce52a8
oldMemory[3] = -542290226 at 0x55f5adce52ac
oldMemory[4] = 4 at 0x55f5adce52b0
oldMemory[5] = 5 at 0x55f5adce52b4
oldMemory[6] = 6 at 0x55f5adce52b8
oldMemory[7] = 7 at 0x55f5adce52bc
oldMemory[8] = 8 at 0x55f5adce52c0
*/

  return 0;
}

/**
 * resize_array -- resize a dynamically-allocated block of memory
 *
 * Why must you assign the result of realloc back to your pointer?
 * ---------------------------------------------------------------
 *   a = realloc(a, new_size);
 *
 *   • Potential relocation
 *     Depending on heap layout, the block pointed to by `a` may not be
 *     extendable in place (e.g. if another block is immediately after it).
 *     In that case, `realloc` will allocate a fresh block elsewhere,
 *     copy the old data to the new block, free the old block, and return
 *     the new address.
 *
 *   • If you don’t capture the return value:
 *     realloc(a, new_size);
 *     // you’re still holding the old pointer 'a'
 *
 *     – Success path: you have no reference to the new memory, so you
 *       leak the reallocated block.
 *     – Failure path: realloc returns NULL, and ‘a’ still points to
 *       the original memory (which has not been freed). You must
 *       detect this to avoid a crash or memory leak.
 *
 * What happens to the old location?
 * ---------------------------------
 *   – On success, if the block had to move, the old block is freed
 *     automatically by realloc().
 *   – On failure (NULL return), the original block remains allocated
 *     and untouched; you must handle the error to avoid losing the
 *     reference.
 *
 *   – The freed block’s contents are not zeroed—you may still “see” the old
 *     bit-patterns if you read from the old pointer, but doing so is
 *     undefined behavior and must be avoided.
 *    // check the scenario performed above
 *
 * Best practices
 * --------------
 *   • Always assign and check the result:
 *
 *       T *tmp = realloc(a, new_size * sizeof *a);
 *       if (tmp == NULL) {
 *           // handle OOM: 'a' is still valid and unchanged
 *       } else {
 *           a = tmp;
 *       }
 *
 *   • Do not “nullify” or zero out the old buffer after relocation —
 *     the old block has already been freed by realloc when it moves.
 *
 *   • To avoid data leaks on failure, use a temporary pointer.
 *
 *   • Beware integer overflow when computing `new_size * sizeof *a`.
 *
 *   • If you really need to zero out newly allocated extend of memory:
 *
 *       size_t old_size = // previous number of elements 
 *       size_t new_count = // desired number of elements 
 *       T *tmp = realloc(a, new_count * sizeof *a);
 *       if (tmp) {
 *           // zero only the extra bytes
 *           memset((char*)tmp + old_size * sizeof *a,
 *                  0,
 *                  (new_count - old_size) * sizeof *a);
 *           a = tmp;
 *       }
 *
 * Summary
 * -------
 *   – Always capture realloc’s return value.
 *   – Use a temporary pointer to detect allocation failure safely.
 *   – The old block is automatically freed on success; on failure, it remains valid.
 */
