#include <iostream>
#include <typeinfo>

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
        if (rear == NULL) // understanding the queue is empty
        {
            front = rear = temp;
            return;
        }
        rear->next = temp; // old rear->next now points to temp
        rear = temp;       // update rear
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
        front = front->next; // old front update
        delete temp;         // memory release
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
    Queue<float> q;
    q.enqueue(10.01);
    q.enqueue(20.02);
    q.enqueue(30.03);

    cout << q.dequeue() << endl; // Output: 10
    cout << q.peek() << endl;    // Output: 20
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    auto returnedval = q.dequeue();
    cout << typeid(returnedval).name() << endl;
    Queue<string> q2;
    cout << endl;
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