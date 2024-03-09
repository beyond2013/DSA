Credit: Following algorithm has been taken from the book **Theory and Problems of Data Structures** by **Seymour Lipschutz**  

Data is an array with N elements, This algorithm sorts the elements in DATA.  

```
(Bubble Sort) Bubble(DATA, N)
1. Repeat Steps 2 and 3 for K=1 to N-1
2. Set PTR := 1
3. Repeat while PTR <= N - K
  a). If DATA[PTR] > DATA[PTR + 1], then: 
        Interchange / Swap DATA[PTR] and DATA[PTR + 1]
      End of If structure
  b). Set PTR := PTR + 1
  End of inner loop.
 End of outer loop (Step 1)

4. Exit.
```  
