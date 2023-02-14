#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() {
    int n, x; cin >> n >> x;
    multiset<int> arr;
    unordered_map<int, vector<int>> indexOf;
    int alsoArr[n];
    int k;
    for (int i = 0; i < n; i++) {
        cin >> alsoArr[i];
        arr.insert(alsoArr[i]);
        indexOf[alsoArr[i]].push_back(i+1);
    }

    sort(alsoArr, alsoArr + n);

    for (const auto& ele : arr) {
        auto itr = arr.find(ele);

        arr.erase(itr);
        auto pos = arr.find(x - ele);
        if (pos != arr.end()) {
            if (ele == x - ele) {
                cout << indexOf[ele][0] << " " << indexOf[ele][1] << "\n";
            } else {
                cout << indexOf[ele][0] << " " << indexOf[x - ele][0] << "\n";
            }
            return 0;
        }
        arr.insert(ele);
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}