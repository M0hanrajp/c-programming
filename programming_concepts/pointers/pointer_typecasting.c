#include <stdio.h>

int main(void) {
    int a = 1025;
    int* ptr = &a;
    printf("ptr = %p && *ptr = %d\n", (void*)ptr, *ptr);

    // char typecasting
    char* ptrA = (char* )ptr;
    // if you dont typecast (char* ) to ptr then you get a warning:
    // initialization of ‘char *’ from incompatible pointer type ‘int *’ [-Wincompatible-pointer-types]
    // regardless of the warning the output for below print statement remains the same
    // Casting an int* to a char* and then dereferencing is a well-defined way to examine the raw bytes of an object.
    printf("ptrA = %p && *ptrA = %d\n", (void*)ptrA, *ptrA);

    return 0;
}

/* here the output when cast to char* is
 * ptr = 0x7ffc05d999d4 && *ptr = 1025 & ptrA = 0x7ffc05d999d4 && *ptrA = 1
 
 What actually happens (little-endian)

1. **`int a = 1025;`**

   * 1025 decimal = `0x00000401` in hex.
2. **Memory (byte-by-byte) on little-endian**

   ```
   Address+0: 0x01   ← least-significant byte
   Address+1: 0x04
   Address+2: 0x00
   Address+3: 0x00   ← most-significant byte
   ```
3. **`int *ptr = &a;  *ptr`**

   * Reads 4 bytes starting at Address+0 → reassembles `0x00000401` → prints **1025**.
4. **`char *ptrA = (char*)ptr;  *ptrA`**

   * Reads exactly 1 byte at Address+0 → sees `0x01` → prints **1**.

So your statement “reading only a byte because `sizeof(char)==1`” is spot on – but that **byte** happens to be `0x01`, 
not `0x04`.  If you wanted to see the `0x04` you’d have to read the second byte:

```c
printf("%d\n", *(ptrA + 1));   // prints 4
```
Big-endian vs. Little-endian

* On a **big-endian** machine the highest-order byte (`0x00`) would be at Address+0, and the lowest (`0x01`) at Address+3 – so `*ptrA` would print 0 instead of 1.
* Almost all x86/x86-64 systems are little-endian, which is why you saw **1**.
*/
