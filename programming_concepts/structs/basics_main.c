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
    
    // Array of structure (collection of dissimilar data types
    struct laptop_essentials database_room[3];
    strcpy(database_room[0].name, "mouse");
    database_room[1].price = 45;
    database_room[2].quantity = 44;

    for(int index = 0; index < 3; index++) {
        printf("database_room[%d], name:%s & a:%p, quantity:%d & a:%p, price:%f & a:%p\n",
                index, database_room[index].name, &database_room[index].name,
                database_room[index].quantity, &database_room[index].quantity,
                database_room[index].price, &database_room[index].price);
    }
    return 0;
}
