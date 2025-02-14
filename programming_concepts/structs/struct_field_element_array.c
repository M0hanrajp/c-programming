#include <stdio.h>

typedef struct tools_array {
    int screws[2];
    int knife[2];
    int saw[2];
} tools_db_array;

// display struct field array
// Meaning here the structure contains fields that are all arrays
void display_struct_variable_array(tools_db_array *input_data, int data_size);

int main(void) {
    tools_db_array new_data;
    new_data.screws[0] = 1;new_data.knife[0] = 2;new_data.saw[0] = 3;
    new_data.screws[1] = 4;new_data.knife[1] = 5;new_data.saw[1] = 6;

/*  // Memory layout
    (gdb) x/24bx &new_data
    0x7fffffffdf80: 0x01    0x00    0x00    0x00    0x04    0x00    0x00    0x00
    0x7fffffffdf88: 0x02    0x00    0x00    0x00    0x05    0x00    0x00    0x00
    0x7fffffffdf90: 0x03    0x00    0x00    0x00    0x06    0x00    0x00    0x00

    // Calculation of offset
    // Please note that when we declare the fields as arrays
    // they are accessed through their index
    // base address of the struct remains constant
    0x7fffffffdf80 >> new_data.screws[0]
    0x7fffffffdf84 >> new_data.screws[1]
    0x7fffffffdf88 >> new_data.knife[0]
    0x7fffffffdf8C >> new_data.knife[1]
    0x7fffffffdf90 >> new_data.saw[0]
    0x7fffffffdf94 >> new_data.saw[1]
    // GDB output for verification
    (gdb) p new_data.screws[0]
    $09 = 1
    (gdb) p &new_data.screws[0]
    $10 = (int *) 0x7fffffffdf80
    (gdb) p new_data.screws[1]
    $11 = 4
    (gdb) p &new_data.screws[1]
    $12 = (int *) 0x7fffffffdf84

    How Calculations can be done ?
    ==============================
    new_data.screws[1] = 4.
    Previously as we know in order to get the value of a struct field we used the formula
    base address + offset address = address of struct field

    so in terms of struct fields as array
    ===================================================================================
    >> Base Address + offset of field + n * sizeof(field data type)
    >> where n is 0 based index of the array
    ===================================================================================

    // For accessing struct field screws 0 & 1
    >> 0x7fffffffdf80 (Base address) + 0 (offset of field) + (0 * sizeof(int)) = new_data.screws[0] = 1
    >> 0x7fffffffdf80 (Base address) + 0 (offset of field) + (1 * sizeof(int)) = new_data.screws[1] = 4

    // For accessing struct field knife 0 & 1
    >> 0x7fffffffdf80 (Base address) + 8 (offset of field) + (0 * sizeof(int)) = new_data.knife[0] = 2
    >> 0x7fffffffdf80 (Base address) + 8 (offset of field) + (1 * sizeof(int)) = new_data.knife[1] = 5

    // For accessing struct field saw 0 & 1
    >> 0x7fffffffdf80 (Base address) + 16 (offset of field) + (0 * sizeof(int)) = new_data.knife[0] = 3
    >> 0x7fffffffdf80 (Base address) + 16 (offset of field) + (1 * sizeof(int)) = new_data.knife[1] = 6 
*/

    display_struct_variable_array(&new_data, 2);
    // &new_data is sent as function argument because new_data is just an instance
    // It's not struct array that it will decay into a pointer to the first element of the struct.
    // Remember new_data is an variable/instance of type struct tools_db_array
    /* the function argument is a pointer to a struct
     * i.e. tools_db_array *input_data, (read it backwards)
     * this is a pass by reference example 
     * More info on how the function performs is given inside the function definition
     */

    // Pointer to a struct
    // This will edit the values and replace them with new values.
    tools_db_array *some_data = &new_data;
    some_data->screws[0] = 7;some_data->knife[0] = 8;some_data->saw[0] = 9;
    some_data->screws[1] = 1;some_data->knife[1] = 2;some_data->saw[1] = 3;
    display_struct_variable_array(some_data, 2);

    return 0;
}

void display_struct_variable_array(tools_db_array *input_data, int data_size) {
    printf("struct_variable_array\n");
    for(int subscript = 0; subscript < data_size; subscript++) {
        printf("Screws: %d, Knife: %d, saw: %d\n",
                input_data->screws[subscript], input_data->knife[subscript], input_data->saw[subscript]);
    }
    /* Below are the ways in which we can access the elements 
     * *(input_data->screws + subscript), *(input_data->knife + subscript), *(input_data->saw + subscript));
     * using -> will give the address of the element, using * to dereference will give the final output
     *
     * (*input_data).screws[subscript], (*input_data).knife[subscript], (*input_data).saw[subscript]);
     * Here we have not used "->" operator
     * input_data retrieves the actual struct that input_data is pointing to.
     * input_data behaves like a regular struct instance.
     * input_data is now the struct instance, (*input_data).screws accesses the screws array inside the struct.
     * ((*input_data).screws[subscript]) This retrieves the subscript-th element from the screws array.
     *
     * Most important 
     * input is a pointer to a struct type
     * We will need "->" operator to get field member's value.
     */
}
