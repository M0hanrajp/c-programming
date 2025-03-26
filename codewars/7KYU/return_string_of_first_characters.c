/* In this exercise, a string is passed to a method and a new string has to be returned with the first character of each word in the string.
For example:
"This Is A Test" ==> "TIAT"
Strings will only contain letters and spaces, with exactly 1 space between words, and no leading/trailing spaces. */
char *make_acronym (const char *words, char *letters) {
  unsigned index = 0;
  letters[index++] = words[0];
  for(int i = 1; words[i] != '\0'; i++)
    if(words[i] == ' ') {letters[index++] = words[i + 1];continue;}
  letters[index] = '\0';
	return letters; // return it
}
