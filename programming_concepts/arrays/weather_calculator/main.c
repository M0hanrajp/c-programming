/* C program to that calculates weather statistics
 * NOTE: Requirements
 * 1. Find total rainfall each year
 * 2. average yearly rainfall
 * 3. average rainfall each month
 * ------------------------------
 * Input - 2D array - 5 rows & 12 columns
 * Rainfall amounts can be floats
 */

#include <stdio.h>
#define YEARS 5
#define MONTHS 12

int main(void)
{
    // Hardcoded rainfall data for 5 years
    double rainfall[YEARS][MONTHS] = {
        {3.4, 2.1, 1.8, 4.5, 2.9, 3.0, 2.5, 1.7, 3.2, 2.6, 2.0, 3.8},
        {2.5, 1.9, 3.2, 2.4, 3.0, 2.7, 2.6, 3.5, 2.8, 2.9, 3.1, 2.3},
        {3.0, 2.8, 3.5, 2.7, 2.9, 3.2, 2.6, 2.8, 2.4, 2.3, 2.7, 3.0},
        {2.6, 2.7, 3.1, 2.8, 2.5, 3.2, 3.0, 2.9, 2.7, 2.8, 2.3, 2.4},
        {3.2, 2.4, 2.9, 3.1, 3.5, 2.7, 2.8, 3.0, 3.3, 2.6, 2.7, 2.9}
    };
    double average_yearly_rainfall = 0;
    int start = 0;
    double average_monthly_rainfall = 0;
    // Calculating total rainfall each year
    for(int element_years = 0; element_years < YEARS; element_years++)
    {
        double total_rainfall = 0;
        for(int element_months = 0; element_months < MONTHS; element_months++)
        {
            total_rainfall += rainfall[element_years][element_months];
        }
        printf("Year %d, Anual Rainfall (inches): %.2lf\n", 2015 + element_years, total_rainfall);
        average_yearly_rainfall += total_rainfall;
    }
    
    // Average rainfall for the last 5 years 
    printf("-- Average rainfall for the past 5 years : %.2lf --\n", average_yearly_rainfall/5);
    
    // Monthly average
    
    for(int element_years = 0; element_years < YEARS; element_years++)
    {
        for(int element_months = start; element_months < start + 1; element_months++)
        {
            average_monthly_rainfall += rainfall[element_years][element_months];
        }
        if(element_years == 4)
        {
            printf("-- Month %2d average rainfall of past 5 years (inches): %lf\n", start + 1, average_monthly_rainfall/5);
            start++;
            element_years = -1;
            average_monthly_rainfall = 0;
        }
        if(start == 12)
        {
                break;
        }
    }
    return 0;
}

