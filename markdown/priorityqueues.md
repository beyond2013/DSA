# Priority Queues

A **priority queue** is a type of abstract data structure that, similar to a regular queue, supports insertion of elements. However, in a priority queue, each element is associated with a priority, and the element with the highest priority is dequeued (removed) first. If two elements have the same priority, they are processed according to the order in which they were added, similar to a regular queue.

## Key Operations in a Priority Queue:
1. **Insert (enqueue)**: Add an element to the priority queue.
2. **Delete (dequeue)**: Remove the element with the highest priority from the queue.
3. **Peek/Top**: Retrieve the highest priority element without removing it.

## Implementation Approaches:

There are various ways to implement a priority queue, with two common approaches being **array-based implementation** and **linked list-based implementation**. Let's dive into each approach in detail.

### 1. Array-Based Implementation of Priority Queue

In an array-based priority queue, elements are stored in an array, and the priority is managed by their position in the array. There are a few possible strategies to manage priorities within an array:

### a. Unsorted Array:
- **Insertion**: Inserting an element is simple and efficient (O(1)) because you just add the element at the end of the array.
- **Deletion**: When deleting, you must find the element with the highest priority, which requires scanning the entire array (O(n)).
- **Space Complexity**: O(n), where `n` is the number of elements.

**Example Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<pair<int, int>> queue; // pair<element, priority>

public:
    void insert(int element, int priority) {
        queue.push_back(make_pair(element, priority));
    }

    int deleteMax() {
        if (queue.empty()) return -1;

        int maxIndex = 0;
        for (int i = 1; i < queue.size(); i++) {
            if (queue[i].second > queue[maxIndex].second) {
                maxIndex = i;
            }
        }

        int maxElement = queue[maxIndex].first;
        queue.erase(queue.begin() + maxIndex);
        return maxElement;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(10, 2);
    pq.insert(15, 5);
    pq.insert(20, 1);

    cout << pq.deleteMax() << endl; // 15
    return 0;
}
```

### b. Sorted Array:
- **Insertion**: Inserting an element requires placing it in its correct position based on its priority, which requires shifting elements (O(n)).
- **Deletion**: Deleting the element with the highest priority is efficient because it’s always at one end of the array (O(1)).
- **Space Complexity**: O(n).

**Example Code:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PriorityQueue {
    vector<pair<int, int>> queue; // pair<element, priority>

public:
    void insert(int element, int priority) {
        queue.push_back(make_pair(element, priority));
        sort(queue.begin(), queue.end(), [](auto &left, auto &right) {
            return left.second > right.second;
        });
    }

    int deleteMax() {
        if (queue.empty()) return -1;
        int maxElement = queue.front().first;
        queue.erase(queue.begin());
        return maxElement;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(10, 2);
    pq.insert(15, 5);
    pq.insert(20, 1);

    cout << pq.deleteMax() << endl; // 15
    return 0;
}
```

## 2. Linked List-Based Implementation of Priority Queue

In a linked list-based priority queue, elements are stored in nodes, and each node contains a pointer to the next node. The priorities are managed by the order in which the nodes are connected.

### a. Unsorted Linked List:
- **Insertion**: Adding a new node to the front or end of the linked list is simple and efficient (O(1)).
- **Deletion**: Removing the highest-priority element requires traversing the list to find it (O(n)).
- **Space Complexity**: O(n).

**Example Code:**
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data, priority;
    Node* next;
};

class PriorityQueue {
    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    void insert(int element, int priority) {
        Node* newNode = new Node();
        newNode->data = element;
        newNode->priority = priority;
        newNode->next = head;
        head = newNode;
    }

    int deleteMax() {
        if (!head) return -1;

        Node* maxNode = head;
        Node* temp = head;
        Node* prev = nullptr;
        Node* maxPrev = nullptr;

        while (temp) {
            if (temp->priority > maxNode->priority) {
                maxNode = temp;
                maxPrev = prev;
            }
            prev = temp;
            temp = temp->next;
        }

        if (maxPrev) {
            maxPrev->next = maxNode->next;
        } else {
            head = maxNode->next;
        }

        int maxElement = maxNode->data;
        delete maxNode;
        return maxElement;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(10, 2);
    pq.insert(15, 5);
    pq.insert(20, 1);

    cout << pq.deleteMax() << endl; // 15
    return 0;
}
```

### b. Sorted Linked List:
- **Insertion**: Adding a new node requires traversing the list to find the correct position based on its priority (O(n)).
- **Deletion**: Removing the element with the highest priority is efficient as it's always at the front (O(1)).
- **Space Complexity**: O(n).

**Example Code:**
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data, priority;
    Node* next;
};

class PriorityQueue {
    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    void insert(int element, int priority) {
        Node* newNode = new Node();
        newNode->data = element;
        newNode->priority = priority;

        if (!head || head->priority < priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    int deleteMax() {
        if (!head) return -1;

        int maxElement = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return maxElement;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(10, 2);
    pq.insert(15, 5);
    pq.insert(20, 1);

    cout << pq.deleteMax() << endl; // 15
    return 0;
}
```

## Practical Applications of Priority Queues:

1. **Task Scheduling**: In operating systems, priority queues are used to manage processes and tasks, where tasks with higher priority are executed before others. This is crucial in real-time systems where certain operations must occur within strict time constraints.

2. **Dijkstra’s Algorithm**: Priority queues are used in graph algorithms like Dijkstra's shortest path algorithm. The queue helps efficiently pick the next node with the smallest tentative distance.

3. **Huffman Encoding**: Priority queues are used in Huffman encoding to build optimal prefix codes for data compression. The queue helps select the two lowest-frequency nodes at each step.

4. **Event Simulation**: In discrete event simulation, events are scheduled at various points in time. A priority queue is used to efficiently manage these events in the order of their scheduled times.

5. **AI and Machine Learning**: Priority queues are utilized in search algorithms like A* search for pathfinding and game AI. The queue manages the nodes to explore, prioritizing those with the lowest cost.

6. **Load Balancing**: In distributed systems, priority queues are used to manage tasks and balance the load efficiently across servers by prioritizing tasks based on urgency or resource needs.

## Conclusion:

Priority queues are a versatile and powerful data structure that plays a critical role in various applications, from operating systems to AI. Depending on the requirements for insertion and deletion operations, different implementations (array-based or linked list-based) can be chosen. Understanding both implementations and their trade-offs helps in selecting the best approach for specific use cases.