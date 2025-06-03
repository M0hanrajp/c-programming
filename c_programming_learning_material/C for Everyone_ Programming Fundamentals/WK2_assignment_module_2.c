/* Write enumerated types that supports dates—such as december 12. 
 * Then add a function that produces a next day.  
 * So nextday(date) of december 12 is december 13. 
 * Also write a function printdate(date) that prints a date legibly.
 * The function can assume that February has 28 days and it most know how many days are in each month. 
 * Use a struct with two members; one is the month and the second  is the day of the month—an int (or short).
 *
 * typedef enum month{ jan, feb, …} month;
 * typedef struct date{ month m; int d} date;
 *
 * Then print out  the date January 1  and print  the next day Jan 2.
 * Do this for the following dates:  February 28, March 14, October 31, and  December 31.
 */

#include <stdio.h>

// months of the year as enum
typedef enum month   { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEPT, OCT, NOV, DEC } month;

// array of max days that holds max days for a month corresponding to enum month
int maxDays[12] =  { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// define date as struct, with members month and date
typedef struct date {
    month m;
    short int d;
} date;

// Function that prints date
void printDate(date *date) {
    switch (date->m) {
        case  JAN:   printf("Date: January %hd\n",  date->d); break;
        case  FEB:   printf("Date: February %hd\n", date->d); break;
        case  MAR:   printf("Date: March %hd\n",    date->d); break;
        case  APR:   printf("Date: April %hd\n",    date->d); break;
        case  MAY:   printf("Date: May %hd\n",      date->d); break;
        case  JUN:   printf("Date: June %hd\n",     date->d); break;
        case  JUL:   printf("Date: July %hd\n",     date->d); break;
        case  AUG:   printf("Date: August %hd\n",   date->d); break;
        case SEPT:   printf("Date: September %hd\n",date->d); break;
        case  OCT:   printf("Date: October %hd\n",  date->d); break;
        case  NOV:   printf("Date: November %hd\n", date->d); break;
        case  DEC:   printf("Date: December %hd\n", date->d); break;
        default  :   printf("Date: not found\n");             break;
    }
}

// Function that calculates next day
date *nextDay(date *date) {
    short int nd = date->d + 1;
    if(nd < maxDays[date->m]) {
        date->d = nd;
        return date;
    } else {
        date->d = nd - date->d;
        date->m++;
        if(date->m > 11)
            date->m = JAN;
        return date;
    }
}

int main(void) {

    // set the following dates according to question.
    date feb = {FEB, 28};
    date mar = {MAR, 15};
    date oct = {OCT, 31};
    date dec = {DEC, 31};

    /* call print date, but execute the return value from nextDay
     * nextDay returns a pointer to the updated date
     * printDate prints the updated date
     */
    printDate(nextDay(&feb));
    printDate(nextDay(&mar));
    printDate(nextDay(&oct));
    printDate(nextDay(&dec));
    return 0;

    /* following output is observed
     * Date: March 1
     * Date: March 16
     * Date: November 1
     * Date: January  1
     */
}
