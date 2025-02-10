### Assignment with {} syntax (database_home = {"Lenovo", 3334.45, 2};)
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
