#include <bits/stdc++.h>
#include <map>
using namespace std;
int main ()
{
    
    /*basic input output*/
    map <int , string> m;
    m[3]="abc";
    m[1]="bcd";
    m[2]="zfd";

    for(auto it: m)
    {
        cout<<it.first<<it.second<<endl;
    }

    /*find funtion*/
    auto x=m.find(2);
    cout<<(*x).first;

    return 0;
}

