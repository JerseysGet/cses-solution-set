#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 1000000007;

int32_t main() {
    int n; cin >> n;
    int lastSix[6];
    for (int i = 0; i < 5; i++) {
        lastSix[i] = 0;
    }
    lastSix[5] = 1;
    int ans;
    for (int i = 0; i < n; i++) {
        int sum = (lastSix[0] + lastSix[1] + lastSix[2] + lastSix[3] + lastSix[4] + lastSix[5]) % M;
        for (int i = 0; i < 5; i++) {
            lastSix[i] = lastSix[i+1];
        }
        lastSix[5] = sum;
    }
    cout << lastSix[5] << "\n";
}