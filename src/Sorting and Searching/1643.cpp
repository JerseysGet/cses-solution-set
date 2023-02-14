#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int currSum = 0;
    int maxSum = LONG_LONG_MIN;

    for (int ele : arr) {
        currSum += ele;
        maxSum = max(maxSum, currSum);

        if (currSum < 0) {
            currSum = 0;
        }
    }

    cout << maxSum << "\n";
}