//Q. NUmber of smllest subsequnce that have sum k
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int arr[n] = {2, 8, 3, 1, 1};
    int k = 13; // try 14,15 also

    // insert all arrray emelents in max heap (decending order done)
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int sum = 0, count = 0;
    while (!pq.empty())
    {
        sum = sum + pq.top();
        pq.pop();

        if(sum>=k)
        {
            count++;
        }
    }
    if(count ==0) cout<<-1;
    else cout<<count;

    return 0;
}
