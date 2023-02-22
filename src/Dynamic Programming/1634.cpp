#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = LONG_LONG_MAX - 100;
// unordered_map<int, int> memo;


int32_t main() {
    int n, x; cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int memo[x + 1];
    memo[0] = 0;
    for (int i = 1; i <= x; i++) {
        memo[i] = INF;
        for (const auto& coin : coins) {
            if (i - coin >= 0) {
                memo[i] = min(memo[i], 1 + memo[i - coin]);
            }
        }
    }
    int ans = memo[x];
    cout << ((ans == INF) ? (-1) : (ans)) << "\n";
}