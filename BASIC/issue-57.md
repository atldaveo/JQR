# Issue 57: Describe concepts associated with hashing

## Data distribution as it relates to hashing
Since a hash table maps data into a hash table using a key and a hash function, the key-function combination ought to
output a unique index so that data can be distributed as evenly as possible. However, given an uncertain number of elements,
it is difficult to ensure that a key-function combination will yield a completely unique index; especially if the number of 
elements increases in number to a size comparable to the size of the hash table itself.  

## Hash function efficiency
- Ability for the function to evenly distribute objects across a hash table (low load factor)
- Index is calculated quickly
- Collisions are minimized (or at least resolved effectively)

## Hash collisions
Collisions occur when an element is mapped to an already occupied space within a hash table. Collisions are inevitable due to a conflict between
storage requirements and imperfect hash functions. However, collisions are resolvable. Two popular techniques are described below. 
- **Direct Chaining**: Individual buckets are structured as linked lists so that more than one element can occupy a single bucket.    
- **Open Addressing**: If an address in the table is already occupied, the element requiring storage is moved into a neighboring bucket.

## Works Cited
Karumanchi, N. Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles. CareerMonk Publications; 2017.