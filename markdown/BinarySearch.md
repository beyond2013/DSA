# Binary Search

Binary search is a highly efficient algorithm for finding an element in a sorted list. Unlike linear search, which checks each element one by one, binary search repeatedly divides the search interval in half, which significantly reduces the number of comparisons needed.

## Steps of Binary Search:

1. **Start with the entire list**: Set the initial search interval to cover the whole list.
2. **Find the middle element**: Calculate the middle index of the current search interval.
3. **Compare the middle element**:
   - If it matches the target, return the index.
   - If the target is smaller than the middle element, repeat the search on the left half.
   - If the target is larger than the middle element, repeat the search on the right half.
4. **Narrow down the interval**: Adjust the search interval based on the comparison.
5. **Repeat until the interval is empty**: If the search interval becomes empty and the target is not found, return a value indicating the target is not in the list (often -1 or `None`).

## Example:

Suppose we have a sorted list `[1, 3, 4, 7, 9, 11, 13]` and we want to find the index of the value `7`.

1. The middle element is `7` (index `3`).
2. Compare `7` with `7` (match found).
3. Return the index `3`.

## Pseudocode:

Here is the pseudocode for binary search:

```
function binary_search(array, target):
    left = 0
    right = length(array) - 1
    
    while left <= right:
        middle = (left + right) // 2
        
        if array[middle] == target:
            return middle
        elif array[middle] < target:
            left = middle + 1
        else:
            right = middle - 1
    
    return -1  // target not found
```

## Python Implementation:

Here is a simple implementation of binary search in Python:

```python
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        middle = (left + right) // 2
        
        if arr[middle] == target:
            return middle
        elif arr[middle] < target:
            left = middle + 1
        else:
            right = middle - 1
    
    return -1  # target not found

# Example usage
arr = [1, 3, 4, 7, 9, 11, 13]
target = 7
result = binary_search(arr, target)
print(f'Target found at index: {result}')  # Output: Target found at index: 3
```

## Time Complexity:

- **Best case**: \(O(1)\) (if the target is the middle element in the first check)
- **Worst case**: \(O(\log n)\) (where \(n\) is the number of elements in the list)
- **Average case**: \(O(\log n)\)

## Conditions for Binary Search:

1. **Sorted List**: The list must be sorted for binary search to work correctly.
2. **Random Access**: The list should allow random access (like an array), as binary search requires direct access to elements based on index.

## Summary
Binary search is significantly more efficient than linear search for large lists due to its logarithmic time complexity. However, it is only applicable when the list is sorted.