#include <stdio.h>
#include <stddef.h>

void displayTwoDimensionalString(size_t size, char (*input)[size]) {
    // 2 because there are only two rows of strings in main function
    for(size_t i = 0; i < 2; i++) {
        for(size_t j = 0; input[i][j] != '\0'; j++) {
            printf("Row[%lu] :: %c & address :: %p\n", i, input[i][j], &input[i][j]);
        }
    }
    // Note: use 1 for loop and use subscript i & %s to print out the whole string instead
    // of accessing character by character.
}

void displayTwo_DimensionalString(char **input) {
    // 2 because there are only two rows of strings in main function
    for(size_t i = 0; i < 2; i++) {
        for(size_t j = 0; input[i][j] != '\0'; j++) {
            printf("Row[%lu] :: %c & address :: %p\n", i, input[i][j], &input[i][j]);
        }
    }
    // Note: use 1 for loop and use subscript i & %s to print out the whole string instead
    // of accessing character by character.
}

void displayOneDimensionalString(size_t size, const char* string) {
    for(int i = 0; string[i] != '\0'; i++) {
        printf("Element[%2d] = %c & address :: %p\n",i, string[i], &string[i]);
    }
    printf("Using print function :: %s\n", string);
}

int main() {
    // One dimensional array with basics
    char strO[20] = "I use Arch linux BTW";
    printf("size of 1D strO :: %lu\n", sizeof(strO));
    printf("address of variable strO :: %p (pointer to whole array) \nsize of &StrO :: %lu\n", &strO, sizeof(&strO));
    printf("str0 decays to a pointer to the first element :: %c && address :: %p (without & operator) \n", *strO, strO);
    // call the function :: 
    displayOneDimensionalString(20, strO);
    // Two dimensional array with basics
    char strT[2][4] = {"one", "two"};
    printf("================\nsizeof 2D char array :: %lu\n", sizeof(strT));
    printf("address of 2D char array :: %p without & operator\n", strT);
    printf("address of variable &strT :: %p (pointer to whole array) \nsize of &StrO :: %lu\n", &strT, sizeof(&strT));
    // call the function ::
    printf("Value :: %s address of string 1 :: %p\n", strT[0], strT[0]);
    printf("Value :: %s address of string 2 :: %p\n", strT[1], strT[1]);
    displayTwoDimensionalString(4, strT);

    char *strN[5] = {"Hi", "Hello"};
    displayTwo_DimensionalString(strN);
    return 0;
}
