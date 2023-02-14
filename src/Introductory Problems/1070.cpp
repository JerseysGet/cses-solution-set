#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }

    if (n < 4) {
        cout << "NO SOLUTION";
        return;
    }
    for (int i = 2 * (n/2); i >= 6; i-=2) {
        cout << i << " ";
    }

    cout << "2 4 1 3 ";
    for (int i = 5; i <= n + n%2 - 1; i+=2) {
        cout << i << " ";
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