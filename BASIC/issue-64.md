# Issue 64: Describe terms and concepts associated with secure coding practices

## Common string-handling functions
Functions commonly used and found in the `library string.h`. Functions include `strelen`, `strcpy`, `strcat`, `strncmp`, `strstr`, etc.

## Which functions guarantee null-terminated strings 
`strcpy`, `strncpy`, `strcat`, and `strncat` generate null-terminated strings in C under the library `string.h`. 

## An off-by-one error
A logic error that involves a number that differs from its intended value by 1. Ususally occurs via a non-strict inequality iterating an extra or one fewer iteration. May also occur if the developer fails to recognize zero-based indexing of elements.  

## An integer overflow
When an operation surpasses the maximum possible number that the data point can hold. Generally results in a modulo-type wrap-around outputting a number far less than the intended value. For signed integers, the max possible number would be 2147483647 or 4294967295 for unsigned integers.  

## A buffer overflow
When more data is written to a buffer than it can hold, causing the excess data to overwrite adjacent memory. The writing of data into neighboring, unallotted memory spaces often leads to erratic program behavior and has commonly been used as a security exploit - especially since the C-family of programming does not automatically protect against buffer overflow in an array.   

## The concept of use-after-free
Attempt to access previously freed memory. Even if a memory allocation is freed, the pointer is still pointing to the freed portion of memory. This could lead to erratic program behavior.  

## Reource acquisition is initialization (RAII)
Concept that binds the lifecycle of a resource to the lifetime of an object. Could potentially lead to memory leaks, dangling pointers, resource starvation, and other undefined program behavior if left unchecked in code. RAII commonly occurs when a resource (eg. memory) is allocated, but the program exits without deallocating that resource. 

## The difference between input validation vs. input sanitization
Validation is the process of ensuring that a program operates on clean, correct, and useful data. Techniques include:

- Rejection (Simply not accepting a non-valid input)
- Sanitization (A process that cleans/scrubs the input to match program input requirements as to ensure expected outcomes)
- Escaping (Halting and exiting the program on reception of an invalid input)

**Validation** is how the program handles bad inputs as a whole versus **sanitization** changes the input to make it safe to process.

## The meaning of a pure function and if a function has a side-effect

### Pure Function
A function is considered "pure" if it is
- Deterministic (function has consistent, predictable results without relying on external factors)
- Has no **side effects** (no state outside the scope of the function is affected). Examples of side effects include:
-- Modifying a global/static variable
-- Writing data to a file or database
-- Modifying the DOM (in web development)
-- Printing to the console

## General low-level crypto basics (eg. different encryption schemes and how you might implement them system-wide, what crypto is better for different use cases)
A programming security feature that converts data from plaintext into ciphertext. Encryption works similar to hashing where it involves the use of a cipher algorithm and a key to turn data into an unreadable ciphertext form that, ideally, only those with a key can decode. Examples of basic cuphers include

Encryption Schemes
- Symmetric (Same key for encryption and decryption)
- Asymmetric (Public key for encryption, private key for decryption)
- Hashing (Same input produces the same hash. Small changes produce a completely different hash)

The optimal use of encryption schemes depends on the need of the user. For instance, if speed is an important concern and security is not (eg. file management), symmetric encryption would be optimal. For situations where security is absolutely essential with no concern for processing time (eg. PII storage or digital signatures), users are more likely to use asymmetric encryption. For situations where data integrity and changes in data are immediately evident (eg. storing passwords), one would likely opt to use hasing.

## Penetration testing principles, tools, and techniques
Penetration Testing (or pentesting) allows for external entities to identify potential weaknesses and areas of exploitation inside of a program. Basic pentesting follows five distinct phases:

1. **Planning and reconnaisance**
This phase deals with gathering intelligence on a target. With this background information, pentesters are better able to identify vulnerabilities in the program. Tools commonly used for this phase are 
- Open Source Intelligence (OSINT) 
- WHOIS and DNS Lookup (See who owns a domain and/or its subdomains)
- Shodan (Find specific types of internet-connected devices)

2. **Scanning**
During this phase, pentesters probe the target's cyber-defense using a variety of tools to see how it responds. Tools typically used for this phase include
- Nmap (Network map)
- OWASP Zed Attack Proxy (Web app vulnerability scanner)
- Wireshark (Network protocol analyzer)

3. **Gaining Access**
Once a vulnerability has been identified, pentesters attempt to exploit the vulnerability and escalate their privileges. Tools used for this phase include
- Metasploit (Exploits vulnerabilities)
- SQLmap (Automates detection and exploitation of SQL injection flaws)
- Hydra (Brute force network logon cracker) 

4. **Maintaining Access**
Ensure enduring access upon exploitation. Tools include
- Mimikatz (Extracts passwords, hash, and PIN from memory)
- Netcat (Network utility for reading/writin to network connections)
- PowerSploit (Powershell post-exploitation framework)

5. **Analysis and Reporting**
The final phase of pentesting involves the documentation of found vulnerabilities, how those vulnerabilities could be exploited, and patching recommendations. Tools for this phase include 
- Dradis (Documentation tool)
- db_export (MSF) (Exports data from metasploit's database)
- CherryTree (Hierarchical note-taking application)

## Obfuscation techniques
Obfuscation is a method of programming to make written code confusing to a human viewer while still maintaining its integrity as functioning code. Methods of obfuscation are described below
- **Opaque predicates:** Conditional statements obvious at compile-time, but not for a decompiler
- **Control Flow Flattening:** Convert existing code into a single large switch-case loop as to make it harder to reconstruct the original control flow.
- **String Encryption:** Encrypt string constants up until runtime. Static analysis becomes more difficult.
- **Instruction Substitution:** Turn simple instructions in code into more complex equivalents. 
- **Dead Code Insertion:** Insert functionally useless code into the program to confuse decompilers.
- **Dynamic Code Loading:** Load only portions of code at runtime so that the created binary does not immediately show all parts of the loaded code.
- **Anti-Debugging Techniques:** Implement code that changes program behavior upon detection of a debugger.
- **Code Packing:** Using a packer to compress and encrypt the original binary that unpacks at runtime.

## Works Cited

Gopalakrishna D. 2024. 11_Secure_Coding/11.1_Terms_and_Concepts. [class resource]. Basic Level Curriculum Repository. [US Army Cyber School]. 