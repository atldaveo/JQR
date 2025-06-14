# Issue 93: Describe your organization's testing philosophy (e.g. CI/CD, TDD, etc.)

The organization I am currently a part of does not employ a testing philosophy. As such, following is the testing philosophy of tech company Netflix.

## Full-Cycle Development
Engineers are responsible for the entire software lifecycle (from inception to deployment) so the particular DevOps group ends up becoming subject matter experts on the application being made, issues are addressed efficiently, and instill a sense of ownership 

(Fisher et al 2018). 

## Automated Testing
Netflix CI/CD pipeline allows for rapid code integration/deployment while quickly identifying/resolving defects in the application. Moreover, Netflix ensures that its programs are functional over a variety of platforms. As such, automated testing also includes functionality, performance, and stress on a myriad of devices such as phones, computers, etc. 

(Shafeeq 2024)

## Resilience Engineering 
In order to test the robustness and resilience of software, Netflix deliberately introduces system failures using tools like Chaos Monkey and Simian Army. Both of these tools introduce unusual system conditions, simulate random production instance disabilities, terminates random services, and creates failure scenarios that engineers need to adapt. In doing so, Netflix's applications are extremely robust while developers are less likely to be caught off guard when real-world issues do arise.  

(What is Netflix's Chaos Monkey? 2024)

## Works Cited
Fisher-Ogden P, Burrell G, Marsh D. Full Cycle Developers at Netflix - Operate What You Build. [Internet]. Medium; 2018 May 17. [Accessed 2025 Jan 31]. Available from: https://netflixtechblog.com/full-cycle-developers-at-netflix-a08c31f83249

Shafeeq A. The Innovative DevOps Philosophy at Netflix. [Internet]. Dev.To; 2024 Jun 25. [Accessed 2025 Jan 31]. Available from: https://dev.to/azeem_shafeeq/the-innovative-devops-philosophy-at-netflix-528h?

What is Netflix's Chaos Monkey? [Internet]. Geeks for Geeks; 2024 Apr 15. [Accessed 2025 Jan 31]. Available from: https://www.geeksforgeeks.org/what-is-netflixs-chaos-monkey/