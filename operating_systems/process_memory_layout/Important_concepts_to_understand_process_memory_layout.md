### Virtual memory

[Reference](https://medium.com/@breakpoint.tutorials/memory-organization-of-a-c-program-a32417e91f5b#:~:text=We%20can%20see%20these%20addresses,did%2C%20please%20share%20it%20:%2D))

- abstraction of a concept hides the details on what goes on actually under the hood
- Virtual memory is a memory management technique that provides an “idealized abstraction of the storage resources 
  that are actually available on a given machine which “creates the illusion to users of a very large (main) memory.(from wiki)
- The OS abstracts these details, so that a process does not have to deal with the complex task of sharing memory with other processes.
    - Why we need virtual memory ?
        - operating system has to manage the memory allocations of multiple processes seamlessly.
        - Operating systems support concurrent execution of programs by scheduling different processes in time and at any point in time, 
          only one process can be running (on a single core CPU).
- Each running process in linux, gets its own virtual address space or virtual memory and this is huge (128 TB for 64 bit)
    - WHich is far beyond the physical address space usualyy 8/16 GB.

why 128 TB for 64 bit ?

Characteristic | 32-bit | 64-bit (x86-64 canonical)
-- | -- | --
Pointer width | 32 bits → 4 bytes | 64 bits → 8 bytes
Theoretical VAS | 2322^{32}232 addresses = 4 GiB | 2642^{64}264 addresses = 16 EiB
Byte vs. word addressable | byte-addressable (1 address = 1 byte) | byte-addressable (same)
Typical OS limit | full 2^32 used → 4 GiB | only lower 47 bits used → 2^47 = 128 TiB
| SI vs. binary units | 32-bit: 4 GiB = 4 × 2³⁰ B ≈ 4.29 × 10⁹ B (≈ 4.29 GB) | 64-bit: 128 TiB = 128 × 2⁴⁰ B ≈ 1.41 × 10¹⁴ B (≈ 140 TB) |
User vs. kernel split | often 3 GiB user / 1 GiB kernel | often 47 bits user (128 TiB) / 17 bits kernel
Practical mapped span | up to 0x0000 0000–0xFFFF FFFF | up to 0x0000 0000 0000–0x7FFF FFFF FFFF
Executable layout | code/.data/.bss/heap/stack within 4 GiB | same segments in a 128 TiB arena
Implications | – pointer arithmetic wraps at 4 GiB – easy to exhaust VA with large mappings | – effectively “infinite” today– sparse maps with huge gaps– very low risk of VA exhaustion

```bash
# for 32 bit machines
- A 32-bit register can hold any integer from 0 up to 2³²−1.
- Because the machine is byte-addressable, each of those integers is interpreted as the address of one byte in memory.
- Thus you have 2³² possible byte-addresses → you can label (and therefore access) 2³² bytes = 4 GiB of memory.
- Total 2³² addresses → 2³² bytes → 4 GiB memory addressable.

# for 64 bit machines
4-level page tables:
x86-64 virtual addresses are broken into

- 4 sets of 9 bits for page-table indices (P4, P3, P2, P1) → 4×9=36 bits
- 12 bits for the page-offset 36+12=48 So only bits 0–47 actually select pages in hardware.

Canonical addressing rule:
- Bits 48–63 of a valid user-mode pointer must all equal bit 47 (sign-extension).
- If bit 47=0 → bits 48–63=0 → valid range 0x0000_0000_0000_0000 to 0x0000_7FFF_FFFF_FFFF
- If bit 47=1 → bits 48–63=1 → kernel space (not user-accessible)

Resulting user-mode span:
Only the “lower half” (bit 47=0) is used by user processes, giving = 128TiB of user-mode virtual address space.

64-bit register:  [63.........................0]
Theoretical:      any 0…2^64−1

Hardware uses:  [47.....0]  ← 48 bits for page tables
Canonical rule: bits 63…48 = bit 47

User addresses: 0x0000_0000_0000_0000 … 0x0000_7FFF_FFFF_FFFF
                (2^47 bytes = 128 TiB)
```
Consider the following example for dbus daemon process running in a 64 bit linux machine:
```bash
$ sudo pmap -x 182
182:   @dbus-daemon --system --address=systemd: --nofork --nopidfile --systemd-activation --syslog-only
Address           Kbytes     RSS   Dirty Mode  Mapping
000055a0e46da000      36      36       0 r---- dbus-daemon
...
00007ffc6d262000     132      40      40 rw---   [ stack ]
00007ffc6d39d000      16       0       0 r----   [ anon ]
00007ffc6d3a1000       8       4       0 r-x--   [ anon ]
---------------- ------- ------- -------
total kB            8788    5068     900

# 8788 kB is the total virtual memory you have mapped (the sum of all VMAs).
# 5068 kB is the subset of those pages that are resident in RAM at this moment.
# 900 kB of that resident memory has been dirtied (modified) and would need to be written back if it were to be paged out.
```
- When a process is running, it accesses memory locations using variables and pointers and function calls.

Q: Who prepares the VA space, how creates VA details is it the executable ?, what is the role of OS in VA space ?
Q: how process communicate if all of them have their own VA space ?

### Page, Page Table

[Reference](https://medium.com/@breakpoint.tutorials/memory-organization-of-a-c-program-a32417e91f5b#:~:text=We%20can%20see%20these%20addresses,did%2C%20please%20share%20it%20:%2D))

- For translating the virtual address to physical address The OS uses page tables and TLBs (transaltion lookaside buffer) to manage this translation.
- reality the memory is divided into pages and the mapping is stored for each page and not for each address.
    - In Linux (and most OSes), memory is divided into fixed-size chunks called pages. (A 4 KiB chunk of actual memory (RAM))
    - A page table is a data structure used by the operating system (and CPU) to keep track of where each page is.
>Pages are like rooms in a hotel.
The Page Table is like the hotel reception desk that tells you:
"Your room (physical page) is on floor 3, room 42."

### Memory Sandbox

[Reference](https://gabrieletolomei.wordpress.com/miscellanea/operating-systems/in-memory-layout/)

- Each process in a multitasking OS runs in its own memory sandbox. This is the virtual address space
- the term sandbox (you can do anything you want in the sandbox, it will not harm the outside process/OS system).
- https://gabrieletolomei.wordpress.com/miscellanea/operating-systems/virtual-memory-paging-and-swapping/

### local variables are reclaimed in the block scope they are initialized in

Reclaimed = Available for Reuse
- The bytes aren’t zeroed or erased; they simply aren’t “owned” by your function any more.
- The next time you call any function, or push data onto the stack, the CPU will use that reclaimed region.
- suppose int (declared local to foo()) takes 4 bytes from 0x01 - 0x03, this is occupied till foo completes it's execution.
- When control exits the block, it moves the stack pointer back up, “reclaiming” that space.

Why it matters
- Safety: You can’t accidentally read or write a variable after its block ends (the compiler will reject it).
- Efficiency: The stack pointer arithmetic is cheap, so creating and destroying locals this way is very fast.
- Undefined Behavior: If you somehow keep a pointer to that reclaimed space (e.g. by returning &a), using it later is undefined behavior—your program might crash or give garbage.

### Difference between naked function and normal function

- sometimes called a “no-prologue/epilogue” function) is one for which the compiler emits no automatic stack-frame setup or teardown. 
- In other words, it omits the usual function prologue/epilogue, leaving all register saves, stack adjustments, and return logic entirely 
  up to you.

Feature | Normal Function | Naked Function
-- | -- | --
Prologue | push ebp; mov ebp, esp; sub esp, … | None
Epilogue | add esp, …; pop ebp; ret | None
Local-variable space | Compiler reserves it automatically | You must allocate on stack
Register saving | Caller- or callee-save per ABI | You must push/pop manually
Stack/frame pointer | Consistent RBP/EBP-based addressing | No guaranteed frame pointer
Mixing C and asm | Allowed (with limitations) | Not allowed—only asm in body
