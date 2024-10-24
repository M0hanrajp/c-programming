Bitwise operators in C are used to perform operations on individual bits of data. These operators directly manipulate the binary representation of integers, which makes them powerful for low-level programming, optimization, and tasks involving bit-level processing.

Here’s a detailed breakdown of the bitwise operators available in C:

### 1. **Bitwise AND (`&`)**:
The **AND** operator compares each bit of its two operands. The result is `1` if **both** corresponding bits are `1`, otherwise the result is `0`.

#### Example:
```c
a = 6;   // 6 in binary is 0000 0110
b = 3;   // 3 in binary is 0000 0011
result = a & b;  // result = 2 (0000 0010)
```
| a (6) | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 |
|-------|---|---|---|---|---|---|---|---|
| b (3) | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |
| a & b | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |

**Use Case**: Clearing bits, masking specific bits.

---

### 2. **Bitwise OR (`|`)**:
The **OR** operator compares each bit of its two operands. The result is `1` if **at least one** corresponding bit is `1`, otherwise the result is `0`.

#### Example:
```c
a = 6;   // 6 in binary is 0000 0110
b = 3;   // 3 in binary is 0000 0011
result = a | b;  // result = 7 (0000 0111)
```
| a (6) | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 |
|-------|---|---|---|---|---|---|---|---|
| b (3) | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |
| a \| b| 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 |

**Use Case**: Setting specific bits.

---

### 3. **Bitwise XOR (`^`)**:
The **XOR** (exclusive OR) operator compares each bit of its two operands. The result is `1` if the corresponding bits are **different**, and `0` if they are the same.

#### Example:
```c
a = 6;   // 6 in binary is 0000 0110
b = 3;   // 3 in binary is 0000 0011
result = a ^ b;  // result = 5 (0000 0101)
```
| a (6)  | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 |
|--------|---|---|---|---|---|---|---|---|
| b (3)  | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |
| a ^ b  | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 1 |

**Use Case**: Flipping bits, toggling specific bits, checking if two values are different.

---

### 4. **Bitwise NOT (`~`)**:
The **NOT** operator inverts all the bits of its operand (i.e., converts all `1`s to `0`s and `0`s to `1`s).

#### Example:
```c
a = 6;  // 6 in binary is 0000 0110
result = ~a;  // result = -7 (in 2's complement form)
```
| a (6) | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 |
|-------|---|---|---|---|---|---|---|---|
| ~a    | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 1 |

In two’s complement representation, `~6` results in `-7` because of how negative numbers are stored in memory.

**Use Case**: Inverting bits.

---

### 5. **Bitwise Left Shift (`<<`)**:
The **left shift** operator shifts the bits of its left operand to the left by the number of positions specified by the right operand. Zeros are filled in from the right.

#### Example:
```c
a = 3;   // 3 in binary is 0000 0011
result = a << 1;  // result = 6 (0000 0110)
```
| a (3) | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |
|-------|---|---|---|---|---|---|---|---|
| a << 1| 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 |

**Use Case**: Multiplying a number by powers of 2 (e.g., `a << 1` is equivalent to multiplying `a` by 2).

---

### 6. **Bitwise Right Shift (`>>`)**:
The **right shift** operator shifts the bits of its left operand to the right by the number of positions specified by the right operand. The behavior depends on whether the number is signed or unsigned:
- **For unsigned numbers**, zeros are filled in from the left.
- **For signed numbers**, the sign bit (most significant bit) is filled in from the left (arithmetic right shift).

#### Example (Unsigned):
```c
a = 6;   // 6 in binary is 0000 0110
result = a >> 1;  // result = 3 (0000 0011)
```
| a (6) | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 0 |
|-------|---|---|---|---|---|---|---|---|
| a >> 1| 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |

**Use Case**: Dividing a number by powers of 2 (e.g., `a >> 1` is equivalent to dividing `a` by 2).

---

### 7. **Shift Operators with Signed Numbers**:
For signed numbers:
- **Left shift (`<<`)** behaves the same as with unsigned numbers.
- **Right shift (`>>`)** fills the leftmost bits with the sign bit (preserving the sign of the number).

#### Example (Signed Right Shift):
```c
int a = -4;  // -4 in binary is represented as 1111 1100 (in 2's complement)
int result = a >> 1;  // result = -2 (1111 1110)
```

---

### Summary of Operators:

| **Operator** | **Symbol** | **Description**                        |
|--------------|-------------|----------------------------------------|
| AND          | `&`         | Sets each bit to 1 if both bits are 1  |
| OR           | `\|`        | Sets each bit to 1 if at least one bit is 1 |
| XOR          | `^`         | Sets each bit to 1 if bits are different |
| NOT          | `~`         | Inverts all the bits                   |
| Left Shift   | `<<`        | Shifts bits to the left, filling with 0s |
| Right Shift  | `>>`        | Shifts bits to the right, filling with 0s for unsigned and the sign bit for signed |

---

### Practical Applications of Bitwise Operators:
1. **Setting/Clearing Specific Bits**: You can use bitwise operators to set, clear, or toggle specific bits in a number (e.g., manipulating flags).
2. **Masking**: Using `&` to extract specific bits from a number (e.g., checking if a certain bit is set).
3. **Shifts for Efficiency**: Left shifts and right shifts can be used to multiply or divide integers by powers of 2, which is often faster than actual multiplication or division.
4. **Flags**: Bitwise operators are often used to manipulate flags in systems programming, where individual bits in an integer are used to represent boolean options.
