# Issue 20 - Describe the purpose and use of C programming fundamentals

1. **The main() function:** Start of program execution. Organizes functions within its body in order to lay out the structure of the overall program. All programs must have a main.

	`main() {BODY OF THE PROGRAM}`

2.  **The return statement:** Controls the flow of a program by exiting the program or returning a value to a variable. 

	`return 0` (exits program / function)

3. **Macro Guards:** Used to prevent re-definition or multi-inclusion of macros and/or header files. By including guards such as 
`#pragma`
or
`#ifndef HEADER_H`
`#endif`
the developer prevents unpredictable program behavior, especially in larger programs relying on many header files and modules. 
4. **Data Types:** The categorization of different forms of data used in C by size and type. `int` `float` `char` and `double` constitute the basic data types used in C. However, developers may define their own data types using declarations such as `typedef`.
5. **Functions and Procedures:** Blocks of code that performs a specific task and returns a value.
	`return_type function(data_type arg1, data_type arg2)`
	`{`
			`//FUNCTION BODY`
			`return value;`
	`}`
6. **Parameters:** The argument values that a function takes such as `arg1` and `arg2`
7. **Scope:** The region of the program in which a variable or function is known. Variables of a global scope (typically defined outside of main) can be referred to by all parts of a program within the directory.
8. **Return Values:** A function may return a certain value based on the return-type that it was declared / defined. For example, a function 
`int function_name()`would return a value of type `int` to wherever it was called. 
9. **Header Files:** A collection of `extern` declared variables and functions of a corresponding source file (like a module) that are included in another file via `#include "header.h"` or `#include <stdio.h>`
10. **Keywords:** Reserved words that have special meaning and serve a specific purpose in the language. `static` keywords retain its value across calls, but limited within the function it is called or within the file (if defined outside function) it is referred. `extern` keywords declare variables or functions that may be defined outside the current file. Global scope. 
11. **Pointers:** variables that store the memory address of another variable. Declared using an `*` as in
`int* integer_pointer` which declares a pointer that points to a data of type `int`. One can access the value being pointed at by dereferencing using `*`. The address that the pointer is pointing at can be accessed using the `&` operator. Pointers assist in direct manipulation of memory, passing by reference, and efficient data structure handling.
12. **An Array:** A collection of elements stored in contiguous memory locations. Elements of an array can be accessed via an index (or pointer) to a specific location within the array. Elements must be homogenous, a pre-defined size, and indexed starting at 0.  An explicit initialization can be seen below.
`int numbers[5] = {1, 2, 3, 4, 5};` 5-element array of type `int`.
13. **C Preprocessor:** A separate first step in program compilation. Common preprocessor directives are `#include` (file inclusion) and `#define`(macro substitution). Macro guards are also a part of this process. 
14. **Casting:** The forcing of a type conversion using a certain unary operator. For example, if I want a more precise quotient, while having only declare integer arguments, I can do the following,
`int dividend;`
`int divisor;`
`int quotient;`
`(float) quotient = (float) divisor / (float) dividend;`
15. **Control Flow:** Order in which statements, instructions, or functions are executed. Control flow can be controlled using basic structures such as conditionals, loops, and branching statements.
`if (1 == x)`
`{`
	`printf("x is %d\n", x);`
`}`
`else`
`{`
	`printf("x is something else");`
`}`
This if-statement controls the flow of the code so that the program makes a conditional decision.
16. **Endianness:** The way data is stored and interpreted in memory, usually as bytes. Organized in one of two primary ways - Big-endian and little-endian. Big-endian data is stored with the MSB at the lowest memory address  . Little-endian data is stored with the LSB at the lowest memory address.  
17. **Multi-Byte vs. Unicode Character Sets:** Both are methods of encoding language / symbol characters. Multi-byte character sets (MBCS) allows for the representation of character symbols that require additional space outside of the traditional single-byte ASCII set such as Chinese GB2312 or EUC-KR Korean. Prominent characteristics are that MBCS is variable-length and compatible with single-byte sets. On the other hand, Unicode Character sets are a universal encoding standard that encompasses all possible human languages, characters, symbols, etc. They are represented in UTF-8 (1 to 4 bytes / character), UTF-16 (2 to 4 bytes / character), and UTF-32 (4 bytes / character).  
18. **Multi-Threading:** A program's ability to execute multiple threads (smallest unit of execution) at the same time - enables efficient use of CPU, but may cause separate issues if mismanaged (such as data racing and deadlock). A safe way to execute multi-threading is to ensure threads are asynchronous and run them concurrently as to avoid the aforementioned issues since neither thread relies on each other. Implemented using libraries like `pthreads.` 
19. **Hashing:** Technique used to map data on a table using a hash value determined by the use of a hash function. Data is input into a hashing function in order to create a hash value. This value is an index within a hash table to which the original input data is stored. The hash function itself must be able to uniformly distribute a variety of data while also allowing for an easy look-up of the value itself while attempting to mitigate the occurrences of collisions (when multiple data is mapped to the same location on a hash table).  
 
## Works Cited
Kernighan BW, Ritchie DM. The C (ANSI C) Programming Language. Addison-Wesley; 1988.