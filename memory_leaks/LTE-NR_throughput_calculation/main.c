#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* further enhancements would be to develop a c program to calculate the throughput 
 * in ideal conditions as specified by the spec */

typedef struct {
    char *cell_name;
    double data_received; // in MB
    double time_period;   // in seconds
} Throughput_Info;

Throughput_Info* create_throughput_info(const char* cell_name, double data_received, double time_period) {
    Throughput_Info *throughput_info = (Throughput_Info*) malloc(sizeof(Throughput_Info));
    throughput_info->cell_name = (char*) malloc(strlen(cell_name) + 1);
    strcpy(throughput_info->cell_name, cell_name);
    throughput_info->data_received = data_received;
    throughput_info->time_period = time_period;
    return throughput_info;
}

void display_throughput(Throughput_Info *throughput_info) {
    double throughput = throughput_info->data_received / throughput_info->time_period;
    printf("Cell Name: %s\n", throughput_info->cell_name);
    printf("Throughput: %.2f MB/s\n", throughput);
}

void free_memory(Throughput_Info* throughput_info) {
    free(throughput_info->cell_name);
    free(throughput_info);
}

int main() {
    Throughput_Info *throughput_info = create_throughput_info("Cell_A", 500.0, 10.0);

    display_throughput(throughput_info);
    free_memory(throughput_info);
    return 0;
}
