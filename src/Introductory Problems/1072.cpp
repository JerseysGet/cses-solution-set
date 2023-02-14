#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int m; cin >> m;
    for (int n = 1; n <= m; n++) {
        cout << ((n*n*n*n - n*n)/2 - 4*(n-2)*(n-1)) << "\n";
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