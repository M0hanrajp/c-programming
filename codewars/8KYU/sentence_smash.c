/* Sentence Smash
Write a function that takes an array of words and smashes them together into a sentence and returns the sentence. You can ignore any need to sanitize words or add punctuation, but you should add spaces between each word. Be careful, there shouldn't be a space at the beginning or the end of the sentence!

Example
['hello', 'world', 'this', 'is', 'great']  =>  'hello world this is great'
words = ['hello', 'world', 'this', 'is', 'great']
smash(words) # returns "hello world this is great"
Assumptions
You can assume that you are only given words.
You cannot assume the size of the array.
You can assume that you do get an array.
What We're Testing
We're testing basic loops and string manipulation. This is for beginners who are just learning loops and string manipulation.

Disclaimer
This is for beginners so we want to test basic loops and string manipulation. Advanced users should easily be able to do this in one line. */
#include <stdlib.h>
#include <string.h>
char *smash (const char *const words[/* count */], size_t count) {
  char *sentence = (char *)calloc(10 * count, sizeof(char));
  if(count == 0){return sentence;}
	strcpy(sentence, words[0]);
  for(size_t i = 1; i < count; i++) {
    strcat(sentence, " ");
    strcat(sentence, words[i]);
  }
  return sentence;
}
