# data-structures

Author: David Chung
Date: 13JAN25
Last Updated: 10APR25

## Repository Structure

The repository is organized as follows:

```
data-structures/
|- binary-search-table/
    |- build/
    |- include/
    |- src/
    |- .gitignore
    |- Makefile
|- circularly-linked-list/
    |- build/
    |- include/
    |- src/
    |- .gitignore
    |- Makefile
|- hash-table/
    |- build/
    |- include/
    |- src/
    |- .gitignore
    |- Makefile
|- priority-queue/
    |- build/
    |- include/
    |- src/
    |- .gitignore
    |- Makefile
|- stack/
    |- build/
    |- include/
    |- src/
    |- .gitignore
    |- Makefile
|- README.md
```

## Usage / Testing
Testing was conducted using code that would implement the respective data structures. Each data structure has its own test code named "<data structure type>-test.c". Additionally, each data structure is self-contained and independently runnable so long as you navigate the current directory to that specific data structure's directory.

In order to run the test code for a data structure, follow the steps below.
1. Navigate to the data structure to be examined.
2. Enter `make run` on the terminal to execute the test code.
3. You will be able to see the feedback for the test code in the terminal and validate functionality.
4. Once complete, enter `make clean` to remove build artifacts and clean out the directory. 

### Goals
Demonstrate knowledge on how several data structures are constructed using C 

## Features
- Accepts all data types using void* pointer
- Dynamic memory allocation
- Handle overflow by doubling the size of the structure where relevent

## Issues Addressed
-40 (Demonstrate skill in controlling memory)
-51 (Demonstrate skill in creating and using a circularly linked list that accepts any data type)
-52 (Demonstrate skill in creating and using a binary search tree that accepts any data type)
-53 (Demonstrate skill in creating and using a hash table that accepts any data type)
-54 (Demonstrate skill in creating and using a stack that accepts any data type)
-55 (Demonstrate skill in creating and using a priority queue that accepts any data type)

## Citations
Barr M. Embedded C Coding Standard. BARR group - The Embedded Systems Experts; 2018.

Gamma E, Helm R, Johnson R, Vlissides J. Design Patterns: Elements of Reusable Object-Oriented Software. Addison-Wesley; 1977. 

Karamanchi, N. Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles. CareerMonk Publications; 2017.

Kernighan BW, Ritchie DM. The C Programming Language: ANSI C. Addison-Wesley; 1988.

Prata S. C Primer Plus. Addison-Wesley; 2014.