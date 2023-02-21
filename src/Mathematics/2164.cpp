#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve() {
    int n, k; cin >> n >> k;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    
    if (k <= (n/2)) {
        cout << 2 * k << "\n";
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
    cout << 2 * (n - product) + 1 << "\n";
}

int32_t main() {
    int q; cin >> q;
    while(q--) {solve();}
    return 0;
}