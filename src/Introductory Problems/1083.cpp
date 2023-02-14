#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n; cin >> n;
    int sum = 0;
    int t;
    for (int i = 0; i < n-1; i++) {
        cin >> t;
        sum += t;
    }

    cout << (n*n + n)/2 - sum << "\n";
}