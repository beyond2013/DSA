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
import random
import time

arr = random_integers = [random.randint(1, 100000000) for _ in range(1000)]
# arr = [38, 27, 43, 3, 9, 82, 10]
print("Array before sorting")
print(arr)
start_time = time.time()
merge_sort(arr)
end_time = time.time()
elapsed_time = end_time - start_time

print("Array after merge sort")
print(arr)

print(f"Time taken by merge_sort: {elapsed_time} seconds")