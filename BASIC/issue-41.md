# Issue 41 - Describe purpose and use of foundational Python mechanics

## The return statement
Leaves the current function call. Moves progress of `try` statement into `finally`. 
Usually denotes the end of a function or main. At the end of a function, the return statement
also outputs the value that the function was coded to return.

### Return values (return type and reference)
Allows a function to provide computed data back to the user. Though the return type is determined at runtime.
The following are examples of what can be returned to the user (at the end of a function):
- One or more values of any data type
- Data structures
- Custom objects 
- References of mutable objects like lists and dictionaries (also means modifications affect the referenced item)

## Data types
The classification or characterization of data items. The difference in data types indicates the intention
of the data's function. Moreover, data types may also vary in size so that they could be more optimally and 
efficiently used within the program. Many data types are already built in, but the developer may also choose
to construct his own data type via a class.

Basic data types include: int, float, and complex
Sequence types include: str, list, tuple, and range
Built-in types include: dict, list, set, frozenset, tuple

### A function
A function object created by user-generated definition. Functions are consequently called using its name
and the pre-programmed argument values to execute an action - potentially returning another object. 
Functions are typically defined as follows:
```
def function_name(parameter1, parameter2):
    function body
    function body
    function body
    return a_value
```
while function calls are external references to a function such as:
```
variable = function_name(par1, par2)
```

### Parameters
A named entity in a function or method definition that specifies an argument. Below 
are the five kinds of parameters:
- positional-or-keyword     (arguments that can be passed via either positionally OR keyword. Default)
- positional-only           (arguments that can only be passed by position between parentheses)
- keyword-only              (argument that can be supplied only by keyword by appending a single * in the spot)
- var-positional            (arguments that are passed by position but sequence does not matter using * before the arg)
- var-keyword               (arguments that can be arbitrary so long as they are prepended with **)

### Scope 
The area in which statements, variables, and/or functions apply. Defines the visibility of a name within a block.
- Global: Applies everywhere there is a reference to the element.
- Nonlocal: Applies only in the scope of the function or class body where it is referenced.
- Local: Applies within the bounds of the block in which it was defined.
- Annotation: Similar to function-level "nonlocal" scope, but applied only to generic and "lazy" data. 

### Import files 
Imports are executed in two phases:
1. Find, load, initialize referenced module / package.
2. Define a name or names in the local namespace for the scope where the import statement occurs. 
This operation allows developers access to pre-made functions and databases.

## Mutable
Contents of mutable sequences can be changed after creation. As such, elements that belong in 
a mutable sequence are susceptible to modification. Examples include **lists**, sets, and byte arrays.

### List
A list of iterable elements. List elements are typically homogenous and mutable. 
They can be defined in the following ways

1. []                           (Denote empty list - default)
2. [a, b, c]                    (Data inside brackets separated by commas)
3. [x for x om oterable]        (List comprehension)
4. list(iterable)               (Type constructor)

### Dictionaries
A representation of finite sets of objects indexed by almost any values known as keys. Keys must be
compared by object identity rather than value (Cannot use values containing mutable sequences as keys).
Dictionaries function as a look-up based on the submitted key while also preserving insertion order.
Dictionaries are mutable. They are created using `{}`.

## Immutable
Contents of immutable sequences cannot be changed after creation. The only exception to this rule
is if the immutable sequence held references to mutable objects; the reference itself cannot change, 
but the mutable object referenced can be modified. Examples include strings, **tuples**, frozen sets, and bytes.

### Tuple
Typically used to store collections of heterogeneous data or an immutable sequence of homogenous data. Tubles are 
constructed as follows:
- `()`                                  (empty parentheses for empty tuple)
- `a, b, c` or `(a, b, c)`              (comma separated items)
- `tuple()` or `tuple(iterable)`        (explicit function call)

#### Singleton
A tuple of one item. Constructed as follows:
- `a,` or (a,)                          (trailing comma after one element indicates singleton)

## Works Cited
Python 3.13.1 documentation. Python Software Foundation; 2025 Jan 16. https://docs.python.org/3/.