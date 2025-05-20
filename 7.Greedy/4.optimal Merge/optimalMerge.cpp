/*Choose/take any two files, add their computation times, and 
append the sum back to the list of computation times.
{Cost = Sum of computation time}

Repeat this process until only one file is left in the array.
We must perform these operations in such a way that the total
 cost is minimized.*/

#include <iostream>
#include <queue>
using namespace std;

/*
Approach:
1.Push all elements to a min-heap.
2.Take the top 2 elements one by one and add the cost to the answer.
3.Push the merged file back into the min-heap.

When a single element remains, output the total cost.
*/

int main() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;

    // Min-heap to store file sizes
    priority_queue<int, vector<int>, greater<int>> pq;

    // Manual input
    cout << "Enter sizes of " << n << " files:\n";
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        pq.push(size);
    }

    int totalCost = 0;

    // Merge files until one remains
    while (pq.size() > 1) {
        // Take two smallest files
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        int mergeCost = first + second;
        totalCost += mergeCost;

        // Push merged file size back
        pq.push(mergeCost);
    }

    cout << "\nMinimum total cost of merging files = " << totalCost << endl;
    return 0;
}
