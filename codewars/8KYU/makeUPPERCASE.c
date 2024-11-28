/* Write a function which converts the input string to uppercase.
  doTest("abc", "ABC");
  doTest("ABC", "ABC");
  doTest("abcABC1234@@@@###", "ABCABC1234@@@@###");
  doTest("", ""); */
char *makeUpperCase (char *string)
{
  for(int index = 0; string[index] != '\0'; index++) {
    if(string[index] >= 'a' && string[index] <= 'z') {
      string[index] -= 32;
    }
  }
  // write to string and return it
  return string;
}

