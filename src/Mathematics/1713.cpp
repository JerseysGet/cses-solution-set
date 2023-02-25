#include <bits/stdc++.h>
using namespace std;
// #define int unsigned long long



vector<int> factorSieve(int n) {
    vector<int> factors(n+1, 0);
    for (int k = 1; k <= n; k++) {
        for (int l = 1; l * k <= n; l++) {
            factors[l*k]++;
        }
    }
    return factors;
}

int32_t main() {
    vector<int> factors = factorSieve(1000000);
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        cout << factors[x] << "\n";
    }
}