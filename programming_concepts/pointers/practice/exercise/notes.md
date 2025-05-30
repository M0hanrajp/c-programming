### Some important notes I come across.

```c
struct Rec {
    int a;
    double b;
    char c[4];
} records[10];

struct Rec *r = records + 5;
```
>when you subtract two pointers of the same type, you get the difference in elements, not bytes. So:
```c
ptrdiff_t count = (records + 5) - records;  // count == 5
```
>(char*)(records + 5) - (char*)records == 5 * sizeof(struct Rec);
- here each element will be treated as byte because pointer are of char *
- so total number of bytes between them equals number of elements.
