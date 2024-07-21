#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data;
    int next;
} Node;

Node linkedList[MAX_SIZE];
int head = -1;
int freeList = 0;

void initializeFreeList()
{
    for (int i = 0; i < MAX_SIZE - 1; i++)
    {
        linkedList[i].next = i + 1;
    }
    linkedList[MAX_SIZE - 1].next = -1;
}

int getNode()
{
    if (freeList == -1)
    {
        return -1;
    }
    int index = freeList;
    freeList = linkedList[freeList].next;
    return index;
}

void freeNode(int index)
{
    linkedList[index].next = freeList;
    freeList = index;
}

void insertAtBeginning(int data)
{
    int newNode = getNode();
    if (newNode == -1)
    {
        printf("No space available\n");
        return;
    }
    linkedList[newNode].data = data;
    if (head == -1)
    {
        linkedList[newNode].next = newNode;
    }
    else
    {
        int current = head;
        while (linkedList[current].next != head)
        {
            current = linkedList[current].next;
        }
        linkedList[newNode].next = head;
        linkedList[current].next = newNode;
    }
    head = newNode;
}

void display()
{
    if (head == -1)
    {
        printf("List is empty\n");
        return;
    }
    int current = head;
    do
    {
        printf("%d -> ", linkedList[current].data);
        current = linkedList[current].next;
    } while (current != head);
    printf("(head)\n");
}

int main()
{
    initializeFreeList();
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);
    display();
    return 0;
}