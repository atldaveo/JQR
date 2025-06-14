# Issue 84: Describe the purpose of the following registers

## General Purpose Registers
Registers are primitive components of computer architecture built directly into hardware that holds operands for arithmetic instructions (in assembly). Modern computers typically contain 32 64-bit registers, 8 of which are GPRs. General Purpose Registers (GPR) are specifically designed to hold addresses or data (operands and pointers).
(Patterson 2017)   

## EIP (Execution Instruction Pointer) Register
The 32-bit EIP register contains the address to the next instruction to be executed (Intel Corporation 2024).

## EFLAGS (Program Status and Control) Register
The 32-bit EFLAGS Register reports on the satus of the program being executed and allows limited (application-program level) control of the processor (Intel Corporation 2024).

## Works Cited
Intel Corporation. 2024. Intel 64 and IA-32 architectures software developer's manual. Santa Clara (CA): Intel Corporation. Available from: https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html

Patterson DA, Hennessy JL. Computer Organization and Design. Elsevier: Cambridge; 2017.