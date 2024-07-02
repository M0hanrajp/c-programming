#include <stdio.h>
#include "grades.h"

int main() {
    initialize_grade_list();

    add_grade("Alice", 85);
    add_grade("Bob", 92);
    add_grade("Charlie", 78);

    printf("Student Grades:\n");
    view_grades();

    free_grade_list();
    return 0;
}
