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

