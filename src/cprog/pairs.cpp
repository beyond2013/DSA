#include <iostream>
#include <utility> // for std::pair
using namespace std;

int main()
{
    // Creating a pair of integers
    pair<int, int> p1 = make_pair(10, 20);

    // Accessing the elements of the pair
    cout << "First element of the pair: " << p1.first << endl;
    cout << "Second element of the pair: " << p1.second << endl;

    // Modifying the elements of the pair
    p1.first = 30;
    p1.second = 40;

    cout << "Modified first element of the pair: " << p1.first << endl;
    cout << "Modified second element of the pair: " << p1.second << endl;

    // Another way to create a pair
    pair<int, int> p2(30, 38);

    // Comparing pairs
    if (p1 < p2)
    {
        cout << "Pair p1 is less than pair p2" << endl;
    }
    else if (p1 > p2)
    {
        cout << "Pair p1 is greater than pair p2" << endl;
    }
    else
    {
        cout << "Pair p1 is equal to pair p2" << endl;
    }

    return 0;
}
