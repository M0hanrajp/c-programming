#include <stdio.h>

int main(void) {
    char word[] = "something";
    char *words = "Code Code Code";
    char copy[20];
    char *newString = NULL;

    // assigning to a new char array
    copy = word;
    
    // trying to assign directly of type word[]
    word = "computer";

    // trying to assign directly of type char *
    words = "Code";

    // Assigning to a new char pointer
    newString = words;
    return 0;
}
