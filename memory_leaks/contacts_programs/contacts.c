#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacts.h"

#define MAX_CONTACTS 100

char **names;
char **phones;
int contact_count = 0;

void initialize_contact_list() {
    names = (char**) malloc(MAX_CONTACTS * sizeof(char*));
    phones = (char**) malloc(MAX_CONTACTS * sizeof(char*));
}

void add_contact(const char *name, const char *phone) {
    names[contact_count] = (char*) malloc(strlen(name) + 1);
    strcpy(names[contact_count], name);
    phones[contact_count] = (char*) malloc(strlen(phone) + 1);
    strcpy(phones[contact_count], phone);
    contact_count++;
}

void view_contacts() {
    for (int i = 0; i < contact_count; i++) {
        printf("Name: %s, Phone: %s\n", names[i], phones[i]);
        free(names[i]);
        free(phones[i]);
    }
    free(names);
    free(phones);
}
