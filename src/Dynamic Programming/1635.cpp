#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 1000000007;

int get(int (&memo)[], int x) {
    if (x < 0) {
        return 0;
    }

    return memo[x];
}

int32_t main() {
    int n, x; cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int memo[x+1];
    memo[0] = 1;

    for (int i = 1; i <= x; i++) {
        memo[i] = 0;
        for (const auto& coin : coins) {
            memo[i] += get(memo, i - coin);
            memo[i] %= M;
        }
    }

    cout << memo[x] << "\n";
}