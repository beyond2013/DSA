# Radix Sort

Radix sort is a non-comparative sorting algorithm that sorts numbers by processing individual digits. It processes the digits from the least significant digit to the most significant digit (LSD radix sort) or vice versa (MSD radix sort). It is often used with integer keys, but it can be adapted for other data types.

## Steps of LSD Radix Sort

1. **Find the maximum number**: Determine the number with the maximum number of digits.
2. **Sort based on each digit**: Starting with the least significant digit, sort the array using a stable sorting algorithm (like counting sort).
3. **Repeat for each digit**: Move to the next significant digit and repeat the sorting process.

## Pseudocode for LSD Radix Sort

Here's a high-level pseudocode for LSD radix sort:

```
RadixSort(arr):
    max_number = find_max(arr)
    num_digits = number_of_digits(max_number)

    for digit in range(num_digits):
        counting_sort(arr, digit)

CountingSort(arr, digit):
    output = [0] * length of arr
    count = [0] * 10

    for number in arr:
        digit_value = extract_digit(number, digit)
        count[digit_value] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(len(arr) - 1, -1, -1):
        digit_value = extract_digit(arr[i], digit)
        output[count[digit_value] - 1] = arr[i]
        count[digit_value] -= 1

    for i in range(len(arr)):
        arr[i] = output[i]

ExtractDigit(number, digit):
    return (number // 10^digit) % 10
```

## Example

Let's go through an example to see how LSD radix sort works.

Suppose we have an array: `[170, 45, 75, 90, 802, 24, 2, 66]`

1. **Find the maximum number**: The maximum number is `802`, which has 3 digits.

2. **Sort based on each digit**:
   - **Ones place**:
     - `[170, 90, 802, 2, 24, 45, 75, 66]`
   - **Tens place**:
     - `[802, 2, 24, 45, 66, 170, 75, 90]`
   - **Hundreds place**:
     - `[2, 24, 45, 66, 75, 90, 170, 802]`

The final sorted array is `[2, 24, 45, 66, 75, 90, 170, 802]`.

## Characteristics of Radix Sort

- **Time Complexity**: O(nk), where n is the number of elements and k is the number of digits in the maximum number.
- **Space Complexity**: O(n + k), where n is the number of elements and k is the range of the digits (usually fixed and small).
- **Stability**: Radix sort is stable; it preserves the relative order of equal elements.
- **Adaptiveness**: Radix sort is efficient for sorting integers and strings, especially when the number of digits or characters is small compared to the number of elements.

## Implementation in Python

Here's how you can implement LSD radix sort in Python:

```python
def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1

    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    max_num = max(arr)
    exp = 1
    while max_num // exp > 0:
        counting_sort(arr, exp)
        exp *= 10

# Example usage
arr = [170, 45, 75, 90, 802, 24, 2, 66]
radix_sort(arr)
print(arr)
```

This code will output the sorted array `[2, 24, 45, 66, 75, 90, 170, 802]`.