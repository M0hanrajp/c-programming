## Mini Project: Safe Array Operations in C

**Goal:** To implement a small module that manages a fixed-size integer array, providing functions to initialize, set, get, and print elements, all while using `assert()` to catch common errors during development.

**Features:**

1.  **Fixed-Size Array:** The module will operate on a global or static array of a predefined maximum size.
2.  **Initialization:** A function to initialize all array elements to a specific value.
3.  **Set Element:** A function to set the value of an element at a given index.
4.  **Get Element:** A function to retrieve the value of an element at a given index.
5.  **Print Array:** A function to print the contents of the array.
6.  **Assertions:** `assert()` will be used to check:
    * Array bounds (index validity) for `set_element` and `get_element`.
    * Pointer validity (e.g., if we were passing array pointers around, though we'll keep it simple with a global/static array for this example).
    * Logical consistency (e.g., ensuring an "initialized" flag is set before certain operations if we were to add such a feature).

>_The main goal was to learn the usage of assert in C here_

---

### Build & run the project

`make` is required to build the project.
- `make build` to build the project
- `make run` to run the program.
- `make clean` removes all build files.:w

```bash
--- Safe Array Test Program ---
Asserts are currently: ENABLED

Test 1: Initialize and Print
S_ARRAY[0] = 0 stored at 0x5bd7fbfd9020
S_ARRAY[1] = 0 stored at 0x5bd7fbfd9024
S_ARRAY[2] = 0 stored at 0x5bd7fbfd9028
S_ARRAY[3] = 0 stored at 0x5bd7fbfd902c
S_ARRAY[4] = 0 stored at 0x5bd7fbfd9030
Max array size: 5

Test 2: Set and Get valid elements
Set element at index 0 to 8
Set element at index 4 to 88
get_value at index (4): 88
get_value at index 4: 88
S_ARRAY[0] = 8 stored at 0x5bd7fbfd9020
S_ARRAY[1] = 0 stored at 0x5bd7fbfd9024
S_ARRAY[2] = 0 stored at 0x5bd7fbfd9028
S_ARRAY[3] = 0 stored at 0x5bd7fbfd902c
S_ARRAY[4] = 88 stored at 0x5bd7fbfd9030
```
### Project Files:

```bash
├── Makefile
├── README.md
├── build
│   ├── assert_test_safe_array
│   ├── main.o
│   └── safe_array.o
├── log
│   └── assert_safe_array.log
└── src
    ├── main.c
    ├── safe_array.c
    └── safe_array.h
```
