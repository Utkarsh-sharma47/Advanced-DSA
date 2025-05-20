#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> m; // key = end time, value = start time
    int n ;

    m[9] = 7; // activity from 10 to 20
    m[10] = 0; // activity from 20 to 30
    m[14] = 12; // activity from 15 to 12 — This is wrong logically (start > end)
    m[11] = 13; 
    m[16] = 15; 

    int take = 0;
    int endtime;

    for (auto it : m)
    {
        if (take == 0)
        {
            endtime = it.first; // end time of first activity in sorted order
            take++;
        }
        else if (it.second >= endtime)
        {
            endtime = it.first;
            take++;
        }
    }
    cout << take;

    return 0;
}
