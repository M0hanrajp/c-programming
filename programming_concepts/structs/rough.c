#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
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
} a;

int main(void) {
    a.x = 0xFFFFFF; a.c = 'A';
    //*(uint32_t *)&a.y = 0xFFFFFFFF;  // Force 0xff bytes for float
    *(uint64_t *)&a.z = 0xFFFFFFFFFFFFFFFF;  // Force 0xff bytes for double
/*     a[0].x = 0xFFFFFF; a[1].x = 0xFFFFFF;
    a[0].c = 'A', a[1].c = 'A';
    *(uint32_t *)&a[0].y = 0xFFFFFFFF;  // Force 0xff bytes for float
    *(uint32_t *)&a[1].y = 0xFFFFFFFF;  // Force 0xff bytes for float
    *(uint64_t *)&a[0].z = 0xFFFFFFFFFFFFFFFF;  // Force 0xff bytes for double
    *(uint64_t *)&a[1].z = 0xFFFFFFFFFFFFFFFF;  // Force 0xff bytes for double
*/
    printf("sizeof struct %zu\n", sizeof(a));
    printf("Offset of x: %lu\n", offsetof(struct struct_a , x));
    printf("Offset of y: %lu\n", offsetof(struct struct_a, y));
    printf("Offset of c: %lu\n", offsetof(struct struct_a, c));
    printf("Offset of z: %lu\n", offsetof(struct struct_a, z));
    //printf("Offset of zz: %lu\n", offsetof(struct struct_a, zz));
    return 0;
}
