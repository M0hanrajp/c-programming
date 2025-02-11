### Notes on structure 
- A struct contains a number of data types grouped together. These data types may or may not be of the same type.
- Below is the basic way of declaraing a structure.
    - Structures allow grouping of related data.Each field has its own data type.
    - Structure variables need to be declared separately.
```c
// syntax
struct <struct-name> {
    element 0; // may be char
    element 1; // may be float or int
};
```
- Below is one type of declaration of structures, more declaration types & info in basics_declaration.c
```c
// example
    // struct inside main function
    struct laptop { // name of the structure is laptop
                    // Contains three fields: name (char array), price (float), and quantity (int).
        char name[10]; // each data type declared ends with ;
        float price;
        int quantity;
    }; // close struct laptop declaration with ;
    struct laptop database_home; // database_home is declared as a variable of type struct laptop
```
- Assignment of values is only allowed during declaration.
```c
    struct laptopdb { // name of the structure data type
        // struct elements
    } database_record = {"Lenovo", 4545.44, 2}; // variable is declared during struct declaration.
```
- Struct elements can be initialized separately as below:
```c
    strcpy(database_home.name, "Lenovo");
    database_home.quantity = 2;
    database_home.price = 2222.32;
```
- During declaration and initialization of struct elements (more info in basics_declarations).
    - Struct elements initialized with compound literal type assignment reset the value of the elements.
        - i.e. `database_home = (struct laptop){.quantity = 2};` in this manner.
        - Meaning if any strcut fields not initialized or assigned will be set to `0/NULL`.
    - Only direct assignment preserves the struct elements value. `(database_home.quantity = 2;) does NOT erase other values.`

#### **Different Ways to Declare and Initialize Structures in C**

| **Method**                      | **Syntax** | **Behavior** | **Cautions** |
|----------------------------------|-----------|-------------|--------------|
| **Standard Declaration**        | `struct laptop db;` | Memory allocated, values **not initialized** (garbage values). | Always initialize before use. |
| **Direct Initialization**       | `struct laptop db = {"Lenovo", 3334.45, 2};` | Works **only at declaration**. | Cannot reassign later using `{}`. |
| **Designated Initialization (C99+)** | `struct laptop db = {.name="Lenovo", .price=3334.45, .quantity=2};` | Fields initialized in **any order**. Unspecified fields default to `0`. | Only works at declaration. |
| **Using `typedef`**             | `typedef struct {...} Laptop;` | Removes need for `struct` keyword when declaring variables. | No direct effect on initialization. |
| **Assigning After Declaration** | `db.price = 3334.45; strcpy(db.name, "Lenovo");` | Fields assigned **individually**. Existing values remain unchanged. | String assignment **requires `strcpy()`**. |
| **Compound Literals (C99+) – Full Assignment** | `db = (struct laptop){"Dell", 2550, 1};` | **Replaces all fields** in `db`. Existing values are **erased**. | All unspecified fields reset to `0`. Be cautious of overwriting. |
| **Compound Literals (C99+) – Partial Assignment** | `db = (struct laptop){.quantity = 2};` | **Only `quantity` is set, but other fields reset to `0`**. | Name and price are **erased** (set to `NULL` and `0`). |
| **Array of Structures**         | `struct laptop inventory[3] = {...};` | Each element is a **separate structure**. | Must access elements using **indexing**. |
| **Pointer to Structure**        | `struct laptop *ptr = &db;` | Use `->` to access fields via pointer. | Be careful with uninitialized pointers. |
| **Anonymous Structure (Single-use only)** | `struct { char name[10]; float price; int quantity; } db = {...};` | Creates **one-time-use** struct variable. | Cannot reuse struct elsewhere in the program. |

#### Accessing structure elements
```c
struct <struct-name> {
    // declaration
    float <field-item>;
}

struct <struct-name> <var-name> = {// fields populated};
```
- We can acess using the `.` operator, by using syntax `<var-name>.<field-item>`

### Structure memory organization

1. **Structure Definition (`struct laptop { ... };`)**  
   - **No memory is allocated here**.  
   - It **only defines** a new data type (`struct laptop`) or the format of the struct is defined.

2. **Variable Declaration (`struct laptop database_home;`)**  
   - **Memory is allocated here**.  
   - The compiler reserves enough space to store `database_home` in memory.

#### **How Much Memory is Allocated?**  
- The concept of **structure padding**
    - A processor will have processing word length as that of data bus size. On a 32-bit machine, the processing word size will be 4 bytes.
    - If the memory is arranged as a single bank of one-byte width, the processor needs to issue 4 memory read cycles to fetch an integer.
        - Meaning int is of 4 byte and to read the whole integer you would need 4 cycles from the processor.
        - So in 32 bit architecture, 1 byte is 8 bit long, 32/8 - 4 bytes (word processing length)
        - A processor will have processing word length as that of data bus size. On a 32-bit machine, the processing word size will be 4 bytes.
        - Overall 32 bit processor will be able to read the integer in one cycle.
        - the natural alignment of int on a 32-bit machine is 4 bytes. When a data type is naturally aligned, the CPU fetches it in minimum read cycles.
    - The allignment/Padding will be decided by the largest data type present in the structure.
        - I.e. if int is the largest element then structure will be 4 byte alligned.
        - if double in the largest element then structure will be 8 byte alligned.
            - Note that a double variable will be allocated on an 8-byte boundary on a 32-bit machine and requires two memory read cycles.
            - i.e. since data is porcessed in 4 byte (1 cycle), double is 8 bytes and will require 2 cycles to be read.
            - On a 64-bit machine, based on a number of banks, a double variable will be allocated on the 8-byte boundary and requires only one memory read cycle.
    - the sizeof structure also depends on the order of the elements written inside of the structure.
    - For example below struct C will be of size 24 bytes and struct D will be of size 16 bytes.
    ```c
        // structure C
    typedef struct structc_tag {
        char c;
        double d;
        int s;
    } structc_t;

    // structure D
    typedef struct structd_tag {
        double d;
        int s;
        char c;
    } structd_t;
    ```
    - Note Even though `char name[10]` is large, it consists of chars, which only require 1-byte alignment.
- Each member within the structure is aligned **according to its own type's alignment requirements**, while the **overall structure size** is aligned to the **largest member’s alignment requirement**.
#### **Alignment of Individual Members**
Each type has its own alignment requirement:
- `char` → **1-byte alignment** (can be placed anywhere)
- `int` → **4-byte alignment** (must be placed at a multiple of `4` address)
- `double` → **8-byte alignment** (must be placed at a multiple of `8` address)

So, **each member is placed at an offset that satisfies its own alignment requirement**.

#### **1. What is Alignment?**
**Alignment** means that a data type must be stored at a memory address that is a **multiple of its alignment requirement**. The CPU accesses memory efficiently when data is aligned properly.
- **4-byte alignment**: The variable must start at an address that is a multiple of 4 (e.g., **0, 4, 8, 12, 16, ...**).
- **8-byte alignment**: The variable must start at an address that is a multiple of 8 (e.g., **0, 8, 16, 24, 32, ...**).
- Refer below table for more clarity
---
#### **2. Alignment Requirements for Common Data Types**
| Data Type | Size (bytes) | Alignment Requirement |
|-----------|------------|----------------------|
| `char`    | 1         | 1-byte (can be anywhere) |
| `short`   | 2         | 2-byte (must start at a multiple of 2) |
| `int`     | 4         | 4-byte (must start at a multiple of 4) |
| `float`   | 4         | 4-byte (must start at a multiple of 4) |
| `double`  | 8         | 8-byte (must start at a multiple of 8) |
| `long`    | 8         | 8-byte (must start at a multiple of 8) |
| `pointer` | 8 (on 64-bit) | 8-byte (must start at a multiple of 8) |
