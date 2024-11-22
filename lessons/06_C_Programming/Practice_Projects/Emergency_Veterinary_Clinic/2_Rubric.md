# Emergency Veterinary Management System: Rubric

## Specific Implementation Standards

| Requirement | Point Value | Score | Comments |
| --- | --- | --- | --- |
| Functional and Interactive Terminal | 5 | | |
| (`Check in New Patient`) Add animals to priority queue, prompting user for necessary information, refusing invalid data. | 6 | | |
| (`Call up Next Patient`) Remove animals from the front of the priority queue | 6 | | |
| (`Display Queue`) Display all animals in queue | 5 | | |
| (`Search for Patient`) Search for animal by ID or name and display position in queue and all other data related to it. | 6 | | |
| (`Help`) Displays a prompt that provides a helpful prompt to the user. | 2 | |
| (`Modify Existing Patient Data`) Update animal data: modify existing animal's Severity Level and updates position in queue, and allows for description to be modified. | 6 | | |
| Properly deserialize data file on startup | 6 | | |
| (`Save Data`) Properly serialize data to file | 5 | | |
| (`Quit Program`) Cleanly shuts down the program | 5 | | |
| Properly uses Abstract Data Types | 4 | | |
| Implement priority queue for appointment management | 4 | | |
| Subtotal | 60 | | |

General Implementation Standards

| Requirement | Point Value | Score | Comments |
| --- | --- | --- | --- |
| Memory management | 10 | | |
| Follows style guide(s) | 5 | | |
| Follows required directory structure | 2 | | |
| Builds without warnings | 5 | | |
| Discretionary points | 10 | | |
| Documentation on all functions, enums, structures, and defines | 3 | | |
| User Manual / README (to include compilation steps) | 3 | | |
| Design Document | 2 | | |
| Subtotal | 40 | | |

| Base Score | Points Possible |
| --- | --- |
| __ | 100 |

| Extra Credit Item | Point Value |
| --- | --- |
| Use a signal handler to shutdown gracefully when SIGINT is sent. | 1 |
| Reads/writes data to the inventory file(s) in big-endian. | 1 |
| Implement continuous integration/continuous development (CI/CD) - A `.gitlab-ci.yml` file shall be provided that will perform linting, compilation, memory leak detection (`valgrind`), and run unit tests. | 2 |
| A reference manual for maintainers containing documentation for every function, it's parameters, and return values (see [Doxygen tutorial](https://opensource.com/article/22/5/document-source-code-doxygen-linux)). | 1 |
| Implement a circularly-linked list populated with 5 veterinary doctors' names. See [here](./0_Specification.md#circularly-linked-list-extra-credit) for details. | 2 |

**FINAL SCORE:** ____

**FINAL COMMENTS:** ____
