### **What is Array Decay?**
In most contexts, the name of an array **decays** into a pointer to its **first element**. 
However, there are some **exceptions** where the array does *not* decay, and it retains its full array type.

---

### **Rules of Array Decay**

1. **Array Used in an Expression**  
   When you use an array name in an expression (e.g., passing to a function, assigning it to a pointer), the array **decays** into a pointer to its first element.

   - Example:
     ```c
     int arr[5] = {1, 2, 3, 4, 5};
     int *ptr = arr;  // 'arr' decays into a pointer to the first element
     ```

     Here:
     - `arr` decays to `&arr[0]`.
     - Its type becomes `int *`.

   **Key Rule**: The first element of `arr` is `arr[0]`, so the type of the decayed pointer is a pointer to the type of the array elements.

   **General Case**:  
   If `T arr[N]`, then `arr` decays to `T *`.

---

2. **Exceptions to Array Decay**  
   There are 3 situations where an array does **not** decay to a pointer:

   #### a) **`sizeof` Operator**  
   When you use `sizeof` with an array, it gives the size of the **entire array** and does not cause decay.

   ```c
   int arr[5];
   printf("%zu\n", sizeof(arr)); // Prints 20 (5 * size of int)
   ```

   - `sizeof(arr)` gives the size of the entire array (not the size of a pointer).

   #### b) **`&` Operator** (Address-of Operator)  
   When you take the address of the array, the result is a pointer to the entire array, not a pointer to the first element.

   ```c
   int arr[5];
   printf("%p\n", (void *)&arr); // Address of the array
   ```

   - Here, `&arr` is of type `int (*)[5]` (pointer to an array of 5 integers).

   #### c) **Array as a String Literal in Initialization**  
   String literals used to initialize a character array do not decay.

   ```c
   char arr[] = "hello";
   ```

   - The array `arr` is initialized with the string, and it retains its array type.

---

3. **When Passing Arrays to Functions**
   When you pass an array to a function, it **always decays** to a pointer to its first element. The size information of the array is **lost**.

   - Example:
     ```c
     void func(int *p) {
         printf("%d\n", *p);
     }

     int arr[5] = {1, 2, 3, 4, 5};
     func(arr);  // 'arr' decays to 'int *'
     ```

   - Here:
     - `arr` decays to `int *` when passed to `func`.

   If you need to preserve the size of the array, you can pass it as a pointer to the full array:

   ```c
   void func(int (*p)[5]) {  // Pointer to an array of 5 ints
       printf("%d\n", (*p)[0]);
   }

   int arr[5] = {1, 2, 3, 4, 5};
   func(&arr);  // Pass address of the entire array
   ```

---

4. **For Multidimensional Arrays**
   For multidimensional arrays, **only the first dimension decays** when passed to a function.

   - Example:
     ```c
     int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

     int (*ptr)[3] = arr;  // 'arr' decays to 'int (*)[3]'
     ```

   Here:
   - `arr` decays into a **pointer to the first row** (each row is an array of 3 integers).
   - `ptr` is of type `int (*)[3]` (pointer to an array of 3 integers).

---

### **How to Know What an Array Decays To?**

To determine what an array decays into, follow these steps:

1. **Look at the array type**:  
   - If the array is declared as `T arr[N]`, it will decay to `T *` (pointer to the first element).

2. **Check the context**:  
   - **In an expression** → Decays to a pointer to the first element.  
   - **With `sizeof` or `&`** → Does **not** decay.  

3. **For multidimensional arrays**:  
   - Only the **first dimension** decays.  
   - If `T arr[M][N]`, it decays to `T (*)[N]` (pointer to an array of `N` elements).

---

### Examples to Reinforce the Rules

#### Case 1: Simple Array
```c
int arr[5] = {1, 2, 3, 4, 5};

printf("%p\n", (void *)arr);   // Decays to int *
printf("%zu\n", sizeof(arr));  // No decay, size is 20 bytes
printf("%p\n", (void *)&arr);  // No decay, type is int (*)[5]
```

#### Case 2: Passing to a Function
```c
void func(int *p) {
    printf("%d\n", *p);
}

int arr[5] = {1, 2, 3, 4, 5};
func(arr);  // Decays to int *
```

#### Case 3: Multidimensional Array
```c
int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

printf("%p\n", (void *)arr);      // Decays to int (*)[3]
printf("%p\n", (void *)&arr[0]);  // Same as 'arr'
```
---

### **Summary Table**

| Context                  | Does `arr` Decay?      | Type of Result         |
|--------------------------|------------------------|------------------------|
| **Expression (default)** | Yes                    | `T *`                  |
| **`sizeof(arr)`**        | No                     | `T[N]`                 |
| **`&arr`**               | No                     | `T (*)[N]`             |
| **Function Argument**    | Yes                    | `T *`                  |
| **Multidimensional**     | Yes (first dimension)  | `T (*)[cols]`          |

---

1. Arrays decay **by default** to a pointer to their first element.  
2. `sizeof` and `&` **prevent decay**.  
3. Multidimensional arrays decay only in the **first dimension**.
