#include <stdio.h>
#include <stddef.h>

// using array of pointers technique
// TODO: How can this work ?
void displayTwoDimensionalString(size_t rows, size_t cols, char (*input)[cols]) {
    // the function argument can be simply written as char input[size][size]
    // because this also decays to char (*input)[size]
    // the function argument is decalred in this way because in the main function the array decays into pointer to first row.
    // [reason](https://github.com/M0hanrajp/c-programming/blob/9dc137f42ddd125c1378418e74411ec3a668c2e5/misc_notes/oneDimensional_twoDimensional_array_decay.md?plain=1#L93)
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; input[i][j] != '\0'; j++) {
            printf("Row[%lu]Col[%lu] :: %c & address :: %p\n", i, j, input[i][j], &input[i][j]);
        }
    }
    // Note: use 1 for loop and use subscript i & %s to print out the whole string instead
    // of accessing character by character.
    // Note if j < cols is used, then j will move from 0 till cols - 1, which might end up printing the null character
}

void displayOneDimensionalString(size_t size, const char* string) {
    for(int i = 0; string[i] != '\0'; i++) {
        printf("Element[%2d] = %c & address :: %p\n",i, string[i], &string[i]);
    }
    printf("Using print function :: %s\n", string);
}

int main() {
    // One dimensional array with basics
    char strO[21] = "I use Arch linux BTW";
    printf("sizeof(strO) :: %lu\n", sizeof(strO));
    printf("address of strO (&strO):: %p (pointer to whole array) i.e. of type char (*)[20] \nsizeof address (&StrO) :: %lu\n", &strO, sizeof(&strO));
    printf("str0 decays to a pointer to the first element with address strO:: %p && value *strO:: %c\n", strO, *strO);
    // call the function ::
    displayOneDimensionalString(20, strO);
    // Two dimensional array with basics
    char strT[2][4] = {"Bit", "Git"};
    printf("================\nsizeof 2D char array :: %lu\n", sizeof(strT));
    printf("address of 2D char array :: %p without & operator\n", strT);
    printf("address of variable &strT :: %p (pointer to whole array) char (*)[2][4] \nsize of &StrO :: %lu\n", &strT, sizeof(&strT));
    // call the function ::
    printf("Value :: %s address of string 1 :: %p\n", strT[0], strT[0]); // this can be written as StrT as it is decaying to type char (*)[4]
    printf("Value :: %s address of string 2 :: %p\n", strT[1], strT[1]);
    displayTwoDimensionalString(2, 4, strT);
    printf("\n");

    return 0;
}
