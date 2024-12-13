## data-structures

Author: David Chung
Date: 9 DEC 24
Purpose: Partially fulfill JQR requirements

### Directory Overview

This directory contains sub-directories named after each data structure
being templated.

Each of these sub-directories are self-contained mini-repositories for
independently run test programs (named [data structure]-test.c) via its own 
Makefile. Additionally, each of these sub-directories contain all the 
dependencies and hold the consequent object files on creation of the C 
executable. 

In the terminal, navigate the current directory to one of the data structure
sub-directories, and then follow the usage directions to view implementation.   

### Usage 

Usage: 
make 

./[data structure folder name]

make clean - Cleans workspace and removes previous build artifacts

### Functions
- All data structures are formed in their respective header file
- All structure methods / helpers are defined in their respective .c file
- Testing is coded in the [data structure]-test.c file and executed via 'make'
