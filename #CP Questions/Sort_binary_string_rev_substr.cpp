/*
Q.sort string by reversing the sub strings, how many reversal req?
00011000111011110000
zeros or ones coming together dont matter since they will be reversed together so you
can count them as single equivalent zero or one
resultant string=0101010

*number of substring reversal required is equal to "10" pairs present in string
*/
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    int a = 2, b = 3;

    cout << "Before swapping a = " << a << " , b = " << b
         << endl;

    // temporary variable
    int temp;

    // appying swapping algorithm
    temp = a;
    a = b;
    b = temp;
    cout << "After swapping a = " << a << " , b = " << b
         << endl;

    return 0;
}