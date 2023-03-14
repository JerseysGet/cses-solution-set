#include <bits/stdc++.h>
using namespace std;
// #define int long long

vector<bool> visited;
vector<vector<int>> adjLists;
unordered_set<int> unvisited;
unordered_map<int, int> previous;

void DFS(int v) {
    unvisited.erase(v);
    for (auto adjV : adjLists[v]) {
        if (unvisited.count(adjV) == 1) {
            previous[adjV] = v;
            unvisited.erase(adjV);
            DFS(adjV);
        } else if (previous[v] != adjV) {
            int curr = v;
            string path = "";
            int length = 0;
            while (curr != adjV) {
                // cout << curr << " ";
                path += to_string(curr) + " ";
                curr = previous[curr];
                length++;
            }
            path += to_string(curr) + " ";
            path += to_string(v) + " ";
            length += 2;
            cout << length << "\n" << path << "\n";
            exit(0);
        }
    }
}

int32_t main() {
    int n, m; cin >> n >> m;
    adjLists = vector<vector<int>> (n+1, vector<int>());
    visited = vector<bool> (n+1, false);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adjLists[a].push_back(b);
        adjLists[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        unvisited.insert(i);
    }


    while (!unvisited.empty()) {
        DFS(*unvisited.begin());
    }

    cout << "IMPOSSIBLE\n";
}