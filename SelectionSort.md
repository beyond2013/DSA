Following Algorithm sorts an Array `A` using selection sort algorithm.

```
SelectionSort(A)
  n:= length(A)
    for i:=1 to n
      j:= FindIndexOfSmallest(A,i,n)
      swap A[i] with A[j]
    end for
 end procedure
 
FindIndexOfSmallest(A,i,n)
  smallestAt := i
  for j := i + 1 to n
    if(A[j] < A[SmallestAt])
      smallestAt :=j
    end if
  end for
  return smallestAt
end procedure
```
