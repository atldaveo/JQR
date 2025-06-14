# Issue 34: Describe terms asociated with compiling, linking, debugging, and executables
1. **Portable Executable (PE)**
File format that Windows OS uses to load and execute binary files. 
 
2. **Executable and Linkable Format (ELF)**
Linux file format for loading and executing binaries.

3. **Difference between PE and ELF**
- ELF can run on a variety of platforms and architectures whereas PE can only run on Windows
- Structure of a PE 
-- DOS Header
-- PE Header
-- Section Header(s)
-- Import / Export Tables
-- Relocation Table
- Structure of ELF
-- Headers
-- Sections
-- Segments: Program (Execution) and Section (Linking)

4. **Difference between a library (shared object / DLL) and a regular executable program**
A library is a collection of precompiled routines used by executables, but not meant for standalone execution. The code inside of a library is reusable and often shared by multiple programs. A regular executable is a complete application designed to run independently. Formatting for libraries are `.so` (UNIX shared object) or `.dll`(Windoes dynamically-linked library). Regular executables are ELF for Linux and PE for Windows.  

5. **Calling convention/Application Binary Interface (ABI)** 
Dictates how code from different modules, libraries, and languages can interact within a program. 
- Calling convention dictates rules for functino calls.
- ABI defines how programs, libraries, and system calls interact at the binary level.  
- Compiler translates source code into an object file via ABI and calling conventions.
- Linker combines object files into a final executable or shared library.

## Works Cited
Microsoft Windows App Development: PE Format. Microsoft; 2024 [accessed 2024 Jan 04]. https://learn.microsoft.com/en-us/windows/win32/debug/pe-format.

TIS Committee. Tool Interface Standard (TIS) Executable and Linking Format (ELF) Specification Version 1.2. Linux Foundation; 1995.