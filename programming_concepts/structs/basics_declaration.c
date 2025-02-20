#include <stdio.h>
#include <string.h>

int main(void) {
    // declaration type 1
    struct laptop { // name of the structure data type
        char name[10]; // elements declaration, ends with ;
        float price;
        int quantity;
    }; // close the declaration with ;
    struct laptop database_home; // database_home is a variable of type struct laptop.

    // declaration type 2
    struct laptopdb { // name of the structure data type
        char name[10]; // elements declaration, ends with ;
        float price;
        int quantity;
    } database_record = {"Lenovo", 4545.44, 2}; // variable is declared during struct declaration.
                                                // declaration with initialization

    // declaration type 3
    // This kind of decalaration has limited scope while using structs
    struct { // name of the structure data type is not provided
        char name[10]; // elements declaration, ends with ;
        float price;
        int quantity;
    } database_file = {.price = 3334.45, .quantity = 2, .name = "Lenovo"}; 
    // variable is declared during struct declaration, without struct name
    // in this format of declaration Fields can be initialized in any order.
    // Unspecified fields are set to zero or NULL.

    // The following is not allowed after struct has been declared.
    //database_home = {"Lenovo", 3334.45, 2};

    // The following initialization is allowed
    // the below declaration will change only the value that is set and other values in struct
    // remain same, unchanged
    strcpy(database_home.name, "Lenovo");
    database_home.quantity = 2;
    database_home.price = 2222.32;

    // if we would want to change database_home initialization
    // Allows initialization after declaration using (struct Type){} syntax. (Compound literals)
    database_home = (struct laptop){"Dell", 2550, 1}; // works in C99 and beyond
    /* Output:
     * before change
     * database_home = {name = "Lenovo\000\000\000", price = 2222.32007, quantity = 2}
     * after change
     * database_home = {name = "Dell\000\000\000\000\000", price = 2550, quantity = 1}
     * if any filed is not included in the above declaration it will be reset to 0/NULL.
     */
    database_home = (struct laptop){.quantity = 2}; // this is also allowed
    /* Output
     * database_home = {name = "\000\000\000\000\000\000\000\000\000", price = 0, quantity = 2}
     * Name and price where reduced to NULL and 0
     * why because
     * Compound literals create a new temporary structure and assign it to database_home.
     * When fields are omitted, they are reset to zero (0).
     * Direct assignment to fields (database_home.quantity = 2;) does NOT erase other values.
     */
    database_record = (struct laptopdb){.name = "Hp", .price = 1233.3};
    /* Output:
     * Before
     * database_record = {name = "Lenovo\000\000\000", price = 4545.43994, quantity = 2}
     * after compound literal assignment
     * database_record = {name = "Hp\000\000\000\000\000\000\000", price = 1233.30005, quantity = 0}
     */
    return 0;
}
