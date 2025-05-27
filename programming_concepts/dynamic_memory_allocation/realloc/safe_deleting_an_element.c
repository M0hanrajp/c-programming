#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // increased the size of a from 1 to 3
    int *a = calloc(1, sizeof(int));
    a = realloc(a, 2 * sizeof(int));
    a = realloc(a, 3 * sizeof(int));

    // assign 1 2 3
    for (int i = 0; i < 3; i++) a[i] = i + 1;
    for (int i = 0; i < 3; i++) printf("a[%d] = %d at %p\n", i, a[i], a + i);

    // Deleting the element at a[1] -> the wrong way
    // Done to check program output, get the address of 2nd element a[1] and free it.
/*     int *fa = a + 1;
    free((fa));
    fa = NULL; */

    // Deleting the element at a[2] -> the right way
    // Suppose you have an array a[0..n-1], and you want to delete a[1]:
    memmove(a + 1, // where to copy ? destination: element-1’s slot, 
            a + 2, //  what to copy ? source: element-2’s slot to end of array 
            sizeof(int)); // total size of element from 2nd slot till end.
    /* before: a[0] = 1, a[1] = 2, a[2] = 3
     * after : a[0] = 1, a[1] = 3, a[2] = 3
     * explained in better detail below the page */
    int new_size = 3 - 1;
    int *a_temp = realloc(a, new_size * sizeof(int));
    if(a_temp) a = a_temp;

    // try to print the whole array
    for (int i = 0; i < new_size; i++) printf("a_new[%d] = %d at %p\n", i, a[i], a + i);
/*output,

    During compiling,
    deleting_an_element.c: In function ‘main’:
    deleting_an_element.c:16:5: warning: ‘free’ called on pointer ‘a’ with nonzero offset 4 [-Wfree-nonheap-object]
       16 |     free((fa));
          |     ^~~~~~~~~~
    deleting_an_element.c:8:9: note: returned from ‘realloc’
        8 |     a = realloc(a, 3 * sizeof(int));
          |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~

    The error means,
    -  calling free() on a pointer (fa) that doesn’t point to the start of the block you got from realloc. 
    - In C the rule is You may only pass to free() exactly the pointer you got back from malloc/calloc/realloc.

    Why ?
      - free() doesn’t know how to walk backwards to the real start of the allocation
      - the following is what allocator does
      [ header | 3×int data ]
           ^
           └─ this is what you get back in `a`
      - the runtime expects that fa points at the very start of its alloc’d block—so it can look “just before” 
        that address and read its header. But fa is four bytes (one int) past the true start, so the allocator 
        sees garbage instead of its header. It can’t “walk backwards” from fa to find the real header, because 
        it has no way to know how far back to go.

    Output:
    $ ./a.out
    a[0] = 1 at 0x557b2ce2e2a0
    a[1] = 2 at 0x557b2ce2e2a4
    a[2] = 3 at 0x557b2ce2e2a8
    free(): invalid pointer
    Aborted (core dumped)

    How to fix it ?

    Memory layout (each cell holds one int):

       Index:    0      1      2      3      4
       ——+—————————————————————————————————————
        a: |  A0  |  A1  |  A2  |  A3  |  A4  |
           +------+------+------+------+------+

    We call: memmove(a+1, a+2, 3*sizeof(int))

       src region: starts at index 2 (A2) for length 3 ints → covers [2,3,4]
       dst region: starts at index 1          → covers [1,2,3]

                             ↓
                           Before:                            After memmove:

      Index:   0      1      2      3      4            0      1      2      3      4
          +——————————————————————————————————+      +————————————————————————————————--+
      a:  |  A0  |  A1  |  A2  |  A3  |  A4  |   a: |  A0  |  A2  |  A3  |  A4  |  A4  |
          +------+------+------+------+------+      +------+------+------+------+------+
                                     ↑                        ↑      ↑      ↑
                                  source                    new[1]  new[2]  new[3]

    The original `a[4]` remains untouched, but now you consider the array length logically 
    reduced by one. You’d then do `realloc(a, 4*sizeof *a)` and `free(a)` later.
    This shifting leaves you with the sequence  

    General formula:

    // Delete a[x] from an array a[0..n-1]:
    // Shift elements a[x+1]..a[n-1] into positions a[x]..a[n-2]:
    memmove(
        a + x,            // destination: start at slot x
        a + x + 1,        // source: start at slot x+1
        (n - x - 1)       // number of elements to move
          * sizeof *a     // size of each element
    );

    if a[2] has to be removed
    size_t x = 2;                       // index to remove
    memmove(a + x, a + x + 1, (5 - 2 - 1) * sizeof *a);
    //         └───┘ └────┘    └───┘
    //         dst   src       count = 2 elements
    //   moves a[3],a[4] → into a[2],a[3]

    a = realloc(a, (5 - 1) * sizeof *a); = [ a[0], a[1], a[3], a[4] ]

*/



    return 0;
}
