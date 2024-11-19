### Strings

Mistakes:
- In order to print a string (manually by iterating through each character)
    - Use '\0' character as the exit expression.
    - when iterating with i as an integer from 0 till `\0` make sure expression checks the character not the integer.
        - i.e. check `variable[iteration n] != '\0'` not `iteration n' != '\0'` inside the loop.
        - in ascii `\0` (The null terminator) character value is 0.

**Key Differences**

| **Aspect**             | **`input[i] != '\0'`**                           | **`i != '\0'`**                     |
|-------------------------|--------------------------------------------------|--------------------------------------|
| **Context**            | Character array/string traversal                 | Numeric comparison                  |
| **Checks**             | If the current character is not the null terminator (`'\0'`) | If the integer `i` is not zero       |
| **Use Case**           | Iterating or processing strings                  | General numeric conditions           |
| **Outcome**            | Relates to the data in `input`                   | Relates to the value of `i`          |

### Questions

- char words[] = {'A', 'B', 'C', 'D', '\0'};, when printed by calling the function mentioned in basics_main.c prints ABCD.
    - when the same words[] is used without '\0' it prints ABCD, what is the behavior here ? does compiler add the '\0' terminator ?
