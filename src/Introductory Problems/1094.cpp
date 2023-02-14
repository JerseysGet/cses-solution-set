#include <bits/stdc++.h>
using namespace std;
#define int long long



void findAnswer(const unordered_set<int>& originalSet,vunordered_set<int>& set, vector<int>& ans, int n) {
    if (ans.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }

        exit(0);
    }
    for (const auto& ele : set) {
        if (ans.size() == 0 || abs(ele - ans.back()) != 1) {
            set.erase(ele);
            ans.push_back(ele);
            findAnswer(set, ans, n);
            set.insert(ele);
            ans.erase(ans.end());
        }
    }

}

int32_t main() {
    int n; cin >> n;
    unordered_set<int> set;
    for (int i = 1; i<=n; i++) {
        set.insert(i);
    }
    vector<int> l;
    findAnswer(set, l, n);
}