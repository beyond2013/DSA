Source: https://en.wikipedia.org/wiki/Insertion_sort  
Following algorithm performs Insertion sort on array `A`

```
procedure InsertionSort(A)
  k := 1
  while k < length(A)
      j := k
      while j > 0 and A[j-1] > A[j]
          swap A[j] and A[j-1]
          j := j - 1
      end while
      k := k + 1
  end while
end procedure
```
