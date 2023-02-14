#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> desiredSize;
    vector<int> apartmentSize;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        desiredSize.push_back(a);
    }

    for (int i = 0; i < m; i++) {
        cin >> a;
        apartmentSize.push_back(a);
    }

    sort(apartmentSize.begin(), apartmentSize.end());
    sort(desiredSize.begin(), desiredSize.end());

    int p1 = 0, p2 = 0, ans = 0;
    while (p1 != desiredSize.size() && p2 != apartmentSize.size()) {
        if (abs(desiredSize[p1] - apartmentSize[p2]) <= k) {
            ans++;
            p1++;
            p2++;
        } else {
            if (desiredSize[p1] < apartmentSize[p2]) {
                p1++;
            } else if (desiredSize[p1] > apartmentSize[p2]) {
                p2++;
            }
        }
    }

    cout << ans << "\n";
}