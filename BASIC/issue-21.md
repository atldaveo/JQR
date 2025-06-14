# Issue 21: Describe C programming concepts in regards to memory
1. **Memory map of a Linux process**
Shows how a Linux process uses different portions of memory and for what purpose. One can view the memory map of a certain process using `pmap`with a process ID (PID). The output of this command will yield a multi-column list of (from left to right) memory address, KB of memory used (offset), access/permissions, and name of the process. An example of a memory map for PID 5485 can be found below.   
```shell
$ sudo pmap 5484 | more
5484:   sshd: /usr/sbin/sshd -D [listener]
0000560d6317f000     48K r---- sshd
0000560d6318b000    564K r-x-- sshd
0000560d63218000    296K r---- sshd
0000560d63262000     16K r---- sshd
0000560d63266000      4K rw--- sshd
0000560d63267000     16K rw---   [ anon ]
```
2. **Automatically allocated memory**
Memory is allocated automatically upon function call and deallocated automatically on completion. Occurs on the **stack**  and deallocated on completion of the function. Used primarily for local variables and function parameters.

3. **Dynamically allocated memory**
Memory is allocated at runtime using functions like 'malloc()' and must be explicitly deallocated using `free()`. Occurs on the **heap**. Typically used when size / number of variables are uncertain at compilation. Specifically applicable for use in data structures.  

4. **Statically allocated memory**
Memory that is allocated at compile-time and exists for the duration of the program's life; memory is not freed until program is complete / exits. Occurs in the **data segment** and automatically managed by the compiler. Used for global variables, static local variables, and constants.  

5. **In the context of automatic vs. dynamic allocation, explain how those concepts are related to the implementation of a stack and heap in a C program.**
Considering the automatic and ephemeral nature of automatic memory allocation, the stack would be naturally smaller than the heap. The predictability of the items to be stored in the stack make it ideal for the processor to automate. On the other hand, the heap's larger storage space allows for memory allocation for more uncertain needs. Dynamic memory allocation's inherent uncertainty and manual nature necesitates larger space to work with. However, precautions must be taken to prevent issues from arising when using both the stack and the heap such as stack overflow in the stack and memory leaks / fragmentations in the heap. 

## Works Cited
Kernighan BW, Ritchie DM. The C (ANSI C) Programming Language. Addison-Wesley; 1988.

Prata S. C Primer Plus. Addison Wesley; 2014.

Red Hat: How to analyze a Linux process' memory map with pmap; 2022 [accessed 2025 January 5]. https://www.redhat.com/en/blog/pmap-command.