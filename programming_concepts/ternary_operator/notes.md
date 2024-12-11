### Can we use loops in ternery operator conditions ?

```bash
My initial code:
return sum = ( a > b ) ? (while(b <= a){n += b; b++}) : while(a <= b){n += a; a++};
```
- Solution: Expressions are not allowed in ternery operator.
- The **ternary operator** is meant for compact conditional assignments or expressions, not for including blocks of code like loops.
- For example, the following works because it involves simple expressions:
  ```c
  return (a > b) ? (a - b) : (b - a);
  ```
  But attempting to include `while` statements would result in a syntax error.
```c
# The following would also work
return (a > b) ? calculateSum(b, a) : calculateSum(a, b);
```
