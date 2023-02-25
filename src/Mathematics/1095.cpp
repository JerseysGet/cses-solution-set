#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

const int M = 1000000007;

int multiply(int x, int y) {
    return ((x % M) * (y % M)) % M;
}

int exponent(int a, int b) {
    if (b == 0) {
        return 1;
    } else if (a == 0) {
        return 0;
    }

    vector<int> pow2; // pow2[i] = a^2^i
    pow2.push_back(a);
    for (int k = 0; (1 << k) <= b; k++) {
        pow2.push_back(multiply(pow2[k], pow2[k]));
    }

    int ans = 1, exp = 0;
    while (b > 0) {
        if (b & 1 == 1) {
            ans = multiply(ans, pow2[exp]);
        }
        b >>= 1;
        exp++;
    }

    return ans;
}

int32_t main() {
    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        cout << exponent(a, b) << "\n";
    }
}