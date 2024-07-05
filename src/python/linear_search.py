def linear_search(arr, target):
    for index, value in enumerate(arr):
        if value == target:
            return index
    return -1  # target not found

# Example usage
arr = [4, 2, 7, 1, 3]
target = 7
result = linear_search(arr, target)
print(f'{target} found at index: {result}')  # Output: Target found at index: 2