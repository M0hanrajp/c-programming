/* Usually when you buy something, you're asked whether your credit card number, 
 * phone number or answer to your most secret question is still correct. However, 
 * since someone could look over your shoulder, you don't want that shown on your 
 * screen. Instead, we mask it.
Your task is to write a function maskify, which changes all but the last four characters into '#'.

Examples (input --> output):
"4556364607935616" --> "############5616"
     "64607935616" -->      "#######5616"
               "1" -->                "1"
                "" -->                 ""

// "What was the name of your first pet?"
"Skippy" --> "##ippy"
"Nananananananananananananananana Batman!" --> "####################################man!" */
#include <string.h>
char *maskify (char *masked, const char *string) {
  if(strlen(string) < 5) {return strcpy(masked, string);}
  strcpy(masked, string);
  for(unsigned i = 0; i < strlen(string) - 4; i++)
    masked[i] = '#';
	return masked; // return it
}
