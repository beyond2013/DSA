# Dequeue (Double ended queue)

A **dequeue** (short for **double-ended queue**) is a linear data structure that allows insertion and deletion of elements from both ends, i.e., from the front and the rear. This makes it more flexible than a standard queue, which only allows insertion at the rear and deletion from the front.

## Characteristics of Dequeue:
- **Insertions and Deletions**: You can insert or delete elements from both ends (front and rear).
- **Dynamic Size**: Like other linear structures such as vectors or lists, a dequeue can grow or shrink dynamically.

## Types of Dequeue:
1. **Input-restricted dequeue**: Insertion is restricted to one end, but deletion can occur at both ends.
2. **Output-restricted dequeue**: Deletion is restricted to one end, but insertion can occur at both ends.

## Operations on Dequeue:
- **`push_front(item)`**: Insert an item at the front.
- **`push_back(item)`**: Insert an item at the rear.
- **`pop_front()`**: Remove an item from the front.
- **`pop_back()`**: Remove an item from the rear.
- **`front()`**: Access the front element.
- **`back()`**: Access the rear element.
- **`isEmpty()`**: Check if the dequeue is empty.
- **`size()`**: Get the number of elements in the dequeue.

## C++ Implementation Using STL (Standard Template Library)
C++ provides a `deque` class in the STL, which is a double-ended queue.

Here's a simple C++ implementation:

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;

    // Insert elements at the back
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Insert elements at the front
    dq.push_front(5);
    dq.push_front(1);

    std::cout << "Deque after insertion: ";
    for (int n : dq)
        std::cout << n << " ";
    std::cout << std::endl;

    // Accessing front and back elements
    std::cout << "Front element: " << dq.front() << std::endl;
    std::cout << "Back element: " << dq.back() << std::endl;

    // Remove elements from the front and back
    dq.pop_front();
    dq.pop_back();

    std::cout << "Deque after popping from front and back: ";
    for (int n : dq)
        std::cout << n << " ";
    std::cout << std::endl;

    // Checking size of the deque
    std::cout << "Size of deque: " << dq.size() << std::endl;

    // Checking if the deque is empty
    if (dq.empty())
        std::cout << "Deque is empty" << std::endl;
    else
        std::cout << "Deque is not empty" << std::endl;

    return 0;
}
```

## Explanation of the Code:
1. **Inserting Elements**: 
   - `dq.push_back(10);` adds `10` to the rear of the dequeue.
   - `dq.push_front(5);` adds `5` to the front of the dequeue.
   
2. **Accessing Elements**:
   - `dq.front();` retrieves the first element.
   - `dq.back();` retrieves the last element.

3. **Removing Elements**:
   - `dq.pop_front();` removes the element at the front.
   - `dq.pop_back();` removes the element at the rear.

4. **Checking Size and Emptiness**:
   - `dq.size();` returns the number of elements in the dequeue.
   - `dq.empty();` checks if the dequeue is empty.

This is a basic introduction to dequeue data structures and their operations with a C++ example using the STL.