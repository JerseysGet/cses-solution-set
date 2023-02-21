#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(int n, int k) {
    if (n == 1) {
        cout << "1 ";
        return;
    }
    
    if (k <= (n/2)) {
        cout << 2 * k << " ";
        return;
    }
    int t = n - k + 1;

    int product = 2*t - 1;
    while (product != n) {
        if (product > n) {
            product = product >> 1;
            break;
        }

        product = product << 1;
    }
    cout << 2 * (n - product) + 1 << " ";
}

int32_t main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        solve(n, i);
    }
    cout << "\n";
    return 0;
}