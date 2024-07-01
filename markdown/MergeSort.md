# Merge Sort

Merge sort is a popular and efficient sorting algorithm based on the divide and conquer paradigm. It works by recursively dividing the array into two halves, sorting each half, and then merging the sorted halves back together. Here is a step-by-step explanation of the merge sort algorithm:

1. **Divide**: If the array has more than one element, divide it into two halves.
2. **Conquer**: Recursively apply the merge sort to both halves.
3. **Combine**: Merge the two sorted halves to produce a sorted array.

## Pseudocode for Merge Sort

Here's a high-level pseudocode for merge sort:

```
MergeSort(arr):
    if length of arr > 1:
        mid = length of arr / 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        MergeSort(left_half)
        MergeSort(right_half)

        merge(left_half, right_half, arr)

merge(left, right, arr):
    i = j = k = 0

    while i < length of left and j < length of right:
        if left[i] < right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    while i < length of left:
        arr[k] = left[i]
        i += 1
        k += 1

    while j < length of right:
        arr[k] = right[j]
        j += 1
        k += 1
```

## Example

Let's go through an example to see how merge sort works.

Suppose we have an array: `[38, 27, 43, 3, 9, 82, 10]`

1. **Divide**: Split the array into two halves.
   - Left: `[38, 27, 43]`
   - Right: `[3, 9, 82, 10]`

2. **Conquer**: Recursively apply merge sort to both halves.

   - For `[38, 27, 43]`:
     - Split into `[38]` and `[27, 43]`
     - `[38]` is already sorted.
     - Split `[27, 43]` into `[27]` and `[43]`
     - `[27]` and `[43]` are already sorted.
     - Merge `[27]` and `[43]` to get `[27, 43]`
     - Merge `[38]` and `[27, 43]` to get `[27, 38, 43]`

   - For `[3, 9, 82, 10]`:
     - Split into `[3, 9]` and `[82, 10]`
     - Split `[3, 9]` into `[3]` and `[9]`
     - `[3]` and `[9]` are already sorted.
     - Merge `[3]` and `[9]` to get `[3, 9]`
     - Split `[82, 10]` into `[82]` and `[10]`
     - `[82]` and `[10]` are already sorted.
     - Merge `[82]` and `[10]` to get `[10, 82]`
     - Merge `[3, 9]` and `[10, 82]` to get `[3, 9, 10, 82]`

3. **Combine**: Merge the sorted halves `[27, 38, 43]` and `[3, 9, 10, 82]` to get `[3, 9, 10, 27, 38, 43, 82]`

The final sorted array is `[3, 9, 10, 27, 38, 43, 82]`.

## Characteristics of Merge Sort

- **Time Complexity**: O(n log n) in all cases (best, average, worst).
- **Space Complexity**: O(n) due to the temporary arrays used for merging.
- **Stability**: Merge sort is stable; it preserves the relative order of equal elements.
- **Parallelism**: The divide and conquer nature makes merge sort well-suited for parallel processing.

## Implementation in Python

Here's how you can implement merge sort in Python:

```python
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

# Example usage
arr = [38, 27, 43, 3, 9, 82, 10]
merge_sort(arr)
print(arr)
```

This code will output the sorted array `[3, 9, 10, 27, 38, 43, 82]`.