#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* For example lets say we call in the initiate_handover function
 * further the dummy data needs to be implemented using random funciton in c
 * further if there is a cell change we need to report cell change confrimed.
 */

typedef struct {
    int ue_id;
    char *current_cell;
} Handover_Info;

Handover_Info* initiate_handover(int ue_id, const char* from_cell, const char* to_cell) {
    Handover_Info *handover_info = (Handover_Info*) malloc(sizeof(Handover_Info));
    handover_info->ue_id = ue_id;
    handover_info->current_cell = (char*) malloc(strlen(to_cell) + 1);
    strcpy(handover_info->current_cell, to_cell);
    printf("UE %d handed over from %s to %s\n", ue_id, from_cell, to_cell);
    return handover_info;
}

void display_handover_info(Handover_Info *handover_info) {
    printf("UE ID: %d\n", handover_info->ue_id);
    printf("Current Cell: %s\n", handover_info->current_cell);
}

// this funciton deallocates the memory allocated to respective services
void free_memory(Handover_Info* handover_info) {
    free(handover_info->current_cell);
    free(handover_info);
}

int main() {
    // Need to add this inside a loop so that we can have extra implementation regarding cell change.	
    Handover_Info *handover_info = initiate_handover(101, "Cell_A", "Cell_B");

    display_handover_info(handover_info);
    free_memory(handover_info);
    return 0;
}
