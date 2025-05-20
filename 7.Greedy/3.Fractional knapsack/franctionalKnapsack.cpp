/*
we are given "n" items with {weight(kg), value(Rs)} in array of pairs.
we are theif with sack(capacity 'W'(kg)) ,we need to steal items
 so that we have MAX value.
*/

#include <bits/stdc++.h>
using namespace std;

/*
STEP 1: find (value/Wt) for each element and sort the
        array acc to tht value
STEP 2: take elements until u have capacity
 --when u cant take further whole element
STEP 3: take it by value/Wt and count
*/

int main()
{
    // stolen value;
    double val = 0;
    // capacity of our sack (W)
    int W;
    cout << "Enter capacity of sack (W) = ";
    cin >> W;

    //   Rs/kg(key), <value, weight> (value of map)
    map<double, pair<int, int>, greater<>> m;
     
    int n;
    cout << "Enter number of items (n) = ";
    cin >> n;

    // //Mannual INPUT
    // m[3]={21,7};
    // m[6]={24,4};
    // m[2]={12,6};
    // m[8]={40,5};
    // m[5]={30,6};

    // INPUT the 2 things for each element
    for (int i = 0; i < n; i++)
    {
        int v, w;
        cout << "Enter value of item " << i + 1 << " = ";
        cin >> v;
        cout << "Enter weight of item " << i + 1 << " = ";
        cin >> w;

        double vw = (double)v / w;

        m[vw] = {v, w};
    }

    for (auto i : m)
    {
        // weight of item less than capacity
        if (i.second.second <= W)
        {
            val = val + i.second.first; // add the full item value to stolen val
            W = W - (i.second.second);  // reduce capacity of our bag
        }
        else
        {
            // we will take remaining wt = W (whatever left)
            // takenValue will be: (value/Wt)*W
            val += i.first * W;
            break;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nMaximum value we can steal = Rs " << val << endl;

    return 0;
}
