#include <bits/stdc++.h>
using namespace std;
#define int long long

int get(int (&prefix)[], int i) {
    if (i < 0) {
        return 0;
    }

    return prefix[i];
}

int32_t main() {
    int n, q; cin >> n >> q;
    int arr[n];
    int prefix[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i == 0) {
            prefix[i] = arr[i];
        } else {
            prefix[i] = prefix[i-1] + arr[i];
        }
    }

    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << get(prefix, r-1) - get(prefix, l-2) << "\n";
    }
}