/* A C program to calculate average and percentage of the marks obtained
 * Requirements:
 * Function should be able to receive marks & return the avg & percentage
 * Function is called from main & results should be displayed from main.
 */

#include <stdio.h>

// Function prototype declaration
void calculate_average_percentage(float *maths, float *science, float *english, float *average, float *percentage);

int main(void)
{
    float average = 0;
    float percentage = 0;
    // input of subjects
    float maths = 0;
    float science = 0;
    float english = 0;
    printf("Enter the marks obtained : ");
    scanf("%f %f %f", &maths, &science, &english);

    // Function call
    calculate_average_percentage(&maths, &science, &english, &average, &percentage);
    printf("Average across all the 3 subjects: %.3f\n", average);
    printf("percentage obtained in all 3 subjects: %.3f %%\n", percentage);
    return 0;
}

// Function definition
void calculate_average_percentage(float *maths, float *science, float *english, float *average, float *percentage)
{
    *average = (*maths + *science + *english)/3;
    *percentage = ((*maths + *science + *english)/300) * 100;
}
