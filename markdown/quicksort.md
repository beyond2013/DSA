# Quick Sort

Quick sort is another efficient sorting algorithm, also based on the divide and conquer strategy. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

## Steps of Quick Sort

1. **Choose a Pivot**: Select an element from the array to be the pivot. Common strategies include picking the first element, the last element, or a random element.
2. **Partition**: Rearrange the array so that all elements less than the pivot come before it, and all elements greater than the pivot come after it. The pivot is now in its final position.
3. **Recursively Sort Sub-arrays**: Apply the same process to the sub-arrays of elements with smaller values and those with larger values.

## Pseudocode for Quick Sort

Here's a high-level pseudocode for quick sort:

```
QuickSort(arr, low, high):
    if low < high:
        pi = Partition(arr, low, high)
        QuickSort(arr, low, pi - 1)
        QuickSort(arr, pi + 1, high)

Partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i = i + 1
            swap arr[i] with arr[j]
    swap arr[i + 1] with arr[high]
    return i + 1
```

## Example

Let's go through an example to see how quick sort works.

Suppose we have an array: `[10, 7, 8, 9, 1, 5]`

1. **Choose a Pivot**: Let's pick the last element `5` as the pivot.
2. **Partition**:
   - Move elements less than `5` to the left: `[1, 7, 8, 9, 10, 5]`
   - Swap pivot with the element at its final position: `[1, 5, 8, 9, 10, 7]`
   - Pivot index is `1`.

3. **Recursively Sort Sub-arrays**:
   - Sub-array before pivot: `[1]`
   - Sub-array after pivot: `[8, 9, 10, 7]`

4. Repeat the process for the sub-arrays.

## Characteristics of Quick Sort

- **Time Complexity**:
  - Average case: O(n log n)
  - Best case: O(n log n)
  - Worst case: O(n^2) (e.g., when the pivot selection is poor)
- **Space Complexity**: O(log n) due to the recursion stack.
- **Stability**: Quick sort is not stable; it does not preserve the relative order of equal elements.
- **Parallelism**: Like merge sort, quick sort can be parallelized.

## Implementation in Python

Here's how you can implement quick sort in Python:

```python
def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

# Example usage
arr = [10, 7, 8, 9, 1, 5]
quick_sort(arr, 0, len(arr) - 1)
print(arr)
```

This code will output the sorted array `[1, 5, 7, 8, 9, 10]`.