#include <stdio.h>

typedef struct tools_varray {
    int screws[2];
    int knife[2];
    int saw[2];
} tools_db_array;

// display struct field array
// Meaning here the structure contains fields that are all arrays
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

int main(void) {
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
