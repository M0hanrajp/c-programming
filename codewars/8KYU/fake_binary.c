/* Given a string of digits, you should replace any digit below 5 
 * with '0' and any digit 5 and above with '1'. Return the resulting string.
Note: input will never be an empty string */
void fakeBin(const char *digits, char *binary) {
  // Please place result in the memory pointed to by
  // the binary parameter. binary has enough memory to
  // accommodate the answer as well as the null-terminating
  // character.
  int i = 0;
  while(digits[i] != '\0'){binary[i] = ((digits[i] - '0') >= 5) ? '1' : '0';i++;}
 	binary[i] = '\0';
}
