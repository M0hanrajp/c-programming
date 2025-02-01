#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void display(char **input, unsigned size) { // this can be written as *input[]
  printf("Input is local to the function display hence it's address will be different\naddress of input :: %p\n", &input);
  for(unsigned i = 0; i < size; i++) {
      printf("<< String[%u]  >> :: %8s at address :: %p stored in %p\n", i, input[i], input[i], input + i);
      for(unsigned j = 0; input[i][j] != '\0'; j++) {
          printf("Element[%u] :: %c at address :: %p stored in %p\n", j, input[i][j], (*(input + i) + j), input + i);
      }
  }
  // for(unsigned i = 0; input[i] != NULL; i++) 
  // the above statement works only if input[i] is NULL.
  // so char *str[] = {"Welcome", "to", "jumanji", NULL}; will work but if not declared then it will cause a segfault
}

int main(void) {
  char *str[] = {"Welcome", "to", "jumanji"};
  // char mod[] =  {"The jungle"};
  // str[2] = mod;str[2][0] = 't';
  printf("total memory occupied by elements of str :: %lu\nprints the size of the array of pointers, not the total memory occupied by the strings.\n",
          sizeof(str));
  // str++;
  // Phase 1
  // Printing out str elements, address.
  // Printing out individual char elements from char * elements.

   // str[0][1] = 'x'; // Attempting to modify array of pointers.
  /* This leads to segmentation fault as we are attempting to modify readonly memory.
   * Means, str has address char ** type which holds pointer to a char (char *).
   * This is a pointer to a char, and the string is stored in read only memory
   * More info in scenarios.md */

  // Can we overcome this ?? 
  /* We can fix that by declaring an char arr[] = {<some string>}, when we declare it this
   * way even though the string literal is stored in readonly memory, during array creation
   * the string is copied from readonly memory to the stack and char array works as constant
   * pointer to a char/string, hence we are able to modify the contents.
   * for example in this program comment out char mod[] & char str[2] = mod;str[2][0] = 't' 
   * statements and exectue the program to see the difference. 
   * Capital T from mod will be changed to t.
   * */

  // Calling display funciton to display array of pointers
  display(str, 3);
  // #define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
  // the size can also be calculated using a macro
 
  // uncomment the below code if string needs printing from the main function
/*   for(unsigned i = 0; i < 3; i++) {
      printf("<< String[%u]  >> :: %8s at address :: %p stored in %p\n", i, str[i], str[i], str + i);
      for(unsigned j = 0; str[i][j] != '\0'; j++) {
          printf("Element[%u] :: %c at address :: %p stored in %p\n", j, str[i][j], &str[i][j], str + i);
      }
  } */
  return 0;
}
