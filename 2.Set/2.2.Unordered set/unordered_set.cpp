#include <bits/stdc++.h>

using namespace std;
int main ()
{

    /*basic input output*/
    set <string> s;
    s.insert("bcd");
    s.insert("bcd");
    s.insert("abc");
    s.insert("xyz");
    s.insert("xyz");
    s.insert("xyz");

    for(auto it: s)
    {
        cout<<it<<endl;
    }

    /*find funtion*/
    auto it=s.find("abc");
    s.erase(it);

    cout<<"AFTER ERASEING from us"<<endl;
    for(auto it: s)
    {
        cout<<it<<endl;
    }
    

    return 0;
}

