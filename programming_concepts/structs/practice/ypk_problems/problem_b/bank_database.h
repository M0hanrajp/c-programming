#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H

// Struct - data of customers 
typedef struct {
    int account_number;
    char account_holder_name[3];
    float account_balance;
} bank_database;

// this allows me to define account_data in other file.
extern bank_database account_data[200];

#endif
