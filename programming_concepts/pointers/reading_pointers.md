## Examples

### 1. `char (*(*x())[5])();`
```c
char (*(*x())[5])();
```

* The `x()` you see here is **not** actually “calling” a function at runtime—it’s part of the *declarator* syntax that tells the compiler “`x` is a function taking no arguments…”.
* In that declarator, you never sprinkle semicolons around the inner pieces—you only put **one** semicolon at the very end to terminate the entire declaration:

  ```c
  char (*(*x())[5])();   // ← only one semicolon, after the whole thing
  ```

---

### In ordinary **code** (function calls)

```c
char (*(*fp())[5])();  // suppose this is declared somewhere…

int main(void) {
    // Here, fp() _really is_ a call to a function.
    char (*(*p)[5])() = fp();  
    //                              ^ semicolon ends the statement

    // And if you call the function that p points to:
    char c = (*p[0])();       
    //                      ^ semicolon ends this statement
}
```

* **Every** expression or statement in C (including a function call like `fp();` or `someFunction(arg);`) must end in a semicolon.
* But within a declaration’s grammar, the `()` after an identifier means “this is a function,” **not** “do it now,” so you don’t semicolon-terminate those inner parentheses.

---

### TL;DR

* **Declaration context**: `x()` inside `char (*(*x())[5])();` is part of the type, so no inner semicolons—just one semicolon at the end.
* **Statement context**: when you *actually* call a function (e.g. `x();` in `main`), that’s a statement, and it **does** need its own semicolon.

### 2. `int (*(*foo)(const int *))[3];`
```c
int (*(*foo)(const int *))[3];
```

1. **Find the identifier**

   * You see `foo`.

2. **Look immediately to its right**

   * You see nothing until you hit the first “outer” `)`, but just before that, you see `(const int *)`.
   * That tells you `foo` is something that takes a `const int *` as an argument.

3. **Look immediately to its left**

   * You see a `*` inside the parentheses `(*foo)`—so `foo` is a *pointer* to something.

4. **So far you have**

   > `foo` is a pointer to a function taking `(const int *)`.

5. **Now—what does that function return?**

   * After the closing `)` of the argument list, you hit another pair of parentheses:

     ```c
     (*   /* foo dereferenced as a function */ (const int *))
     ```

     and immediately after that closing `)` you see `[3]`.
   * That means *the result of calling* `(*foo)(const int *)` is something subscriptable with `[3]`—i.e. an array of 3 somethings.

6. **What is the base type of that array?**

   * Finally, to the very left of everything you see `int`.
   * So the array is of `int`.

7. **Putting it all together**

   * **`(*foo)(const int *)`**
     • → “call the function pointed to by `foo`, passing a `const int *`, producing …”
   * **`…)[3]`**
     • → “… an array of 3 …”
   * **`int`**
     • → “… ints.”
   * And since you used `[3]` on the result, you actually have a *pointer* to that array (the outermost `*` just outside the `( … )[3]`).

---

### In plain English

> **`foo` is a pointer to a function that takes a `const int *` argument and returns a pointer to an array of three `int`s.**

---

### Why the `[3]` binds to the function’s return

* **Parentheses rule**: In C declarations, `()` for function calls and `[]` for array subscripting bind more tightly than the outer `*` that you see around the whole thing.
* Here the grouping is effectively:

  ```c
  int (    * ( * foo )(const int *)   )[3];
    ^            ^               ^
    |            |               `─ The `[3]` applies to the result of the call
    |            `─ foo is a pointer
    `─ base type
  ```
* Because `[3]` comes *after* the `)` that closes the function’s parameter list, it modifies the function’s return type, not `foo` itself.

---

## Warnings:

### warning: initialization of ‘const int **’ from incompatible pointer type ‘int **’ [-Wincompatible-pointer-types] 

This warning occur when you try to assign `int **` to a `const int **

When you write:

```c
int   *t;        // t has type “pointer to int”
const int **v;   // v has type “pointer to pointer to const int”
v = &t;          // error: incompatible pointer type
```

the compiler is preventing a situation where you could end up doing this:

```c
static const int ci = 42;
*v = &ci;        // (if it were allowed) store &ci into t
*t = 99;         // later, use t (an int*) to modify ci!
```

Here’s the breakdown:

1. **`v = &t;`**
   You trick the compiler into letting `v` point at `t`.
2. **`*v = &ci;`**
   Since `v` is a `const int **`, it’s legal to store the address of a `const int` into `*v`.  But `*v` is really `t`!  So now `t` points at `ci`.
3. **`*t = 99;`**
   You treat `t` as an `int*` and write to it—modifying `ci`, which was supposed to be read-only.  That’s undefined behavior.

By refusing to convert an `int **` into a `const int **`, the compiler stops you from “sneaking” (i.e. implicitly inserting) a `const int *` into a plain `int *`.  In other words, it prevents you from accidentally using a non‐const pointer to modify something that another pointer considers const.

---

### The rule in simple terms

* You **can** do:

  ```c
  int *    → const int *      // add const “down” one level
  ```
* You **cannot** do:

  ```c
  int **   → const int **     // add const “down” two levels
  ```

  because that would let you store a `const int *` into an `int *` underneath and break the promise of immutability.

Whenever you need a `const int **`, you must start from a genuine `const int *`, e.g.:

```c
const int *tmp = &ci;
const int **v  = &tmp;    // safe!
```

### Warning: warning: assignment to ‘const int **’ from incompatible pointer type ‘int * const*’ [-Wincompatible-pointer-types]

```bash
int* const c = &x (where x is type int)

const int **a = &c (see the warning)
```
The heart of the confusion is that the two “middle” pointer levels carry their `const` in different places:

```c
// Your declaration
int * const c = &x;      // c:    pointer-level1 is const, base-level is non-const
                          // type of c:     int * const
                          // type of &c:    int * const *

const int **a = &c;      // a:    pointer-level1 is non-const, base-level is const
                          // type of a:     const int **
                          // *a must be    const int *
```

– **`&c`** has type **`int * const *`**

* That is, “pointer to (const pointer to int).”

– **`a`** expects a **`const int **`**

* That is, “pointer to (pointer to const int).”

Because

```
int * const *    ≠    const int **
```

you get a warning.  Even though both ultimately point to an `int`, the placement of `const` is different:

| Level              | `int * const *`      | `const int **`       |
| ------------------ | -------------------- | -------------------- |
| Level 0 (`a`/`&c`) | pointer to …         | pointer to …         |
| Level 1 (`*…`)     | const pointer to int | pointer to const int |
| Level 2 (`**…`)    | int                  | const int            |

Because **`*a`** must be a `const int *`, but **`*(&c)`** is an `int * const`, those types don’t match—and C forbids you from converting `int * const *` to `const int **` for precisely this reason (it would let you sneak a `const int *` into an `int *` underneath and then mutate a “const” object).

