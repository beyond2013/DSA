#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
};

template <typename T>
class Queue
{
private:
    Node<T> *front, *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(T x)
    {
        Node<T> *temp = new Node<T>();
        temp->data = x;
        temp->next = NULL;
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return T(); // Return default value for the type
        }
        T item = front->data;
        Node<T> *temp = front;
        front = front->next;
        delete temp;
        if (front == NULL)
        {
            rear = NULL;
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
        return front->data;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl; // Output: 10
    cout << q.peek() << endl;    // Output: 20

    Queue<string> q2;
    q2.enqueue("hello");
    q2.enqueue("world");

    cout << q2.dequeue() << endl; // Output: hello

    return 0;
}

/*
## Summary of Coding Examples

* **Purpose:** Implements a queue data structure using a linked list, allowing for dynamic size and generic data types through templates.
* **Key components:**
  * `Node` class: Represents a single element in the queue.
  * `Queue` class: Encapsulates the queue operations.
  * `front` and `rear`: Pointers to the front and rear of the queue.
* **Operations:**
  * `enqueue`: Adds an element to the rear of the queue by creating a new node.
  * `dequeue`: Removes an element from the front of the queue by updating the front pointer and deleting the old node.
  * `peek`: Returns the element at the front without removing it.
  * `isEmpty`: Checks if the queue is empty.
* **Advantages:** Dynamic size, no overflow issues.


*/