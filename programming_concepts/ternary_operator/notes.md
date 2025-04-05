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

### return statement not allowed 

- Here the function takes in a char and checks the value.
- the function returns the desired value based on the character.
```bash
hex_char == '9' ? return 9 : return 0;
```
>Ternery only allows expressions and not return statements.
- We could write the above statement as follows:
```bash
return hex_char == '9' ? 9 : 0;
```

### Remeber to match the syntax:

The syntax in your conditional expression looks fine from a purely structural perspective, but there might be issues related to **readability**, **operator precedence**, and **bracket omission**. Here's a step-by-step breakdown of potential problems:

### 1. **Ambiguity Without Parentheses**
Without parentheses, it can be hard to determine the correct grouping of the conditions. The ternary operator (`?:`) has **right-to-left associativity**, so the expression may not behave as expected unless grouped explicitly. For example:
```c
a + b > c ? b + c > a ? c + a > b ? 1 : 0
```
This is equivalent to:
```c
a + b > c ? (b + c > a ? (c + a > b ? 1 : 0) : 0) : 0
```

If your intention is different, parentheses are **mandatory** to clarify the logic.

### 2. **Ternary Operator Misuse**
The ternary operator is nested here, making the logic difficult to follow. While it is valid in C, deeply nested ternary operations can be hard to debug and understand. For instance:
```c
a + b > c ? b + c > a ? c + a > b ? 1 : 0 : 0 : 0
```
It can be rewritten using `if` statements for clarity.

### 3. **Potential Logical Error**
The condition checks (`a + b > c`, `b + c > a`, `c + a > b`) resemble a triangle inequality test, where these conditions determine if three sides can form a triangle. If that’s your intent, the ternary operator should evaluate all conditions sequentially, or you should ensure the logic is sound. 

### 4. **Return Statement**
The word `return` is incomplete in your code snippet:
```c
eturn a + b > c ...
```
It should be `return` instead of `eturn`.

#### Suggested Fixes:
Here’s a cleaner version with proper parentheses and indentation:
```c
return (a + b > c) 
       ? ((b + c > a) 
          ? ((c + a > b) ? 1 : 0) 
          : 0) 
       : 0;
```

Or, better yet, use an `if` statement:
```c
if (a + b > c && b + c > a && c + a > b) {
    return 1;
} else {
    return 0;
}
```
### Using functions in ternery operator expression
Ternary operator syntax:
```bash
// syntax
condition ? expression_if_true : expression_if_false
```
- a function (which is having a valid return type) is allowed using in ternery operator.
- a function which is declared of type void (which does not return anything) is not allowed.
- expression must evaluate to a value.

### Using pointer variables in ternery operator condition
Ternery operator synatx:
```bash
// syntax
condition ? expression_if_true : expression_if_false
   ^>> what if a pointer is used here.
```
- if a pointer is used at a condition
    - a. is assigned to NULL, it is false.
    - b. is assigned to valid address which itself is a nonzero number, which is why the condition evaluates to true.
    - c. is not assigned NULL is just declared, then here ptr is initialized inside main,
        - it's storage class is automatic storage class it's value is indeterminate.
        - Hence the expression would lead to undefined behavior.
C spec: 23(draft) 6.7.9
![Image](https://github.com/user-attachments/assets/0dd29f56-8359-40da-90da-11ffd5afe5fe)
