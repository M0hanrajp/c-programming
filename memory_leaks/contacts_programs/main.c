/* NOTE: 
   This project consists of three files:
- `contacts.h` defines the function prototypes for managing the contact list.
- `contacts.c` implements the functions to initialize the contact list, add 
   contacts, view contacts, and free the contact list.
- `main.c` contains the main function, which demonstrates adding and viewing contacts in the contact list.
   Memory leaks have been deliberately introduced in this project. Your task is to find and fix them. The
   `free_contact_list` function is intended to clean up all allocated memory, but there might be mistakes
   or missing cleanup steps. Feel free to run and debug the code to identify and resolve these issues.
*/
#include <stdio.h>
#include "contacts.h"

int main() {
    initialize_contact_list();

    add_contact("Alice", "123-456-7890");
    add_contact("Bob", "234-567-8901");
    add_contact("Charlie", "345-678-9012");
    printf("Contact List:\n");
    view_contacts();
    return 0;
}
