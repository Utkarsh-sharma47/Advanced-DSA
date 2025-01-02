#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    //             key   value
    map < int, int > m;
    int n = 0;
    // default value in map is zero

    for (int i = 1; i <= (n1 + n2 + n3); i++)
    {
        int x; //key
        cin >> x;
        //[key] ie x=key
        m[x]++;
    }
    vector <int> v;
    for(auto i: m)
    {
        if(i.second>=2)//value (frequency of number)
        {
            v.pushback(i.first);//key (number)
        }
    }

    cout<<v.size()<<endl;
    for(int k=v.begin(); k<=v.end(); k++)
    {
        cout<<v[k]<<endl;
    }

}
