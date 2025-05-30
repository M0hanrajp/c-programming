#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
/* struct struct_a {
    long int x;
    float y;
    char c;
    double z;
} a; */
struct struct_a {
    long long int x;
    short int y;
    char c;
    int z;
} a[2];

int main(void) {
    //a.x = 0xFFFFFF; a.c = 'A';
    //*(uint32_t *)&a.y = 0xFFFFFFFF;  // Force 0xff bytes for float
    //*(uint64_t *)&a.z = 0xFFFFFFFFFFFFFFFF;  // Force 0xff bytes for double
/*     a[0].x = 0xFFFFFF; a[1].x = 0xFFFFFF;
    a[0].c = 'A', a[1].c = 'A';
    *(uint32_t *)&a[0].y = 0xFFFFFFFF;  // Force 0xff bytes for float
    *(uint32_t *)&a[1].y = 0xFFFFFFFF;  // Force 0xff bytes for float
    *(uint64_t *)&a[0].z = 0xFFFFFFFFFFFFFFFF;  // Force 0xff bytes for double
    *(uint64_t *)&a[1].z = 0xFFFFFFFFFFFFFFFF;  // Force 0xff bytes for double
*/
    printf("sizeof struct %zu, a[0] starts at %p\n", sizeof(a[0]), (void *)&a[0]);
    printf("Offset of x: %lu\n", offsetof(struct struct_a, x));
    printf("Offset of y: %lu\n", offsetof(struct struct_a, y));
    printf("Offset of c: %lu\n", offsetof(struct struct_a, c));
    printf("Offset of z: %lu\n", offsetof(struct struct_a, z));
    printf("sizeof struct %zu, a[1] starts at %p\n", sizeof(a[1]), (void *)&a[0]);
    //printf("Offset of zz: %lu\n", offsetof(struct struct_a, zz));
    struct node {
        int data;
        struct node *next;
    } n;
    /* n++;
     * n is a structure variable of type struct node.
     * Writing n++ is like saying “take the whole struct n, and increment it by one,” 
     * which makes no sense to the compiler—hence the “wrong type argument to increment” error.
     * if n was struct node * then incrementing would be ok
     */
    n.next = &n;
    printf("%p %p\n", &n.data, n.next);
    int *p = &n.data;
    /* int *q = (&n.data)++;
     * this does not work, &n.data yields a prvalue (temporary) pointer, not an lvalue variable.
     * The prefix ++ (or postfix ++) in C can only be applied to an lvalue of arithmetic or pointer 
     * type—i.e. something like a named variable, or something you could write on the left side of an assignment.
     */
    p++;
    printf("%p %d\n", p, *p); // for trial
    
    // size of gives the total size of struct
    int arr[4];
    struct Node {
        char label;
    int value;
    };
    struct Node arr_s[4];
    printf("sizeof(struct node): %zu, sizeof(arr_s): %zu & sizeof(arr): %zu\n", sizeof(struct Node), sizeof(arr_s), sizeof(arr));
    /* when sizeof is applied to an array you get the total number of bytes occupied by all its element */

    // strlen gives the size of string with 0 index based, sizeof gives size of whole char array of 6 elements hence size is 6
    printf("strlen(hello) = %zu, sizeof(hello) = %zu\n", strlen("hello"), sizeof("hello"));

    // TODO: Pointer arithmetic what is allowed and what is not
    int r[10]; double s[4];
    printf("Difference between &arr[8] & &arr[0] = %ld number of elements\n", &r[8] - &r[0]);
    printf("Difference between &double[4] & &double[2] = %ld number of elements\n", &s[4] - &s[2]);
    /* &s[4] - (double *)&r[2] doing this is an undefined behavior,
     *  (raw address of s[4])−(raw address of r[2]) / sizeof(double)
     * the division turned out to be invlaid and it posted -1,
     */

    return 0;
}
