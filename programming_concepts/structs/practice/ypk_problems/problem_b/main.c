/* A C program to simulate a bank application */
#include <stdio.h>
#include <ctype.h>
#include "bank_database.h"

/*  Struct - data of customers 
    Below is for reference:
    int account_number;char account_holder_name[3];float account_balance;
    bank_database is the typedef defined for struct
    extern bank_database account_data[200];
*/ 

// Function declaration - get account number, name & balance less than x amount
void threshold_balance(bank_database *account_data, int database_size);

// Function declaration - withdraw or deposit into the account  
void account_withdraw_deposit(bank_database *user_account, int database_size);

int main(void) {
    int user_services = 0;
    char user_service_choice = 0;
    printf("Welcome to Yes Bank!\nPlease choose the below options to proceed:\n");
    do {
        printf("To withdraw or deposit choose 0, to check account balance of database choose 1\nYour choice: ");
        scanf("%d", &user_services);
        switch (user_services) {
            case 0:
                account_withdraw_deposit(account_data, 200);
                printf("Do you wish to using the service (y/n): ");
                scanf(" %c", &user_service_choice);
                break;
            case 1:
                threshold_balance(account_data, 200);
                printf("Do you wish to using the service (y/n): ");
                scanf(" %c", &user_service_choice);
                break;
        }
    }while(tolower(user_service_choice) != 'n');
    return 0;
}

// Function definition - get account number, name & balance less than x amount
void threshold_balance(bank_database *account_data, int database_size) {
    printf("Below is the data of account holders having balance between 1500 & 3000:\n");
    for(int index = 0; index < database_size; index++) {
        if((account_data + index)->account_balance > 1500 && (account_data + index)->account_balance < 3000) {
            printf("Account holder name:%s, Account no.:%3d, Account balance:%.2f\n",
                    (account_data + index)->account_holder_name,
                    (account_data + index)->account_number,
                    (account_data + index)->account_balance);
        }
    }
}

// Function declaration - withdraw or deposit into the account
void account_withdraw_deposit(bank_database *user_account, int database_size) {
    int user_option = 0, user_account_number = 0, withdraw_amount = 0, deposit_amount = 0;
    char user_choice = 0;
    do {
        printf("0 -> withdraw amount | 1 -> deposit amount\nEnter option: ");
        scanf("%d", &user_option);
        switch (user_option) {
            case 0:
                printf("You have choosen withdrawal option\nPlease enter account number to proceed: ");
                scanf("%d", &user_account_number);
                printf("Hello %s!, Enter the total amount to withdraw: ", 
                        (user_account + user_account_number - 1)->account_holder_name);
                scanf("%d", &withdraw_amount);
                if(withdraw_amount <= (user_account + user_account_number - 1)->account_balance) {
                    printf("Withdraw %d amount successfull, your remaining balance is %.2f\n",
                            withdraw_amount, ((user_account + user_account_number - 1)->account_balance) - withdraw_amount);
                }
                else if (withdraw_amount > (user_account + user_account_number - 1)->account_balance) {
                    printf("Cannot withdraw since %d amount exceeds your current account balance %.2f\n",
                            withdraw_amount, (user_account + user_account_number - 1)->account_balance);
                }
                printf("Do you wish to withdraw or deposit again ? (y/n) : ");
                scanf(" %c", &user_choice);
                break;
            case 1:
                printf("You have choosen deposit option\nPlease enter account number to proceed: ");
                scanf("%d", &user_account_number);
                printf("Hello %s!, Enter the total amount to deposit: ", 
                        (user_account + user_account_number - 1)->account_holder_name);
                scanf("%d", &deposit_amount);
                printf("%d was deposited to your account successfully!\nBank balance was updated, current bal:%.2f\n",
                        deposit_amount, ((user_account + user_account_number - 1)->account_balance) + deposit_amount);
                printf("Do you wish to withdraw or deposit again ? (y/n) : ");
                scanf(" %c", &user_choice);
                break;
        }
    }while(tolower(user_choice) != 'n');
}
