#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int INF = INT_MAX;


int32_t main() {
    int n, q; cin >> n >> q;
    int arr[n]; for (auto& k : arr) cin >> k;
    while (q--) {
        int l, r; cin >> l >> r; l--; r--;
        int ans = INF;
        for (int i = l; i <= r; i++) {
            ans = min(ans, arr[i]);
        }
        cout << ans << "\n";
    }
}