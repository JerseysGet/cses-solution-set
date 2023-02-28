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
    int i = 1;
    vector<unordered_set<int>> chunks;
    while (i <= n) {
        unordered_set<int> chunk;
        chunk.insert(i);
        while (indexOf[i+1] > indexOf[i] && i <= n-1) {
            i++;
            chunk.insert(i);
        }
        chunks.push_back(chunk);
        answer++;
        if (i == n) {
            break;
        }
        i++;
    }
    cout << answer << "\n";
}