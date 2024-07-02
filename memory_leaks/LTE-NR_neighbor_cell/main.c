#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *cell_name;
    int num_neighbors;
    char **neighbor_cells;
} Neighbor_List;

Neighbor_List* create_neighbor_list(const char* cell_name, int num_neighbors, const char* neighbors[]) {
    Neighbor_List *neighbor_list = (Neighbor_List*) malloc(sizeof(Neighbor_List));
    neighbor_list->cell_name = (char*) malloc(strlen(cell_name) + 1);
    strcpy(neighbor_list->cell_name, cell_name);
    neighbor_list->num_neighbors = num_neighbors;
    neighbor_list->neighbor_cells = (char**) malloc(num_neighbors * sizeof(char*));
    for (int i = 0; i < num_neighbors; ++i) {
        neighbor_list->neighbor_cells[i] = (char*) malloc(strlen(neighbors[i]) + 1);
        strcpy(neighbor_list->neighbor_cells[i], neighbors[i]);
    }
    return neighbor_list;
}

void display_neighbor_list(Neighbor_List *neighbor_list) {
    printf("Cell Name: %s\n", neighbor_list->cell_name);
    printf("Neighbors:\n");
    for (int i = 0; i < neighbor_list->num_neighbors; ++i) {
        printf("  %s\n", neighbor_list->neighbor_cells[i]);
        free(neighbor_list->neighbor_cells[i]);
    }
}

void free_memory(Neighbor_List* neighbor_list) {
    free(neighbor_list->neighbor_cells);
    free(neighbor_list->cell_name);
    free(neighbor_list);
}

int main() {
    const char *neighbors[] = {"Cell_B", "Cell_C", "Cell_D"};
    Neighbor_List *neighbor_list = create_neighbor_list("Cell_A", 3, neighbors);

    display_neighbor_list(neighbor_list);
    free_memory(neighbor_list);
    return 0;
}
