#include <bits/stdc++.h>
using namespace std;
// #define int long long

vector<vector<int>> adjLists;
unordered_map<int, bool> visited;
unordered_map<int, int> previous;
int32_t main() {
    int n, m; cin >> n >> m;
    int x, y;
    adjLists = vector<vector<int>> (n+1, vector<int>());
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        adjLists[x].push_back(y);
        adjLists[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    bool flag = false;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            for (auto adjV : adjLists[q.front()]) {
                if (!visited[adjV]) {
                    previous[adjV] = q.front();
                    visited[adjV] = true;
                    q.push(adjV);
                    if (adjV == n) {
                        flag = true;
                        goto outerEnd;
                    }
                }
            }
        q.pop();
        }
        outerEnd:
        if (flag) {
            break;
        }
    }
    if (visited[n]){
        vector<int> path;
        path.push_back(n);
        int curr = n;
        while (curr != 1) {
            curr = previous[curr];
            path.push_back(curr);
        }
        cout << path.size() << "\n";
        for (auto it = path.rbegin(); it != path.rend(); it++) {
            cout << *it << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }
    cout << "\n";
}