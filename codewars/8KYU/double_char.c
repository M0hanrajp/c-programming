/* Given a string, you have to return a string in which each character (case-sensitive) is repeated once.
Examples (Input -> Output):
* "String"      -> "SSttrriinngg"
* "Hello World" -> "HHeelllloo  WWoorrlldd"
* "1234!_ "     -> "11223344!!__  " */
char *double_char (const char *string, char *doubled) {
  if(*string == 0){*doubled = '\0';}
  char *start = doubled;
  while(*string){*doubled = *string; doubled++; *doubled = *string; doubled++; string++;}
  *doubled = '\0';
  return start; // return it
}
