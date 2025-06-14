# Issue 58: Demonstrate the ability to analyze sorting routines to determine the most efficient one to use, using an approximation of Big-O notation.

## Insertion Sort
- Worst case complexity: O(n^2)
- Best Case Complexity: O(n)
- Average Complexity: O(n^2)
- Worst case space complexity: O(n^2) total; O(1) auxiliary 

## Selection Sort
- Worst case complexity: O(n^2)
- Best Case Complexity: O(n^2)
- Average Complexity: O(n^2)
- Worst case space complexity: O(1) auxiliary

## Merge Sort
- Worst case complexity: O(nlogn)
- Best Case Complexity: O(nlogn)
- Average Complexity: O(nlogn)
- Worst case space complexity: O(n) auxiliary 

## Heap Sort
- Worst case complexity: O(nlogn)
- Best Case Complexity: O(nlogn)
- Average Complexity: O(nlogn)
- Worst case space complexity: O(n) total; O(1) Auxiliary

## Quick Sort
- Worst case complexity: O(n^2) 
- Best Case Complexity: O(nlogn)
- Average Complexity: O(nlogn)
- Worst case space complexity: O(1) 

## Hashing (For indexing)
- Worst case complexity: O(n)
- Best Case Complexity: O(1)
- Average Complexity: O(1)
- Worst case space complexity: O(n)

## Analysis
Taking into account both the performance and space complexity, each of these algorithms have their different use-cases. For example, selection sort would likely be seldom used based on its requirement to sort through the entire array regardless of how the items were sorted in the first place. As such, hashing would be best for immediate lookups of a large dataset. However, merge sort would probably be subopitmal for limited memory uses as merge sort requires temporary arrays be formed via auxiliary memory requirements. For average use, quick sort would likely be the most efficient for routine use due to its relliable performance and average efficiency .  

## Works Cited
Karumanchi, N. Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles. CareerMonk Publications; 2017.