#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main() {
    int n; cin >> n;
    int arr[n]; for (int& k : arr) cin >> k;
    sort(arr, arr+n);
    int ans = 1;
    for (int k : arr) {
        if (ans < k) {
            cout << ans << "\n";
            return 0;
        }

        ans += k;
    }    

    cout << ans << "\n";
}