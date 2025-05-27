/* (b) Can an array of pointers to strings be used to collect strings from
the keyboard? If yes, how? If not, why not? */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main(void) {
  char *pa[SIZE];
  char *pb[SIZE] = {"A", "B", "C", "D", "E"};
/*Trial 1 
  Below code works when SIZE == 1
  char a[SIZE];
  printf("Enter char : \n");
  scanf("%c", a);
  pa[0] = a;
  printf("From array of pointers : %s\n", *pa); */
  
  // Trial 2
  for(int i = 0; i < SIZE; i++){
  pa[i] = (char *)calloc(16, sizeof(char));
  printf("Enter string at element %d: ", i);
  scanf("%s", pa[i]);
  }

  // pa[4][0] = 'A'; you can mutate the elements of pa as the memory is heap allocated.
  // pb[4][0] = 'A'; this leads to seg fault as we are attempting to change read only memory.
  printf("Print pa, dynamically allocated char * from calloc\n");
  for(int i = 0; i < SIZE; i++) {
    printf("Value %s :: at char * address :: %p & element %d :: at address %p\n", pa[i], pa[i], i, pa + i);
  }
  printf("\n");
  printf("Print pb, directly declared from main function with initialized elements\n");
  for(int i = 0; i < SIZE; i++) {
    printf("Value %s :: at char * address :: %p & element %d :: at address %p\n", pb[i], pb[i], i, pb + i);
  }
  return 0;
}
/*
// Output of Trial 2
```bash
Enter string at element 0: A
Enter string at element 1: B
Enter string at element 2: C
Enter string at element 3: D
Enter string at element 4: E
Print pa, dynamically allocated char * from calloc
Value A :: at char * address :: 0x56493aec72a0 & element 0 :: at address 0x7fff2bfdfd60
Value B :: at char * address :: 0x56493aec7ae0 & element 1 :: at address 0x7fff2bfdfd68
Value C :: at char * address :: 0x56493aec7b00 & element 2 :: at address 0x7fff2bfdfd70
Value D :: at char * address :: 0x56493aec7b20 & element 3 :: at address 0x7fff2bfdfd78
Value E :: at char * address :: 0x56493aec7b40 & element 4 :: at address 0x7fff2bfdfd80

Print pb, directly declared from main function with initialized elements
Value A :: at char * address :: 0x564923d96008 & element 0 :: at address 0x7fff2bfdfd90
Value B :: at char * address :: 0x564923d9600a & element 1 :: at address 0x7fff2bfdfd98
Value C :: at char * address :: 0x564923d9600c & element 2 :: at address 0x7fff2bfdfda0
Value D :: at char * address :: 0x564923d9600e & element 3 :: at address 0x7fff2bfdfda8
Value E :: at char * address :: 0x564923d96010 & element 4 :: at address 0x7fff2bfdfdb0
```
- Learnings from the problems
- In pa The actual strings (pa[i] values) are in the heap, and their addresses are non-contiguous due to calloc() allocations.
- In pb The string literals themselves are stored in the read-only data segment (.rodata), and their addresses are sequential,
  reflecting how the compiler places them in memory.
*/
