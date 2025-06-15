#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 10

// elements structure
typedef struct elements {
    char  name[10];
    char  aSymbol[3];
    float aWeight;
} elements;

// list structure
typedef struct list {
    elements data[10];
    struct list *next;
} list;

// creates a new list
list *createList(elements data[], int idx) {
    list *head = calloc(1, sizeof(struct list));
    // assign the data captured in elements 
    strcpy(head->data[idx].name, data[idx].name);
    strcpy(head->data[idx].aSymbol, data[idx].aSymbol);
    head->data[idx].aWeight = data[idx].aWeight;
    head->next = NULL;
    return head;
}

// builds each single list
list *buildList(elements data[], int idx, list *phead) {
    list *head = createList(data, idx); 
    head->next = phead;
    return head;
}

// prepares the 10 linked list with data input from user
list *prepareElementList(elements data[], int size) {
    list *head = createList(data, size - 1);
    for(int i = size - 2; i >= 0; i--) {
        head = buildList(data, i, head);
    }
    return head;
}

// prints the linked list in format 
void printList(list *head) {
    int eidx = 0;
    printf("\nThe following is printed out from linked list::\n");
        printf("-----------------------------------\n");
        printf("No.  Name        Symb     at.weight\n");
        printf("-----------------------------------\n");
    while (head != NULL) {
        printf("%2d] %-10s    %-2s        %.3f\n",
                   eidx + 1, head->data[eidx].name,
                   head->data[eidx].aSymbol,
                   head->data[eidx].aWeight);
        head = head->next;
        eidx++;
    }
    free(head);
}

int main(void) {

    elements data[MAX_ELEMENTS];

    /* Get the user input from terminal
     * all input will be stored in the struct elements data array */
    printf("Enter the first 10 elements of the periodic table:\n");
    printf("Enter the data with spaces, for example: Hydrogen H 1.008\n\n");

    for(int i = 0; i < 10; i++) {
        printf("Enter the %d element: ", i + 1);
        scanf("%s %s %f", data[i].name, data[i].aSymbol, &data[i].aWeight);
    }

    // Build linked list and with the result print out the list to stdout
    printList(prepareElementList(data, MAX_ELEMENTS));

    /* output:
        Enter the first 10 elements of the periodic table:
        Enter the data with spaces, for example: Hydrogen H 1.008

        Enter the 1 element: Hydrogen H 1.008
        Enter the 2 element: Helium He 4.003
        Enter the 3 element: Lithium Li 6.941
        Enter the 4 element: Beryllium Be 9.012
        Enter the 5 element: Boron B 10.811
        Enter the 6 element: Carbon C 12.011
        Enter the 7 element: Nitrogen N 14.007
        Enter the 8 element: Oxygen O 15.999
        Enter the 9 element: Fluorine F 18.988
        Enter the 10 element: Neon Ne 20.180

        The following is printed out from linked list::
        -----------------------------------
        No.  Name        Symb     at.weight
        -----------------------------------
         1] Hydrogen      H         1.008
         2] Helium        He        4.003
         3] Lithium       Li        6.941
         4] Beryllium     Be        9.012
         5] Boron         B         10.811
         6] Carbon        C         12.011
         7] Nitrogen      N         14.007
         8] Oxygen        O         15.999
         9] Fluorine      F         18.988
        10] Neon          Ne        20.180
    */
    return 0;
}
