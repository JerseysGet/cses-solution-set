#include <bits/stdc++.h>
using namespace std;
#define int long long
 // 2 3 1 4 1 ..
int32_t main() {
    int n; cin >> n;
    int arr[n]; for (int& k : arr) cin >> k;
    unordered_map<int, int> indexOf;
    int L = 0, R = 0;
    int maxSize = 1;
    while(R < n) {
        if (indexOf.count(arr[R]) == 0 || !(indexOf[arr[R]] < R && indexOf[arr[R]] >= L)) {
            indexOf[arr[R]] = R;
        } else {
            L = indexOf[arr[R]] + 1;
            indexOf[arr[R]] = R;
        }
        R++;
        maxSize = max(maxSize, R - L);
    }

    cout << maxSize << "\n";
}