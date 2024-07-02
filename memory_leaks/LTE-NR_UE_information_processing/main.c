#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ue_id;
    int signal_strength;
    char *connected_cell;
} UE_Info;

UE_Info* create_ue_info(int ue_id, int signal_strength, const char* connected_cell) {
    UE_Info *ue_info = (UE_Info*) malloc(sizeof(UE_Info));
    ue_info->ue_id = ue_id;
    ue_info->signal_strength = signal_strength;
    ue_info->connected_cell = (char*) malloc(strlen(connected_cell) + 1);
    strcpy(ue_info->connected_cell, connected_cell);
    return ue_info;
}

void display_ue_info(UE_Info *ue_info) {
    printf("UE ID: %d\n", ue_info->ue_id);
    printf("Signal Strength: %d\n", ue_info->signal_strength);
    printf("Connected Cell: %s\n", ue_info->connected_cell);
}

void free_memory(UE_Info *ue_info) {
    free(ue_info->connected_cell);
    free(ue_info);
}

int main() {
    UE_Info *ue_info1 = create_ue_info(101, -65, "Cell_A");
    UE_Info *ue_info2 = create_ue_info(102, -70, "Cell_B");
    display_ue_info(ue_info1);
    free_memory(ue_info1);
    display_ue_info(ue_info2);
    free_memory(ue_info2);
    return 0;
}
/* Before and after memory freeing
 * valgrind -s --leak-check=full --leak-check=yes --show-leak-kinds=all --track-origins=yes ./ue_info
==5318== Memcheck, a memory error detector
==5318== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==5318== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==5318== Command: ./ue_info
==5318==
UE ID: 101
Signal Strength: -65
Connected Cell: Cell_A
UE ID: 102
Signal Strength: -70
Connected Cell: Cell_B
==5318==
==5318== HEAP SUMMARY:
==5318==     in use at exit: 46 bytes in 4 blocks
==5318==   total heap usage: 5 allocs, 1 frees, 1,070 bytes allocated
==5318==
==5318== 7 bytes in 1 blocks are indirectly lost in loss record 1 of 4
==5318==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==5318==    by 0x109217: create_ue_info (main.c:15)
==5318==    by 0x1092FE: main (main.c:32)
==5318==
==5318== 7 bytes in 1 blocks are indirectly lost in loss record 2 of 4
==5318==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==5318==    by 0x109217: create_ue_info (main.c:15)
==5318==    by 0x10931B: main (main.c:33)
==5318==
==5318== 23 (16 direct, 7 indirect) bytes in 1 blocks are definitely lost in loss record 3 of 4
==5318==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==5318==    by 0x1091E8: create_ue_info (main.c:12)
==5318==    by 0x1092FE: main (main.c:32)
==5318==
==5318== 23 (16 direct, 7 indirect) bytes in 1 blocks are definitely lost in loss record 4 of 4
==5318==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==5318==    by 0x1091E8: create_ue_info (main.c:12)
==5318==    by 0x10931B: main (main.c:33)
==5318==
==5318== LEAK SUMMARY:
==5318==    definitely lost: 32 bytes in 2 blocks
==5318==    indirectly lost: 14 bytes in 2 blocks
==5318==      possibly lost: 0 bytes in 0 blocks
==5318==    still reachable: 0 bytes in 0 blocks
==5318==         suppressed: 0 bytes in 0 blocks
==5318==
==5318== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
anton@DESKTOP-NSTIV7M:~/c_programming/memory_leaks/LTE-NR_UE_information_processing$ valgrind -s --leak-check=full --leak-check=yes --show-leak-kinds=all --track-origins=yes ./ue_info
==5363== Memcheck, a memory error detector
==5363== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==5363== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==5363== Command: ./ue_info
==5363==
UE ID: 101
Signal Strength: -65
Connected Cell: Cell_A
UE ID: 102
Signal Strength: -70
Connected Cell: Cell_B
==5363==
==5363== HEAP SUMMARY:
==5363==     in use at exit: 0 bytes in 0 blocks
==5363==   total heap usage: 5 allocs, 5 frees, 1,070 bytes allocated
==5363==
==5363== All heap blocks were freed -- no leaks are possible
==5363==
==5363== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/
