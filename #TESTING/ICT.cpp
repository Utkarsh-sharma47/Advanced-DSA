#include <bits/stdc++.h>
using namespace std;

int ones(int n)
{
    int count = 0;
    while(1)
    {
        if(n==0)
        {
            return count;
        }
        
        else{
            count++;
            n=n&(n-1);
        }
    }
}


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
	    int n;
	    cin>>n;
	    vector <int> v;
	    for(int i =0; i<n; i++)
	    {
	       int x;
	       cin>>x;
	       v.push_back(x);
	    }
	    bool check =1;
	    for(int i=0; i<n; i++)
	    {
            if(ones(v[i]) != ones(i+1))
            {
                check = 0;
                break;
            }
            
	    }
	    if(check)
	    {
	        cout<<"Yes"<<endl;
	    }
	    else{
	        cout<<"No"<<endl;
	    }
	    
	}

}
