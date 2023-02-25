#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

const int M = 1000000007;

int multiply(int x, int y, int m) {
    return ((x % m) * (y % m)) % m;
}

int exponent(int a, int b, int m) {
    if (b == 0) {
        return 1;
    } else if (a == 0) {
        return 0;
    }

    vector<int> pow2; // pow2[i] = a^2^i
    pow2.push_back(a);
    for (int k = 0; (1 << k) <= b; k++) {
        pow2.push_back(multiply(pow2[k], pow2[k], m));
    }

    int ans = 1, exp = 0;
    while (b > 0) {
        if (b & 1 == 1) {
            ans = multiply(ans, pow2[exp], m);
        }
        b >>= 1;
        exp++;
    }

    return ans;
}

int32_t main() {
    int n; cin >> n;
    while (n--) {
        int a, b, c; cin >> a >> b >> c;
        int bToC = exponent(b, c, M - 1);
        cout << exponent(a, bToC, M) << "\n";
    }
}