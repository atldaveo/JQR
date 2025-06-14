# Issue 95: Describe the difference between modular and monolithic design and its impact on testing

Modular design refers to software being designed in independent modules that compose the whole (Thomas 2020). For example, a modular program may have a variety of separate functions that can be tested and maintained separately. 

From a testing standpoint, modular software makes software easier to troubleshoot and test. If software is developed modularly, it will be obvious where bugs may originate and each module that the software uses can be tested independently, and in isolation, prior to deployment. Moreover, a program can be developed in parallel as each section (module) of the program can be assigned to different teams. Different groups can work on different aspects of a program at the same time, thus allowing for more efficient use of time. That said, the use of independent modules in a program necesitates integration testing - additional, but necessary overhead in the testing process that confirms that a module will function as intended with the rest of the program and with other modules.
(Martin 2003)   

Monolithic design is the construction of a system built as a single, unified application where all components are tightly coupled and interdependent (Parnas 1972). The entire program is developed, tested, and deployed as a single unit.

Unit testing is significantly harder because of the need to test the whole program and waiting on total development prior to testing. Integration testing will more difficult as well due to the highly interdependent nature of the different sections of the code. Moreover, the difficulty in debugging, regression testing, and even scaling (up and down) will also be significantly increased for the same reason. Small changes within the monolithic system may lead to unintended consequences somewhere else within the code with no easy way to pinpoint how, where, and what was affected.

## Works Cited
Martin, RC. Agile Software Development: Principles, Patterns, and Practices. Prentice Hall; 2003.

Parnas DL. On the criteria to be used in decomposing systems into modules. Communications of the ACM. 1972 Dec 1; 15(12). https://doi.org/10.1145/361598.361623

Thomas D, Hunt, A. The Pragmatic Programmer. Addison-Wesley; 2020.