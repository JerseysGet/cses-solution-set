#include <bits/stdc++.h>
#define int long long

using namespace std;
void hanoi(int n, int src, int helper, int dest) {
    if (n == 1) {
        cout << src << " " << dest << "\n";
        return;
    }

    hanoi(n-1, src, dest, helper);
    cout << src << " " << dest << "\n";
    hanoi(n-1, helper, src, dest);
}

int32_t main() {
    int n; cin >> n;
    cout << (1 << n) - 1 << "\n";
    hanoi(n, 1, 2, 3);
    return 0;
}