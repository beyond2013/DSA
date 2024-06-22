# Complexity Analysis

- Data Structures and Algorithms are fundamentally about efficiently using computer resources like memory and processing power (time).

- Just as different problems require different data structures, there are often multiple algorithms to solve the same problem.

- Complexity Analysis is a crucial tool for choosing the best algorithm.

- It analyzes how an algorithm's resource usage (primarily execution time) grows with the size of the input data (represented by n).

- As data size increases, some algorithms become much slower than others.

- Complexity Analysis helps us understand these trade-offs.

- Some algorithms might be very fast for small datasets but slow for large ones.

- Others might optimize for speed by using more memory.

- Additionally, even for the same size input, some algorithms might be more efficient depending on the data's internal order (sorted, random, etc.)

- By understanding these complexities, we can choose algorithms that are efficient for our specific needs and data size.


## Big O Notation

- It is a mathematical tool used in Complexity Analysis to express the upper bound on an algorithm's resource usage (usually time) in terms of its input size (n).

 - It ignores constant factors and lower-order terms, focusing on the dominant factor that determines how the algorithm scales with large inputs.

- Imagine an algorithm takes 10n^2 + 20n + 5 steps for an input size of n. 

- While the exact number of steps depends on n, Big O notation lets us say the algorithm is O(n^2).

- This means the dominant factor is n^2, and the algorithm's time complexity grows proportionally to the square of the input size as n gets very large.

- Common Big O notations include O(1) (constant time), O(n) (linear time), O(n^2) (quadratic time), and O(log n) (logarithmic time).

- By understanding Big O notation, we can compare different algorithms for a task and choose the one that scales best for our expected data sizes. We'll delve deeper into specific Big O notations and their implications in the future. 

## Common Searching and Sorting Algorithms with Big O Notations

| **Algorithm**      | **Type**                     | **Time Complexity (Worst)** | **Space Complexity** |
|--------------------|------------------------------|-----------------------------|----------------------|
| **Linear Search**  | Searching                    | O(n)                        | O(1)                 |
| **Binary Search**  | Searching (Sorted Data Only) | O(log n)                    | O(1)                 |
| **Selection Sort** | Sorting                      | O(n^2)                      | O(1)                 |
| **Insertion Sort** | Sorting                      | O(n^2)                      | O(1)                 |
| **Bubble Sort**    | Sorting                      | O(n^2)                      | O(1)                 |
| **Merge Sort**     | Sorting                      | O(n log n)                  | O(n)                 |
| **Quick Sort**     | Sorting                      | O(n^2) (worst)              | O(log n) (average)   |
| **Heap Sort**      | Sorting                      | O(n log n)                  | O(1)                 |