#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve() {
    int n; cin >> n;
    int answer = 0;
    while (n > 0) {
        n /= 5;
        answer += n;
    }
    cout << answer;
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