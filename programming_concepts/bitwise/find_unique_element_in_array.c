/* for a given array where every element repeats itself twice, find the element
 * that ocurrrs only once */
#include <stdio.h>

int main(void) {
    int arr[] = {2, 3, 4, 6, 2, 4, 3};
    int unique = 0;
    for (int i = 0; i < 7; i++) {
        unique ^= arr[i];
    }
    printf("Unqiue element :: %d\n", unique);
    return 0;
}
