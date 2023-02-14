#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    sort(arr, arr+n);
    int median = (arr[n/2] + arr[(n+1)/2])/2;
    int cost = 0;
    for (int ele : arr) {
        cost += abs(ele - median);
    }

    cout << cost << "\n";
}