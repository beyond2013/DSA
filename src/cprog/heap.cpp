#include <iostream>
using namespace std;
// this implementation does not store any key at the zero index of the array
class MaxHeap
{
public:
    int *arr;
    int size;
    int capacity;

    MaxHeap(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        arr = new int[capacity + 1];
    }

    int parent(int i)
    {
        return i / 2;
    }

    int left(int i)
    {
        return 2 * i;
    }

    int right(int i)
    {
        return 2 * i + 1;
    }

    void insert(int k)
    {
        if (size == capacity)
        {
            cout << "Heap is full\n";
            return;
        }

        size++;
        arr[size - 1] = k;

        int i = size - 1;
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void maxHeapify(int i)
    {
        cout << "inside maxHeapify(int i), value of i is " << i << endl;
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && arr[l] > arr[largest])
        {
            cout << "l: " << l << "size: " << size << "arr[" << l << "]: " << arr[l] << "arr[" << largest << "]" << arr[largest] << endl;
            cout << "resetting largest to l" << endl;
            largest = l;
            cout << "new value of largest: " << largest << endl;
        }

        if (r < size && arr[r] > arr[largest])
        {
            cout << "r: " << r << "size: " << size << "arr[" << r << "]: " << arr[r] << "arr[" << largest << "]" << arr[largest] << endl;
            cout << "resetting largest to r" << endl;
            largest = r;
            cout << "new value of largest: " << largest << endl;
        }

        if (largest != i)
        {
            cout << "largest: " << largest << "and i: " << i << "are not equal" << endl;
            cout << "swapping arr[" << i << "]: " << arr[i] << " with arr[" << largest << "]: " << arr[largest] << endl;
            swap(arr[i], arr[largest]);
            cout << "Next recursive call to maxHeapify(" << largest << ")" << endl;
            maxHeapify(largest);
        }
    }

    int extractMax()
    {
        if (size == 0)
        {
            cout << "Heap is empty\n";
            return -1;
        }

        int max = arr[0];
        arr[0] = arr[size - 1];
        size--;
        maxHeapify(0);
        return max;
    }
    void deleteKey(int k)
    {
        // Find the index of the element to be deleted
        int i = 0;
        while (i < size && arr[i] != k)
        {
            i++;
        }

        if (i == size)
        {
            cout << "Element not found\n";
            return;
        }

        // Swap the element to be deleted with the last element
        swap(arr[i], arr[size - 1]);
        size--;

        // Heapify the affected subtree
        maxHeapify(i);
    }
};

int main()
{
    int choice = 0, cap = 10, key, loop = 1;
    MaxHeap h(cap);
    while (loop == 1)
    {
        // cout << "\n1. Create Heap" << endl;
        cout << "1. insert into Heap" << endl;
        cout << "2. extractMax from Heap" << endl;
        cout << "3. delete a key from Heap" << endl;
        cout << "Enter your choice 1-3: ";
        cin >> choice;
        switch (choice)
        {
            /* case 1:
                 cout << "enter the capacity for heap: " << endl;
                 cin >> cap;
                 break;
                 */
        case 1:
            cout << "enter the key you want to insert: ";
            cin >> key;
            h.insert(key);
            break;
        case 2:
            cout << "h.extractMax() returned: " << h.extractMax() << endl;
            break;
        case 3:
            cout << "Which key you want to delete? ";
            cin >> key;
            h.deleteKey(key);
            break;
        default:
            cout << " Invalid input ";
        }
        cout << "Enter 1 to continue: ";
        cin >> loop;
    }
    return 0;
}