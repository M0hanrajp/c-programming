/* A c program to understand struct pointers */

#include <stdio.h>
#include <string.h>
struct book {
    char name[20];
    int pages;
    int price;
};

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

int main(void) {

    struct book database = {"Little", 400, 500};
    struct book *store = NULL;
    store->pages = 3;
    store->price = 400;
    strcpy(store->name, "Old tales");
    printf("Name:%s, Pages:%d, Price:%d\n", store->name, store->pages, store->price);
    struct user_equipment ue_a;
    user_equipment_readings(&ue_a);
    return 0;
}

// function definiton - user equipment readings
void user_equipment_readings(struct user_equipment *data) {
    printf("Enter the name of UE: ");
    scanf("%s", data->name);
    data->rsrp = -76;data->rsrq = -18, data->sinr = 24;data->cell_id = 5;data->bler = 9;
    printf("The following data was observed for a UE:\n");
    printf("UE name:%s, RSRP:%d dBm, RSRQ:%d dB, SINR:%d dB, CELL_ID:%d, BLER:%d%%\n",
            // data->structure_element == (*data).structure_variable
            data->name, data->rsrp, data->rsrq, data->sinr, data->cell_id, (*data).bler);
}
