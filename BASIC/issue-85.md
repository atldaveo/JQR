# Issue 85: Describe the difference in registers between x86 and x64

## x86
- x86 architectures contain 8 GPRs (each 32 bits wide) 
- Utilizes an 32-bit EIP
- EFLAGS registers store execution condition / control flags 
- Function arguments are primarily executed in the stack

(Intel Corporation 2024)

## x64
- 64-bit architecture. 16 GPRs (Each 64 bits wide)
- Utilizes a 64-bit RIP (same function as a EIP in x86)
- Uses RFLAGS (64-bit) instead of EFLAGS
- First few function arguments occur in dedicated registers (extra GPRs) as to improve performance

(AMD 2024)

## Works Cited
AMD. 2024. AMD64 Architecture Programmer’s Manual Volume 2: System Programming. Sunnyvale (CA): Advanced Micro Devices. Available from: https://www.amd.com/content/dam/amd/en/documents/processor-tech-docs/programmer-references/24593.pdf

Intel Corporation. 2024. Intel 64 and IA-32 architectures software developer's manual. Santa Clara (CA): Intel Corporation. Available from: https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html