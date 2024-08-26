# Binary Search Tree (BST) Data Structure

A **Binary Search Tree (BST)** is a node-based data structure where:
- Each node has at most two children, (referred to as the left child and the right child)
- It is a binary tree with the following properties:
  1. **Left Subtree Property**: The left subtree of a node contains only nodes with values less than the node's key.
  2. **Right Subtree Property**: The right subtree of a node contains only nodes with values greater than the node's key.
  3. **No Duplicates**: There are no duplicate nodes.
- These properties make it easy to search for an element in O(log n) time in a balanced BST.

```
      50
     /  \
   30    70
   / \   / \
 20  40 60  80
```

## C++ Implementation of BST
Explanation of the code is appended to the bottom of the source code.

[link to c++ implementation of BST](../src/cprog/bst.cpp)

## Importance of BST

1. **Efficient Searching**: BST allows for quick lookup, addition, and removal of items, which makes it suitable for applications where search operations are frequent.
  
2. **Dynamic Data**: Unlike arrays, BSTs don't require resizing, making them ideal for dynamic datasets.

3. **Ordered Data**: BST maintains an order of elements, which means that in-order traversal will give the elements in a sorted order.

### Applications of BST

1. **Databases**: BSTs are often used to implement indexing in databases, enabling efficient data retrieval.

2. **Sorting**: Although not as efficient as specialized sorting algorithms, in-order traversal of a BST can be used to sort elements.

3. **Priority Queue**: BSTs can be used in the implementation of priority queues where quick access to the smallest or largest element is required.

4. **Symbol Tables**: In compilers and interpreters, BSTs are used to implement symbol tables, where identifiers are stored and accessed efficiently.

The BST's balance is crucial for maintaining its efficiency, as unbalanced BSTs can degrade to a linked list in the worst case, leading to O(n) time complexity for operations. Hence, variants like AVL trees and Red-Black trees are often used to maintain balance.