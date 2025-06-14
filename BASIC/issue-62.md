# Issue 62: Describe terms and concepts associated with concurrency

## Threading (thread vs. pthread)
 A technique in programming where a single process is divided into multiple threads. 
 Each thread represents a separate flow of execution within the same process, sharing 
 the same memory space, file descriptors, and other resources.

### pthread
pthread is a library to manage threading operations. The Posix thread (pthread) is 
the implementation of threading using an API in UNIX systems in POXIS standard. Most, 
if not all, pthread functions are found in the unistd.h and pthread.h libraries.

`pthread_t thread;`

************************

## Thread synchronization mechanisms (locking) 
Synchronizes access to shared resources in multi-threaded programs to prevent race 
conditions and ensure data consistency. Primarily composed of mutexes, joins, and 
conditional variables.

### Mutex (Mutual Exclusion Lock)
Ensures that only one thread can access a critical shared section at a time, thus 
ensuring mutual exclusion. As such, mutex's serialize shared resources. Can only be 
applied to threads in a single process. Does not work between processes. Anytime a 
global resource is accessed by more than one thread the resource should have a Mutex 
associated with it.

`int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);`
`pthread_mutex_t lock;`
`int pthread_mutex_trylock(pthread_mutex_t *mutex)`
`int pthread_mutex_unlock(pthread_mutex_t *mutex) `
`int pthread_mutex_destroy(pthread_mutex_t *mutex)`

**Block access to variables by other threads** 

#### Race conditions
Occurs in concurrent programming when two or more threads attempt to perform
operations on the same memory area. 

### join
A synchronization mechanism that makes a thread wait until other threads are complete. 
Typically, a parent thread ensures a child thread to complete its process before 
continuing its own process.  

**Makes a thread wait until others are completed / terminated**

`int pthread_join(pthread_t thread, void **return_val)`

### Condition variables
**Data type:** `pthread_cond_t`
Condition variables are typically used in conjunction with a mutex to ensure safe 
access to shared resources. The process generally involves:

#### **Locking the Mutex**
A thread locks a mutex to safely check and manipulate shared data.

#### **Waiting on the Condition Variable. **
If the condition is not met, the thread waits on the condition variable. This...

##### Puts the thread to sleep until it is signaled. 

##### Releases the associated mutex.
Puts the thread to sleep until it is signaled.
Signaling the Condition Variable: Another thread signals the condition variable when 
the condition becomes true. This wakes up one or more waiting threads.

#### **Signal the condition variable **
Another thread signals the condition variable when the condition becomes true. This 
wakes up one or more waiting threads.

#### **Reacquiring the Mutex**
Once woken up, the thread reacquires the mutex to safely continue execution.

## fork
used to create a new process by duplicating the calling process. Identical processes 
are differentiated with a PID return value of 0 (child) and the parent process 
receives the child's PID. 

`int fork(void)`

## create
The create function creates a new thread - initialize thread, assigns resources, and 
specifies function to execute. 

```
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, 
                    void *(*start_routine)(void *), void *arg)`
```                   

## exit
Terminates the calling thread by letting the function return.

`void pthread_exit(void *return_val)`

## detach
Detaches a thread. When this detached thread terminates, its resources are automatically 
released back to the system without the need for another thread to join with the 
terminated thread. Returns 0 if successful

`int pthread_detach(pthread_t thread)`

## self
Function returns the ID of calling thread. Same as `pthread_create()`, only the function 
is working on itself. 

`pthread_t pthread_self(void)`

## Semaphore
A semaphore is a signaling mechanism that controls access to a resource by multiple 
threads, up to a defined limit. A semaphore is an integer variable that is subjec to change / 
manipulation via atomic operations. Semaphores come in two varieties, unnamed and named 
semaphore. They differ only in their open, init, and close procedures as semaphores behave 
like files. 

`sem_t semaphore;` 

### atomics
Singular unit of work that either must be executed completely or not at all. Lack of 
intermediate states provides higher level of flexibility. Atomic operations 
ensure data integrity and mitigate the risk of race consitions.  

Functions are defined in <stdatomic.h>

## Deadlocks
a situation in concurrent programming where two or more processes or threads are unable to proceed because each is waiting for a resource that the other holds. Deadlocks result in a standstill where none of the involved processes can make progress.

## thread safe
The threaded routines must call functions which are "thread safe". Therefore, any function that does not use static data or other shared resources is thread-safe.

## thread id
A unique identifier assigned to a thread within a process. It is used by the operating system or threading library to track and manage threads independently.

## Scheduling algorithms (ie. round robin, shortest job first, priority scheduling)
These algorithms are used in operating systems to determine the order in which 
processes are executed by the CPU. Specific types are described below.

- **Round Robin:** All processes are given a specific, fixed amount of CPU time. If a 
process doesn't finish in the allotted time, the process is moved to the back of the queue to try again later. If the process succcessfully executes with time remaining on 
the quantum, the scheduler immediately moves to the next process attempting to execute.  

- **Shortest Job First:**  Execute the process with the shortest burst time first. Scheduler identifies the process that would take the least amount of time to execute and then executes that process to completion. Upon completion of the process, the scheduler looks for the next fastest process, executes that process, and repeat until all processes 
are successfully executed.

- **Priority Scheduling:** Execute processes based on priority. Each process is assigned a priority (lower number means higher priority) and then executed based on the priority value. That said, one of the biggest pitfalls with this type of scheduling is that a low-priority process may have to wait indefinitely in the ready queue as new processes with higher priorities will take precedence regardless when either processes were initialized.   

## Works Cited
Carnegie Mellon University. 2007. Linux tutorial: POSIX threads. Pittsburgh (PA): Carnegie Mellon University. [accessed 2025 Jan 19]. https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html.

2024. 10_Operating_Systems_Concepts. [class resource]. Basic Level Curriculum Repository. [US Army Cyber School]. 
