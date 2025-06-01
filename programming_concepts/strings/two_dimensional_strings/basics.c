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
    
    /* Here's how we can print "Git" using pointer arithmetic.
     * char (*input)[cols], input is a pointer to whole 1D array, currently it will point to the first 1D array.
     * Git lies in row 1, so we can use the following way to access the 1D char array "Git"
     */
    printf("Using pointer arithmetic to print 2nd Row char array::\n");
    char (*p)[cols] = input;
    p += 1; // now p points to 2nd Row.
    for(int i = 0; (*p)[i] != '\0'; i++) {
        printf("char[%d] = %c\n", i, *(*p + i)); // dereferencing once we get base address of char array.
    }
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

/* Output
    $ ./a.out
    sizeof(strO) :: 21
    address of strO (&strO):: 0x7ffcd8d8df40 (pointer to whole array) i.e. of type char (*)[20]
    sizeof address (&StrO) :: 8
    str0 decays to a pointer to the first element with address strO:: 0x7ffcd8d8df40 && value *strO:: I
    Element[ 0] = I & address :: 0x7ffcd8d8df40
    Element[ 1] =   & address :: 0x7ffcd8d8df41
    Element[ 2] = u & address :: 0x7ffcd8d8df42
    Element[ 3] = s & address :: 0x7ffcd8d8df43
    Element[ 4] = e & address :: 0x7ffcd8d8df44
    Element[ 5] =   & address :: 0x7ffcd8d8df45
    Element[ 6] = A & address :: 0x7ffcd8d8df46
    Element[ 7] = r & address :: 0x7ffcd8d8df47
    Element[ 8] = c & address :: 0x7ffcd8d8df48
    Element[ 9] = h & address :: 0x7ffcd8d8df49
    Element[10] =   & address :: 0x7ffcd8d8df4a
    Element[11] = l & address :: 0x7ffcd8d8df4b
    Element[12] = i & address :: 0x7ffcd8d8df4c
    Element[13] = n & address :: 0x7ffcd8d8df4d
    Element[14] = u & address :: 0x7ffcd8d8df4e
    Element[15] = x & address :: 0x7ffcd8d8df4f
    Element[16] =   & address :: 0x7ffcd8d8df50
    Element[17] = B & address :: 0x7ffcd8d8df51
    Element[18] = T & address :: 0x7ffcd8d8df52
    Element[19] = W & address :: 0x7ffcd8d8df53
    Using print function :: I use Arch linux BTW
    ================
    sizeof 2D char array :: 8
    address of 2D char array :: 0x7ffcd8d8df38 without & operator
    address of variable &strT :: 0x7ffcd8d8df38 (pointer to whole array) char (*)[2][4]
    size of &StrO :: 8
    Value :: Bit address of string 1 :: 0x7ffcd8d8df38
    Value :: Git address of string 2 :: 0x7ffcd8d8df3c
    Row[0]Col[0] :: B & address :: 0x7ffcd8d8df38
    Row[0]Col[1] :: i & address :: 0x7ffcd8d8df39
    Row[0]Col[2] :: t & address :: 0x7ffcd8d8df3a
    Row[1]Col[0] :: G & address :: 0x7ffcd8d8df3c
    Row[1]Col[1] :: i & address :: 0x7ffcd8d8df3d
    Row[1]Col[2] :: t & address :: 0x7ffcd8d8df3e
    Using pointer arithmetic to print 2nd Row char array::
    char[0] = G
    char[1] = i
    char[2] = t

*/
