/* A c program to understand struct pointers */

#include <complex.h>
#include <stdio.h>
#include <string.h>

struct user_equipment {
    char name[5];
    int rsrp;
    int rsrq;
    int sinr;
    int cell_id;
    int bler;
};

// function declaration - user equipment readings
void user_equipment_readings(struct user_equipment *data);

// return a struct from a function
struct user_equipment *modify_readings(struct user_equipment *data);

int main(void) {
    struct user_equipment ue_a;

    // pass by reference
    user_equipment_readings(&ue_a);

    // after above function is processed ue_a will have default values as assigned 
    // in the function user_equipment_readings
    // pointer to a struct
    struct user_equipment *ptr = &ue_a;
    // modifying the values
    strcpy(ptr->name, "APL");
    ptr->rsrp = -80;ptr->rsrq = -15, ptr->sinr = 22;ptr->cell_id = 6;ptr->bler = 10;

    // Again calling the function, values must be return to default values assigned 
    // inside the function.
    user_equipment_readings(ptr); // sending ptr which is a pointer to a struct
    struct user_equipment *modified_readings = modify_readings(ptr);
    printf("Modified readings :::\n");
    printf("UE name:%s, RSRP:%2d dBm, RSRQ:%2d dB, SINR:%2d dB, CELL_ID:%2d, BLER:%2d%%\n",
            modified_readings->name, modified_readings->rsrp, 
            ptr->rsrq, ptr->sinr, ue_a.cell_id, ue_a.bler); // to show that ptr & ue_a also change because it's pass by reference.
                                                            // note ptr was passed to function modify readings
    return 0;
}

// function definiton - user equipment readings
void user_equipment_readings(struct user_equipment *data) {
    strcpy(data->name, "SAM");
    data->rsrp = -76;data->rsrq = -18, data->sinr = 24;data->cell_id = 5;data->bler = 9;
    printf("The following data was observed for a UE:\n");
    printf("UE name:%s, RSRP:%2d dBm, RSRQ:%2d dB, SINR:%2d dB, CELL_ID:%2d, BLER:%2d%%\n",
            // data->structure_element == (*data).structure_variable
            data->name, data->rsrp, data->rsrq, data->sinr, data->cell_id, (*data).bler);
}

// function definiton - return a struct from a function
struct user_equipment *modify_readings(struct user_equipment *data) {
    static struct user_equipment data_out;
    strcpy(data->name, "HTC");
    data->rsrp = -90;
    data->rsrq = -17;
    data->sinr =  20;
    data->cell_id = 15;
    data->bler = 25;
    data_out = *data; // using struct feature of quick assignemnt of struct
    return &data_out;
}

/* Output of the program
 *
 *
(gdb) info locals
// initial default values when function is called first time
ue_a = {name = "SAM\000", rsrp = -76, rsrq = -18, sinr = 24, cell_id = 5, bler = 9}
ptr = 0x0
(gdb) n
29          strcpy(ptr->name, "APL");
(gdb) n
30          ptr->rsrp = -80;ptr->rsrq = -15, ptr->sinr = 22;ptr->cell_id = 6;ptr->bler = 10;
(gdb) n
34          user_equipment_readings(ptr); // sending ptr which is a pointer to a struct
(gdb) info locals
// After modification the values have changed
ue_a = {name = "APL\000", rsrp = -80, rsrq = -15, sinr = 22, cell_id = 6, bler = 10}
ptr = 0x7fffffffdf80
(gdb) n
// When function is called again the values revert back to default values
The following data was observed for a UE:
UE name:SAM, RSRP:-76 dBm, RSRQ:-18 dB, SINR:24 dB, CELL_ID:5, BLER:9% */
/* 
The following data was observed for a UE:
UE name:SAM, RSRP:-76 dBm, RSRQ:-18 dB, SINR:24 dB, CELL_ID: 5, BLER: 9%
The following data was observed for a UE:
UE name:SAM, RSRP:-76 dBm, RSRQ:-18 dB, SINR:24 dB, CELL_ID: 5, BLER: 9%
Modified readings :::
UE name:HTC, RSRP:-90 dBm, RSRQ:-17 dB, SINR:20 dB, CELL_ID:15, BLER:25% */
