# Some reminders for architectures compliant with System V ABI
##### 0.99.7

- Registers %rbp, %rbx and %r12 through %r15 "belong" to the calling function.
- UNCERTAIN: %rsp "belong" to the calling function.
- Stack must be 8 bytes aligned
- Functions parameters integers order: %rdi, %rsi, %rdx, %rcx, %r8, %r9, then passed on the stack
- Syscall parameters integers order: %rdi, %rsi, %rdx, %r10, %r8, %r9
- On syscall, %rcx and %r11 are destroyed
- When syscall returns negative value, it is -errno

- Page size is from 4KB to 64KB.
- Virtual address space has 48-bit address, from 0x0000000000000000 to 0x00007fffffffffff.
- 0x0008000000000000 to 0xffffffffffffffff is for system and dynamic segments.
- By convention, 0x0 to 0x0000000000400000 is unmapped, then text segments, data segments, heap, stack.
