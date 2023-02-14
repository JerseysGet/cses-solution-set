#include <bits/stdc++.h>
using namespace std;
#define int long long

int m = 1000000007;

int multiply(int a, int b) {
    return (a * b) % m;
}

int exp2(int n) {
    if (n == 0) {
        return 1;
    }
    return multiply(2LL, exp2(n-1));
}

void solve() {
    int n; cin >> n;
    cout << exp2(n);
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