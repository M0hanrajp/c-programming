### Program behaviors

- Scanf takes in tokens until "enter" key is used.
- If a space is encountered then it will print all the characters till that first space and rest all characters are included in input buffer.
Error 1:
```bash
basics_main.c: In function ‘main’:
basics_main.c:20:13: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
   20 |     scanf("%s", &userInput);
      |            ~^   ~~~~~~~~~~
      |             |   |
      |             |   char (*)[100]
      |             char *
```
- &userInput is the address of the array itself, which is a different type (char (*)[100]), not a char *.:w
- How to make scanf take multi word input: [Code snippet here]()
- when scanf with `%[^\n\s` is used then we need to make sure the input buffer is clear, meaning there should not be any characters left, following is a demonstartion:
```bash
# Full string entered (nromal scanf prints till first space character 
Enter a string:: Coding is tough
Coding
Coding
# Modified scanf that takes multi word string, (it prints here "is tough" from previous string as it was discarded previously by normal scanf
Enter a string::  is tough
 is tough
# need to check from process memory layout POV
```
- learn how scanf reads input and the difference in input buffer.
