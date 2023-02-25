#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 1000000007;
const int twoInverse = 500000004;
int multiply(int x, int y) {
    return ((x % M) * (y % M)) % M; 
}

int s(int L, int R) {
    return multiply(multiply((R - L + 1), twoInverse), (L + R) % M);
}

int factorSum(int n) {
    int ans = multiply(n, n);
    for (int i = 1; i <= n; i++) {
        ans -= n % i;
        ans %= M;
    }

    return ans;
}

int32_t main() {
    int n; cin >> n;
    int L = 1, R;
    int ans = 0;
    while (L <= n) {
        R = n/(n/L);
        ans += multiply(n/L, s(L, R));
        ans %= M;
        L = R + 1;
    }

    cout << ans << "\n";
}
