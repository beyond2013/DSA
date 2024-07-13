# Recursion and Analyzing Recursive Algorithms

## Introduction to Recursion

**Recursion** is a programming technique where:
- a function calls itself directly or indirectly,
- to solve a problem.
- The recursive function generally breaks down a problem into smaller sub-problems of the same type,
- solving each sub-problem recursively.

## Key Components of Recursion

1. **Base Case**: The condition under which the recursion ends. Without a base case, the function would call itself indefinitely, leading to a stack overflow.
2. **Recursive Case**: The part of the function where the function calls itself with a modified argument, moving towards the base case.

## Example of a Recursive Function

A classic example of a recursive function is calculating the factorial of a number.

```python
def factorial(n):
    if n == 0:
        return 1  # Base case
    else:
        return n * factorial(n - 1)  # Recursive case
```

In this example:
- The **base case** is `n == 0`, where the function returns `1`.
- The **recursive case** is `n * factorial(n - 1)`, where the function calls itself with `n - 1`.

## Analysis of Recursive Algorithms

Analyzing recursive algorithms involves determining their correctness, time complexity, and space complexity.

## Correctness

To prove the correctness of a recursive algorithm, we use mathematical induction:
1. **Base Case**: Show that the algorithm works for the simplest case.
2. **Inductive Step**: Assume the algorithm works for all cases up to `k` and then show it works for `k+1`.

## Time Complexity

The time complexity of a recursive algorithm can often be determined by solving a recurrence relation, which represents the total time taken by the algorithm.

### Steps to Determine Time Complexity:

1. **Write the Recurrence Relation**: Identify the relation that defines the time complexity in terms of smaller sub-problems.
2. **Solve the Recurrence**: Use techniques such as the Master Theorem, iteration method, or recursion tree to solve the recurrence.

### Example: Fibonacci Sequence

Consider the naive recursive algorithm to compute the nth Fibonacci number:

```python
def fibonacci(n):
    if n <= 1:
        return n  # Base case
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)  # Recursive case
```

### Recurrence Relation

The time complexity $T(n)$ can be defined as:
$T(n) = T(n-1) + T(n-2) + O(1)$

### Solving the Recurrence

By solving this recurrence, we find that the time complexity is exponential:
$T(n) = O(2^n)$

### Space Complexity

The space complexity of a recursive algorithm is determined by the maximum depth of the recursion stack. Each recursive call adds a new frame to the stack.

### Example: Factorial

For the factorial function:

```python
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)
```

- The depth of the recursion stack is $n$.
- Therefore, the space complexity is $O(n)$.

### Summary

- **Recursion** simplifies the code and divides a problem into sub-problems.
- **Base Case and Recursive Case** are crucial components of a recursive function.
- **Correctness** is often proven using mathematical induction.
- **Time Complexity** can be determined by solving recurrence relations.
- **Space Complexity** depends on the depth of the recursion stack.

Understanding recursion and its analysis helps in designing efficient algorithms and recognizing potential performance bottlenecks.