### 1. Know your place-values (powers of 16)

| Exponent | 16⁰ | 16¹ | 16² |  16³ |   16⁴  |    16⁵    |  …  |
| :------: | :-: | :-: | :-: | :--: | :----: | :-------: | :-: |
|   Value  |  1  |  16 | 256 | 4096 | 65 536 | 1 048 576 |     |

* **16¹ = 16**, **16² = 256**, **16³ = 4096**, etc.
* Memorize up through 16³–16⁴ for most byte/word work.

### 2. Hex digits ↔ decimal ↔ binary

| Hex | Decimal | Binary 4-bit |
| :-: | :-----: | :----------: |
|  0  |    0    |     0000     |
|  1  |    1    |     0001     |
|  2  |    2    |     0010     |
|  3  |    3    |     0011     |
|  4  |    4    |     0100     |
|  5  |    5    |     0101     |
|  6  |    6    |     0110     |
|  7  |    7    |     0111     |
|  8  |    8    |     1000     |
|  9  |    9    |     1001     |
|  A  |    10   |     1010     |
|  B  |    11   |     1011     |
|  C  |    12   |     1100     |
|  D  |    13   |     1101     |
|  E  |    14   |     1110     |
|  F  |    15   |     1111     |

### Here’s the greedy‐subtraction breakdown for converting **419₁₀ → hex**:

| Power (16ᵏ) | Value | ⌊419 ÷ Value⌋ = Digit | Digit × Value |           Remainder | Hex Digit |
| ----------: | ----: | --------------------: | ------------: | ------------------: | :-------: |
|         16² |   256 |                     1 |   1×256 = 256 | 419 − 256 = **163** |     1     |
|         16¹ |    16 |       ⌊163 ÷ 16⌋ = 10 |   10×16 = 160 |   163 − 160 = **3** |     A     |
|         16⁰ |     1 |       ⌊ 3  ÷  1⌋ =  3 |      3×1 =  3 |         3 −  3 =  0 |     3     |

1. **Largest power ≤ 419** is 16² = 256.
2. Coefficient = ⌊419/256⌋ = 1 → hex “1”. Remainder = 419 − 256 = 163.
3. Next power 16¹ = 16. Coefficient = ⌊163/16⌋ = 10 → hex “A”. Remainder = 163 − 160 = 3.
4. Next power 16⁰ = 1. Coefficient = ⌊3/1⌋ = 3 → hex “3”. Remainder = 0.

**Reading the digits top→bottom gives**:

```
419₁₀ = 1 A 3₁₆ or 0x01 0x0A3
```
### Same way how to read it for binary

```
419₁₀ = 1 A 3₁₆ or 0x01 0x0A3

// from left most, multiply the hexdigit with placevalue 
1 ---> 16 ^ 2 *  1 = 256

A ---> 16 ^ 1 * 10 = 160 // a - 10 in hex

3 ---> 16 ^ 0 *  3 =   3
------------------------
                     419
```
###  Quick mental anchors

* **0x10 = 16**, **0x100 = 256**, **0x1000 = 4096**
* **0xFF = 255** (one full byte)
* **0xFFFF = 65 535** (full 16-bit)
* Chunk hex in nibbles: e.g. 0xABCD → A (10) in the 16³ place, B (11) in 16², etc.

