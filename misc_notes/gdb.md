## Notes for GDB

### Contents
- [How to use printf in GDB](#how-to-use-printf-in-gdb)

### [How to use printf in GDB](#how-to-use-printf-in-gdb)

You can use `printf` in GDB to print formatted output while debugging your program. This is useful for inspecting variables, expressions, or memory contents in a controlled format.

Here's how to use `printf` in GDB:

#### Basic Syntax:
```gdb
printf "format string", [arguments]
```

#### Examples:

#### 1. Printing Simple Values:
```gdb
(gdb) print some_variable          # Simple print
(gdb) printf "Value: %d\n", some_variable
```

#### 2. Printing Strings:
```gdb
(gdb) printf "String value: %s\n", some_string
```

#### 3. Printing Pointers:
```gdb
(gdb) printf "Pointer address: %p\n", some_pointer
```

#### 4. Printing Memory Content:
To print the content at a memory address:
```gdb
(gdb) printf "Memory content: %d\n", *((int *) 0xaddress)
```

#### 5. Printing an Array:
To print the elements of an array:
```gdb
(gdb) printf "Array[0]: %d, Array[1]: %d\n", array[0], array[1]
```

#### 6. Using Expressions:
You can also use expressions within `printf`:
```gdb
(gdb) printf "Sum: %d\n", some_variable + 10
```

#### Additional Tips:
- **String formatting:** GDB follows the standard C `printf` format specifiers (`%d`, `%f`, `%s`, `%p`, etc.).
- **Escape sequences:** You can use `\n` for a newline or `\t` for a tab.
- **Evaluate complex expressions:** Combine variables and calculations for detailed debugging.

---

#### Example Debugging Session:
1. **Start GDB and set a breakpoint:**
   ```bash
   gdb ./my_program
   (gdb) break main
   (gdb) run
   ```

2. **Inspect a variable with `printf`:**
   ```gdb
   (gdb) printf "Variable x: %d\n", x
   ```

3. **Continue execution:**
   ```gdb
   (gdb) continue
   ```
This approach helps you format the output more precisely than the default `print` command in GDB.
