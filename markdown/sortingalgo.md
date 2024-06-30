# Sorting Algorithms

Here is a brief note on some of the standard sorting algorithms:

## 1. **Bubble Sort**

**Description**: 
Bubble sort is a simple comparison-based algorithm where each pair of adjacent elements is compared, and the elements are swapped if they are in the wrong order. This process is repeated until the list is sorted.

**Time Complexity**:
- Best Case: \(O(n)\)
- Average Case: \(O(n^2)\)
- Worst Case: \(O(n^2)\)

**Space Complexity**: \(O(1)\)

**Use Case**: It is primarily used for educational purposes and is not suitable for large datasets due to its inefficiency.

## 2. **Selection Sort**

**Description**: 
Selection sort divides the list into a sorted and an unsorted region. It repeatedly selects the smallest (or largest, depending on sorting order) element from the unsorted region and moves it to the end of the sorted region.

**Time Complexity**:
- Best Case: \(O(n^2)\)
- Average Case: \(O(n^2)\)
- Worst Case: \(O(n^2)\)

**Space Complexity**: \(O(1)\)

**Use Case**: It is easy to understand and implement, but it is inefficient on large lists.

## 3. **Insertion Sort**

**Description**: 
Insertion sort builds the sorted array one element at a time by repeatedly picking the next element from the unsorted region and inserting it into its correct position in the sorted region.

**Time Complexity**:
- Best Case: \(O(n)\)
- Average Case: \(O(n^2)\)
- Worst Case: \(O(n^2)\)

**Space Complexity**: \(O(1)\)

**Use Case**: It is efficient for small data sets and nearly sorted data.

## 4. **Merge Sort**

**Description**: 
Merge sort is a divide-and-conquer algorithm that recursively divides the list into two halves, sorts each half, and then merges the sorted halves to produce the final sorted list.

**Time Complexity**:
- Best Case: \(O(n \log n)\)
- Average Case: \(O(n \log n)\)
- Worst Case: \(O(n \log n)\)

**Space Complexity**: \(O(n)\)

**Use Case**: It is suitable for large datasets and stable sorting requirements.

## 5. **Quick Sort**

**Description**: 
Quick sort is a divide-and-conquer algorithm that selects a "pivot" element and partitions the array into two halves, with elements less than the pivot on one side and elements greater than the pivot on the other. It then recursively sorts the halves.

**Time Complexity**:
- Best Case: \(O(n \log n)\)
- Average Case: \(O(n \log n)\)
- Worst Case: \(O(n^2)\)

**Space Complexity**: \(O(\log n)\)

**Use Case**: It is highly efficient for large datasets and is often used in practice, though the worst-case performance can be mitigated with good pivot selection strategies.

## 6. **Heap Sort**

**Description**: 
Heap sort builds a heap from the input data, then repeatedly extracts the maximum element from the heap and rebuilds the heap until all elements are sorted.

**Time Complexity**:
- Best Case: \(O(n \log n)\)
- Average Case: \(O(n \log n)\)
- Worst Case: \(O(n \log n)\)

**Space Complexity**: \(O(1)\)

**Use Case**: It is useful for large datasets and when memory usage is a concern.

## 7. **Radix Sort**

**Description**: 
Radix sort is a non-comparison-based algorithm that sorts numbers by processing individual digits. It sorts the elements based on each digit, from the least significant to the most significant.

**Time Complexity**:
- Best Case: \(O(nk)\)
- Average Case: \(O(nk)\)
- Worst Case: \(O(nk)\)

**Space Complexity**: \(O(n + k)\)

**Use Case**: It is efficient for sorting large numbers or strings with a fixed length.

## 8. **Bucket Sort**

**Description**: 
Bucket sort distributes the elements into several buckets, sorts each bucket individually (using another sorting algorithm, often insertion sort), and then concatenates the sorted buckets.

**Time Complexity**:
- Best Case: \(O(n + k)\)
- Average Case: \(O(n + k)\)
- Worst Case: \(O(n^2)\)

**Space Complexity**: \(O(n + k)\)

**Use Case**: It is useful for sorting data that is uniformly distributed over a range.

## Summary

| Algorithm     | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|---------------|-------------------------|---------------------------|-------------------------|------------------|
| Bubble Sort   | \(O(n)\)                | \(O(n^2)\)                | \(O(n^2)\)              | \(O(1)\)         |
| Selection Sort| \(O(n^2)\)              | \(O(n^2)\)                | \(O(n^2)\)              | \(O(1)\)         |
| Insertion Sort| \(O(n)\)                | \(O(n^2)\)                | \(O(n^2)\)              | \(O(1)\)         |
| Merge Sort    | \(O(n \log n)\)         | \(O(n \log n)\)           | \(O(n \log n)\)         | \(O(n)\)         |
| Quick Sort    | \(O(n \log n)\)         | \(O(n \log n)\)           | \(O(n^2)\)              | \(O(\log n)\)    |
| Heap Sort     | \(O(n \log n)\)         | \(O(n \log n)\)           | \(O(n \log n)\)         | \(O(1)\)         |
| Radix Sort    | \(O(nk)\)               | \(O(nk)\)                 | \(O(nk)\)               | \(O(n + k)\)     |
| Bucket Sort   | \(O(n + k)\)            | \(O(n + k)\)              | \(O(n^2)\)              | \(O(n + k)\)     |

These sorting algorithms have different strengths and are chosen based on the specific requirements of the data and the context of the problem.