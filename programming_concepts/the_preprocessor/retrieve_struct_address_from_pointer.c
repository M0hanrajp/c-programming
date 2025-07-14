// These are classic macros used in Linux kernel-style C code to retrieve the 
// address of a struct given a pointer to one of its members.

#include <stdio.h>
#include <stddef.h>

#define container_of(ptr, type, member) \
    ((type*)(((char*)(ptr)) - offsetof(type, member)))

struct Node {
    int data;
    struct Node *next;
};

int main(void) {
    struct Node n = { .data = 42, .next = NULL };
    struct Node *np = &n;
    /* get address of the member 'next' */
    struct Node **memp = &np->next;
    /* now recover the containing struct from memp */
    struct Node *orig = container_of(memp, struct Node, next);
    printf("%d\n", orig->data);
    return 0;
}
