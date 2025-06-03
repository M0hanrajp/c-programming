### pointer arithmetic

| Operation                 | Syntax                  | Allowed? | Result Type  | Notes                                                                                  |
| ------------------------- | ----------------------- | :------: | ------------ | -------------------------------------------------------------------------------------- |
| **Addition**              |                         |          |              |                                                                                        |
| Pointer + Integer         | `p + n`                 |    Yes   | `T*`         | Move forward by `n` elements of `T`.                                                   |
| Integer + Pointer         | `n + p`                 |    Yes   | `T*`         | Commutative with `p + n`.                                                              |
| Pointer + Pointer         | `p1 + p2`               |    No    | —            | Undefined operation.                                                                   |
| **Subtraction**           |                         |          |              |                                                                                        |
| Pointer − Integer         | `p - n`                 |    Yes   | `T*`         | Move backward by `n` elements of `T`.                                                  |
| Integer − Pointer         | `n - p`                 |    No    | —            | Invalid operands.                                                                      |
| Pointer − Pointer         | `p1 - p2`               |   Yes¹   | `ptrdiff_t`  | #elements between them; only defined if both point into (or just past) the same array. |
| **Multiplication**        |                         |          |              |                                                                                        |
| Pointer \* Integer        | `p * n`                 |    No    | —            | Not defined.                                                                           |
| Integer \* Pointer        | `n * p`                 |    No    | —            | Not defined.                                                                           |
| Pointer \* Pointer        | `p1 * p2`               |    No    | —            | Not defined.                                                                           |
| **Division**              |                         |          |              |                                                                                        |
| Pointer / Integer         | `p / n`                 |    No    | —            | Not defined.                                                                           |
| Integer / Pointer         | `n / p`                 |    No    | —            | Not defined.                                                                           |
| Pointer / Pointer         | `p1 / p2`               |    No    | —            | Not defined.                                                                           |
| **Modulo**                |                         |          |              |                                                                                        |
| Pointer % Integer         | `p % n`                 |    No    | —            | Not defined.                                                                           |
| Integer % Pointer         | `n % p`                 |    No    | —            | Not defined.                                                                           |
| Pointer % Pointer         | `p1 % p2`               |    No    | —            | Not defined.                                                                           |
| **Increment / Decrement** |                         |          |              |                                                                                        |
| `++p`                     | Pre-increment           |    Yes   | `T*`         | Advance by one element.                                                                |
| `p++`                     | Post-increment          |    Yes   | `T*` (value) |                                                                                        |
| `--p`                     | Pre-decrement           |    Yes   | `T*`         | Move back by one element.                                                              |
| `p--`                     | Post-decrement          |    Yes   | `T*` (value) |                                                                                        |
| **Compound Assignment**   |                         |          |              |                                                                                        |
 `p += n`                  | Add and assign integer  |    Yes   | `T*`         | Same as `p = p + n`.                                                                   |
| `p -= n`                  | Subtract and assign int |    Yes   | `T*`         | Same as `p = p - n`.                                                                   |
| `p *= n`                  | Multiply and assign     |    No    | —            | Not defined.                                                                           |
| `p /= n`                  | Divide and assign       |    No    | —            | Not defined.                                                                           |
| `p %= n`                  | Modulo and assign       |    No    | —            | Not defined.                                                                           |

¹ *Pointer – pointer* yields the number of elements of type `T` between the two pointers.  The result is only defined when both pointers refer to (or just past) elements of the **same** array object; otherwise the behavior is undefined.

### Why is Integer - pointer invalid?

Because the compiler cannot subtract a pointer from an integer in a meaningful way. 
There is no overload or rule in C that defines int - pointer.

Remember: Pointer arithmetic is defined as operations on a memory address. Subtracting 
a pointer from an integer doesn’t make sense in terms of memory layout.

>Addition (+) in pointer arithmetic is commutative but Subtraction (-) is not commutative

**Key points:**

* **All pointer arithmetic (`+`/`−`) is in units of the pointed‐to type**, not raw bytes.
* **You cannot add, multiply, divide, or modulo two pointers**, nor multiply or divide a pointer by an integer—only `pointer ± integer` and `pointer − pointer` are allowed.
* **Increment/decrement and the corresponding `+=`/`−=` with integers are supported**, but there is no compound assignment for the other arithmetic ops.

