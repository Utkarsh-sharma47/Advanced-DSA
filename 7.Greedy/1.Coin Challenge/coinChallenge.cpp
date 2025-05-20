#include <bits/stdc++.h>
using namespace std;

int coinMake(vector<int> v, int x)
{
    sort(v.begin(), v.end(), greater<int>());
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        while (v[i] <= x)
        {
            x = x - v[i];
            cnt++;
        }
        if(x==0)
        {
            return cnt;
        }
    }
    return false;
}

int main()
{
    vector<int> v = {1, 2, 5, 10, 20};
    int x = 54;

    int c = coinMake(v, x);
    cout << c;

    return 0;
}
