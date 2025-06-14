# Issue 87: Describe the purpose of the stack and how data is added/removed from it.

A stack is a last-in, first out data structure used for spilling registers and returning to a previous state - prior to the execution of an instruction. Programs may require more than the traditional eight registers to execute. As such, stacks are ideal for ameliorating the data spillover - though at a cost to performance on the basis of the principle of memory locality. The storage inside of a stack is temporary in nature.   

Data is added to the stack via a push operation. This causes an increment of the stack pointer. After data is stored where the pointer is pointing, the pointer increments to the next available spot on the stack. Data can also be added to a specific space on the stack by manually incrementing the pointer via an offset. However, the principle will still stand that the most recent piece of data will still be removed as processes are completed or data retrieved. 

eg.
```
PUSH EAX;       @ Push data in register EAX onto stack 
```

Data is removed from the stack via a pop. Pops occur when data from the stack is retrieved or when the stack pointer is decremented. 

eg.
```
POP EAX;        @ Pop the top value from stack into the EAX register
```

# Works Cited 
Patterson DA, Hennessy JL. Computer Organization and Design. Elsevier: Cambridge; 2017.