/* You'll be given a list of two strings, and each will contain exactly 
 * one colon (":") in the middle (but not at beginning or end). The length 
 * of the strings, before and after the colon, are random.
Your job is to return a list of two strings (in the same order as the original 
list), but with the characters after each colon swapped.
Examples
["abc:123", "cde:456"]  -->  ["abc:456", "cde:123"]
["a:12345", "777:xyz"]  -->  ["a:xyz", "777:12345"] */
#include <stdlib.h>
#include <string.h>
void tail_swap (char *out[2], const char *const in[2]) {
  size_t io = 0, ioc = 0, ii = 0, iic = 0;
  // allocate memory for out & get the ':' index
  for(int i = 0; i < 2; i++) {
	  out[i] = (char *)calloc(50, sizeof(char));
    for(int j = 0; in[i][j] != '\0'; j++) {
      if(i == 0 && in[i][j] == ':'){io = j;ioc = j + 1;}
      if(i == 1 && in[i][j] == ':'){ii = j;iic = j + 1;}     
    }
  }
  strcpy(out[0], in[0]);
  strcpy(out[1], in[1]);
  // copy 2nd string contents to 1st
  for(int j = ii + 1; in[1][j] != '\0'; j++) {
    out[0][ioc++] = in[1][j];
  }
  out[0][ioc] = '\0';
  // copy 1st string contents to 2nd
  for(int k = io + 1; in[0][k] != '\0'; k++) {
    out[1][iic++] = in[0][k];
  }
  out[1][iic] = '\0'; 
}
