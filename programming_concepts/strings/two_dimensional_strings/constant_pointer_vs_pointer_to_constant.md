### Theory of constant pointer & pointer to a constant

Points to remember:
- string literals are immutable and typically stored in read-only memory.

#### Difference between `char str[] = "Hello code";` and `char *ptr = "Hello code";`
- where str is a constant pointer to a char.
- where ptr is a pointer to a constant char.
![Image](https://github.com/user-attachments/assets/fc44f3a0-551a-4a66-b146-c42150b9d7a9)

[Pointers can be read in different way too, for example char const *p and const char *p are the same !](https://github.com/M0hanrajp/c-programming/blob/3659579d1c2d3c058f71432087722554b3259d5d/programming_concepts/strings/two_dimensional_strings/constant_pointers_%26_Pointer_to_constant.c#L28)

#### Constant pointer to a string:

In the textbook YPK let us C, page 340,
```bash
# The below is reffered to as constant pointer to a string
    char str[5] = "Linux";
# constant pointer - str
# string "Linux"
```
>A **constant pointer** is a pointer that cannot change the memory address it holds.
- The array name (e.g., `str`) acts as a **constant pointer** to the first element of the array.
- Constant pointer means the address stored in p cannot be changed, but the contents of the memory it points to (the char array) can be modified, provided it is not const itself.
- Attempting p++ means you are trying to modify the address stored in p to point to the next char. This is not allowed because the pointer is const.

```bash
char str[6] = "Linux";
// Memory layout:
+----+----+----+----+----+----+
|'L'| 'i'| 'n'| 'u'| 'x'| '\0'|
+----+----+----+----+----+----+
 ^ (fixed address, str) but character's at those address are modifyable.
```
#### Pointer to a constant string:

In the textbook YPK let us C, page 340,
```bash
# The below is reffered to as pointer to a constant string
    char *p = "Linux";
# constant string - "linux"
# pointer - p
```
- It is a pointer pointing to a string that is constant (read-only) and cannot be modified. This often happens when the pointer is assigned the address of a string literal.
- Why Is the String Constant?
   - String literals in C are constant by design:
   - The C standard specifies that modifying a string literal is undefined behavior.
   - To enforce immutability, most compilers store string literals in a read-only segment of memory.
```c
char *ptr = "Linux";
// Memory layout (string in read-only memory):
+----+----+----+----+----+----+
|'L'| 'i'| 'n'| 'u'| 'x'| '\0'|
+----+----+----+----+----+----+
 ^ (modifiable address, ptr)
ptr can move to the next character, e.g., ptr++.
```
- Here string is immutable because string literal that is stored in read only memory section, the address of that has been assigned to p.
- for Declaration of `char str[]` format during initialization:
>The contents of the string literal "Hello" are copied from the read-only memory into the array str, which is allocated in local writable memory (typically on the stack for local variables or in writable memory for globals).
- After the initialization, str is completely independent of the string literal "Hello". The string literal remains in read-only memory, but str exists in writable memory and can be modified freely.
- The string literal remains constant and unchanged in read-only memory, while the array str resides in writable memory.

#### Comparison: String Literal assigned to Char * vs. string literal assigned to char str[] 

| Case                              | Memory Location        | Modifiable? | Explanation                                                                 |
|-----------------------------------|------------------------|-------------|-----------------------------------------------------------------------------|
| `char *ptr = "Linux";`            | Read-only memory       | No          | `ptr` points to the immutable string literal in read-only memory.          |
| `char str[] = "Linux";`           | Writable memory (stack)| Yes         | `"Linux"` is copied into a writable local array (`str`).                   |

#### The Standard Defines This Behavior

1. **String Literals**:
   - Are stored in an implementation-defined, static memory area (usually read-only memory).
   - Modifying a string literal results in undefined behavior.

2. **Arrays Initialized with String Literals**:
   - The array is treated as a completely independent block of memory.
   - The string literal is used only to **initialize** the array, and a **copy** of its content is created in writable memory.

#### Difference Between constant pointer to a string & pointer to a constant string

| Feature                     | `char str[6] = "Linux";`            | `char *ptr = "Linux";`                |
|-----------------------------|-------------------------------------|---------------------------------------|
| **Storage**                 | Array stores the string in local memory. | Pointer points to a string literal in read-only memory. |
| **Modifiable Contents?**    | Yes, the array contents are modifiable. | No, string literal is read-only.      |
| **Pointer Behavior**        | Array name is a constant pointer.   | Pointer is a modifiable variable.     |
| **Pointer Arithmetic?**     | `str++` is invalid.                 | `ptr++` is valid.                     |

#### Comparison Table

| Declaration                      | Description                                       | Modifiable Contents? | Pointer Modifiable? |
|----------------------------------|---------------------------------------------------|-----------------------|----------------------|
| `char *ptr = "Linux";`           | Pointer to string literal (read-only memory).     | No                    | Yes                  |
| `const char *ptr = "Linux";`     | Pointer to a constant string literal.             | No                    | Yes                  |
| `char str[] = "Linux";`          | Modifiable local array initialized with "Linux".  | Yes                   | No (array name).     |
| `char *const ptr = "Linux";`     | Constant pointer to string literal.               | No                    | No                  |

>6.7.11 Initialization N3220 [2024-02-22] (early C2y draft)
![image](https://github.com/user-attachments/assets/fae28d16-1335-421e-8410-2df0692adada)

![image](https://github.com/user-attachments/assets/a46d3a96-de8e-40d1-a328-b2ff4b838222)
