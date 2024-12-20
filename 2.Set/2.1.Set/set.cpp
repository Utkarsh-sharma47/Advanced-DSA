#include <bits/stdc++.h>

using namespace std;
int main ()
{

    /*basic input output*/
    set <string> s;
    s.insert("abc");
    s.insert("bcd");
    s.insert("xyz");

    for(auto it: s)
    {
        cout<<it<<endl;
    }

    /*find funtion*/
    auto it=s.find("abc");
    s.erase(it);
    cout<<"AFTER ERASEING"<<endl;
    for(auto it: s)
    {
        cout<<it<<endl;
    }

    return 0;
}

