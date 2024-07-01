# Heap Sort

Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure. It divides the input into a sorted and an unsorted region and iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region.

## Steps of Heap Sort

1. **Build a Max-Heap**: Rearrange the array into a max-heap, where the largest element is at the root.
2. **Extract Elements from the Heap**: Move the root of the max-heap to the end of the array and reduce the heap size. Then heapify the root element to ensure the remaining elements still form a max-heap.
3. **Repeat**: Continue the process until all elements are sorted.

## Pseudocode for Heap Sort

Here's a high-level pseudocode for heap sort:

```
HeapSort(arr):
    n = length of arr

    # Build a max-heap
    for i from n//2 - 1 down to 0:
        heapify(arr, n, i)

    # One by one extract elements
    for i from n-1 down to 0:
        swap arr[0] with arr[i]
        heapify(arr, i, 0)

heapify(arr, n, i):
    largest = i
    left = 2*i + 1
    right = 2*i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        swap arr[i] with arr[largest]
        heapify(arr, n, largest)
```

## Example

Let's go through an example to see how heap sort works.

Suppose we have an array: `[4, 10, 3, 5, 1]`

1. **Build a Max-Heap**:
   - Rearrange the array to `[10, 5, 3, 4, 1]`

2. **Extract Elements from the Heap**:
   - Swap `10` with `1`: `[1, 5, 3, 4, 10]`
   - Heapify root: `[5, 4, 3, 1, 10]`
   - Swap `5` with `1`: `[1, 4, 3, 5, 10]`
   - Heapify root: `[4, 1, 3, 5, 10]`
   - Swap `4` with `1`: `[1, 3, 4, 5, 10]`
   - Heapify root: `[3, 1, 4, 5, 10]`
   - Swap `3` with `1`: `[1, 3, 4, 5, 10]`
   - Heapify root: `[1, 3, 4, 5, 10]`

The final sorted array is `[1, 3, 4, 5, 10]`.

## Characteristics of Heap Sort

- **Time Complexity**:
  - Best case: O(n log n)
  - Average case: O(n log n)
  - Worst case: O(n log n)
- **Space Complexity**: O(1) since it is an in-place sorting algorithm.
- **Stability**: Heap sort is not stable; it does not preserve the relative order of equal elements.
- **Parallelism**: Heap sort is not easily parallelizable due to its inherent sequential nature.

## Implementation in Python

Here's how you can implement heap sort in Python:

```python
def heap_sort(arr):
    n = len(arr)

    # Build a max-heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements one by one
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

# Example usage
arr = [4, 10, 3, 5, 1]
heap_sort(arr)
print(arr)
```

This code will output the sorted array `[1, 3, 4, 5, 10]`.