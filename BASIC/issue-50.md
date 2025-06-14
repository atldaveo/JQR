# Issue 50: Describe the concepts and terms associated with key data structures

## Hash Table
A hash table is an indexable table where data, located somewhere within the table, may be accessed/stored given a unique key. 
This table differs from a dictionary in its use of a key and hash function to index data. 

## Stack
An ordered list that employs a last in, first out (LIFO) method of storage. Elements within a stack are either "popped" or 
"pushed. By popping an element, the top element of the stack is moved out. By "pushing" an element, a new element is added
to the top of the stack.   

## The effect of FIFO and LIFO
The effect of FIFO and LIFO are explained in the descriptions of the queue and the stack, respectively.

## Tree vs. Binary Search Tree
A generic tree is a data structure that contains a head node, or a root, that branches into multiple other nodes. Those
subsequent nodes correspondingly branch into their own set of nodes thus creating a hierarchical "tree-like" structure 
of parent-nodes and child-nodes. 

A binary search tree (BST) differs from a generic tree in that a BST is a specific configuration of a generic tree. The  
key features of a BST are that
- Each parent node of a BST has only two child nodes
- All data in the left side of the BST is less than the value of the root
- All data in the right side of the BST is greater than the value of the root
- All ancestral data must follow the BST characteristic

The primary benefit of configuring a BST is the decrease in complexity searching for data in this data structure. Compared
to an unordered, generic tree, a BST yields, at most, a O(n) level of complexity while also producing a sorted list by default
when tracing data through its ancestry. 

## Linked List
A set of nodes that contains two pieces of information - the data itself and a pointer pointing to the next node in the list.
The start of this, singly, linked list is referred to as the head and the pointer in the final node in the list is NULL, 
indicating the end of the list. Searching for information is unidirectional - a query searches only one direction through
all the items in the list until the node is found.   

## Doubly Linked List
A doubly linked list differs from a regular, singly, linked list in that queries are now bi-directional. Pointers in each node
point in either direction. Though a doubly-linked list is more flexible in its traversal, the addition of an extra pointer 
slightly complicates the manipulation of the elements in this linked list. 

## Circularly Linked List
A circularly linked list differs from the previous linked list structures in that these lists do not have ends. Instead of the 
final node in the linked list containing a NULL pointer, the final node of a circularly linked list contains a pointer pointing
back to the head of the list. 

## Queue vs. Priority Queue
A queue holds data in a first in, first out (FIFO) configuration. As such, a generic queue data structure, similar to a stack,
manipulates its data elements using two main operations - enqueue and dequeue. Enqueuing adds elements to the queue while dequeuing
removes elements from the queue. 

A priority queue differs from a traditional queue in that the order of entry into the queue is not the sole factor in which element
is dequeued first. Instead, in addition to the order, a priority attribute is also added to the struct that helps determine the order
in which elements are removed from the queue. The priority is typically encoded using the size of a key. As such, a generic priority
queue will add, remove, and sort elements based on the size of a key rather than in which order the element is entered into the queue.   

## Weighted Graph
A weighted graph is a set of interconnected vertices (nodes) and edges (branches) where the branches have a specific value associated
with them. As such, traversing between vertices using specific edges incurs a certain cost; optimizing traversal is based on the value
of these edges rather than the number of edges between certain nodes.   

## Common Pitfalls when using linked lists, treees, and graphs
- The dynamic allocation of memory when creating data structures creates need to manually free the memory when unused or risk 
memory leaks
- Pointers must be handled meticulously or risk infinite loops (when accidently referencing self) or segmentation faults (when 
dereferencing null pointers)
- Inappropriate use of data structures may lead to suboptimal complexity in containing / sorting through data elements   

## Works Cited
Karumanchi, N. Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles. CareerMonk Publications; 2017.