#include <bits/stdc++.h>
using namespace std;
#define int long long

bool comp(const pair<int ,int>& a, const pair<int, int>& b) {
    return (a.second < b.second);
}

int32_t main() {
    int n; cin >> n;
    vector<pair<int, int>> customers;

    for (int i = 0; i < n; i++) {
        pair<int, int> c;
        cin >> c.first;
        cin >> c.second;
        customers.push_back(c);
    }

    vector<pair<int, int>> arrivalTime(customers);
    vector<pair<int, int>> leavingTime(customers);
    sort(arrivalTime.begin(), arrivalTime.end());
    sort(leavingTime.begin(), leavingTime.end(), comp);

    int i = 0, j = 0;
    int maxCount = -1;
    int currCount = 0;
    while (i < arrivalTime.size() && j < leavingTime.size()) {
        if (arrivalTime[i].first < leavingTime[j].second) {
            currCount++;
            i++;
        } else if (arrivalTime[i].first = leavingTime[j].second) {
            currCount--;
            j++;
        } else if (arrivalTime[i].first > leavingTime[j].second) {
            i++;
            j++;
        }

        maxCount = max(maxCount, currCount);
    }

    cout << maxCount << "\n";
}