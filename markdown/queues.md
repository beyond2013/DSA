# Queue Data Structure


A queue is a linear data structure that follows the **First In First Out (FIFO)** principle. This means the first element added to the queue is the first one to be removed. It's like a line of people waiting for their turn.

**Basic Operations:**

<img src="../fig/queue.png" width="200" height="150" align="right">

* **Enqueue:** Adds an element to the rear of the queue.
* **Dequeue:** Removes an element from the front of the queue.
* **Peek:** Returns the element at the front of the queue without removing it.
* **IsEmpty:** Checks if the queue is empty.
* **IsFull:** Checks if the queue is full (only applicable for array implementation).

## Implementation Using Array
[link to c++ implementation of queue using Array](../src/cprog/queuearray.cpp)

**Explanation:**
* The `front` and `rear` pointers keep track of the queue's ends.
* The `% capacity` operation is used for circular queue implementation to efficiently utilize the array.
* The `enqueue` operation adds an element to the rear, incrementing `rear`.
* The `dequeue` operation removes an element from the front, incrementing `front`.
* The `peek` operation returns the element at the front without removing it.
* The `isEmpty` and `isFull` functions check the queue's state.

## Implementation Using Linked List
[link to implementation using linked list ](../src/cprog/queuearray.cpp)

**Explanation:**
* The `front` and `rear` pointers point to the first and last nodes respectively.
* The `enqueue` operation creates a new node, adds it to the rear, and updates `rear`.
* The `dequeue` operation removes the front node, updates `front`, and deletes the removed node.
* The `peek` operation returns the data of the front node.
* The `isEmpty` function checks if the queue is empty.

## Practical Applications of Queues

* **Breadth-First Search (BFS) in graphs**
* **Operating System:** Process scheduling, disk scheduling
* **Networking:** Packet routing, message queuing
* **Simulations:** Waiting lines, queues in supermarkets, etc.
* **Data structures:** Implementing stacks, priority queues
* **Caching:** LRU(Least Recently Used) cache replacement

Queues are essential in various computing scenarios due to their efficient handling of data in a first-in-first-out manner.
 
