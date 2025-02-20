/* A c program to understand structure and functions */
#include <stdio.h>
#include <string.h>
// structrue declaration
struct zoo {
    char name[10];
    int number_of_animals[5];
    float price;
};

struct city {
    char name[10];
    struct zoo database;
};

// Function declaration - display structure elements individual
void struct_display_elements(char *city, char *animal_name, int *total_animals, float price);

// Function declaraiton - passing the whole struct
void struct_display(struct city function_database);

int main(void) {
    struct city data = {"Jaipur", {"Camel", 4, 56000}};
    // Passing individual elements
    struct_display_elements(data.name, data.database.name, data.database.number_of_animals, data.database.price);
    // Passing whole struct
    struct city database_two;
    database_two.database.price = 95000; // This should not be given priority
    // pass by value
    struct_display(database_two);
    return 0;
}

// Function definition - display structure elements individual
void struct_display_elements(char *city, char *animal_name, int *total_animals, float price) {
    printf("Passing individual elements: The following data is the type of animal found in the city\n");
    printf("City name:%s, Animal:%s, total animals:%d, price:%.2f\n", city, animal_name, *total_animals, price);
}

// Function definition - passing the whole struct (pass by value)
void struct_display(struct city function_database) {
    strcpy(function_database.name, "Mumbai");
    strcpy(function_database.database.name, "Dino");
    function_database.database.number_of_animals[0] = 34;
    function_database.database.price = 89000;
    printf("Passing entire structure: The following data is the type of animal found in the city\n");
    printf("City name:%s, Animal:%s, total animals:%ls, price:%.2f\n", 
            function_database.name, function_database.database.name, 
            function_database.database.number_of_animals, function_database.database.price);
}
