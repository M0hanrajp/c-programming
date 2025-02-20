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
    
    /* Feature A, direct assignment between structure variable of same type
     * The values of a structure variable can be assigned to another structure variable of the same type using 
     * the assignment operator. This copying of all structure elements at one go has been possible only because 
     * the structure elements are stored in contiguous memory locations.
     */
    struct organization database_two;
    database_two = database_one;
    printf("Direct assignment:\nTotal Employee: %d, population:%d, chairs:%d, avg_salary:%.2f\n",
            database_two.employees, database_two.population, database_two.chairs, database_two.average_salary);
    
    /* if not for above feature,
     * we would need to do the following:*/
    struct organization database_three;
    database_three.employees = database_two.employees;
    database_three.population = database_two.population;
    database_three.chairs = database_two.chairs;
    database_three.average_salary = 65000;
    printf("piece-meal copying:\nTotal Employee: %d, population:%d, chairs:%d, avg_salary:%.2f\n",
            database_three.employees, database_three.population, database_three.chairs, database_three.average_salary);


    // Feature B, is structure nesting, discussed in struct_nesting.c

    // Feature C, is passing a struct to a function, discussed in struct_array.c, 
    // struct_pointers_function.c, struct_functions.c & notes files.
    
    // Feature D, is usage of pointer to a structure, discussed in struct_pointer_function.c
    
    // Feature E, return a struct from function discussed in struct_pointers_function.c

    return 0;
}
