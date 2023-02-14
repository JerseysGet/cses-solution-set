#include <bits/stdc++.h>
using namespace std;
#define int long long

int S(int n) {
    int tentoN = pow(10, n);
    return (n * tentoN) - (tentoN - 10)/9 - 1;
}

void solve() {
    int n; cin >> n;
    int k = 0;
    do {
        k++;
    } while (S(k) < n);

    int Sk = S(k);
    int Sk1 = S(k-1);
    int tentoK = pow(10, k);
    int number = (tentoK - 1) - ((Sk - n)/k);
    for (int i = 0; i < (k - ((n - Sk1) % k)) % k; i++) {
        number /= 10;
    }
    cout << number % 10 << "\n";

    // int sum = 0;
    // int i = 0;
    // for (i = 1; sum < n; i++) {
    //     cout << i;
    //     sum += 1 + (int)(log10(i));
    // }
    // // ??
    // cout << "\n" << sum;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}