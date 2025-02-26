#include <stdio.h>
#include <stddef.h>

int main(void) {

    typedef struct football_game {
        unsigned short      num_players  : 4;
        unsigned int        num_managers : 2;
        unsigned short      num_cameras  : 3;
    } __attribute__((packed)) statistics;

    statistics week_a;
    week_a.num_players = 0xf;week_a.num_managers = 1; week_a.num_cameras = 7;
    printf("sizeof week_a : %zu\n", sizeof(week_a));
    return 0;
}
