# `int *p[3] vs int (*p)[3]

---

## 1. `int (*p)[3]`

### 1.1 Declaration and Syntax

* **Declaration:**

  ```c
  int (*p)[3];
  ```
* **Reading the Declaration:**

  * Start at `p`: “`p` is something….”
  * Encounter `*p`: “`*p` is a pointer target…”
  * Encounter `[3]` on the right of `*p`: “`*p` is an **array of 3 ints**.”
  * Thus: **`p` is a pointer to an array of 3 `int`s.**

### 1.2 Type Semantics

* **Type of `p`:**

  * `p` has type `int (*)[3]`.
  * In English: “pointer to a contiguous block of exactly 3 `int` values.”
  * It is **not** the same as `int **`. You cannot assign an `int**` directly to `p`.
  * When you write `*p`, the type of `*p` is `int[3]` (an array of 3 `int`s). Only in expression contexts will that array decay to `int *`.

* **Why This Exists:**

  * C allows pointers to arrays of known size so that you can, for example, iterate row-by-row through a 2D array whose second dimension is fixed (in this case, 3).

### 1.3 Memory Layout

* **Memory for `p` itself:**

  * Declaring `int (*p)[3];` reserves exactly one pointer’s worth of storage (on the stack, static area, or wherever you declared it).
  * That pointer is intended to hold the address of an array of three `int`s (which must be allocated or exist elsewhere).

* **Memory for what `p` points to:**

  * Suppose you have a 2D array of type `int arr[2][3] = { {1,2,3}, {4,5,6} };`.
  * Each “row” `arr[i]` is itself a contiguous block of three `int` values in memory:

    ```
    arr[0]: [ 1 |  2 |  3 ]
    arr[1]: [ 4 |  5 |  6 ]
    ```
  * If you write:

    ```c
    int (*p)[3] = arr;
    ```

    then `p` points to `arr[0]` (the first 3-element block). No extra array is allocated for `p`; only storage for a single pointer.

### 1.4 Pointer Arithmetic

* **Arithmetic on `p`:**

  * Because `p` is of type `int (*)[3]`, adding `1` to `p` moves it forward by `sizeof(int[3])` bytes.
  * If `sizeof(int) == 4`, then `sizeof(int[3]) == 12`. Hence:

    ```c
    p + 1      // advances the address by 12 bytes, jumping from arr[0] to arr[1]
    ```
  * Similarly, `p - 1` would move backward by 12 bytes (to the previous row).

* **Dereferencing after arithmetic:**

  * `*(p + 1)` yields the second row (type `int[3]`, which decays to `int *` in most contexts).
  * Equivalently, `p[1]` is the same as `*(p + 1)` and has type `int[3]` (decays to `int *` when used e.g. in indexing).

### 1.5 Dereferencing and Decay Behavior

* **Dereferencing `p`:**

  * `*p` has type `int[3]` (an actual array of three `int`s).
  * In most expression contexts (e.g. when you pass `*p` to a function expecting `int *`), that array decays to a pointer to its first element. Concretely:

    ```c
    int (*p)[3] = arr;        // arr is int[2][3], decays to &arr[0]
    int *q = *p;              // *p is int[3] ⇒ decays to int*
    // Now q points to arr[0][0]
    ```
  * **Important:** `*p` itself is not an `int *`—it is strictly an `int [3]`. Only when used in contexts like function calls, pointer arithmetic, or assignment to an `int *` variable does it decay.

* **Decay of `p`:**

  * `p` itself is already a pointer type (`int (*)[3]`). It does **not** decay.
  * However, if you take `*p` in a context like `int *r = *p;`, then `*p` decays from `int [3]` → `int *`.

* **`sizeof` and `&` exceptions:**

  * Because `*p` is an array, `sizeof(*p)` gives the size of the array (e.g. `3 × sizeof(int)`). It does not give the size of a pointer.
  * Likewise, `&(*p)` yields type `int (*)[3]` again (pointer to an array of 3 ints).

### 1.6 Typical Use Cases

1. **Iterating Over Rows of a True 2D Array:**
   If you have a statically-declared 2D array whose second dimension is known (e.g. `int grid[10][3]`), you can use `p` to step through each row easily.

2. **Passing a Single Row to a Function:**
   You might write a function that processes exactly three `int`s at a time:

   ```c
   void process_row(int (*row)[3]) {
       // row is a pointer to an array of 3 ints
       for (int j = 0; j < 3; j++) {
           printf("%d ", (*row)[j]);  
           // or equivalently: row[0][j], since row[0] is that array
       }
       printf("\n");
   }

   int main(void) {
       int matrix[5][3] = {
           {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}, {13,14,15}
       };
       // Pass the third row (index 2) to process_row:
       process_row(&matrix[2]);  // &matrix[2] has type int (*)[3]
       return 0;
   }
   ```

   In this example, inside `process_row()`, the parameter `row` points to a block of three `int`s.

3. **Treating Each Row Like a Single Object:**
   You might compute offsets, copy rows, or swap rows by manipulating `int (*)[3]` directly.

### 1.7 Example Code Snippet

```c
#include <stdio.h>

int main(void) {
    // A 2×3 “true” 2D array
    int arr[2][3] = {
        { 1,  2,  3 },
        { 4,  5,  6 }
    };

    // Declare p as “pointer to an array of 3 ints”
    int (*p)[3] = arr;  // arr decays to &arr[0], which is type int (*)[3]

    // Print elements using pointer‐to‐array notation
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            // p[row] has type int[3] (decaying to int*), so p[row][col] works
            printf("%d ", p[row][col]);
        }
        printf("\n");
    }
    // Output so far:
    //   1 2 3
    //   4 5 6

    // Demonstrate pointer arithmetic:
    p = p + 1;                 // Advance by “one array of 3 ints” (12 bytes if int is 4 bytes)
    printf("Now (*p)[0] is %d\n", (*p)[0]);  // prints 4 (the first element of the second row)

    // Demonstrate that *p is an array that decays:
    int *row0_ptr = *p;        // *p is an int[3], decays to int* pointing at element 4
    printf("row0_ptr[2] is %d\n", row0_ptr[2]);  // prints 6

    return 0;
}
```

### 1.8 Common Pitfalls and Misconceptions

1. **Confusing “pointer to array” with “array of pointers”:**

   * `int (*p)[3]` is a pointer. You can do `p++`.
   * Do not mistake it for `int *p[3]`, which is an array, not a pointer.

2. **Assuming `*p` Is an `int *` Automatically:**

   * Technically, `*p` is `int[3]`. Only in expression contexts (e.g. when you assign it to an `int *`) does it decay.

3. **Incorrect `sizeof` Expectations:**

   * `sizeof(p)` is the size of one pointer (e.g. 8 bytes on a 64-bit machine).
   * `sizeof(*p)` is the size of three `int`s (e.g. 12 bytes if `sizeof(int)` is 4).

4. **Assuming Pointer Arithmetic Is By `sizeof(int)`:**

   * No—when you do `p + 1`, it jumps by `sizeof(int[3])`, i.e. 3 × `sizeof(int)`.

5. **Attempting to Assign an Incompatible Type:**

   * You cannot write `p = some_int_ptr;` if `some_int_ptr` is `int *` or `int **`. A pointer to a single `int` is not the same as a pointer to an array of 3 `int`s.

---

## 2. `int *p[3]`

### 2.1 Declaration and Syntax

* **Declaration:**

  ```c
  int *p[3];
  ```
* **Reading the Declaration:**

  * Start at `p`: “`p` is something….”
  * Encounter `[3]`: “`p` is an array of 3 elements….”
  * Each element’s type is specified by what appears before, i.e. `int *`.
  * Thus: **`p` is an array of 3 pointers to `int`.**

### 2.2 Type Semantics

* **Type of `p`:**

  * Literally, `p` has type “array of 3 `int*`” (written in C as `int *[3]`).
  * Because arrays are not first-class lvalues, in most expression contexts `p` will **decay** into a pointer to its first element. Since each element is an `int*`, the decayed type is `int **`.
  * Each slot `p[i]` is an `int *`. You can store in it the address of an `int` (or to the first element of an `int` array).

* **Why This Exists:**

  * You might want a fixed-size group (3 in this case) of pointers, each pointing to separate integer buffers or separate single `int` variables.

### 2.3 Memory Layout

* **Memory for `p` itself:**

  * When you declare `int *p[3];`, the compiler allocates memory for exactly 3 pointer-sized slots (for example, 3 × 8 bytes = 24 bytes on a typical 64-bit system).
  * These slots are contiguous in memory (just like any array).
  * Initially, each slot (each `int *`) is uninitialized until you explicitly assign a pointer into it.

* **Memory for what `p[i]` points to:**

  * Each `p[i]` can point to any `int` or to any `int` array. Those integer values or arrays must be allocated separately (either statically, on the stack, or via `malloc`).
  * Example layout after initialization:

    ```c
    int a = 10, b = 20, c = 30;
    int *p[3] = { &a, &b, &c };
    ```

    Memory might look like:

    ```
    [ p[0] | p[1] | p[2] ]
      ↓       ↓       ↓
      &a      &b      &c
    [ a ]   [ b ]   [ c ]
    ```

### 2.4 Decay Behavior and Pointer Arithmetic

* **Decay of `p`:**

  * In most contexts, writing just `p` in an expression causes it to decay from “array of 3 `int*`” to “pointer to `int*`,” i.e. `int **`.
  * Once it has decayed to `int **`, you can increment or decrement it: `(p + 1)` is valid (pointer arithmetic on an `int **`), moving by `sizeof(int*)`.

* **Exceptions (no decay):**

  * When you apply `sizeof(p)`, `p` does **not** decay; instead, the compiler returns the size of the entire array (3 × `sizeof(int*)`).
  * When you write `&p`, you get a pointer to the entire array, type `int *(* )[3]`.

* **Arithmetic After Decay:**

  * Suppose `sizeof(int*) == 8`. Then `(p + 1)` moves by 8 bytes, from the address of `p[0]` to the address of `p[1]`.
  * Example:

    ```c
    int *q = p[0];        // q is int*, pointing at whatever p[0] pointed to
    int **pp = p;         // decay: p → int**
    pp = pp + 1;          // now pp points to p[1]
    ```
  * You cannot write `p + 1` if the context does not allow decay (e.g. `sizeof(p + 1)` is invalid, because `p` only decays in an expression; `sizeof` is a compile-time operator).

### 2.5 Dereferencing and Usage

* **Dereferencing Once (`*p`):**

  * Since `p` is an array of `int*`, the expression `*p` is equivalent to `p[0]`. Its type is `int *`.
  * To get the integer that `p[0]` points to, you write `*p[0]` (parentheses optional in this case, because `[]` binds more tightly than `*`).
  * Example:

    ```c
    int x = 99;
    int *p[3] = { &x, NULL, NULL };
    // Here *p   →  p[0], which is &x  (type: int*)
    // So **p   →  *(&x) = x = 99
    printf("%d\n", *p[0]);  // prints 99
    ```

* **Using Two Indices (`p[i][j]`):**

  * Because `p[i]` is an `int *`, you can treat `p[i]` like the base address of a separate array of `int`. If `p[i]` indeed points to the first element of some `int` array, then `p[i][j]` is well defined.
  * Example:

    ```c
    int a[2] = { 10, 20 };
    int b[2] = { 30, 40 };
    int *p[3] = { a, b, NULL };

    // p[0][1] → a[1] → 20
    // p[1][0] → b[0] → 30
    ```
  * If you only want a single `int` per pointer (not an array), you still write `*p[i]` to get that one `int`.

### 2.6 Typical Use Cases

1. **Collecting Heterogeneous or Dynamically-Sized Buffers:**

   * Sometimes you want a small fixed bucket of pointers, each of which may point to arrays of different lengths. For example:

     ```c
     char *lines[3];
     lines[0] = malloc(100);  // first line buffer
     lines[1] = malloc(200);  // second line buffer
     lines[2] = malloc(150);  // third line buffer
     ```

     Here, `lines` (analogous to `p`) is an array of 3 `char*` (similar to `int *p[3]` but for `char*`).
2. **Storing Pointers to Individual Variables:**

   * If you have three separate `int` variables and want to create an array of their addresses:

     ```c
     int a = 1, b = 2, c = 3;
     int *p[3] = { &a, &b, &c };
     // Now you can loop: for (int i = 0; i < 3; i++) { printf("%d ", *p[i]); }
     ```
3. **Passing a “Pointer Array” to a Function:**

   * Since `p` (an array) decays to `int **` in function-call contexts, you might write:

     ```c
     void print_values(int **arr, int count) {
         for (int i = 0; i < count; i++) {
             printf("%d ", *arr[i]);
         }
         printf("\n");
     }

     int a = 5, b = 10, c = 15;
     int *p[3] = { &a, &b, &c };
     print_values(p, 3);  // here p decays to int**, &p[0] effectively
     ```

### 2.7 Example Code Snippet

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Suppose we want three separate blocks of 2 integers each:
    int *p[3];  // array of 3 pointers to int

    // Allocate each block dynamically
    for (int i = 0; i < 3; i++) {
        p[i] = malloc(2 * sizeof(int));
        if (!p[i]) {
            perror("malloc failed");
            return 1;
        }
        // Fill with sample values
        p[i][0] = i * 10 + 1;
        p[i][1] = i * 10 + 2;
    }

    // Print the contents of each block
    for (int i = 0; i < 3; i++) {
        printf("Block %d: %d, %d\n", i, p[i][0], p[i][1]);
    }
    // Possible output:
    //   Block 0: 1, 2
    //   Block 1: 11, 12
    //   Block 2: 21, 22

    // Demonstrate that p decays to int** when passed to a function
    void print_first_value(int **arr_ptr) {
        // arr_ptr[0] is p[0] (an int*); *arr_ptr[0] is the first int in that block
        printf("First element of block 0 = %d\n", *arr_ptr[0]);
    }
    print_first_value(p);

    // Clean up
    for (int i = 0; i < 3; i++) {
        free(p[i]);
    }
    return 0;
}
```

### 2.8 Common Pitfalls and Misconceptions

1. **Thinking `p` Is a Pointer (so you can write `p++`):**

   * Out of the box, `p` is an array, not a pointer variable. You cannot write `p++` in your code at the same scope where `p` is declared as `int *p[3]`. That is a compile-time error.
   * Only after `p` decays—e.g. when you pass it to a function as an `int **` parameter—can you treat the parameter as a pointer and do pointer arithmetic inside that function.

2. **Confusing Levels of Indirection:**

   * `p[i]` is an `int *`. To get an `int` you must write `*p[i]`.
   * If you write `*p`, that is the same as `p[0]` (an `int *`), not an `int`. To get the actual integer you still need `**p`.

3. **Assuming Uniform Buffer Sizes:**

   * Unlike `int arr[3][2]`, which forces each row to have exactly 2 ints, with `int *p[3]` each `p[i]` might point to a block of a different size. You must manage each allocated buffer’s size separately.

4. **Forgetting to Initialize Pointers:**

   * After `int *p[3];`, each `p[i]` is uninitialized. If you attempt to dereference `*p[i]` before assigning a valid address, you get undefined behavior. Always ensure you have done something like `p[0] = &some_int;` or `p[0] = malloc(...)` before using it.

5. **Mixing Up `sizeof(p)` vs. `sizeof(*p)`:**

   * `sizeof(p)` yields the size of the array itself—`3 × sizeof(int*)`.
   * `sizeof(*p)` (where `*p` is `p[0]`) yields `sizeof(int*)`.

---

## 3. Side-By-Side Conceptual Comparison (Summary)

Below is a concise, side-by-side glimpse at how these two declarations differ in key respects—abstracted from their detailed documentation above.

| **Feature**                         | **`int (*p)[3]`**                                              | **`int *p[3]`**                                                                       |
| ----------------------------------- | -------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| **What `p` is**                     | A pointer variable that points to an array of 3 `int`s.        | An array of 3 pointers; each slot holds an `int *`.                                   |
| **Type of `p`**                     | `int (*)[3]`                                                   | `int *[3]` (decays to `int **` in most expressions)                                   |
| **Memory allocated by declaration** | Just one pointer’s worth of space (for `p` itself).            | Three pointer-sized slots filled row-wise (for `p[0]`, `p[1]`, `p[2]`).               |
| **What `p + 1` does**               | Moves forward by `sizeof(int[3])` (three `int`s).              | After decay, moves forward by `sizeof(int*)` (one pointer-sized chunk).               |
| **Type of `*p`**                    | `int[3]` (an array of 3 ints; decays to `int *`).              | `int *` (specifically, `p[0]`).                                                       |
| **Trying to do `p++`**              | Allowed (since `p` is a pointer to array).                     | Not allowed at declaration scope (because `p` is not a pointer, but an array).        |
| **Typical usage**                   | Iterating rows of a true 2D array with fixed second dimension. | Holding distinct pointers to separate integer blocks or variables, grouped as a trio. |
| **Dereferencing to get an `int *`** | `int *q = *p;`  (array-of-3-ints decays to `int *`)            | `int *q = p[0];`  (`*p` is already `p[0]`, an `int *`)                                |
| **Dereferencing to get an `int`**   | `(*p)[j]` or `p[0][j]`                                         | `*p[0]` (or equivalently, `p[0][0]` if `p[0]` points to an array)                     |
| **`sizeof(p)`**                     | Size of one pointer (e.g. 8 bytes on 64-bit).                  | Size of 3 pointers (e.g. 24 bytes on 64-bit).                                         |
| **`sizeof(*p)`**                    | Size of three `int`s (e.g. 12 bytes if `sizeof(int)==4`).      | Size of one `int *` (e.g. 8 bytes on 64-bit).                                         |
| **Decay in expressions**            | `p` never decays (it is already a pointer).                    | `p` always decays from “array of 3 `int *`” → “pointer to `int *`” (i.e. `int**`).    |

---

## 4. Final Notes

* Whenever you see parentheses around `*p`, it usually indicates that the pointer binds to something complex—here, an entire array type. Without parentheses (e.g. `int *p[3]`), the brackets bind more tightly to `p` itself, making it an array.

* Visualizing memory layouts side by side can help solidify the conceptual difference:

  **`int (*p)[3]`**

  ```
  [ p ——→  ┌───────────────────────┐ ]
           │  [ int | int | int ]  │  ← a block of 3 ints
           └───────────────────────┘
  ```

  **`int *p[3]`**

  ```
  ┌──────────────────────────┬──────────────────────────┬──────────────────────────┐
  │ p[0] (int*) → [ int ]    │ p[1] (int*) → [ int ]    │ p[2] (int*) → [ int ]    │
  └──────────────────────────┴──────────────────────────┴──────────────────────────┘
  ```

* Experimenting with small code snippets (printing addresses, sizes, and values) is the best way to internalize these differences. Use `printf("%p\n", p);`, `printf("%zu\n", sizeof(p));`, `printf("%d\n", *p[i]);`, and so on to see precisely how each declaration behaves at runtime.

By keeping the above explanations, examples, and pitfalls in mind, you should be able to choose and use the appropriate form—either `int (*p)[3]` when you need a pointer to a fixed-width array, or `int *p[3]` when you need a small, fixed-size collection of independent integer pointers.
