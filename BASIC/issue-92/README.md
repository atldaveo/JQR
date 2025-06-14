# Issue 92: Demonstrate the ability to reverse engineer a binary and identify key facts about it

## Pre-requisites
- Update / Install JDK 21
- Update / Install Ghidra 11.3
- Update / Install vscode
- Install extension Hex Editor for vscode (by Microsoft)
- Update / Install gcc
- Obtain compiled binary for a program 

## Overview
For this reverse engineering demonstration, I will be using a binary from the most recent version of simple-calc/ (compiled in `gcc`).

## Usage
1. Navigate to the simple-calc directory and compile the project (either with `gcc -o` or `make`). There should be a new binary created called "simple-calc".
2. Open the binary "simple-calc" with Hex Editor.
3. Open Ghidra, start a new non-shared project named "simple-calcRE".
4. In Ghidra, under the "file" tab, import the recently created binary.
5. Once the file is imported, Ghidra will generate a "Import Results Summary" (figure-1.png) with key details such as file / project names, language, compiler, processor, endianness, size etc.
6. Close the summary and double-click on the imported file in Ghidra to begin analysis.
7. Keep default analysis settings and start the auto-analysis.
8. Once analysis is complete, a dashboard with several windows will appear (figure-2.png). Of note are the main listing window (disassembler) and the decompiler.

## Analysis
### Entry Point / Variables `main()`
- Search for the entry point to the code in the listing window by identifying a function using "main". Once it has been identified, you can start to see what variables are declared and general structure of the code (figure-3.png).    
- As I move down the decompiler, I can see the different operations, strings, and flow of the main() code. For example, I can see all the error-handling for input arguments specific to "simple-calc". That said, I can begin to infer that this program is a calculator of some sort that validates user input to output a calculated value or an error / help message (figure-4.png).
- Most C entry points (`main()`) take two arguments (argc and *argv[]). So if the main() here has two arguments, then I can safely assume that the two arguments in this program's `main()` is also argc and a pointer for argv[], respectively.  
- If there is a third argument, it is most likely an environment variable. 

### Function `count_check`
- Examine all the pink text in both windows. These are function calls. If I double-click them, the "listing" and "decompile" windows will jump to where the functions are defined. 
- Analyzing the function "count_check()" (figure-6.png), I can see that this function compares parameter values and ends with `return 1` or `return 0`.
- Further, I see that if "param_3" and "param_1" are equal, the function immediately ends with `return 1` whereas if "param_3" is less than "param_1", there is a print to standard error saying that there is a wildcard expansion. That said, I can infer that "param_3" is the expected "argc" value from main and that "param_1" is the "argc" value that was read into the entry point. 

### Pointers
- Moreover, I see that variables "local_28" and "local_24" are being referenced by address - meaning these are pointers.
- Variables "local_28" and "local_24" are 32-bit (qword) pointers initialized at 0
- Variable "local_20" is a 64-bit (dword) pointer initialized at 0      

### For-Loop (Not relevent to "simple-calc")
- Generally structured as follows: `for (a; b; c) { d }`
```
for 
(
    init_statement;             // (a) Initialize the loop                    
    condition_statement;        // (b) Check to stay in loop or break
    false_expression;           // (c) Run if condition (b) is false 
) {
    true_expression;            // (d) Run if condition (b) is true
}                               // Loop back to condition until b becomes false
```

### Switch-Case, If-Else, Goto, While
- These structures are readily evident as Ghidra extracts these statements exactly as it appears in the source code. 

## Additional Features
- You can rename local variables to make the decompiled code easier to read (figure-5.png). 
- If edits to the decompiler have reached a point of total uncertainty, you can "re-decompile" the whole thing to restart. 
- When importing a binary, Ghidra will automatically determine file type (PE, ELF, etc).
- Highlighting code blocks on the disassembler will highlight the same block of code in the decompiler (and vice versa) (figure-8.png).  

## Works Cited
RicochetTech. 2023. Intro to Ghidra Tutorial 2023 | Setup to Disassembly Window | Ghidra SRE. [Accessed 2025 Feb 09]. YouTube. Available from: https://www.youtube.com/watch?v=OWEZQMVLMPs&t=43s