# Issue 86: Describe the ways in which data can move between registers and memory

## Immediate to register
1. CPU fetches instruction (MOV)
2. CPU decodes instruction
3. CPU places immediate value onto the data bus and writes into specified register (assuming the immediate value is smaller than 32 bits (x86) or 64 bits (x64))

eg.
``` 
MOV RAX, 0x5;        @ move '5' into register RAX (GPR)  
```

## Register to register
1. CPU fetches instruction from memory (MOV)
2. CPU decodes instruction 
3. Data copied from source to destination register. 

eg. 
```
MOV EBX, EAX;         @ move (copy) contents of register R1 into R2
```

## Immediate to memory
1. CPU fetches instruction (LDR)
2. CPU decodes the instruction
3. Calculate memory address (if arithmetic is invoked for an offset)
4. Move data via BUS to memory address calculated

eg.
```
MOV DWORD PTR [RBP - 4], 42;    @ 42 into memory address RBP (offset - 4) 4 Bytes in size
```

## Register to memory
1. CPU fetches instruction (MOV)
2. CPU decodes instruction
3. Register value placed on data bus
4. Memory address calculated (if required)
5. Value in register is written into memory

eg.
```
MOV [RBP - 4], EAX;     @ Move contents of register EAX into address of RBP offset -4
```
## Memory to register
1. CPU fetches instruction (load data from memory into register)
2. CPU decodes instruction  
3. Memory address is calculated if required
4. Value at address is fetched
5. Value is loaded into destination register

eg.
```
MOV EAX, [RBP + 4];     @ Move (copy) data from address RBP+4 to register EAX
```

## Memory to memory
1. CPU fetches instruction (MOV)
2. CPU decodes instruction
3. Memory addresses are calculated if required
4. Data from source address is loaded into temporary register
5. Data is moved from temporary register to destination address 

eg.
```
MOV EAX, DWORD PTR [RBP - 8];       @ Load data in address RBP-8 into register EAX
MOV DWORD PTR [RBP - 16], EAX;      @ Store value from register EAX into address RBP - 16
```

## Works Cited
Patterson DA, Hennessy JL. Computer Organization and Design. Elsevier: Cambridge; 2017.