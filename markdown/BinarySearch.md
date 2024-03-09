Source: https://en.wikipedia.org/wiki/Binary_search_algorithm

Following Algorithm performs binary search on array `A` with `n` elements, searching for target `T`

```
procedure binary_search(A, n, T):
    L := 0
    R := n − 1
    while L <= R:
        m := floor((L + R) / 2)
        if A[m] < T:
            L := m + 1
        else if A[m] > T:
            R := m - 1
        else:
            return m
    return unsuccessful
 end procedure
 
 ```
 
