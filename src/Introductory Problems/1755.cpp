#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve() {
    string s; getline(cin, s);
    int fMap[26] = {0};
    for (const auto& c : s) {
        fMap[c - 'A']++;
    }

    int evenEntries = 0;
    char oddChar;
    for (int i = 0; i < 26; i++) {
        if (fMap[i] % 2 == 0) {evenEntries++;}
        else {oddChar = i + 'A';}
    }

    if (s.length() % 2 == 0 && evenEntries == 26) {
        for (int i = 0; i < 26; i++) {
            for (int k = 0; k < fMap[i]/2; k++) {
                cout << (char) (i + 'A');
            }
        }

        for (int i = 25; i >= 0; i--) {
            for (int k = 0; k < fMap[i]/2; k++) {
                cout << (char) (i + 'A');
            }
        }
    } else if (s.length() % 2 == 1 && evenEntries == 25) {
        for (int i = 0; i < 26; i++) {
            for (int k = 0; k < fMap[i]/2; k++) {
                cout << (char) (i + 'A');
            }
        }
        cout << oddChar;
        for (int i = 25; i >= 0; i--) {
            for (int k = 0; k < fMap[i]/2; k++) {
                cout << (char) (i + 'A');
            }
        }
    } else {
        cout << "NO SOLUTION";
    }
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