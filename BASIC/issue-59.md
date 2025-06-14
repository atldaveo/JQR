# Issue 59: Describe terms and concepts associated with Operating System (OS) virtualization

## Processes
A process is a program in execution, consisting of the program code, current activity (e.g., program counter and registers), and associated system resources (e.g., memory). Processes enable multitasking by allowing multiple programs to execute concurrently on a single CPU.

Processes are managed by the operating system, which provides isolation and resource allocation. They can be in one of several states: new, ready, running, waiting, or terminated.
(Selberschatz 2018)

## CPU Scheduling
CPU scheduling is the mechanism by which the operating system determines which process in the ready queue should be allocated the CPU next. The goal of CPU scheduling is to optimize CPU utilization, throughput, and response time while minimizing waiting and turnaround time (Tanenbaum 2014).

## Paging Tables
Data structures used to hold virtual memory. They are mapped into physical addresses in virtualization. Paging tables occupy non-contiguous portions of physical memory to allow flexibility in using virtual systems within a hypervisor. Pagin divides memory into fixed-sized blocks in physical memory called frames. Page tables store the mappings of page numbers to frame numbers in order to allow easier indexing and operation of a virtual OS similar to a physical OS (Silberschatz 2018).   

## Caching
Soring frequently used data in the cache. A cache is a level of the memory hierarchy between the processor and main memory. However, a cache also refers to any storage managed to take advantage of locality of access. This makes it easier to call the data; significantly lower probability of miss due to the cache's position in the memory hierarchy (Hennessy 2017).   

## Kernel and User-Mode Memory
Operating systems use kernel mode and user mode to separate privileged operations from user-level processes. This distinction prevents user processes from directly accessing or modifying critical system resources.
- **Kernel-Mode**: Allows unrestricted access to hardware and system resources.
- **User Mode**: Restricts process access to ensure system stability and security. Processes must request system services through system calls
(Bovet 2005)

## Works Cited
Bovet DP, Cesati M. Understanding the Linux Kernel. 3rd ed. Sebastopol (CA): O’Reilly Media; 2005.

Hennessy JL, Patterson, DA. Computer Organization and Design: The Hardware/Software Interface. Cambridge: Morgan Kaufmann; 2017.

Silberschatz A, Galvin PB, Gagne G. Operating System Concepts. 10th ed. Hoboken (NJ): Wiley; 2018.

Tanenbaum AS, Bos H. Modern Operating Systems. 4th ed. Upper Saddle River (NJ): Pearson; 2014.