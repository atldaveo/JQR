# Issue 88: Describe the following calling conventions

## cdecl (C Declaration)
- Default calling convention for C and C++ programs
- Function parameters are pushed onto stack in reverse (right-to-left)
- Caller is responsible for cleaning the stack after function call
- _ is prefixed to function names for decoration unless C linkage is exported

## stdcall
- Used to call Win32 API functions
- Callee is responsible for cleaning the stack
- Function parameters are pushed onto stack right-to-left
- Argument is passed by value (except for ptrs and reference)
- Decorated with _ prefix followed by @ and number of bytes (in decimal)
-- `int func(int a, double b)` is decorated as `_func@12` 

## fastcall
- Arguments to functions are to be passed in registers when possible
- Only applies to x86 architecture
- First two `DWORD` or smaller arguments are passed in ECX and EDX from left to right
-- All else passed on stack right to left
- Called function is responsible for cleaning the stack
- Classes, structs, and unions are treated as multi-byte types and passed on the stack

## Works Cited
Microsoft Contributors. Calling Conventions. [Internet]. Microsoft Corporation; 2021 Aug 2. Available from: https://learn.microsoft.com/en-us/cpp/cpp/calling-conventions?view=msvc-170