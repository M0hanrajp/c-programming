/* A c program to demonstrate struct concept */
#include <stdio.h>
#include <string.h>
#include <strings.h>

// declaration of structure outside the main funciton
struct laptop_essentials {
    char name[15];
    int quantity;
    float price;
};

struct laptop_essentials database_essentials_office = {"keyboard", 2, 2324};
/* 
 * While printing out the memory layout
 * since database_essentials_office is declared globally
 * GDB prints out the offset value <database_essentials_office+16>: 
(gdb) x/24bx &database_essentials_office
0x555555558010 <database_essentials_office>:    0x6b    0x65    0x79    0x62    0x6f    0x61    0x72    0x64
0x555555558018 <database_essentials_office+8>:  0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x555555558020 <database_essentials_office+16>: 0x02    0x00    0x00    0x00    0x00    0x40    0x11    0x45 */

int main(void)
{
    // struct inside main function
    struct laptop { // name of the structure
        char name[10]; // data types ends declaration, ends with ;
        float price;
        int quantity;
    }; // close the declaration with ;
    struct laptop database_home; // declare variables with type struct <struct name>

    // get input from stdin
    printf("Enter laptop's name:");
    scanf("%s", database_home.name);
    printf("Enter laptop's price:");
    scanf("%f", &database_home.price);
    printf("Enter number of laptops:");
    scanf("%d", &database_home.quantity);
/*     GDB output
 *     (gdb) info locals
       database_home = {name = "Lenovo\000\000\000", price = 1000, quantity = 2} */

    // Initialize using assignment operator
    struct laptop database_office;

    strcpy(database_office.name, "Acer");
    database_office.quantity = 1;
    printf("Below are database found from office:\nWhat is the price of %s laptop ? : ", database_office.name);
    scanf("%f", &database_office.price);
    printf("Office database was updated:\nName:%s, Price:%2f, Quantity:%d\n",
            database_office.name, database_office.price, database_office.quantity);

    // Types of assignments to a structure
    struct laptop database_store = {"Leigon", 45000, 22};
    printf("Office database was updated:\nName:%s, Price:%2f, Quantity:%d\n",
                database_store.name, database_store.price, database_store.quantity);
    struct laptop_essentials database_lock = {.name = "something", .price = 22222, .quantity = 3};
    printf("Office database was updated:\nName:%s, Price:%2f, Quantity:%d\n",
                database_lock.name, database_lock.price, database_lock.quantity);
    // Checking the address:
    strcpy(database_office.name, "Lenovo");database_office.price = 45000;database_office.quantity = 2;
    printf("Address of name: %p\nAddress of price: %p\nAddress of quantity: %p\n",
            &database_home.name, &database_home.price, &database_home.quantity);

    printf("Laptop essentials:\n%s, qty:%d, price:%2f\n", 
            database_essentials_office.name, database_essentials_office.quantity, database_essentials_office.price);
    return 0;
}
