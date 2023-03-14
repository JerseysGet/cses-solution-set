#include <bits/stdc++.h>
using namespace std;
// #define int long long


vector<vector<int>> adjLists;
unordered_set<int> unvisited;
void BFS(int v) {
    queue<int> q;
    q.push(v);
    unvisited.erase(v);
    while (!q.empty()) {
        for (auto adjV : adjLists[q.front()]) {
            if (unvisited.count(adjV) == 1) {
                unvisited.erase(adjV);
                q.push(adjV);
            }
        }
        q.pop();
    }
}

int32_t main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        unvisited.insert(i-1);
        adjLists.push_back(vector<int>());
    }
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adjLists[x-1].push_back(y-1);
        adjLists[y-1].push_back(x-1);
    }

    vector<int> cities;
    while (!unvisited.empty()) {
        cities.push_back(*unvisited.begin());
        BFS(*unvisited.begin());
    }
    cout << cities.size() - 1 << "\n";
    for (int i = 0; i < cities.size() - 1; i++) {
        cout << cities[i] + 1 << " " << cities[i+1] + 1 << "\n";;
    }

    return 0;
}