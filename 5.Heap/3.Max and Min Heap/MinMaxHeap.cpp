#include<bits/stdc++.h>
using namespace std;


int main()
{
    // //MAX heap
    // priority_queue<int> pq;
    // pq.push(2);
    // pq.push(10);
    // pq.push(13);
    // pq.push(12);
    // pq.push(11);

    // cout<<pq.top()<<endl;

    // MIN heap
    priority_queue<int, greater<int>> pq;
     pq.push(2);
    pq.push(10);
    pq.push(1);
    pq.push(12);
    pq.push(11);

    cout<<pq.top();


    return 0;
}
