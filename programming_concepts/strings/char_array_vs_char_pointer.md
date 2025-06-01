Below is the full, uninterrupted explanation comparing:

1. ```c
   char a[] = "something";
   ```
2. ```c
   char *p = "string";
   ```

along with details about where each lives in memory, their mutability, pointer‐arithmetic rules, and common pitfalls.

---

## 1. `char a[] = "something";`

```c
char a[] = "something";
```

* **What happens at compile/run time:**

  1. The compiler sees the literal `"something"`, which is 10 bytes long (9 characters + the terminating `'\0'`).
  2. It allocates an array of exactly 10 bytes named `a` (on the stack if it’s a local variable, or in the writable data segment if declared at file scope or with `static`).
  3. It copies each byte of the literal into those 10 bytes at program startup (before `main()` begins). After that copy, there is no further link between `a` and the original literal.

* **Key properties of `a`:**

  * `a` is an actual array object of type `char[10]`.
  * **Immutable address:** You cannot do `a = …` or `a++`. Array names are not modifiable lvalues.

    * In C, whenever an array name appears in an expression (except when it’s the operand of `sizeof`, `_Alignof`, or unary `&`), it “decays” to a `char *` pointing to `a[0]`. But that decay does not mean you can reassign `a` itself.
  * **Writable contents:** Because you have your own copy of the data in a writable region (stack or data segment), you are free to modify `a[i]`. For example:

    ```c
    a[0] = 'S';        // perfectly fine
    *(a + 1) = 'O';   // also fine
    ```
  * Once you’ve modified `a`, the original literal in read‐only memory is irrelevant; you are operating on your local buffer.

* **About the “string literal” and read‐only memory:**

  * The literal `"something"` itself lives in a read‐only section of your compiled binary (often called `.rodata`).
  * That region is flagged as non‐writable by the operating system. If you somehow got a pointer directly to that literal and tried to modify it, you’d get undefined behavior (often a crash).
  * In the `char a[] = "something";` case, the literal is used only to initialize `a`. After that, `a` is a completely separate buffer in writable memory.

---

## 2. `char *p = "string";`

```c
char *p = "string";
```

* **What happens at compile/run time:**

  1. The compiler places the literal `"string"` (7 bytes: `'s','t','r','i','n','g','\0'`) into its read‐only data segment.
  2. At runtime, `p` is a pointer variable (typically stored on the stack if local) that is initialized to point at the first byte of that literal.

* **Key properties of `p`:**

  * `p` is a pointer variable of type `char *`.
  * Since `p` is an actual variable holding an address, you **can** do pointer arithmetic on `p` itself:

    ```c
    p++;        // now p points at the 't' in "string"
    p = p + 3;  // now p points at the 'i'
    ```
  * However, you **cannot** modify the characters of the literal, because they reside in read‐only memory. Writing to them via `p[...]` is undefined behavior:

    ```c
    p[0] = 'S';  // Undefined behavior (likely a segmentation fault)
    ```
  * Although C’s type system still treats string literals as `char[]` (not `const char[]`), by convention—and in practice—you must treat them as if they were `const char[]`. If you write:

    ```c
    const char *q = "string";
    ```

    the compiler will warn you if you try `q[0] = 'S';`. With `char *p = "string";`, the language allows it in C89/C99 for backward compatibility, but modifying it is still undefined.

* **“Pointer to a constant char array” vs. “pointer to char”:**

  * In strictly correct, modern‐style C, you would use `const char *` to point at a literal:

    ```c
    const char *msg = "hello";
    ```

    to signal “I will not write into this memory.”
  * Writing `char *p = "string";` compiles but leaves you vulnerable to accidentally writing into read‐only memory.

* **If you really need a mutable copy:**

  * Allocate your own buffer and copy the literal into it:

    ```c
    char buf[] = "string";   // separate, writable copy
    buf[0] = 'S';            // OK
    ```
  * Or use `malloc`/`strdup`:

    ```c
    char *q = strdup("string");  // allocates writable memory
    q[0] = 'S';                  // OK
    free(q);
    ```

---

## 3. Where in memory do these live?

1. **String literal (e.g. `"string"` or `"something"`):**

   * Placed by the compiler into a read‐only segment of the executable (often called `.rodata`).
   * Has static lifetime (exists for the duration of the entire program).
   * You must never attempt to write to it—doing so is undefined.

2. **`char a[] = "..."`:**

   * If declared at block scope without `static`, it lives on the stack (automatic storage).
   * If declared at file scope or with `static`, it lives in the writable data segment.
   * In either case, after initialization, it is your own separate writable copy.

3. **`char *p = "..."`:**

   * The pointer variable `p` itself (assuming local) lives on the stack.
   * It points directly at the literal in read‐only memory.
   * There is no second copy made—`p` just “pegs” to that read‐only location.

---

## 4. Pointer arithmetic: when can you do it?

1. **`char a[]`**

   * You **cannot** write `a++` or `a = a + 1;` because `a` is not a pointer variable. It is an array name.
   * You **can** use `(a + 1)` in expressions. For example:

     ```c
     char *t = a + 2;   // t now points at a[2]
     ```
   * If you need a moving pointer into that array, do:

     ```c
     char *writePtr = a;
     *writePtr++ = 'x';   // OK—writePtr is a pointer you can increment
     ```

2. **`char *p = "..."`**

   * You **can** do `p++`, `p = p + 3`, etc., because `p` is a pointer variable.
   * You **must not** do `*p = ...` if it points at a literal—writing there is undefined.

---

## 5. Common “gotchas” and best practices

1. **Never assume string literals are writable.**

   * Although C’s grammar calls them `char [N]`, the compiler typically places them in read‐only memory. Always treat `"..."` as read‐only. Trying to modify it is undefined (and usually crashes).

2. **If you need a mutable buffer, explicitly make one.**

   * Either use `char a[] = "..."` or allocate with `malloc/strdup`:

     ```c
     char buf[] = "hello";     // writable array
     char *dyn = strdup("hello");  // writable if strdup succeeded
     ```

3. **Prefer `const char *` when pointing at a literal.**

   * This way, any accidental write attempt is caught at compile time:

     ```c
     const char *msg = "hello";
     // msg[0] = 'H';  // Compiler error or warning
     ```

4. **Watch your buffer sizes.**

   * If you write `char a[5] = "something";`, that won’t compile because `"something"` needs 10 bytes (including `'\0'`).
   * Always ensure `sizeof(a) >= strlen(literal) + 1`.

5. **Remember lifetime differences:**

   * A local `char a[]` lives only as long as that function call’s stack frame. After returning, it becomes invalid.
   * A string literal lives for the entire program.
   * A global or `static char a[]` has static lifetime (exists for the whole program).

6. **Multi‐dimensional arrays of literals:**

   * For example:

     ```c
     char *arr[] = { "one", "two", "three" };
     ```

     Each of `"one"`, `"two"`, `"three"` is a distinct literal in read‐only memory, and `arr` is an array of pointers to them. You still cannot write `arr[i][j] = ...`.

7. **Compound literals (C99+):**

   * You can do things like:

     ```c
     char *p = (char[]){ 'a','b','c','\0' };
     ```

     This creates a temporary modifiable array (its lifetime is until the end of that full expression). It is not stored in `.rodata`.

---

## 6. TL;DR

* **`char a[] = "something";`**

  * Creates a separate, writable array of exactly the size needed.
  * You cannot do `a = something;` or `a++`, because `a` is an array name (not a pointer variable).
  * You can modify its contents (`a[i] = ...`) since it’s in writable memory.

* **`char *p = "string";`**

  * Points directly at a string literal in read‐only memory.
  * You can do pointer arithmetic on `p` (e.g. `p++`), because `p` is a pointer variable.
  * You must not modify `*p` or any `p[i]`, since that literal is effectively read‐only (attempting to do so is undefined).

