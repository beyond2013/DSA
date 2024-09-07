# Hashing

## Introduction

- Hashing is a technique used to efficiently :
   - store
   - retrieve, and
   - manage data.
- It is a fundamental part of many:
   - algorithms and
   -  data structures.
- The basic idea behind hashing is to transform a given input (or 'key') into a unique or nearly unique output ('hash code' or 'hash value') 
- The hash code can be used as an index to quickly locate the data associated with the key.


## 1. Basics of Hashing

Hashing is a technique used to map data (keys) to an index in a fixed-size table called a **hash table**. 

- **Hash Table**: A data structure that implements an [associative array](./associativeArray.md), a structure that can map keys to values.
- **Hash Function**: A function that takes an input (or 'key') and returns an index in the hash table where the value is stored.

## Example of a Hash Function

Consider a simple hash function that takes a string and returns the sum of the ASCII values of its characters modulo the size of the hash table.

```cpp
int hashFunction(string key, int tableSize) {
    int hashValue = 0;
    for (char c : key) {
        hashValue += c; // Add ASCII value of each character
    }
    return hashValue % tableSize; // Modulo operation for table size
}
```

This function takes a string key, computes the sum of the ASCII values of its characters, and returns the remainder when divided by the table size. This remainder is the index where the key-value pair should be stored in the hash table.

## Properties of a Good Hash Function

1. **Deterministic**: The same key should always hash to the same value.
2. **Efficiently Computable**: It should not consume too much time or resources to compute.
3. **Uniform Distribution**: It should distribute keys uniformly across the hash table to minimize collisions.
4. **Minimization of Collisions**: Different keys should not hash to the same index often.

---

## 2. Working of a Hash Function

A hash function works by converting an input (or 'key') into an index (hash value). This index corresponds to a location in the hash table where the associated value is stored.

### Steps in Hashing

1. **Key Selection**: Choose the data (key) that needs to be stored.
2. **Hash Calculation**: Apply the hash function to compute the index.
3. **Data Storage**: Store the key-value pair at the computed index in the hash table.

### Indexing in the Context of Hashing

Indexing in hashing involves calculating a direct access path for the data using a hash function. The hash function computes the index where the data should reside, effectively reducing the search time to `O(1)` on average. The efficiency of indexing through hashing comes from the uniform distribution of hash values and the minimization of collisions.

### Example

Let's assume we have a hash table of size 10 and the following keys: "apple", "orange", "banana".

1. Compute hash values using a hash function:
   - `hashFunction("apple") % 10 = 2`
   - `hashFunction("orange") % 10 = 7`
   - `hashFunction("banana") % 10 = 5`

2. Store values at respective indices:
   - `apple` at index `2`
   - `orange` at index `7`
   - `banana` at index `5`

---

## 3. Collision and Collision Resolution Techniques

A **collision** occurs when two different keys hash to the same index in the hash table. There are several methods to handle collisions:

### 3.1 Open Addressing

Open Addressing resolves collisions by probing or searching the hash table for the next available slot.

- **Linear Probing**: Start at the hashed index and search linearly for the next empty slot.
  - Formula: `index = (hash(key) + i) % tableSize`, where `i` is the probing step.
  - Example: If "apple" and "grape" both hash to index 2, store "apple" at 2 and search for the next free slot for "grape".
  
- **Quadratic Probing**: Probing interval increases quadratically.
  - Formula: `index = (hash(key) + i^2) % tableSize`.
  - This helps in avoiding clustering but may lead to secondary clustering (keys hashed to the same value will follow the same probing sequence).

- **Double Hashing**: Uses two hash functions to determine the probe sequence.
  - Formula: `index = (hash1(key) + i * hash2(key)) % tableSize`.
  - Reduces clustering and improves distribution.

### 3.2 Chaining

Chaining handles collisions using linked lists. Each slot in the hash table contains a pointer to a linked list of keys that hash to the same index.

- **Separate Chaining**: Each index in the hash table points to a linked list containing all keys that hash to the same index.
  - Example: If "apple" and "grape" both hash to index 2, store them in a linked list at index 2.

- **Advantages of Chaining**:
  - Easy to implement.
  - Dynamic table size (the linked list can grow).
  - Efficient when the number of collisions is small.

- **Disadvantages of Chaining**:
  - Increased memory usage due to the storage of pointers.
  - Potential performance degradation if the linked lists become too long.

---

### 4. Choosing a Hash Function and Collision Resolution Strategy

Choosing a hash function and collision resolution strategy depends on:

- **Expected number of keys**: Larger tables with more entries may benefit from open addressing.
- **Distribution of keys**: Keys with similar prefixes or patterns may cause clustering.
- **Memory limitations**: Chaining requires additional pointers, while open addressing uses less space but may require table resizing.
- **Performance requirements**: Depending on whether the emphasis is on insertion speed, search speed, or deletion efficiency.

### 5. Rule of Thumb for Hash Table Size
 There are several rules of thumb and best practices for determining the size of a hash table, which help balance memory usage and performance. The size of a hash table is crucial for minimizing collisions and ensuring efficient access, insertion, and deletion operations.

1. **Choose a Size Relative to the Expected Number of Entries**
   - A common rule of thumb is to set the size of the hash table to be **larger than the number of expected entries**, typically around **1.5 to 2 times** the expected number of elements (the "load factor" will be between 0.5 and 0.75).
   - For example, if you expect to store 1,000 elements, you might start with a hash table size of 1,500 or 2,000.

2. **Keep the Load Factor Below a Certain Threshold**
   - The **load factor** is defined as the ratio of the number of elements (`n`) to the size of the hash table (`m`), expressed as `n/m`.
   - A typical threshold for the load factor is **0.7** to **0.75**. Keeping the load factor below this threshold helps reduce the number of collisions, thus maintaining efficient operations.
   - If the load factor exceeds this threshold, consider resizing the hash table.

3. **Use a Prime Number for Hash Table Size**
   - Using a **prime number** for the size of the hash table is often recommended, especially when using open addressing for collision resolution (like linear probing or double hashing).
   - A prime number size helps ensure that the hash function distributes keys more evenly, reducing clustering and minimizing the chance of collision patterns caused by regular key distributions.

4. **Resize Dynamically When Needed**
   - Many hash table implementations (e.g., those in Python or Java) automatically resize when the load factor exceeds a certain threshold.
   - The table is typically resized by doubling its size, which keeps the load factor under control and reduces collisions.

### Factors to Consider When Deciding Hash Table Size

1. **Expected Number of Elements**
   - Estimate the maximum number of elements that will be stored in the hash table. This estimate will determine the initial size and the resizing strategy.

2. **Collision Handling Strategy**
   - The hash table's size also depends on the collision resolution technique:
     - **Chaining**: Since collisions are handled by storing elements in a list or another data structure, a higher load factor may be more acceptable (up to around 1.0 or even higher), but performance will degrade if too many elements end up in the same bucket.
     - **Open Addressing**: Since all elements are stored directly in the table, a lower load factor (like 0.5 to 0.75) is recommended to keep probe sequences short and ensure efficient operations.

3. **Memory Constraints**
   - If memory is a concern, you might opt for a smaller table size with a higher load factor. However, this may lead to more collisions and slower performance.

4. **Hash Function Quality**
   - The effectiveness of a hash function in distributing keys uniformly impacts the ideal size of the hash table. A poor hash function that clusters keys together will require a larger table to reduce collisions.

5. **Growth Patterns of the Data**
   - Consider how the volume of data may change over time. If data growth is unpredictable or expected to increase significantly, choose a more conservative size or implement dynamic resizing.

### Example Calculation

Suppose you expect to store up to **10,000 elements** in your hash table.

1. **Choose a Load Factor**: Let's aim for a load factor of **0.7**.
2. **Calculate Initial Size**: 
   - `m = n / Load Factor = 10,000 / 0.7 ≈ 14,285`.
3. **Round Up to a Prime Number**: To reduce clustering, round up to the next prime number, such as **14,311**.

#### Conclusion

To decide on the hash table size:

- Start with a size that is 1.5 to 2 times the expected number of entries.
- Keep the load factor below 0.7–0.75 to minimize collisions.
- Use a prime number size if possible, especially for open addressing schemes.
- Consider dynamic resizing for changing data volumes.

### Conclusion

Hashing is an essential technique for optimizing search and retrieval operations in data structures. Understanding the choice of hash functions, collision resolution techniques like open addressing and chaining, and the impact of indexing on performance is crucial for effectively implementing hash-based data structures.

### Questions for Review

1. What are the properties of a good hash function?
2. How does open addressing differ from chaining in collision resolution?
3. Explain the concept of quadratic probing and how it helps in collision resolution.
4. Why is the choice of hash function crucial in the performance of a hash table?
