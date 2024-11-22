# Emergency Veterinary Management System: Specifications

## Introduction

Welcome to Green Hills Wildlife Emergency Veterinary Clinic! Our mission is to provide efficient, quality care to animals suffering from illness or injury. In addition to servicing local pet owners, our clinic provides care to animals of a local animal sanctuary that cares for a large variety of animals that cannot be returned to the wild. Until recently, our method of triage using first-come-first-serve to take in animals has been sufficient, but as the nearby sanctuary takes in more animals, it's become inefficient and even dangerous as animals are not being seen in time.

## Intent

The goal of this program is to develop an Emergency Veterinary Management System that effectively manages triage for animals with severe injuries and illnesses that require immediate medical attention. The nurse at the front desk needs a responsive queuing system that they can use to process incoming animals and document their ailments, organizing the queue such that animals with more dangerous ailments are placed ahead of others, as well as a way to remove animals from the queue in the event of untimely passing. The user of this program needs to be able to save the existing data in the queue to a file as a method of persistence and data recovery.

## Requirements

**The user interface shall:**

- Be responsive to user input, providing timely responses.
- Utilize a command-line interface (non-GUI).

**The user prompts for input shall be:**

- Clear
- Concise
- Easy to understand

### Program shall

- Run with `./bin/emergency_vet <animal_queue.dat>`.
- Implement make or CMake to build the project with the following targets:
    - `all` - builds the complete project.
    - `run` - ensures the project is built and launches the server.
    - `test` - ensures the project is built and runs tests.
    - `clean` - removes all build artifacts (leaves sanctuary_data and documents intact).
- Implement all data structures as *abstract data types* that accept `void *` as their data type.
- Read the full queue data file on program load, managed in memory. See [protocol details here](./1_Protocol.md).
- Implement file operations that prevent partial-reads and partial-writes.
- Implement a `help` feature for users to get help on the entire program or specific functions.
- Compile without errors or warnings with `-Wall -Wextra` at minimum.
- Securely handle user input.
- Appropriately handle memory without leaks.
- Run on Ubuntu 22.04 LTS with no external dependencies.
- Provide a method of safely exiting the program, prompting the user to provide an output file to store program data.
- Be compliant with the [BARR-C Embedded Guide](https://barrgroup.com/sites/default/files/barr_c_coding_standard_2018.pdf).

### Required Data Structures

- Implement a [priority queue](https://en.wikipedia.org/wiki/Priority_queue) for executing triage on injured animals, prioritized based on the severity of illness or injury.
- Severity scales from 0-99, where the higher the value, the higher the severity.
    - ex. An animal with severity 30 would be closer to the front of the queue than an animal with a severity of 16. Values outside of this range are considered invalid.

### Mandatory File Structure Format

- Data will be deserialized from a data file on startup based on the file name provided as a command-line argument.
- The data will be serialized to the same data file when the `save` command is used, but **will not** automatically occur before closing.
- If the file name given as a command-line argument does not exist, the program will create an empty file of that name.
- Data file contains patient details:
    - Severity level (can be modified) - `uint8_t`
    - Animal name length - `uint8_t`
    - Species name length - `uint8_t`
    - PADDING - 3 x `uint8_t`
    - Description length - `uint16_t`
    - Animal name (cannot be modified) - 32-byte NULL padded and terminated string
    - Species name (cannot be modified) - 32-byte NULL padded and terminated string
    - Description of illness or injury (can be modified) - 256-byte NULL padded and terminated string
- This [script](_assets/queue_data_generator.py) will allow you to generate small, medium, and large queue data files to assist with development. Copy the file into your project directory and execute with `python3 queue_data_generator.py`.

- Note: "NULL padded and terminated" to 32 bytes means a string like "Elephant" (8 bytes) would get padded to `Elephant\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0` where `\0` is a null byte.

### Program Workflow

The program shall provide an intuitive ***menu-driven*** interface, with the following options:

| Main Menu Option | Expected Behavior |
| --- | --- |
| Check in New Patient | Provide an interface for users to add an animal to the service queue, prompting them for the animal's unique ID, Animal Name, Species Animal Name, severity level, and a brief description of the illness or injury before inserting the animal into the priority queue based on the severity provided. |
| Modify Existing Patient Data | Creates a menu that allows users to select what attribute of a specified animal to modify and save. If the severity level is modified, the animal's position in the priority queue should reflect the change. |
| Call up Next Patient | Remove the first animal in the priority queue and displays the animal's details to the screen. |
| Remove Patient from Queue | Remove the specified animal from the queue. |
| Display Queue | Prints a list of all animals in the queue, displaying their ID, Animal Name, and severity value. |
| Search for Patient | Search for animal by ID or name and display position in queue and all other data related to it. |
| Save Data | Serialize the existing priority queue to a file with the name `<UNIX TIMESTAMP>_queue.dat` following the defined protocol for easy data recovery. |
| Help | Displays dialog outlining the intent of the current menu and the purpose of any available sub-menu options. Should be included on every menu.|
| Quit Program | Closes the program. |

#### Menu Tree

```text
Main Menu
  |--> 1. Check in New Patient
      |--> Prompt for patient data

  |--> 2. Call up Next Patient

  |--> 3. Modify Existing Patient Data
      |--> Prompt for patient name
          |--> 1. Modify Patient Name
          |--> 2. Modify Patient Species Name
          |--> 3. Modify Patient Severity Value
          |--> 4. Modify Patient Description

  |--> 4. Remove Patient from Queue
      |--> Prompt for patient name

  |--> 5. Display Queue
  |--> 6. Search for Patient
      |--> Prompt for patient name

  |--> 7. Save Data
  |--> 8. Help
  |--> 9. Quit Program
```

On startup, the program will take a file name provided as a command-line argument and deserializes the data stored in the file into a priority queue. The user will then be presented a menu with the required options as outlined above, where they will be prompted for input. Once the user decides to quit the program, all resources are released back to the operating system, allowing the program to close without memory leaks.

## Deliverables

1. Working program meeting the above requirements.
2. Utilization of `make` or `cmake` to build the project.
3. Documentation of functions, enums, structs, and defines.

## Extra Credit

| Extra Credit Item | Point Value |
| --- | --- |
| Use a signal handler to shutdown gracefully when SIGINT is sent. | 1 |
| Reads/writes data to the inventory file(s) in big-endian. | 1 |
| Implement continuous integration/continuous development (CI/CD) - A `.gitlab-ci.yml` file shall be provided that will perform linting, compilation, memory leak detection (`valgrind`), and run unit tests. | 2 |
| A reference manual for maintainers containing documentation for every function, it's parameters, and return values (see [Doxygen tutorial](https://opensource.com/article/22/5/document-source-code-doxygen-linux)). | 1 |
| Implement a circularly-linked list populated with 5 veterinary doctors' names. See [here](#circularly-linked-list-extra-credit) for details. | 2 |

## Circularly Linked List Extra Credit

In addition to maintaining the queue of patients waiting to be seen by a doctor, the system needs a method to assign the patient to a doctor once they're called up for treatment. To do so, implement a [circularly linked list (CLL)](../../../08_Data_Structures/02_linked_list.md#circularly-linked-list) that allows doctor's names to be stored, so that each time a patient is called up for treatment, the next doctor in the list is displayed.

On startup, the program should take a file containing a list of doctors' names separated by newline characters as an additional command-line argument. If the file does not exist, create an empty file of that name.

For example:

```sh
./bin/emergency_vet animal_queue.dat doctors.dat
```

In order to implement this feature, create the following menu options and any necessary sub-menus:

- `Add New Doctor`
- `Remove Doctor`
- `View Available Doctors`

If no doctors are in the CLL, do not allow the user to call up the next patient without requiring at least one doctor be added to the CLL.

When a user uses the `Save Data` option from the main menu, store the existing list of doctors to a file named `<UNIX TIMESTAMP>_doctors.dat` for easy data persistence and recovery.

## JQR Tasks

Completing this project and all of its requirements successfully will fulfill the following JQR tasks:

- (U) Demonstrate the proper declaration, understanding, and use of C data types and underlying structures.
- (U) Demonstrate proper declaration, understanding, and use of fixed-width C dta types defined in `stdint.h`.
- (U) Demonstrate the ability to create and implement a function that uses different arrays.
- (U) Demonstrate the ability to perform basic arithmetic operations using appropriate C operators while ensuring proper order of operations (PEMDAS).
- (U) Demonstrate the ability to properly use the
standard main() entry arguments.
- (U) Demonstrate the ability to perform file
management operations in C.
- (U) Demonstrate the ability to create and implement
functions to meet a requirement.
- (U) Demonstrate the ability to perform data
validation.
- (U) Demonstrate skill in using pointers.
- (U) Demonstrate skill in creating and implementing
conditional statements, expressions, and constructs.
- (U) Demonstrate the ability to build a binary from
multiple C source files and headers by writing a
Makefile using explicit rules.
- (U) Demonstrate skill in using the C preprocessor.
- (U) Demonstrate skill in controlling memory.
- (U) Demonstrate skill in implementing a priority
queue that accepts any data type.
- (U) Demonstrate skill in using secure coding
techniques.
- (U) Demonstrate the ability to handle partial reads
and writes during serialization and de-serialization.

Completing the extra credit successfully will either fulfill or contribute greatly to the following JQR tasks:

- (U) Demonstrate the ability to use interrupts and signal handling.
- (U) Demonstrate skill in creating and using a
circularly linked list that accepts any data type.

## Turn-In Instructions

Commit your final work to a branch named "develop". When ready for turn-in:

1. Create a "merge request" to merge "develop" into "main".
2. Select your instructor or mentor as the reviewer.
3. Choose the merge option: "Delete source branch when merge is accepted".
