// C program to calculate the vowels in a program, code wars, https://www.codewars.com/users/jayeshcp
#include <stddef.h>

size_t get_count(const char *s) {
    int count = 0;
    for (int index = 0; s[index] != '\0'; index++) {
        switch (s[index]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                count++;   // Increment for each vowel
                break;     // Stop here to avoid fall-through
            default:
                break;     // Default case; do nothing
        }
    }
    return count;
}
// Test(Sample_Test, should_return_the_vowel_count)
// {
//     cr_assert_eq(get_count("abracadabra"), 5);
//     cr_assert_eq(get_count(""), 0);
// }
