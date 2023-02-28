#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n; cin >> n;
    multiset<int> tops;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        auto justGreater = tops.upper_bound(k);
        if (justGreater == tops.end()) {
            tops.insert(k);
        } else {
            tops.erase(justGreater);
            tops.insert(k);
        }
    }

    cout << tops.size() << "\n";
}