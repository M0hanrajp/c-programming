### Scenarios of strings 

#### 1D array, expanded form and string literal.

- In the below scenario, sentence is a constant pointer to a char array.
- the funciton display string takes input pointer to a char as an argument.
- base address of sentence is sent, here both `pointer` and `string` are mutable.
```bash
void displayString(char *input) {
    printf("Address &input %p & value *input %c, value of input (which holds char array's address) %p\n", &input, *input, input);
    for(int i = 0; *input != '\0' ; i++) {
        *input = 'X';
        printf("element :: %c & address of element :: %2d is %p\n", *input, i, input);
        input++;
    }
    printf("\n");
}

int main() {
    char sentence[] = "I use arch linux BTW";
    printf("Address of sentence in main %p\n", sentence);
    displayString(sentence);
    return 0;
}
```
- the char array address itself is the first element's address :
- Observe the first char is 'I' as per sentence[0]. base address of sentence is present inside function.
![Image](https://github.com/user-attachments/assets/57636f13-8148-443e-a627-d8645d8af462)

- Note:
   - declare a pointer variable of type char that holds sentence's address.
   - Then pointer is mutable, string can be modified.
- [How size is determined for declaration of type `word[] = "string"` ?](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/notes.md#how-size-is-determined-for-declaration-of-type-word--string-)
```bash
Address of sentence in main 0x7ffe9d7d58e0
String in main :: I use arch linux BTW
Address &input 0x7ffe9d7d58a8 & value *input I, value of input # (which holds char array's address) 0x7ffe9d7d58e0
// all characters are modified because of *input = 'X';
element :: X & address of element ::  0 is 0x7ffe9d7d58e0
element :: X & address of element ::  1 is 0x7ffe9d7d58e1
element :: X & address of element ::  2 is 0x7ffe9d7d58e2
element :: X & address of element ::  3 is 0x7ffe9d7d58e3
element :: X & address of element ::  4 is 0x7ffe9d7d58e4
element :: X & address of element ::  5 is 0x7ffe9d7d58e5
element :: X & address of element ::  6 is 0x7ffe9d7d58e6
element :: X & address of element ::  7 is 0x7ffe9d7d58e7
element :: X & address of element ::  8 is 0x7ffe9d7d58e8
element :: X & address of element ::  9 is 0x7ffe9d7d58e9
element :: X & address of element :: 10 is 0x7ffe9d7d58ea
element :: X & address of element :: 11 is 0x7ffe9d7d58eb
element :: X & address of element :: 12 is 0x7ffe9d7d58ec
element :: X & address of element :: 13 is 0x7ffe9d7d58ed
element :: X & address of element :: 14 is 0x7ffe9d7d58ee
element :: X & address of element :: 15 is 0x7ffe9d7d58ef
element :: X & address of element :: 16 is 0x7ffe9d7d58f0
element :: X & address of element :: 17 is 0x7ffe9d7d58f1
element :: X & address of element :: 18 is 0x7ffe9d7d58f2
element :: X & address of element :: 19 is 0x7ffe9d7d58f3
```
> learn more on 1D arrays in detailed manner [here](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/two_dimensional_strings/output.md)
#### 1D array of pointers calculations.[here](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/two_dimensional_strings/output.md#passing-stro-to-functions)
