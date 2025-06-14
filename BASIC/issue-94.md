# Issue 94: Describe the difference between unit testing and functional/integration testing

## Unit Testing
Unit testing is making sure that individual modules of a code function in isolation. It is imperative that each part of the code functions by themselves before attempting to bring everything together to test as a whole. 

## Functional / Integration Testing
Integration testing is validating that all the subsystems are able to work cooperatively in the system as a whole. Funtional / integration testing should be treated as am extension of unit testing, or at least the next iteration of unit testing. Once the sub-systems have been individually tested, those sub-systems need to be tested with other sub-systems until full functional validation has been achieved. Oftentimes, the overall system will be integrated into an even broader system as to necesitate even more integration testing. So in essense, functional and integration testing are merely another form of unit testing. 

Potentially included in this suite of testing is performance testing. Programmers must also rigorously test the program for a variety of suboptimal conditions to ensure that the software is robust enough to field and handle a diverse array of potential use-cases and conditions.  

## Works Cited
Thomas D, Hunt, A. The Pragmatic Programmer. Addison-Wesley; 2020.