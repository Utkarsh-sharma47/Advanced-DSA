#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "ABCD";
    // i & j are starting and ending index of substrings
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            //  j - i + 1 :represents the length of the substring
            cout << s.substr(i, j - i + 1) << " ";
        }
        cout << endl << endl;
    }

    return 0;
}
