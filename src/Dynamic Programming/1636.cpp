#include <bits/stdc++.h>
using namespace std;
// #define int long long
// This solution uses a lot of memory, causing seg fault with long long
const int M = 1000000007;

int32_t main() {
    int n, x; cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<vector<int>> numberOfWays(n, vector<int>(x+1, 0));
    // int numberOfWays[n][x+1];
    for (int i = 0; i < n; i++) {
        numberOfWays[i][0] = 1;
    }

    // cannot flip the order of these two loops !
    for (int c = 0; c < n; c++) {
        for (int i = 1; i <= x; i++) {
            int term1, term2;
            if (c == 0) {
                term1 = 0;
            } else {
                term1 = numberOfWays[c-1][i];
            }

            if (i - coins[c] < 0) {
                term2 = 0;
            } else {
                term2 = numberOfWays[c][i-coins[c]];
            }

            numberOfWays[c][i] = (term1 + term2) % M;
        }
    }

    cout << numberOfWays[n-1][x] << "\n";
}