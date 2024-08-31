# Heap Data Structure

A Heap is a specialized tree-based data structure that satisfies the following properties:

- **Complete Binary Tree:** It's a binary tree where all levels are completely filled except possibly the last level, which is filled from left to right.
- **Heap Order Property:** For every node, the key (value) of that node is either:
  - greater than or equal to (in a Max Heap) or
  - less than or equal to (in a Min Heap) the keys of its children.

There are two types of heaps:

- **Max Heap:** The key of the root node is greater than or equal to the keys of all its children.
```
       30
      /   \
     20    15
    /  \  /  \
   8   4  7  6
```
- **Min Heap:** The key of the root node is less than or equal to the keys of all its children.

```
        5
      /   \
     8     6
    / \   / \
   10  12 15 13
```
## Importance of Heaps

Heaps are essential data structures due to their efficient operations, particularly:

- **Priority Queue Implementation:**  
  + Heaps are commonly used to implement priority queues, where elements are ordered based on their priority.
  + This is useful in various applications like 
    + scheduling tasks,
    + Dijkstra's algorithm, and 
    + Huffman coding.
- **Efficient Sorting:** Heaps are used in heap sort, a comparison-based sorting algorithm that has a time complexity of O(n log n) in the average and worst cases.
- **Data Structures for Graph Algorithms:** Heaps are used in several graph algorithms, 
  + such as Prim's algorithm for finding the minimum spanning tree and 
  + Dijkstra's algorithm for finding the shortest path.

## C++ Implementation of Heap
Explanation of the code is appended to the bottom as comments.  
[C++ implementation of a Max Heap using an array-based representation](../src/cprog/heap.cpp)

+ This implementation provides basic operations like:
  - insertion
  - extraction of the maximum element, and
  -  heapify, 
which are essential for using heaps in various applications. 
+ You can extend this implementation to include other heap operations as needed.
## interactive visualization
[visit this link for interactive visualization](https://www.cs.usfca.edu/~galles/visualization/Heap.html)