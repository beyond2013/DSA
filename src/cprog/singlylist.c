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
    linkedList[newNode].next = head;
    head = newNode;
}

void display()
{
    int current = head;
    while (current != -1)
    {
        printf("%d -> ", linkedList[current].data);
        current = linkedList[current].next;
    }
    printf("NULL\n");
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