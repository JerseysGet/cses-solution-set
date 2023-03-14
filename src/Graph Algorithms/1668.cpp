#include <bits/stdc++.h>
using namespace std;
// #define int long long

vector<vector<int>> adjLists;
unordered_set<int> unvisited;
vector<int> color;

void BFS(int v) {
    queue<int> q;
    q.push(v);
    unvisited.erase(v);
    color[v] = 1;
    int currColor = 1;
    while (!q.empty()) {
        int size = q.size();
        currColor = 3 - color[q.front()]; // flips color b/w 1 and 2
        while (size--) {
            for (auto adjV : adjLists[q.front()]) {
                if (color[adjV] == 3 - currColor) {
                    cout << "IMPOSSIBLE\n";
                    exit(0);
                }
                if (unvisited.count(adjV) == 1) {
                    unvisited.erase(adjV);
                    color[adjV] = currColor;
                    q.push(adjV);
                }
            }
            q.pop();
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    adjLists = vector<vector<int>>(n+1, vector<int>());
    color = vector<int>(n+1, 0);  
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adjLists[a].push_back(b);
        adjLists[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        unvisited.insert(i);
    }


    while (!unvisited.empty()) {
        BFS(*unvisited.begin());
    }

    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }

    cout << "\n";
}