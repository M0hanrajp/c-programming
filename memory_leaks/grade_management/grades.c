#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grades.h"

#define MAX_STUDENTS 100

char **student_names;
int *grades;
int student_count = 0;

void initialize_grade_list() {
    student_names = (char**) malloc(MAX_STUDENTS * sizeof(char*));
    grades = (int*) malloc(MAX_STUDENTS * sizeof(int));
}

void add_grade(const char *name, int grade) {
    student_names[student_count] = (char*) malloc(strlen(name) + 1);
    strcpy(student_names[student_count], name);

    grades[student_count] = grade;
    student_count++;
}

void view_grades() {
    for (int i = 0; i < student_count; i++) {
        printf("Name: %s, Grade: %d\n", student_names[i], grades[i]);
    }
}

void free_grade_list() {
    for (int i = 0; i < student_count; i++) {
        free(student_names[i]);
    }
    free(student_names);
    free(grades);
}
