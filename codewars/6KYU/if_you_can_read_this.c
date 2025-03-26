/* The idea for this kata came from 9gag today:
The lyrics to "Never gonna give you up" by Rick Astley encoded in the NATO phonetic alphabet

Task
You'll have to translate a string to Pilot's alphabet (NATO phonetic alphabet).

Input:
If, you can read?

Output:
India Foxtrot , Yankee Oscar Uniform Charlie Alfa November Romeo Echo Alfa Delta ?

Note:
There is a preloaded dictionary that you can use, named NATO. It uses uppercase keys, e.g. NATO['A'] is "Alfa". See comments in the initial code to see how to access it in your language.
The set of used punctuation is ,.!?.
Punctuation should be kept in your return string, but spaces should not.
Xray should not have a dash within.
Every word and punctuation mark should be seperated by a space ' '.
There should be no trailing whitespace */
#include <stdlib.h>
#include <string.h>
// NATO['A'] == "Alfa", etc
extern const char *const NATO[];

char *to_nato(const char *words) {
  const char *nato[] = {"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike","November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra","Tango","Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"};
  char *tn = (char *)calloc(5000, sizeof(char));
  strcpy(tn, words[0] < 90 ? nato[words[0] - 65] : nato[words[0] - 97]);
  strcat(tn, " ");
  for(size_t i = 1; words[i] != '\0'; i++) {
    switch(words[i]) {
        case 'a':
        case 'A': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;       
        case 'b':
        case 'B': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;              
        case 'c':
        case 'C': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;              
        case 'd':
        case 'D': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;              
        case 'e':
        case 'E': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;              
        case 'f':
        case 'F': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;              
        case 'g':
        case 'G': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;              
        case 'h':
        case 'H': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;              
        case 'i':
        case 'I': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;              
        case 'j':
        case 'J': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;              
        case 'k':
        case 'K': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;              
        case 'l':
        case 'L': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 'm':
        case 'M': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 'n':
        case 'N': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 'o':
        case 'O': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 'p':
        case 'P': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 'q':
        case 'Q': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 'r':
        case 'R': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 's':
        case 'S': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 't':
        case 'T': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 'u':
        case 'U': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 'v':
        case 'V': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 'w':
        case 'W': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 'x':
        case 'X': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 'y':
        case 'Y': strcat(tn, words[i] < 90 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case 'z':
        case 'Z': strcat(tn, words[i] < 91 ? nato[words[i] - 65] : nato[words[i] - 97]); strcat(tn, " "); break;
        case '!': strcat(tn, "! "); break;
        case ',': strcat(tn, ", "); break;
        case '?': strcat(tn, "? "); break;
        case '.': strcat(tn, ". "); break;
        default : break;
    }
  }
  tn[strlen(tn) - 1] = '\0';
  return tn; // return a heap-allocated string
}
