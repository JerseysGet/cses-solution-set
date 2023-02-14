#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() {
    int n, m; cin >> n >> m;
    multiset<int> prices;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        prices.insert(k);
    }

    vector<int> customers;
    for (int i = 0; i < m; i++) {
        cin >> k;
        customers.push_back(k);
    }
    
    for (const auto& cust : customers) {
        auto i = prices.upper_bound(cust);
        if (i == prices.begin()) { // all are greater
            cout << "-1\n";
        } else {
            i--; // i points to just leq element
            cout << *i << "\n";
            prices.erase(i);
        }
    }  
    
    return 0;
}