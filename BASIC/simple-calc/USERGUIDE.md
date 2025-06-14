# Simple-Calc USERGUIDE

Author: David Chung
Date: 9 DEC 24
Last Updated: 11 MAR 25

## Requirements
- **Hardware:** Any machine capable of running C and Python3
- **Operating System:** Ubuntu 22 or later
- **Software:** Use `git clone` to clone necessary files from the repository

## Setup
### General Usage
1. Ensure all dependent / project files are locally downloaded.
2. Check the Makefile to ensure default configuration (gcc compiler)
3. In a terminal, navigate to the directory to where all of the project files were downloaded. 
4. Execute `make clean` to clear potential remnants of a previous session.
5. Execute `make` to compile and link the program
6. Preced all commands with `./simple-calc` 
7. Proceeding commands are below

```
OPTIONS:
  <num1> + <num2>     Add two numbers
  <num1> - <num2>     Subtract two numbers
  <num1> * <num2>     Multiply two numbers
  <num1> / <num2>     Divide two numbers
  <num> >> <space>    Right shift a number by space(s)
  <num> << <space>    Left shift a number by space(s)
  -h                  Show this help message
```

### Changing the Compiler
If you would like to use a different compiler to run the program, see below

1. Edit the Makefile (line 2) to reflect the active compiler

-- `CC = musl-gcc`                (MUSL)
-- `CC = arm-linux-gnueabi-gcc`   (ARM)
-- `CC = aarch64-linux-gnu-gcc`   (AArch64 / ARM 64-bit)

2. Save the configuration and follow the general usage steps.

### Testing
1. Assuming all required files are still locally saved, in the terminal, run `make test`
2. This command will run simple-calc through a basic CUNIT testing Suite. 

## Known Issues / Bugs
- Operators '<<' and '*' are not interpreted as string literals and such create unintended behavior such as wilcard expansion (globbing). This is addressed by surrounding operators with quotation marks ("<<" and "*") in the terminal.   