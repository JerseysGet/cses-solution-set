#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    string line;
    getline(cin, line);
    int n = line.length();
    int longestLength = 1;
    int currentLength = 1;
    for (int i = 0; i < n-1; i++) {
        if (line[i] == line[i+1]) {
            currentLength++;
        } else {
            currentLength = 1;
        }

        longestLength = max(longestLength, currentLength);
    }
    cout << longestLength << "\n";

}