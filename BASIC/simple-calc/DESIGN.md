# DESIGN

## High-Level Architecture

1. Main Function ("main.c"): Main entrypoint for the program. Coordinates program flow and data validation
2. Helper Functions ("operations.c", "validations.c", "arithmetic.c"): Reusable functions that modularize validation and execution

## Usage 

- For general usage, compile/link using CLI command `make`
- To run the program, run `./simple-calc [OPTIONS]`
- To clean the project of build artifacts, run `make clean` 
- To run the test script for simple-calc, run `make test` 
- To run clang-tidy linter on the program, run `make tidy`
- To cross-compile using MUSL, run `make musl`

## Known Bugs and Issues

## Data Flow

`
+-------------------+
|   User Input      |
+-------------------+
        |
        v
+-------------------+
| Argument Parsing  |
+-------------------+
        |
        v
+---------------------------+
| Validation and Conversion |
+---------------------------+
        |
        v
+-------------------+
|  Arithmetic Ops   |
+-------------------+
        |
        v
+-------------------+
|   Output Result   |
+-------------------+
`

## Modules

1. Main Module (main.c)

Orchestrates the program flow.
Handles command-line arguments and calls helper functions.

2. Validation Module (validations.c)

Functions for validating operands and operators.
Checks for input format, type, and range.

3. Arithmetic Module (arithmetic.c)

Performs the actual arithmetic or bitwise calculations.
Contains reusable functions for addition, subtraction, multiplication, etc.

4. Debugging Module (debug.c)

Provides debug logs and detailed error information for developers.

5. Operations Module ("operations.c")

Provides reusable code that allows for the main to decide appropriate 
arithmetic operations and outputs

## Key Design Decisions

- Manual Parsing of Command-Line Arguments
-- Decided against using getopt() to simplify user input (no flags required).

- Input Validation
-- All input is validated for type safety and correctness before performing any operations.

- Modular Design
-- Each function has a single responsibility, enhancing code readability and maintainability.

- Single Exit Point
-- The main function uses a single exit point (end:) to manage cleanup and error handling.

# Future improvements
- Prevent `>>` from generates files instead of right shifting
- Prevent `*` from causing a wildcard expansion 

