The memory allocation for arrays depends on **how and where they are declared** in the program. Let’s break it down for both **compile-time** and **runtime** allocations:

### **1. Static Arrays (Memory Allocated at Compile Time)**

#### **What are Static Arrays?**
These are arrays where the size is determined at **compile time**, and the memory is allocated either:
- On the **stack** (for local variables inside functions).
- In the **data segment** (for global or static variables).

#### **Examples of Static Arrays**
- Local array:
  ```c
  void example() {
      int numbers[5];  // Allocated on the stack at compile time
  }
  ```
- Global or static array:
  ```c
  static int global_array[10];  // Allocated in the data segment at compile time
  ```

#### **When is the Size Fixed?**
The size of the array is determined at compile time if:
1. The size is explicitly specified:
   ```c
   int arr[10];  // 10 integers allocated
   ```
2. The size is inferred from an initializer:
   ```c
   char str[] = "hello";  // Allocates 6 bytes (5 characters + null terminator)
   ```

**Key Characteristics**:
- The memory is allocated at **compile time**.
- The size cannot be changed during runtime.

---

### **2. Dynamic Arrays (Memory Allocated at Runtime)**

#### **What are Dynamic Arrays?**
Dynamic arrays are arrays whose size is determined at **runtime**, not at compile time. Memory for these arrays is allocated using functions like `malloc` in C.

#### **Examples of Dynamic Arrays**
- Allocating memory for an array dynamically:
  ```c
  int *numbers = malloc(5 * sizeof(int));  // Allocates memory for 5 integers at runtime
  ```

- Using variable-length arrays (C99 and later):
  ```c
  void example(int size) {
      int arr[size];  // Size is determined at runtime (stack allocation)
  }
  ```

#### **Key Characteristics**:
- Memory is allocated at **runtime**.
- The size can be determined dynamically based on program inputs or conditions.
- For `malloc`, the memory is allocated on the **heap**.
- For variable-length arrays, the memory is allocated on the **stack**.

---

### **3. Comparison: Compile-Time vs. Runtime Allocation**

| Feature                         | Compile-Time Arrays                 | Runtime Arrays                              |
|---------------------------------|-------------------------------------|--------------------------------------------|
| **Size**                        | Fixed at compile time               | Determined at runtime                      |
| **Memory Allocation**           | Stack (local) or data segment (global/static) | Heap (`malloc`) or stack (variable-length arrays) |
| **Flexibility**                 | Size cannot be changed after declaration | Size can be adjusted based on input        |
| **Performance**                 | Faster (no runtime overhead)        | Slower (runtime allocation/deallocation)   |
| **Lifetime**                    | Depends on scope (local/global)     | Must be managed manually (`free` for `malloc`) |

---

### **4. Practical Examples**

#### **Static Array (Compile-Time Allocation)**
```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};  // Allocated on the stack
    printf("Size of arr: %zu bytes\n", sizeof(arr));  // Outputs 20 (5 * sizeof(int))
    return 0;
}
```

#### **Dynamic Array (Runtime Allocation)**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));  // Allocated on the heap
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);  // Deallocate memory
    return 0;
}
```
---

### **5. Summary**
- **Compile-Time Allocation**: Used for arrays with fixed sizes; the memory is allocated on the stack or data segment before the program runs.
- **Runtime Allocation**: Used for dynamic arrays where the size is determined at runtime; the memory is allocated on the heap or stack dynamically.
- Choosing between the two depends on the **requirements for size flexibility and memory management**.
