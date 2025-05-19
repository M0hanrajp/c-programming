In C, a function call is not just a high-level jump to some named block of code; it involves a well-defined protocol—often called the **calling convention**—that governs how arguments are passed, how the return address and local state are managed, and which registers (if any) must be preserved by caller or callee. Below is a step-by-step walkthrough of what happens, taking the classic **cdecl** convention on an x86 (32-bit) platform as our primary example. Many principles carry over to x86\_64 (SysV AMD64), ARM, etc., with differences noted where relevant.

---

## 1. Compiler’s View: Generating the Call Site

When you write in C:

```c
int foo(int a, int b) {
    return a + b;
}

int main() {
    int x = foo(2, 3);
    // …
}
```

the compiler turns the call `foo(2,3)` roughly into this sequence of instructions:

1. **Evaluate and push arguments**

   * `push 3`
   * `push 2`
2. **Call instruction**

   * `call foo`
3. **Cleanup (caller‐side)**

   * `add  esp, 8`    ; remove the two 4-byte arguments from the stack
4. **Use return value**

   * usually in `EAX` (per convention)

> **Note**: In some conventions (e.g., stdcall), callee cleans up the arguments.

---

## 2. Stack Layout at the Moment of `call`

Immediately after the CPU executes `call foo`, the stack (growing downward) looks like this:

```
          +-----------------+
 low addr |  return value?  |  ; unused until foo returns
          +-----------------+
          |   arg #2 (3)    |  <- ESP_old - 4
          +-----------------+
          |   arg #1 (2)    |  <- ESP_old
          +-----------------+
          | return address  |  ; pushed by CALL
          +-----------------+ <- ESP (new)
          |   old EBP       |  ; not yet; set by callee prologue
          +-----------------+
```

1. **Arguments** are pushed right‐to‐left (`b` then `a`).
2. The CPU’s `call` instruction does two things atomically:

   * **Push** the *address of the next instruction* (the return address) onto the stack.
   * **Jump** to the entry point of `foo`.

---

## 3. Function Prologue: Setting Up the Stack Frame

At the first few instructions of `foo`, the compiler emits a *prologue* to establish a new **stack frame** (a.k.a. “activation record”):

```asm
foo:
    push ebp            ; save caller’s frame pointer
    mov  ebp, esp       ; set up new frame pointer
    sub  esp, N         ; allocate space for locals and spilled regs
    ; now [ebp+8] is a, [ebp+12] is b
```

* **`push ebp`** preserves the caller’s frame pointer.
* **`mov ebp, esp`** makes the current stack pointer the base of this frame.
* **`sub esp, N`** reserves space for local variables, temporary storage, and saved registers.

On **x86\_64 SysV**, by contrast, the first six integer/pointer arguments go in registers (`RDI`, `RSI`, `RDX`, `RCX`, `R8`, `R9`), so no pushes; registers that callee wants to preserve go on the stack in the prologue.

---

## 4. Accessing Arguments and Locals

Within the body of `foo`, the layout relative to `EBP` is:

```
[ EBP + 8 ]    →  first argument (`a`)
[ EBP + 12 ]   →  second argument (`b`)
[ EBP ]        →  old EBP (saved)
[ EBP – 4 ]    →  first local (if any)
[ EBP – 8 ]    →  second local, etc.
```

Reading or writing a local or argument becomes a simple memory access with a constant offset.

---

## 5. The Function Body and Return

Suppose `foo` is simple:

```asm
    mov eax, [ebp+8]    ; load a into EAX
    add eax, [ebp+12]   ; add b
    ; result in EAX
```

* **Return value** is conventionally placed in `EAX` (x86) or `RAX` (x86\_64).

---

## 6. Function Epilogue: Tearing Down the Frame

Right before returning, the compiler emits an *epilogue* mirroring the prologue:

```asm
    mov  esp, ebp     ; deallocate locals
    pop  ebp          ; restore caller’s frame pointer
    ret               ; pop return address into EIP, jump there
```

* **`mov esp, ebp`** resets the stack pointer.
* **`pop ebp`** restores the old frame pointer.
* **`ret`** pops the return address into the instruction pointer (EIP/RIP), resuming execution in the caller.

If using a callee‐cleanup convention (stdcall), the `ret` can be `ret 8` which also adjusts `ESP` to drop the arguments in one go.

---

## 7. Caller Resumes

Back in `main`, after `call foo` returns:

```asm
add esp, 8        ; [cdecl] clean up the two arguments
mov [ebp-4], eax  ; store return value into local x
```

Now `main` continues, with its previous stack frame intact.

---

## 8. Variations & Modern Calling Conventions

* **x86\_64 SysV (Linux/macOS)**

  * First six integer args: `RDI`, `RSI`, `RDX`, `RCX`, `R8`, `R9`
  * Return in `RAX` (and `RDX` if 128-bit)
  * Caller saves: `RAX, RCX, RDX, RSI, RDI, R8–R11`
  * Callee saves: `RBX, RBP, R12–R15`

* **Microsoft x64**

  * First four args: `RCX, RDX, R8, R9`
  * Home space (32 bytes) reserved on stack for shadowing those regs

* **ARM (AArch64)**

  * First eight args: `X0–X7`
  * Return in `X0` (and `X1` for larger)
  * Similar preserved vs. volatile register sets

Each architecture defines its own prologue/epilogue idioms in assembler.

---

## 9. Summary of the Underlying Mechanism

1. **Argument evaluation & placement** (stack or registers)
2. **`call` instruction** pushes return address and jumps
3. **Callee prologue** sets up stack/frame pointer, saves necessary registers
4. **Function body** executes, uses `[EBP+offset]` or registers for args/locals
5. **Return value** placed in a designated register
6. **Callee epilogue** tears down frame, restores registers
7. **`ret` instruction** pops return address, jumps back
8. **Caller cleanup** (if required) and resumption

This protocol ensures **reentrancy**, **nesting** (recursive calls), and **interoperability** between separately compiled modules. Understanding it at the assembly level is crucial for low-level debugging, interfacing with other languages, and grasping performance implications of argument passing and register usage.
