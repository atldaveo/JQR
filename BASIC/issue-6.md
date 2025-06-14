# Issue 6: Describe the classification levels of the development networks and the associated handling requirements of source code and binaries for your organization

To combat insider threats, it is prudent to assign each project to more than one person in a "zero-trust" security model (JP 3-12 2022).

## Classifications 

- **Public (Unclassified) Network**: Source code is intended for public release or openly sourced, Data can be saved / transferred / stored without encryption.

- **Internal (Confidential) Network**:  Not intended for public release. code is proprietary / internally used by the owning organization. Must encrypt data when transferring / transporting, source code / binaries must be stored and secure repositories with version control, and must authenticate personnel wishing to handle the network,

- **Restricted (Sensitive) Network**: For sensitive projects involving intellectual property, regulatory compliance, or client-specific requirements. Strict access control to include MFA. Source code is segregated and kept in isolation. Must encrypt when transporting. Limited use of peripherals.

- **Classified Network** : For highly sensitive or government-classified projects. Code must be in complete isolation, source code must be encrypted both while moving and at rest. Must comply with relevant government or regulatory standards (like NIST).

(NIST SP 800-53 2020)

 ## Handling Source Code and Binaries
 - Role-based access control to restrict code viewership and modification to those with appropriate credentials.
 - Encrypt all source code / binaries
 - Regular auditing and monitoring
 - Regular (encrypted) backups and version control
 - Isolate each stage of the development process  
(Secure Coding Practices 2025)

## Works Cited
Joint Publication 3-12: Joint Cyberspace Operations. Department of Defense; 2022 Dec 22. https://jdeisjsmil.

NIST SP 800-53 Rev. 5: Security and Privacy Controls for Information Systems and Organizations. National Institute of Standards and Technology (NIST) Computer Security Resource Center; 2020 Sep [updated 2023 Dec 19]. https://csrc.nist.gov/pubs/sp/800/53/r5/upd1/final. 

Secure Coding Practices. Open Worldwide Application Security Project (OWASP). [accessed 2025 Jan 7]. https://owasp.org/www-project-secure-coding-practices-quick-reference-guide/stable-en/01-introduction/05-introduction. 