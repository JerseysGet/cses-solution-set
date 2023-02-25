#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n; cin >> n;
    int M = -1;
    unordered_map<int, int> fMap;
    int arr[n]; 
    for (int& ele : arr) {
        cin >> ele;
        M = max(M, ele);
        fMap[ele]++;
    }

    for (int i = M; i >= 1; i--) {
        int gcdFreq = 0;
        for (int j = 1; i * j <= M; j++) {
            gcdFreq += fMap[i*j];
            if (gcdFreq > 1) {
                cout << i << "\n";
                return 0;
            }
        }
    }


}