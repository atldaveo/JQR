# Issue 56: Describe concepts associated with traversal techniques

## Depth-first traversal
When navigating through the different vertices in a graph, a depth-first traversal takes one path to its end before
backtracking to a previous vertex and traversing in-depth again. The technique takes note of the vertices it has visited
using a stack-based visited table. This process is repeated until a specific vertex is found. A pitfall for this type of 
traversal is that the time complexity of this traversal technique is not efficient as the technique will route through all 
vertices and bypass possible shorter routes.   

## Breadth-first traversal
Breadth-first traversal is another graph traversal technique where vertices are classified by level and the route of 
traversal completes an entire level prior to moving further into the graph. This technique thus uses a queue-based 
route guidance. Once the next vertex is reached, the route follows all vertices adjacent to the current one. Once all 
adjacent vertices are visited, the next adjacent vertices are visited. The technique continues this pattern until all 
vertices are visited.   

## Technique of determining the weight of a given path when traversing a graph
Using a distance table, a vertex's distance to adjacent nodes are calculated with the weight multiplier. Based on those values, 
the lowest cost is determined and the BFS continues from the vertex with the lowest cost. This pattern continues until a path is
formed from the origin to its destination. This is the **most efficient path for traversing a graph** - Dijkstra's algorithm. 

## Works Cited
Karumanchi, N. Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles. CareerMonk Publications; 2017.
