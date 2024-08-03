# Linked List

- A linked list is a data structure used to store a collection of elements.
-  Each element in a linked list is called a node, and each node contains two parts: 
     1. Data: The value stored in the node.
     2. Pointer: A reference to the next node in the sequence.

- Linked lists are dynamic data structures, which means they can grow and shrink in size during runtime.
- They are useful for applications where the number of elements is unknown beforehand.

## Types of Linked Lists

1. **Singly Linked List**: Each node points to the next node in the sequence and the last node points to `NULL`.

2. **Doubly Linked List**: Each node has two pointers: one pointing to the next node and another pointing to the previous node.

3. **Circular Linked List**: Similar to a singly linked list, but the last node points back to the first node instead of `NULL`.

## Implementation Using Arrays in C

### Singly Linked List

In a singly linked list, each node points to the next node.

[Link to c implementation of singly linked list](../src/cprog/singlylist.c)


### Doubly Linked List

In a doubly linked list, each node points to both the next and previous nodes.

[Link to c implementation of doubly linked list](../src/cprog/doublylist.c).


### Circular Linked List

In a circular linked list, the last node points back to the first node. 

[Link to implementation in C](../src/cprog/circularlist.c).

## Implementation Using pointers in C++

[Link to c++ implementation](../src/cprog/linkedlist.cpp)

### Summary of implementation

1. **Node class:** Represents a single node with data and a pointer to the next node.
2. **LinkedList class:** Represents the linked list with a pointer to the head node.
3. **insertAtBeginning():** Inserts a new node at the beginning of the list.
4. **insertAtEnd():** Inserts a new node at the end of the list.
5. **deleteNode():** Deletes a node with the given data from the list.
6. **printList():** Prints the elements of the linked list.

This implementation provides a basic foundation for linked lists. You can extend it with additional functions like searching, reversing, and other operations as needed.

**Remember:**
* To use this code with different data types, replace `int` with the desired data type in the `LinkedList` and `Node` templates.
* Proper memory management is essential to avoid memory leaks. Consider using smart pointers like `std::unique_ptr` for more robust implementations.

This code offers a clear and efficient way to implement linked lists in C++ while adhering to object-oriented principles.

## Potential Applications of each type of linked list

Linked lists are versatile data structures that can be used in various applications due to their dynamic nature. Here are some potential applications for each type of linked list:

### Singly Linked List

1. **Stack Implementation**: Singly linked lists can be used to implement stacks where the insertion (push) and deletion (pop) operations are performed at the beginning of the list.
2. **Queue Implementation**: They can also be used to implement queues where insertion (enqueue) occurs at the end and deletion (dequeue) occurs at the beginning.
3. **Adjacency List Representation of Graphs**: In graph theory, singly linked lists can efficiently represent adjacency lists, where each node stores a list of its adjacent nodes.
4. **Dynamic Memory Allocation**: Singly linked lists are used in dynamic memory management systems to keep track of free memory blocks.

### Doubly Linked List

1. **Browser History**: Doubly linked lists can be used to implement the backward and forward navigation in web browsers, allowing traversal in both directions.
2. **Undo-Redo Functionality**: Applications like text editors use doubly linked lists to manage the undo and redo operations, enabling movement forward and backward through the list of actions.
3. **Navigation Systems**: In applications like music players or image viewers, doubly linked lists can manage the navigation of previous and next items efficiently.
4. **Binary Tree Representation**: They can be used to represent binary trees where each node has pointers to its left and right children, allowing for easy traversal and manipulation.

### Circular Linked List

1. **Round-Robin Scheduling**: Circular linked lists are ideal for implementing round-robin scheduling in operating systems, where each process is given a fixed time slice in a cyclic order.
2. **Circular Buffer**: They can be used to implement circular buffers or ring buffers, which are used in buffering data streams.
3. **Multiplayer Games**: In turn-based multiplayer games, circular linked lists can manage the sequence of player turns efficiently.
4. **Music Playlists**: Circular linked lists can manage playlists where the playlist loops back to the beginning after the last song is played, providing continuous playback.

Each type of linked list offers unique advantages that make them suitable for different scenarios. The choice of linked list depends on the specific requirements of the application, such as the need for bidirectional traversal, efficient insertion and deletion, or cyclic behavior.