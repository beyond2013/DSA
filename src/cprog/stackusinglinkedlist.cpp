#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;

    Node(T data) : data(data), next(nullptr) {} // constructor
};

template <typename T>
class Stack
{
private:
    Node<T> *top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = top;
        top = newNode;
    }

    T pop()
    {
        if (isEmpty()) // ask gemini why isEmpty not preceded by any reference to object / class this
        {
            // Handle empty stack condition
            throw std::runtime_error("Stack is empty");
        }
        Node<T> *temp = top;
        T data = temp->data;
        top = top->next;
        delete temp;
        return data;
    }

    T peek()
    {
        if (isEmpty())
        {
            // Handle empty stack condition
            throw std::runtime_error("Stack is empty");
        }
        return top->data;
    }
};

int main()
{
    Stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << myStack.peek() << std::endl; // Output: 30

    myStack.pop();
    std::cout << myStack.peek() << std::endl; // Output: 20

    return 0;
}
