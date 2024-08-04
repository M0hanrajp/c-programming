/* A C program to understand struct array */
#include <stdio.h>

typedef struct {
    int screws;
    int kinfe;
    int saw;
} tools;

typedef struct {
    int screws[2];
    int knife[2];
    int saw[2];
} tools_array;

// display array struct
void display_struct_array(tools *input_data, int data_size);

// display struct variable array
void display_struct_variable_array(tools_array *input_data, int data_size);

int main(void) {
    tools data[3];
    data[0].screws = 1;data[0].kinfe = 2;data[0].saw = 3;
    data[1].screws = 1;data[1].kinfe = 2;data[1].saw = 3;
    data[2].screws = 1;data[2].kinfe = 2;data[2].saw = 3;
    display_struct_array(data, 3);

    tools_array new_data;
    new_data.screws[0] = 1;new_data.knife[0] = 2;new_data.saw[0] = 3;
    new_data.screws[1] = 1;new_data.knife[1] = 2;new_data.saw[1] = 3;
    display_struct_variable_array(&new_data, 2);
    tools_array *some_data = &new_data;
    some_data->screws[0] = 1;some_data->knife[0] = 2;some_data->saw[0] = 6;
    some_data->screws[1] = 1;some_data->knife[1] = 2;some_data->saw[1] = 3;
    display_struct_variable_array(some_data, 2);
    return 0;
}

// display array struct
void display_struct_array(tools *input_data, int data_size) {
    printf("struct_array\n");
    for(int subscript = 0; subscript < data_size; subscript++) {
        printf("Screws: %d, Knife: %d, saw: %d\n", 
                (*(input_data + subscript)).screws, (input_data + subscript)->kinfe, input_data[subscript].saw);
    }
}

// display struct variable array
void display_struct_variable_array(tools_array *input_data, int data_size) {
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
