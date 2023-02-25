#include <bits/stdc++.h>
using namespace std;
#define int long long

int findLargestDigit(int n) {
    int ans = 0;
    while (n > 0) {
        ans = max(ans, n % 10);
        n /= 10;
    }

    return ans;
}

int32_t main() {
    int n; cin >> n;
    int ct = 0;
    while (n > 0) {
        n -= findLargestDigit(n);
        ct++;
    }

    cout << ct << "\n";
}