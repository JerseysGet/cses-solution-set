#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n; cin >> n;
    map<int, set<int>> dep;

    int k, v;
    for (int i = 0; i < n; i++) {
        cin >> k >> v;
        dep[v].insert(k);
    }

    int currPos = 1;
    int movies = 0;
    for (auto& mapping : dep) {
        auto nextPos = mapping.second.upper_bound(currPos - 1);
        if (nextPos == mapping.second.end()) {
            continue;
        } else {
            movies++;
            currPos = mapping.first;
        }
    }

    cout << movies << "\n";
}