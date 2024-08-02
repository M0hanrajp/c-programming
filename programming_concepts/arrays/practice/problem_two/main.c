/* A c program that checks:
 * - If numbers are positive, negative, even & odd */
#include <stdio.h>
int main(void)
{
    int stored_array[10] = {-1, 2, 3, -4, -5, -6, 7, 8, -9, -10};
    int count_positive = 0, count_negative = 0, count_even = 0, count_odd = 0;
    for(int elements = 0; elements < 10; elements++)
    {
        if(stored_array[elements] % 2 == 0)
            count_even++;
        else
            count_odd++;
        if(stored_array[elements] < 0)
            count_negative++;
        else
            count_positive++;
    }
    printf("Total even: %d, odd: %d, negative: %d & positive: %d\n", count_even, count_odd, count_negative, count_positive);
    return 0;
}
