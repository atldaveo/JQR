# Issue 90: Describe the difference between static and dynamic analysis

## Static Analysis
Analyzing executables without actually running the running the code. Usually a precursor to dynamic analysis - by conducting static analysis, the analyzer avoids the danger of running a potentially malicious executable. 
(Dewhurst 2025)

The following are tools and techniques that can support static analysis
- Hex viewers and editors (View hex representation of a file)
- File identification (Determine characteristics of a file like type, embedded data, metadata, integrity, etc.)
- Hashing (Determining integrity or known malicious software)
- Disassembly (Converting binary into assembly to see how if works)
- Binary diffing (Comparing binaries)
(Chubb 2024)

## Dynamic Analysis
Dynamic analysis, on the other hand, is an analysis of an executable while the executable is running. During dynamic analysis, a program's behavior, interaction with environment, input handling, etc. are all observed all during runtime. 
(NIST 2020) 

Common tools for dynamic analysis are as follows:
- GNU Debugger (Memory usage, variables, and flow) 
- Valgrind (Memory leaking)
- Perf (Linux performance)
- ProcMon (Windows operations)
- OWASP ZAP (Web app vulnerabilities)
(Chubb 2024)

## Works Cited
Chubb I. 01_Reverse_Engineering. [Class Resource]. Basic Level Curriculum 
Repository; 2024 Aug. [Accessed 2025 Jan 28]. [US Army Cyber School].

Dewhurst R. Static Code Analysis. [Internet]. OWASP. [Accessed 2025 Jan 28]. Available from: https://owasp.org/www-community/controls/Static_Code_Analysis

NIST (National Institute of Standards and Technology). 2020. Security and privacy controls for information systems and organizations. NIST Special Publication 800-53, Revision 5. Gaithersburg (MD): National Institute of Standards and Technology. [accessed 2025 Jan 28]. https://doi.org/10.6028/NIST.SP.800-53r5