/* A C program to understand struct array */
#include <stdio.h>

typedef struct tools{
    int screws;
    int knife;
    int saw;
} tools_db; // tools_db is an alias for the structure which is of type struct tools
            // It's just a reference it's not the actual struct interface
            // The actual interface for the struct is struct tools but is refered by alias tools_db

// the below tools_varray is discussed in struct_field_element_array.c
typedef struct tools_varray {
    int screws[2];
    int knife[2];
    int saw[2];
} tools_db_array;

// display array struct
void display_struct_array(tools_db *input_data, int data_size);

// display struct field array
// Meaning here the structure contains fields that are all arrays
void display_struct_variable_array(tools_db_array *input_data, int data_size);

int main(void) {

    // Assigning values to data
    tools_db data[3];
    data[0].screws = 1;data[0].knife = 2;data[0].saw = 3;
    data[1].screws = 1;data[1].knife = 2;data[1].saw = 3;
    data[2].screws = 1;data[2].knife = 2;data[2].saw = 3;

/*  (gdb) whatis tools_db >> this is just an alias
    type = struct tools
    (gdb) whatis data
    type = tools_db [3] >> data is the array of struct of size 3
    (gdb) p data
    $2 = {{screws = 1, knife = 2, saw = 3}, {screws = 1, kinfe = 2, saw = 3}, {screws = 1, kinfe = 2, saw = 3}}
    (gdb) p sizeof(tools_db) >> size of the structure is 12 bytes since tools_db is of type struct tools
    $4 = 12
    (gdb) p sizeof(data) >> 3 * sizeof(tools_db) i.e. 36
    $3 = 36

    // Memory layout ::
    (gdb) x/36bx data
    0x7fffffffdf70: 0x01    0x00    0x00    0x00    0x02    0x00    0x00    0x00
    0x7fffffffdf78: 0x03    0x00    0x00    0x00    0x01    0x00    0x00    0x00
    0x7fffffffdf80: 0x02    0x00    0x00    0x00    0x03    0x00    0x00    0x00
    0x7fffffffdf88: 0x01    0x00    0x00    0x00    0x02    0x00    0x00    0x00
    0x7fffffffdf90: 0x03    0x00    0x00    0x00

    // offsets
    0x7fffffffdf70 >> data[0].screws
    0x7fffffffdf74 >> data[0].knife
    0x7fffffffdf78 >> data[0].saw
    0x7fffffffdf7C >> data[1].screws
    0x7fffffffdf80 >> data[1].knife
    0x7fffffffdf84 >> data[1].saw
    0x7fffffffdf88 >> data[2].screws
    0x7fffffffdf8C >> data[2].knife
    0x7fffffffdf90 >> data[2].saw

    (gdb) p data[0]
    $11 = {screws = 1, kinfe = 2, saw = 3}
    (gdb) p data[1]
    $12 = {screws = 1, kinfe = 2, saw = 3}
    (gdb) p data[2]
    $13 = {screws = 1, kinfe = 2, saw = 3}
    (gdb) p &data[0]
    $14 = (tools_db *) 0x7fffffffdf70 // memory address 0x7fffffffdf70 is being interpreted as a pointer
                                      // to a tools_db struct, since it's the base address. & data acts
                                      // as a pointer to a first element

    (gdb) p (data + 1).screws // here dot operator implicitly dereferences so we get one.
                              // Means it as same as (*(data + 1)).screws
                              // (data + i).field is equivalent to (*(data + i)).field, since . has higher precedence than *.
                              // The . operator automatically accesses the struct fields, even if data + i is a pointer.
                              // This was possible only through gdb as it's more flexible
                              // Need to use -> operator if we are accessing fields from struct pointers.
    $39 = 1
    (gdb) p data[1].screws // simple way of accessing struct field, the type would be int.
    $40 = 1
    (gdb) p &(data + 1).screws
    $41 = (int *) 0x7fffffffdf7c // using & gives it of type int * as we are accessing a field
    (gdb) p &data[1].screws
    $42 = (int *) 0x7fffffffdf7c

    How Calculations can be done ?
    ==============================
    data[1].screws gives out value = 1.
    basically base address + offset address = address of struct field

    so in terms of array of structs,
    ===================================================================================
    >> data[1].screws: Address = Base Address + 1 * sizeof(tools_db) + Offset of screws
    ===================================================================================
    > 0x7fffffffdf70 (Base address) + 1 * 12(sizeof(tools_db)) + 0 = 1 (screws)
    > 0x7fffffffdf70 (Base address) + 1 * 12(sizeof(tools_db)) + 4 = 2 (knife)
    > 0x7fffffffdf70 (Base address) + 1 * 12(sizeof(tools_db)) + 8 = 2 (saw)
*/
    // Passing data to a function
    display_struct_array(data, 3);
/*  - while passing array of struct which is of type <alias-name> var-name[sizeofarray]
        - the function argument must accept the base address of the struct instance.
        - Hence the function argument might be written as (<alias-name> *<var-name>), a pointer that 
          accepts the base address.
    - Since data is already of type tools_db [3] here, it decays as a pointer to it's first element.
    - Hence `data` can be sent without using & operator.
    - Because if we send &data here it will be a pointer to whole array i.e. tools_db (*)[3] 

    For information on how the elements are accessed please refer the comments w.r.t to
    function name  display_struct_array(data, 3); below
*/

    tools_db_array new_data;
    new_data.screws[0] = 1;new_data.knife[0] = 2;new_data.saw[0] = 3;
    new_data.screws[1] = 1;new_data.knife[1] = 2;new_data.saw[1] = 3;
    display_struct_variable_array(&new_data, 2); // &new_data is sent as function argument because new_data is just an instance
                                                 // It's not like array that it will decay to an address hence &new_data is sent
                                                 // Remember new_data is an variable/instance of type struct tools_db_array


    // Pointer to a struct
    tools_db_array *some_data = &new_data;
    some_data->screws[0] = 1;some_data->knife[0] = 2;some_data->saw[0] = 6;
    some_data->screws[1] = 1;some_data->knife[1] = 2;some_data->saw[1] = 3;
    display_struct_variable_array(some_data, 2);
    return 0;
}

// display array struct
void display_struct_array(tools_db *input_data, int data_size) {
    printf("struct_array\n");
    for(int subscript = 0; subscript < data_size; subscript++) {
        printf("Screws: %d, Knife: %d, saw: %d\n", 
                (*(input_data + subscript)).screws, (input_data + subscript)->knife, input_data[subscript].saw);
    }
/*     - above are the ways in which we can access fields from struct pointer.
       - why struct pointer term here ?
       - When you pass a pointer to a struct (tools_db *input_data), the variable inside 
         the function acts as a pointer, so you must use -> to access its fields.
       - Due to this variable it does not act like instance of the struct instead acts as 
         a pointer to a struct hence we need -> to dereference the pointer to point to the field.
       - this is known as passing by reference.

    - In the pass by value case, the funciton argument will be (struct <alias> var)
    - and from the main function we can directly send the instance of the struct.
    - When you pass a struct instance (not a pointer) to a function, you can access its 
      fields using . operator.
    - When calling the function, the struct instance is copied onto the stack.
    - Inside the function, the parameter is a local copy of the struct, which behaves like a normal variable.
    - You access its fields with . because it is a full struct, not a pointer. */
}

// display struct variable array
void display_struct_variable_array(tools_db_array *input_data, int data_size) {
    printf("struct_variable_array\n");
    for(int subscript = 0; subscript < data_size; subscript++) {
        printf("Screws: %d, Knife: %d, saw: %d\n",
                input_data->screws[subscript], input_data->knife[subscript], input_data->saw[subscript]);
    }
    /* Below are the ways in which we can access the elements 
     * *(input_data->screws + subscript), *(input_data->knife + subscript), *(input_data->saw + subscript));
     * (*input_data).screws[subscript], (*input_data).knife[subscript], (*input_data).saw[subscript]);
     */
}
