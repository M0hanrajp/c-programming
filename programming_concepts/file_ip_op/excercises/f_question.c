/* A binary file “emp.dat” has structure [EID, Ename, designation, salary].
i. Write a user defined function CreateEmp() to input data for a record and create a file emp.dat.
ii. Write a function display() in Python to display the detail of all employees whose salary is more
than 50000. */

#include <stdio.h>

typedef struct employeeDatabase {
    int eid;
    int salary;
    char name[10];
    char designation;
} employeeDatabase;

void writeToBinaryFile(const char *file) {
    FILE *sf = fopen(file, "wb");
    employeeDatabase data;
    char exitLoop = 'y';
    while (exitLoop != 'n') {
        printf("Enter the details of the employees: ");
        scanf("%d %s %c %d", &data.eid, data.name, &data.designation, &data.salary);
        fwrite(&data, sizeof(data), 1, sf);
        printf("press 'Y' to continue or 'N' to exit: ");
        scanf(" %c", &exitLoop);
    }
    fclose(sf);
}

void readFromBinaryFile(const char *file) {
    printf("\nDisplaying Database ::\n");
    FILE *sf = fopen(file, "rb");
    employeeDatabase data;
    short int objRead = 0;
    while ((objRead = fread(&data, sizeof(data), 1, sf)) == 1) {
        printf("EID: %2d Name: %s Designation: %c Salary: %2d$\n", data.eid, data.name, data.designation, data.salary);
    }
    fclose(sf);
}

// read more than 1 struct instace at once using fread
void readMultipleStructInstanceFromBinaryFile(const char *file) {
    printf("\nEmployees having salary more than 3000 ::\n");
    FILE *sf = fopen(file, "rb");
    employeeDatabase data[3]; // size can be anything
    short int objRead = 0;
    objRead = fread(data, sizeof(data[0]), 3, sf);
    for (int i = 0; i < objRead; i++) {
        if(data[i].salary > 3000)
            printf("%s ,\n", data[i].name);
    }
    fclose(sf);
}

int main(void) {
    //writeToBinaryFile("edir/f_problem_data.dat");
    readFromBinaryFile("edir/f_problem_data.dat");
    readMultipleStructInstanceFromBinaryFile("edir/f_problem_data.dat");
    return 0;
}

// output
/*
Enter the details of the employees: 1 Neil A 4000
press 'Y' to continue or 'N' to exit: y
Enter the details of the employees: 2 knox B 2000
press 'Y' to continue or 'N' to exit: y
Enter the details of the employees: 3 Charles R 7000
press 'Y' to continue or 'N' to exit: y
Enter the details of the employees: 4 Hulk S 3000
press 'Y' to continue or 'N' to exit: n

Displaying Database ::
EID:  1 Name: Neil Designation: A Salary: 4000$
EID:  2 Name: knox Designation: B Salary: 2000$
EID:  3 Name: Charles Designation: R Salary: 7000$
EID:  4 Name: Hulk Designation: S Salary: 3000$

Employees having salary more than 3000 ::
Neil ,
Charles ,
*/
