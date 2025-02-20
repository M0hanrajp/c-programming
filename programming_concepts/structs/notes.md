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
} <variable-name>; // method 1 
struct <struct-name> <variable-name> // method 2
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
    // database_home might be refered to as structure variable/instance/object
```
- Assignment of values is only allowed during declaration.
```c
    struct laptopdb { // name of the structure data type
        // struct elements
    } database_record = {"Lenovo", 4545.44, 2}; // variable is declared during struct declaration.
```
- If elements are not initialized during declaration then they can be assigned separately as below:
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

#### **Key Differences Between Global and Local `struct` Declarations in C**
Declaring a struct inside `main()` vs. globally has several implications in terms of **scope, memory allocation, storage class, and lifetime**. Let's break it down:

#### ** Memory Allocation & Storage Class**
| **Location**  | **Memory Segment**   | **Lifetime**  | **Accessibility**  |
|--------------|-------------------|--------------|-----------------|
| **Global Struct Instance**  | **Data Segment (BSS/Initialized Data Section)**  | **Program Lifetime**  | Accessible **anywhere** in the file (or across files using `extern`) |
| **Local Struct Instance**  | **Stack**  | **Only while the function is executing**  | Accessible **only inside the function** |

- The Global declared & local declared struct both structs were initialised to 0 by default.

#### Accessing structure elements
```c
struct <struct-name> {
    // declaration
    float <field-item>;
}
struct <struct-name> <var-name> = {// fields populated};
```
- We can acess using the `.` operator, by using syntax `<var-name>.<field-item>`
- `struct <struct-name> <var-name> = {0};` this will set all fields to 0 inside the struct.
- so what is <var-name> what can it be called ? for example `struct books harry_potter` what is `harry_potter` here ?
    - answer is in Learnings.md[2] and basics_memory_part_2.c
    - harry_potter is an instance/object/variable of type struct books.
    - You can't print it directly because it's a collection of fields, not a primitive type.
    - Field access relies on memory offsets from the base address.
    - Passing a struct to a function copies its value, unless passed by pointer.(Needs verification)

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

Below is an example of struct,
```c
2	  struct books {
3	    char name[4];
4	    int pages;
5	    double price;
6	  } harry_potter = {"GOF", 1114, 80.80};
```
![Image](https://github.com/user-attachments/assets/831bf6d4-55df-4539-90f6-ce763ec13201)

#### **What is Alignment?**
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

### **Understanding `typedef` in `struct` Declarations**
In C, `typedef` is used to create an alias for a type, making the code more readable and reducing the need to repeatedly use `struct` when declaring variables.

#### **Using typedef with structs**
| **Declaration Style** | **Syntax** | **When to Use** |
|----------------------|------------|----------------|
| **Without `typedef`** | `struct laptop myLaptop;` | If you want to use `struct` explicitly. |
| **With `typedef` (Anonymous Struct)** | `typedef struct { ... } Laptop;` | If you don't need to refer to `struct` explicitly. |
| **With `typedef` and Struct Name** | `typedef struct laptop { ... } Laptop;` | If you need both `struct laptop` and `Laptop`. |
| **With Pointers** | `typedef struct laptop *LaptopPtr;` | To simplify pointer declarations. |

#### Array of structures
In the following way we can declare and access array of structures
```bash
// syntax
typedef struct <struct-name> {
    <data-type> element_0;  // Example: char, int, float, etc.
    <data-type> element_1;  
} <alias-name>;  // This becomes the alias for struct <struct-name>
// struct <struct-name> is the actual interface for the struct.
// (alias) is just a shortcut to avoid typing struct Laptop everywhere.

// Declaration
<variable-name>[array_size]
// Accessing multiple fields
<variable-name>[0].field
<variable-name>[n].field
```
Important note regarding accessing struct filds, note that [a] applies in GDB only.
- [a] alias[1].field-name is same as `(*(alias + 1)).field-name` & `(alias + 1).field-name` give value of the element.
- The `.` operator automatically accesses the struct fields, even if data + i is a pointer.

#### **Struct and Pointer Arithmetic**  
- **Array notation (`data[i]`) and pointer arithmetic (`*(data + i)`) are equivalent** for accessing elements.  
- The **dot (`.`) operator automatically dereferences** pointers when accessing struct fields.  
- **Pointer arithmetic in struct arrays:**
  - `data + 1` moves to the **next struct** (i.e., `Base Address + sizeof(struct)`).
  - `&data[i]` gives the **address of struct i**.
  - `&(data[i].field)` gives the **address of the specific field** within struct `i`.  

#### **Memory Offsets & Address Calculations**  
- The **base address of an array of structs** is the address of `data[0]`.  
- **Field address calculation in struct arrays:**  
  - `Address of field = Base Address + (Index * sizeof(struct)) + Offset of Field`  
  - Example: `data[1].screws` → `Base Address + 1 * sizeof(struct) + Offset of screws`  
- **Using GDB (`x/24bx &variable`)** helps visualize how struct fields are stored in memory.  

#### **Pointer & Struct Relationship**  
- A **struct variable itself is not a pointer**, but we can create pointers to structs.  
- **Using `&data[0]` gives a pointer to the first struct instance** in an array.  
- `data[i]` is equivalent to `*(data + i)`, meaning `data` can be used as a pointer to the first element.  
- The **dot operator (`.`) has higher precedence than dereference (`*`)**, so:
  - `(data + 1).screws` is equivalent to `(*(data + 1)).screws`.  

![Image](https://github.com/user-attachments/assets/c5adb5bb-03a1-45f5-a0f4-c25626592313)

#### **Summary: All Possible Ways to Access Struct Fields**
| Syntax | Works On | Equivalent To |
|---------|---------|--------------|
| `item.screws` | Struct variable | Direct field access |
| `input_data[subscript].screws` | Array of structs | `(*(input_data + subscript)).screws` |
| `(*(input_data + subscript)).screws` | Pointer to struct array | `input_data[subscript].screws` |
| `(input_data + subscript)->screws` | Pointer to struct array | `(*(input_data + subscript)).screws` |
| `*(int *)((char *)input_data + subscript * sizeof(tools_db) + offsetof(tools_db, screws))` | Memory manipulation | Manual field access |

>Note: Learn how array of fields can be created and accessed in struct, in file struct_field_element_array.c

#### **Key Takeaways**
✅ **Use `.` when working with struct variables.**  
✅ **Use `->` when working with pointers to structs.**  
✅ **Use `[]` when working with an array of structs.**  
✅ **Use pointer arithmetic + `offsetof()` for advanced memory manipulation.**

### **Comparison: Passing Struct by Value vs. Pointer**

#### **Passing by Value (struct instance)**
```c
#include <stdio.h>

struct Laptop {
    char name[10];
    int price;
};

// Function that takes a struct by value
void printLaptop(struct Laptop l) {
    // l is a copy of the original struct
    printf("Laptop: %s, Price: %d\n", l.name, l.price);
}

int main() {
    struct Laptop myLaptop = {"Dell", 500};
    printLaptop(myLaptop); // Passes a copy of myLaptop
    return 0;
}
```
✅ **Inside `printLaptop()`, you can access fields using `.` because `l` is a full struct instance.**

---

#### **Passing by Pointer (struct pointer)**
```c
int main() {
    struct Laptop myLaptop = {"Dell", 500};
    printLaptop(&myLaptop); // Passes address of myLaptop
    return 0;
}

void printLaptopPtr(struct Laptop *l) {
    // l is a pointer to the original struct
    printf("Laptop: %s, Price: %d\n", l->name, l->price);
}
```
✅ **Here, `->` is required because `l` is a pointer to the struct, not the struct itself.**

### **Takeaway**
| Passing Method        | Behavior |
|-----------------------|------------------------------------------------|
| **Pass by Value** (`printLaptop(l)`) | A **copy** of the struct is passed. Access fields with `.` |
| **Pass by Pointer** (`printLaptopPtr(&l)`) | A **pointer** to the original struct is passed. Access fields with `->` |

Note you can also pass individual elements of the struct by having function arguments of their respective type.

#### Nested structs
more information in struct_nesting.c (below are the short notes)
```c
struct kitchen {
    int items;
    char name[20];
    char compartment_name[10];
};

struct home {
    int rooms;
    struct kitchen records;// struct inside another struct
};
```
Observe the memory layout [Link to above generated layout](https://pythontutor.com/render.html#code=struct%20kitchen%20%7B%0A%20%20%20%20int%20items%3B%0A%20%20%20%20char%20name%5B20%5D%3B%0A%20%20%20%20char%20compartment_name%5B10%5D%3B%0A%7D%3B%0A%0Astruct%20home%20%7B%0A%20%20%20%20int%20rooms%3B%0A%20%20%20%20struct%20kitchen%20records%3B//%20struct%20inside%20another%20struct%0A%7D%3B%0Aint%20main%28void%29%0A%7B%0A%20%20%20%20struct%20home%20database%3B%0A%20%20%20%20//%20following%20way%20we%20can%20assign%20the%20varaibles%0A%20%20%20%20database.rooms%20%3D%201%3B%0A%20%20%20%20//%20%22.%22%20operator%20used%202%20times%20for%20refering%20nested%20struct's%20fields%0A%20%20%20%20strcpy%28database.records.name,%20%22knife%22%29%3B%0A%20%20%20%20database.records.items%20%3D%204%3B%0A%20%20%20%20strcpy%28database.records.compartment_name,%20%22shelf%22%29%3B%0A%20%20return%200%3B%0A%7D&cppShowBinary=true&cppShowMemAddrs=true&cumulative=true&curInstr=5&heapPrimitives=true&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false)
![Image](https://github.com/user-attachments/assets/4f096073-bf8c-44ef-b51d-3d8c2b4495ea)

✅ **Accessing Nested Struct Fields:**  
   - **Format:** `outer_struct.inner_struct.field = value;`
   - **Two dot operators (`.`)** → First for **nested struct**, second for **field inside nested struct**.  
   - **Memory calculation formula:**  
     ```
     Address = Base Address of Outer Struct + Offset of Nested Struct + Offset of Field
     ```
✅ **Offset Calculation from Nested Struct Perspective:**  
   - The **offset of a field inside a nested struct is relative to the nested struct itself**.  
   - We first compute the **nested struct’s offset within the outer struct**.  
   - Then, we compute the **field’s offset within the nested struct**.  

#### **💡 Accessing `database.rooms`**
```
Address = Base Address (0x7fffffffdf80) + Offset of `rooms` (0)
         = 0x7fffffffdf80
Value   = 1
```
✅ **Correct Calculation:** `database.rooms = 1`

#### **💡 Accessing `database.records.name`**
```
Address = Base Address (0x7fffffffdf80) + Offset of `records` (4) + Offset of `name` (4)
         = 0x7fffffffdf80 + 4 + 4
         = 0x7fffffffdf88
Value   = "knife"
```
if there was a pointer to a struct that has a nested struct.
```c
    // pointer to a struct, and accessing nested struct elements
    struct home *ptr = &database;
    printf("House features:\nRooms:%d, item_name:%s, qty:%d, item_location:%s\n",
            ptr->rooms, ptr->records.name, ptr->records.items, ptr->records.compartment_name);
```

```bash
#TODO: 
- how will struct allignment differ in 32 bit and 64 bit architecture
- dynamic allocation of structs.
```
