#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    unordered_set<int> set;
    int n; cin >> n;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        set.insert(k);
    }

    cout << set.size() << "\n";
    return 0;
}