/* A c program that indicates employee's tenures */
#include <stdio.h>
// structure employee
struct employee {
    int empcode;
    char empname[5];
    int date_year;
};

// Funciton to get user data
void enter_data(struct employee *enter_data, int data_size);

// Function to display user data
void display_data(struct employee *data, int data_size);

// Function to check which employee's tenure
int return_employee(struct employee *which_database, int *user_empcode, int data_size);

// Function to calculate employee's tenure
void calculate_tenure(int *enter_employee_year);

int main(void) {
    int employee_code = 0, employee_year = 0;
    // store employee data
    struct employee database[2];
    // Get data from user & display the entered data:
    enter_data(&database[0], 2);display_data(&database[0], 2);
    // Calculating employee tenure, first get empoloyee code for a particualar employee
    printf("This program calculates employee's tenure\nPlease entered the desired employee code the calculate tenure: ");
    scanf("%d", &employee_code);
    // Get joining data of employee year
    employee_year = return_employee(database, &employee_code, 5);
    // calculate tenure:
    calculate_tenure(&employee_year);
    return 0;
}

// Function to display user data
void display_data(struct employee *data, int data_size) {
    for(int subscript = 0; subscript < data_size; subscript++) {
        printf("Employee code:%d, Employee Name:%s, Employee joining year %d\n",
                (data + subscript)->empcode, (data + subscript)->empname, (data + subscript)->date_year);
    }
    printf("\n");
}

// Funciton to get user data
void enter_data(struct employee *enter_data, int data_size) {
    printf("Enter the below data:\n");
    for(int subscript = 0; subscript < data_size; subscript++) {
        printf("Employee code: ");
        scanf("%d", &(enter_data + subscript)->empcode);
        printf("Employee name: ");
        scanf("%s", (enter_data + subscript)->empname);
        printf("Enter the year of joining: ");
        scanf("%d", &(enter_data + subscript)->date_year);
    }
}

// Function to check which employee's tenure
int return_employee(struct employee *which_database, int *user_empcode, int data_size) {
    int return_index = 0;
    for(int subscript = 0; subscript < data_size; subscript++) {
        if((which_database + subscript)->empcode == *user_empcode) {
            return_index = subscript;
            break;
        }
    }
    return ((which_database + return_index)->date_year);
}

// Function to calculate employee's tenure
void calculate_tenure(int *enter_employee_year) {
    int user_entered_year = 0, tenure = 0;
    printf("Enter year from which tenure has to be calculated: ");
    scanf("%d", &user_entered_year);
    if(*enter_employee_year < user_entered_year) {
        tenure = user_entered_year - *enter_employee_year;
    }
    if(tenure == 0)
        printf("Total tenure was 0 years from %d year\n", user_entered_year);
    else
        printf("Total tenure was %d years from %d year\n", tenure, user_entered_year);
}

