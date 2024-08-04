/* A c program to understand structure nesting */

#include <stdio.h>
#include <string.h>

struct kitchen {
    int items;
    char name[20];
    char compartment_name[10];
};

struct home {
    int rooms;
    struct kitchen records;// struct inside another struct
};

int main(void)
{
    struct home database;
    database.rooms = 1;
    strcpy(database.records.name, "knife");
    database.records.items = 4;
    strcpy(database.records.compartment_name, "shelf");
    printf("House features:\nRooms:%d, item_name:%s, qty:%d, item_location:%s\n",
            database.rooms, database.records.name, database.records.items, database.records.compartment_name);
    return 0;
    /* Can be acessed or assigned by refering to the identifier created inside another struct
     * Format :: struct variable(.)nested_struct variable(.)nested_struct variable identifier
     */
}
