#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    if (n % 4 == 0) {
        cout << "YES\n";
        cout << n / 2 << "\n";
        for (int i = 1; i <= n/4; i++) {cout << i << " ";}
        for (int i = 1 + 3*(n/4); i <= n; i++) {cout << i << " ";}
        cout << "\n";
        cout << n/2 << "\n";
        for (int i = 1 + (n/4); i <= 3*(n/4); i++) {cout << i << " ";}
        
    } else if (n % 4 == 3) {
        cout << "YES\n";
        cout << 2 * (n/4) + 1 << "\n";
        for (int i = 1; i <= n/4; i++) {cout << i << " ";}
        for (int i = 3 + 3*(n/4); i <= n; i++) {cout << i << " ";}
        cout << "\n";
        cout << n - 2*(n/4) - 1 << "\n";
        for (int i = 1 + (n/4); i <= 2 + 3*(n/4); i++) {cout << i << " ";}
    } else {
        cout << "NO\n";
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