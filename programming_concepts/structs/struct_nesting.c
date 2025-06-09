/* A c program to understand structure nesting */

#include <stddef.h>
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
/* 
        A struct’s size is always rounded up to a multiple of its 
        alignment requirement, and in an array each element is placed on that same boundary.
        // from the output of the program.
        sizeof(struct home) = 40, _Alignof(struct home) = 4
        sizeof(struct kitchen) = 36, _Alignof(struct kitchen) = 4
        offsetof(struct home, rooms) = 0, offsetof(struct home, records) = 4

    // Memory layout of struct kitchen
    (gdb) x/36bx &database.records
    0x7fffffffdf84: 0x04    0x00    0x00    0x00    0x6b    0x6e    0x69    0x66
    0x7fffffffdf8c: 0x65    0x00    0x00    0x00    0x00    0x00    0x00    0x00
    0x7fffffffdf94: 0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
    0x7fffffffdf9c: 0x73    0x68    0x65    0x6c    0x66    0x00    0x00    0x00
    0x7fffffffdfa4: 0x00    0x00    0x00    0x00

    // Memory layout of struct home database,
    // we can see that struct kitchen base address (0x7fffffffdf84) is after 4 bytes of database's base address.
    // offset of struct kitchen records is 4.
    (gdb) x/40bx &database
    0x7fffffffdf80: 0x01    0x00    0x00    0x00    0x04    0x00    0x00    0x00
    0x7fffffffdf88: 0x6b    0x6e    0x69    0x66    0x65    0x00    0x00    0x00
    0x7fffffffdf90: 0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
    0x7fffffffdf98: 0x00    0x00    0x00    0x00    0x73    0x68    0x65    0x6c
    0x7fffffffdfa0: 0x66    0x00    0x00    0x00    0x00    0x00    0x00    0x00

    // struct home database (is the instance)
    // It has the base address 0x7fffffffdf80
    // struct home database.records (is accessing the nested structure) at 0x7fffffffdf84
    // Complete memory layout as follows

    0x7fffffffdf80: 0x01    0x00    0x00    0x00 >> database.rooms (int)
    ==============================================================================
    0x7fffffffdf84: 0x04    0x00    0x00    0x00 >> database.records.items (int)
    ==============================================================================
    0x7fffffffdf88: 0x6b    0x6e    0x69    0x66    0x65    0x00    0x00    0x00 |
    0x7fffffffdf90: 0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00 | >> 20 bytes of database.records.name
    0x7fffffffdf98: 0x00    0x00    0x00    0x00                                 |
    ==============================================================================
    0x7fffffffdf9c: 0x73    0x68    0x65    0x6c    0x66    0x00    0x00    0x00 | >> 10 bytes of database.records.compartment_name
    0x7fffffffdfa4: 0x00    0x00    0x00    0x00                                 |
                                    ^----------^ >> last 2 bytes are padding
    The last 2 bytes of padding at 0x7fffffffdfa4 ensure that if an array of struct 
    home were allocated, the next instance would start at a multiple of 4.
 */

int main(void)
{
    struct home database;

    printf("sizeof(struct home) = %zu, _Alignof(struct home) = %zu\n", 
            sizeof(database), 
            _Alignof(struct home));
    printf("sizeof(struct kitchen) = %zu, _Alignof(struct kitchen) = %zu\n", 
            sizeof(database.records), 
            _Alignof(struct home));
    printf("offsetof(struct home, rooms) = %ld, offsetof(struct home, records) = %ld\n", 
            offsetof(struct home, rooms),
            offsetof(struct home, records));

    // following way we can assign the varaibles
    database.rooms = 1;
    // "." operator used 2 times for refering nested struct's fields
    strcpy(database.records.name, "knife");
    database.records.items = 4;
    strcpy(database.records.compartment_name, "shelf");

    printf("House features:\nRooms:%d, item_name:%s, qty:%d, item_location:%s\n",
            database.rooms, database.records.name, database.records.items, database.records.compartment_name);

    // pointer to a struct, and accessing nested struct elements
    struct home *ptr = &database;
    printf("House features:\nRooms:%d, item_name:%s, qty:%d, item_location:%s\n",
            ptr->rooms, ptr->records.name, ptr->records.items, ptr->records.compartment_name);

    return 0;

    /* Can be acessed or assigned by refering to the identifier created inside another struct
     * Format :: outer_struct.inner_struct.field = value
    //
    // Calculations
    // struct home database
    Address = Base Address (0x7fffffffdf80) + Offset of `rooms` (0)
             = 0x7fffffffdf80
    Value   = 1

    ================================
    // Nested structure calculations
    ================================

    Formula: Address = Base Address of Outer Struct + Offset of Nested Struct + Offset of Field
    > The offset of a field inside a nested struct is relative to the nested struct itself.
    > We first compute the nested struct’s offset within the outer struct.
    > Then, we compute the field’s offset within the nested struct

    database.records.items
              ^--------------nested struct (first dot operator)
                       ^-----nested struct field (second dot operator)
    // Calculations
    >> base address of struct home + offset of records + offset of struct field
    database.records.items
    >> can be written as 
    Address = Base Address (0x7fffffffdf80) + Offset of `records` (4) + Offset of `items` (0)
             = 0x7fffffffdf80 + 4 + 0
             = 0x7fffffffdf84
    Value   = 4    

    database.records.name
    >> can be written as
    Address = Base Address (0x7fffffffdf80) + Offset of `records` (4) + Offset of `name` (4)
             = 0x7fffffffdf80 + 4 + 4
             = 0x7fffffffdf88
    Value   = "knife"

    database.records.compartment_name
    >> can be written as
    Address = Base Address (0x7fffffffdf80) + Offset of `records` (4) + Offset of `compartment_name` (28)
             = 0x7fffffffdf80 + 4 + 28
             = 0x7fffffffdf9C
    Value   = "shelf"    
    */
}

/* If struct kitchen is not declared then we get the following error
 * also if struct home is declared before struct kitchen we get the same error
 * struct_nesting.c:14:20: error: field ‘records’ has incomplete type
   14 |     struct kitchen records;// struct inside another struct
      |                    ^~~~~~~ 
*/
