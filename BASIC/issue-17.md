# Issue 17: Describe an example of software development/documentation best practices 

**Software Development Best Practices**
-Comprehensive README ("README.md") outlining the structure of the repo and functions the program is capable of executing.
-API Documentation ("README.md") that describes possible/intedned developer interactions with software such as endpoints, request/response structures, error codes, and authentication methods.
-Strict adherence to style guides (such as BARR C and PEP8) to provide a more readable code.

**Software Documentation Best Practices**
-Requirements ("requirements.txt") outlining how the program ought to function, limits/constraints, cost, etc.
-Use of add-ons such as Doxygen to provide comments (in code) describing the definition, arguments, and parameters of different portions of code.

## Agile Practices

- Incremental deliverables over fixed development periods (aka. sprints)
- Integrating "User Stories" in a backlog as to fully encapsulate the desires and intentions of the customer
- Daily scrums
- Writing tests before writing the actual code to prevent regression (**TDD**)
- Automated deployment of code with continuous (and frequent) integration and delivery (**CI/CD**)
- Frequent meetings and collaboration with stakeholders / customers

## Software Life Cycle for Software Development

Agile / Scrum tenets state an iterative and incremental model that emphasizes constant communication with the customer, rapid delivery of changes/products, and continuous feedback / improvement dialogue for the product over the course of multiple sprints. Requirements, design, coding, testing, and review are all performed concurrently.  

DevOps, according to Microsoft, summarizes the entire lifecycle into planning, development, delivery, and operation. Moreover, DevOps closely follows the practices of CI/CD, Version Control, Agile Software Development, Infrastructure as Code, Configuration Management, and Continuous Monitoring. 

## Version Control 
Management of code in versions as to more easily track changes and revert to previous working versions of the code in case revisions go awry. Moreover, the process of merging code allows for more coordinated collaboration with tight control over what changes are allowed to merge with the main line of effort. 

## Testing
Code should always be and frequently tested as to enhance the resilience of the overall code. Unit tests ought to be standard practice in basic code where assertions are tested as to ensure the integrity of code. In addition to the basic unit testing, other forms of testing should be implemented and documented to identify, and ultimately patch, potential vulnerabilities in all stages of a software lifecycle IAW prevailing attack vectors and unintended usages.   

## Code Reviews
Allowing for team members to review the code written by somebody else. Google breaks down code reviews into distinct dimensions: design, functionality, complexity, tests, naming, comments, style, and documentation. Techniques include a formal review by someone who will provide insights into specific code in a reasonable time or informally through continuous pair programming. Reviewers must observe code and only approve when the final code is in a state that will ultimately advance the overall objective of the application.    

## Requirements Gathering / Analysis
When gathering requirements, developers ought akways probe the stakeholders for what exactly they want as a deliverable. Oftentimes, users don't actually know what they want. As such requirements should arise out of engaging conversations and behaviors through techniques such as user stories. In addition, regular collaborations with the user / stakeholder via sprints can aid in the evolution or clarification of requirements during development. 

## Design / Architecture
The software under development ought to be modular and facilitate automated testing. Additionally, these modules ought to be independent in nature and serve a unique function - in function and in code, don't repeat yourself. Also, towards the beginning of the design process, designs and architectures ought to be validated via prototyping. This way, developers will have an idea what the system will look like end-to-end while having a startpoint and direction to go through the lifecycle of the software.  

## Coding Standards
Organizational style guides provide the manner in which programs are coded. However innocuous as points of style guides may seem, all aspects of code have underlying software design or principles. Such coding standards are based on readability (both for standard code review for google and in print as seen in Barr-C).

## Works Cited
Beck K, Beedle M, van Bennekum A, Cockburn A, et al. Manifesto for Agile Software Development. [Accessed 2025 Apr 12]. Ward Cunnningham. Available from: https://agilemanifesto.org/

Eng-practices. Google. [Accessed 2025 Apr 12]. Available from: https://google.github.io/eng-practices/review/

Gamma E, Helm R, Johnson R, Vlissides J. Design Patterns: Elements of Reusable Object-Oriented Software. Addison-Wesley; 1977.

Jacobs M, Kulia-Mader J, et al. What is DevOps?. Microsoft Corporation; 2023 Jan 24. [Accessed 2025 Apr 12]. Available from: https://learn.microsoft.com/en-us/devops/what-is-devops#devops-and-the-application-lifecycle 

Kernighan BW, Ritchie DM. The C Programming Language: ANSI C. Addison-Wesley; 1988.

Prata S. C Primer Plus. Addison-Wesley; 2014.

Schwaber K & Sutherland J. The Scrum Guide: The Definitive Guide to Scrum: The Rules of the Game. [Accessed 2025 Apr 12]. 2020. Available from: https://scrumguides.org/docs/scrumguide/v2020/2020-Scrum-Guide-US.pdf#zoom=100

Thomas D, Hunt A. The Pragmatic Programmer. Addison-Wesley; 2020.