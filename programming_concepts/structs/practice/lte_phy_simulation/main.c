/* A C program to simluate LTE PHY layer readings from a user equipment */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

typedef struct user_equipment {
    char ue_name[10];
    int rsrp[6];
    int rsrq[6];
    int sinr[6];
    int cell_id;
    int cell_earfcn;
    int cell_band;
} user_equipment;

// Funciton to print random readings
void lte_phy_simluation(user_equipment *record_readings, int iterations);

int main(void) {

    user_equipment *database_readings = (user_equipment *)malloc(sizeof(user_equipment));
    lte_phy_simluation(database_readings, 5);
    free(database_readings);
    return 0;
}

// Funciton to print random readings
void lte_phy_simluation(user_equipment *record_readings, int iterations) {
    strcpy(record_readings->ue_name, "iphone");
    record_readings->cell_id = 10;
    record_readings->cell_earfcn = 5230;
    record_readings->cell_band = 12;
    for(int index = 0; index < iterations; index++) {
        record_readings->rsrp[index] = 90;
        record_readings->rsrq[index] = 12;
        record_readings->sinr[index] = 20;
        printf("UE_ID:%s, Cell_id:%d, Cell_Earfcn:%d, Cell_band:%d, RSRP:-%d dBm, RSRQ:-%d dB, SINR:%d dB\n",
                record_readings->ue_name, record_readings->cell_id, record_readings->cell_earfcn, 
                record_readings->cell_band, 
                (record_readings->rsrp[index]) + index,
                (record_readings->rsrq[index]) + index, 
                (record_readings->sinr[index]) - index);
        if(index > iterations - 4) {
            record_readings->cell_id = 12;
        }
    }
}


