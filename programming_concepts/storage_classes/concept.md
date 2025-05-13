The concept of storage class allows one to understand the properties of a variable which is declared in source code,
The properties are:

* **Default value of variable**: value if you don’t explicitly initialize.
* **Scope of variable**: where in the source code/functions the name is visible.
* **Storage Duration (lifetime of a variable)**: lifetime of the object (automatic, static, thread, or dynamic via `malloc`).
* **Linkage**: whether multiple declarations refer to the same object (`none`, `internal`, `external`).
* **Where is the variable stored**: memory or CPU registers ?

There are 4 storage classes in C,

**Automatic**
- 
* static
* register
* extern

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

| Position                  | Scope | Linkage          | Lifetime        | Typical Use                                   |
| ------------------------- | ----- | ---------------- | --------------- | --------------------------------------------- |
| `static` in function      | Block | None             | Static duration | Preserve state across function calls          |
| `static` outside function | File  | Internal linkage | Static duration | Limit variable or function visibility to file |

### Linkage

Linkage refers to the ability of an identifier (variable or function) to be referred to in other scopes. If a variable or function with the same identifier is declared in several scopes, but cannot be referred to from all of them, then several instances of the variable are generated. The following linkages are recognized:

**no linkage.** The variable or function can be referred to only from the scope it is in (block scope). All block scope variables that are not declared extern have this linkage, as well as all function parameters and all identifiers that aren't functions or variables.

**internal linkage**. The variable or function can be referred to from all scopes in the current translation unit. All file scope variables which are declared static or constexpr(since C23) have this linkage, and all file scope functions declared static (static function declarations are only allowed at file scope).

**external linkage**. The variable or function can be referred to from any other translation units in the entire program. All file scope variables which are not declared static or constexpr(since C23) have this linkage, all file scope function declarations which are not declared static, all block scope function declarations, and, additionally, all variables or functions declared extern have this linkage unless a prior declaration with internal linkage is visible at that point.

### Storage duration

Every object has a property called storage duration, which limits the object lifetime. There are four kinds of storage duration in C:

**automatic storage duration.** The storage is allocated when the block in which the object was declared is entered and deallocated when it is exited by any means (goto, return, reaching the end). One exception is the VLAs; their storage is allocated when the declaration is executed, not on block entry, and deallocated when the declaration goes out of scope, not when the block is exited(since C99). If the block is entered recursively, a new allocation is performed for every recursion level. All function parameters and non-static block-scope objects have this storage duration, as well as compound literals used at block scope(until C23)

**static storage duration.** The storage duration is the entire execution of the program, and the value stored in the object is initialized only once, prior to main function. All objects declared static and all objects with either internal or external linkage that aren't declared _Thread_local(until C23)thread_local(since C23)(since C11) have this storage duration.

**thread storage duration.** The storage duration is the entire execution of the thread in which it was created, and the value stored in the object is initialized when the thread is started. Each thread has its own, distinct, object. If the thread that executes the expression that accesses this object is not the thread that executed its initialization, the behavior is implementation-defined. All objects declared _Thread_local(until C23)thread_local(since C23) have this storage duration.

**allocated storage duration.** The storage is allocated and deallocated on request, using dynamic memory allocation functions.

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
