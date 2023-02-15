#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n; cin >> n;
    int arr[n+1];
    int indexOf[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        indexOf[arr[i]] = i;
    }

    int answer = 0;
    for (int i = 1; i < n; i++) {
        while (indexOf[i+1] > indexOf[i]) {
            i++;
        }
        answer++;
    }
    cout << ((answer == 1) ? (1) : (answer + 1)) << "\n";
}