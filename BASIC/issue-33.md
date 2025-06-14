# Issue 32: Given a specification for a stateful application or protocol, describe and/or draw a diagram of the possible states it can have.

## Example Requirements
Below is a depiction of a finite state machine for a simple user log-in interface that accepts a valid username and password to access an application.

Possible States:
1. LOGGED OUT (Initial state)
2. AUTHENTICATING 
3. LOGGED IN (Final state)
4. LOCKED
5. ERROR

## Show/describe criteria necessary to change between each possible state, show/describe the input/output generated (if any) during the change between each possible state, show/describe the conditions necessary to be in the initial state, show/describe the conditions necessary to get to the final state, show/describe the relationship (if any) between each state in the program, account for any possible error conditions that may occur during state transitions

| Current State     | Change Criteria           | Next State        | Input/Output      |
| ----------------- | ------------------------- | ----------------- | ----------------- |
| LOGGED OUT        | User enters input         | AUTHENTICATING    | in: login info    |
| AUTHENTICATING    | Input is correct          | LOGGED IN         | out: access       |
| AUTHENTICATING    | Input is incorrect        | ERROR             | out: "try again"  |
| ERROR             | User acknowledgement      | LOGGED OUT        | in: user ack
| AUTHENTICATING    | Input is incorrect (x3)   | LOCKED            | in: 3x bad logins |
| LOGGED IN         | User logs out             | LOGGED OUT        | in: logout cmd    |
| LOCKED            | Wait 3 hours              | LOGGED OUT        | out: "try again"  |
