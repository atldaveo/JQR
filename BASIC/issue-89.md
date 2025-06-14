# Issue 89: Describe purpose and use of foundational RE mechanics

## Disassembler
A disassembler performs the inverse role of a traditional assembler. The disassembler translates machine language into a human-readable assembly language. Using a disassebler allows its user to take binary information from a computer and potentially surmise the function of that binary by inferring the executability and function of that binary. However, modern computing systems are difficult to perform static analysis on using only a disassembler because of secure coding techniques being used to prevent such intrusions. Techniques such as encryption and obfuscation, combined with resilient modern computer architectures like variable-width instructions, create additional obstacles preventing simple static analysis using a disassembler. 

(Disassembler 2025)

## Decompiler
A computer program that translates a binary back into high-level source code. A decompiler functions reverse to a traditional compiler. Oftentimes, a decompiler is used to recover lost or unavailable source code by decompiling executable code back into high-level code. However, specific information such as variable names, comments, and code structure is often lost during compilation - so a decompiler's function is not a straightforward process for many languages. However, for executables made using languages such as Java or .NET, class structure and debugging information are often retained when compiled as to make it easier to conduct static analysis on their decompiled products. A decompiler works by first loading (and parsing) machine code and extracting basic facts such as a code's entry point(s) and libraries. Then, the decompiler disassembles machine code into a machine-independent intermediate representation (IR). This IR is then put through data flow analysis (register contents and the manipulation flow of some variables), type analysis (discerning data types based on operations), and structuring (turning IR into different statements dictating control flow). Finally, the decompiler generates the high-level code.    

(Decompiler 2025)

## Debugger
A computer program used to test and debug programs. Key features of a debugger include 
- Query processor
- Symbol resolver
- Expression interpreter
- Support interface
- Single-stepping / Breakpointing
- GUI frontend

In addition to helping correct bugs in programming, debuggers can also be used for nefarious purposes such as software cracking and pirating.  

(Debugger 2025)

## Works Cited
Debugger. 2025. Wikipedia. [accessed 2025 Jan 25]. Available from: https://en.wikipedia.org/wiki/Debugger

Decompiler. 2025. Wikipedia. [accessed 2025 Jan 25]. Available from: https://en.wikipedia.org/wiki/Decompiler

Disassembler. 2025. Wikipedia. [accessed 2025 Jan 25]. Available from: https://en.wikipedia.org/wiki/Disassembler

