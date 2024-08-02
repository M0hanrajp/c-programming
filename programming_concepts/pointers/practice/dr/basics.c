/* Dennis DR & BK simple programs */
#include <stdio.h>

int main(void) {
    
    int x = 10, i = 1;
    //int *p = NULL;
    //p = &x;
    //printf("%d & %d\n", ++*p, *p++);
    //printf("%d\n", *p++);
    printf("%d %d %d %d %d %d %d %d %d\n", 
            --i, ++i, i++, i++, i--, --i, ++i, ++i, i);
    return 0;
}
