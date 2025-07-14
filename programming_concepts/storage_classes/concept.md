The concept of storage class allows one to understand the properties of a variable which is declared in source code,
The properties are:

* **Default value of variable**: value if you don’t explicitly initialize.
* **Scope of variable**: where in the source code/functions the name is visible.
* **Storage Duration (lifetime of a variable)**: lifetime of the object (automatic, static, thread, or dynamic via `malloc`).
* **Linkage**: whether multiple declarations refer to the same object (`none`, `internal`, `external`).
* **Where is the variable stored**: memory or CPU registers ?

There are 4 storage classes in C,

* **Automatic**
* **static**
* **register**
* **extern**

https://en.cppreference.com/w/c/language/storage_duration (reference from which the below document was prepared)
https://medium.com/@ganga.jaiswal/scope-and-storage-of-variables-in-c-programming-f372f32dad78

Here’s a consolidated overview of C’s storage classes in tabular form:

| Keyword           | Storage Duration          | Scope         | Linkage              | Default Initialization      | Typical Use / Notes                                                         |
| ----------------- | ------------------------- | ------------- | -------------------- | --------------------------- | --------------------------------------------------------------------------- |
| `auto` (implicit) | Automatic (block)         | Block (local) | None                 | **Indeterminate**           | Default for local variables. Rarely written explicitly.                     |
| `register`        | Automatic (block)         | Block (local) | None                 | **Indeterminate**           | Hint to keep in CPU register (mostly ignored by modern compilers).          |
| `static` (block)  | Static (program-lifetime) | Block (local) | None                 | Zero (if uninitialized)     | Retains value across function calls; useful for counters, memoization.      |
| `static` (file)   | Static (program-lifetime) | File (global) | Internal (within TU) | Zero (if uninitialized)     | Limits symbol to one translation unit—encapsulation in multi-file programs. |
| `extern`          | Static (program-lifetime) | File (global) | External (cross-TU)  | **None** (declaration only) | Declares a global defined elsewhere; used in headers for shared globals.    |
| `_Thread_local`   | Thread (per-thread)       | Block or file | Internal or External | Zero (if uninitialized)     | C11 feature for thread-specific data.                                       |

- **Indeterminate**: it’s undefined behavior to use it. Anything could happen: on one run it might look like zero, on another it might be “random” garbage
- `static (block)`, Modifying the block‐scope static variable only changes that local instance; all other references resolve to the file‐scope static object, whose value remains unchanged. (look at `f()` in static_storage_class.c)
- `extern` here, for initialization, if it has the variable defined (int x = 1 in some.c then value of that variable will be 1), if int x; is left uninitialized then the value was observed to be 0 when compiled, check extern_definition.c for more clarification.
- If no storage-class specifier is provided, the defaults are:
  - extern for all functions
  - extern for objects at file scope
  - auto for objects at block scope
- For declarations of pointer type `int *p;`,
  - `int *p;` is an invalid memory location, using %d to access it causes seg fault & using %p it prints out NIL.
  - it is only valid if it's allocated memory through malloc, calloc or defined using a int value.

| Position                  | Scope | Linkage          | Lifetime        | Typical Use                                   |
| ------------------------- | ----- | ---------------- | --------------- | --------------------------------------------- |
| `static` in function      | Block | None             | Static duration | Preserve state across function calls          |
| `static` outside function | File  | Internal linkage | Static duration | Limit variable or function visibility to file |

Here’s a compact table showing the key combinations of **scope**, **storage duration**, and **linkage** in C, with examples and where each name is visible:

| Scope              | Storage Duration | Linkage  | Example                                  | Visibility                                      |
| ------------------ | ---------------- | -------- | ---------------------------------------- | ----------------------------------------------- |
| **File-scope**     | Static           | Internal | `static int counter = 0;`                | All functions in **this** .c file               |
| **File-scope**     | Static           | External | `int global_var = 1;`                    | Every translation unit (via `extern`)           |
| **Block-scope**    | Automatic        | None     | `void f(){ int x; /* … */ }`             | Only inside that `{ … }`                        |
| **Block-scope**    | Static           | None     | `void f(){ static int y; /* … */ }`      | Only inside that `{ … }`, persists across calls |
| **Function param** | Automatic        | None     | `void g(int p)`                          | Only inside `g`                                 |
| **Allocated**      | Dynamic          | None     | `int *p = malloc(...);`                  | From malloc until free; name as a pointer var   |
| **File-scope**     | Thread           | External | `_Thread_local int t;`                   | All TUs (one per thread)                        |
| **File-scope**     | Thread           | Internal | `static _Thread_local int t;`            | This TU only (one per thread)                   |

* **Scope** is *where* in the source code the name is visible.
* **Storage duration** is *how long* the object lives in memory.
* **Linkage** is *whether* and *how* the same name refers to the same object across scopes or translation units.

Great question — **linkage** and **scope** are closely related but fundamentally different concepts in C. Let’s break them down clearly:

---

### 🔑 Key Differences Between Linkage and Scope

| Concept             | **Scope**                                                                              | **Linkage**                                                                                                          |
| ------------------- | -------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| **Definition**      | The *region of the program* where an identifier (name) is **visible** and can be used. | Describes whether the **name refers to the same entity** across different parts (translation units) of a program.    |
| **Concerns**        | *Where* you can **use** a name.                                                        | *Whether* a name refers to the **same object/function** across scopes/files.                                         |
| **Types**           | - Block scope<br>- Function prototype scope<br>- File scope                            | - No linkage<br>- Internal linkage<br>- External linkage                                                             |
| **Example**         | `int x = 5;` inside a function is **block scope** — can’t be used outside.             | `int x = 5;` at file scope has **external linkage** by default — can be accessed in other `.c` files using `extern`. |
| **When it applies** | All identifiers (variables, functions, typedefs, structs, etc.).                       | Only to **variables and functions**, not types, typedefs, labels, or parameters.                                     |
| **Controlled by**   | Where the name is declared.                                                            | Storage class specifiers like `static`, `extern`.                                                                    |

### Linkage

Linkage refers to the ability of an identifier (variable or function) to be referred to in other scopes. If a variable or function with the same identifier is declared in several scopes, but cannot be referred to from all of them, then several instances of the variable are generated. The following linkages are recognized:

**no linkage.** The variable or function can be referred to only from the scope it is in (block scope). All block scope variables that are not declared extern have this linkage, as well as all function parameters and all identifiers that aren't functions or variables.

**internal linkage**. The variable or function can be referred to from all scopes in the current translation unit. All file scope variables which are declared static or constexpr(since C23) have this linkage, and all file scope functions declared static (static function declarations are only allowed at file scope).

**external linkage**. The variable or function can be referred to from any other translation units in the entire program. All file scope variables which are not declared static or constexpr(since C23) have this linkage, all file scope function declarations which are not declared static, all block scope function declarations, and, additionally, all variables or functions declared extern have this linkage unless a prior declaration with internal linkage is visible at that point.

Understanding different translation units: https://stackoverflow.com/questions/79620220/understanding-different-translation-units-in-c-the-meaning

### Storage duration

Every object has a property called storage duration, which limits the object lifetime. There are four kinds of storage duration in C:

**automatic storage duration.** The storage is allocated when the block in which the object was declared is entered and deallocated when it is exited by any means (goto, return, reaching the end). One exception is the VLAs; their storage is allocated when the declaration is executed, not on block entry, and deallocated when the declaration goes out of scope, not when the block is exited(since C99). If the block is entered recursively, a new allocation is performed for every recursion level. All function parameters and non-static block-scope objects have this storage duration, as well as compound literals used at block scope(until C23)

**static storage duration.** The storage duration is the entire execution of the program, and the value stored in the object is initialized only once, prior to main function. All objects declared static and all objects with either internal or external linkage that aren't declared _Thread_local(until C23)thread_local(since C23)(since C11) have this storage duration.

**thread storage duration.** The storage duration is the entire execution of the thread in which it was created, and the value stored in the object is initialized when the thread is started. Each thread has its own, distinct, object. If the thread that executes the expression that accesses this object is not the thread that executed its initialization, the behavior is implementation-defined. All objects declared _Thread_local(until C23)thread_local(since C23) have this storage duration.

**allocated storage duration.** The storage is allocated and deallocated on request, using dynamic memory allocation functions.

### Scope 

C has four kinds of scopes:
- block scope
    - The scope of any identifier declared inside a {}, including function bodies, or in any expression, declaration, or statement 
      appearing in if, switch, for, while, or do-while statement(since C99), or within the parameter list of a function definition 
      begins at the point of declaration and ends at the end of the block or statement in which it was declared.
- file scope
    - The scope of any identifier declared outside of any block or parameter list begins at the point of declaration and ends at 
      the end of the translation unit.
- function scope
- function prototype scope

more details here: https://en.cppreference.com/w/c/language/scope

### C translation unit

https://stackoverflow.com/questions/42262802/what-exactly-is-a-translation-unit-in-c

In C, a **translation unit** is the basic unit of compilation.  More precisely:

**Definition**
A source file together with all the headers and source files included via the preprocessing directive #include is known as a preprocessing translation unit. After preprocessing, a preprocessing translation unit is called a translation unit.

the .i file you get is exactly the translation unit for foo.c. It contains:
- All headers inlined at each #include
- All macros expanded
- All conditional‐compilation directives resolved
- Comments stripped

### Questions:

>Q: function parameters cannot be declared with most storage class specifiers such as: auto, static, extern, register

Note: Only register was historically allowed (in C89/C90), but even that is deprecated and removed in modern C standards (C11 and onwards)compilers ignore `register`, and you should avoid using it in new code.

#### 💡 Why are storage classes disallowed in parameters?

Because **function parameters already have automatic storage duration** — they live on the stack during the function call — so there’s no need (or meaning) to declare them as `auto` or `static`. Here's why:

* `auto`: Default for local variables and parameters — redundant.
* `register`: Hint, but no longer meaningful.
* `static`: Implies persistence across calls — not applicable to parameters.
* `extern`: Meant for external linkage — parameters are not externally linked.

>Q: Why you cannot specify storage class to the memeber of structs

**you cannot** use storage-class specifiers on members inside a `struct` (or `union`) definition. Storage-class specifiers like `static`, `extern`, `auto`, and `register` apply to variable (or function) declarations, not to type members. 

Here’s why:

2. **Members aren’t objects yet**
   When you write

   ```c
   struct S {
       int a;
       /* static int b; */  // ❌ invalid
   };
   ```

   you’re only *describing* the layout of a type. No actual object of type `struct S` exists until you declare a variable of that type. At that point, you apply storage-class rules to the *variable*, not to the members.

3. **How to control member storage**

   * The *entire* struct object’s storage duration and linkage are determined by how you declare the variable:

     ```c
     static struct S s1;    // s1 has static storage duration, internal linkage
     struct S s2;           // s2 has automatic storage duration, no linkage
     extern struct S s3;    // s3 has static duration, external linkage
     ```
   * You cannot, for instance, make one member live longer than another inside the same object.

**In summary:**

* Storage-class specifiers belong on the *declaration* of a variable (or function), not on individual fields of a `struct`.
* All members of a given struct instance share the same storage duration and linkage as the struct object itself.

### Meaning of explicit vs implicit in programming 

explicit" means the programmer directly specifies the data type of a variable or other entity. 
"Implicit" means the compiler infers the data type based on the context or the value being assigned.

### Scalar (return type) from a function.

```c
foo(int c) {
  return c + 1;
}
/* c is created locally on stack,
 * if it's return value is used to compute in a expression

what is the return value ? is it lost becuase the program counter 
returns to main ? (since variable was created on stack)
*/
```
- **“If a function returns a scalar type** like int or float, the value is typically returned 
via a CPU register (like eax or rax). 
- So even if it's computed from a local variable stored on the stack, the value itself is passed 
  through a register — not the stack. 
- That’s why returning a scalar value is safe, and it doesn’t matter that its origin was on the stack.
- The returned value won’t be affected after the function exits."

| Return Value Type                                              | Mechanism                                                   | Remains Valid After Return? | Notes                                                                                                       |
| -------------------------------------------------------------- | ----------------------------------------------------------- | --------------------------- | ----------------------------------------------------------------------------------------------------------- |
| **Scalar types**<br/>(e.g. `int`, `float`, `double`, pointers) | Copied into a CPU register (e.g. `EAX`/`RAX`, `XMM0`, etc.) | ✔ Yes                       | Always safe. The value lives in a register, independent of the callee’s stack frame.                        |
| **Struct/union (by value)**                                    | Returned in registers or via caller-allocated space         | ✔ Yes                       | The ABI handles copying all bytes back. Even large structs may use a hidden pointer to space in the caller. |
| **Pointer to local (stack) variable**                          | Pointer to memory in the callee’s stack                     | ✘ No                        | The stack frame is destroyed on return → pointer becomes dangling.                                          |
| **Pointer to static variable**                                 | Pointer to data in static storage                           | ✔ Yes                       | Static data persists for the program’s lifetime.                                                            |
| **Pointer to heap (malloc’d) memory**                          | Pointer to dynamically allocated memory                     | ✔ Yes                       | The memory remains allocated until explicitly freed.                                                        |
| **Pointer to function-local array**                            | Array decays to pointer                                     | ✘ No                        | Same as “pointer to local”: array is on the stack, so pointer dangles.                                      |
| **Array by value**<br/>(e.g. `int foo()[N]`)                   | **Not allowed** in C                                        | —                           | C does not support returning arrays by value.                                                               |
| **Pointer to global variable**                                 | Pointer to data in global storage                           | ✔ Yes                       | Global data persists for the program’s lifetime.                                                            |
