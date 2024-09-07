# Associative Array

This article presents a C++ implementation using two separate arrays to store names and phone numbers. This example uses a simple hash function to map names to their corresponding phone numbers in the "phonebook."

## Explanation of the Approach

1. **Hash Function**: The hash function converts a string (person's name) into an index by summing the ASCII values of the characters and using the modulo operator with the size of the hash table (`100` in this case).
2. **Collision Handling**: We use a simple linear probing technique for handling collisions. If the computed index is already occupied, we move to the next index until an empty slot is found.
3. **Two Arrays**: One array (`names`) is used to store names, and the other (`contacts`) is used to store corresponding phone numbers.

## C++ Code Implementation

```cpp
#include <iostream>
#include <string>
#include <vector>

const int MAX_SIZE = 100;

// Simple hash function to calculate index
int hashFunction(const std::string& name) {
    int hashValue = 0;
    for (char ch : name) {
        hashValue += ch; // Sum of ASCII values
    }
    return hashValue % MAX_SIZE; // Modulo with maximum size of the array
}

// Phonebook class to manage insert and search
class PhoneBook {
    std::vector<std::string> names;
    std::vector<std::string> contacts;

public:
    PhoneBook() : names(MAX_SIZE, ""), contacts(MAX_SIZE, "") {}

    // Insert a new contact
    void insert(const std::string& name, const std::string& contact) {
        int index = hashFunction(name);

        // Linear probing to handle collision
        while (!names[index].empty()) {
            if (names[index] == name) {
                std::cout << "Error: Contact with name " << name << " already exists.\n";
                return;
            }
            index = (index + 1) % MAX_SIZE; // Move to the next index
        }

        names[index] = name;
        contacts[index] = contact;
        std::cout << "Contact added: " << name << " - " << contact << "\n";
    }

    // Search for a contact by name
    void search(const std::string& name) {
        int index = hashFunction(name);

        // Linear probing to find the contact
        while (!names[index].empty()) {
            if (names[index] == name) {
                std::cout << "Contact found: " << name << " - " << contacts[index] << "\n";
                return;
            }
            index = (index + 1) % MAX_SIZE; // Move to the next index
        }

        std::cout << "Error: Contact with name " << name << " not found.\n";
    }
};

int main() {
    PhoneBook phonebook;

    // Inserting contacts
    phonebook.insert("Alice", "123-456-7890");
    phonebook.insert("Bob", "987-654-3210");
    phonebook.insert("Charlie", "555-123-4567");

    // Searching for contacts
    phonebook.search("Alice");
    phonebook.search("Eve");

    return 0;
}
```

### Explanation of the Code

- **Hash Function (`hashFunction`)**: Computes the hash value by summing the ASCII values of the characters in the name. The result is taken modulo `MAX_SIZE` to ensure it falls within the range of available indices.
- **Insert Function (`insert`)**:
  - Computes the hash index for the given name.
  - Uses linear probing to find an available slot if a collision occurs.
  - Inserts the name and contact at the computed or probed index.
- **Search Function (`search`)**:
  - Computes the hash index for the given name.
  - Uses linear probing to find the desired contact by name.
  - Returns the contact if found, or an error message if not found.

### Points to Discuss with Students

1. **Hash Function Simplicity**: Demonstrate how the hash function converts a string to an index and why modulo is used.
2. **Collision Handling**: Explain the use of linear probing for handling collisions and discuss other methods (like chaining).
3. **Performance Considerations**: Discuss how the load factor affects performance and why resizing or choosing an appropriate size is essential.
4. **Limitations**: Explain limitations like potential clustering with linear probing, and discuss when to use more sophisticated hash functions.

This example is simple but demonstrates the core concepts of hashing, associative arrays, and collision resolution. Would you like more examples or explanations?