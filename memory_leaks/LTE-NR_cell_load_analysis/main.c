#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *cell_name;
    int connected_ues;
} Cell_Load;

Cell_Load* create_cell_load(const char* cell_name, int connected_ues) {
    Cell_Load *cell_load = (Cell_Load*) malloc(sizeof(Cell_Load));
    cell_load->cell_name = (char*) malloc(strlen(cell_name) + 1);
    strcpy(cell_load->cell_name, cell_name);
    cell_load->connected_ues = connected_ues;
    return cell_load;
}

void display_cell_load(Cell_Load *cell_load) {
    printf("Cell Name: %s\n", cell_load->cell_name);
    printf("Connected UEs: %d\n", cell_load->connected_ues);
}

// function used to free dynamically allocated memory
void free_memory(Cell_Load *cell_load) {
    free(cell_load->cell_name);
    free(cell_load);
}

int main() {
    // This can be used as a parameter to read multiple data with respect to cell load
    Cell_Load *cell1 = create_cell_load("Cell_A", 50);
    Cell_Load *cell2 = create_cell_load("Cell_B", 30);

    display_cell_load(cell1);
    free_memory(cell1);
    display_cell_load(cell2);
    free_memory(cell2);
    return 0;
}
