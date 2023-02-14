#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve() {
    int l, r; cin >> l >> r;
    int delta = abs (l - r);
    if (l > r && ((l - 2*delta) % 3 == 0) && ((l - 2*delta) >= 0) && ((r - delta) % 3 == 0) && ((r - delta) >= 0)) {
        cout << "YES\n";
    } else if (l == r && (l % 3 == 0) && (r % 3 == 0)) {
        cout << "YES\n";
    } else if (r > l && ((r - 2*delta) % 3 == 0) && ((r - 2*delta) >= 0) && ((l - delta) % 3 == 0) && ((l - delta) >= 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}