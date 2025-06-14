# Issue 37: Describe how and when bitwise operators are used:
Can only be used on signed and unsigned integral operands (`char`, `short`, `int`, and `long`).

## AND (&)
Compares each bit of two operands and outputs a 1 only for one instance - when corresponding bits are both equal to 1. 
For example, if `int x = 5` or `0101` and `int y = 9` or `1001`. Then `int Z = x & y` would result in a z value 
of `0001` or `1`. Typically used to mask off some set of bits

## OR (|)
Unless the two compared bit values are both `0`, the result will be `1`. For example, 
if `int x = 0101 0101`, `int y = 1010 1001`, and `int z = x | y` then z's resultant value
is `1111 1101` where the single zero bit occurs in the position where both x and y's bits
were equal to 0. As such, this operator is typically used to turn bits on.  

## XOR (^)
The exclusive OR operator (XOR) produces 1 similar to the OR operator except for the instance of matching
1 bits. For example, if `x = 0101` and `y = 0110`, `x ^ y = 0011`.

## Bitwise Complement (~)
Converts an integer to its 1's complement. In bitwise interpretation, each 1 bit will become a 0 and
each 0 bit will become a 1. 

## Shift Left (<<)
Shifts the bit value of the operand to the left by the value of positions.
`x << 2` Shifts the bits constituting x to the left 2 bits. Assuming `int x = 3` or `0011`,
'x' becomes `0000 1100` or `12`.   Each left shift is equivalent to multiplying by 2. 

## Shift Right (>>)
Shifts the bit value of the operand to the left by the value of positions.
`x >> 1` Shifts the bits constituting x to the left 1 bit. Assuming `int x = 4` or `0100`,
'x' becomes `0010` or `2`.   

## Add, Remove, and Test for single-bit flags
- **Add a single-bit flag**

Assuming a flag variable has been initiated to 0 (all bits are set to 0), using an OR operator and a 
left shift operator, a bit can be flipped within this flag variable based on the condition that caused 
the flag to occur. 

```
int flags = 0;                  // 0000 0000
if (CONDITION)                  
{
    flags |= (1 << 2);          // 0000 0100
}
return 0;
```

- **Remove a single-bit flag**

Given the above example (bit 2 is set to 1), a bitwise complement and AND operators must be used to 
clear / remove the flags. 

```
int flags = 4;                  // 0000 0100
flags &= ~(1 << 2);             // AND against 1111 1011
```

- **Test for a single-bit flag**

To test if a single bit is set to 1, a bit-wise AND must be used - most likely within an if-statement.

```
FLAG_POS            2           // Checking bit-position 2 for flag 

int flags = 4;                  // 0000 0100
if (flags & (1 << FLAG_POS))    // Check if there is a 1 in FLAG_POS within variable flags
{
    [FLAG HAS BEEN SET]
}
else
{
    [FLAG IS STILL 0]
}
```

## Extracting Arbitrary Bytes from multi-byte data types
Using bitwise operations, multi-byte data types may be separated into non-contiguous sets of bytes. 
Assuming a variable of type `int` (4 Bytes) contains usable information in its first 8 bits (little-endian). Bitwise
operators can either be used to extract that Byte of pertinent information or extract the unimportant 
other 24 bits.

```
#include <stdio.h>
#include <stdint.h>

int main()
{
    int number = 0x12345678;
    uint8_t chunked_num[sizeof(number)];

    for (int i = 0; i < sizeof(number); i++)
    {
        uint8_t byte = (number >> (i * 8)) & 0xFF;     // iterate through each set of 8 bits
        chunked_num[i] = byte;                         // store each byte as an individual element in the array
    }

    return 0;
}
```

The body of the code allows for multi-byte data to be manipulated into smaller components using bitwise operators. Either 
arbitrary or important bytes may be extracted from the array. If there is already certainty as to what the requirements are, 
there is not even a need to put the individual portions of the original data type into an array. Instead, the arbitrary bytes
could be masked and, effectively, removed via an AND operator and an explicit casting to `uint8_t`. This way, portability and
direct bit manipulation can be achieved without. 

## Works Cited
Kernighan BW, Ritchie DM. The C (ANSI C) Programming Language. Addison-Wesley; 1988.

Prata S. C Primer Plus. Addison Wesley; 2014.
