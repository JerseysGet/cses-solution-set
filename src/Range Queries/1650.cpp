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
    int arr[n], prefix[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i == 0) {
            prefix[i] = arr[0];
        } else {
            prefix[i] = prefix[i-1] ^ arr[i];
        }
    }

    int l, r;
    while(q--) {
        cin >> l >> r; l--; r--;
        cout << (get(prefix, r) ^ get(prefix, l-1)) << "\n";
    }
}