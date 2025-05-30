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
In C, pointers are meant to model positions within arrays of objects of a given type. All of C’s pointer 
arithmetic—including subtraction—is defined in terms of elements, not raw bytes.
oundaries (or mix totally unrelated objects), you invoke undefin
>(char*)(records + 5) - (char*)records == 5 * sizeof(struct Rec);
- here each element will be treated as byte because pointer are of char *
ed behavior—anything can happen, including “weird” negative results.

Whenever you do pointer subtraction in C, the standard only defines it if **both pointers point into (or just past) the *same* array object**.  Subtracting pointers that refer to different arrays (or totally unrelated objects) is **undefined behavior**—the compiler is free to do anything.

**What the compiler actually did**
   On your platform:

   * `s` happened to be laid out *below* `r` in memory.
   * `s[4]` lives at `addr(s) + 4*sizeof(double)`.
   * `r[2]` (cast to `double*`) lives at `addr(r) + 2*sizeof(int)`.
   * Numerically, `addr(s)+32` was *less* than `addr(r)+8`.

   When you subtract pointers the compiler computes

$$
\frac{\bigl(\text{raw address of }s[4]\bigr) \;-\;\bigl(\text{raw address of }r[2]\bigr)}{\ sizeof(\text{double})\ }.
$$
   
Here that turned out to be something like

$$
\frac{132 - 144}{8} \;=\; -12/8 \;\xrightarrow{\text{integer div. toward zero}}\;-1.
$$
