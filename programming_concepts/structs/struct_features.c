/* This c program is to test out a few structure features */
#include <stdio.h>

struct organization {
    int employees;
    int population;
    int chairs;
    float average_salary;
};

int main(void)
{
    struct organization database_one = {45, 45, 45, 50000};
    printf("Total Employee: %d, population:%d, chairs:%d, avg_salary:%.2f\n",
            database_one.employees, database_one.population, database_one.chairs, database_one.average_salary);
    
    struct organization database_two;
    database_two = database_one;
    printf("Direct assignment:\nTotal Employee: %d, population:%d, chairs:%d, avg_salary:%.2f\n",
            database_two.employees, database_two.population, database_two.chairs, database_two.average_salary);

    struct organization database_three;
    database_three.employees = database_two.employees;
    database_three.population = database_two.population;
    database_three.chairs = database_two.chairs;
    database_three.average_salary = 65000;
    printf("piece-meal copying:\nTotal Employee: %d, population:%d, chairs:%d, avg_salary:%.2f\n",
            database_three.employees, database_three.population, database_three.chairs, database_three.average_salary);
    return 0;
}
