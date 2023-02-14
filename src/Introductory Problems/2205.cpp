#include <bits/stdc++.h>
using namespace std;
#define int long long

void grayMap(int k, int n) {
    bitset<64> bset(k);
    for (int i = n; i >= 1; i--) {
        cout << (bset[i] == bset[i-1]) ? 0:1;
    }     
    cout << "\n";
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < 1 << n; i++) {
        grayMap(i, n);
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