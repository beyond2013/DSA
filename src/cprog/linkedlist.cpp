#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head;

    LinkedList()
    {
        head = nullptr;
    }

    // Function to insert a node at the beginning
    void insertAtBeginning(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a node at the end
    void insertAtEnd(T data)
    {
        if (head == nullptr)
        {
            insertAtBeginning(data);
            return;
        }

        Node<T> *newNode = new Node<T>(data);
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to delete a node
    void deleteNode(T data)
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->data == data)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp; // delete keyword is used to release dynamically allocated memroy using the new operator
            return;
        }

        Node<T> *temp = head;
        /* the while loop searches for the data in the list
           it will exit in 2 conditions
              1. if the end of list is reached
              2. if the data is found
           on exiting the list a further check using if
           tests if the loop exited upon reaching the end
           of the list if so, it means that the data was not found
           otherwise it would have exited due to a match
        */
        while (temp->next != nullptr && temp->next->data != data)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            return; // Element not found
        }

        Node<T> *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Function to print the linked list
    void printList()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedList<int> list;
    list.insertAtEnd(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.printList(); // Output: 20 10 30

    list.deleteNode(20);
    list.printList(); // Output: 10 30

    return 0;
}

/*
### Explanation
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
*/