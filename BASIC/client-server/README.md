# Simple-Calc

Author: David Chung
Date: 11 JAN 25
Purpose: Convey understanding of network relationships via a C-programmed server and a Python-programmed client. This will be a standalone program due to its narrow scope.
Last Updated: 7 FEB 25

`main' is programmed in `server.c`

## Features
- Client accepts user input via command line and sends it to the server
- Server-side message logging in `server_log.txt`
- Client-side message logging in `client_log.txt`
- Server-side signal interrupt (`ctrl-c`) handling
- Added designated directories "server-repo" and "client-repo" for remote file management
- Added remote file management function `file_ls`. View files in repo "server-repo" when invoked on client-side. 

## Issues addressed
- 18 (With references, resources, and a provided unit-level coding standard or style guide, identify coding standard violations in Python source code)
- 27 (Demonstrate the ability to perform file management operations in C)
- 42 (Demonstrate the proper declaration and use of Python data types and object-oriented constructs)
- 44 (Demonstrate the ability to perform file management operations in Python)
- 45 (Demonstrate the ability to create and implement functions to meet a requirement)
- 49 (Demonstrate the ability to parse command line arguments using built-in functionality)
- 61 (Demonstrate the ability to use the following (signal handling) constructs)
- 71 (In Python, demonstrate skill in using networking commands accounting for endianness)
- 72 (In C, demonstrate skill in using networking commands accounting for endianness)
- 73 (Demonstrate skill in handling partial send()/recv())
- 74 (Demonstrate skill in implementing functions that can properly handle any IP address (IPv4/IPv6).)

### Pre-Requisites
-GNU (eg. GCC)
-Python3
-OS-specific socket library support

### Directory Structure
```
|- client-server/
    |- build/           # Build object(s)
    |- include/         # Header Files
    |- src/             # Client and server source files
    |- client-repo      # Directory for client files
    |- server-repo      # Directory for server files
    |- .gitignore
    |- Makefile         
    |- README.md        # Code structure and usage guide
```

## Getting Started
1. Set current directory to `client-server`
2. Enter 'make clean' in terminal followed by `make run` (Makefile will compile and run server)
3. In a new terminal, navigate `cd` to `client-server/src/`
6. Run the command `python3 client.py`
7. Once client is connected to the server, the user is free send / receive from either the server or client. 
8. To quit, user will input "exit" on either terminals.
9. A log `log_file.txt` will be generated upon termination.

## Usage
- If the client enters 'file_ls' on command line, client will be able to view all files inside of server's "server-repo/" directory
- 'file_get' requires debugging