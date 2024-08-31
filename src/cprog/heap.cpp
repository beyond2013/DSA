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
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && arr[l] > arr[largest])
            largest = l;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
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
};

int main()
{
    MaxHeap h(10);
    h.insert(10);
    h.insert(5);
    h.insert(30);
    h.insert(20);
    h.insert(15);

    cout << h.extractMax() << endl;
    cout << h.extractMax() << endl;

    return 0;
}