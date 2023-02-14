#include <bits/stdc++.h>
using namespace std;
#define int long long

void minimize(int* arr, int n, int sum, int& minDiff, int currIndex, int currentSum) {
    if (currIndex == n) {
        minDiff = min(minDiff, abs(sum - 2*currentSum));
        return;
    }

    int temp = minDiff;
    // include currIndex
    minimize(arr, n, sum, minDiff, currIndex+1, currentSum + arr[currIndex]);

    // exclude currIndex
    minimize(arr, n, sum, minDiff, currIndex+1, currentSum);
}

void solve() {
    int n; cin >> n;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int answer = LONG_MAX;
    minimize(arr, n, sum, answer, 0, 0);
    cout << answer;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}