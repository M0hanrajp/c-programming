#include <ctype.h>
#include <stdio.h>
#include <string.h>

void longestSubstringWithoutRepeatingChars(char *string) {
    int count = 0, max = 0;
    for(int i = 0; string[i] != '\0'; i++) {
        for(int j = i + 1; string[j] != '\0'; j++) {
            if(tolower(string[i]) != tolower(string[j])) {
                count++;
            } else {
                if(count > max) {
                    max = count;
                    i = j - 1;
                }
                count = 0;
                break;
            }
        }
    }
    printf("output :: %d\n", count);
}

int main(void) {
    char *str = "Cisco is my dream company";
    longestSubstringWithoutRepeatingChars(str);
    return 0;
}
