#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n; cin >> n;
    cout << n << " ";
    while (n > 1) {
        n = (n % 2 == 0) ? (n/2) : (3*n + 1);
        cout << n << " ";
    }
    cout << "\n";
}