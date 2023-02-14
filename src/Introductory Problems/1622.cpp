#include <bits/stdc++.h>
using namespace std;
#define int long long

int factorial(int n) {
    if (n == 0) {return 1;}
    return n * factorial(n-1);
}

void permute(int* fMap, int n, string& currentString) {
    if (currentString.length() == n) {
        cout << currentString << "\n";
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (fMap[i] == 0) {
            continue;
        }

        currentString += ('a' + i);
        fMap[i]--;
        permute(fMap, n, currentString);
        fMap[i]++;
        currentString = currentString.substr(0, currentString.size() - 1);
    }

}

void solve() {
    string str; getline(cin, str);
    sort(str.begin(), str.end());
    int num = factorial(str.length());
    int fMap[26] = {0};
    for (char c : str) {
        fMap[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        num /= factorial(fMap[i]);
    }
    cout << num << "\n";
    string stor;
    permute(fMap, str.length(), stor);

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}