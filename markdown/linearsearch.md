# Linear Search

Linear search is a simple algorithm used to find a particular value in a list. It works by checking each element of the list one by one until the desired element is found or the list ends. Here's a step-by-step explanation:

## Steps of Linear Search:

1. **Start at the beginning**: Begin with the first element of the list.
2. **Check each element**: Compare the current element with the target value.
3. **If a match is found**: Return the index of the matching element.
4. **If no match is found**: Move to the next element and repeat step 2.
5. **End of list**: If the end of the list is reached without finding a match, return a value indicating the target is not in the list (often -1 or `None`).

## Example:

Suppose we have a list `[4, 2, 7, 1, 3]` and we want to find the index of the value `7`.

1. Compare `4` with `7` (not a match).
2. Compare `2` with `7` (not a match).
3. Compare `7` with `7` (match found).
4. Return the index `2`.

## Pseudocode:

Here's the pseudocode for linear search:

```
function linear_search(array, target):
    for index from 0 to length(array) - 1:
        if array[index] == target:
            return index
    return -1  // target not found
```

### Python Implementation:

Here is a simple implementation of linear search in Python:

```python
def linear_search(arr, target):
    for index, value in enumerate(arr):
        if value == target:
            return index
    return -1  # target not found

# Example usage
arr = [4, 2, 7, 1, 3]
target = 7
result = linear_search(arr, target)
print(f'Target found at index: {result}')  # Output: Target found at index: 2
```

## Time Complexity:

- **Best case**: \(O(1)\) (if the target is the first element)
- **Worst case**: \(O(n)\) (if the target is the last element or not present)
- **Average case**: \(O(n)\)

### Why Average case time complexity is \(O(n)\)

The average case time complexity of linear search is \(O(n)\) because, on average, the target element will be found halfway through the list.

To understand why, consider the following:

1. **Uniform Distribution Assumption**: We assume that the target element is equally likely to be at any position in the list. This means it could be found anywhere from the first position to the last with equal probability.

2. **Average Position Calculation**: If we have a list of \(n\) elements, the target element could be in any of the \(n\) positions. To find the average number of comparisons needed, we consider the sum of the positions divided by the total number of positions.

   The positions range from 1 to \(n\), and the sum of the first \(n\) natural numbers is \(\frac{n(n + 1)}{2}\). The average position is:
   \[
   \text{Average position} = \frac{1 + 2 + 3 + \ldots + n}{n} = \frac{\frac{n(n + 1)}{2}}{n} = \frac{n + 1}{2}
   \]

3. **Average Comparisons**: On average, we need to make \(\frac{n + 1}{2}\) comparisons to find the target. As \(n\) grows larger, the \(\frac{1}{2}\) becomes less significant, and the number of comparisons is approximately \(\frac{n}{2}\).

4. **Asymptotic Notation**: In Big-O notation, constant factors and lower-order terms are ignored because they have less impact on the growth rate as \(n\) increases. Therefore, \(\frac{n}{2}\) is simplified to \(O(n)\).

So, the average case for linear search is \(O(n)\) because, on average, you have to search through half of the list to find the target element.

## Summary
Linear search is easy to implement and understand, but it is not the most efficient for large lists compared to other searching algorithms like binary search. However, it is useful when dealing with small or unsorted lists.