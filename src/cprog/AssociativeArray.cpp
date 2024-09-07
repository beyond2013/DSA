#include <iostream>
#include <string>
#include <vector>

const int MAX_SIZE = 100;

// Simple hash function to calculate index
int hashFunction(const std::string &name)
{
    int hashValue = 0;
    for (char ch : name)
    {
        hashValue += ch; // Sum of ASCII values
    }
    return hashValue % MAX_SIZE; // Modulo with maximum size of the array
}

// Phonebook class to manage insert and search
class PhoneBook
{
    std::vector<std::string> names;
    std::vector<std::string> contacts;

public:
    PhoneBook() : names(MAX_SIZE, ""), contacts(MAX_SIZE, "") {}

    // Insert a new contact
    void insert(const std::string &name, const std::string &contact)
    {
        int index = hashFunction(name);

        // Linear probing to handle collision
        while (!names[index].empty())
        {
            if (names[index] == name)
            {
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
    void search(const std::string &name)
    {
        int index = hashFunction(name);

        // Linear probing to find the contact
        while (!names[index].empty())
        {
            if (names[index] == name)
            {
                std::cout << "Contact found: " << name << " - " << contacts[index] << "\n";
                return;
            }
            index = (index + 1) % MAX_SIZE; // Move to the next index
        }

        std::cout << "Error: Contact with name " << name << " not found.\n";
    }
};

int main()
{
    /* PhoneBook phonebook;

     // Inserting contacts
     phonebook.insert("Alice", "123-456-7890");
     phonebook.insert("Bob", "987-654-3210");
     phonebook.insert("Charlie", "555-123-4567");

     // Searching for contacts
     phonebook.search("Alice");
     phonebook.search("Eve");
   */
    // Imran and Mehran hash into the same slot 3
    // Seenan and Kamran hash into the same slot 2
    // Basit and Ihsan hash into the same slot 99
    // Behram and Sajid hash into the same slot 91
    std::string name;
    int choice = 1;
    while (choice)
    {
        std::cout << "\nEnter a name: ";
        std::cin >> name;

        std::cout << "\nHash of " << name << " is " << hashFunction(name) << std::endl;
        std::cout << "Press 1 to continue: ";
        std::cin >> choice;
    }
    return 0;
}