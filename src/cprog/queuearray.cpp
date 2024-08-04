#include <iostream>

using namespace std;

template <typename T>
class Queue
{
private:
    T *array;
    int front, rear, size;
    int capacity;

public:
    Queue(int cap)
    {
        capacity = cap;
        front = rear = -1;
        array = new T[capacity];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }

    void enqueue(T x)
    {
        if (isFull())
        {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = x;
        if (front == -1)
        {
            front = rear;
        }
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return T(); // Return default value for the type
        }
        T item = array[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        return item;
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return T(); // Return default value for the type
        }
        return array[front];
    }
};

int main()
{
    Queue<int> q(5); // Queue for integers
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl; // Output: 10
    cout << q.peek() << endl;    // Output: 20

    Queue<string> q2(3); // Queue for strings
    q2.enqueue("hello");
    q2.enqueue("world");

    cout << q2.dequeue() << endl; // Output: hello

    return 0;
}

/*

## Summary of Coding Examples

### Template-Based Queue using Array

* **Purpose:** Implements a queue data structure using a fixed-size array, allowing for generic data types through templates.
* **Key components:**
  * `Queue` class: Encapsulates the queue operations.
  * `array`: Stores the queue elements.
  * `front`, `rear`, and `size`: Track the queue's state.
  * `capacity`: Maximum size of the queue.
* **Operations:**
  * `enqueue`: Adds an element to the rear of the queue.
  * `dequeue`: Removes an element from the front of the queue.
  * `peek`: Returns the element at the front without removing it.
  * `isEmpty`: Checks if the queue is empty.
  * `isFull`: Checks if the queue is full.
* **Limitations:** Fixed size, potential for overflow if not managed carefully.
*/