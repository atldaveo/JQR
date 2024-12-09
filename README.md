# JQR
This repository will support the completion of JQR tasks acting as a local repo.

## Simple-Calc

Author: David Chung
Date: 9 DEC 24
Purpose: Partially fulfill JQR requirements

### Usage 

Usage: 
./build/simple-calc [OPTIONS]
Options:
  <num1> + <num2>     Add two numbers
  <num1> - <num2>     Subtract two numbers
  <num1> * <num2>     Multiply two numbers
  <num1> / <num2>     Divide two numbers
  <num> >> <space>    Right shift a number by space(s)
  <num> << <space>    Left shift a number by space(s)
  -h                  Show this help message
  -v                  Show version information

make clean - Cleans workspace and removes previous build artifacts

### Functions
1. main() - In 'main.c'. Function takes user CMD Line input (in accordance to "Usage") and either outputs the arithmetic result or error with either a 0 or 1, respectively, integer output.
2. add(x, y) - Defined in 'arithmetic.c'. Adds two valid int32_t integers (x and y) together.
3. subtract(x, y) - Defined in 'arithmetic.c'. Subtracts a valid int32_t integer (y) from another (x).  
4. multiply(x, y) - Defined in 'arithmetic.c'. Multiplies two valid int32_t integers (x and y) together.
5. divide(x, y) - Defined in 'arithmetic.c'. Divides a valid int32_t integer (y) from another (x).
6. shift_right(num, space) - Defined in 'arithmetic.c'. Right shifts a number (num) by 'space' number of spaces.
7. shift_left(num, space) -  Defined in 'arithmetic.c'. Left shifts a number (num) by 'space' number of spaces.
8. print_help() - Defined in 'helpers.c'. Takes a const char pointer, in this case argv[0] and prints a usage guide.

### Testing
1. 'test_arithmetic.c' utilizes the CUnit library to test simple assertions through all the functions of 'arithmetic.c' in order to identify erratic program behavior
2. 'simple-calc-test.py' script generates a quasi-random assortment of [OPTIONS] abd runs the simple-calc program. `     