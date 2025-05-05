## C preprocessor

- Converts source code to expanded source code, from `.c` to `.i` file.
```c
#define PI 3.14
   ^-------------------- Preprocessor directive
        ^--------------- macro template
            ^----------- macro expansion
```
- replace the occurrance of `PI` in a program with 3.14.

### Rules for defining preprocessor directive
- There should be no blankspace between macro template and it's argument.
- paranthesis for the macro expansion is necessary.
- define preprocessor directives as multiline using `\`.
