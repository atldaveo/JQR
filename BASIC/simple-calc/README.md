# Simple-Calc

Author: David Chung
Date: 9 DEC 24
Purpose: Command-line utility for performing basic arithmetic operations
Last Updated: 9 APR 25
Summary of changes:
- Addressed the valgrind error messages by updating Makefile (dynamically linked objects instead of using `-static` when building the main target) 

## Repository Structure

The repository is organized as follows:

```
simple-calc/
|- simple-calc/                 # Overall project directory
  |- src/                       # Source files required for proper compilation
  |- include/                   # Header files
  |- test/                     # Unit tests/scripts for program validation
  |- Makefile                   # Makefile to build and test the program
  |- README.md                  # Delineates general overview of project
  |- DESIGN.md                  # Describes the structure of the project
  |- .gitignore
```

### Goals
- Provide intuitive and user-friendly CLI for simple calculations
- Ensure robustness through a variety of input validation and error-handling
- Ensure modularity thru reusable code
- Ensure efficiency through reduction of overhead at compile-time

## Functions and Features
1. main() - In 'main.c'. Function takes user CMD Line input (in accordance to "Usage") and either outputs the arithmetic result or error with either a 0 or 1, respectively, integer output.
2. add(x, y) - Defined in 'arithmetic.c'. Adds two valid int32_t integers (x and y) together.
3. subtract(x, y) - Defined in 'arithmetic.c'. Subtracts a valid int32_t integer (y) from another (x).  
4. multiply(x, y) - Defined in 'arithmetic.c'. Multiplies two valid int32_t integers (x and y) together.
5. divide(x, y) - Defined in 'arithmetic.c'. Divides a valid int32_t integer (y) from another (x).
6. shift_right(num, space) - Defined in 'arithmetic.c'. Right shifts a number (num) by 'space' number of spaces.
7. shift_left(num, space) -  Defined in 'arithmetic.c'. Left shifts a number (num) by 'space' number of spaces.
8. print_help() - Defined in 'helpers.c'. Takes a const char pointer, in this case argv[0] and prints a usage guide.

- Supports **32-bit** operands
- Handle simple bitwise and arithmetic operations
- Supports compilation in MUSL and GCC 

## Testing
1. 'test-arithmetic.c' utilizes the CUnit library to test simple assertions through all the functions of 'arithmetic.c' in order to identify erratic program behavior
2. 'simple-calc-test.py' script generates a quasi-random assortment of [OPTIONS] abd runs the simple-calc program.

## Issues Addressed
- 19 (With references, resources, and a provided unit-level coding standard or style guide, identify coding standard violations in C source code)
- 22 (Demonstrate the proper declaration, understanding, and use of C data types and underlying structures:)
- 23 (Demonstrate proper declaration, understanding, and use of fixed-width C data types defined in stdint.h)
- 24 (Demonstrate the ability to create and implement a function that uses different arrays)
- 25 (Demonstrate the ability to perform basic arithmetic operations using appropriate C operators while ensuring proper order of operations (PEMDAS))
- 26 (Demonstrate the ability to properly use the standard main() entry arguments)
- 28 (Demonstrate the ability to create and implement functions to meet a requirement)
- 29 (Demonstrate the ability to perform data validation)
- 30 (Demonstrate skill in using pointers)
- 31 (Demonstrate skill in creating and implementing conditional statements, expressions, and constructs)
- 35 (Demonstrate skill in compiling, linking, and debugging)
- 36 (Demonstrate the ability to build a binary from multiple C source files and headers by writing a Makefile using explicit rules)
- 38 (Demonstrate skill in using the C preprocessor)
- 43 (Demonstrate the ability to perform basic arithmetic operations using Python operators while ensuring proper order of operations (PEMDAS))
- 45 (Demonstarte the ability to create and implement functions to meet a requirement)
- 46 (Demonstrate the ability to perform data validation)
- 47 (Demonstrate skill in creating and implementing conditional statements, expressions, and constructs)
- 103 (Demonstrate knowledge of alternative C libraries to glibc)
- 104 (Demonstrate the ability to cross-compile an application for multiple architectures)
- 105 (Develop a capability)

## Citations
Barr M. Embedded C Coding Standard. BARR group - The Embedded Systems Experts; 2018.

Gamma E, Helm R, Johnson R, Vlissides J. Design Patterns: Elements of Reusable Object-Oriented Software. Addison-Wesley; 1977. 

Kernighan BW, Ritchie DM. The C Programming Language: ANSI C. Addison-Wesley; 1988.

Prata S. C Primer Plus. Addison-Wesley; 2014.

van Rossum G, Warsaw B, Coghlan A. PEP 8 - Style Guide for Python Code, Python Software Foundation; 2001.