#include <stdio.h>

int main(void) {
    FILE *f = fopen("fdir/elephant_seat_data.txt", "r");
    int error = 0;
    int st = 0;
    int t = 0;
    while ((error = fscanf(f, "%d", &st)) != EOF) {
        t += st;
    }
    printf("%d\n", t/1000);
    return 0;
}
