#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(vector<int> &heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() && heap[left] > heap[largest])
        largest = left;

    if (right < heap.size() && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        Heapify(heap, largest);
    }
}

void insert(vector<int> &heap, int key)
{
    heap.push_back(key);
    int i = heap.size() - 1;
    while (i != 0 && heap[i] > heap[(i - 1) / 2])
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteNode(vector<int> &heap, int key)
{
    int i = 0;
    for (i = 0; i < heap.size(); i++)
    {
        if (heap[i] == key)
            break;
    }

    swap(&heap[i], &heap[heap.size() - 1]);
    heap.pop_back();
    Heapify(heap, i);
}

void printHeap(vector<int> &heap)
{
    for (int i = 0; i < heap.size(); i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main()
{
    cout<<"HEAPS"<<endl;

    vector<int> heap;
    insert(heap, 3);
    insert(heap, 5);    
    insert(heap, 9);
    deleteNode(heap, 5);

    printHeap(heap);

    return 0;
}