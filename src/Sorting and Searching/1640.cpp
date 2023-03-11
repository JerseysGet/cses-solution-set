#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> arr;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        arr.push_back({k, i+1});
    }
    sort(arr.begin(), arr.end());
    int L = 0, R = arr.size()-1;
    while (L < R) {
        if (arr[L].first + arr[R].first > x) {
            R--;
        } else if (arr[L].first + arr[R].first < x) {
            L++;
        } else {
            cout << arr[L].second << " " << arr[R].second << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
}