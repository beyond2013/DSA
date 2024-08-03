**Credits:** Contents presented here are taken from the book *Theory and problems of Data Structures* by *Seymour Lipschutz*.

# Stacks
---
A stack is a list of elements in which an element may be inserted or deleted only at one end, called the *top* of the stack.  
This means that elements are removed from a stack in the reverse order of that in which they were inserted into the stack.  

Special terminology is used for the two basic operations associated with stacks.

a) **Push** is the term used to insert an element into a stack.  
b) **Pop** is the term used to delete an element from a stack.

## Array Representation of Stacks
---
Stacks may be represented in the compuer in various ways, usually by means of a one-way list or a linear array. Following text uses **STACK** to refer to linear array representation of stack, a pointer variable **TOP** points to the top element of stack and variable **MAXSTK** gives the maximum number of elements that can be held by the stack. TOP = 0 or TOP = NULL means that the stack is empty.

Following procedures present how an **ITEM** can be **pushed** or **poped** from a stack.

Following procedure pushes an ITEM onto a stack.

```
PUSH(STACK, TOP, MAXSTK, ITEM)  
1. if TOP = MAXSTK, then: Print: OVERFLOW and Return.
2. Set TOP:= TOP + 1.
3. Set STACK[TOP] := ITEM.
4. Return.
```
Following procedure deletes the top element of STACK and assigns it to the variable ITEM.  

```
POP(STACK, TOP, ITEM)  
1. If TOP = 0, then: Print: UNDERFLOW, and Return.
2. Set ITEM := STACK[TOP].
3. Set TOP := TOP - 1.
4. Return.
```

## Implementing Stacks using linked list
[Link to c++ implementation](../src/cprog/stackusinglinkedlist.cpp)

### Explanation
  1. Node Structure:
     - Each node contains data and a pointer to the next node.

  2. Stack Class:
      - top: Pointer to the top node of the stack (head of the linked list).
      - isEmpty(): Checks if the stack is empty.
      - push(T data):
         + Creates a new node with the given data.
         + Sets the new node's next pointer to the current top.
         + Updates top to point to the new node.
      - pop():
         + Checks for an empty stack.
         + Removes the top node.
         + Returns the data of the removed node.
      - peek(): Returns the data at the top of the stack without removing it.
  3. Advantages of Using Linked List for Stack
    - Dynamic sizing: No need to pre-allocate a fixed size array.
    - Efficient insertions and deletions: Operations can be performed in constant time O(1).
    - Flexibility: Can be used for other data structures like queues and graphs.  

By using a linked list, we effectively implement a stack with the required LIFO behavior. This approach provides flexibility and efficiency in managing stack operations.


## Using Stack as a tool to evaluate arithmetic expressions in reverse Polish notation
---


Following Algorithm finds the VALUE of an arithmetic expression  P written in postfix notation.

```
1. Add a right parenthesis ")" at the end of P.  
2. Scan P from left to right and repeat Step 3 and 4 for each element of P until ) is encountered.  
3. If an operand is encountered, put it on STACK.  
4. If an operator is encountered, then:  
  a) Remove the two top elements of STACK, where A is the top element and B is the next-to-top element.  
	b) Evaluate B opr A.  
	c) Push the result of b) back on STACK.
  [End of If structure]
[End of Step 2 loop]
5. Set VALUE equal to the top element of STACK.
6. Exit.
