### [1] Assignment with {} syntax (database_home = {"Lenovo", 3334.45, 2};)
```c
// code
int main(void) {
    // declaration type 1
    struct laptop { // name of the structure data type
        char name[10]; // elements declaration, ends with ;
        float price;
        int quantity;
    }; // close the declaration with ;
    struct laptop database_home; // database_home is a variable of type struct laptop.
    database_home = {"Lenovo", 3334.45, 2};
    database_home.name = "Lenovo";
```
- This syntax is only valid during declaration.
- Cannot be used after declaring database_home separately.
#### **3. Allowed vs. Disallowed Assignments**  
✅ **Allowed during declaration** (Memory is allocated and values are set at once):  
```c
// during declaration of struct itself
struct laptop database_home = {"Lenovo", 3334.45, 2}; // ✅ Works
```
🚫 **Not allowed after declaration** (No syntax for assigning multiple values at once):  
```c
database_home = {"Lenovo", 3334.45, 2}; // ❌ Error: Expected expression before '{' token
```
Instead, you must assign values **individually**:  
```c
strcpy(database_home.name, "Lenovo"); // ✅ Assign string using strcpy()
database_home.price = 3334.45;        // ✅ Assign float value
database_home.quantity = 2;          // ✅ Assign integer value
```

### [2] Struct variable do not decay as a pointer to it's first field like an array

Structs, however, are value types, meaning they represent a complete object, not just a reference to its first field.
```bash
~/c-programming/programming_concepts/structs$ gcc -Wall -g -Wall basics_memory_part_2.c
basics_memory_part_2.c: In function ‘main’:
basics_memory_part_2.c:14:55: warning: format ‘%p’ expects argument of type ‘void *’, but argument 2 has type ‘struct books’ [-Wformat=]
   14 |     printf("What is the address of harry_potter ? :: %p\n", harry_potter);
      |                                                      ~^     ~~~~~~~~~~~~
      |                                                       |     |
      |                                                       |     struct books
      |                                                       void *
# Code
    struct books {
        char name[5];
        int pages;
        double price;
    } harry_potter = {"GOF", 1900, 85.75};

    printf("What is the address of harry_potter ? :: %p\n", harry_potter);
```
- printf("What is the address of harry_potter ? :: %p\n", (struct books)harry_potter);
     * The above does not work
     * Structs, however, are value types, meaning they represent a complete object, not just a reference to its first field.
     * It is not a pointer it is a full instance
     * Structs do not automatically convert to pointers because:
     * They can contain different types of fields.
     * The language treats them as value types (passing/copying the whole structure instead of a reference).
     * More info is given in notes.md and basics_memory_part_2.c
